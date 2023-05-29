#include "cpclickablelabel.h"
#include <QMouseEvent>
#include <QDir>
#include <QFileDialog>
#include <QDebug>

CPClickableLabel::CPClickableLabel(QWidget* parent, Qt::WindowFlags f) : QLabel(parent, f), selectImage(false), image(NULL) {

}

CPClickableLabel::~CPClickableLabel() {

}

void CPClickableLabel::mousePressEvent(QMouseEvent* event) {
    Q_UNUSED(event);
    if (event->button() == Qt::LeftButton) {
        if (selectImage) {
            selectFile();
        } else {
            emit clicked();
        }
    }
}

void CPClickableLabel::setSelectImage(bool selectImage) {
    this->selectImage = selectImage;
}

void CPClickableLabel::selectFile() {
    qDebug() << "selectFile: " << tr("image_file_format");
    QString file = QFileDialog::getOpenFileName(this,
                tr("select_image_file"), QDir::home().path(), "图片文件格式 (*.png *.jpg *.jpeg *.bmp)");
        qDebug() << "selected file: " << file;

    if (file.length() > 0) {
        image = QImage(file);
        qDebug() << "getPersonImage: " << image.width() << "-" << image.height();

        setPixmap(QPixmap::fromImage(this->resizeQImage(image, this->size())));
    }
    emit selectedFile(file);
}



QImage CPClickableLabel::resizeQImage(const QImage& image, QSize size) {
    qDebug() << "resizeQImage: " << image.width() << "-" << image.height() << "  to size: " << size.width() << "-" << size.height();
    if (image.width() > 0 && image.height() > 0) {
        if (size.width()/size.height()) {
            // height
            qDebug() << " resize: " << size.height() * image.width()/image.height() << "-" << size.height();
            return image.scaled(size.height() * image.width()/image.height(), size.height(), Qt::KeepAspectRatio);
        } else {
            // width
            qDebug() << " resize: " << size.width() << "-" << image.height() *size.width()/ image.width();
            return image.scaled(size.width(), image.height() *size.width()/ image.width(), Qt::KeepAspectRatio);
        }
    } else {
        return QImage();
    }
}

QImage CPClickableLabel::getImage() {
    return image;
}

void CPClickableLabel::setImage(const QImage& image) {
    this->image = image;
}


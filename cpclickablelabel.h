#ifndef CPCLICKABLELABEL_H
#define CPCLICKABLELABEL_H

#include "cp-clickable-label_global.h"
#include <QLabel>
#include <QWidget>

class CPCLICKABLELABEL_EXPORT CPClickableLabel: public QLabel {
    Q_OBJECT
public:
    CPClickableLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    virtual ~CPClickableLabel();

    QImage getImage();

signals:
    void clicked();
    void selectedFile(QString file);

private:
    void selectFile();
    QImage resizeQImage(const QImage& image, QSize size);

protected:
    void mousePressEvent(QMouseEvent* event);

private:
    QImage image;
};

#endif // CPCLICKABLELABEL_H

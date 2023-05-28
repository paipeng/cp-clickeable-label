#include "cpclickablelabel.h"
#include <QMouseEvent>

CPClickableLabel::CPClickableLabel(QWidget* parent, Qt::WindowFlags f) : QLabel(parent, f) {

}



CPClickableLabel::~CPClickableLabel() {

}

void CPClickableLabel::mousePressEvent(QMouseEvent* event) {
    Q_UNUSED(event);
    if (event->button() == Qt::LeftButton) {
        emit clicked();
    }
}


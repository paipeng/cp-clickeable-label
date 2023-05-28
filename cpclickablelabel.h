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

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);
};

#endif // CPCLICKABLELABEL_H

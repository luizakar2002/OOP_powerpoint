#include "Circle.hpp"
#include <QPainter>

Circle::Circle(const QRect &rect) : rect(rect) {}

Circle::Circle(OptionsValues opt) : _opt(opt)
{
    rect = QRect(20, 20, 100, 100); // TK: Not Good
}

void Circle::draw(QPainter &painter) const
{
    painter.setPen(getStyledPen(_opt)); // TK: Code duplication
    painter.drawEllipse(rect);
    painter.setPen(Qt::NoPen); // TK: Code duplication
}

bool Circle::contains(const QPoint &point) const {
    return rect.contains(point);
}

void Circle::move(const QPoint &offset) {
    rect.moveTo(offset); // TK: Code duplication
}

void Circle::resize(const QPoint &handlePos, const QPoint &resizeHandlePos) {
     // TK: Code duplication
    int deltaX = handlePos.x() - resizeHandlePos.x();
    int deltaY = handlePos.y() - resizeHandlePos.y();
    rect.adjust(0, 0, deltaX, deltaY);
}

QRect Circle::getRect() const {
    return rect; // TK: Code duplication
}

bool Circle::isOnResizeHandle(const QPoint &pos) const
{
     // TK: Code duplication
    int handleSize = 8;
    QRect handleRect = rect.adjusted(-handleSize, -handleSize, handleSize, handleSize);
    return handleRect.contains(pos);
}

QPen Circle::getStyledPen(const OptionsValues &_opt) const
{
    return ShapeBase::getStyledPen(_opt); // TK: Code duplication
}

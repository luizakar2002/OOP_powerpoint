# include "Rectangle.hpp"
# include <QPainter>
# include <QDebug>

Rectangle::Rectangle(const QRect &rect) : rect(rect) {}

Rectangle::Rectangle(OptionsValues opt) : _opt(opt)
{
    rect = QRect(20, 20, 100, 50);
}

void Rectangle::draw(QPainter &painter) const
{
    painter.setPen(getStyledPen(_opt)); // [TK] Code duplication
    painter.drawRect(rect);
    painter.setPen(Qt::NoPen); // [TK] Code duplication
}

bool Rectangle::contains(const QPoint &point) const
{
    return rect.contains(point); // [TK] Code duplication
}

void Rectangle::move(const QPoint &offset)
{
    rect.moveTo(offset); // [TK] Code duplication
}

void Rectangle::resize(const QPoint &handlePos, const QPoint &resizeHandlePos)
{
     // [TK] Code duplication
    int deltaX = handlePos.x() - resizeHandlePos.x();
    int deltaY = handlePos.y() - resizeHandlePos.y();
    rect.adjust(0, 0, deltaX, deltaY);
}

QRect Rectangle::getRect() const
{
    return rect; // [TK] Code duplication
}

bool Rectangle::isOnResizeHandle(const QPoint &pos) const
{
     // [TK] Code duplication
    int handleSize = 2;
    QRect handleRect = rect.adjusted(-handleSize, -handleSize, handleSize, handleSize);
    return handleRect.contains(pos);
}

QPen Rectangle::getStyledPen(const OptionsValues &_opt) const
{
     // [TK] Code duplication
    return ShapeBase::getStyledPen(_opt);
}

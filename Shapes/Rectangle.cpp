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
    painter.setPen(getStyledPen(_opt));
    painter.drawRect(rect);
    painter.setPen(Qt::NoPen);
}

bool Rectangle::contains(const QPoint &point) const
{
    return rect.contains(point);
}

void Rectangle::move(const QPoint &offset)
{
    rect.moveTo(offset);
}

void Rectangle::resize(const QPoint &handlePos, const QPoint &resizeHandlePos)
{
    int deltaX = handlePos.x() - resizeHandlePos.x();
    int deltaY = handlePos.y() - resizeHandlePos.y();
    rect.adjust(0, 0, deltaX, deltaY);
}

QRect Rectangle::getRect() const
{
    return rect;
}

bool Rectangle::isOnResizeHandle(const QPoint &pos) const
{
    int handleSize = 2;
    QRect handleRect = rect.adjusted(-handleSize, -handleSize, handleSize, handleSize);
    return handleRect.contains(pos);
}

QPen Rectangle::getStyledPen(const OptionsValues &_opt) const
{
    return ShapeBase::getStyledPen(_opt);
}

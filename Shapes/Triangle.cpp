# include "Triangle.hpp"
# include <QPainter>
# include <QDebug>

Triangle::Triangle(const QRect &rect) : rect(rect) {}

Triangle::Triangle(OptionsValues opt) : _opt(opt)
{
    rect = QRect(20, 20, 100, 100);
}

void Triangle::draw(QPainter &painter) const
{
    QPolygon triangle;
    triangle << QPoint(rect.x() + rect.width() / 2, rect.y())
             << QPoint(rect.x(), rect.y() + rect.height())
             << QPoint(rect.x() + rect.width(), rect.y() + rect.height());

    painter.setPen(getStyledPen(_opt));
    painter.drawPolygon(triangle);
    painter.setPen(Qt::NoPen);
}

bool Triangle::contains(const QPoint &point) const
{
    return rect.contains(point);
}

void Triangle::move(const QPoint &offset)
{
    rect.moveTo(offset);
}

void Triangle::resize(const QPoint &handlePos, const QPoint &resizeHandlePos)
{
    int deltaX = handlePos.x() - resizeHandlePos.x();
    int deltaY = handlePos.y() - resizeHandlePos.y();
    rect.adjust(0, 0, deltaX, deltaY);
}

QRect Triangle::getRect() const
{
    return rect;
}

bool Triangle::isOnResizeHandle(const QPoint &pos) const
{
    int handleSize = 8;
    QRect handleRect = rect.adjusted(-handleSize, -handleSize, handleSize, handleSize);
    return handleRect.contains(pos);
}

QPen Triangle::getStyledPen(const OptionsValues &_opt) const
{
    return ShapeBase::getStyledPen(_opt);
}

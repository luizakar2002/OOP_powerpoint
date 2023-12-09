# include "Triangle.hpp"
# include <QPainter>
# include <QDebug>

Triangle::Triangle(const QRect &rect) : rect(rect) {}

Triangle::Triangle(OptionsValues opt) : _opt(opt)
{
    rect = QRect(20, 20, 100, 100); // TK:Not good
}

void Triangle::draw(QPainter &painter) const
{
    QPolygon triangle;
    triangle << QPoint(rect.x() + rect.width() / 2, rect.y())
             << QPoint(rect.x(), rect.y() + rect.height())
             << QPoint(rect.x() + rect.width(), rect.y() + rect.height());

    painter.setPen(getStyledPen(_opt)); // TK: Code duplication
    painter.drawPolygon(triangle);
    painter.setPen(Qt::NoPen); // TK: Code duplication
}

bool Triangle::contains(const QPoint &point) const
{
    return rect.contains(point); // TK: Code duplication
}

void Triangle::move(const QPoint &offset)
{
    rect.moveTo(offset); // TK: Code duplication
}

void Triangle::resize(const QPoint &handlePos, const QPoint &resizeHandlePos)
{
     // TK: Code duplication
    int deltaX = handlePos.x() - resizeHandlePos.x();
    int deltaY = handlePos.y() - resizeHandlePos.y();
    rect.adjust(0, 0, deltaX, deltaY);
}

QRect Triangle::getRect() const
{
    return rect; // TK: Code duplication
}

bool Triangle::isOnResizeHandle(const QPoint &pos) const
{
     // TK: Code duplication
    int handleSize = 8; // TK:Not good to hardcode such values in the functions
    QRect handleRect = rect.adjusted(-handleSize, -handleSize, handleSize, handleSize);
    return handleRect.contains(pos);
}

QPen Triangle::getStyledPen(const OptionsValues &_opt) const
{
    return ShapeBase::getStyledPen(_opt); // TK: Code duplication
}

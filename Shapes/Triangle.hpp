#ifndef TRIANGLE_HPP
# define TRIANGLE_HPP

# include "ShapeBase.hpp"
# include <QPolygon>

class Triangle : public ShapeBase
{
public:
    Triangle(const QRect &rect);
    Triangle(OptionsValues);

public:
    void draw(QPainter &painter) const override;
    bool contains(const QPoint &point) const override;
    void move(const QPoint &offset) override;
    void resize(const QPoint &handlePos, const QPoint &resizeHandlePos) override;

    QRect   getRect() const override;
    bool    isOnResizeHandle(const QPoint &pos) const override;
    QPen    getStyledPen(const OptionsValues &_opt) const override;


private:
    QRect               rect;
    OptionsValues       _opt;
};

#endif /* TRIANGLE_HPP */

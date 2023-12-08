#ifndef CIRCLE_HPP
# define CIRCLE_HPP

# include <QRect>
# include "ShapeBase.hpp"

class Circle : public ShapeBase
{
public:
    Circle(const QRect &rect);
    Circle(OptionsValues);

public:
    void draw(QPainter &painter) const override;
    bool contains(const QPoint &point) const override;
    void move(const QPoint &offset) override;
    void resize(const QPoint &handlePos, const QPoint &resizeHandlePos) override;

    QRect   getRect() const override;
    bool    isOnResizeHandle(const QPoint &pos) const override;
    QPen    getStyledPen(const OptionsValues &_opt) const override;

private:
    QRect rect;
    OptionsValues       _opt;
};

#endif /* CIRCLE_HPP */

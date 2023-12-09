#ifndef CIRCLE_HPP
# define CIRCLE_HPP

# include <QRect>
# include "ShapeBase.hpp"

class Circle : public ShapeBase
{
public:
    // [TK] Where used this constructor?
    Circle(const QRect &rect);
    // [TK] User can't change OptionValues later, why there is two contradicting constructors, why there is no simple setters for the Rect and OptionValues ?
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
    // [TK] Why those memebers aren't in the Base class?
    QRect rect;
    OptionsValues       _opt;
};

#endif /* CIRCLE_HPP */

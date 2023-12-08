#ifndef SHAPEBASE_HPP
# define SHAPEBASE_HPP

# include <QRect>
# include <QPolygon>
# include <QPainter>

# include <iostream>
# include <unordered_map>

using OptionsValues = std::unordered_map<std::string, std::string>;

enum class Shape { Rectangle, Circle, Triangle };

class ShapeBase
{
public:
    virtual ~ShapeBase() = default;

public:
    virtual void draw(QPainter &painter) const = 0;
    virtual bool contains(const QPoint &point) const = 0;
    virtual void move(const QPoint &offset) = 0;
    virtual void resize(const QPoint &handlePos, const QPoint &resizeHandlePos) = 0;

    virtual QRect       getRect() const = 0;
    virtual bool        isOnResizeHandle(const QPoint &pos) const = 0;

    virtual QPen        getStyledPen(const OptionsValues &_opt) const;
};

#endif /* SHAPEBASE_HPP */

# include "BoundingBox.hpp"

BoundingBox::BoundingBox(): _topLeftX(20), _topLeftY(20), _width(100), _height(100)
{

}

BoundingBox::BoundingBox(int topLeftX, int topLeftY, int width, int height)
    : _topLeftX(topLeftX), _topLeftY(topLeftY), _width(width), _height(height)
{

}

int     BoundingBox::getTopLeftX() const
{
    return _topLeftX;
}

int     BoundingBox::getTopLeftY() const
{
    return _topLeftY;
}

int     BoundingBox::getWidth() const
{
    return _width;
}

int     BoundingBox::getHeight() const
{
    return _height;
}

void    BoundingBox::setTopLeftX(int topLX)
{
    _topLeftX = topLX;
}

void    BoundingBox::setTopLeftY(int topLY)
{
    _topLeftY = topLY;
}


#ifndef DOCUMENT_ITEMS_BOUNDINGBOX_HPP
# define DOCUMENT_ITEMS_BOUNDINGBOX_HPP

class BoundingBox
{
private:
    int _topLeftX;
    int _topLeftY;
    int _width;
    int _height;

public:
    BoundingBox();
    BoundingBox(int, int, int, int);
    ~BoundingBox() = default;

    int getWidth() const;
    int getHeight() const;
    int getTopLeftX() const;
    int getTopLeftY() const;

    void    setTopLeftX(int);
    void    setTopLeftY(int);
};

#endif /* DOCUMENT_ITEMS_BOUNDINGBOX_HPP */

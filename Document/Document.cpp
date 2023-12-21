# include "Document.hpp"

void    Document::add_slide()
{
    SlidePtr new_slide = std::make_shared<Slide>();
    _slides.push_back(new_slide);
}

SlidePtr Document::get_slide(Position pos) const
{
    return _slides.at(pos);
}

Slides  Document::get_slides() const
{
    return _slides;
}

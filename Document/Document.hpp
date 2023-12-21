#ifndef DOCUMENT_DOCUMENT_HPP
# define DOCUMENT_DOCUMENT_HPP

# include <vector>

# include "Slide.hpp"

using Slides = std::vector<SlidePtr>;

class Document
{
private:
    Slides  _slides;
public:
    Document() = default;
    ~Document() = default;

    void        add_slide();
    SlidePtr    get_slide(Position) const;
    Slides      get_slides() const;

};

#endif /*DOCUMENT_DOCUMENT_HPP*/
#ifndef QT_RENDERER_SLIDERENDERER_HPP
# define QT_RENDERER_SLIDERENDERER_HPP

# include "ItemRenderer.hpp"
# include "../../Document/Slide.hpp"

class SlideRenderer
{
private:
    ItemRenderer    _itemRenderer;
public:
    SlideRenderer() = default;
    ~SlideRenderer() = default;

    void    renderSlide(SlidePtr, QPaintDevice *);
private:
    QPen    getStyledPen(const OptionsValues &_opt) const;
};

#endif /*QT_RENDERER_SLIDERENDERER_HPP*/

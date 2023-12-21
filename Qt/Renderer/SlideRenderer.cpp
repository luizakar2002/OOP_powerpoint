# include "SlideRenderer.hpp"

# include <QPainter>

void SlideRenderer::renderSlide(SlidePtr slide, QPaintDevice *paintDevice)
{
    QPainter painter;
    painter.begin(paintDevice);

    for (auto item : slide->get_items())
    {
        painter.setPen(getStyledPen(item->getOptionsValues()));
        _itemRenderer.renderItem(*item, &painter);
        painter.setPen(Qt::NoPen);
    }

    painter.end();
}

QPen SlideRenderer::getStyledPen(const OptionsValues &_opt) const
{
    QPen borderPen;

    borderPen.setWidth(3);

    auto borderColorIter = _opt.find("-Bcolor");
    if (borderColorIter != _opt.end())
    {
        QColor borderColor(QString::fromStdString(borderColorIter->second));

        if (borderColor.isValid())
            borderPen.setColor(borderColor);
        else
            borderPen.setColor(Qt::white);
    }
    else
        borderPen.setColor(Qt::white);

    auto borderStyleIter = _opt.find("-Bstyle");
    if (borderStyleIter != _opt.end())
    {
        Qt::PenStyle borderStyle = Qt::SolidLine;

        if (borderStyleIter->second == "DashLine")
            borderStyle = Qt::DashLine;
        else if (borderStyleIter->second == "DotLine")
            borderStyle = Qt::DotLine;

        borderPen.setStyle(borderStyle);
    }

    return borderPen;
}

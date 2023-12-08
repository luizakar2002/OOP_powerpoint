#include "ShapeBase.hpp"

QPen ShapeBase::getStyledPen(const OptionsValues &_opt) const
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

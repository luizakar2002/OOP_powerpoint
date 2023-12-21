# include "ItemRenderer.hpp"
# include "../Application.hpp"

ItemRenderer::ItemRenderer()
{
    registerRenderer(ItemType::Rectangle,
                    [this](Item item, QPainter* painter)
                    {
                        painter->drawRect(create_QRect(item.getBoundingBox()));
                    });
    registerRenderer(ItemType::Ellipse,
                    [this](Item item, QPainter* painter)
                    {
                        painter->drawEllipse(create_QRect(item.getBoundingBox()));
                    });
    registerRenderer(ItemType::Triangle,
                    [this](Item item, QPainter* painter)
                    {
                        painter->drawPolygon(create_QPolygon(item.getBoundingBox()));
                    });
}

void ItemRenderer::registerRenderer(ItemType type, RenderFunction function)
{
    _renderFunctions[type] = function;
}

QRect   ItemRenderer::create_QRect(const BoundingBox &bounding_box)
{
    return QRect(bounding_box.getTopLeftX(), bounding_box.getTopLeftY(), bounding_box.getWidth(), bounding_box.getHeight());
}

QPolygon   ItemRenderer::create_QPolygon(const BoundingBox &bounding_box)
{
    QPolygon triangle;
    triangle << QPoint(bounding_box.getTopLeftX() + bounding_box.getWidth() / 2, bounding_box.getTopLeftY())
             << QPoint(bounding_box.getTopLeftX(), bounding_box.getTopLeftY() + bounding_box.getHeight())
             << QPoint(bounding_box.getTopLeftX() + bounding_box.getWidth(), bounding_box.getTopLeftY() + bounding_box.getHeight());
    return triangle;
}

void ItemRenderer::renderItem(const Item& item, QPainter* painter) const
{
    auto it = _renderFunctions.find(item.getItemType());
    if (it == _renderFunctions.end())
        std::runtime_error("Item is not renderable.");
    it->second(item, painter);
}

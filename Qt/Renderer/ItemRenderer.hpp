#ifndef QT_RENDERER_ITEMRENDERER_H
# define QT_RENDERER_ITEMRENDERER_H

# include <functional>
# include <QPainter>
# include <QRect>
# include <QPolygon>

# include "../../Document/Items/Item.hpp"

class ItemRenderer
{

private:
    using RenderFunction = std::function<void(Item, QPainter*)>;
    using RenderFunctions = std::unordered_map<ItemType, RenderFunction>;

private:
    RenderFunctions     _renderFunctions;

public:
    ItemRenderer();
    ~ItemRenderer() = default;

    void    registerRenderer(ItemType type, RenderFunction function);
    void    renderItem(const Item& item, QPainter* painter) const;
public:
    QRect       create_QRect(const BoundingBox &);
    QPolygon    create_QPolygon(const BoundingBox &);
};

#endif /*QT_RENDERER_ITEMRENDERER_H*/

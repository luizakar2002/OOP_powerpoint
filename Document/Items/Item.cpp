# include "Item.hpp"

Item::Item(): _itemType(ItemType::Rectangle)
{

}

Item::Item(ItemType type): _itemType(type)
{

}

Item::Item(ItemType type, int topLeftX, int topLeftY, int width, int height): _itemType(type), _boundingBox(topLeftX, topLeftY, width, height)
{

}

ItemType    Item::getItemType() const
{
    return _itemType;
}

BoundingBox &Item::getBoundingBox()
{
    return _boundingBox;
}

OptionsValues &Item::getOptionsValues()
{
    return _options_values;
}

void    Item::setOptionsValues(const OptionsValues &ops)
{
    // Not written std::move as it is not intended to transfer ownership of args to Item. The ops are passed from Command [AddItemCommand]
    _options_values = ops;
}


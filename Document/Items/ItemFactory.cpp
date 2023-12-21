# include "ItemFactory.hpp"

ItemFactory::ItemFactory()
{
    registerItem("Rectangle", []() { return std::make_unique<Item>(ItemType::Rectangle); });
    registerItem("Ellipse", []() { return std::make_unique<Item>(ItemType::Ellipse); });
    registerItem("Triangle", []() { return std::make_unique<Item>(ItemType::Triangle); });
    registerItem("Text", []() { return std::make_unique<Item>(ItemType::Text); });
}

void ItemFactory::registerItem(const std::string& itemName, Creator creator)
{
    _itemCreators[itemName] = creator;
}

ItemPtrUnique ItemFactory::create_raw_Item(const std::string &itemName)
{
    auto it = _itemCreators.find(itemName);
    if (it == _itemCreators.end())
        throw std::runtime_error("This item is not available: " + itemName);
    return it->second();
}
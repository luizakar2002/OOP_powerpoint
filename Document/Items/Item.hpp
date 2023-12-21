#ifndef DOCUMENT_ITEMS_ITEM_HPP
# define DOCUMENT_ITEMS_ITEM_HPP

# include <iostream>
# include <memory>
# include <vector>
# include <unordered_map>

# include "BoundingBox.hpp"

enum class ItemType
{
    Rectangle,
    Ellipse,
    Triangle,
    Text
};

using OptionsValues = std::unordered_map<std::string, std::string>;

class Item
{
private:
    ItemType        _itemType;
    OptionsValues   _options_values;
    BoundingBox     _boundingBox;

public:
    Item();
    Item(ItemType);
    Item(ItemType, int, int, int, int);
    ~Item() = default;

    ItemType        getItemType() const;
    BoundingBox     &getBoundingBox();
    OptionsValues   &getOptionsValues();
    void            setOptionsValues(const OptionsValues &);
};

using ItemPtrShared = std::shared_ptr<Item>;
using ItemPtrUnique = std::unique_ptr<Item>;

#endif /*DOCUMENT_ITEMS_ITEM_HPP*/

#ifndef DOCUMENT_ITEMS_ITEMFACTORY_HPP
# define DOCUMENT_ITEMS_ITEMFACTORY_HPP

# include <iostream>
# include <unordered_map>
# include <memory>
# include <functional>
#include "Item.hpp"

class ItemFactory
{
private:
    using Creator = std::function<ItemPtrUnique()>;
    using ItemCreators = std::unordered_map<std::string, Creator>;

private:
    ItemCreators _itemCreators;

public:
    ItemFactory();

public:
    void            registerItem(const std::string &, Creator);
    ItemPtrUnique   create_raw_Item(const std::string&);

};

#endif /*DOCUMENT_ITEMS_ITEMFACTORY_HPP*/

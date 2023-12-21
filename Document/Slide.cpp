# include "Slide.hpp"

void    Slide::add_item(ItemPtrShared  new_item)
{
    _items.push_back(new_item);
}

ItemPtrShared Slide::get_item(Position pos) const
{
    return _items.at(pos);
}

Items   Slide::get_items() const
{
    return _items;
}

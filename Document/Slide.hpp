#ifndef DOCUMENT_SLIDE_HPP
# define DOCUMENT_SLIDE_HPP

# include <memory>
# include "Items/Item.hpp"

using Position = int;
using Items = std::vector<ItemPtrShared>;

class Slide
{
private:
    Items   _items;

public:
    Slide() = default;
    ~Slide() = default;

    void              add_item(ItemPtrShared);
    ItemPtrShared     get_item(Position) const;
    Items             get_items() const;


};

using SlidePtr = std::shared_ptr<Slide>;

#endif /*DOCUMENT_SLIDE_HPP*/
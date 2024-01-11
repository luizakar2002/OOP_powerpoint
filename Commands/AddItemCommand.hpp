#ifndef COMMANDS_ADDITEMCOMMAND_HPP
# define COMMANDS_ADDITEMCOMMAND_HPP

# include <unordered_map>

# include "Command.hpp"
# include "../Document/Items/Item.hpp"
# include "../Qt/Application.hpp"

using ItemTypes = std::unordered_map<std::string, ItemType>;

class AddItemCommand : public Command
{
private:
    static const ItemTypes _item_types;
public:
    AddItemCommand() = default;
    virtual ~AddItemCommand() = default;

    void            execute() override;

private:
    ItemType    parse_item_type(std::string);
    void        parse_item_coords(ItemPtrUnique&&);
};

#endif /*COMMANDS_ADDITEMCOMMAND_HPP*/

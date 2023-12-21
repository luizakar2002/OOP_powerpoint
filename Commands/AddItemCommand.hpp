#ifndef COMMANDS_ADDITEMCOMMAND_HPP
# define COMMANDS_ADDITEMCOMMAND_HPP

# include "Command.hpp"
# include "../Document/Items/ItemFactory.hpp"
# include "../Document/Items/Item.hpp"
# include "../Qt/Application.hpp"

class AddItemCommand : public Command
{
private:
    ItemFactory _itemFactory;

public:
    AddItemCommand() = default;
    virtual ~AddItemCommand() = default;

public:
    void            execute() override;
};

#endif /*COMMANDS_ADDITEMCOMMAND_HPP*/

#ifndef COMMANDS_ADDSLIDECOMMAND_HPP
# define COMMANDS_ADDSLIDECOMMAND_HPP

# include "Command.hpp"

class AddSlideCommand : public Command
{
public:
    AddSlideCommand() = default;
    virtual ~AddSlideCommand() = default;

public:
    void    execute() override;
};

#endif /*COMMANDS_ADDSLIDECOMMAND_HPP*/

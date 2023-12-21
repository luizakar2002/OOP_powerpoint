#ifndef COMMANDS_HELPCOMMAND_HPP
# define COMMANDS_HELPCOMMAND_HPP

# include "Command.hpp"

class HelpCommand : public Command
{
public:
    HelpCommand() = default;
    virtual ~HelpCommand() = default;

public:
    void    execute() override;
};

#endif /*COMMANDS_HELPCOMMAND_HPP*/

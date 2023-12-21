#ifndef COMMANDS_QUITCOMMAND_HPP
# define COMMANDS_QUITCOMMAND_HPP

# include "Command.hpp"

class QuitCommand : public Command
{
public:
    QuitCommand() = default;
    virtual ~QuitCommand() = default;

public:
    void    execute() override;
};

#endif /*COMMANDS_QUITCOMMAND_HPP*/

#ifndef PARSER_COMMANDREGISTRY_HPP
# define PARSER_COMMANDREGISTRY_HPP

# include <unordered_map>
# include <memory>
# include <functional>

# include "../Commands/Command.hpp"

class CommandRegistry
{
private:
    using Creator = std::function<CommandPtr()>;
    using CommandCreators = std::unordered_map<std::string, Creator>;

private:
    CommandCreators _commandCreators;
    
public:
    CommandRegistry();

public:
    void        registerCommand(const std::string &, Creator);
    CommandPtr  create_raw_Command(const std::string& commandName);

};

#endif /*PARSER_COMMANDREGISTRY_HPP*/

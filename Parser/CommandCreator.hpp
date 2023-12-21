#ifndef PARSER_COMMANDCREATOR_HPP
# define PARSER_COMMANDCREATOR_HPP

# include <algorithm>
# include <iostream>
# include <vector>

# include "CommandRegistry.hpp"
// # include "../Commands/AddSlideCommand.hpp"
// # include "../Commands/DisplayCommand.hpp"


// using InputVector = std::vector<std::string>;

class CommandCreator
{
private:
    CommandRegistry _commandRegistry;

public:
    CommandCreator() = default;
    ~CommandCreator() = default;

public:
    CommandPtr      parse(std::istream&);

private:
    void            parse_operands(std::istream&, Command &);
};

#endif /*PARSER_COMMANDCREATOR_HPP*/

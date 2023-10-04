#ifndef PARSER_HPP
# define PARSER_HPP

# include <algorithm>
# include <iostream>
# include <unordered_map>
# include <vector>

# include "Commands/Command.hpp"
# include "Commands/AddCommand.hpp"
# include "Commands/DisplayCommand.hpp"

using InputVector = std::vector<std::string>;
using OptionsValues = std::unordered_map<std::string, std::string>;
using CommandRegistry = std::unordered_map<std::string, Command*>;

class Parser
{
    private:
        std::string     _main_command;
        InputVector     _command_line;
        OptionsValues   _options_values_map;
        CommandRegistry _command_registry;

    public:
        Parser();
        Parser(const Parser &);
        ~Parser();

        Parser &operator=(const Parser &);

    public:
        Command    *parse(InputVector);
        void        parse_main_command();
        void        parse_operands();

    public:
    class InvalidCommand : public std::exception {
        public:
            const char *what()
            {
                return "Command is invalid! See HELP.";
            }
    };
};

#endif /*PARSER_HPP*/
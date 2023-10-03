# include "Parser.hpp"

Parser::Parser()
{

}

Parser::Parser(const Parser &other)
{

}

Parser::Parser(InputVector input)
{
    _command_line = input;
    _command_registry["Add"] = new AddCommand();
    // for (auto word: _command_line)
    //     std::cout << word << std::endl;
}

Parser::~Parser()
{

}

Parser &Parser::operator=(const Parser &)
{

}


void    Parser::parse_main_command()
{
    // TO DO: check in command registry
    std::vector<std::string> commands = {"Add", "Remove", "Display", "Change"};

    _main_command = _command_line[0];
    _command_line.erase(std::begin(_command_line));

    try
    {
        if (std::find(commands.begin(), commands.end(), _main_command) == commands.end())
            throw InvalidCommand();
    }
    catch(InvalidCommand &invalid)
    {
        std::cerr << invalid.what() << std::endl;
    }
    
}

void    Parser::parse_operands()
{
    for (auto it = _command_line.begin(); it != _command_line.end(); it += 2)
    {
        try
        {
            _options_values_map[*it] = std::stod(*(it + 1));
        }
        catch(...)
        {
            std::cerr << "Invalid operand! See HELP." << '\n';
        }
    }
}

Command    *Parser::parse()
{
    parse_main_command();
    parse_operands();
    _command_registry[_main_command]->setOptionsValues(_options_values_map);
    return _command_registry[_main_command];
}

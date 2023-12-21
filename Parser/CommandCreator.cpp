# include "CommandCreator.hpp"

CommandPtr  CommandCreator::parse(std::istream& input_stream)
{
    std::string command_name;
    input_stream >> command_name;
    auto command = _commandRegistry.create_raw_Command(command_name);
    parse_operands(input_stream, *command);
    return command;
}

void    CommandCreator::parse_operands(std::istream& input_stream, Command &command)
{
    OptionsValues ops;

    std::string key, value;
    while (input_stream >> key)
    {
        input_stream >> value;
        ops[key] = value;
    }
    command.setOptionsValues(ops);
}
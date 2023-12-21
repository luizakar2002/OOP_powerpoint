#ifndef COMMAND_COMMAND_HPP
# define COMMAND_COMMAND_HPP

# include <iostream>
# include <memory>
# include <unordered_map>

using OptionsValues = std::unordered_map<std::string, std::string>;

class Command
{
protected:
    OptionsValues   _options_values;
public:
    Command() = default;
    virtual ~Command() {}

    virtual void execute() = 0;
    virtual void setOptionsValues(const OptionsValues &optionsValues)
    {
        _options_values = std::move(optionsValues);
    }
};

using CommandPtr = std::unique_ptr<Command>;

#endif /*COMMAND_COMMAND_HPP*/

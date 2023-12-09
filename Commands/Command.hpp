#ifndef COMMAND_HPP
# define COMMAND_HPP

# include <iostream>
# include <unordered_map>

using OptionsValues = std::unordered_map<std::string, std::string>;
class ShapeRegistry;

class Command
{
private:
         // OptionsValues   _options_values;
public:
    virtual ~Command() {}

    // [TK] Only few commands may use ShapeRegistry, why it is passed as an argument to execute?
    // For example what should do with it Display command?
    virtual void execute(ShapeRegistry &) = 0;
    virtual void setOptionsValues(OptionsValues) = 0;
};

# include "../Registries/ShapeRegistry.hpp"

#endif /*COMMAND_HPP*/

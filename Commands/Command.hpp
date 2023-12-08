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

    virtual void execute(ShapeRegistry &) = 0;
    virtual void setOptionsValues(OptionsValues) = 0;
};

# include "../Registries/ShapeRegistry.hpp"

#endif /*COMMAND_HPP*/

# include "AddCommand.hpp"

AddCommand::AddCommand()
{

}

AddCommand::AddCommand(OptionsValues opt)
{
    _options_values = opt;
}

AddCommand::~AddCommand()
{

}

void    AddCommand::execute(ShapeRegistry &shape_reg)
{

}

void    AddCommand::setOptionsValues(OptionsValues opt)
{
    _options_values = opt;
}
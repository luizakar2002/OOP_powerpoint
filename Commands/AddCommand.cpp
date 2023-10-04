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
    std::string shape_name;
    Shape *new_shape;
    try
    {
        std::string shape_name = _options_values["-name"];
        // std::cout << "SHAPE NAME " << shape_name << std::endl;
        new_shape = shape_reg.getShapeCtorMap()[shape_name](_options_values);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    shape_reg.updateCurrentShapes(new_shape);
    // std::cout << "SHAPE REG SIZE IN ADD " << shape_reg.getCurrentShapes().size() << std::endl;
}

void    AddCommand::setOptionsValues(OptionsValues opt)
{
    _options_values = opt;
}
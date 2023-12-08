# include "AddCommand.hpp"
# include <QDebug>

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
    std::unique_ptr<ShapeBase> new_shape;

    try
    {
        std::string shape_name = _options_values["-shape"];
        qDebug()<< "SHAPE NAME " << shape_name << "/n";
        new_shape = shape_reg.getShapeCtorMap()[shape_name](_options_values);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    shape_reg.pushBackCurrentShapes(std::move(new_shape));
    // std::cout << "SHAPE REG SIZE IN ADD " << shape_reg.getCurrentShapes().size() << std::endl;
}

void    AddCommand::setOptionsValues(OptionsValues opt)
{
    _options_values = opt;
}

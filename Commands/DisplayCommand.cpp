# include "DisplayCommand.hpp"
# include <QDebug>

DisplayCommand::DisplayCommand()
{

}

DisplayCommand::DisplayCommand(OptionsValues opt)
{
    _options_values = opt;
}

DisplayCommand::~DisplayCommand()
{

}

void    DisplayCommand::execute(ShapeRegistry &shape_reg)
{
    // std::vector<Shape *> current_shapes = shape_reg.getCurrentShapes();
    qDebug() << "IN DISPLAY\n"; // << current_shapes.size() << std::endl;
    // for (auto shape : current_shapes)
    // {
    //     shape->display();
    // }
}

void    DisplayCommand::setOptionsValues(OptionsValues opt)
{
    _options_values = opt;
}

# include "Application.hpp"

Application::Application()
{
    // _parser = Parser();
    // _shape_registry = ShapeRegistry();
}

Application::~Application()
{

}

void    Application::run()
{
    // while (42)
    // {
        Command *command = _parser.parse();
        command->execute(_shape_registry);
    // }
}
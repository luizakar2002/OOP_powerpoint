#include "HelpCommand.hpp"
#include "../Qt/Application.hpp"

void HelpCommand::execute()
{
    Application::instance()->getQtController().logOutput("Add -item [Rectangle, Ellipse, Triangle] -Bcolor [red, blue, ...] -Bstyle [DashLine, DotLine]");
    Application::instance()->getQtController().logOutput("AddSlide");
    Application::instance()->getQtController().logOutput("Help");
}


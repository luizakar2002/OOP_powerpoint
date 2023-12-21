#include "AddSlideCommand.hpp"
#include "../Qt/Application.hpp"

void AddSlideCommand::execute()
{
    Application::instance()->get_document().add_slide();
    Application::instance()->getQtController().logOutput("Added new slide.");
}


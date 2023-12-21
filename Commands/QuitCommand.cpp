#include "QuitCommand.hpp"
#include "../Qt/Application.hpp"

void QuitCommand::execute()
{
    Application::instance()->quit();
}


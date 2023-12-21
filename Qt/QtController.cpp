# include "QtController.hpp"
# include "Application.hpp"

# include <stdexcept>

void QtController::runCommand(std::istream &input)
{
    try
    {
        CommandPtr command = Application::instance()->get_commandCreator().parse(input);
        command->execute();
        documentChanged();
    }
    catch(const std::exception& e){
        emit logOutputSignal(e.what());
    }
}

void QtController::documentChanged()
{
    emit signalDocumentChanged();
}

void QtController::logOutput(const std::string& message)
{
    emit logOutputSignal(message);
}
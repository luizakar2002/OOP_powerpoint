# include "Application.hpp"

Application::Application(int argc, char **argv): QApplication(argc, argv)
{
    _current_slide_id = 0; // starts from 0
    _document.add_slide();
}

Application *Application::instance()
{
    return dynamic_cast<Application*>(QApplication::instance());
}

int    Application::exec()
{
    return QApplication::exec();
}

void    Application::quit()
{
    QApplication::quit();
}

Document    &Application::get_document()
{
    return _document;
}

CommandCreator    &Application::get_commandCreator()
{
    return _commandCreator;
}

SlideRenderer    &Application::get_slideRenderer()
{
    return _slideRenderer;
}

ItemFactory    &Application::get_itemFactory()
{
    return _itemFactory;
}

QtController    &Application::getQtController()
{
    return _qtController;
}

size_t     &Application::get_current_slide_id()
{
    return _current_slide_id;
}

SlidePtr    Application::get_current_slide()
{
    return _document.get_slide(_current_slide_id);
}

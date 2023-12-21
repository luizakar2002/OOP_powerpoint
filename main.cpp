# include "Qt/Application.hpp"
# include "Qt/MainWindow.hpp"

int main(int argc, char *argv[])
{
    Application app(argc,argv);
    MainWindow main_window;

    main_window.show();

    return Application::instance()->exec();
}

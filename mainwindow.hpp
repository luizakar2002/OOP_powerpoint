#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

# include <QMainWindow>
# include <QLineEdit>
# include <QPushButton>
# include <QDebug>
# include <vector>
# include <sstream>


# include "mywidget.hpp"
# include "Parser.hpp"
# include "./Commands/Command.hpp"
# include "./Registries/ShapeRegistry.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Parser              _parser;
    ShapeRegistry       _shape_registry;
    MyWidget            *myWidget;
    QLineEdit           *inputLineEdit;

    void setupToolBar();
    void setupInputBox();


    QPushButton *rectangleButton;

    void    setter() { qDebug() << "setttter/n"; }

};

#endif // MAINWINDOW_HPP

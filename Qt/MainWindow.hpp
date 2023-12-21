#ifndef QT_MAINWINDOW_HPP
# define QT_MAINWINDOW_HPP

# include <QMainWindow>

class QAction;
class ItemsToolBar;
class WorkingArea;
class CommandWidget;
class SlideView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QString command;
    SlideView* slideView;
    WorkingArea* workingArea;
    ItemsToolBar* itemsTb;
    CommandWidget* commandWidget;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;



};

#endif /*QT_MAINWINDOW_HPP*/

# include "MainWindow.hpp"
# include "View/ItemsToolBar.hpp"
# include "View/CommandWidget.hpp"
# include "View/WorkingArea.hpp"
# include "View/SlideView.hpp"
# include "Application.hpp"
# include "Configuration.hpp"

# include <QToolBar>
# include <QVBoxLayout>
# include <QHBoxLayout>
# include <QSplitter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    // resize(Configuration::getWindowWidth(), Configuration::getWindowHeight());

    itemsTb = new ItemsToolBar;
    addToolBar(Qt::TopToolBarArea, itemsTb);

    workingArea = new WorkingArea;
    commandWidget = new CommandWidget;
    commandWidget->setFixedHeight(120);
    slideView = new SlideView;

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(workingArea);
    layout->addWidget(commandWidget);

    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addWidget(slideView);
    mainLayout->addLayout(layout);

    QWidget* mainWidget = new QWidget(this);
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);

    connect(commandWidget, &CommandWidget::commandEntered, &Application::instance()->getQtController(), &QtController::runCommand);
    connect(&Application::instance()->getQtController(), &QtController::signalDocumentChanged, slideView, &SlideView::onDocumentChanged);
    connect(&Application::instance()->getQtController(), &QtController::signalDocumentChanged, workingArea, &WorkingArea::onDocumentChanged);
    connect(&Application::instance()->getQtController(), &QtController::logOutputSignal, commandWidget, &CommandWidget::logCommand);

    connect(itemsTb, &ItemsToolBar::rectangleShapeSelected, workingArea, &WorkingArea::setRectangleShape);
    connect(itemsTb, &ItemsToolBar::ellipseShapeSelected, workingArea, &WorkingArea::setCircleShape);
    connect(itemsTb, &ItemsToolBar::triangleShapeSelected, workingArea, &WorkingArea::setTriangleShape);
}


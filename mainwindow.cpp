# include "mainwindow.hpp"
# include <QToolBar>
# include <QHBoxLayout>
# include "configuration.hpp"
# include <QWidget>
# include <QLineEdit>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    myWidget = new MyWidget(_shape_registry, this);
    setCentralWidget(myWidget);
    setWindowTitle("powerpoint");
    resize(Configuration::getWindowWidth(), Configuration::getWindowHeight());

    connect(&_shape_registry, &ShapeRegistry::shapeAdded, myWidget, &MyWidget::updateShapes);

    setupToolBar();
    setupInputBox();
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupToolBar()
{
    QToolBar *toolBar = addToolBar("Shapes");

    QAction *rectangleAction = toolBar->addAction("Rectangle");
    connect(rectangleAction, &QAction::triggered, myWidget, &MyWidget::setRectangleShape);

    QAction *circleAction = toolBar->addAction("Circle");
    connect(circleAction, &QAction::triggered, myWidget, &MyWidget::setCircleShape);

    QAction *triangleAction = toolBar->addAction("Triangle");
    connect(triangleAction, &QAction::triggered, myWidget, &MyWidget::setTriangleShape);
}

void MainWindow::setupInputBox()
{
    inputLineEdit = new QLineEdit(this);
    inputLineEdit->setPlaceholderText("Enter a command: ");

    QLayout *existingLayout = centralWidget()->layout();

    if (!existingLayout)
    {
        QVBoxLayout *newLayout = new QVBoxLayout(centralWidget());
        centralWidget()->setLayout(newLayout);
        existingLayout = newLayout;
    }

    existingLayout->addWidget(inputLineEdit);
    existingLayout->setContentsMargins(10, Configuration::getWindowHeight() - 50, 10, 5); // Margins to give some space
    setFocusProxy(inputLineEdit);

    connect(inputLineEdit, &QLineEdit::returnPressed, [this]() {
        QString inputText = inputLineEdit->text();
        qDebug() << "User input: " << inputText;

        std::string str = inputText.toStdString();
        std::stringstream ss(str);
        std::string word;
        std::vector<std::string> words;

        while (ss >> word)
            words.push_back(word);

        Command *command = _parser.parse(words);
        command->execute(_shape_registry);

        inputLineEdit->clear();
    });
}




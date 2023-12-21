#include "ItemsToolBar.hpp"
#include "../Application.hpp"

ItemsToolBar::ItemsToolBar(QToolBar* parent)
    : QToolBar(parent)
{
    QAction *rectangleAction = addAction("Rectangle");
    QAction *ellipseAction = addAction("Ellipse");
    QAction *triangleAction = addAction("Triangle");
    QAction *textAction = addAction("Text");

    connect(rectangleAction, &QAction::triggered, this, &ItemsToolBar::rectangleShapeSelected);
    connect(ellipseAction, &QAction::triggered, this, &ItemsToolBar::ellipseShapeSelected);
    connect(triangleAction, &QAction::triggered, this, &ItemsToolBar::triangleShapeSelected);
    connect(textAction, &QAction::triggered, this, &ItemsToolBar::textShapeSelected);
}




// // QToolBar *toolBar = addToolBar("Shapes");

// QAction *rectangleAction = addAction("Rectangle");
// connect(rectangleAction, &QAction::triggered, , &WorkingArea::setRectangleShape);

// QAction *circleAction = addAction("Circle");
// connect(circleAction, &QAction::triggered, myWidget, &WorkingArea::setCircleShape);

// QAction *triangleAction = addAction("Triangle");
// connect(triangleAction, &QAction::triggered, myWidget, &WorkingArea::setTriangleShape);

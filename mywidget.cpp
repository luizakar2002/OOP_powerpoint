# include "mywidget.hpp"
# include <QPainter>
# include <QPolygon>
# include <memory>
# include <QDebug>

MyWidget::MyWidget(ShapeRegistry &shape_reg, QWidget *parent) : QWidget(parent), _shape_registry(shape_reg), isResizing(false), isMoving(false), currentShape(Shape::Rectangle)
{
    setMouseTracking(true);
}

void MyWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    for (const auto &shape : _shape_registry.getCurrentShapes())
        shape->draw(painter);
}

void MyWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        handleMoving(event);
        if (!isMoving)
            handleResizing(event);
    }
    if (isMoving) {
        setCursor(Qt::ClosedHandCursor);
    }
}


void MyWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (isMoving)
        moveShape(event);
    else if (isResizing)
    {
        setCursor(Qt::SizeFDiagCursor);
        resizeShape(event);
    }
    else
    {
        for (const auto &shape : _shape_registry.getCurrentShapes())
            if (shape->contains(event->pos()))
            {
                setCursor(Qt::SizeAllCursor);
                return;
            }
        unsetCursor();
    }
}

void MyWidget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    isMoving = false;
    isResizing = false;
    currentMovingShape = nullptr;
    currentResizingShape = nullptr;
    unsetCursor();
}

void MyWidget::handleMoving(QMouseEvent *event)
{
    for (auto &shape : _shape_registry.getCurrentShapes())
        if (shape->contains(event->pos()))
        {
            isMoving = true;
            moveOffset = event->pos() - shape->getRect().topLeft();
            currentMovingShape = shape.get();
            break;
        }
}


void MyWidget::handleResizing(QMouseEvent *event)
{
    for (auto &shape : _shape_registry.getCurrentShapes())
        if (shape->isOnResizeHandle(event->pos()))
        {
            isResizing = true;
            resizeHandlePos = event->pos();
            currentResizingShape = shape.get();
            break;
        }
}

void MyWidget::moveShape(QMouseEvent *event)
{
    currentMovingShape->move(event->pos() - moveOffset);
    update();
}

void MyWidget::resizeShape(QMouseEvent *event)
{
    currentResizingShape->resize(event->pos(), resizeHandlePos);
    resizeHandlePos = event->pos();
    update();
}

void MyWidget::setRectangleShape()
{
    _shape_registry.pushBackCurrentShapes(std::make_unique<Rectangle>(QRect(20, 20, 100, 50)));
    update();
}

void MyWidget::setCircleShape()
{
    _shape_registry.pushBackCurrentShapes(std::make_unique<Circle>(QRect(20, 20, 100, 100)));
    update();
}

void MyWidget::setTriangleShape()
{
    _shape_registry.pushBackCurrentShapes(std::make_unique<Triangle>(QRect(20, 20, 100, 100)));
    update();
}

void MyWidget::updateShapes() {
    update();
}

// void MyWidget::setShapeRegistry(ShapeRegistry &shape_reg)
// {
//     _shape_registry = shape_reg;
// }


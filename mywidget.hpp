#ifndef MYWIDGET_HPP
# define MYWIDGET_HPP

# include <QWidget>
# include <QPushButton>
# include <QMouseEvent>
# include <QVector>

# include "./Shapes/ShapeBase.hpp"
# include "./Shapes/Circle.hpp"
# include "./Shapes/Rectangle.hpp"
# include "./Shapes/Triangle.hpp"
# include "./Registries/ShapeRegistry.hpp"

class MyWidget : public QWidget {
    Q_OBJECT

public:
    MyWidget(ShapeRegistry &, QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    // QVector<std::shared_ptr<ShapeBase>> shapeList;
    ShapeRegistry   &_shape_registry;
    bool        isResizing;
    bool        isMoving;
    QPoint      resizeHandlePos;
    QPoint      moveOffset;
    ShapeBase   *currentResizingShape;
    ShapeBase   *currentMovingShape;
    Shape       currentShape;

    void handleMoving(QMouseEvent *event);
    void handleResizing(QMouseEvent *event);
    void moveShape(QMouseEvent *event);
    void resizeShape(QMouseEvent *event);

public slots:
    void setRectangleShape();
    void setCircleShape();
    void setTriangleShape();
    void updateShapes();

// public:
//     void    setShapeRegistry(ShapeRegistry &);
};

#endif /* MYWIDGET_H */

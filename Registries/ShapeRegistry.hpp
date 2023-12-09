#ifndef REGISTRIES_SHAPEREGISTRY_HPP
# define REGISTRIES_SHAPEREGISTRY_HPP

# include <iostream>
# include <map>
# include <vector>
# include <QVector>
# include <functional>
# include <QObject>


# include "../Shapes/Triangle.hpp"
# include "../Shapes/Circle.hpp"
# include "../Shapes/Rectangle.hpp"

using ShapeCtor = std::function<std::unique_ptr<ShapeBase>(OptionsValues)>;
using ShapeCtorMap = std::map< std::string, ShapeCtor >;
using CurrentShapes = QVector<std::shared_ptr<ShapeBase>>;

class ShapeRegistry: public QObject
{
    Q_OBJECT

private:
    // [TK] What is the meaning of the _current_shapes?
    // what's that got to do here?
    CurrentShapes    _current_shapes;
    ShapeCtorMap     _shape_constructors;

public:
    ShapeRegistry();
    ~ShapeRegistry();

public:
    void             registerShape(std::string , ShapeCtor );
    CurrentShapes    getCurrentShapes(); //???
    ShapeCtorMap     getShapeCtorMap(); // [TK] You should not expose your internal implementation, instead provide direct factory method
    // i.e std::unique_ptr<ShapeBase> Create(ShapeType, OptionsValues);
    void             pushBackCurrentShapes(std::unique_ptr<ShapeBase> shape); //???

signals:
    void shapeAdded();
};

#endif /*REGISTRIES_SHAPEREGISTRY_HPP*/

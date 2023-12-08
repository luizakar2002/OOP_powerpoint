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
    CurrentShapes    _current_shapes;
    ShapeCtorMap     _shape_constructors;

public:
    ShapeRegistry();
    ~ShapeRegistry();

public:
    void             registerShape(std::string , ShapeCtor );
    CurrentShapes    getCurrentShapes();
    ShapeCtorMap     getShapeCtorMap();
    void             pushBackCurrentShapes(std::unique_ptr<ShapeBase> shape);

signals:
    void shapeAdded();
};

#endif /*REGISTRIES_SHAPEREGISTRY_HPP*/

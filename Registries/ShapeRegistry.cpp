# include "ShapeRegistry.hpp"

ShapeRegistry::ShapeRegistry()
{
    registerShape("Triangle", [](OptionsValues operands) {
        return new Triangle(operands);
    });
    registerShape("Circle", [](OptionsValues operands) {
        return new Circle(operands);
    });


}

ShapeRegistry::~ShapeRegistry()
{

}

void    ShapeRegistry::registerShape(std::string shapeType, ShapeCtor constructor)
{    
    _shape_constructors[shapeType] = constructor;
}

std::vector<Shape *>   ShapeRegistry::getCurrentShapes()
{
    return _current_shapes;
}

ShapeCtorMap   ShapeRegistry::getShapeCtorMap()
{
    return _shape_constructors;
}

void    ShapeRegistry::updateCurrentShapes(Shape *new_shape)
{
    _current_shapes.push_back(new_shape);
}

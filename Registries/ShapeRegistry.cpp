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
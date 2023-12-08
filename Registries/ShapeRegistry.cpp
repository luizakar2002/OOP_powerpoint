# include "ShapeRegistry.hpp"

ShapeRegistry::ShapeRegistry()
{
    registerShape("Triangle", [](OptionsValues operands)
    {
        return std::make_unique<Triangle>(operands);
    });
    registerShape("Circle", [](OptionsValues operands)
    {
        return std::make_unique<Circle>(operands);
    });
    registerShape("Rectangle", [](OptionsValues operands)
    {
        return std::make_unique<Rectangle>(operands);
    });

}

ShapeRegistry::~ShapeRegistry()
{

}

void    ShapeRegistry::registerShape(std::string shapeType, ShapeCtor constructor)
{
    _shape_constructors[shapeType] = constructor;
}

CurrentShapes   ShapeRegistry::getCurrentShapes()
{
    return _current_shapes;
}

ShapeCtorMap   ShapeRegistry::getShapeCtorMap()
{
    return _shape_constructors;
}

void ShapeRegistry::pushBackCurrentShapes(std::unique_ptr<ShapeBase> shape)
{
    _current_shapes.push_back(std::move(shape));
    emit shapeAdded();
}

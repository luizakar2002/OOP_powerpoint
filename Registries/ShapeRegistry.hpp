#ifndef REGISTRIES_SHAPEREGISTRY_HPP
# define REGISTRIES_SHAPEREGISTRY_HPP

# include <iostream>
# include <map>
# include <vector>
# include <functional>

# include "../Shapes/Triangle.hpp"
# include "../Shapes/Circle.hpp"

using ShapeCtor = std::function< Shape*(OptionsValues)>;
using ShapeCtorMap = std::map< std::string, ShapeCtor >;

class ShapeRegistry
{
    private:
        std::vector<Shape *>     _current_shapes;
        ShapeCtorMap             _shape_constructors;
    public:
        ShapeRegistry();
        ~ShapeRegistry();

    public:
        void                    registerShape(std::string , ShapeCtor );
        std::vector<Shape *>    getCurrentShapes();
        ShapeCtorMap            getShapeCtorMap();
        void                    updateCurrentShapes(Shape *);
};

#endif /*REGISTRIES_SHAPEREGISTRY_HPP*/
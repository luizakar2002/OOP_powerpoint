#ifndef SHAPE_HPP
# define SHAPE_HPP

# include <unordered_map>

using OptionsValues = std::unordered_map<std::string, std::string>;

class Shape
{
    public:
        virtual ~Shape();

        // virtual void display() = 0;
};

#endif /*SHAPE_HPP*/
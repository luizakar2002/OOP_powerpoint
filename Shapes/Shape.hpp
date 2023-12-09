#ifndef SHAPE_HPP
# define SHAPE_HPP

# include <iostream>
# include <unordered_map>

using OptionsValues = std::unordered_map<std::string, std::string>;

class Shape
{
    public:
        virtual ~Shape() {}; // TK: use = default instead giving body

        // TK: What is th purpose of the display method?
        virtual void display() = 0;
};

#endif /*SHAPE_HPP*/

#ifndef TRIANGLE_HPP
# define TRIANGLE_HPP

# include "Shape.hpp"

class Triangle : public Shape
{
    private:
        OptionsValues       _opt; // TEMPORARY, later pos, line style and so on should be extracted from opt and kept seperately
    public:
        Triangle(OptionsValues);
        virtual ~Triangle();

    public:
        

};

#endif /*TRIANGLE_HPP*/
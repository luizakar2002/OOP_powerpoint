#ifndef CIRCLE_HPP
# define CIRCLE_HPP

# include "Shape.hpp"

class Circle : public Shape
{
    private:
        OptionsValues       _opt; // TEMPORARY, later pos, line style and so on should be extracted from opt and kept seperately
    public:
        Circle(OptionsValues);
        virtual ~Circle() {};

    public:
        void    display() override;

};

#endif /*CIRCLE_HPP*/
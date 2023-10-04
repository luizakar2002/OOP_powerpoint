# include "Circle.hpp"

Circle::Circle(OptionsValues opt)
{
    _opt = opt;
}

void    Circle::display()
{
    std::cout << "Circle" << std::endl;
    for (const auto& pair : _opt)
    {
        std::cout << "Option: " << pair.first << ", Value: " << pair.second << std::endl;
    }
}
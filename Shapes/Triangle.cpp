# include "Triangle.hpp"

Triangle::Triangle(OptionsValues opt)
{
    _opt = opt;
}

void    Triangle::display()
{
    std::cout << "Triangle" << std::endl;
    for (const auto& pair : _opt)
    {
        std::cout << "Option: " << pair.first << ", Value: " << pair.second << std::endl;
    }
}
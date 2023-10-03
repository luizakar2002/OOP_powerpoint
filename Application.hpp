#ifndef APPLICATION_HPP
# define APPLICATION_HPP

# include "Commands/Command.hpp"
# include "Parser.hpp"
// # include "Registries/CommandRegistry.hpp"
# include "Registries/ShapeRegistry.hpp"

class Application
{
    private:
        Parser              _parser;
        ShapeRegistry       _shape_registry;

        
        // CommandRegistry     _command_registry;
    public:
        Application();
        ~Application();

    public:
        void    run();
};

#endif /*APPLICATION_HPP*/
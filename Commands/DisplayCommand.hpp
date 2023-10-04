#ifndef DISPLAYCOMMAND_HPP
# define DISPLAYCOMMAND_HPP

# include "Command.hpp"

class DisplayCommand : public Command
{
    private:
        OptionsValues   _options_values;
    public:
        DisplayCommand();
        DisplayCommand(OptionsValues);
        virtual ~DisplayCommand();

    public:
        void    execute(ShapeRegistry &) override;
        void    setOptionsValues(OptionsValues) override;
};

#endif /*DISPLAYCOMMAND_HPP*/
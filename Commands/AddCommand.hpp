#ifndef ADDCOMMAND_HPP
# define ADDCOMMAND_HPP

# include "Command.hpp"

class AddCommand : public Command
{
    private:
        OptionsValues   _options_values;
    public:
        AddCommand();
        AddCommand(OptionsValues);
        virtual ~AddCommand();

    public:
        void    execute(ShapeRegistry &) override;
        void    setOptionsValues(OptionsValues) override;
};

#endif /*ADDCOMMAND_HPP*/
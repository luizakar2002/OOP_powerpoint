# include "CommandRegistry.hpp"

# include "../Commands/AddItemCommand.hpp"
# include "../Commands/AddSlideCommand.hpp"
# include "../Commands/HelpCommand.hpp"
# include "../Commands/QuitCommand.hpp"

CommandRegistry::CommandRegistry()
{
    registerCommand("Add", []() {return std::make_unique<AddItemCommand>(); });
    registerCommand("AddSlide", []() {return std::make_unique<AddSlideCommand>(); });
    registerCommand("Help", []() {return std::make_unique<HelpCommand>(); });
    registerCommand("Quit", []() {return std::make_unique<QuitCommand>(); });

    // _registry["Display"] = std::make_unique<CreateSlideCommand>();
    // _registry["change"] = std::make_unique<ChangeItemCommand>();
    // _registry["goSlide"] = std::make_unique<GoSlideCommand>();
    // _registry["display"] = std::make_unique<DisplayCommand>();       
    // _registry["draw"] = std::make_unique<DrawCommand>();       
    // _registry["list"] = std::make_unique<ListCommand>();

    // _registry["quit"] = std::make_unique<QuitCommand>();
}

void    CommandRegistry::registerCommand(const std::string &commandName, Creator creator)
{
    _commandCreators[commandName] = creator;
}

CommandPtr CommandRegistry::create_raw_Command(const std::string &commandName)
{
    auto commandIter = _commandCreators.find(commandName);    
    if(commandIter == _commandCreators.end())
        throw std::runtime_error("Command is invalid! See Help.");
    return commandIter->second();
}

# include "Application.hpp"

Application::Application()
{
    // _parser = Parser();
    // _shape_registry = ShapeRegistry();
}

Application::~Application()
{

}

void    Application::run()
{
    while (42)
    {
        std::string userInput;
        std::vector<std::string> words;

        std::cout << "Enter a sentence: ";
        std::getline(std::cin, userInput);

        std::istringstream iss(userInput);
        std::string word;

        while (iss >> word) {
            words.push_back(word);
        }

        Command *command = _parser.parse(words);
        command->execute(_shape_registry);
    }
}
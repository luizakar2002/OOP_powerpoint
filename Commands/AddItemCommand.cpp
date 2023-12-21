# include "AddItemCommand.hpp"
# include <QDebug>
# include <string>

void    AddItemCommand::execute()
{
    std::string     item_type;
    ItemPtrUnique   new_item;

    item_type = _options_values["-item"];
    qDebug()<< "SHAPE NAME " << item_type << "/n";

    new_item = _itemFactory.create_raw_Item(item_type); // Item validity is checked here
    new_item->setOptionsValues(_options_values);

    auto it = _options_values.find("-x");
    if (it != _options_values.end())
    {
        new_item->getBoundingBox().setTopLeftX(std::stoi(it->second));
    }

    it = _options_values.find("-y");
    if (it != _options_values.end())
    {
        new_item->getBoundingBox().setTopLeftY(std::stoi(it->second));
    }

    Application::instance()->get_current_slide()->add_item(std::move(new_item));
}

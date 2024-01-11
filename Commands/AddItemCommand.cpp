# include "AddItemCommand.hpp"
# include <QDebug>
# include <string>

const ItemTypes AddItemCommand::_item_types = {
    {"Rectangle", ItemType::Rectangle},
    {"Ellipse", ItemType::Ellipse},
    {"Triangle", ItemType::Triangle}
};

void    AddItemCommand::execute()
{
    std::string     item_type;
    ItemPtrUnique   new_item;

    item_type = _options_values["-item"];
    qDebug()<< "SHAPE NAME " << item_type << "/n";

    new_item = std::make_unique<Item>(parse_item_type(item_type));
    new_item->setOptionsValues(_options_values);

    // auto it = _options_values.find("-x");
    // if (it != _options_values.end())
    // {
    //     new_item->getBoundingBox().setTopLeftX(std::stoi(it->second));
    // }

    // it = _options_values.find("-y");
    // if (it != _options_values.end())
    // {
    //     new_item->getBoundingBox().setTopLeftY(std::stoi(it->second));
    // }

    parse_item_coords(std::move(new_item));
    Application::instance()->get_current_slide()->add_item(std::move(new_item));
}

ItemType    AddItemCommand::parse_item_type(std::string item_type)
{
    auto it = _item_types.find(item_type);
    if (it != _item_types.end())
        return it->second;

    throw std::runtime_error("This item is not available AddItem: " + item_type); // catched in QtController

}

void    AddItemCommand::parse_item_coords(ItemPtrUnique&& new_item)
{
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
}

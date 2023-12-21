#ifndef APPLICATION_HPP
# define APPLICATION_HPP

# include <QApplication>

# include "../Document/Document.hpp"
# include "../Parser/CommandCreator.hpp"
# include "Renderer/SlideRenderer.hpp"
# include "../Document/Items/ItemFactory.hpp"
# include "QtController.hpp"

class Application : public QApplication
{
private:
    size_t              _current_slide_id;
    Document            _document;
    CommandCreator      _commandCreator;
    SlideRenderer       _slideRenderer;
    ItemFactory         _itemFactory;
    QtController        _qtController;

public:
    static Application  *instance();
    Application(int argc, char **argv);

    int     exec();
    void    quit();

    Document            &get_document();
    CommandCreator      &get_commandCreator();

    SlideRenderer       &get_slideRenderer();
    ItemFactory         &get_itemFactory();
    QtController        &getQtController();

    size_t              &get_current_slide_id();
    SlidePtr            get_current_slide();

};

#endif /*APPLICATION_HPP*/

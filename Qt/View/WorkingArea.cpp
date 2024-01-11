# include "WorkingArea.hpp"
# include "../Application.hpp"
# include <QPaintEvent>
# include <QPainter>

WorkingArea::WorkingArea(QWidget *parent)
    : QWidget{parent}
{
    setMinimumSize(800,600);
}

void WorkingArea::paintEvent(QPaintEvent *event)
{
    auto currentSlide = Application::instance()->get_current_slide();
    QImage image(size(), QImage::Format_ARGB32_Premultiplied);

    Application::instance()->get_slideRenderer().renderSlide(currentSlide, &image);

    QPainter widgetPainter(this);
    widgetPainter.drawImage(0, 0, image);
}

void WorkingArea::onDocumentChanged()
{
    this->update();
}

void WorkingArea::setRectangleShape()
{
    ItemPtrUnique new_raw_item = std::make_unique<Item>(ItemType::Rectangle);
    Application::instance()->get_current_slide()->add_item(std::move(new_raw_item));
    update();
}

void WorkingArea::setCircleShape()
{
    ItemPtrUnique new_raw_item = std::make_unique<Item>(ItemType::Ellipse);
    Application::instance()->get_current_slide()->add_item(std::move(new_raw_item));
    update();
}

void WorkingArea::setTriangleShape()
{
    ItemPtrUnique new_raw_item = std::make_unique<Item>(ItemType::Triangle);
    Application::instance()->get_current_slide()->add_item(std::move(new_raw_item));
    update();
}

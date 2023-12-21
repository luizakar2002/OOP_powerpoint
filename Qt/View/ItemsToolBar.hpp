#ifndef QT_VIEW_ITEMSTOOLBAR_HPP
#define QT_VIEW_ITEMSTOOLBAR_HPP

#include <QToolBar>

class ItemsToolBar : public QToolBar
{
    Q_OBJECT

signals:
    void rectangleShapeSelected();
    void ellipseShapeSelected();
    void triangleShapeSelected();
    void textShapeSelected();

public:
    ItemsToolBar(QToolBar* parent = nullptr);
};

#endif /*QT_VIEW_ITEMSTOOLBAR_HPP*/

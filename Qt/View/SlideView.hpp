#ifndef QT_VIEW_SLIDEVIEW_HPP
# define QT_VIEW_SLIDEVIEW_HPP

#include <QWidget>

class QStandardItemModel;
class QTreeView;

class SlideView : public QWidget
{
    Q_OBJECT
    
public:
    SlideView(QWidget* parent = nullptr);

private:
    void updateDocumentTree();

signals:
    void signalExpanded(int);

public slots:
    void onExpanded(const QModelIndex &index);
    void onDocumentChanged();

private:
    QStandardItemModel* model;
};

#endif /*QT_VIEW_SLIDEVIEW_HPP*/

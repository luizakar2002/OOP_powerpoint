#include "SlideView.hpp"
#include "../Application.hpp"

#include <QTreeView>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QVBoxLayout>

SlideView::SlideView(QWidget *parent)
    : QWidget(parent), model(new QStandardItemModel)
{
    QTreeView* documentTree = new QTreeView(this);
    documentTree->header()->hide();
    documentTree->setVisible(true);
    documentTree->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    updateDocumentTree();

    documentTree->setModel(model);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(documentTree);
    setFixedWidth(180);

    connect(documentTree, &QTreeView::expanded, this, &SlideView::onExpanded);
}

void SlideView::updateDocumentTree()
{
    int slideIdx = 1;

    for (auto &slide : Application::instance()->get_document().get_slides())
    {
        QStandardItem *slideItem = new QStandardItem("Slide " + QString::number(slideIdx));

        model->appendRow(slideItem);
        ++slideIdx;
    }
}

void SlideView::onExpanded(const QModelIndex &index){
    qDebug() << index.row();
}

void SlideView::onDocumentChanged(){
    model->clear();
    updateDocumentTree();
}


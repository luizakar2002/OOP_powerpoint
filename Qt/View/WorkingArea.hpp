#ifndef QT_VIEW_WORKING_AREA_HPP
# define QT_VIEW_WORKING_AREA_HPP

# include <QWidget>
# include <QList>

class WorkingArea : public QWidget
{
    Q_OBJECT
public:
    explicit WorkingArea(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;

public slots:
    void onDocumentChanged();

public slots:
    void setRectangleShape();
    void setCircleShape();
    void setTriangleShape();

};

#endif /*QT_VIEW_WORKING_AREA_HPP*/

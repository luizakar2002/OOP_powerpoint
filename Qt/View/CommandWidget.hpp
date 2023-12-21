#ifndef QT_VIEW_COMMANDWIDGET_HPP
# define QT_VIEW_COMMANDWIDGET_HPP

# include <QWidget>
# include <QLineEdit>
# include "CommandLog.hpp"

class CommandWidget : public QWidget
{
    Q_OBJECT
public:
    CommandWidget(QWidget* parent = nullptr);

signals:
    void commandEntered(std::istream& is);
    void signalSetText(const QString& text);

public slots:
    void logCommand(const std::string& output);
    
private slots:
    void executeCommand();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    void pushCommand(const QString& command);

private:
    QLineEdit* commandLine;
    CommandLog* commandLog;
    QList<QString> inputHistory;
    QList<QString>::iterator it;
};

#endif //QT_VIEW_COMMANDWIDGET_HPP
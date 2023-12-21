#include "CommandWidget.hpp"
#include <QVBoxLayout>
#include <QKeyEvent>
#include <sstream>

CommandWidget::CommandWidget(QWidget *parent)
    : QWidget(parent)
{
    commandLine = new QLineEdit;
    commandLog = new CommandLog;

    QVBoxLayout* layout = new QVBoxLayout; 
    layout->addWidget(commandLine);
    layout->addWidget(commandLog);
    setLayout(layout);

    connect(this, &CommandWidget::signalSetText, commandLine, &QLineEdit::setText);
    connect(commandLine, &QLineEdit::returnPressed, this, &CommandWidget::executeCommand);
}

void CommandWidget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Up:
        if(it != inputHistory.begin() || !inputHistory.empty()){
            --it;
        }
        break;
    case Qt::Key_Down:
        if(it != std::prev(inputHistory.end()) || !inputHistory.empty()){
            ++it;
        }
        break;
    }
}

void CommandWidget::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Up:
        emit signalSetText(*it);
        break;
    case Qt::Key_Down:
        emit signalSetText(*it);
        break;
    }
}

void CommandWidget::pushCommand(const QString &command)
{
    inputHistory.push_back(command);
    it = std::prev(inputHistory.end());
}

void CommandWidget::executeCommand()
{
    pushCommand(commandLine->text());
    std::istringstream iss{commandLine->text().toStdString()};
    emit commandEntered(iss);
    commandLine->clear();
}

void CommandWidget::logCommand(const std::string& output)
{
    commandLog->append(QString::fromStdString(output));
}

#ifndef QT_VIEW_COMMANDLOG_HPP
# define QT_VIEW_COMMANDLOG_HPP

# include <QTextEdit>

class CommandLog : public QTextEdit
{
    Q_OBJECT
public:
    CommandLog(QWidget* parrent = nullptr);
};

#endif /*QT_VIEW_COMMANDLOG_HPP*/

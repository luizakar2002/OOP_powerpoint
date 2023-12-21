#ifndef QT_UICONTROLLER_HPP
# define QT_UICONTROLLER_HPP

# include <iosfwd>
# include <QObject>

class QtController : public QObject
{
    Q_OBJECT

public slots:
    void runCommand(std::istream& input);

public:
    void logOutput(const std::string& message);
    void documentChanged();
signals:
    void signalDocumentChanged();
    void logOutputSignal(const std::string& message);
};

#endif /*QT_UICONTROLLER_HPP*/
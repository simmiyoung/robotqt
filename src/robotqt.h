#ifndef ROBOTQT_H
#define ROBOTQT_H

#include <QMainWindow>

class QTabWidget;
class QListWidget;
class QTextEdit;
class QSplitter;

class RobotQt : public QMainWindow
{
    Q_OBJECT

public:
    RobotQt();
    ~RobotQt();


private:
    QTabWidget *leftTab;
    QListWidget *listStatus;
    QTextEdit *editSource;
    QWidget *right2DGraph;
    QSplitter *mainSplitter;

    void readSettings();
};

#endif // ROBOTQT_H

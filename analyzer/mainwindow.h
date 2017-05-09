#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>

#include <QPushButton>
#include <QLineEdit>

#include "WordFrequencyCounter.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QPushButton* startButton;
    QPushButton* browseButton;
    QLineEdit*   lineEdit;
private slots:
    void start();

};

#endif // MAINWINDOW_H

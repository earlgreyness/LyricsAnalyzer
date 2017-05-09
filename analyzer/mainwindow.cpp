#include "mainwindow.h"

#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    startButton = new QPushButton(this);
    startButton->setText("Start");

    browseButton = new QPushButton(this);
    browseButton->setText("Browse...");

    lineEdit = new QLineEdit(this);



    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(lineEdit);
    layout->addWidget(browseButton);
    layout->addWidget(startButton);

    this->setLayout(layout);

    connect(startButton, SIGNAL(clicked()), this, SLOT(start()));


    WordFrequencyCounter counter;
    counter.printResults();
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::start()
{

}

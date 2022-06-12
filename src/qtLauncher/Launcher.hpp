#ifndef LAUNCHER_HPP
#define LAUNCHER_HPP

// Qt
#include <QApplication>
#include <QWidget>
#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QRadioButton>  
#include <QSplitter>
#include <QLineEdit>
#include <QListView>
#include <QTableView>
#include <QSpacerItem>
#include <QEvent>
#include <QGroupBox>
#include <QDesktopWidget>
#include <QTextStream>
#include <QMainWindow>
#include <QIcon>
#include <QStatusBar>

// STANDARD
#include <iostream>
#include <exception>
#include <fstream>

// NETWORK
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

class Launcher : public QMainWindow
{
    Q_OBJECT
    
    public:
    explicit Launcher(QWidget *parent = 0);
    
    private slots:
        void slotEnableHost();
        void soltDisableHost();
        void checkFormIsValid();
    
    private:
        QLineEdit* host;
        QLineEdit* port;
        QLineEdit* name;
        QRadioButton* rHost;
        QRadioButton* rClient;
};

#endif
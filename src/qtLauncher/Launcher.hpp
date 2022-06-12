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
#include <QIcon>

#include <iostream>
#include <exception>
#include <fstream>

class Launcher : public QWidget
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
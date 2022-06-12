#include "Launcher.hpp"

Launcher::Launcher(QWidget *parent) : QWidget(parent) {   
    setFixedSize(270, 230);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());
    setWindowTitle("Launcher");
    show();

    QVBoxLayout* main_section = new QVBoxLayout();

    // #========= Section ROLE =========#
    QGroupBox* group_role = new QGroupBox(tr("What are you ?"));
    QHBoxLayout* section_role = new QHBoxLayout();
    
    rHost = new QRadioButton("Host");
    rClient = new QRadioButton("Client");

    rHost->setChecked(true);

    section_role->addWidget(rHost);
    section_role->addWidget(rClient);

    group_role->setLayout(section_role);

    // #========= Section settings =========#
    QFormLayout* section_settings = new QFormLayout();

    host = new QLineEdit();
    host->setDisabled(true);
    port = new QLineEdit("6000");
    name = new QLineEdit();

    host->setMaxLength(15);
    port->setMaxLength(5);
    name->setMaxLength(20);

    section_settings->addRow("Host IP: ", host);
    section_settings->addRow("Port: ", port);
    section_settings->addRow("Name: ", name);

    // #========= Section validation =========#
    QHBoxLayout* section_valid = new QHBoxLayout();

    QPushButton* valid = new QPushButton("Launch");
    QPushButton* quit = new QPushButton("Quit");

    section_valid->addWidget(valid);
    section_valid->addWidget(quit);

    // #========= Creating menu =========#
    main_section->addWidget(group_role);
    main_section->addSpacing(5);
    main_section->addLayout(section_settings);
    main_section->addLayout(section_valid);

    connect(quit, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
    connect(rHost, SIGNAL(clicked()), this, SLOT(soltDisableHost()));
    connect(rClient, SIGNAL(clicked()), this, SLOT(slotEnableHost()));
    connect(valid, SIGNAL(clicked()), this, SLOT(checkFormIsValid()));

    setLayout(main_section);
}

void Launcher::slotEnableHost() { host->setDisabled(false); }

void Launcher::soltDisableHost() { host->setDisabled(true); }

void Launcher::checkFormIsValid() { 
    // Checking host IP address is valid
    bool IP_convert_success=true;
    QString host_str = host->text();
    if(host->isEnabled()) {
        QStringList pieces = host_str.split(".");

        if(pieces.size()==4) {
            for(QString str: pieces) {
                int temp = str.toInt(&IP_convert_success, 10);
                if(temp>255) { IP_convert_success = false; }
                
                if(!IP_convert_success) { break; }
            }
        } else { IP_convert_success = false; }
    }

    // Checking port is valid
    QString port_str = port->text();
    bool port_conv_succ = true;
    port_str.toInt(&port_conv_succ, 10);

    if(port_conv_succ && IP_convert_success) {
        std::ofstream file("./conf.cfg");

        if(file) {
            if(rHost->isChecked()) {
                file << 0 << " " << port_str.toStdString() << " " << name->text().toStdString();
            } else {
                file << 1 << " " << host_str.toStdString() << " " << port_str.toStdString() << " " << name->text().toStdString();
            }   
        } else {
            std::cout << "> [ERROR] impossible d'ouvrir le fichier de configuration" << std::endl;
        }

        file.close();
        QApplication::instance()->quit();
    }
    else {
        if(!port_conv_succ) {
            port->setText("");
            port->setPlaceholderText("#INVALID#");
        }
        if(!IP_convert_success) {
            host->setText("");
            host->setPlaceholderText("#INVALID#");
        }
    }
}
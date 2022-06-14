#include "Launcher.hpp"

Launcher::Launcher(bool* runApp,QWidget *parent) : status(runApp), QMainWindow(parent) {   
    
    QScreen *screen = QGuiApplication::primaryScreen();
    setGeometry(screen->size().width()/2 - 270/2, screen->size().height()/2 - 230/2,270, 230);
    setWindowTitle("Launcher");
    show();

    QVBoxLayout* main_section = new QVBoxLayout();

    // #========= Section ROLE =========#
    QGroupBox* group_role = new QGroupBox(tr("Network settings"));
    QHBoxLayout* section_role = new QHBoxLayout();
    
    rHost = new QRadioButton("Host");
    rClient = new QRadioButton("Join");

    rHost->setChecked(true);

    section_role->addWidget(rHost);
    section_role->addWidget(rClient);

    group_role->setLayout(section_role);

    // #========= Section settings =========#
    QFormLayout* section_settings = new QFormLayout();

    host = new QLineEdit("");
    host->setDisabled(true);
    port = new QLineEdit("6000");
    name = new QLineEdit("");

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
    main_section->addSpacing(10);
    main_section->addLayout(section_valid);

    connect(quit, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
    connect(rHost, SIGNAL(clicked()), this, SLOT(soltDisableHost()));
    connect(rClient, SIGNAL(clicked()), this, SLOT(slotEnableHost()));
    connect(valid, SIGNAL(clicked()), this, SLOT(slotcheckFormIsValid()));

    QWidget* widget = new QWidget();
    widget->setLayout(main_section);
    setCentralWidget(widget);
}

void Launcher::slotEnableHost() { host->setDisabled(false); }

void Launcher::soltDisableHost() { host->setDisabled(true); }

void Launcher::slotcheckFormIsValid() { 

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

    // Checking port syntax is valid
    QString port_str = port->text();
    bool port_conv_succ = true;
    bool port_valid=true;
    port_str.toInt(&port_conv_succ, 10);

    // Testing if the port is available
    if(!host->isEnabled()) {
        int server_sock;
        sockaddr_in server;
        server_sock = socket(AF_INET, SOCK_STREAM, 0);
        if(server_sock==-1) { 
            std::cout << "> [ERROR] can't init socket" << std::endl;
        }
        server.sin_addr.s_addr = INADDR_ANY;
        server.sin_family = AF_INET;
        server.sin_port = htons(atoi(port_str.toStdString().c_str()));
        if (bind(server_sock, (struct sockaddr *) &server, sizeof(server)) == -1) { 
            std::cout << "[ERROR] port already used " << std::endl;    
            port_valid=false;
        }
        ::close(server_sock);
    }

    // Checking name
    QString name_str = name->text();
    bool name_valid=true;
    if(name_str.toStdString().size()==0) name_valid=false;

    // Conclusion of validation of the form
    if(port_conv_succ && IP_convert_success && port_valid && name_valid) {
        *status = true;
        std::ofstream file("./conf.cfg");

        if(file) {
            if(rHost->isChecked()) {
                file << 0 << std::endl << "" << std::endl << port_str.toStdString() << std::endl << name_str.toStdString();
            } else {
                file << 1 << std::endl << host_str.toStdString() << std::endl << port_str.toStdString() << std::endl << name->text().toStdString();
            }   
        } else {
            std::cout << "> [ERROR] impossible d'ouvrir le fichier de configuration" << std::endl;
        }

        file.close();
        QApplication::instance()->quit();
    }
    else {
        if(!name_valid) {
            name->setText("");
            name->setPlaceholderText("#EMPTY#");
        }

        if(!port_conv_succ) {
            port->setText("");
            port->setPlaceholderText("#INVALID#");
        } else {
            if(!port_valid) {
                port->setText("");
                port->setPlaceholderText("#ALREADY_USED#");
                
            }
        }
        
        if(!IP_convert_success) {
            host->setText("");
            host->setPlaceholderText("#INVALID#");
        }
    }
}
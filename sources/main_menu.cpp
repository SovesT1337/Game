#include <main_menu.hpp>

int menu(int argc, char *argv[])
{
    QApplication menu(argc, argv);

    Menu window;

    window.resize(1920, 1080);
    window.setWindowTitle("MENU");
    window.show();

    return menu.exec();
}

Menu::Menu(QWidget *parent)
{
    LoadImages();

    LoadConfig();
    LoadButtons();
    InitGame();
}

void Menu::LoadConfig()
{
    ifstream input("/home/sovest/CLionProjects/Game/config/Config.json");
    input >> config;
}

void Menu::LoadImages()
{
    back.load("/home/sovest/CLionProjects/Game/images/back.png");
}

void Menu::LoadButtons()
{
    level01 = new QPushButton("Level 1", this);
    level02 = new QPushButton("Level 2", this);
    level03 = new QPushButton("Level 3", this);
    exit = new QPushButton("Exit", this);
    level01->move(900, 300);
    level02->move(1920, 1080);
    level03->move(1920, 1080);
    exit->move(1650, 350);
    if (config["Level01"] == true)
        level02->move(900, 400);
    if (config["Level02"] == true)
        level03->move(900, 500);

    connect(exit, &QPushButton::clicked, this, &Menu::Exit);
    connect(level01, &QPushButton::clicked, this, &Menu::LoadLevel1);
    connect(level02, &QPushButton::clicked, this, &Menu::LoadLevel2);
    connect(level03, &QPushButton::clicked, this, &Menu::LoadLevel3);
}

void Menu::Exit()
{
    ofstream out(configfile);
    out.close();
    config["Alive"] = false;
    out.open("/home/sovest/CLionProjects/Game/config/Config.json");
    out << config;
    out.close();
    QApplication::quit();
}

void Menu::LoadLevel1()
{
    json battle = {{"Enemy1", "/home/sovest/CLionProjects/Game/config/Enemy1.json"},
                   {"Enemy2", "/home/sovest/CLionProjects/Game/config/Enemy1.json"},
                   {"Enemy3", "/home/sovest/CLionProjects/Game/config/Enemy1.json"},
                   {"Enemy4", "/home/sovest/CLionProjects/Game/config/Enemy1.json"}};
    ofstream out("/home/sovest/CLionProjects/Game/config/Battle.json");
    out << battle;
    out.close();
    config["Level01"] = true;
    out.open("/home/sovest/CLionProjects/Game/config/Config.json");
    out << config;
    out.close();
    QApplication::quit();
}

void Menu::LoadLevel2()
{
    json battle = {{"Enemy1", "/home/sovest/CLionProjects/Game/config/Enemy1.json"},
                   {"Enemy2", "/home/sovest/CLionProjects/Game/config/Enemy1.json"},
                   {"Enemy3", "/home/sovest/CLionProjects/Game/config/Enemy1.json"},
                   {"Enemy4", "/home/sovest/CLionProjects/Game/config/Enemy1.json"}};
    ofstream out("/home/sovest/CLionProjects/Game/config/Battle.json");
    out << battle;
    out.close();
    config["Level02"] = true;
    out.open("/home/sovest/CLionProjects/Game/config/Config.json");
    out << config;
    out.close();
    QApplication::quit();
}

void Menu::LoadLevel3()
{
    json battle = {{"Enemy1", "/home/sovest/CLionProjects/Game/config/Enemy1.json"},
                   {"Enemy2", "/home/sovest/CLionProjects/Game/config/Enemy1.json"},
                   {"Enemy3", "/home/sovest/CLionProjects/Game/config/Enemy1.json"},
                   {"Enemy4", "/home/sovest/CLionProjects/Game/config/Enemy1.json"}};
    ofstream out("/home/sovest/CLionProjects/Game/config/Battle.json");
    out << battle;
    out.close();
    config["Level03"] = true;
    out.open("/home/sovest/CLionProjects/Game/config/Config.json");
    out << config;
    out.close();
    QApplication::quit();
}

void Menu::doDrowing()
{
    QPainter qp(this);

    qp.drawImage(0, 0, back);
}

void Menu::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    doDrowing();
}

void Menu::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);

    repaint();
}

void Menu::InitGame()
{
    timerId = startTimer(DELAY);
}

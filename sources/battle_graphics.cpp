// Copyright by SovesT 2021
// Created by sovest on 30.10.2021.
//

#include <battle_graphics.hpp>

int battle(int argc, char *argv[])
{
    QApplication battle(argc, argv);
    Battle window;
    window.resize(1920, 1080);
    window.setWindowTitle("BATTLE");
    window.show();
    return battle.exec();
}

Battle::Battle(QWidget *parent)
{
    srand(time(NULL));
    LoadImages();
    LoadChar();
    LoadEnemy();
    LoadLabels();
    InitGame();
}

void Battle::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter qp(this);
    qp.drawImage(0, 0, back);

    if (enemy[0].dead() && enemy[1].dead() && enemy[2].dead() && enemy[3].dead())
        YouWin(qp);
    if (stud[0].dead() && stud[1].dead() && stud[2].dead() && stud[3].dead())
        GameOver(qp);
    doDrowing();
}

void Battle::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);
    if (!attacking && !recieving && !gamefinished)
    {
        if (turn < 4)
        {
            click1 = turn;
            if (stud[turn].dead())
                turn++;
        }
        if (turn >= 4)
        {
            if (!enemy[turn - 4].dead())
                recieving = true;
            else
                turn++;
        }
        if (turn == 8)
            turn = 0;
    }
    repaint();
}

void Battle::InitGame()
{
    timerId = startTimer(DELAY);
}

void Battle::YouWin(QPainter &qp)
{
    gamefinished = true;
    step++;
    if (step == 100)
    {
        for (size_t i = 0; i < 4; ++i)
        {
            stud[i].level_up();
            stud[i].save();
        }
    }
    if (step < 100)
        qp.drawImage(900, 350, youwin);
    if (step >= 100)
        qp.drawImage(900, 350, levelup);
    if (step == 200)
    {
        step = 0;
        QApplication::quit();
    }
}

void Battle::GameOver(QPainter &qp)
{
    gamefinished = true;
    step++;
    qp.drawImage(900, 350, gameover);
    if (step == 200)
    {
        json config;
        ifstream input("/home/sovest/CLionProjects/Game/config/Config.json");
        input >> config;
        config["Alive"] = false;
        input.close();
        ofstream out("/home/sovest/CLionProjects/Game/config/Config.json");
        out << config;
        out.close();
        QApplication::quit();
    }
}

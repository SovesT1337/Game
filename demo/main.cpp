#include <QApplication>
#include <QPushButton>
#include <battle_graphics.hpp>
#include <main_menu.hpp>
// #include <nlohmann/json.hpp>

using nlohmann::json;

void refresh()
{
       json config = {
           {"Name", "Saxman"},
           {"Type", "Archer"},
           {"HP", 80},
           {"MP", 10},
           {"Attack", 40},
           {"Armor", 0},
           {"Level", 1},
           {"Image1", "/home/sovest/CLionProjects/Game/images/archer_1.png"},
           {"Image2", "/home/sovest/CLionProjects/Game/images/archer_2.png"},
           {"Image3", "/home/sovest/CLionProjects/Game/images/archer_3.png"},
           {"Image4", "/home/sovest/CLionProjects/Game/images/archer_4.png"},
       };
       ofstream out("/home/sovest/CLionProjects/Game/config/Archer.json");
       out << config;
       out.close();

       config = {
           {"Name", "Trendkiller"},
           {"Type", "Damager"},
           {"HP", 80},
           {"MP", 0},
           {"Attack", 40},
           {"Armor", 0},
           {"Level", 1},
           {"Image1", "/home/sovest/CLionProjects/Game/images/damager_1.png"},
           {"Image2", "/home/sovest/CLionProjects/Game/images/damager_2.png"},
           {"Image3", "/home/sovest/CLionProjects/Game/images/damager_3.png"},
           {"Image4", "/home/sovest/CLionProjects/Game/images/damager_4.png"},
       };
       out.open("/home/sovest/CLionProjects/Game/config/Damager.json");
       out << config;
       out.close();

       config = {
           {"Name", "Viktor"},
           {"Type", "Tank"},
           {"HP", 100},
           {"MP", 0},
           {"Attack", 30},
           {"Armor", 20},
           {"Level", 1},
           {"Image1", "/home/sovest/CLionProjects/Game/images/tank_1.png"},
           {"Image2", "/home/sovest/CLionProjects/Game/images/tank_2.png"},
           {"Image3", "/home/sovest/CLionProjects/Game/images/tank_3.png"},
           {"Image4", "/home/sovest/CLionProjects/Game/images/tank_4.png"},
       };
       out.open("/home/sovest/CLionProjects/Game/config/Tank.json");
       out << config;
       out.close();

       config = {
           {"Name", "Katia"},
           {"Type", "Wisard"},
           {"HP", 60},
           {"MP", 10},
           {"Attack", 50},
           {"Armor", 0},
           {"Level", 1},
           {"Image1", "/home/sovest/CLionProjects/Game/images/wisard_1.png"},
           {"Image2", "/home/sovest/CLionProjects/Game/images/wisard_2.png"},
           {"Image3", "/home/sovest/CLionProjects/Game/images/wisard_3.png"},
           {"Image4", "/home/sovest/CLionProjects/Game/images/wisard_4.png"},
       };
       out.open("/home/sovest/CLionProjects/Game/config/Wisard.json");
       out << config;
       out.close();

       config = {{"Level01", false},
                 {"Level02", false},
                 {"Level03", false},
                 {"Alive", true}};
       out.open("/home/sovest/CLionProjects/Game/config/Config.json");
       out << config;
       out.close();
}

int main(int argc, char *argv[])
{
       refresh();
       ifstream input;
       json config;
       input.open("/home/sovest/CLionProjects/Game/config/Config.json");
       input >> config;
       input.close();
       while (config["Alive"] == true)
       {
              menu(argc, argv);
              input.open("/home/sovest/CLionProjects/Game/config/Config.json");
              input >> config;
              input.close();
              if (config["Alive"] == true)
                     battle(argc, argv);
       }
}

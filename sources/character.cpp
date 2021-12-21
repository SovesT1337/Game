// Copyright by SovesT 2021
// Created by sovest on 18.10.2021.
//

#include <character.hpp>
#include <utility>
#include <map>
#include <fstream>

using std::ifstream;
using std::map;
using std::ofstream;
using std::endl;
using std::to_string;

Character::Character()
{
    Name = "Clyde";
    Type = "NULL";
    HP = 1;
    MP = 1;
    Attack = 1;
    Armor = 1;
    Level = 1;
}

Character::Character(string file, pair<int, int> loc)
{
    map<string, string> config;
    ifstream input(file);
    if (input.is_open())
    {
        while (!input.eof())
        {
            string st;
            getline(input, st);
            string st1 = st.substr(0, st.find(' '));
            st.erase(0, st.find(' ') + 1);
            string st2 = st.substr(2, st.size());
            config[st1] = st2;
        }
    }
    input.close();
    Name = std::move(config["Name"]);
    Type = std::move(config["Type"]);
    HP = stoi(config["HP"]);
    MP = stoi(config["MP"]);
    Attack = stoi(config["Attack"]);
    Armor = stoi(config["Armor"]);
    Level = stoi(config["Level"]);
    Image1 = std::move(config["Image1"]);
    Image2 = std::move(config["Image2"]);
    Image3 = std::move(config["Image3"]);
    Image4 = std::move(config["Image4"]);
    image[0].load(QString::fromStdString(Image1));
    image[1].load(QString::fromStdString(Image2));
    image[2].load(QString::fromStdString(Image3));
    image[3].load(QString::fromStdString(Image4));
    rect = image[0].rect();
    location = loc;
    rect.moveTo(location.first, location.second);
    Config = std::move(file);
}

void Character::save(){
    ofstream out(Config);
    out << "Name = " << Name << endl;
    out << "Type = " << Type << endl;
    out << "HP = " << to_string(HP) << endl;
    out << "MP = " << to_string(MP) << endl;
    out << "Attack = " << to_string(Attack) << endl;
    out << "Armor = " << to_string(Armor) << endl;
    out << "Level = " << to_string(Level) << endl;
    out << "Image1 = " << Image1 << endl;
    out << "Image2 = " << Image2 << endl;
    out << "Image3 = " << Image3 << endl;
    out << "Image4 = " << Image4;
    out.close();
}

int Character::attack() const
{
    return Attack + (Attack * (rand() % 2) / 2);
}

int Character::magic_attack(int Attack_, int mana_usage)
{
    MP -= mana_usage;
    return Attack_;
}

void Character::get_damage(int damage)
{
    HP -= damage - Armor;
}

string Character::getHP()
{
    return std::to_string(HP);
}

void Character::recover_health(int heal)
{
    HP += heal;
}

void Character::recover_mana(int heal)
{
    MP += heal;
}

void Character::level_up()
{
    Level++;
    HP *= 1.2;
    Attack *= 1.2;
}

Character Character::operator=(Character *rhs)
{
    HP = rhs->HP;
    MP = rhs->MP;
    Attack = rhs->Attack;
    Armor = rhs->Armor;
    Level = rhs->Level;
    image[0] = rhs->image[0];
    image[1] = rhs->image[1];
    rect = rhs->rect;
    location = rhs->location;
    Name = rhs->Name;
    Type = rhs->Type;
    return *this;
}

QImage Character::getImage(int n)
{
    return image[n];
}

QRect Character::getRect()
{
    return rect;
}

QRect *Character::getRect_()
{
    return &rect;
}

pair<int, int> Character::getLocation()
{
    return location;
}

string Character::getName()
{
    return Name;
}

string Character::getType()
{
    return Type;
}

Character::~Character() = default;

bool Character::dead() { return HP <= 0; }
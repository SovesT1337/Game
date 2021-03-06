// Copyright by SovesT 2021
// Created by sovest on 18.10.2021.
//

#ifndef KURSACH_CHARACTER_HPP
#define KURSACH_CHARACTER_HPP

#include <string>
#include <QImage>
#include <QRect>
#include <utility>
#include <nlohmann/json.hpp>

using std::string;
using std::pair;
using std::vector;
using nlohmann::json;

class Character {
private:
    string Name;
    string Type;
    int HP;
    int MP;
    int Attack;
    int Armor;
    int Level;
    QImage image[4];
    QRect rect;
    pair<int, int> location;
    string Config;
    string Image1;
    string Image2;
    string Image3;
    string Image4;

public:
    Character();
    Character(string, pair<int, int>);
    ~Character();
    int attack() const;
    int magic_attack(int, int);
    void get_damage(int);
    void recover_mana(int);
    void recover_health(int);
    void level_up();
    void save();
    QImage getImage(int);
    QRect getRect();
    QRect* getRect_();
    string getName();
    string getType();
    string getHP();
    pair<int, int> getLocation();
    Character operator=(Character*);
    bool dead();
};

#endif //KURSACH_CHARACTER_HPP

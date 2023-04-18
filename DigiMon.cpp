#include <iostream>
#include <unistd.h>
// #include <Windows.h>
using namespace std;

// 数码宝贝基类
class Digimon {
protected:
    string name;
    int level;
    int attack;
    int defense;
    int hp;
    int satiety;
public:
    Digimon(string name, int level, int attack, int defense, int hp, int satiety) {
        this->name = name;
        this->level = level;
        this->attack = attack;
        this->defense = defense;
        this->hp = hp;
        this->satiety = satiety;
        this->experience = 0;
    }

    virtual void evolve() {}

    void gain_experience(int exp) {
        experience += exp;
        cout << name << " 获得了 " << exp << " 点经验值." << endl;
        level_up();
    }

    void level_up() {
        while (experience >= level * 10) {
            experience -= level * 10;
            level++;
            attack += 5;
            defense += 5;
            hp += 10;
            cout << name << " 升级了! 当前等级: " << level << endl;
            if (level == 16) {
                evolve();
            }
        }
    }
    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Attack: " << attack << endl;
        cout << "Defense: " << defense << endl;
        cout << "HP: " << hp << endl;
        cout << "Satiety: " << satiety << endl;
    }
    void eat(int satietyChange, int attackChange, int defenseChange, int hpChange) {
        satiety += satietyChange;
        if (satiety > 100) {
            satiety = 100;
        }
        attack += attackChange;
        defense += defenseChange;
        hp += hpChange;
        cout << name << " ate a meal and changed the attributes." << endl;
    }
};

// 派生类：火山兽
class Agumon: public Digimon {
public:
    Agumon(string name, int level): Digimon(name, level, 30, 20, 100, 50) {}

    void evolve() override {
        name = "Greymon";
        attack += 30;
        defense += 20;
        hp += 50;
        cout << "Agumon 进化成了 Greymon!" << endl;
    }
};

// 派生类：冰河兽
class Gabumon: public Digimon {
public:
    Gabumon(string name, int level): Digimon(name, level, 20, 30, 100, 50) {}

    void evolve() override {
        name = "Garurumon";
        attack += 20;
        defense += 30;
        hp += 50;
        cout << "Gabumon 进化成了 Garurumon!" << endl;
    }
};


// 主函数
int main() {
    Digimon *player = new Agumon("Agumon", 3);
    Digimon *enemy = new Gabumon("Gabumon", 2);
    player->display();
    sleep(3);
    player->eat(30, 5, 10, 0);
    player->display();
    sleep(3);
    player->gain_experience(100);
    player->display();
    delete player;
    delete enemy;
    return 0;
}

#include <iostream>
#include <unistd.h>
#include <vector>
#include <fstream>
// #include <Windows.h>
using namespace std;

class Digimon {
protected:
    string name;
    int level;
    int attack;
    int defense;
    int hp;
    int satiety;
    int experience;
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

public:
    // 新增技能结构体
    struct Skill {
        string name;
        int damage;
        int usage;
    };

    // 新增道具结构体
    struct Item {
        string name;
        int effect;
        int quantity;
    };

    vector<Skill> skills;
    vector<Item> items;

    // 新增战斗方法
    void battle(Digimon &opponent, bool autoMode);
    
    // 新增普通攻击方法
    void normalAttack(Digimon &opponent);
    
    // 新增技能攻击方法
    void skillAttack(Digimon &opponent, Skill &skill);
    
    // 新增使用道具方法
    void useItem(Item &item);

    // 保存游戏
    void saveGame() {
        ofstream saveFile("savegame.txt");
        if (saveFile.is_open()) {
            saveFile << name << endl;
            saveFile << level << endl;
            saveFile << attack << endl;
            saveFile << defense << endl;
            saveFile << hp << endl;
            saveFile << satiety << endl;
            saveFile << experience << endl;
            saveFile.close();
        } else {
            cout << "无法打开文件" << endl;
        }
    }

    // 加载游戏
    void loadGame() {
        ifstream loadFile("savegame.txt");
        if (loadFile.is_open()) {
            getline(loadFile, name);
            loadFile >> level;
            loadFile >> attack;
            loadFile >> defense;
            loadFile >> hp;
            loadFile >> satiety;
            loadFile >> experience;
            loadFile.close();
        } else {
            cout << "无法打开文件" << endl;
        }
    }
};

// 派生类：火山兽
class Agumon: public Digimon {
public:
    Agumon(string name, int level);

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
    Gabumon(string name, int level);

    void evolve() override {
        name = "Garurumon";
        attack += 20;
        defense += 30;
        hp += 50;
        cout << "Gabumon 进化成了 Garurumon!" << endl;
    }
};

// 在派生类的构造函数中初始化技能和道具
Agumon::Agumon(string name, int level): Digimon(name, level, 30, 20, 100, 50) {
    skills.push_back({"Fire Breath", 20, 5});
    items.push_back({"Health Potion", 50, 3});
}

Gabumon::Gabumon(string name, int level): Digimon(name, level, 20, 30, 100, 50) {
    skills.push_back({"Ice Blast", 20, 5});
    items.push_back({"Health Potion", 50, 3});
}

void Digimon::battle(Digimon &opponent, bool autoMode) {
    // 战斗逻辑
}

void Digimon::normalAttack(Digimon &opponent) {
    // 普通攻击逻辑
}

void Digimon::skillAttack(Digimon &opponent, Skill &skill) {
    // 技能攻击逻辑
}

void Digimon::useItem(Item &item) {
    // 使用道具逻辑
}

void adventure(Digimon *player) {
    // 冒险逻辑
}

void encounterEnemy(Digimon *player) {
    // 遇到怪物逻辑
}

void battleMenu(Digimon *player, Digimon *enemy) {
    // 战斗选项逻辑
}

void gameMenu(Digimon *player) {
    int choice;
    while (true) {
        cout << "游戏菜单：" << endl;
        cout << "1. 冒险" << endl;
        cout << "2. 保存游戏" << endl;
        cout << "3. 加载游戏" << endl;
        cout << "4. 退出游戏" << endl;
        cout << "请选择操作：";
        cin >> choice;
        switch (choice) {
        case 1:
            adventure(player);
            break;
        case 2:
            player->saveGame();
            cout << "游戏已保存" << endl;
            break;
        case 3:
            player->loadGame();
            cout << "游戏已加载" << endl;
            break;
        case 4:
            return;
        default:
            cout << "无效选择，请重新选择" << endl;
        }
    }
}

int main() {
    Digimon *player = new Agumon("Agumon", 3);
    gameMenu(player);
    delete player;
    return 0;
}

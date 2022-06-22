#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include <windows.h>

int hod = 1; //твой ход ли сейчас. 1 да, 0 нет
int optim = 0; //для урезания каждого второго кадра
int lvl = 0; //на каком уровне. 0 глобальная карта, 1 локальная
bool in_menu = true; //находится ли пользователь в меню
using namespace sf;

class player {
public:
    int HP;
    int x;//координаты на глобальной карте
    int y;
    int maxhp;
    int damage;
    int xl;//координаты на локальной карте
    int yl; 
};

class block {
public:
    std::string type;
};

RenderWindow window(VideoMode(1800, 900), "Very good game");
player Player;
block map[5000][5000];//глобальная карта
block level[100][100];//локальная карта



void HPdisplay(int HP, int maxhp, int x, int y, Color color) {//отображение полоски хп
    x += 25;//небольшой отступ 
    float HPf = HP;
    float maxhpf = maxhp;
    int width = HPf / (maxhpf / 100) * 0.5;
    RectangleShape rectangle(Vector2f(width, 5));
    rectangle.move(x, y);
    rectangle.setFillColor(color);
    window.draw(rectangle);
    RectangleShape rectangle1(Vector2f(50, 5));
    rectangle1.move(x, y);
    rectangle1.setFillColor(Color(0, 0, 0, 0));
    rectangle1.setOutlineColor(Color(0, 0, 0));
    rectangle1.setOutlineThickness(2);
    window.draw(rectangle1);
}

class enemy {
public:
    int HP;
    int maxhp;
    int x;
    int y;
    void display(int px, int py) {
        if (HP > 0) {
            RectangleShape rectangle(Vector2f(100, 100));
            rectangle.move(x - px + 900, y - py + 400);
            Texture enemytxt;
            enemytxt.loadFromFile("vrag1.png");
            rectangle.setTexture(&enemytxt);
            window.draw(rectangle);
            HPdisplay(HP, maxhp,  x - px + 900, y - py + 370, Color(255, 0, 0));
        }
    }
    void move(int px, int py) {
        if (rand() % 2 == 0) {
            if (HP > 0) {
                if (x < px) {
                    x += 100;
                }
                if (y < py) {
                    y += 100;
                }
                if (x > px) {
                    x -= 100;
                }
                if (y > py) {
                    y -= 100;
                }
            }
        }
    }
    void killpl(int px, int py) {//убавление хп игрока
        if (rand() % 2 == 0) {
            if (HP > 0) {
                if (x == px && y == py) {
                    Player.HP -= 10;
                }
            }
        }
    }
    void die(int mx, int my) { //убавление хп врага
        if (mx / 100 == x / 100 && my / 100 == y / 100) {
            HP -= Player.damage;
        }
    }
};

enemy vrag1;//враги
enemy vrag2;
enemy vrag3;
enemy vrag4;
enemy vrag5;

void lvlgen() {//генерация локальной карты
    int x = 0;
    int y = 0;
    int randomv;
    while (y < 100) {
        while (x < 100) {
            randomv = rand() % 20;
            if (randomv == 0) {
                level[x][y].type = "box1";
            }
            else {
                level[x][y].type = "grass1";
            }
            x++;
        }
        x = 0;
        y++;
    }
    vrag1.maxhp = 100;            //задаем характеристики врагам
    vrag1.HP = vrag1.maxhp;
    vrag1.x = rand() % 100 * 100;
    vrag1.y = rand() % 100 * 100;
    vrag2.maxhp = 100;
    vrag2.HP = vrag2.maxhp;
    vrag2.x = rand() % 100 * 100;
    vrag2.y = rand() % 100 * 100;
    vrag3.maxhp = 100;
    vrag3.HP = vrag3.maxhp;
    vrag3.x = rand() % 100 * 100;
    vrag3.y = rand() % 100 * 100;
    vrag4.maxhp = 100;
    vrag4.HP = vrag4.maxhp;
    vrag4.x = rand() % 100 * 100;
    vrag4.y = rand() % 100 * 100;
    vrag5.maxhp = 100;
    vrag5.HP = vrag5.maxhp;
    vrag5.x = rand() % 100 * 100;
    vrag5.y = rand() % 100 * 100;
}


void display() {
    if (!in_menu) {
        int x = 0;
        int y = 0;


        while (y < 11) {
            while (x < 20) {
                if (lvl == 0) {//блоки на глобальной карте
                    RectangleShape rectangle(Vector2f(100, 100));
                    rectangle.move(x * 100 - 100 - ((Player.x - (Player.x / 100 * 100))) + 50, y * 100 - 100 - ((Player.y - (Player.y / 100 * 100))));
                    Texture blocktxt;
                    blocktxt.loadFromFile(map[(Player.x) / 100 + (x - 9)][Player.y / 100 + (y - 5)].type + ".png");
                    rectangle.setTexture(&blocktxt);
                    rectangle.setOutlineThickness(2);
                    rectangle.setOutlineColor(Color(0, 0, 0));
                    window.draw(rectangle);
                }
                if (lvl == 1) {//блоки на локальной карте
                    RectangleShape rectangle(Vector2f(100, 100));
                    rectangle.move(x * 100 - 100 - ((Player.xl - (Player.xl / 100 * 100))) + 50, y * 100 - 100 - ((Player.yl - (Player.yl / 100 * 100))));
                    Texture blocktxt;
                    blocktxt.loadFromFile(level[(Player.xl) / 100 + (x - 9)][Player.yl / 100 + (y - 5)].type + ".png");
                    rectangle.setTexture(&blocktxt);
                    rectangle.setOutlineThickness(2);
                    rectangle.setOutlineColor(Color(0, 0, 0));
                    window.draw(rectangle);
                }
                x++;
            }
            x = 0;
            y++;
        }
        if (Player.HP > 0) {//отображение игрока
            RectangleShape rectangle(Vector2f(50, 50));
            rectangle.move(875, 425);
            rectangle.setFillColor(Color(60, 60, 250));
            window.draw(rectangle);
            HPdisplay(Player.HP, Player.maxhp, 850, 375, Color(60, 60, 250));
        }
        if ((hod == 1 || lvl == 1) && Player.HP > 0) {//отображение зоны взаимодействия

            RectangleShape rectangle(Vector2f(290, 290));
            rectangle.move(755, 305);
            rectangle.setFillColor(Color(0, 0, 0, 0));
            rectangle.setOutlineColor(Color(255, 0, 0));
            rectangle.setOutlineThickness(5);
            window.draw(rectangle);
        }
        if (lvl == 1) {//отображение врагов
            vrag1.display(Player.xl + 50, Player.yl);
            vrag2.display(Player.xl + 50, Player.yl);
            vrag3.display(Player.xl + 50, Player.yl);
            vrag4.display(Player.xl + 50, Player.yl);
            vrag5.display(Player.xl + 50, Player.yl);
        }
        if (hod == 0) {
            Image newhodi;
            newhodi.loadFromFile("hod1.png");
            Texture newhodt;
            newhodt.loadFromImage(newhodi);
            Sprite newhods;
            newhods.setTexture(newhodt);
            newhods.move(0, 0);
            window.draw(newhods);
        }
    }
    else {
        Image imgi;
        imgi.loadFromFile("menu.png");
        Texture imgt;
        imgt.loadFromImage(imgi);
        Sprite imgs;
        imgs.setTexture(imgt);
        imgs.move(0, 0);
        window.draw(imgs);
    }
    window.display();
}

void mouseuse(Event event) {
    
    int x; int y; if (!in_menu) {
        int nx = 0; int ny = 0;
        if (event.type == Event::MouseButtonPressed) {
            Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсор
            Vector2f pos = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд окна)
            if (event.key.code == Mouse::Left) {
                x = pos.x - 50;
                y = pos.y;
                if (lvl == 0) {
                    nx = Player.x + (x / 100 * 100) - 800;
                    ny = Player.y + (y / 100 * 100) - 400;
                }
                else {
                    nx = Player.xl + (x / 100 * 100) - 800;
                    ny = Player.yl + (y / 100 * 100) - 400;
                }
                if (nx / 100 > (Player.x / 100) - 2 && nx / 100 < (Player.x / 100) + 2 && ny / 100 > (Player.y / 100) - 2 && ny / 100 < (Player.y / 100) + 2 && hod == 1 && lvl == 0) {
                    Player.x = nx;
                    Player.y = ny;
                    if (map[Player.x / 100][Player.y / 100].type == "enemy1") {
                        lvl = 1;
                        hod = 1;
                        lvlgen();
                        Player.xl = 4900;
                        Player.yl = 4900;

                    }
                    else if (lvl == 0) {
                        hod = 0;
                    }
                }
                if (nx / 100 > (Player.xl / 100) - 2 && nx / 100 < (Player.xl / 100) + 2 && ny / 100 > (Player.yl / 100) - 2 && ny / 100 < (Player.yl / 100) + 2 && lvl == 1 && Player.HP > 0) {
                    if (nx > 1000 && nx < 9000 && ny > 500 && ny < 9500) {
                        Player.xl = nx;
                        Player.yl = ny;
                    }
                }
                if (hod == 0 && x + 50 > 0 && x + 50 < 300 && y > 0 && y < 50) {
                    hod = 1;
                }
            }
            if (event.key.code == Mouse::Right) { //сражение с врагами
                x = pos.x - 50;
                y = pos.y;

                if (lvl == 1) {
                    nx = Player.xl + (x / 100 * 100) - 800;
                    ny = Player.yl + (y / 100 * 100) - 400;
                }
                if (lvl == 1 && nx / 100 > (Player.xl / 100) - 2 && nx / 100 < (Player.xl / 100) + 2 && ny / 100 > (Player.yl / 100) - 2 && ny / 100 < (Player.yl / 100) + 2 && Player.HP > 0) {
                    vrag1.die(nx, ny);
                    vrag2.die(nx, ny);
                    vrag3.die(nx, ny);
                    vrag4.die(nx, ny);
                    vrag5.die(nx, ny);
                }
            }
        }
    }
    else {
        if (event.type == Event::MouseButtonPressed) {
            Vector2i pixelPos = Mouse::getPosition(window);
            Vector2f pos = window.mapPixelToCoords(pixelPos);
            if (event.key.code == Mouse::Left) {
                x = pos.x;
                y = pos.y;
                if (x > 320 && y > 295 && x < 1478 && y < 472) {
                    in_menu = false; //закрытие меню
                }
            }
        }
    }
}

int main()
{
    
    
    Player.HP = 100; //задаём характеристики игрока
    Player.x = 200000; // 1 блок это 100 
    Player.y = 200000;
    Player.maxhp = 100;
    Player.damage = 10;


    //mapgen();
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }

        }
        mouseuse(event);
        if (!in_menu) {
            if (lvl == 1 && rand() % 10 == 0) {
                vrag1.move(Player.xl, Player.yl); //движение и атака врагов
                vrag1.killpl(Player.xl, Player.yl);
                vrag2.move(Player.xl, Player.yl);
                vrag2.killpl(Player.xl, Player.yl);
                vrag3.move(Player.xl, Player.yl);
                vrag3.killpl(Player.xl, Player.yl);
                vrag4.move(Player.xl, Player.yl);
                vrag4.killpl(Player.xl, Player.yl);
                vrag5.move(Player.xl, Player.yl);
                vrag5.killpl(Player.xl, Player.yl);

            }
            if (lvl == 1 && vrag1.HP <= 0 && vrag2.HP <= 0 && vrag3.HP <= 0 && vrag4.HP <= 0 && vrag5.HP <= 0) {
                lvl = 0;
                Player.maxhp = Player.maxhp + 15;
                Player.damage = Player.damage + 5;
                Player.HP = Player.maxhp;
                map[Player.x / 100][Player.y / 100].type = "enemy2"; //замена лагеря на разрушенный
            }
        }
        if (optim == 0) {//урезка каждого второго кадра
            display(); optim = 1;
        }else { optim = 0; }
    }
    
    return 0;
}


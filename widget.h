#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

const int BLOCK_SIZE=25; //Довжина сторони блоку
const int MARGIN=5; //Розмір полів
const int AREA_ROW=20; //Довжина вікна
const int AREA_COL=12; //Ширина вікна

//Напрямок
enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    SPACE
};

//Визначення межової інформації
struct Border
{
    int ubound;
    int dbound;
    int lbound;
    int rbound;
};

//Координати
struct block_point
{
    int pos_x;
    int pos_y;
};

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    void InitGame();
    void StartGame();
    void GameOver();

    void ResetBlock();
    void BlockMove(Direction dir);
    void BlockRotate(int block[4][4]);
    void CreateBlock(int block[4][4],int block_id);
    void GetBorder(int block[4][4],Border &border);
    void ConvertStable(int x,int y);
    bool IsCollide(int x,int y,Direction dir);

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    virtual void paintEvent(QPaintEvent *event);
    virtual void timerEvent(QTimerEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);

private:
    Ui::Widget *ui;

private:
    int game_area[AREA_ROW][AREA_COL]; //Область сцени в квадратах (0 - порожній, 1 - активний, 2 - неактивний)
    block_point block_pos; //Координати блоку
    int cur_block[4][4]; //Форма блоку
    Border cur_border; //Границя блоку
    int next_block[4][4]; //Наступний блок
    bool isStable; //Чи є даний блок стабільним
    int score;  //Рахунок гри
    int game_timer; //Таймер падіння блоку
    int paint_timer; //Оновлення таймера
    int speed_ms; //Швидкість
    int refresh_ms; //Інтервал оновлення

};

#endif // WIDGET_H

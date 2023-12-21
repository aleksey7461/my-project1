#include <iostream>
#include <conio.h>

using namespace std;

bool gameover;
const int width = 20;
const int height = 20;
int x, y, fruitx, fruity, score, ntail;
int tailx[100], taily[100];
enum edirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
edirection dir;

void setup() {
    gameover = false;
    dir = STOP;
    x = width / 2 - 1;
    y = height / 2 - 1;
    fruitx = rand() % width;
    fruity = rand() % height;
    score = 0;
}
void draw() {
   system("cls");
    for (int i = 0; i < width + 1; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1)
                cout<< "#";
            if (i == y && j == x)
                cout << "0";
            else if (i == fruity && j == fruitx)
                cout << "F";
            else {
                bool print = false;
                for (int k = 0; k < ntail; k++){
                    if (tailx[k] == j && taily[k] == i) {
                        print = true;
                        cout << "o";
                    }
                }
                cout << " ";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width + 1; i++)
        cout << "#";
    cout << endl;
    cout << "score: " << score << "\n";
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameover = true;
                break;
        }
    }
}

void logic() {
    int px = tailx[0];
    int py = taily[0];

    int p2x, p2y;

    tailx[0] = x;
    taily[0] = y;

    for (int i = 0; i < ntail; i++) {
        p2x = tailx[i];
        p2y = taily[i];

        tailx[i] = px;
        taily[i] = py;

        px = p2x;
        py = p2y;
    }
    switch (dir) {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
    }

//    if (x > width || x < 0 || y > height || y < 0)
//        gameover = true;

    if (x >= width - 1)
        x = 0;
    else if (x < 0)
        x = width -2;

    if (y >= height)
        y = 0;
    else if (y < 0)
        y = height - 1;

    for (int i = 0; i < ntail; i++){
        if (tailx[i] == x && taily[i] == y)
            gameover = true;
    }

    if (x == fruitx && y == fruity){
        score++;
        fruitx = rand() % width;
        fruity = rand() % height;
        ntail++;
    }
}

int main() {
    setup();
    while (!gameover) {
        draw();
        input();
        logic();
    }
}

/*  404410062   資工二*/
#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

class GameOfLife
{
public:
    GameOfLife();
    //Postcondition: default width and height.
    int initialize(int pattern);
    //Precondition: pattern is the mode of the enter.
    //Postcondieion: initialize the mode of the pattern.
    int proceed(int time);
    //Precondition: time is the change time.
    //Postcondition: proceed the time of the cell.
    int copy();
    //Postcondition: copy new_cell to cell.
    void display() const;
    //Postcondition: display the whole cell.
    bool gotoxy(int x, int y);
    //Precondition: x is coordinate x. y is coordinate y.
    //Postcondition: let the cursor move to coordinate (x,y).
private:
    int width;
    int height;
    bool cell[100][100];
    bool new_cell[100][100];
};

int main()
{
    int pattern, generation, number(0);
    while(1)
    {
        GameOfLife enter_pattern;
        cout << "Enter the pattern number : ";
        cin >> pattern;
        enter_pattern.initialize(pattern);
        enter_pattern.display();
        generation = 100;
        while(generation--)
        {
            enter_pattern.gotoxy(0, 1 + number * 25);
            enter_pattern.proceed(1);
            enter_pattern.copy();
            enter_pattern.display();
        }
        number++;
    }
}

GameOfLife :: GameOfLife() : width(80), height(23)
{
    /*Body intentionally empty.*/
}

int GameOfLife :: initialize(int pattern)
{
    int i, j, count;
    for (i = 0; i < height; i++)
        for (j = 0; j < width; j++)
            cell[i][j] = false;
    if (pattern == 1)
    {
        cell[height / 2 - 1][width / 2 - 2] = true;
        cell[height / 2 - 1][width / 2 - 1] = true;
        cell[height / 2 - 1][width / 2] = true;
        cell[height / 2][width / 2 - 2] = true;
        cell[height / 2 + 1][width / 2 - 1] = true;
    }
    else if (pattern == 2)
    {
        cell[height / 2 - 2][width / 2 - 2] = true;
        cell[height / 2 - 2][width / 2 + 1] = true;
        cell[height / 2 - 1][width / 2 - 3] = true;
        cell[height / 2][width / 2 - 3] = true;
        cell[height / 2][width / 2 + 1] = true;
        cell[height / 2 + 1][width / 2 - 3] = true;
        cell[height / 2 + 1][width / 2 - 2] = true;
        cell[height / 2 + 1][width / 2 - 1] = true;
        cell[height / 2 + 1][width / 2] = true;
    }
    else if (pattern == 3)
    {
        cell[height / 2 - 6][width / 2 - 5] = true;
        cell[height / 2 - 6][width / 2 + 3] = true;
        cell[height / 2 + 6][width / 2 - 5] = true;
        cell[height / 2 + 6][width / 2 + 3] = true;
        cell[height / 2 - 6][width / 2 - 4] = true;
        cell[height / 2 - 6][width / 2 + 2] = true;
        cell[height / 2 + 6][width / 2 - 4] = true;
        cell[height / 2 + 6][width / 2 + 2] = true;
        cell[height / 2 - 5][width / 2 - 4] = true;
        cell[height / 2 - 5][width / 2 + 2] = true;
        cell[height / 2 + 5][width / 2 - 4] = true;
        cell[height / 2 + 5][width / 2 + 2] = true;
        cell[height / 2 - 5][width / 2 - 3] = true;
        cell[height / 2 - 5][width / 2 + 1] = true;
        cell[height / 2 + 5][width / 2 - 3] = true;
        cell[height / 2 + 5][width / 2 + 1] = true;
        cell[height / 2 - 4][width / 2 - 7] = true;
        cell[height / 2 - 4][width / 2 + 5] = true;
        cell[height / 2 + 4][width / 2 - 7] = true;
        cell[height / 2 + 4][width / 2 + 5] = true;
        cell[height / 2 - 4][width / 2 - 4] = true;
        cell[height / 2 - 4][width / 2 + 2] = true;
        cell[height / 2 + 4][width / 2 - 4] = true;
        cell[height / 2 + 4][width / 2 + 2] = true;
        cell[height / 2 - 4][width / 2 - 2] = true;
        cell[height / 2 - 4][width / 2] = true;
        cell[height / 2 + 4][width / 2 - 2] = true;
        cell[height / 2 + 4][width / 2] = true;
        cell[height / 2 - 3][width / 2 - 7] = true;
        cell[height / 2 - 3][width / 2 + 5] = true;
        cell[height / 2 + 3][width / 2 - 7] = true;
        cell[height / 2 + 3][width / 2 + 5] = true;
        cell[height / 2 - 3][width / 2 - 6] = true;
        cell[height / 2 - 3][width / 2 + 4] = true;
        cell[height / 2 + 3][width / 2 - 6] = true;
        cell[height / 2 + 3][width / 2 + 4] = true;
        cell[height / 2 - 3][width / 2 - 5] = true;
        cell[height / 2 - 3][width / 2 + 3] = true;
        cell[height / 2 + 3][width / 2 - 5] = true;
        cell[height / 2 + 3][width / 2 + 3] = true;
        cell[height / 2 - 3][width / 2 - 3] = true;
        cell[height / 2 - 3][width / 2 + 1] = true;
        cell[height / 2 + 3][width / 2 - 3] = true;
        cell[height / 2 + 3][width / 2 + 1] = true;
        cell[height / 2 - 3][width / 2 - 2] = true;
        cell[height / 2 - 3][width / 2] = true;
        cell[height / 2 + 3][width / 2 - 2] = true;
        cell[height / 2 + 3][width / 2] = true;
        cell[height / 2 - 2][width / 2 - 6] = true;
        cell[height / 2 - 2][width / 2 + 4] = true;
        cell[height / 2 + 2][width / 2 - 6] = true;
        cell[height / 2 + 2][width / 2 + 4] = true;
        cell[height / 2 - 2][width / 2 - 4] = true;
        cell[height / 2 - 2][width / 2 + 2] = true;
        cell[height / 2 + 2][width / 2 - 4] = true;
        cell[height / 2 + 2][width / 2 + 2] = true;
        cell[height / 2 - 2][width / 2 - 2] = true;
        cell[height / 2 - 2][width / 2] = true;
        cell[height / 2 + 2][width / 2 - 2] = true;
        cell[height / 2 + 2][width / 2] = true;
        cell[height / 2 - 1][width / 2 - 5] = true;
        cell[height / 2 - 1][width / 2 + 3] = true;
        cell[height / 2 + 1][width / 2 - 5] = true;
        cell[height / 2 + 1][width / 2 + 3] = true;
        cell[height / 2 - 1][width / 2 - 4] = true;
        cell[height / 2 - 1][width / 2 + 2] = true;
        cell[height / 2 + 1][width / 2 - 4] = true;
        cell[height / 2 + 1][width / 2 + 2] = true;
        cell[height / 2 - 1][width / 2 - 3] = true;
        cell[height / 2 - 1][width / 2 + 1] = true;
        cell[height / 2 + 1][width / 2 - 3] = true;
        cell[height / 2 + 1][width / 2 + 1] = true;
    }
    else
    {
        count = width * height * pattern / 100;
        while(count--)
        {
            i = rand() % height;
            j = rand() % width;
            if (cell[i][j] != true)
                cell[i][j] = true;
            else
                count++;
        }
    }
}

int GameOfLife :: proceed(int time)
{
    int i, j, live;
    while(time--)
    {
        for (i = 0; i < height; i++)
        {
            for (j = 0; j < width; j++)
            {
                live = 0;
                if (i != 0)
                {
                    if (j != 0)
                        if (cell[i - 1][j - 1] == true)
                            live++;
                    if (cell[i - 1][j] == true)
                        live++;
                    if (j != width - 1)
                        if (cell[i - 1][j + 1] == true)
                            live++;
                }
                if (j != 0)
                    if (cell[i][j - 1] == true)
                        live++;
                if (j != width - 1)
                    if (cell[i][j + 1] == true)
                        live++;
                if (i != height - 1)
                {
                    if (j != 0)
                        if (cell[i + 1][j - 1] == true)
                            live++;
                    if (cell[i + 1][j] == true)
                        live++;
                    if (j != width - 1)
                        if (cell[i + 1][j + 1] == true)
                            live++;
                }
                new_cell[i][j] = false;
                if (cell[i][j] == true && live < 2)         //if cell is live and its neighbor is less than two,then it dies.
                    new_cell[i][j] = false;
                else if (cell[i][j] == true && live > 3)    //if cell is live and its neighbor is more than three, then it dies.
                    new_cell[i][j] = false;
                else if (cell[i][j] == true && (live == 2 || live == 3))    //if cell is live and its neighbor is equal to two or three
                    new_cell[i][j] = true;                                  //then it dies.
                else if (cell[i][j] == false && live == 3)      //if cell is dead and its neighbor is equal to three, then it lives.
                    new_cell[i][j] = true;
            }
        }
    }
}

int GameOfLife :: copy()
{
    int i, j;
    for (i = 0; i < height; i++)
        for (j = 0; j < width; j++)
            cell[i][j] = new_cell[i][j];
}

void GameOfLife :: display() const
{
    int i, j;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (cell[i][j] == true)
                cout << "O";
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool GameOfLife :: gotoxy(int x, int y)
{
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE); // handle of Get stdout
    if (hOutput == INVALID_HANDLE_VALUE) return FALSE; // Can't get
    COORD cc;
    cc.X = (SHORT) x;
    cc.Y = (SHORT) y;
    return SetConsoleCursorPosition(hOutput, cc); // set cursor
}

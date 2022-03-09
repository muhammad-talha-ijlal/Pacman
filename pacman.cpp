#include <iostream>
#include <windows.h>
#include <math.h>
#include <time.h>
using namespace std;
#include <conio.h>

bool gameRun = true;
int lives = 3;
int en = 0;
int maxScore = 1;
int dis[4];
string dir2 = "up";
string dir3 = "left";
char previousitem = ' ';
int old1x, old1y;
int pX, pY, g1X, g1Y, g2X, g2Y, g3X, g3Y, g4X, g4Y, score = 0;
char maze[24][71] = {
    {"#####################################################################"},
    {"||O...................................... ..P.............  ...... O||"},
    {"||.. %%%%%%%%%%%%%%%%        ...     %%%%%%%%%%%%%%  |%|..   %%%%   ||"},
    {"||..     G  |%|   |%|     |%|...     |%|        |%|  |%|..    |%|   ||"},
    {"||..        |%|   |%|     |%|...     |%|        |%|  |%|..    |%|   ||"},
    {"||..        %%%%%%%%  . . |%|...     %%%%%%%%%%%%%%     ..   %%%%.  ||"},
    {"||..        |%|       . . |%|...    ............... |%| ..       .  ||"},
    {"||..        %%%%%%%%%%. . |%|...    %%%%%%%%%%%%    |%| G.   %%%%.  ||"},
    {"||..               |%|.             |%|......       |%| ..    |%|.  ||"},
    {"||..     ......... |%|.             |%|......|%|        ..    |%|.  ||"},
    {"||..|%|  |%|%%%|%|.|%|. |%|            ......|%|        ..|%| |%|.  ||"},
    {"||..|%|  |%|   |%|..    %%%%%%%%%%%%%  ......|%|         .|%|.      ||"},
    {"||..|%|  |%|   |%|..           ...|%|     %%%%%%        . |%|.      ||"},
    {"||..|%|            .           ...|%|               |%| ..|%|.      ||"},
    {"||..|%|  %%%%%%%%%%%%%%        ...|%|%%%%%%%%%%     |%| ..|%|%%%%%  ||"},
    {"||...............................................   |%| ..........  ||"},
    {"||   .............................G..............          .......  ||"},
    {"||..|%|  |%|   |%|..    %%%%%%%%%%%%%  ......|%|    |%| ..|%|.      ||"},
    {"||..|%|  |%|   |%|..           ...|%|     %%%%%%    |%| ..|%|.      ||"},
    {"||..|%|            .           ...|%|               |%| ..|%|.      ||"},
    {"||..|%|  %%%%%%%%%%%%%%        ...|%|%%%%%%%%%%     |%| ..|%|%%%%%  ||"},
    {"||.....................................G.........   | | ..........  ||"},
    {"||O .............................................          ....... O||"},
    {"#####################################################################"}};

void calculateMaxScore()
{
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 71; j++)
        {
            if (maze[i][j] == '.')
            {
                maxScore++;
            }
        }
    }
}
void displayMaze()
{
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 71; j++)
        {
            cout << maze[i][j];
        }
        cout << "\n";
    }
}
void findPacPos()
{
    int count = 0;
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 71; j++)
        {
            if (maze[i][j] == 'P')
            {
                pX = i;
                pY = j;
                break;
            }
        }
    }
}
void findGPos()
{
    int count = 0;
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 71; j++)
        {
            if (maze[i][j] == 'G')
            {
                count++;
                if (count == 1)
                {
                    g1X = i;
                    g1Y = j;
                }
                if (count == 2)
                {
                    g2X = i;
                    g2Y = j;
                }
                if (count == 3)
                {
                    g3X = i;
                    g3Y = j;
                }
                if (count == 4)
                {
                    g4X = i;
                    g4Y = j;
                }
            }
        }
    }
}
void moveUp()
{
    if (maze[pX - 1][pY] == ' ')
    {
        maze[pX][pY] = ' ';
        maze[pX - 1][pY] = 'P';
        pX--;
    }
    if (maze[pX - 1][pY] == '.')
    {
        maze[pX][pY] = ' ';
        maze[pX - 1][pY] = 'P';
        pX--;
        score++;
    }
    if (maze[pX - 1][pY] == 'O')
    {
        maze[pX][pY] = ' ';
        maze[pX - 1][pY] = 'P';
        pX--;
        en++;
    }
}
void moveDown()
{
    if (maze[pX + 1][pY] == ' ')
    {
        maze[pX][pY] = ' ';
        maze[pX + 1][pY] = 'P';
        pX++;
    }
    if (maze[pX + 1][pY] == '.')
    {
        score++;
        maze[pX][pY] = ' ';
        maze[pX + 1][pY] = 'P';
        pX++;
    }
    if (maze[pX + 1][pY] == 'O')
    {
        score++;
        maze[pX][pY] = ' ';
        maze[pX + 1][pY] = 'P';
        pX++;
        en++;
    }
}
void moveLeft()
{
    if (maze[pX][pY - 1] == ' ')
    {
        maze[pX][pY] = ' ';
        maze[pX][pY - 1] = 'P';
        pY--;
    }
    if (maze[pX][pY - 1] == '.')
    {
        score++;
        maze[pX][pY] = ' ';
        maze[pX][pY - 1] = 'P';
        pY--;
    }
    if (maze[pX][pY - 1] == 'O')
    {
        score++;
        maze[pX][pY] = ' ';
        maze[pX][pY - 1] = 'P';
        pY--;
        en++;
    }
}
void moveRight()
{
    if (maze[pX][pY + 1] == ' ')
    {
        maze[pX][pY] = ' ';
        maze[pX][pY + 1] = 'P';
        pY++;
    }
    if (maze[pX][pY + 1] == '.')
    {
        score++;
        maze[pX][pY] = ' ';
        maze[pX][pY + 1] = 'P';
        pY++;
    }
    if (maze[pX][pY + 1] == 'O')
    {
        score++;
        maze[pX][pY] = ' ';
        maze[pX][pY + 1] = 'P';
        pY++;
        en++;
    }
}
int findDis(int x1, int y1, int x2, int y2)
{
    if (maze[x1][y2] == '#' || maze[x1][y1] == '|' || maze[x1][y1] == '%')
    {
        return 1000;
    }
    else
        return sqrt(pow(x2 - x1, 2) +
                    pow(y2 - y1, 2) * 1.0);
}
int findMin()
{
    int min = 99999;
    int minIdx = -1;
    for (int i = 0; i < 4; i++)
    {
        if (min > dis[i])
        {
            min = dis[i];
            minIdx = i;
        }
    }

    return minIdx;
}
void moveG1Up()
{
    if (maze[g1X - 1][g1Y] == ' ')
    {
        maze[g1X][g1Y] = ' ';
        maze[g1X - 1][g1Y] = 'G';
        g1X--;
    }
    if (maze[g1X - 1][g1Y] == '.')
    {
        maze[g1X][g1Y] = '.';
        maze[g1X - 1][g1Y] = 'G';
        g1X--;
    }
    if (maze[g1X - 1][g2Y] == 'P')
    {
        if (en > 0)
        {
            maze[g1X][g1Y] = ' ';
            score += 5;
            en--;
        }
        else
        {
            lives--;
        }
    }
}
void moveG1Down()
{
    if (maze[g1X + 1][g1Y] == ' ')
    {
        maze[g1X][g1Y] = ' ';
        maze[g1X + 1][g1Y] = 'G';
        g1X++;
    }
    if (maze[g1X + 1][g1Y] == '.')
    {
        maze[g1X][g1Y] = '.';
        maze[g1X + 1][g1Y] = 'G';
        g1X++;
    }
    if (maze[g1X + 1][g2Y] == 'P')
    {
        if (en > 0)
        {
            maze[g1X][g1Y] = ' ';
            score += 5;
            en--;
        }
        else
        {
            lives--;
        }
    }
}
void moveG1Left()
{
    if (maze[g1X][g1Y - 1] == ' ')
    {
        maze[g1X][g1Y] = ' ';
        maze[g1X][g1Y - 1] = 'G';
        g1Y--;
    }
    if (maze[g1X][g1Y - 1] == '.')
    {
        maze[g1X][g1Y] = '.';
        maze[g1X][g1Y - 1] = 'G';
        g1Y--;
    }
    if (maze[g1X][g1Y - 1] == 'P')
    {
        if (en > 0)
        {
            maze[g1X][g1Y] = ' ';
            score += 5;
            en--;
        }
        else
        {
            lives--;
        }
    }
}
void moveG1Right()
{

    if (maze[g1X][g1Y + 1] == ' ')
    {
        maze[g1X][g1Y] = ' ';
        maze[g1X][g1Y + 1] = 'G';
        g1Y++;
    }
    if (maze[g1X][g1Y + 1] == '.')
    {
        maze[g1X][g1Y] = '.';
        maze[g1X][g1Y + 1] = 'G';
        g1Y++;
    }
    if (maze[g1X][g1Y + 1] == 'P')
    {
        if (en > 0)
        {
            maze[g1X][g1Y] = ' ';
            score += 5;
            en--;
        }
        else
        {
            lives--;
        }
    }
}
void moveGhost1()
{
    for (int i = 0; i < 4; i++)
    {
        dis[i] = 0;
    }
    dis[0] = findDis(g1X - 1, g1Y, pX, pY);
    dis[1] = findDis(g1X + 1, g1Y, pX, pY);
    dis[2] = findDis(g1X, g1Y - 1, pX, pY);
    dis[3] = findDis(g1X, g1Y + 1, pX, pY);
    int x = findMin();

    if (x == 0)
    {
        moveG1Up();
    }
    if (x == 1)
    {
        moveG1Down();
    }
    if (x == 2)
    {
        moveG1Left();
    }
    if (x == 3)
    {
        moveG1Right();
    }
}
void moveG2Up()
{
    if (maze[g2X - 1][g2Y] == ' ')
    {
        maze[g2X][g2Y] = ' ';
        maze[g2X - 1][g2Y] = 'G';
        g2X--;
    }
    if (maze[g2X - 1][g2Y] == '.')
    {
        maze[g2X][g2Y] = '.';
        maze[g2X - 1][g2Y] = 'G';
        g2X--;
    }
    if (maze[g2X - 1][g2Y] == 'P')
    {
        if (en > 0)
        {
            maze[g2X][g2Y] = ' ';
            en--;
        }
        else
        {
            lives--;
        }
    }
}
void moveG2Down()
{
    if (maze[g2X + 1][g2Y] == ' ')
    {
        maze[g2X][g2Y] = ' ';
        maze[g2X + 1][g2Y] = 'G';
        g2X++;
    }
    if (maze[g2X + 1][g2Y] == '.')
    {
        maze[g2X][g2Y] = '.';
        maze[g2X + 1][g2Y] = 'G';
        g2X++;
    }
    if (maze[g2X - 1][g2Y] == 'P')
    {
        if (en > 0)
        {
            maze[g2X][g2Y] = ' ';
            score += 5;
            en--;
        }
        else
        {
            lives--;
        }
    }
}
void moveGhost2()
{
    if (maze[g2X - 1][g2Y] == '#')
    {
        dir2 = "down";
    }
    if (maze[g2X + 1][g2Y] == '#')
    {
        dir2 = "up";
    }
    if (dir2 == "up")
    {
        moveG2Up();
    }
    if (dir2 == "down")
    {
        moveG2Down();
    }
}

void moveG3Left()
{
    if (maze[g3X][g3Y - 1] == ' ')
    {
        maze[g3X][g3Y] = ' ';
        maze[g3X][g3Y - 1] = 'G';
        g3Y--;
    }
    if (maze[g3X][g3Y - 1] == '.')
    {
        maze[g3X][g3Y] = '.';
        maze[g3X][g3Y - 1] = 'G';
        g3Y--;
    }
    if (maze[g3X][g3Y - 1] == 'P')
    {
        if (en > 0)
        {
            maze[g3X][g3Y] = ' ';
            score += 5;
            en--;
        }
        else
        {
            lives--;
        }
    }
}
void moveG3Right()
{
    if (maze[g3X][g3Y + 1] == ' ')
    {
        maze[g3X][g3Y] = ' ';
        maze[g3X][g3Y + 1] = 'G';
        g3Y++;
    }
    if (maze[g3X][g3Y + 1] == '.')
    {
        maze[g3X][g3Y] = '.';
        maze[g3X][g3Y + 1] = 'G';
        g3Y++;
    }
    if (maze[g3X][g3Y + 1] == 'P')
    {
        if (en > 0)
        {
            maze[g3X][g3Y] = ' ';
            score += 5;
            en--;
        }
        else
        {
            lives--;
        }
    }
}
void moveGhost3()
{
    if (maze[g3X][g3Y - 1] == '|')
    {
        dir3 = "right";
    }
    if (maze[g3X][g3Y + 1] == '|')
    {
        dir3 = "left";
    }
    if (dir3 == "left")
    {
        moveG3Left();
    }
    if (dir3 == "right")
    {
        moveG3Right();
    }
}
void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
int getrand()
{
    srand(time(0));
    int num = (1 + (rand() % 4));
    return num;
}
bool moveGhost4()
{
    int move = getrand();
    if (move == 1)
    {
        if (maze[g4X][g4Y - 1] == ' ' || maze[g4X][g4Y - 1] == '.' || maze[g4X][g4Y - 1] == 'P')
        {

            maze[g4X][g4Y] = previousitem;
            g4Y = g4Y - 1;
            previousitem = maze[g4X][g4Y];
            if (previousitem == 'P')
            {
                return 0;
            }

            maze[g4X][g4Y] = 'G';
        }
    }
    if (move == 2)
    {
        if (maze[g4X][g4Y + 1] == ' ' || maze[g4X][g4Y + 1] == '.' || maze[g4X][g4Y + 1] == 'P')
        {

            maze[g4X][g4Y] = previousitem;
            g4Y = g4Y + 1;
            previousitem = maze[g4X][g4Y];
            if (previousitem == 'P')
            {
                return 0;
            }

            maze[g4X][g4Y] = 'G';
        }
    }
    if (move == 3)
    {
        if (maze[g4X - 1][g4Y] == ' ' || maze[g4X - 1][g4Y] == '.' || maze[g4X - 1][g4Y] == 'P')
        {

            maze[g4X][g4Y] = previousitem;
            g4X = g4X - 1;
            previousitem = maze[g4X][g4Y];
            if (previousitem == 'P')
            {
                return 0;
            }

            maze[g4X][g4Y] = 'G';
        }
    }

    if (move == 4)
    {
        if (maze[g4X + 1][g4Y] == ' ' || maze[g4X + 1][g4Y] == '.' || maze[g4X + 1][g4Y] == 'P')
        {

            maze[g4X][g4Y] = previousitem;
            g4X = g4X + 1;
            previousitem = maze[g4X][g4Y];
            if (previousitem == 'P')
            {
                return 0;
            }

            maze[g4X][g4Y] = 'G';
        }
    }
    return 1;
}

main()
{
    findPacPos();
    findGPos();
    system("cls");
    calculateMaxScore();
    while (gameRun)
    {
        int oldLives = lives;
        gotoxy(0, 0);
        cout << "Score: " << score;
        gotoxy(0, 1);
        cout << "Lives: " << lives << "  " << en;
        gotoxy(0, 2);
        displayMaze();
        if (GetAsyncKeyState(VK_UP))
        {
            moveUp();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            moveDown();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            moveRight();
        }
        if (GetAsyncKeyState(VK_LEFT))
        {
            moveLeft();
        }
        if (maze[g1X][g1Y] == 'G')
        {
            moveGhost1();
        }
        if (maze[g2X][g2Y] == 'G')
        {
            moveGhost2();
        }
        if (maze[g3X][g3Y] == 'G')
        {
            moveGhost3();
        }
        if (moveGhost4() == 0)
        {
            lives--;
            continue;
        }
        if (oldLives != lives)
        {
            maze[pX][pY] = ' ';
            pX = 4;
            pY = 4;
            maze[pX][pY] = 'P';
        }
        if (score == maxScore)
        {
            system("cls");
            gotoxy(0, 0);
            cout << "score: " << score << endl;
            cout << "YOU WONF" << endl;
            break;
        }
        if (lives == 0)
        {
            system("cls");
            gotoxy(0, 0);
            cout << "score: " << score << endl;
            ;
            cout << "YOU LOST" << endl;
            break;
        }
    }
    system("pause");
}
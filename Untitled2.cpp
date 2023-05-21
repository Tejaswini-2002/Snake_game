#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;

enum class direction {
	stop,
	left,
	right,
	up,
	down
};

bool flag;
const int length=20, breadth =20;
int tailX[100], tailY[100];
int x,y, targetX, targetY, score,n;
direction d;

struct level_info{
	int speed, count;
};

level_info stages[]={
	{30,0},
	{20,1},
	{10,2}
};

int present_level = 0, high_score = 0; 
void save()
{
	ofstream file("high_score.txt");
	if(file.is_open()){
		file<<high_score;
		file.close();
	}
}

void load()
{
	ifstream file("high_score.txt");
	if(file.is_open()){
		file>>high_score;
		file.close();
	}
}

void System(){
	flag = false;
	d = direction::stop;
	x = length/2;
	y = breadth/2;
	targetX = rand() % length;
	targetY = rand() % breadth;
	score = 0; n = 0; present_level=0;
}

void box(){
	system("cls");

    for (int i = 0; i < length + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < breadth; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "O";
            else if (i == targetY && j == targetX)
                cout << "F";
            else
            {
                bool tail = false;
                for (int k = 0; k < n; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        tail = true;
                    }
                }
                if (!tail)
                    cout << " ";
            }
            if (j == length - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < length + 2; i++)
        cout << "#";
    cout << endl;

    cout << "Score: " << score << endl;
    cout << "Level: " << present_level + 1 << endl;
    cout << "High Score: " << high_score << endl;
}

void Method()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < n; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (d)
    {
        case direction::left:
            x--;
            break;
        case direction::right:
            x++;
            break;
        case direction::up:
            y--;
            break;
        case direction::down:
            y++;
            break;
    }

    if (x >= length)
        x = 0;
    else if (x < 0)
        x = length - 1;

    if (y >= breadth)
        y = 0;
    else if (y < 0)
        y = breadth - 1;

    for (int i = 0; i < n; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
        {
            flag = true;
            break;
        }
    }

    if (x == targetX && y == targetY)
    {
        score += 10;
        targetX = rand() % length;
        targetY = rand() % breadth;
        n++;

        if (score > high_score)
        {
            high_score = score;
            save();
        }

        if (score % 30 == 0)
        {
            present_level++;

            if (present_level >= sizeof(stages) / sizeof(level_info))
                present_level = sizeof(stages) / sizeof(level_info) - 1;
        }
    }
}

void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
            case 'a':
                d = direction::left;
                break;
            case 'd':
                d = direction::right;
                break;
            case 'w':
                d = direction::up;
                break;
            case 's':
                d = direction::down;
                break;
            case 'e':
                flag = true;
                break;
        }
    }
}

int main()
{
    load();
    System();

    while (!flag)
    {
        box();
        Input();
        Method();
        int s = stages[present_level].speed;
        Sleep(s*10); // Sleep for a short period to control game speed
    }

    return 0;
}



	

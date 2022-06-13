#include <iostream>
#include <Windows.h>
using namespace std;

enum ConsoleColor
{
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};

void SetColor(ConsoleColor text, ConsoleColor background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

int main()
{
    int width = 48;
    int height = 13;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (x % 2 == 0 && x < width / 2.5 && y < height / 1.9 && y % 2 == 0)
            {
                SetColor(White, Blue);
                cout << "*";
            }
            else if (x % 2 != 0 && x < width / 2.5 && y < height / 1.9 && y % 2 != 0)
            {
                SetColor(White, Blue);
                cout << "*";
            }
            else if (x < width / 2.5 && y < height / 1.9)
            {
                SetColor(Blue, Blue);
                cout << " ";
            }
            else if (y % 2 != 0)
            {
                SetColor(White, White);
                cout << " ";
            }
            else if (y % 2 == 0)
            {
                SetColor(Red, Red);
                cout << " ";
            }
        }
        cout << "\n";
    }
    SetColor(Black, Black);
    cout << "\n";
}
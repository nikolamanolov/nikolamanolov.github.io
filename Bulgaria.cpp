#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <winuser.h>
#include <time.h>

using namespace std;

const int MAP_ROWS = 40;
const int MAP_COLS = 100;


HANDLE hConsoleOutput = ::GetStdHandle(STD_OUTPUT_HANDLE);
COORD screen_buf = {MAP_ROWS, MAP_COLS};
CHAR_INFO blank_screen[MAP_ROWS * MAP_COLS] = {0};

enum COLORS
{
    BLACK = 0,
    BLUE = FOREGROUND_BLUE,
    CYAN = FOREGROUND_BLUE | FOREGROUND_GREEN,
    GREEN = FOREGROUND_GREEN,
    RED = FOREGROUND_RED,
    BROWN = FOREGROUND_RED | FOREGROUND_GREEN,
    PURPLE = FOREGROUND_RED | FOREGROUND_BLUE,
    LIGHT_GREY =  FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN,

    GREY = 0 | FOREGROUND_INTENSITY,
    LIGHT_BLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    LIGHT_CYAN = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    LIGHT_GREEN = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    LIGHT_RED = FOREGROUND_RED | FOREGROUND_INTENSITY,
    YELLOW = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    PINK = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    WHITE =  FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY,

};


void draw_char(char ch, int y, int x, COLORS foreground_color, COLORS background_color)
{
    CHAR_INFO ch_info;
    ch_info.Char.AsciiChar = ch;
    ch_info.Attributes = foreground_color | (background_color << 4);

    COORD buf_size = {1, 1};
    COORD buf_coord = {0, 0};
    SMALL_RECT screen_pos = {x, y, x+1, y+1};
    ::WriteConsoleOutput(hConsoleOutput, &ch_info, buf_size, buf_coord, &screen_pos);

}

void draw_Bulgaria()
{
    COLORS color[]={WHITE, GREEN, RED};

    for (long long i=0; i<3; i++)
    {
        for (long long j=0; j<12; j++)
        {
            draw_char(' ', i+1, j+1, color[i], color[i]);
        }
    }


}


void draw_Hungary()
{
    COLORS color[]={RED, WHITE, GREEN};

    for (long long i=0; i<3; i++)
    {
        for (long long j=0; j<12; j++)
        {
            draw_char(' ', i+1, j+1, color[i], color[i]);
        }
    }


}

void draw_France()
{
    for (long long i=0; i<3; i++)
    {
        for (long long j=0; j<4; j++)
        {
            draw_char(' ', i+1, j+1, BLUE, BLUE);
        }
    }

    for (long long i=0; i<3; i++)
    {
        for (long long j=4; j<8; j++)
        {
            draw_char(' ', i+1, j+1, WHITE, WHITE);
        }
    }

    for (long long i=0; i<3; i++)
    {
        for (long long j=8; j<12; j++)
        {
            draw_char(' ', i+1, j+1, RED, RED);
        }
    }
}

void draw_England()
{
    for (long long i=0; i<5; i++)
    {
        draw_char(' ', 1, i+1, WHITE, WHITE);
    }
    draw_char(' ', 1, 6, RED, RED);
    draw_char(' ', 1, 7, RED, RED);

    for (long long i=0; i<12; i++)
    {
        draw_char(' ', 2, i+1, RED, RED);
    }
    for (long long i=0; i<5; i++)
    {
        draw_char(' ', 3, i+1, WHITE, WHITE);
    }
    draw_char(' ', 3, 6, RED, RED);
    draw_char(' ', 3, 7, RED, RED);
    for (long long i=7; i<12; i++)
    {
        draw_char(' ', 1, i+1, WHITE, WHITE);
    }

    for (long long i=7; i<12; i++)
    {
        draw_char(' ', 3, i+1, WHITE, WHITE);
    }
}

void draw_Iceland()
{
    for (long long i=0; i<12; i++)
    {
        for (long long j=0; j<45; j++)
        {
            draw_char(' ', i, j, BLUE, BLUE);
        }
    }
    for (long long i=0; i<5; i++)
    {
        draw_char(' ', i, 10, WHITE, WHITE);
        draw_char(' ', i, 11, WHITE, WHITE);
        draw_char(' ', i, 12, RED, RED);
        draw_char(' ', i, 13, RED, RED);
        draw_char(' ', i, 14, RED, RED);
        draw_char(' ', i, 15, RED, RED);
        draw_char(' ', i, 16, WHITE, WHITE);
        draw_char(' ', i, 17, WHITE, WHITE);
    }
    for (long long j=0; j<12; j++)
    {
        draw_char(' ', 4, j, WHITE, WHITE);
    }

    for (long long j=0; j<12; j++)
    {
        draw_char(' ', 5, j, RED, RED);
        draw_char(' ', 6, j, RED, RED);
    }
    for (long long j=0; j<12; j++)
    {
        draw_char(' ', 7, j, WHITE, WHITE);
    }
    for (long long i=4; i<12; i++)
    {
        draw_char(' ', i, 12, RED, RED);
        draw_char(' ', i, 13, RED, RED);
        draw_char(' ', i, 14, RED, RED);
        draw_char(' ', i, 15, RED, RED);
    }
    for (long long i=7; i<12; i++)
    {
        draw_char(' ', i, 10, WHITE, WHITE);
        draw_char(' ', i, 11, WHITE, WHITE);
    }
    for (long long i=7; i<12; i++)
    {
        draw_char(' ', i, 16, WHITE, WHITE);
        draw_char(' ', i, 17, WHITE, WHITE);
    }
    for (long long j=16; j<45; j++)
    {
        draw_char(' ', 5, j, RED, RED);
        draw_char(' ', 6, j, RED, RED);
    }
    for (long long j=18; j<45; j++)
    {
        draw_char(' ', 4, j, WHITE, WHITE);
        draw_char(' ', 7, j, WHITE, WHITE);
    }

}

void draw_Greece()
{
    for (long long i=0; i<9; i++)
    {
        for (long long j=0; j<30; j++)
        {
            draw_char(' ', i, j, BLUE, BLUE);
        }
    }

    for (long long i=1; i<9; i+=2)
    {
        for (long long j=0; j<30; j++)
        {
            draw_char(' ', i, j, WHITE, WHITE);
        }
    }
    for (long long i=0; i<5; i++)
    {
        for (long long j=0; j<10; j++)
        {
            draw_char(' ', i, j, BLUE, BLUE);
        }
    }
    for (long long i=0; i<5; i++)
    {
        draw_char(' ', i, 5, WHITE, WHITE);
        draw_char(' ', i, 4, WHITE, WHITE);
    }
    for (long long j=0; j<10; j++)
    {
        draw_char(' ', 2, j, WHITE, WHITE);
    }



}

void draw_Norway()
{
    for (long long i=0; i<12; i++)
    {
        for (long long j=0; j<45; j++)
        {
            draw_char(' ', i, j, RED, RED);
        }
    }
    for (long long i=0; i<5; i++)
    {
        draw_char(' ', i, 10, WHITE, WHITE);
        draw_char(' ', i, 11, WHITE, WHITE);
        draw_char(' ', i, 12, BLUE, BLUE);
        draw_char(' ', i, 13, BLUE, BLUE);
        draw_char(' ', i, 14, BLUE, BLUE);
        draw_char(' ', i, 15, BLUE, BLUE);
        draw_char(' ', i, 16, WHITE, WHITE);
        draw_char(' ', i, 17, WHITE, WHITE);
    }
    for (long long j=0; j<12; j++)
    {
        draw_char(' ', 4, j, WHITE, WHITE);
    }

    for (long long j=0; j<12; j++)
    {
        draw_char(' ', 5, j, BLUE, BLUE);
        draw_char(' ', 6, j, BLUE, BLUE);
    }
    for (long long j=0; j<12; j++)
    {
        draw_char(' ', 7, j, WHITE, WHITE);
    }
    for (long long i=4; i<12; i++)
    {
        draw_char(' ', i, 12, BLUE, BLUE);
        draw_char(' ', i, 13, BLUE, BLUE);
        draw_char(' ', i, 14, BLUE, BLUE);
        draw_char(' ', i, 15, BLUE, BLUE);
    }
    for (long long i=7; i<12; i++)
    {
        draw_char(' ', i, 10, WHITE, WHITE);
        draw_char(' ', i, 11, WHITE, WHITE);
    }
    for (long long i=7; i<12; i++)
    {
        draw_char(' ', i, 16, WHITE, WHITE);
        draw_char(' ', i, 17, WHITE, WHITE);
    }
    for (long long j=16; j<45; j++)
    {
        draw_char(' ', 5, j, BLUE, BLUE);
        draw_char(' ', 6, j, BLUE, BLUE);
    }
    for (long long j=18; j<45; j++)
    {
        draw_char(' ', 4, j, WHITE, WHITE);
        draw_char(' ', 7, j, WHITE, WHITE);
    }
}

void draw_Malta()
{
    //draw_char(' ', 1, 1, BLACK, BLACK);
    for (long long i=0; i<3; i++)
    {

        for  (long long j=0; j<6; j++)
        {
            draw_char(' ', i+1, j+1, WHITE, WHITE);
        }
    }

    for (long long i=0; i<3; i++)
    {
        for  (long long j=6; j<12; j++)
        {
            draw_char(' ', i+1, j+1, RED, RED);
        }
    }

}



int main()
{

    string countries[]={"Greece", "Malta", "Hungary", "Norway", "England", "Bulgaria", "Iceland", "France"};

    long long br=8;
    string answer;

    draw_char(' ', 30, 40, LIGHT_BLUE, LIGHT_BLUE);

    for (long long i=0; i<br; i++)
    {
        if (i==0) {draw_Greece();}
        if (i==1) {draw_Malta();}
        if (i==2) {draw_Hungary();}
        if (i==3) {draw_Norway();}
        if (i==4) {draw_England();}
        if (i==5) {draw_Bulgaria();}
        if (i==6) {draw_Iceland();}
        if (i==7) {draw_France();}

        for (long long j=0; j<16; j++)
        {
            cout<<endl;
        }
        cout<<"Which flag is this?"<<endl;
        cin>>answer;

        if (answer[0]>96) {answer[0]=char(answer[0]-32);}

        if (answer==countries[i]) {system("cls"); if (i==7) {cout<<"You win"<<endl;}}
        else{system("cls"); cout<<"You lost"<<endl; break;}
    }


    while (1) {};
    return 0;
}

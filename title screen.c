#include<stdio.h>
#include<windows.h>
int main()
{
    HANDLE in,out;
    DWORD info;
    INPUT_RECORD input;
    CONSOLE_SCREEN_BUFFER_INFO scrinfo;
    in=GetStdHandle(STD_INPUT_HANDLE);
    out=GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(in,&scrinfo);
    CHAR_INFO tower[145],of[55],hanoi[145];
    SMALL_RECT twr={45,3,74,8},o={45,10,58,15},han={45,17,74,22};
    COORD zerozero={0,0},fivesz={29,5},twosz={11,5};
    int i,filltower[61]={0,1,2,3,4,7,8,9,12,16,18,19,20,21,22,24,25,26,27,31,35,39,41,45,47,53,57,60,64,68,70,74,76,77,78,82,83,84,85,89,93,97,99,101,103,105,111,113,118,123,124,125,129,131,134,135,136,137,138,140,143},fillof[23]={1,2,3,6,7,8,9,10,11,15,17,22,26,28,29,30,33,37,39,45,46,47,50};
    int fillhanoi[65]={-1,3,6,7,8,11,15,18,19,20,23,24,25,26,27,28,32,34,38,40,41,44,46,50,54,57,58,59,60,61,63,64,65,66,67,69,71,73,75,79,83,86,90,92,96,98,101,102,104,108,112,115,119,121,125,127,131,134,135,136,139,140,141,142,143};
    srand(time(NULL));
    for(i=0;i<145;i++)
    {
        tower[i].Char.AsciiChar=' ';
        tower[i].Attributes=7;
        hanoi[i].Char.AsciiChar=' ';
        hanoi[i].Attributes=7;
    }
    for(i=0;i<55;i++)
    {
        of[i].Char.AsciiChar=' ';
        of[i].Attributes=7;
    }
    for(i=0;i<61;i++)
    {
        tower[filltower[i]].Char.AsciiChar=-37;
        tower[filltower[i]].Attributes=14;
    }
    for(i=0;i<23;i++)
    {
        of[fillof[i]].Char.AsciiChar=-37;
        of[fillof[i]].Attributes=9;
    }
    for(i=0;i<65;i++)
    {
        hanoi[fillhanoi[i]+1].Char.AsciiChar=-37;
        hanoi[fillhanoi[i]+1].Attributes=12;
    }
    WriteConsoleOutput(out,tower,fivesz,zerozero,&twr);
    WriteConsoleOutput(out,of,twosz,zerozero,&o);
    WriteConsoleOutput(out,hanoi,fivesz,zerozero,&han);
    while(!kbhit())
    {
        for(i=0;i<145;i++)
        {
            tower[i].Attributes=rand()%7+9;
            hanoi[i].Attributes=rand()%7+9;
        }
        for(i=0;i<55;i++)
            of[i].Attributes=rand()%7+9;
        WriteConsoleOutput(out,tower,fivesz,zerozero,&twr);
        WriteConsoleOutput(out,of,twosz,zerozero,&o);
        WriteConsoleOutput(out,hanoi,fivesz,zerozero,&han);
        Sleep(100);
    }
    getch();
    return 0;
}

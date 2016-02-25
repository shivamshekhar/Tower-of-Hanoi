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
    CHAR_INFO r[10],p1[3],p2[5],p3[7],e1[3],e2[5],e3[7];
    SMALL_RECT r1r={20,10,20,20},r2r={40,10,40,20},r3r={60,10,60,20},p1r={19,18,21,18},p2r={18,19,22,19},p3r={17,20,23,20};
    COORD zerozero={0,0},rsz={1,10},p1sz={3,1},p2sz={5,1},p3sz={7,1},text={20,22};
    int i,del=2000;
    for(i=0;i<10;i++)
    {
        r[i].Char.AsciiChar=-37;
        r[i].Attributes=FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY|FOREGROUND_GREEN;
    }
    for(i=0;i<7;i++)
    {
        if(i<3)
        {
            p1[i].Char.AsciiChar=-37;
            p1[i].Attributes=12;
            e1[i].Char.AsciiChar=' ';
            e1[i].Attributes=7;
        }
        if(i<5)
        {
            p2[i].Char.AsciiChar=-37;
            p2[i].Attributes=10;
            e2[i].Char.AsciiChar=' ';
            e2[i].Attributes=7;
        }
        p3[i].Char.AsciiChar=-37;
        p3[i].Attributes=9;
        e3[i].Char.AsciiChar=' ';
        e3[i].Attributes=7;
    }
    e1[1].Char.AsciiChar=-37;
    e2[2].Char.AsciiChar=-37;
    e3[3].Char.AsciiChar=-37;
    e1[1].Attributes=15;
    e2[2].Attributes=15;
    e3[3].Attributes=15;
    WriteConsoleOutput(out,r,rsz,zerozero,&r1r);
    WriteConsoleOutput(out,r,rsz,zerozero,&r2r);
    WriteConsoleOutput(out,r,rsz,zerozero,&r3r);
    WriteConsoleOutput(out,p1,p1sz,zerozero,&p1r);
    WriteConsoleOutput(out,p2,p2sz,zerozero,&p2r);
    WriteConsoleOutput(out,p3,p3sz,zerozero,&p3r);
    Sleep(del);
    //step 1
    SetConsoleCursorPosition(out,text);
    printf("from 1 to 3");
    WriteConsoleOutput(out,e1,p1sz,zerozero,&p1r);
    p1r.Left+=40;
    p1r.Right+=40;
    p1r.Top+=2;
    p1r.Bottom+=2;
    WriteConsoleOutput(out,p1,p1sz,zerozero,&p1r);
    //Step 2
    Sleep(del);
    SetConsoleCursorPosition(out,text);
    printf("            ");
    SetConsoleCursorPosition(out,text);
    printf("from 1 to 2");
    WriteConsoleOutput(out,e2,p2sz,zerozero,&p2r);
    p2r.Left+=20;
    p2r.Right+=20;
    p2r.Top+=1;
    p2r.Bottom+=1;
    WriteConsoleOutput(out,p2,p2sz,zerozero,&p2r);
    //step 3
    Sleep(del);
    SetConsoleCursorPosition(out,text);
    printf("            ");
    SetConsoleCursorPosition(out,text);
    printf("from 3 to 2");
    WriteConsoleOutput(out,e1,p1sz,zerozero,&p1r);
    p1r.Left-=20;
    p1r.Right-=20;
    p1r.Top-=1;
    p1r.Bottom-=1;
    WriteConsoleOutput(out,p1,p1sz,zerozero,&p1r);
    //step 4
    Sleep(del);
    SetConsoleCursorPosition(out,text);
    printf("            ");
    SetConsoleCursorPosition(out,text);
    printf("from 1 to 3");
    WriteConsoleOutput(out,e3,p3sz,zerozero,&p3r);
    p3r.Left+=40;
    p3r.Right+=40;
    WriteConsoleOutput(out,p3,p3sz,zerozero,&p3r);
    //step 5
    Sleep(del);
    SetConsoleCursorPosition(out,text);
    printf("            ");
    SetConsoleCursorPosition(out,text);
    printf("from 2 to 1");
    WriteConsoleOutput(out,e1,p1sz,zerozero,&p1r);
    p1r.Left-=20;
    p1r.Right-=20;
    p1r.Top+=1;
    p1r.Bottom+=1;
    WriteConsoleOutput(out,p1,p1sz,zerozero,&p1r);
    //step 6
    Sleep(del);
    SetConsoleCursorPosition(out,text);
    printf("            ");
    SetConsoleCursorPosition(out,text);
    printf("from 2 to 3");
    WriteConsoleOutput(out,e2,p2sz,zerozero,&p2r);
    p2r.Left+=20;
    p2r.Right+=20;
    p2r.Top-=1;
    p2r.Bottom-=1;
    WriteConsoleOutput(out,p2,p2sz,zerozero,&p2r);
    //step 7
    Sleep(del);
    SetConsoleCursorPosition(out,text);
    printf("            ");
    SetConsoleCursorPosition(out,text);
    printf("from 1 to 3");
    WriteConsoleOutput(out,e1,p1sz,zerozero,&p1r);
    p1r.Left+=40;
    p1r.Right+=40;
    p1r.Top-=2;
    p1r.Bottom-=2;
    WriteConsoleOutput(out,p1,p1sz,zerozero,&p1r);
    getch();
    return 0;
}

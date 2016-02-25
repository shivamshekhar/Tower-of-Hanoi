/*
Tower of Hanoi
easy level
made by: Shivam Shekhar
*/
#include<stdio.h>
#include<windows.h>
    HANDLE in;
    HANDLE out;
    DWORD info;
    CONSOLE_SCREEN_BUFFER_INFO scrinfo;
    INPUT_RECORD input;
    CHAR_INFO rod[18],peg1[6],peg2[10],peg3[14],peg4[18],peg5[22],erase1[6],erase2[10],erase3[14],erase4[18],erase5[22];
    COORD zerozero={0,0};
    COORD rodsz={1,18},peg1sz={3,2},peg2sz={5,2},peg3sz={7,2},peg4sz={9,2},peg5sz={11,2};
    COORD text={15,22},pos;
    SMALL_RECT rod1={20,2,20,20},rod2={40,2,40,20},rod3={60,2,60,20};
    SMALL_RECT peg1r1={19,11,21,12},peg2r1={18,13,22,14},peg3r1={17,15,23,16},peg4r1={16,17,24,18},peg5r1={15,19,25,20};
    SMALL_RECT peg1r2={39,11,41,12},peg2r2={38,13,42,14},peg3r2={37,15,43,16},peg4r2={36,17,44,18},peg5r2={35,19,45,20};
    SMALL_RECT peg1r3={59,11,61,12},peg2r3={58,13,62,14},peg3r3={57,15,63,16},peg4r3={56,17,64,18},peg5r3={55,19,65,20};
    int i,j,rod1o[5]={0,1,2,3,4},rod2o[5],rod3o[5],win[5]={0,1,2,3,4};
    int a,b;
    char from,to;
int main()
{
    in=GetStdHandle(STD_INPUT_HANDLE);
    out=GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(out,&scrinfo);
    SetConsoleMode(in,ENABLE_PROCESSED_INPUT);
    for(i=0;i<5;i++)
    {
        rod2o[i]=6;
        rod3o[i]=6;
    }
    for(i=0;i<18;i++)
    {
        rod[i].Char.AsciiChar=-37;
        rod[i].Attributes=FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY;
    }
    for(i=0;i<6;i++)
    {
        peg1[i].Char.AsciiChar=-37;  //red peg
        peg1[i].Attributes=12;
    }
    for(i=0;i<10;i++)
    {
        peg2[i].Char.AsciiChar=-37;
        peg2[i].Attributes=9; //navy blue peg
    }
    for(i=0;i<14;i++)
    {
        peg3[i].Char.AsciiChar=-37;
        peg3[i].Attributes=10; //green peg
    }
    for(i=0;i<18;i++)
    {
        peg4[i].Char.AsciiChar=-37;
        peg4[i].Attributes=11; //light blue peg
    }
    for(i=0;i<22;i++)
    {
        peg5[i].Char.AsciiChar=-37;
        peg5[i].Attributes=13; //magenta peg
    }
    for(i=0;i<6;i++)
    {
        erase1[i].Char.AsciiChar=' ';
        erase1[i].Attributes=7;
    }
    erase1[1].Char.AsciiChar=-37;
    erase1[1].Attributes=15;
    erase1[4].Char.AsciiChar=-37;
    erase1[4].Attributes=15;
    //
    for(i=0;i<10;i++)
    {
        erase2[i].Char.AsciiChar=' ';
        erase2[i].Attributes=7;
    }
    erase2[2].Char.AsciiChar=-37;
    erase2[2].Attributes=15;
    erase2[7].Char.AsciiChar=-37;
    erase2[7].Attributes=15;
    //
    for(i=0;i<14;i++)
    {
        erase3[i].Char.AsciiChar=' ';
        erase3[i].Attributes=7;
    }
    erase3[3].Char.AsciiChar=-37;
    erase3[3].Attributes=15;
    erase3[10].Char.AsciiChar=-37;
    erase3[10].Attributes=15;
    //
    for(i=0;i<18;i++)
    {
        erase4[i].Char.AsciiChar=' ';
        erase4[i].Attributes=7;
    }
    erase4[4].Char.AsciiChar=-37;
    erase4[4].Attributes=15;
    erase4[13].Char.AsciiChar=-37;
    erase4[13].Attributes=15;
    //
    for(i=0;i<22;i++)
    {
        erase5[i].Char.AsciiChar=' ';
        erase5[i].Attributes=7;
    }
    erase5[5].Char.AsciiChar=-37;
    erase5[5].Attributes=15;
    erase5[16].Char.AsciiChar=-37;
    erase5[16].Attributes=15;
    //printing the rods
    WriteConsoleOutput(out,rod,rodsz,zerozero,&rod1);
    WriteConsoleOutput(out,rod,rodsz,zerozero,&rod2);
    WriteConsoleOutput(out,rod,rodsz,zerozero,&rod3);
    //printing the pegs
    WriteConsoleOutput(out,peg1,peg1sz,zerozero,&peg1r1);
    WriteConsoleOutput(out,peg2,peg2sz,zerozero,&peg2r1);
    WriteConsoleOutput(out,peg3,peg3sz,zerozero,&peg3r1);
    WriteConsoleOutput(out,peg4,peg4sz,zerozero,&peg4r1);
    WriteConsoleOutput(out,peg5,peg5sz,zerozero,&peg5r1);
    //starting the game
    while(1)
    {
        while(1)
        {
            pos=text;
            SetConsoleCursorPosition(out,text);
            for(i=0;i<79;i++)
                printf(" ");
            pos.Y++;
            SetConsoleCursorPosition(out,pos);
            for(i=0;i<79;i++)
                printf(" ");
            //taking input
            SetConsoleCursorPosition(out,text);
            printf("from ");
            from=getch();
            printf("%d ", from-48);
            printf("to ");
            to=getch();
            printf("%d",to-48);
            pos=text;
            pos.Y++;
            SetConsoleCursorPosition(out,pos);
            printf("is this move okay (y/n) : ");
            if(getch()=='y')
            {
                if(from>51 || from<49 || to>51 || to<49)
                {
                    pos=text;
                    pos.Y++;
                    SetConsoleCursorPosition(out,pos);
                    for(i=0;i<79;i++)
                        printf(" ");
                    SetConsoleCursorPosition(out,pos);
                    printf("invalid input");
                    Sleep(1000);
                    continue;
                }
                else
                    break;
            }

        }
        erasepeg();
        changepeg(to,from);
        printpeg();
       //winning condition
        for(i=0;i<5;i++)
        {
            if(win[i]!=rod3o[i])
                break;
        }
        if(i==5)
            break;
    }
    system("cls");
    printf("you win!");
    getch();
    return 0;
}
void printpeg(void);
void printpeg()
{
    for(i=0;i<5;i++)
    {
        switch(rod1o[i])
        {
            case 0:
            peg1r1.Top=11 + i*2;
            peg1r1.Bottom=12 + i*2;
            WriteConsoleOutput(out,peg1,peg1sz,zerozero,&peg1r1);
            break;
            case 1:
            peg2r1.Top=11 + i*2;
            peg2r1.Bottom=12 + i*2;
            WriteConsoleOutput(out,peg2,peg2sz,zerozero,&peg2r1);
            break;
            case 2:
            peg3r1.Top=11 + i*2;
            peg3r1.Bottom=12 + i*2;
            WriteConsoleOutput(out,peg3,peg3sz,zerozero,&peg3r1);
            break;
            case 3:
            peg4r1.Top=11 + i*2;
            peg4r1.Bottom=12 + i*2;
            WriteConsoleOutput(out,peg4,peg4sz,zerozero,&peg4r1);
            break;
            case 4:
            peg5r1.Top=11 + i*2;
            peg5r1.Bottom=12 + i*2;
            WriteConsoleOutput(out,peg5,peg5sz,zerozero,&peg5r1);
            break;
        }
        switch(rod2o[i])
        {
            case 0:
            peg1r2.Top=11 + i*2;
            peg1r2.Bottom=12 + i*2;
            WriteConsoleOutput(out,peg1,peg1sz,zerozero,&peg1r2);
            break;
            case 1:
            peg2r2.Top=11 + i*2;
            peg2r2.Bottom=12 + i*2;
            WriteConsoleOutput(out,peg2,peg2sz,zerozero,&peg2r2);
            break;
            case 2:
            peg3r2.Top=11 + i*2;
            peg3r2.Bottom=12 + i*2;
            WriteConsoleOutput(out,peg3,peg3sz,zerozero,&peg3r2);
            break;
            case 3:
            peg4r2.Top=11 + i*2;
            peg4r2.Bottom=12 + i*2;
            WriteConsoleOutput(out,peg4,peg4sz,zerozero,&peg4r2);
            break;
            case 4:
            peg5r2.Top=11 + i*2;
            peg5r2.Bottom=12 + i*2;
            WriteConsoleOutput(out,peg5,peg5sz,zerozero,&peg5r2);
            break;
        }
        switch(rod3o[i])
        {
            case 0:
            peg1r3.Top=11 + i*2;
            peg1r3.Bottom=12 + i*2;
            WriteConsoleOutput(out,peg1,peg1sz,zerozero,&peg1r3);
            break;
            case 1:
            peg2r3.Top=11 + i*2;
            peg2r3.Bottom=12 + i*2;
            WriteConsoleOutput(out,peg2,peg2sz,zerozero,&peg2r3);
            break;
            case 2:
            peg3r3.Top=11 + i*2;
            peg3r3.Bottom=12 + i*2;
            WriteConsoleOutput(out,peg3,peg3sz,zerozero,&peg3r3);
            break;
            case 3:
            peg4r3.Top=11 + i*2;
            peg4r3.Bottom=12 + i*2;
            WriteConsoleOutput(out,peg4,peg4sz,zerozero,&peg4r3);
            break;
            case 4:
            peg5r3.Top=11 + i*2;
            peg5r3.Bottom=12 + i*2;
            WriteConsoleOutput(out,peg5,peg5sz,zerozero,&peg5r3);
            break;
        }

    }
}
void erasepeg(void);
void erasepeg()
{
    WriteConsoleOutput(out,erase1,peg1sz,zerozero,&peg1r1);
    WriteConsoleOutput(out,erase2,peg2sz,zerozero,&peg2r1);
    WriteConsoleOutput(out,erase3,peg3sz,zerozero,&peg3r1);
    WriteConsoleOutput(out,erase4,peg4sz,zerozero,&peg4r1);
    WriteConsoleOutput(out,erase5,peg5sz,zerozero,&peg5r1);
    //
    WriteConsoleOutput(out,erase1,peg1sz,zerozero,&peg1r2);
    WriteConsoleOutput(out,erase2,peg2sz,zerozero,&peg2r2);
    WriteConsoleOutput(out,erase3,peg3sz,zerozero,&peg3r2);
    WriteConsoleOutput(out,erase4,peg4sz,zerozero,&peg4r2);
    WriteConsoleOutput(out,erase5,peg5sz,zerozero,&peg5r2);
    //
    WriteConsoleOutput(out,erase1,peg1sz,zerozero,&peg1r3);
    WriteConsoleOutput(out,erase2,peg2sz,zerozero,&peg2r3);
    WriteConsoleOutput(out,erase3,peg3sz,zerozero,&peg3r3);
    WriteConsoleOutput(out,erase4,peg4sz,zerozero,&peg4r3);
    WriteConsoleOutput(out,erase5,peg5sz,zerozero,&peg5r3);
}
void changepeg(char,char);
void changepeg(char TO,char FROM)
{
    if(TO==50 && FROM==49)
    {
        for(i=0;i<5;i++)
        {
            if(rod1o[i]!=6)
            {
                a=i;
                break;
            }
        }
        for(i=0;i<5;i++)
        {
            if(rod2o[i]!=6)
            {
                b=i;
                break;
            }
        }
        if(i==5)
            b=5;
        if(rod2o[b]>rod1o[a] || rod2o[4]==6)
        {
            rod2o[b-1]=rod1o[a];
            rod1o[a]=6;
        }
    }
    //
    else if(TO==49 && FROM==50)
    {
        for(i=0;i<5;i++)
        {
            if(rod2o[i]!=6)
            {
                a=i;
                break;
            }
        }
        for(i=0;i<5;i++)
        {
            if(rod1o[i]!=6)
            {
                b=i;
                break;
            }
        }
        if(i==5)
            b=5;
        if(rod1o[b]>rod2o[a] || rod1o[4]==6)
        {
            rod1o[b-1]=rod2o[a];
            rod2o[a]=6;
        }
    }
    //
    else if(TO==51 && FROM==50)
    {
        for(i=0;i<5;i++)
        {
            if(rod2o[i]!=6)
            {
                a=i;
                break;
            }
        }
        for(i=0;i<5;i++)
        {
            if(rod3o[i]!=6)
            {
                b=i;
                break;
            }
        }
        if(i==5)
            b=5;
        if(rod3o[b]>rod2o[a] || rod3o[4]==6)
        {
            rod3o[b-1]=rod2o[a];
            rod2o[a]=6;
        }
    }
    //
    else if(TO==50 && FROM==51)
    {
        for(i=0;i<5;i++)
        {
            if(rod3o[i]!=6)
            {
                a=i;
                break;
            }
        }
        for(i=0;i<5;i++)
        {
            if(rod2o[i]!=6)
            {
                b=i;
                break;
            }
        }
        if(i==5)
            b=5;
        if(rod2o[b]>rod3o[a] || rod2o[4]==6)
        {
            rod2o[b-1]=rod3o[a];
            rod3o[a]=6;
        }
    }
    //
    else if(TO==51 && FROM==49)
    {
        for(i=0;i<5;i++)
        {
            if(rod1o[i]!=6)
            {
                a=i;
                break;
            }
        }
        for(i=0;i<5;i++)
        {
            if(rod3o[i]!=6)
            {
                b=i;
                break;
            }
        }
        if(i==5)
            b=5;
        if(rod3o[b]>rod1o[a] || rod3o[4]==6)
        {
            rod3o[b-1]=rod1o[a];
            rod1o[a]=6;
        }

    }
    //
    else if(TO==49 && FROM==51)
    {
        for(i=0;i<5;i++)
        {
            if(rod3o[i]!=6)
            {
                a=i;
                break;
            }
        }
        for(i=0;i<5;i++)
        {
            if(rod1o[i]!=6)
            {
                b=i;
                break;
            }
        }
        if(i==5)
            b=5;
        if(rod1o[b]>rod3o[a] || rod1o[4]==6)
        {
            rod1o[b-1]=rod3o[a];
            rod3o[a]=6;
        }
    }
}

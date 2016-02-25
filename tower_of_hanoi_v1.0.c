/*
Tower of Hanoi game
version 1.0
made by: Shivam Shekhar
*/
#include "towerofhanoi.h"
int main()
{
    in=GetStdHandle(STD_INPUT_HANDLE);
    out=GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(out,&scrinfo);
    SetConsoleMode(in,ENABLE_PROCESSED_INPUT);
    for(i=0;i<6;i++)
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
    for(i=0;i<26;i++)
    {
        peg6[i].Char.AsciiChar=-37;
        peg6[i].Attributes=14; //yellow peg
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
    for(i=0;i<26;i++)
    {
        erase6[i].Char.AsciiChar=' ';
        erase6[i].Attributes=7;
    }
    erase6[6].Char.AsciiChar=-37;
    erase6[6].Attributes=15;
    erase6[19].Char.AsciiChar=-37;
    erase6[19].Attributes=15;
    //home screen
    title();
    while(br)
    {
        system("cls");
        SetConsoleCursorPosition(out,pos1);
        printf("1. Play");
        pos1.Y++;
        SetConsoleCursorPosition(out,pos1);
        printf("2. View animation on how to play");
        pos1.Y++;
        SetConsoleCursorPosition(out,pos1);
        printf("3. Rules");
        switch(getch())
        {
        case 49:
            br=0;
            break;
            case 50:
            while(1)
            {
                system("cls");
                animate();
                printf("\ndo you want to replay this(y/n)?");
                if(getch()=='y')
                    continue;
                else
                    break;
            }
            break;
            case 51:
                rules();
                break;
        }
        pos1.Y-=2;
    }
    system("cls");
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
    WriteConsoleOutput(out,peg6,peg6sz,zerozero,&peg6r1);
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
        for(i=0;i<6;i++)
        {
            if(win[i]!=rod3o[i])
                break;
        }
        if(i==6)
            break;
    }
    system("cls");
    printf("you win!");
    getch();
    return 0;
}

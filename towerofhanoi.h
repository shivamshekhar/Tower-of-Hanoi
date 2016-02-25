/*Tower of Hanoi
header file
version 1.0
made by: Shivam Shekhar
*/
//header files
#include<stdio.h>
#include<windows.h>
    //declarations
    HANDLE in;
    HANDLE out;
    DWORD info;
    CONSOLE_SCREEN_BUFFER_INFO scrinfo;
    INPUT_RECORD input;
    CHAR_INFO rod[18],peg1[6],peg2[10],peg3[14],peg4[18],peg5[22],peg6[26],erase1[6],erase2[10],erase3[14],erase4[18],erase5[22],erase6[26];
    COORD zerozero={0,0};
    COORD rodsz={1,18},peg1sz={3,2},peg2sz={5,2},peg3sz={7,2},peg4sz={9,2},peg5sz={11,2},peg6sz={13,2};//,erase1sz={3,2},erase2sz={5,2},erase3sz={7,2},erase4sz={9,2},erase5sz={11,2},erase6sz={13,2};
    COORD text={15,22},pos,pos1={30,11};
    SMALL_RECT rod1={20,2,20,20},rod2={40,2,40,20},rod3={60,2,60,20};
    SMALL_RECT peg1r1={19,9,21,10},peg2r1={18,11,22,12},peg3r1={17,13,23,14},peg4r1={16,15,24,16},peg5r1={15,17,25,18},peg6r1={14,19,26,20};
    SMALL_RECT peg1r2={39,9,41,10},peg2r2={38,11,42,12},peg3r2={37,13,43,14},peg4r2={36,15,44,16},peg5r2={35,17,45,18},peg6r2={34,19,46,20};
    SMALL_RECT peg1r3={59,9,61,10},peg2r3={58,11,62,12},peg3r3={57,13,63,14},peg4r3={56,15,64,16},peg5r3={55,17,65,18},peg6r3={54,19,66,20};
    int i,j,rod1o[6]={0,1,2,3,4,5},rod2o[6],rod3o[6],win[6]={0,1,2,3,4,5};
    int a,b,br=1;
    char from,to;
//function declarations
void printpeg(void);
void erasepeg(void);
void changepeg(char,char);
void animate(void);
void title(void);
void rules(void);
//function definitions
void printpeg()
{
    for(i=0;i<6;i++)
    {
        switch(rod1o[i])
        {
            case 0:
            peg1r1.Top=9 + i*2;
            peg1r1.Bottom=10 + i*2;
            WriteConsoleOutput(out,peg1,peg1sz,zerozero,&peg1r1);
            break;
            case 1:
            peg2r1.Top=9 + i*2;
            peg2r1.Bottom=10 + i*2;
            WriteConsoleOutput(out,peg2,peg2sz,zerozero,&peg2r1);
            break;
            case 2:
            peg3r1.Top=9 + i*2;
            peg3r1.Bottom=10 + i*2;
            WriteConsoleOutput(out,peg3,peg3sz,zerozero,&peg3r1);
            break;
            case 3:
            peg4r1.Top=9 + i*2;
            peg4r1.Bottom=10 + i*2;
            WriteConsoleOutput(out,peg4,peg4sz,zerozero,&peg4r1);
            break;
            case 4:
            peg5r1.Top=9 + i*2;
            peg5r1.Bottom=10 + i*2;
            WriteConsoleOutput(out,peg5,peg5sz,zerozero,&peg5r1);
            break;
            case 5:
            peg6r1.Top=9 + i*2;
            peg6r1.Bottom=10 + i*2;
            WriteConsoleOutput(out,peg6,peg6sz,zerozero,&peg6r1);
            break;
        }
        switch(rod2o[i])
        {
            case 0:
            peg1r2.Top=9 + i*2;
            peg1r2.Bottom=10 + i*2;
            WriteConsoleOutput(out,peg1,peg1sz,zerozero,&peg1r2);
            break;
            case 1:
            peg2r2.Top=9 + i*2;
            peg2r2.Bottom=10 + i*2;
            WriteConsoleOutput(out,peg2,peg2sz,zerozero,&peg2r2);
            break;
            case 2:
            peg3r2.Top=9 + i*2;
            peg3r2.Bottom=10 + i*2;
            WriteConsoleOutput(out,peg3,peg3sz,zerozero,&peg3r2);
            break;
            case 3:
            peg4r2.Top=9 + i*2;
            peg4r2.Bottom=10 + i*2;
            WriteConsoleOutput(out,peg4,peg4sz,zerozero,&peg4r2);
            break;
            case 4:
            peg5r2.Top=9 + i*2;
            peg5r2.Bottom=10 + i*2;
            WriteConsoleOutput(out,peg5,peg5sz,zerozero,&peg5r2);
            break;
            case 5:
            peg6r2.Top=9 + i*2;
            peg6r2.Bottom=10 + i*2;
            WriteConsoleOutput(out,peg6,peg6sz,zerozero,&peg6r2);
            break;
        }
        switch(rod3o[i])
        {
            case 0:
            peg1r3.Top=9 + i*2;
            peg1r3.Bottom=10 + i*2;
            WriteConsoleOutput(out,peg1,peg1sz,zerozero,&peg1r3);
            break;
            case 1:
            peg2r3.Top=9 + i*2;
            peg2r3.Bottom=10 + i*2;
            WriteConsoleOutput(out,peg2,peg2sz,zerozero,&peg2r3);
            break;
            case 2:
            peg3r3.Top=9 + i*2;
            peg3r3.Bottom=10 + i*2;
            WriteConsoleOutput(out,peg3,peg3sz,zerozero,&peg3r3);
            break;
            case 3:
            peg4r3.Top=9 + i*2;
            peg4r3.Bottom=10 + i*2;
            WriteConsoleOutput(out,peg4,peg4sz,zerozero,&peg4r3);
            break;
            case 4:
            peg5r3.Top=9 + i*2;
            peg5r3.Bottom=10 + i*2;
            WriteConsoleOutput(out,peg5,peg5sz,zerozero,&peg5r3);
            break;
            case 5:
            peg6r3.Top=9 + i*2;
            peg6r3.Bottom=10 + i*2;
            WriteConsoleOutput(out,peg6,peg6sz,zerozero,&peg6r3);
            break;
        }

    }
}
void erasepeg()
{
    WriteConsoleOutput(out,erase1,peg1sz,zerozero,&peg1r1);
    WriteConsoleOutput(out,erase2,peg2sz,zerozero,&peg2r1);
    WriteConsoleOutput(out,erase3,peg3sz,zerozero,&peg3r1);
    WriteConsoleOutput(out,erase4,peg4sz,zerozero,&peg4r1);
    WriteConsoleOutput(out,erase5,peg5sz,zerozero,&peg5r1);
    WriteConsoleOutput(out,erase6,peg6sz,zerozero,&peg6r1);
    //
    WriteConsoleOutput(out,erase1,peg1sz,zerozero,&peg1r2);
    WriteConsoleOutput(out,erase2,peg2sz,zerozero,&peg2r2);
    WriteConsoleOutput(out,erase3,peg3sz,zerozero,&peg3r2);
    WriteConsoleOutput(out,erase4,peg4sz,zerozero,&peg4r2);
    WriteConsoleOutput(out,erase5,peg5sz,zerozero,&peg5r2);
    WriteConsoleOutput(out,erase6,peg6sz,zerozero,&peg6r2);
    //
    WriteConsoleOutput(out,erase1,peg1sz,zerozero,&peg1r3);
    WriteConsoleOutput(out,erase2,peg2sz,zerozero,&peg2r3);
    WriteConsoleOutput(out,erase3,peg3sz,zerozero,&peg3r3);
    WriteConsoleOutput(out,erase4,peg4sz,zerozero,&peg4r3);
    WriteConsoleOutput(out,erase5,peg5sz,zerozero,&peg5r3);
    WriteConsoleOutput(out,erase6,peg6sz,zerozero,&peg6r3);
}
void changepeg(char TO,char FROM)
{
    if(TO==50 && FROM==49)
    {
        for(i=0;i<6;i++)
        {
            if(rod1o[i]!=6)
            {
                a=i;
                break;
            }
        }
        for(i=0;i<6;i++)
        {
            if(rod2o[i]!=6)
            {
                b=i;
                break;
            }
        }
        if(i==6)
            b=6;
        if(rod2o[b]>rod1o[a] || rod2o[5]==6)
        {
            rod2o[b-1]=rod1o[a];
            rod1o[a]=6;
        }
    }
    //
    else if(TO==49 && FROM==50)
    {
        for(i=0;i<6;i++)
        {
            if(rod2o[i]!=6)
            {
                a=i;
                break;
            }
        }
        for(i=0;i<6;i++)
        {
            if(rod1o[i]!=6)
            {
                b=i;
                break;
            }
        }
        if(i==6)
            b=6;
        if(rod1o[b]>rod2o[a] || rod1o[5]==6)
        {
            rod1o[b-1]=rod2o[a];
            rod2o[a]=6;
        }
    }
    //
    else if(TO==51 && FROM==50)
    {
        for(i=0;i<6;i++)
        {
            if(rod2o[i]!=6)
            {
                a=i;
                break;
            }
        }
        for(i=0;i<6;i++)
        {
            if(rod3o[i]!=6)
            {
                b=i;
                break;
            }
        }
        if(i==6)
            b=6;
        if(rod3o[b]>rod2o[a] || rod3o[5]==6)
        {
            rod3o[b-1]=rod2o[a];
            rod2o[a]=6;
        }
    }
    //
    else if(TO==50 && FROM==51)
    {
        for(i=0;i<6;i++)
        {
            if(rod3o[i]!=6)
            {
                a=i;
                break;
            }
        }
        for(i=0;i<6;i++)
        {
            if(rod2o[i]!=6)
            {
                b=i;
                break;
            }
        }
        if(i==6)
            b=6;
        if(rod2o[b]>rod3o[a] || rod2o[5]==6)
        {
            rod2o[b-1]=rod3o[a];
            rod3o[a]=6;
        }
    }
    //
    else if(TO==51 && FROM==49)
    {
        for(i=0;i<6;i++)
        {
            if(rod1o[i]!=6)
            {
                a=i;
                break;
            }
        }
        for(i=0;i<6;i++)
        {
            if(rod3o[i]!=6)
            {
                b=i;
                break;
            }
        }
        if(i==6)
            b=6;
        if(rod3o[b]>rod1o[a] || rod3o[5]==6)
        {
            rod3o[b-1]=rod1o[a];
            rod1o[a]=6;
        }

    }
    //
    else if(TO==49 && FROM==51)
    {
        for(i=0;i<6;i++)
        {
            if(rod3o[i]!=6)
            {
                a=i;
                break;
            }
        }
        for(i=0;i<6;i++)
        {
            if(rod1o[i]!=6)
            {
                b=i;
                break;
            }
        }
        if(i==6)
            b=6;
        if(rod1o[b]>rod3o[a] || rod1o[5]==6)
        {
            rod1o[b-1]=rod3o[a];
            rod3o[a]=6;
        }
    }
}
void animate()
{
    CHAR_INFO r[10],p1[3],p2[5],p3[7],e1[3],e2[5],e3[7];
    SMALL_RECT r1r={20,10,20,20},r2r={40,10,40,20},r3r={60,10,60,20},p1r={19,18,21,18},p2r={18,19,22,19},p3r={17,20,23,20};
    COORD rsz={1,10},p1sz={3,1},p2sz={5,1},p3sz={7,1},text1={20,22};
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
    SetConsoleCursorPosition(out,text1);
    printf("from 1 to 3");
    WriteConsoleOutput(out,e1,p1sz,zerozero,&p1r);
    p1r.Left+=40;
    p1r.Right+=40;
    p1r.Top+=2;
    p1r.Bottom+=2;
    WriteConsoleOutput(out,p1,p1sz,zerozero,&p1r);
    //Step 2
    Sleep(del);
    SetConsoleCursorPosition(out,text1);
    printf("            ");
    SetConsoleCursorPosition(out,text1);
    printf("from 1 to 2");
    WriteConsoleOutput(out,e2,p2sz,zerozero,&p2r);
    p2r.Left+=20;
    p2r.Right+=20;
    p2r.Top+=1;
    p2r.Bottom+=1;
    WriteConsoleOutput(out,p2,p2sz,zerozero,&p2r);
    //step 3
    Sleep(del);
    SetConsoleCursorPosition(out,text1);
    printf("            ");
    SetConsoleCursorPosition(out,text1);
    printf("from 3 to 2");
    WriteConsoleOutput(out,e1,p1sz,zerozero,&p1r);
    p1r.Left-=20;
    p1r.Right-=20;
    p1r.Top-=1;
    p1r.Bottom-=1;
    WriteConsoleOutput(out,p1,p1sz,zerozero,&p1r);
    //step 4
    Sleep(del);
    SetConsoleCursorPosition(out,text1);
    printf("            ");
    SetConsoleCursorPosition(out,text1);
    printf("from 1 to 3");
    WriteConsoleOutput(out,e3,p3sz,zerozero,&p3r);
    p3r.Left+=40;
    p3r.Right+=40;
    WriteConsoleOutput(out,p3,p3sz,zerozero,&p3r);
    //step 5
    Sleep(del);
    SetConsoleCursorPosition(out,text1);
    printf("            ");
    SetConsoleCursorPosition(out,text1);
    printf("from 2 to 1");
    WriteConsoleOutput(out,e1,p1sz,zerozero,&p1r);
    p1r.Left-=20;
    p1r.Right-=20;
    p1r.Top+=1;
    p1r.Bottom+=1;
    WriteConsoleOutput(out,p1,p1sz,zerozero,&p1r);
    //step 6
    Sleep(del);
    SetConsoleCursorPosition(out,text1);
    printf("            ");
    SetConsoleCursorPosition(out,text1);
    printf("from 2 to 3");
    WriteConsoleOutput(out,e2,p2sz,zerozero,&p2r);
    p2r.Left+=20;
    p2r.Right+=20;
    p2r.Top-=1;
    p2r.Bottom-=1;
    WriteConsoleOutput(out,p2,p2sz,zerozero,&p2r);
    //step 7
    Sleep(del);
    SetConsoleCursorPosition(out,text1);
    printf("            ");
    SetConsoleCursorPosition(out,text1);
    printf("from 1 to 3");
    WriteConsoleOutput(out,e1,p1sz,zerozero,&p1r);
    p1r.Left+=40;
    p1r.Right+=40;
    p1r.Top-=2;
    p1r.Bottom-=2;
    WriteConsoleOutput(out,p1,p1sz,zerozero,&p1r);

}
//
void title()
{
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
    WriteConsoleOutput(out,peg1,peg1sz,zerozero,&peg1r1);
    WriteConsoleOutput(out,peg2,peg2sz,zerozero,&peg2r1);
    WriteConsoleOutput(out,peg3,peg3sz,zerozero,&peg3r1);
    WriteConsoleOutput(out,peg4,peg4sz,zerozero,&peg4r1);
    WriteConsoleOutput(out,peg5,peg5sz,zerozero,&peg5r1);
    WriteConsoleOutput(out,peg6,peg6sz,zerozero,&peg6r1);
    //
    WriteConsoleOutput(out,tower,fivesz,zerozero,&twr);
    WriteConsoleOutput(out,of,twosz,zerozero,&o);
    WriteConsoleOutput(out,hanoi,fivesz,zerozero,&han);
    SetConsoleCursorPosition(out,text);
    printf("made by: Shivam Shekhar");
    text.Y++;
    SetConsoleCursorPosition(out,text);
    printf("press any key to begin....");
    text.Y--;
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
}
//
void rules()
{
    system("cls");
    printf("1. There are three rods and 6 pegs. The aim of this game is to move all the pegs(circular discs) from rod 1 to rod 3 in an ascending order from top to bottom.\n\n");
    printf("2. You can only shift one peg at a time.\n\n");
    printf("3. to shift a peg, enter the rod 'from' where you want to shift the peg, and then enter the rod 'to' where you want to shift the peg.\n\n");
    printf("4. you can place a small peg over a large peg but you can't place a large peg   over a small peg\n\n");
    printf("5. for more information, view the animation on how to play\n\n\n\n");
    printf("press any key to continue.......");
    getch();
}


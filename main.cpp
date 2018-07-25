#include <graphics.h>
#include <bits/stdc++.h>
#include <time.h>
#include "character.h"
#include "animation.h"
#include "scorecard.h"
#include "notification.h"
#include "standing.h"
#define LooP while(1)
using namespace std;

struct  Cir
{
    int x ;
    int y ;
    int r ;
};

struct  Rect
{
    int topx;
    int topy;
    int downx;
    int downy;
};

struct Point
{
    int x;
    int y;
};
struct person
{
    char name[30];
    int lvl1;
    int lvl2;
    int lvl3;
} NewPlayer;

double Distance(struct Point a , struct  Point b);

int PixelEr = 2 ;
int COLORS[]= {LIGHTRED,LIGHTBLUE,LIGHTCYAN,LIGHTGRAY,LIGHTGREEN,LIGHTMAGENTA,YELLOW,WHITE};
struct Point Last[50];

void ClearLast(void);
void PushLast(struct Point a);
void ShowMenu();
void RunGame();
int LevelOne();
int LevelTwo();
int LevelBoss();
void FillRect(struct  Rect  a , int colr , int fillpet);
bool inRange(struct  Rect  a,struct  Point b);
bool inRange(struct  Cir  a, struct Point b);
bool inRange(struct  Rect  a,struct   Rect  b);
bool inRange(struct  Rect  a,struct  Cir  b, int type);
bool touched(struct  Rect  a ,struct  Cir  b);
bool touched(struct  Cir  a ,struct  Cir  b);
struct  Cir  _C(int x ,int y , int r);                                          // convert into structure
struct  Rect  _R(int x1 , int y1 , int x2 ,int y2);                           // convert into structure
struct Point _P(int x , int y);                                                  // convert into structure
void MargeinRect(Rect a , int &x , int &y ,int topin , int downin);
void GameMode();
void ArcadeScore(int score);
void HS();



int  ScoreStore();
void GetUserName();
void  ArcadeMode();

int main()
{

    initwindow(1000,600,"Wrecking Face");
    //YouAreAwesome(3);
    GetUserName();
    ShowMenu();
    LooP;
}

void RunGame()
{
    //initialize to zero
    NewPlayer.lvl1=NewPlayer.lvl2=NewPlayer.lvl3=0;
    //start level one
    NewPlayer.lvl1 = LevelOne();

    //if level 1 passed go deep
    if(NewPlayer.lvl1)
    {
        LevelFinis(1);
        //start level Two
        NewPlayer.lvl2 = LevelTwo();
        //if level 2 passed go deep
        if(NewPlayer.lvl2)
        {
            LevelFinis(2);
            //start level boss
            NewPlayer.lvl3 = LevelBoss();
            //if level 2 passed go store data
            if(NewPlayer.lvl3)
            {
                // pass all level
                YouAreAwesome(ScoreStore());
                //cleardevice();
                return ;

            }
            else
            {
                // fail in level boss
                //cleardevice();
                return;
            }
        }
        else
        {
            //fail in level two
            return ;
        }
    }
    else
    {
        // fail in level one
        //cleardevice();
        return ;
    }
}

void ArcadeMode()
{
    //initial obstacle position
    int dx[] =	{ 380, 800, 500, 600, 700, 440, 400, 550, 700, 800};
    int dy[] =	{ 100, 200, 300, 400, 70 , 450, 300, 250, 300, 450};
    //initial obstacle direction
    int dirx[]= { 1,  1, -1, -1, -1,  -1,  1, -1,  1,  -1};
    int diry[]= {-1,  1,  1, -1,  1,  1, -1, -1,  1,  1};


    int obstacle = 2   ;
    int score    = 0   ;
    int Size     = 50  ;
    //GameZone Region
    int topx     = 350 ;
    int topy     = 20  ;
    int downx    = 900 ;
    int downy    = 500 ;

    // making REct for Game zone
    struct  Rect  GameZone = _R(topx-2, topy-2, downx+2, downy+2);

    // setting mouse position all zero
    ClearLast();

    // setting up background
    readimagefile("gamedata/b/l2gb.jpg", 0, 0, getmaxx(), getmaxy());
    FillRect(GameZone, WHITE, SOLID_FILL);

    // initialize mouse position
    int ballx    =	(topx+downx)/2;
    int bally    =	(topy+downy)/2;
    int ballr = 5;

    // for scoring purpose and showing Remaining time

    //initial food position
    int FooDx = 500;
    int FooDy = 300;
    int FooDr = 20 ;


    // scoreboard
    readimagefile("gamedata/b/black.jpg",0,0,200,100);
    PrintScore(score);
    ShowPlayerName(NewPlayer.name);


    WaitForConfirmation();
    while(1)
    {
        // Space bar pause continue
        if(kbhit())
        {
            char c;
            while(kbhit()) c = getch();
            if(c==' ')
            {
                while(1)
                {
                    c = getch();
                    if(c==' ') break;
                }
            }
        }

        // started counting time

        //clearing last mouse trail ball
        if(Last[0].x)
        {
            setcolor(WHITE);
            setfillstyle(SOLID_FILL,WHITE);
            fillellipse(Last[0].x, Last[0].y, ballr, ballr);
        }

        // Checking if Ball out of GameZone
        MargeinRect(GameZone,ballx,bally,ballr,ballr);
        // Printing Ball
        setcolor(BLUE);
        setfillstyle(SOLID_FILL, BLUE);
        fillellipse(ballx, bally, ballr, ballr);
        // Push Position of Ball on List
        PushLast(_P(ballx, bally));


        setcolor(WHITE);

        // Changing direction And position of obstacle
        for(int i =0 ; i < obstacle ; i++)
        {
            // changing direction if out of range
            if(i%2)
            {
                if(dx[i] + dirx[i] < topx)              dirx[i] = - dirx[i];
                if(dx[i] + dirx[i] > downx - Size)      dirx[i] = - dirx[i];
                if(dy[i] + diry[i] < topy)              diry[i] = - diry[i];
                if(dy[i] + diry[i] > downy - Size)      diry[i] = - diry[i];
            }
            else
            {
                if(dx[i] + dirx[i] < topx+Size/2)              dirx[i] = - dirx[i];
                if(dx[i] + dirx[i] > downx-Size/2)      dirx[i] = - dirx[i];
                if(dy[i] + diry[i] < topy+Size/2)              diry[i] = - diry[i];
                if(dy[i] + diry[i] > downy - Size/2)      diry[i] = - diry[i];
            }
            // Changing Position
            dx[i] += dirx[i] ;
            dy[i] += diry[i];
        }
        // Print Obstacle , Detect Collision
        for(int i=0 ; i < obstacle ; i++)
        {

            if(i%2)
            {
                BoxFaceSmile(dx[i], dy[i],Size, COLORS[i%8]);

                // Detect Collision With obstacle
                if(inRange(_R(dx[i]+PixelEr, dy[i]+PixelEr, dx[i]+Size-PixelEr, dy[i]+Size-PixelEr), _C(ballx, bally, ballr-PixelEr), 1))
                {
                    //after collision print sad face
                    BoxFaceSad(dx[i], dy[i],Size, COLORS[i%8]);
                    //make ball red
                    setcolor(LIGHTRED);
                    setfillstyle(SOLID_FILL, LIGHTRED);
                    fillellipse(ballx, bally, ballr, ballr);
                    // wait 2 seconds And se Face Eaten Animation
                    // CollisionMsg(2);
                    readimagefile("gamedata/b/wrecked.jpg",350-2,20-2,900+2,500+2);
                    getch();
                    //show collision message
                    ArcadeScore(score);
                    return ;
                }
            }
            else
            {
                CircleFaceSmile(dx[i], dy[i],Size/2, COLORS[i%8]);
                if(touched(_C(dx[i], dy[i],Size/2), _C(ballx, bally, ballr)))
                {
                    //after collision print sad face
                    CircleFaceSad(dx[i], dy[i],Size/2, COLORS[i%8]);
                    //make ball red
                    setcolor(LIGHTRED);
                    setfillstyle(SOLID_FILL, LIGHTRED);
                    fillellipse(ballx, bally, ballr, ballr);
                    // wait 2 seconds And se Face Eaten Animation

                    //show collision message
                    readimagefile("gamedata/b/wrecked1.jpg",350-2,20-2,900+2,500+2);
                    getch();
                    ArcadeScore(score);
                    return ;
                }
            }
        }
        // Changing Food Position
        if(touched(_C(FooDx,FooDy,FooDr),_C(ballx,bally,ballr)))
        {
            //Ball Eaten Animation
            BallEaten(FooDx,FooDy,FooDr);
            // selecting random position for food
            FooDx = topx + (rand()%(downx-topx-FooDr));
            FooDy = topy + (rand()%(downy-topy-FooDr));
            //increasing score , Size , ballr
            score++;
            Size++;
            ballr++;
            FooDr;
            PixelEr = Size/10;
            // if size being big ,so control it
            if(Size>100) Size = 100;
            if(ballr>100/2) ballr = 100/2;

            //printing score on board
            PrintScore(score);
        }
        // if food position out of GameZone then marge in
        MargeinRect(GameZone,FooDx,FooDy,FooDr,FooDr);
        //print food

        PrintRaida(FooDx,FooDy,FooDr);

        // changing mouse coordinate according to mouse movement
        ballx=( ballx + mousex()) / 2;
        bally=( bally + mousey()) / 2;
        // stop counting time
        //show on board
        //if time greater than 30 show time up message
        //if 30 ball eaten then level finish
    }
}

int LevelTwo()
{
    //initial obstacle position
    int dx[] = { 370, 800, 500, 600, 700, 440, 400, 550, 700, 800 };
    int dy[] = { 100, 200, 300, 400, 70 , 450, 300, 250, 300, 450};

    //initial obstacle direction
    int dirx[]= { 2,  2, -2, -2, -1,  -2,  1, -1,  1,  -1};
    int diry[]= {-2,  2,  2, -2,  2,  1, -1, -1,  1,  1};

    int obstacle = 4   ;
    int score    = 0   ;
    int Delay    = 10  ;
    int Size     = 50  ;

    //GameZone Region
    int topx     = 350 ;
    int topy     = 20  ;
    int downx    = 900 ;
    int downy    = 500 ;


    // making REct for Game zone
    struct  Rect  GameZone = _R(topx-2, topy-2, downx+2, downy+2);

    // setting mouse position all zero
    ClearLast();

    // setting up background
    readimagefile("gamedata/b/l2gb.jpg", 0, 0, getmaxx(), getmaxy());
    FillRect(GameZone, WHITE, SOLID_FILL);


    // initialize mouse position
    int ballx    =	(topx+downx)/2;
    int bally    =	(topy+downy)/2;
    int ballr = 10 ;

    // for scoring purpose and showing Remaining time
    time_t start , End;
    double TotalTime=0;

    //initial food position
    int FooDx = 500;
    int FooDy = 300;
    int FooDr = 20 ;
    // scoreboard
    readimagefile("gamedata/b/black.jpg",0,0,200,100);
    PrintScore(score);
    ShowTime(TotalTime);
    ShowPlayerName(NewPlayer.name);

    WaitForConfirmation();
    while(1)
    {
        // Space bar pause continue
        if(kbhit())
        {
            char c;
            while(kbhit()) c = getch();
            if(c==' ')
            {
                while(1)
                {
                    c = getch();
                    if(c==' ') break;
                }
            }
        }

        // started counting time
        time(&start);

        //clearing last mouse trail ball
        if(Last[0].x)
        {
            setcolor(WHITE);
            setfillstyle(SOLID_FILL,WHITE);
            fillellipse(Last[0].x, Last[0].y, ballr, ballr);
        }

        // Checking if Ball out of GameZone if then marge in
        MargeinRect(GameZone,ballx,bally,ballr,ballr);

        // Printing Ball
        setcolor(BLUE);
        setfillstyle(SOLID_FILL, BLUE);
        fillellipse(ballx, bally, ballr, ballr);

        // Push Position of Ball on List
        PushLast(_P(ballx, bally));

        setcolor(WHITE);

        // Changing direction And position of obstacle
        for(int i =0 ; i < obstacle ; i++)
        {
            // changing direction if out of range
            if(dx[i] + dirx[i] < topx)              dirx[i] = - dirx[i];
            if(dx[i] + dirx[i] > downx - Size)      dirx[i] = - dirx[i];
            if(dy[i] + diry[i] < topy)              diry[i] = - diry[i];
            if(dy[i] + diry[i] > downy - Size)      diry[i] = - diry[i];
            // Changing Position
            dx[i] += dirx[i] ;
            dy[i] += diry[i];
        }
        // Print Obstacle , Detect Collision
        for(int i=0 ; i < obstacle ; i++)
        {

            BoxFaceSmile(dx[i], dy[i],Size, COLORS[i%8]);
            // Detect Collision With obstacle
            if(inRange(_R(dx[i]+PixelEr, dy[i]+PixelEr, dx[i]+Size-PixelEr, dy[i]+Size-PixelEr), _C(ballx, bally, ballr-PixelEr), 1))
            {
                //after collision print sad face
                BoxFaceSad(dx[i], dy[i],Size, COLORS[i%8]);
                //make ball red
                setcolor(LIGHTRED);
                setfillstyle(SOLID_FILL, LIGHTRED);
                fillellipse(ballx, bally, ballr, ballr);
                // wait 2 seconds And see Face Eaten Animation
                delay(1000);
                //show collision message
                CollisionMsg(2);
                return 0;
            }
        }
        // Changing Food Position
        if(touched(_C(FooDx,FooDy,FooDr),_C(ballx,bally,ballr)))
        {
            //Ball Eaten Animation
            BallEaten(FooDx,FooDy,FooDr);
            // selecting random position for food
            FooDx = topx + (rand()%(downx-topx-FooDr));
            FooDy = topy + (rand()%(downy-topy-FooDr));
            //increasing score , Size , ballr
            score++;
            Size++;
            ballr++;
            FooDr;
            PixelEr = Size/10;

            // if size being big ,so control it
            if(Size>100) Size = 100;
            if(ballr>100/2) ballr = 100/2;

            //printing score on board
            PrintScore(score);
        }
        // if food position out of GameZone then marge in
        MargeinRect(GameZone,FooDx,FooDy,FooDr,FooDr);
        //print food

        PrintRaida(FooDx,FooDy,FooDr);



        // changing mouse coordinate according to mouse movement
        ballx=( ballx + mousex()) / 2;
        bally=( bally + mousey()) / 2;
        // stop counting time
        time(&End);
        TotalTime+=difftime(End,start);

        //show on board
        ShowTime(TotalTime);
        //if time greater than 30 show time up message
        if(TotalTime>=30)
        {
            TimeUpMsg();
            return 0;
        }

        //if 30 ball eaten then level finish
        if(score==20)
        {
            return TotalTime;
        }
    }
}


int LevelOne()
{
    // obstacle initial position
    int dx[] =	{ 380, 800, 500, 600, 700, 440, 400, 550, 700, 800};
    int dy[] =	{ 100, 200, 300, 400, 70 , 450, 300, 250, 300, 450};
    // obstacle direction changing
    int dirx[]= { 1,  1, -1, -1, -1,  -1,  1, -1,  1,  -1};
    int diry[]= {-1,  1,  1, -1,  1,  1, -1, -1,  1,  1};

    // number of obstacle and their size
    int obstacle =	4 ;
    int Size     =	20 ;

    // GameZone Region
    int topx     =	350;
    int topy     =	20 ;
    int downx    =	900;
    int downy    =	500;



    //Make game zone Rectangle
    struct  Rect  GameZone = _R(topx-2, topy-2, downx+2, downy+2);

    //clearing last mouse position which is needed for making trail
    ClearLast();
    // setting up background
    readimagefile("gamedata/b/l1gb.jpg", 0, 0, getmaxx(), getmaxy());
    FillRect(GameZone, WHITE, SOLID_FILL);

    // mouse ball position and size
    int ballx    =	(topx+downx)/2;
    int bally    =	(topy+downy)/2;
    int ballr = 10;

    // initialize Food position and size
    int FooDx = 500;
    int FooDy = 300;
    int FooDr = 20 ;
    int score = 0 ;

    // for scoring  purpose and showing remaining time
    time_t start , End;
    double TotalTime=0;
    // Printing Score & Time
    readimagefile("gamedata/b/black.jpg",0,0,200,100);
    PrintScore(score);
    ShowTime(TotalTime);
    ShowPlayerName(NewPlayer.name);

    WaitForConfirmation();
    // moving obstacle
    while(1)
    {
        // Space bar pause continue
        if(kbhit())
        {
            char c;
            while(kbhit()) c = getch();
            if(c==' ')
            {
                while(1)
                {
                    c = getch();
                    if(c==' ') break;
                }
            }
        }

        // start counting time
        time(&start);

        //clearing previous mouse position
        if(Last[0].x)
        {
            setcolor(WHITE);
            setfillstyle(SOLID_FILL,WHITE);
            fillellipse(Last[0].x, Last[0].y, ballr, ballr);
        }

        // Checking if Ball out of GameZone if yes then marge in
        MargeinRect(GameZone,ballx,bally,ballr,ballr);
        // Printing Ball mouse trail
        setcolor(BLUE);
        setfillstyle(SOLID_FILL, BLUE);
        fillellipse(ballx, bally, ballr, ballr);
        // Push Position of Ball on List
        PushLast(_P(ballx, bally));


        setcolor(WHITE);

        // Changing direction And position of obstacle
        for(int i =0 ; i < obstacle ; i++)
        {
            // changing direction if out of range
            if(dx[i] + dirx[i] < topx+Size)              dirx[i] = - dirx[i];
            if(dx[i] + dirx[i] > downx-Size)      dirx[i] = - dirx[i];
            if(dy[i] + diry[i] < topy+Size)              diry[i] = - diry[i];
            if(dy[i] + diry[i] > downy - Size)      diry[i] = - diry[i];
            // Changing Position
            dx[i] += dirx[i] ;
            dy[i] += diry[i];
        }
        // Print Obstacle , Detect Collision
        for(int i=0 ; i < obstacle ; i++)
        {
            CircleFaceSmile(dx[i], dy[i],Size, COLORS[i%8]);
            // Detect Collision With obstacle
            if(touched(_C(dx[i], dy[i],Size), _C(ballx, bally, ballr)))
            {
                //after collision print sad face
                CircleFaceSad(dx[i], dy[i],Size, COLORS[i%8]);
                //make ball red
                setcolor(LIGHTRED);
                setfillstyle(SOLID_FILL, LIGHTRED);
                fillellipse(ballx, bally, ballr, ballr);
                // wait 2 seconds And see Face Eaten Animation
                delay(1000);
                //show collision message
                CollisionMsg(1);
                return 0;
            }
        }
        // Changing Food Position
        if(touched(_C(FooDx,FooDy,FooDr),_C(ballx,bally,ballr)))
        {
            //Ball Eaten Animation
            BallEaten(FooDx,FooDy,FooDr);
            // selecting random position for food
            FooDx = topx + (rand()%(downx-topx-FooDr));
            FooDy = topy + (rand()%(downy-topy-FooDr));
            //increasing score , Size , ballr
            score++;
            Size++;
            ballr++;
            FooDr;
            PixelEr = Size/10;

            // if size being really large then control it
            if(Size>100)
            {
                Size = 100;
            }
            if(ballr>100/2)
            {
                ballr = 100/2;
            }

            //printing score on board
            PrintScore(score);
        }
        // if food position  out of GameZone then marge in
        MargeinRect(GameZone,FooDx,FooDy,FooDr,FooDr);
        //print food
        PrintRaida(FooDx,FooDy,FooDr);

        // changing Ball Coordinate according to mouse movement
        ballx=( ballx + mousex()) / 2;
        bally=( bally + mousey()) / 2;

        //stop counting time
        time(&End);
        TotalTime+=difftime(End,start);

        // show time on score board
        ShowTime(TotalTime);

        //time time greater than 30 , then game end
        if(TotalTime>=30)
        {
            TimeUpMsg();
            return 0;
        }

        // if score greater than 30 then level over
        if(score==10)
        {
            //HighScore(TotalTime);
            return TotalTime;
        }
    }
}


int LevelBoss()
{

    //initial obstacle position
    int dx[] =	{ 380, 800, 500, 600, 700, 440, 400, 550, 700, 800};
    int dy[] =	{ 100, 200, 300, 400, 70 , 450, 300, 250, 300, 450};
    //initial obstacle direction
    int dirx[]= { 1,  1, -1, -1, -1,  -1,  1, -1,  1,  -1};
    int diry[]= {-1,  1,  1, -1,  1,  1, -1, -1,  1,  1};


    int obstacle = 6   ;
    int score    = 0   ;
    int life     = 5   ;
    int Delay    = 10  ;
    int Size     = 50  ;
    //GameZone Region
    int topx     = 350 ;
    int topy     = 20  ;
    int downx    = 900 ;
    int downy    = 500 ;

    // making REct for Game zone
    struct  Rect  GameZone = _R(topx-2, topy-2, downx+2, downy+2);

    // setting mouse position all zero
    ClearLast();

    // setting up background
    readimagefile("gamedata/b/l2gb.jpg", 0, 0, getmaxx(), getmaxy());
    FillRect(GameZone, WHITE, SOLID_FILL);

    // initialize mouse position
    int ballx    =	(topx+downx)/2;
    int bally    =	(topy+downy)/2;
    int ballr = 10;

    // for scoring purpose and showing Remaining time
    time_t start , End;
    double TotalTime=0;

    //initial food position
    int FooDx = 500;
    int FooDy = 300;
    int FooDr = 20 ;
    int Life = 3 ;

    // scoreboard
    readimagefile("gamedata/b/black.jpg",0,0,200,100);
    PrintScore(score);
    ShowTime(TotalTime);
    ShowPlayerName(NewPlayer.name);


    WaitForConfirmation();
    while(1)
    {
        // Space bar pause continue
        if(kbhit())
        {
            char c;
            while(kbhit()) c = getch();
            if(c==' ')
            {
                while(1)
                {
                    c = getch();
                    if(c==' ') break;
                }
            }
        }

        // started counting time
        time(&start);
        //clearing last mouse trail ball
        if(Last[0].x)
        {
            setcolor(WHITE);
            setfillstyle(SOLID_FILL,WHITE);
            fillellipse(Last[0].x, Last[0].y, ballr, ballr);
        }

        // Checking if Ball out of GameZone
        MargeinRect(GameZone,ballx,bally,ballr,ballr);
        // Printing Ball
        setcolor(BLUE);
        setfillstyle(SOLID_FILL, BLUE);
        fillellipse(ballx, bally, ballr, ballr);
        // Push Position of Ball on List
        PushLast(_P(ballx, bally));


        setcolor(WHITE);

        // Changing direction And position of obstacle
        for(int i =0 ; i < obstacle ; i++)
        {
            // changing direction if out of range
            if(i%2)
            {
                if(dx[i] + dirx[i] < topx)              dirx[i] = - dirx[i];
                if(dx[i] + dirx[i] > downx - Size)      dirx[i] = - dirx[i];
                if(dy[i] + diry[i] < topy)              diry[i] = - diry[i];
                if(dy[i] + diry[i] > downy - Size)      diry[i] = - diry[i];
            }
            else
            {
                if(dx[i] + dirx[i] < topx+Size/2)              dirx[i] = - dirx[i];
                if(dx[i] + dirx[i] > downx-Size/2)      dirx[i] = - dirx[i];
                if(dy[i] + diry[i] < topy+Size/2)              diry[i] = - diry[i];
                if(dy[i] + diry[i] > downy - Size/2)      diry[i] = - diry[i];
            }
            // Changing Position
            dx[i] += dirx[i] ;
            dy[i] += diry[i];
        }
        // Print Obstacle , Detect Collision
        for(int i=0 ; i < obstacle ; i++)
        {

            if(i%2)
            {
                BoxFaceSmile(dx[i], dy[i],Size, COLORS[i%8]);

                // Detect Collision With obstacle
                if(inRange(_R(dx[i]+PixelEr, dy[i]+PixelEr, dx[i]+Size-PixelEr, dy[i]+Size-PixelEr), _C(ballx, bally, ballr-PixelEr), 1))
                {
                    //after collision print sad face
                    BoxFaceSad(dx[i], dy[i],Size, COLORS[i%8]);
                    //make ball red
                    setcolor(LIGHTRED);
                    setfillstyle(SOLID_FILL, LIGHTRED);
                    fillellipse(ballx, bally, ballr, ballr);
                    // wait 2 seconds And se Face Eaten Animation
                    delay(1000);

                    //show collision message
                    CollisionMsg(2);
                    return 0;

                }
            }
            else
            {
                CircleFaceSmile(dx[i], dy[i],Size/2, COLORS[i%8]);
                if(touched(_C(dx[i], dy[i],Size/2), _C(ballx, bally, ballr)))
                {
                    //after collision print sad face
                    CircleFaceSad(dx[i], dy[i],Size/2, COLORS[i%8]);
                    //make ball red
                    setcolor(LIGHTRED);
                    setfillstyle(SOLID_FILL, LIGHTRED);
                    fillellipse(ballx, bally, ballr, ballr);
                    // wait 2 seconds And se Face Eaten Animation
                    delay(1000);
                    //show collision message
                    CollisionMsg(1);
                    return 0;
                }
            }
        }
        // Changing Food Position
        if(touched(_C(FooDx,FooDy,FooDr),_C(ballx,bally,ballr)))
        {
            //Ball Eaten Animation
            BallEaten(FooDx,FooDy,FooDr);
            // selecting random position for food
            FooDx = topx + (rand()%(downx-topx-FooDr));
            FooDy = topy + (rand()%(downy-topy-FooDr));
            //increasing score , Size , ballr
            score++;
            Size++;
            ballr++;
            FooDr;
            PixelEr = Size/10;
            // if size being big ,so control it
            if(Size>100) Size = 100;
            if(ballr>100/2) ballr = 100/2;

            //printing score on board
            PrintScore(score);
        }
        // if food position out of GameZone then marge in
        MargeinRect(GameZone,FooDx,FooDy,FooDr,FooDr);
        //print food

        PrintRaida(FooDx,FooDy,FooDr);

        // changing mouse coordinate according to mouse movement
        ballx=( ballx + mousex()) / 2;
        bally=( bally + mousey()) / 2;
        // stop counting time
        time(&End);
        TotalTime+=difftime(End,start);
        //show on board
        ShowTime((int)TotalTime);
        //if time greater than 30 show time up message
        if(TotalTime>=30)
        {
            TimeUpMsg();
            return 0;
        }
        //if 30 ball eaten then level finish
        if(score==30)
        {
            return TotalTime;
        }
    }
}

void ShowMenu()
{
    readimagefile("gamedata/b/mbk.jpg",0,0,1000,600);
    while(1)
    {
        // START Zone
        if(inRange(_R(552,48,800,150),_P(mousex(),mousey())))
        {

            readimagefile("gamedata/b/bkstart.jpg",0,0,1000,600);
            while(inRange(_R(552,48,800,150),_P(mousex(),mousey())))
            {
                if(ismouseclick(WM_LBUTTONDOWN))
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    GameMode();
                   // readimagefile("gamedata/b/bkstart.jpg",0,0,1000,600);
                    readimagefile("gamedata/b/mbk.jpg",0,0,1000,600);
                    break;
;
                }
            }

        }

        // option Zone
        if(inRange(_R(552,160,840,265),_P(mousex(),mousey())))
        {

            readimagefile("gamedata/b/mboption.jpg",0,0,1000,600);
            while(inRange(_R(552,160,840,265),_P(mousex(),mousey())))
            {
                if(ismouseclick(WM_LBUTTONDOWN))
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    Credits();
                    readimagefile("gamedata/b/mbk.jpg",0,0,1000,600);
                    break;
                    //readimagefile("gamedata/b/mboption.jpg",0,0,1000,600);
                }
            }
        }
        // High Score Zone
        if(inRange(_R(552,266,980,367),_P(mousex(),mousey())))
        {

            readimagefile("gamedata/b/mbhighscore.jpg",0,0,1000,600);
            while(inRange(_R(552,266,980,367),_P(mousex(),mousey())))
            {
                if(ismouseclick(WM_LBUTTONDOWN))
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    HS();
                    readimagefile("gamedata/b/mbk.jpg",0,0,1000,600);

                    break;
                    //readimagefile("gamedata/b/mboption.jpg",0,0,1000,600);
                }
            }
        }
        // exit zone
        if(inRange(_R(560,384,754,487),_P(mousex(),mousey())))
        {
            readimagefile("gamedata/b/mbexit.jpg",0,0,1000,600);
            while(inRange(_R(560,384,754,487),_P(mousex(),mousey())))
            {
                if(ismouseclick(WM_LBUTTONDOWN)) exit(0);
            }
        }

    }
}


bool touched(struct  Rect  a, struct  Cir  b)
{
    return inRange(a, b, 1);
}


bool inRange(struct  Rect  a, struct Point b)
{
    if(a.topx > b.x)  return false;
    if(a.topy > b.y)  return false;
    if(a.downx < b.x) return false;
    if(a.downy < b.y) return false;
    return true;

}


bool inRange(struct  Cir  a, struct  Point b)
{
    struct Point center = _P(a.x, a.y);
    if(Distance(center , b) > a.r) return false;
    return true;
}


bool inRange(struct  Rect  a, struct   Rect  b)
{
    struct Point p = _P(b.topx, b.topy);
    struct Point q = _P(b.downx, b.downy);

    if(inRange(a , p) && inRange(a , q)) return true;
    else return false;
}


bool inRange(struct  Rect  a, struct  Cir  b, int type)
{
    if(type%3==0)  // [0]
    {
        struct Point p = _P(b.x , b.y);
        struct  Rect  q = _R(a.topx + b.r, a.topy + b.r, a.downx - b.r, a.downy - b.r);

        if(inRange(q , p))      return true;
        return false;
    }
    if(type%3==1) // 0[]
    {
        struct Point p = _P(b.x , b.y);
        struct  Rect  q = _R (a.topx - b.r, a.topy - b.r, a.downx + b.r, a.downy + b.r);
        if(inRange(q , p))      return true;
        return false;

    }
    if(type%3==2)
    {
        struct Point p = _P(b.x , b.y);
        if(inRange(a,p))        return true;
        return false;
    }
    return true;

}


struct  Cir  _C(int x , int y , int r)
{
    struct  Cir  a ;
    a.r = r;
    a.x = x;
    a.y = y;
    return a ;
}


struct  Rect  _R (int x1 , int y1 , int x2 ,int y2)
{
    struct  Rect  a ;
    a.topx = x1 ;
    a.topy = y1 ;
    a.downx = x2;
    a.downy = y2;
    return a;
}


struct Point _P(int x , int y)
{
    struct Point a ;
    a.x = x;
    a.y = y;
    return a;
}


double Distance(struct Point a , struct  Point b)
{
    double x1 = abs(a.x - b.x);
    double y1 = abs(a.y - b.y);
    return (double)sqrt(x1*x1 + y1*y1);
}


void FillRect(struct  Rect  a , int colr , int fillpet)
{
    int points[] = {a.topx , a.topy ,
                    a.topx , a.downy ,
                    a.downx , a.downy ,
                    a.downx , a.topy ,
                    a.topx , a.topy
                   } ;

    setfillstyle(fillpet , colr);
    fillpoly(5 , points);
}


void PushLast(struct Point a)
{
    for(int i = 0 ; i < 20-1 ; i++)
        Last[i] = Last[i+1];
    Last[20-1] = a;
}


void ClearLast(void)
{
    for(int i = 0 ; i < 30 ; i++)
        Last[i].x = Last[i].y = 0;
}


bool touched(struct  Cir  a ,struct  Cir  b)
{
    if(Distance(_P(a.x,a.y),_P(b.x,b.y))<=(double)(a.r+b.r)) return true;
    return false;
}


void MargeinRect(Rect a , int &x , int &y ,int topin , int downin)
{
    if(x<=a.topx+topin) x = a.topx + topin;
    if(y<=a.topy+topin) y = a.topy + topin;
    if(x>=a.downx-downin) x = a.downx - downin;
    if(y>=a.downy-downin) y = a.downy - downin;
}


int  ScoreStore()
{

    FILE *fp1 , *fp2;
    fp1 = fopen("gamedata/txt/score.txt","r");
    struct person P[6];
    struct person TEMP;

    //reading  score from file
    for(int i=0; i<5; i++)
    {
        fscanf(fp1,"%s",P[i].name);
        fscanf(fp1,"%d",&P[i].lvl1);
        fscanf(fp1,"%d",&P[i].lvl2);
        fscanf(fp1,"%d",&P[i].lvl3);
        //cout<<P[i].name<<endl;
    }
    P[5]  = NewPlayer ;
    //sorting score
    for(int i=5; i>=0; i--)
    {
        if(P[i-1].lvl1+P[i-1].lvl2+P[i-1].lvl3>P[i].lvl1+P[i].lvl2+P[i].lvl3)
        {
            TEMP =  P[i-1];
            P[i-1] = P[i];
            P[i] = TEMP;
        }
    }

    fclose(fp1);
    fp2 = fopen("gamedata/txt/score.txt","w");
    // saving score to file again
    for(int i=0; i<5; i++)
    {
        fprintf(fp2,"%s ",P[i].name);
        fprintf(fp2," %d",P[i].lvl1);
        fprintf(fp2," %d",P[i].lvl2);
        fprintf(fp2," %d\n",P[i].lvl3);
    }
    fclose(fp2);
    for(int i =0 ; i < 6 ; i++)
    {
        if(P[i].lvl1+P[i].lvl2+P[i].lvl3==NewPlayer.lvl1+NewPlayer.lvl2+NewPlayer.lvl3) return i;
    }
}


void GameMode()
{
    readimagefile("gamedata/b/arcade.jpg",0,0,1000,600);

    while(kbhit()) getch();
    while(1)
    {

        if(kbhit())
        {
            while(kbhit()) getch();
            return ;
        }
        // mouse CP on Arcade mode
        if(mousex()>=663 && mousey()>=78 && mousex()<=1000 && mousey()<=140)
        {
            readimagefile("gamedata/b/arcade.jpg",0,0,1000,600);
            while(mousex()>=663 && mousey()>=78 && mousex()<=1000 && mousey()<=140)
            {
                if(kbhit())
                {
                    while(kbhit()) getch();
                    return ;
                }
                if(ismouseclick(WM_LBUTTONDOWN))
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    ArcadeMode();
                    while(kbhit()) getch();
                    return ;
                }
            }
        }
        // mouse CP on challenge mode
        else if(mousex()>=659 && mousey()>=143 && mousex()<=1000 && mousey()<=200)
        {
            readimagefile("gamedata/b/challenge.jpg",0,0,1000,600);
            while(mousex()>=659 && mousey()>=143 && mousex()<=1000 && mousey()<=200)
            {
                if(kbhit())
                {
                    while(kbhit()) getch();
                    return ;
                }
                if(ismouseclick(WM_LBUTTONDOWN))
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    RunGame();
                    if(kbhit()) while(kbhit()) getch();
                    return ;
                }
            }
        }
        else {
            clearmouseclick(WM_LBUTTONDOWN);
        }

    }
}


void GetUserName()
{
    if(kbhit()) while(kbhit()) getch();
    //cleardevice();
    readimagefile("gamedata/b/username.jpg",0,0,1000,600);
    int x = 410 ;
    char name[15]= {0};
    int i=0;
    while(1)
    {
        if(kbhit())
        {
            char ch = getch();
            while(kbhit()) getch();
            if(ch==13)
            {
                strcpy(NewPlayer.name,name);
                return ;
            }
            if(ch==8)
            {
                i--;
                if(i<0) i=0;
                name[i]=0;
                x-=50;
            }
            if((ch>='a' && ch<='z'))
            {
                name[i++]=ch-32;
                if(i>10) i=10;
                name[i]=0;
            }
            if((ch>='A' && ch<='Z'))
            {
                name[i++]=ch;
                if(i>10) i=10;
                name[i]=0;
            }
            readimagefile("gamedata/b/black.jpg",349,222,925,330);
            settextstyle(TRIPLEX_FONT, HORIZ_DIR, 5);
            bgiout<<name<<endl;
            outstreamxy(400,250);
        }
    }
}

void ArcadeScore(int score)
{

    FILE *fp1, *fp2;
    fp1 = fopen("gamedata/txt/ascore.txt","r");
    struct person P[6] , temp;
    for(int i=0; i<5 ; i++)
    {
        fscanf(fp1,"%s",P[i].name);
        fscanf(fp1,"%d",&P[i].lvl1);
    }

    strcpy(P[5].name,NewPlayer.name);
    P[5].lvl1 = score ;

    for(int i = 5 ; i >=1 ; i--)
    {
        if(P[i-1].lvl1<P[i].lvl1)
        {
            temp = P[i-1];
            P[i-1] = P[i];
            P[i] = temp;
        }
    }

    fclose(fp1);

    fp2 = fopen("gamedata/txt/ascore.txt","w");
    for(int i=0; i<6; i++)
    {
        fprintf(fp2,"%s ",P[i].name);
        fprintf(fp2,"%d\n",P[i].lvl1);
    }

    fclose(fp2);
    if(score==P[5].lvl1) YouAreAwesome(10);
    else YouAreAwesome(0);
}
void HS()
{
    //if(kbhit()) while(kbhit()) getch();
    while(1)
    {
        if(mousex()>500)
        {
            readimagefile("gamedata/b/chigh.jpg",0,0,1000,600);
            while(mousex()>500)
            {

                if(ismouseclick(WM_LBUTTONDOWN))
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    Standing1();
                    return ;
                }

            }
        }
        else
        {
            readimagefile("gamedata/b/ahigh.jpg",0,0,1000,600);
            while(mousex()<500)
            {
                if(ismouseclick(WM_LBUTTONDOWN))
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    Standing2();
                    return ;
                }

            }

        }

    }
}

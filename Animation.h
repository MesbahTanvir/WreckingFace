
void WaitForConfirmation()
{
    // setcolor(RED);
    //circle(625,260,50);

    int StartAngle = 0 ;
    while(1)
    {
        setcolor(WHITE);
        int x = mousex();
        int y = mousey();
        if(sqrt(abs(x-625)*abs(x-625) + abs(y-260)*abs(y-260))<=50)
        {
            // setcolor(RED);
            // circle(625,260,50);
            //setcolor(GameBk);
            for(int i=10; i<=360; i+=10)
            {
                pieslice(625,260,0,i,60);
                delay(20);
            }
            break;
        }
        readimagefile("gamedata/b/starthere.jpg",625-50,260-50,625+50,260+50);
        pieslice(625,260,StartAngle,StartAngle+30,60);
        pieslice(625,260,StartAngle+60,StartAngle+90,60);
        pieslice(625,260,StartAngle+120,StartAngle+150,60);
        pieslice(625,260,StartAngle+180,StartAngle+210,60);
        pieslice(625,260,StartAngle+240,StartAngle+270,60);
        pieslice(625,260,StartAngle+300,StartAngle+330,60);
        delay(100);
        StartAngle+=30;
        setcolor(RED);
        //circle(625,260,50);
    }
    // setcolor(WHITE);
    // circle(625,260,50);
}
void BallEaten(int x , int y , int r)
{
    int StartAngle = 0;
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    for(int i=0; i<36; i++)
    {
        pieslice(x,y,StartAngle,StartAngle+10,r+1);
        StartAngle+=10;
        delay(10);
    }
}


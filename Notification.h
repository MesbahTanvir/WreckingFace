void CollisionMsg(int n)
{
    //printf("%d\n",n);
    if(n==1) readimagefile("gamedata/b/wrecked1.jpg",350-2,20-2,900+2,500+2);
    if(n==2) readimagefile("gamedata/b/wrecked.jpg",350-2,20-2,900+2,500+2);
    while(1)
    {
        if(kbhit())
        {
            while(kbhit()) getch();
            break;
        }
    }
    while(kbhit()) getch();
    readimagefile("gamedata/b/tryagain.jpg",0,0,1000,600);
    while(1)
    {
        if(kbhit())
        {
            while(kbhit()) getch();
            //cleardevice();
            return ;
        }
    }
}
void TimeUpMsg()
{
    readimagefile("gamedata/b/timeup.jpg",350-2,20-2,900+2,500+2);
    getch();
}
void LevelFinis(int n)
{

    int i=0;
    char dir[1000];
    sprintf(dir,"gamedata/b/com%dup.jpg",n);
    readimagefile(dir,0,0,1000,600);

    while(1)
    {
        if(kbhit())
        {
            while(kbhit()) getch();
            //cleardevice();
            return ;
        }
    }
}
void YouAreAwesome(int n)
{
    printf("%d\n",n);
    if(n<5) readimagefile("gamedata/b/onboard.jpg",0,0,1000,600);
    else readimagefile("gamedata/b/notonboard.jpg",0,0,1000,600);
    getch();

}
void Credits()
{
    readimagefile("gamedata/b/credits.jpg",0,0,1000,600);
    getch();
}



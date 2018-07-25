
void CircleFaceSmile(int x, int y ,int Size,int colr)
{
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    fillellipse(x,y,Size+2,Size+2);
    setcolor(colr);
    setfillstyle(SOLID_FILL,colr);
    fillellipse(x,y,Size,Size);
    setcolor(BLACK);
    circle(x-Size/2,y-Size/3,Size/3);
    circle(x+Size/2,y-Size/3,Size/3);
    arc(x,y,200,340,2*Size/3);
}
void CircleFaceSad(int x, int y ,int Size,int colr)
{
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    fillellipse(x,y,Size+2,Size+2);
    setcolor(colr);
    setfillstyle(SOLID_FILL,colr);
    fillellipse(x,y,Size,Size);
    setcolor(WHITE);
    circle(x-Size/2,y-Size/3,Size/3);
    circle(x+Size/2,y-Size/3,Size/3);
    arc(x,y+Size,30,150,2*Size/3);
}
void BoxFaceSad(int x, int y ,int Size,int colr)
{
    //first printing White Border
    setcolor(WHITE);
    rectangle(x,y,x+Size,y+Size);
    rectangle(x-1,y-1,x+Size+1,y+Size+1);
    //for a inner box
    x++;
    y++;
    Size-=2;
    int x1 = (x + Size/4);
    int x2 = (x + Size-(Size)/4);
    int y1 = (y + Size/4);
    //drawing face
    setcolor(colr);
    setfillstyle(SOLID_FILL,colr);
    int points[]= {x,y,x+Size,y,x+Size,y+Size,x,y+Size,x,y};
    fillpoly(5,points);
    setcolor(BLACK);
    //line(x,y+Size/2,x+Size,y+Size/2);
    //line (x+Size/2,y,x+Size/2,y+Size/2);
    circle(x1,y1,Size/4-2);
    circle(x2,y1,Size/4-2);
    line(x1,y1+Size/2,x2,y1+Size/2);
    line(x2,y1+Size/2,x2,y1+Size/2+Size/10);
    line(x1,y1+Size/2,x1,y1+Size/10+Size/2);
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    //fillellipse(x1,y1,Size/10,Size/10);
    //fillellipse(x2,y1,Size/10,Size/10);

}
void BoxFaceSmile(int x, int y ,int Size,int colr)
{
    //first printing White Border
    setcolor(WHITE);
    rectangle(x,y,x+Size,y+Size);
    rectangle(x-1,y-1,x+Size+1,y+Size+1);
    //for a inner box
    x++;
    y++;
    Size-=2;
    int x1 = (x + Size/4);
    int x2 = (x + Size-(Size)/4);
    int y1 = (y + Size/4);
    //drawing face
    setcolor(colr);
    setfillstyle(SOLID_FILL,colr);
    int points[]= {x,y,x+Size,y,x+Size,y+Size,x,y+Size,x,y};
    fillpoly(5,points);
    setcolor(BLACK);
    // line(x,y+Size/2,x+Size,y+Size/2);
    // line (x+Size/2,y,x+Size/2,y+Size/2);
    circle(x1,y1,Size/4-2);
    circle(x2,y1,Size/4-2);
    line(x1,y1+Size/2,x2,y1+Size/2);
    line(x2,y1+Size/2,x2,y1+Size/2-Size/10);
    line(x1,y1+Size/2,x1,y1-Size/10+Size/2);
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,WHITE);
}
void PrintRaida(int FooDx,int FooDy,int FooDr)
{
    setcolor(LIGHTMAGENTA);
    setfillstyle(SOLID_FILL,LIGHTMAGENTA);
    fillellipse(FooDx,FooDy,FooDr,FooDr);
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    fillellipse(FooDx-FooDr/2,FooDy-FooDr/3,FooDr/3,FooDr/3);
    fillellipse(FooDx+FooDr/2,FooDy-FooDr/3,FooDr/3,FooDr/3);
    fillellipse(FooDx,FooDy+FooDr/2,2*FooDr/5,2*FooDr/5);

}



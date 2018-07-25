void Standing1(void)
{
    while(kbhit()) getch();

    settextstyle(10,HORIZ_DIR,4);
    readimagefile("gamedata/b/highscore.jpg",0,0,1000,600);
    FILE *fp ;
    fp = fopen("gamedata/txt/score.txt","r");
    char pname[100];
    int lvl1 , lvl2 , lvl3;

    // 1st
    fscanf(fp,"%s",pname);
    fscanf(fp,"%d",&lvl1);
    fscanf(fp,"%d",&lvl2);
    fscanf(fp,"%d",&lvl3);

    bgiout<<pname;
    outstreamxy(160,55);
    bgiout<<lvl1;
    outstreamxy(510,55);
    bgiout<<lvl2;
    outstreamxy(610,55);
    bgiout<<lvl3;
    outstreamxy(710,55);

    // 2nd
    fscanf(fp,"%s",pname);
    fscanf(fp,"%d",&lvl1);
    fscanf(fp,"%d",&lvl2);
    fscanf(fp,"%d",&lvl3);

    bgiout<<pname;
    outstreamxy(160,115);
    bgiout<<lvl1 ;
    outstreamxy(510,115);
    bgiout<<lvl2 ;
    outstreamxy(610,115);
    bgiout<<lvl3 ;
    outstreamxy(710,115);

    // 3rd

    fscanf(fp,"%s",pname);
    fscanf(fp,"%d",&lvl1);
    fscanf(fp,"%d",&lvl2);
    fscanf(fp,"%d",&lvl3);

    bgiout<<pname ;
    outstreamxy(160,170);
    bgiout<<lvl1 ;
    outstreamxy(510,170);
    bgiout<<lvl2 ;
    outstreamxy(610,170);
    bgiout<<lvl3 ;
    outstreamxy(710,170);

    // 4th
    fscanf(fp,"%s",pname);
    fscanf(fp,"%d",&lvl1);
    fscanf(fp,"%d",&lvl2);
    fscanf(fp,"%d",&lvl3);

    bgiout<<pname ;
    outstreamxy(160,230);
    bgiout<<lvl1 ;
    outstreamxy(510,230);
    bgiout<<lvl2 ;
    outstreamxy(610,230);
    bgiout<<lvl3 ;
    outstreamxy(710,230);

    // 5th
    fscanf(fp,"%s",pname);
    fscanf(fp,"%d",&lvl1);
    fscanf(fp,"%d",&lvl2);
    fscanf(fp,"%d",&lvl3);

    bgiout<<pname ;
    outstreamxy(160,290);
    bgiout<<lvl1 ;
    outstreamxy(510,290);
    bgiout<<lvl2 ;
    outstreamxy(610,290);
    bgiout<<lvl3 ;
    outstreamxy(710,290);
    fclose(fp);
    while(!kbhit());
    while(kbhit()) getch();

}
void Standing2(void)
{
    while(kbhit()) getch();
    settextstyle(10,HORIZ_DIR,4);
    readimagefile("gamedata/b/ahighscore.jpg",0,0,1000,600);
    FILE *fp ;
    fp = fopen("gamedata/txt/ascore.txt","r");
    char pname[100];
    int score;

    // 1st
    fscanf(fp,"%s",pname);
    fscanf(fp,"%d",&score);

    bgiout<<pname;
    outstreamxy(160,55);
    bgiout<<score;
    outstreamxy(510,55);
    printf("%s %d\n",pname,score);


    // 2nd
    fscanf(fp,"%s",pname);
    fscanf(fp,"%d",&score);


    bgiout<<pname;
    outstreamxy(160,115);
    bgiout<<score ;
    outstreamxy(510,115);

    // 3rd

    fscanf(fp,"%s",pname);
    fscanf(fp,"%d",&score);


    bgiout<<pname ;
    outstreamxy(160,170);
    bgiout<<score ;
    outstreamxy(510,170);


    // 4th
    fscanf(fp,"%s",pname);
    fscanf(fp,"%d",&score);


    bgiout<<pname ;
    outstreamxy(160,230);
    bgiout<<score;
    outstreamxy(510,230);

    // 5th
    fscanf(fp,"%s",pname);
    fscanf(fp,"%d",&score);


    bgiout<<pname ;
    outstreamxy(160,290);
    bgiout<<score ;
    outstreamxy(510,290);
    fclose(fp);
    while(!kbhit());
    while(kbhit()) getch();
}


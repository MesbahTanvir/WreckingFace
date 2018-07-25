void PrintScore(int score)
{
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
    bgiout<<"SCORE   :"<<score;
    outstreamxy(0,30);
}
void ShowTime(int TotalTime)
{
    // im not kidding here
    /*
        i don't know why
        bgiout<<"TIME      :"<<30-TatalTime;
        not working .


        for this reason I write this long  stuff
    */
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
    if(30-TotalTime==00) bgiout<<"TIME      :00";
    else if(30-TotalTime==01) bgiout<<"TIME      :01";
    else if(30-TotalTime==02) bgiout<<"TIME      :02";
    else if(30-TotalTime==03) bgiout<<"TIME      :03";
    else if(30-TotalTime==04) bgiout<<"TIME      :04";
    else if(30-TotalTime==05) bgiout<<"TIME      :05";
    else if(30-TotalTime==06) bgiout<<"TIME      :06";
    else if(30-TotalTime==07) bgiout<<"TIME      :07";
    else if(30-TotalTime==8) bgiout<<"TIME      :08";
    else if(30-TotalTime==9) bgiout<<"TIME      :09";
    else if(30-TotalTime==10) bgiout<<"TIME      :10";
    else if(30-TotalTime==11) bgiout<<"TIME      :11";
    else if(30-TotalTime==12) bgiout<<"TIME      :12";
    else if(30-TotalTime==13) bgiout<<"TIME      :13";
    else if(30-TotalTime==14) bgiout<<"TIME      :14";
    else if(30-TotalTime==15) bgiout<<"TIME      :15";
    else if(30-TotalTime==16) bgiout<<"TIME      :16";
    else if(30-TotalTime==17) bgiout<<"TIME      :17";
    else if(30-TotalTime==18) bgiout<<"TIME      :18";
    else if(30-TotalTime==19) bgiout<<"TIME      :19";
    else if(30-TotalTime==20) bgiout<<"TIME      :20";
    else if(30-TotalTime==21) bgiout<<"TIME      :21";
    else if(30-TotalTime==22) bgiout<<"TIME      :22";
    else if(30-TotalTime==23) bgiout<<"TIME      :23";
    else if(30-TotalTime==24) bgiout<<"TIME      :24";
    else if(30-TotalTime==25) bgiout<<"TIME      :25";
    else if(30-TotalTime==26) bgiout<<"TIME      :26";
    else if(30-TotalTime==27) bgiout<<"TIME      :27";
    else if(30-TotalTime==28) bgiout<<"TIME      :28";
    else if(30-TotalTime==29) bgiout<<"TIME      :29";
    else if(30-TotalTime==30) bgiout<<"TIME      :30";


    outstreamxy(0,60);

}
void ShowPlayerName(char name[])
{
    settextstyle(0, HORIZ_DIR, 2);
    bgiout<<name;
    outstreamxy(5,5);
}


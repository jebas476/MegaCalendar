/*Program to display the monthly and year calender from 1 A.D-1,00,000 A.D*/






#include<stdio.h>


#include<iostream.h>


#include<conio.h>


#include<string.h>


#include<process.h>


#include<graphics.h>


#include<dos.h>






int select_page();


void mon_select();


int mon_tdays(long int y,int m);


unsigned long int days_calc(long int y,int m);


int key(long int,int,unsigned long int);


char* mon_name(int);


void start_graphics();


void month_calender(int days,int k,long int y,int m);


void month_table(int r,int c);


void year_calender(long int y);


void get_monthcal(int k,int days,int r,int c,int dc,int m);


void year_table(int r,int c,int m);


void iloop_terminator();


void first_page();






/*Main Function*/


void main()


{


        int m,dis_keynum,choice;


        long int y;


        clrscr();


        first_page();


        choice=select_page();


        switch(choice)


        {


                case 1:


                        getyear:


                        iloop_terminator();


                        cout<<"\nEnter the year:";


                        cin>>y;


                        if(!(y==1||y<=100000))


                        {


                                textcolor(14);


                                cprintf("\r\nDear User !Please enter the valid year...");


                                goto getyear;


                        }


                        mon_select();


                        getmonth:


                        iloop_terminator();


                        cout<<"\nEnter the month:";


                        cin>>m;


                        if(!(m==1||m<=12))


                        {


                                textcolor(14);


                                cprintf("\r\nDear User !Please enter the valid month...");


                                goto getmonth;


                        }


                        if(y==1752&&m==9)


                        {


                                textcolor(14);


                                cprintf("\r\nDear User..Can't display the calender of this month!\n\n(September of 1752B.C is a special month in  which historically the \nJulian calender changed to Gregorian calender and contains only 19 days..)");


                                getch();


                                exit(0);


                        }


                        dis_keynum=key(y,m,days_calc(y,m));


                        month_calender(mon_tdays(y,m),dis_keynum,y,m);


                        break;


                case 2:


                        do


                        {


                                iloop_terminator();


                                cout<<"\nEnter the year:";


                                cin>>y;


                                if(!(y==1||y<=100000))


                                {


                                        textcolor(14);


                                        cprintf("\r\nDear User !Please enter the valid year...");


                                }


                                year_calender(y);


                        }while(!(y==1||y<=100000));


                        break;


                default:


                        exit(1);


        }


        getch();


}






int select_page()


{


        int y,choice;


        clrscr();


        textmode(-1);


        y=getmaxy()-10;


        textcolor(10);


        cprintf("\r\n\nSelect any one of the options:-");


        textcolor(9);


        cprintf("\r\n\n\n1.Monthly Calender");


        cprintf("\r\n\n2.Year Calender");


        cprintf("\r\n\n3.Exit");


        getchoice:


        iloop_terminator();


        textcolor(10);


        cprintf("\r\n\nEnter your choice:");


        cin>>choice;


        if(choice==1||choice==2||choice==3)


                return choice;


        else


        {


                y+=10;


                textcolor(14);


                cprintf("\n\nInvalid Choice!");


                goto getchoice;


        }


}










/* To display the months for selection */


void mon_select()


{


        textcolor(14);


        cprintf("\r\n\n1.January\r\n2.February\r\n3.March\r\n4.April\r\n5.May\r\n6.June");


        cprintf("\r\n7.July\r\n8.August\r\n9.September\r\n10.October\r\n11.November\r\n12.December");


}






/* To calculate the total days in the entered month */


int mon_tdays(long int year,int month)


{


                 int td;






                 if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)


                        td=31;


                else if(month==2)


                {


                        if(year%4==0)


                        {


                                if(year>1752)


                                {


                                        if(year%400==0)


                                                td=29;


                                        else if(year%100==0)


                                                td=28;


                                        else


                                                td=29;


                                }


                                else


                                                 td=29;


                        }


                        else


                                td=28;


                }


                else


                        td=30;


        return(td);


}










/* Function to calculate the total days in between */


unsigned long int days_calc(long int year,int month)


{


        int j;


        long int i;


        unsigned long int days=0;


        for(i=1;i<year;i++)


        {


                if(i%4==0)


                {


                        if(i>1752)


                        {


                                if(i%400==0)


                                        days=days+366;


                                else if(i%100==0)


                                        days=days+365;


                                else


                                        days=days+366;


                        }


                        else


                                days=days+366;


                }


                else


                        days=days+365;


        }


        for(j=1;j<month;j++)


        {


                if(j==1||j==3||j==5||j==7||j==8||j==10||j==12)


                        days=days+31;


                else if(j==2)


                {


                        if(year%4==0)


                        {


                                if(year>1752)


                                {


                                        if(year%400==0)


                                                days=days+29;


                                        else if(year%100==0)


                                                days=days+28;


                                        else


                                                days=days+29;


                                }


                                else


                                        days=days+29;


                        }


                        else


                                days=days+28;


                }


                else


                        days=days+30;


        }


        return(days);


}






/* Function to calculate the key value for display */


int key(long int year,int month,unsigned long int days)


{


        int r;






        r=(days)%7;


        if(r==0)


                r=r+7;


        if(year>=1752||(year==1752&&month>9))


        {


                if(r<5)


                        r=r+3;


                else


                        r=r-4;


        }


        return r;


}






/* Function to return the name of the month */


char* mon_name(int m)


{


        char *a;


        if(m==1)


               strcpy(a,"January");


        if(m==2)


               strcpy(a,"February");


        if(m==3)


                strcpy(a,"March");


        if(m==4)


                strcpy(a,"April");


        if(m==5)


                strcpy(a,"May");


        if(m==6)


               strcpy(a,"June");


        if(m==7)


                strcpy(a,"July");


        if(m==8)


                strcpy(a,"August");


        if(m==9)


                strcpy(a,"September");


        if(m==10)


                strcpy(a,"October");


        if(m==11)


                strcpy(a,"November");


        if(m==12)


                strcpy(a,"December");


        return a;


}






/*Function to display the monthly calender */


void month_calender(int days,int k,long int y,int m)


{


        int i,j,ck,r=130,c=170,dc;


        char f[10];


        start_graphics();


        cout<<"\nEnter the display colour:";


        cin>>dc;


        cleardevice();


        setcolor(dc);


        settextstyle(3,0,2);


        outtextxy(69,100,"Year:");


        sprintf(f,"%ldA.D",y);


        outtextxy(125,100,f);


        outtextxy(372,100,"Month:");


        outtextxy(435,100,mon_name(m));


        outtextxy(r,c,"SUN");


        r=r+50;


        outtextxy(r,c,"MON");


        r=r+50;


        outtextxy(r,c,"TUE");


        r=r+50;


        outtextxy(r,c,"WED");


        r=r+50;


        outtextxy(r,c,"THU");


        r=r+50;


        outtextxy(r,c,"FRI");


        r=r+50;


        outtextxy(r,c,"SAT");


        c=c+30;


        ck=k;


        for(i=1;i<=days;i++)


        {


                if(i==1)


                {


                                 for(r=130,j=1;j<k;j++)


                                        r+=50;                                                              r+=10;






                                 sprintf(f,"%d",i);


                                 outtextxy(r,c,f);


                                 r+=50;


                }


                else


                {


                                 sprintf(f,"%d",i);


                                 outtextxy(r,c,f);


                                 r+=50;


                }


                if(ck%7==0)


                {


                        r=130;


                        c+=25;


                }


                ++ck;






        }


        month_table(130,170);


        getch();


        /* clean up */


        closegraph();


}






/* Function to draw the table for the monthly calender */


void month_table(int r,int c)


{


        int i;


        setcolor(15);


        for(i=1;i<=7;i++)


        {


                line(r-5,c-5,r-5,c+180);


                r+=50;


        }


        line(r-10,c-5,r-10,c+180);


        r=130;


        c=170;


        line(r-5,c-5,r+340,c-5);


        c+=30;


        for(i=1;i<=7;i++)


        {


                line(r-5,c,r+340,c);


                c+=25;


        }


        setcolor(14);


        rectangle(10,50,getmaxx()-10,getmaxy()-50);


        rectangle(12,52,getmaxx()-12,getmaxy()-52);


}






/* Function for initialization of Graphics mode and colour selection */


void start_graphics()


{


        int gdriver = DETECT,gmode, errorcode;


        initgraph(&gdriver, &gmode, "");


       /* read result of initialization  */


        errorcode = graphresult();


        if (errorcode != grOk)


        {


                printf("Graphics error: %s\n", grapherrormsg(errorcode));


                printf("Press any key to halt:");


                getch();


                exit(1);


        }


        cleardevice();


        cout<<"\nChoose any colour for your calender(1-"<<getmaxcolor()<<"):-\n";


        cout<<"\n\t1.Blue\n\t2.Green\n\t3.Cyan\n\t4.Red\n\t5.Magenta";


        cout<<"\n\t6.Brown\n\t7.Light Gray\n\t8.Dark Gray\n\t9.Light Blue\n\t";


        cout<<"10.Light Green\n\t11.Light Cyan\n\t12.Light Red\n\t13.Light Magenta\n\t14.Yellow\n\t15.White";


}






/* Function to display the year calender */


void year_calender(long int y)


{


        int m,dc,k,ic;


        int r=25,c=75,x;


        char f[10];


        start_graphics();


        cout<<"\nEnter the display colour:";


        cin>>dc;


        cleardevice();


        setcolor(14);


        settextstyle(3,0,2);


        x=getmaxx()/2;


        outtextxy(x-60,20,"Year:");


        sprintf(f,"%ldA.D",y);


        outtextxy(x-6,20,f);


        settextstyle(0,0,1);


        setcolor(dc);


        for(m=1;m<=12;m++)


        {


                k=key(y,m,days_calc(y,m));


                if(m==1)


                        get_monthcal(k,mon_tdays(y,m),r,c,dc,m);


                else


                {


                        if(m<=4)


                        {


                                r=r+150;


                                c=75;


                        }


                        else if((m-1)%4==0)


                        {


                                r=25;


                                ic=c+140;


                                c=c+140;


                        }


                        else


                        {


                                r=r+150;


                                c=ic;


                        }


                        get_monthcal(k,mon_tdays(y,m),r,c,dc,m);


                }






        }


        getch();


        closegraph();


}






/* Function to get the month calender for the display of year calender */


void get_monthcal(int k,int days,int r,int c,int dc,int m)


{


        int ck,i,j,cr,cc;


        char f[3];


        cr=r;


        cc=c;


        setcolor(dc);


        outtextxy(r,c,"SU");


        r=r+20;


        outtextxy(r,c,"MO");


        r=r+20;


        outtextxy(r,c,"TU");


        r=r+20;


        outtextxy(r,c,"WE");


        r=r+20;


        outtextxy(r,c,"TH");


        r=r+20;


        outtextxy(r,c,"FR");


        r=r+20;


        outtextxy(r,c,"SA");


        c=c+20;


        ck=k;


        for(i=1;i<=days;i++)


        {


                if(i==1)


                {


                                 for(r=cr,j=1;j<k;j++)


                                        r+=20;                                                              r+=10;






                                 sprintf(f,"%d",i);


                                 outtextxy(r,c,f);


                                 r+=20;


                }


                else


                {


                                 sprintf(f,"%d",i);


                                 outtextxy(r,c,f);


                                 r+=20;


                }


                if(ck%7==0)


                {


                        r=cr;


                        c+=15;


                }


                ++ck;






        }


        year_table(cr,cc,m);


}






/* Function to draw the table in year calender display */


void year_table(int r,int c,int m)


{


        int i,cr,cc;


        cr=r;


        cc=c;


        setcolor(15);


        for(i=1;i<=7;i++)


        {


                line(r-1,c-2,r-1,c+105);


                r+=20;


        }


        line(r,c-2,r,c+105);


        r=cr;


        c=cc;


        line(r+32,c-22,r+108,c-22);


        line(r+30,c-24,r+110,c-24);


        line(r+35,c-10,r+111,c-10);


        line(r+33,c-8,r+113,c-8);


        line(r+32,c-22,r+35,c-10);


        line(r+30,c-24,r+33,c-8);


        line(r+108,c-22,r+111,c-10);


        line(r+110,c-24,r+113,c-8);


        setcolor(12);


        outtextxy(r+38,c-20,mon_name(m));


        setcolor(15);


        line(r-1,c-3,r+140,c-3);


        c+=15;


        for(i=1;i<=7;i++)


        {


                line(r-1,c,r+140,c);


                c+=15;


        }


        setcolor(14);


        rectangle(10,10,getmaxx()-10,getmaxy()-10);


        rectangle(12,12,getmaxx()-12,getmaxy()-12);


}






/* Function to stop the working of infite loop */


void iloop_terminator()


{


        static int i=1;


        ++i;


        if(i>=100)


        {


                textcolor(12+128);


                cprintf("\r\n\n\aInvalid Input! Infinite loop occured!!");


                textcolor(9);


                cprintf("\n\rDear user...you might have entered the invalid inputs like alphaphets or strings");


                cprintf("\nPlease try again...");


                getch();


                exit(1);


        }


}






/* Function to display the first page of the program */


void first_page()


{


        int midx,midy;


        int gdriver = DETECT,gmode, errorcode;


        initgraph(&gdriver, &gmode, "");


        errorcode = graphresult();


        if (errorcode != grOk)


        {


                printf("Graphics error: %s\n", grapherrormsg(errorcode));


                printf("Press any key to halt:");


                getch();


                exit(1);


        }


        cleardevice();


        setbkcolor(0);


        settextjustify(1,1);


        settextstyle(1,0,6);


        midx=getmaxx()/2;


        midy=getmaxy()/2;


        setcolor(12);


        outtextxy(midx,midy-60,"MEGA CALENDER");


        setcolor(13);


        settextstyle(1,0,3);


        outtextxy(midx,midy+10,"(1A.D - 1,00,000A.D)");


        settextstyle(0,0,1);


        setcolor(10);


        outtextxy(midx+80,midy+100,"Designed By,");


        settextstyle(3,0,1);


        setcolor(11);


        outtextxy(midx+130,midy+120,"Jebastin");


        outtextxy(midx+130,midy+140,"Ashish");


        outtextxy(midx+130,midy+160,"Abdul");


        sleep(4);


        cleardevice();


        closegraph();


}


/* End of the program */

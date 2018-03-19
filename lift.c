
#include<stdio.h>
#include<conio.h>

#include<dos.h>

#define ESC 0x1b

int maxy,maxx;
void *buffer,*man;
int flag=5,var_man=5;
int top,left;
int topm,leftm;

int curr_pos=4;


	 void walk(void);
	 void create();
	 void move_lift(int);
	 void simu_end();
	 void initialize();

void main()
{
	 char ch;
	 char* s;
	 initialize();
	 create();
	 while(1)
	 {
	       ch=getch();
	       if(ch==ESC)
	       {
	       simu_end();
	       exit(0);
	       }
	       else if((ch-48)>0 && (ch-48)<=4)
	       {
	       move_lift((int)(ch-48));
	       }
	 }
}

void initialize()
{
	int gd=DETECT,gm,gerror;
	void *floor;
	 initgraph(&gd,&gm,"c:\\tc\\bgi");
	 gerror=graphresult();
	 if(gerror!=grOk)
	 {
		printf("error in init graph %s",grapherrormsg(gerror));
		getch();
		exit(0);
	 }
	 maxy=getmaxy();
	 maxx=getmaxx();

	 rectangle(0,30,maxx,maxy);
	 setfillstyle(SOLID_FILL,3);

	 //Floor creation
	 bar(0,maxy/2,maxx/2-32,maxy/2+10);
	 line(0,maxy/2+10,maxx/2+30,maxy/2+10);

	 floor=malloc(imagesize(0,maxy/2,maxx/2+30,maxy/2+10));

	 getimage(0,maxy/2,maxx/2+30,maxy/2+10,floor);

	 putimage(0,maxy/2,floor,XOR_PUT);

	 putimage(0,170,floor,OR_PUT); //fourth floor

	 putimage(0,270,floor,OR_PUT);  //third floor

	 putimage(0,370,floor,OR_PUT);  //second floor

	 putimage(0,470,floor,OR_PUT);   //first floor

	 setfillstyle(SOLID_FILL,8);

	 bar(30,130,50,169); //fourth floor door
	 bar(30,230,50,269); //third floor door
	 bar(30,330,50,369); //second floor door
	 bar(30,430,50,469); //first  floor door

	 //Elivator shaft
	 line(maxx/2-32,30,maxx/2-32,maxy);
	 line(maxx/2+32,30,maxx/2+32,maxy);

	 //Floor numbers
	 outtextxy(maxx/2-130,maxy-95,"FIRST FLOOR");
	 outtextxy(maxx/2-130,maxy-195,"SECOND FLOOR");
	 outtextxy(maxx/2-130,maxy/2-55,"THIRD FLOOR");
	 outtextxy(maxx/2-130,80,"FORTH FLOOR");

	 //Title
	 settextstyle(4,0,2);
	 setcolor(2);
	 outtextxy(maxx/2-90,0,"LITF SIMULATOR");

	 //Instructions
	 outtextxy(maxx/2+40,30,"INSTRUCTIONS:");
	 outtextxy(maxx/2+40,80,"Step1:call the lift to a floor");
	 outtextxy(maxx/2+40,110,"Step2: Go to destination floor");
	 setcolor(15);
}


void create()
{
	//creating lift
	setfillstyle(SOLID_FILL,8);
	bar(maxx/2-30,100,maxx/2+30,178);
	setfillstyle(SOLID_FILL,9);
	bar(maxx/2-20,110,maxx/2+20,168); //total size is 60/78 pixels

	buffer=malloc(imagesize(maxx/2-30,100,maxx/2+30,178));

	getimage(maxx/2-30,100,maxx/2+30,178,buffer);

	flag=5;
	left=maxx/2-30;
	top=100;

	setfillstyle(SOLID_FILL,2);

	bar(left-30,top+5,left-20,top+15);

	   //creating person

		circle(70,135,5);     //head
		line(70,140,70,160);
		line(70,145,65,154);  //hands
		line(70,145,75,154);
		line(70,155,65,167);   //legs
		line(70,155,75,167);  //total size is 10/30 pixels


	       man=malloc(imagesize(60,130,75,167));

	       getimage(60,130,75,167,man);

	       putimage(60,130,man,XOR_PUT);
	       leftm=30;
	       topm=130;


}

 void walk()
 {
	int x=0;
	while(x<56)
	{
		leftm+=var_man;
		putimage(leftm,topm,man,XOR_PUT);
		delay(20);
		x++;
		putimage(leftm,topm,man,XOR_PUT);
		delay(20);
	}
	var_man=-var_man;
	sound(1000);
	delay(150);
	nosound();

 }


void move_lift(int req_pos)
{
	int i=0;
	int j=0;
	char ch;

//moving the lift  to the calling floor
	if(curr_pos!=req_pos)
	{
		if(curr_pos>req_pos)
		{flag=5;
		j=curr_pos-req_pos;}
		else
		{flag=-5;
		j=req_pos-curr_pos;}
		for(;j>0;j--)
		{
			setfillstyle(SOLID_FILL,4);
			bar(left-30,top+5,left-20,top+15);

			while(i<20)
			{
				putimage(left,top,buffer,XOR_PUT);
				i++;
				top+=flag;
				topm+=flag;
				putimage(left,top,buffer,XOR_PUT);
				delay(20);
			}
			i=0;
			setfillstyle(SOLID_FILL,2);
			bar(left-30,top+5,left-20,top+15);
			delay(50);

		}
	}
	curr_pos=req_pos;

//man enters the lift
	walk();
	putimage(leftm,topm,man,XOR_PUT);

//taking input destination floor
	while(1)
	{
		ch=getch();
		if(ch==ESC)
		{
		simu_end();
		exit(0);
		}
		else if((ch-48)>0 && (ch-48)<=4)
		{
			req_pos=(int)(ch-48);
			break;
		}
	}
	if(curr_pos!=req_pos)
	{
		if(curr_pos>req_pos)
		{flag=5;
		j=curr_pos-req_pos;
		}
		else
		{flag=-5;
		j=req_pos-curr_pos;
		}

//moving the lift  to the destination floor
		for(;j>0;j--)
		{
			setfillstyle(SOLID_FILL,4);
			bar(left-30,top+5,left-20,top+15);

			while(i<20)
			{       putimage(left,top,buffer,XOR_PUT);
				putimage(leftm,topm,man,XOR_PUT);
				i++;
				top+=flag;
				topm+=flag;
				putimage(left,top,buffer,XOR_PUT);
				putimage(leftm,topm,man,XOR_PUT);
				delay(20);
			}
			i=0;
			setfillstyle(SOLID_FILL,2);
			bar(left-30,top+5,left-20,top+15);
			delay(50);
		}
	}
		curr_pos=req_pos;
		putimage(leftm,topm,man,XOR_PUT);
		sound(3000);
		delay(50);
		sound(5000);
		delay(50);
		sound(3000);
		delay(200);
		nosound();

//man walking out of the lift 
		walk();


 }

void simu_end()
{
	cleardevice();
	setcolor(2);
	settextstyle(4,0,3);
	outtextxy(maxx/2-textwidth("closing simulation....")/2,maxy/2,"closing simulation.....");
	delay(500);
	outtextxy(maxx-textwidth("Programming by:")-20,maxy-90,"Programing by:");
	outtextxy(maxx-textwidth("SIDDHARTH")-10,maxy-50,"SIDDHARTH");
	getch();
}

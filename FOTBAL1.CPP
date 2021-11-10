#include <graphics.h>
#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#define SV  0x31 //1
#define S   0x32 //2
#define SE  0x33 //3
#define E   0x36 //6
#define NE  0x39 //9
#define N   0x38 //8
#define NV  0x37 //7
#define V   0x34 //4
#define ESC 0x1b

int X,Y,pct1,pct2, la_rand;

void fereastramica();
void teren();
void parteadr();
int continuare();
int gol();
void final_joc();
void final_runda();
int blocat();
void joc();


void fereastramica()
{
int maxx,maxy;
maxx=getmaxx();
maxy=getmaxy();

setcolor(WHITE);
rectangle(maxx/2-250,maxy/2-100,maxx/2+250,maxy/2+100);
rectangle(maxx/2-250+1,maxy/2-100+1,maxx/2+250-1,maxy/2+100-1);

setcolor(RED);
rectangle(maxx/2-250+2,maxy/2-100+2,maxx/2+250-2,maxy/2+100-2);

setcolor(WHITE);
rectangle(maxx/2-250+3,maxy/2-100+3,maxx/2+250-3,maxy/2+100-3);
rectangle(maxx/2-250+4,maxy/2-100+4,maxx/2+250-4,maxy/2+100-4);

line(maxx/2-250+10,maxy/2+100,maxx/2-250+10,maxy/2+100+10);
line(maxx/2-250+10,maxy/2+100+10,maxx/2+250+10,maxy/2+100+10);
line(maxx/2+250+10,maxy/2+100+10,maxx/2+250+10,maxy/2-100+10);
line(maxx/2+250+10,maxy/2-100+10,maxx/2+250,maxy/2-100+10);

setfillstyle(CLOSE_DOT_FILL,WHITE);
floodfill(maxx/2-180+11,maxy/2+100+1,WHITE);
setcolor(LIGHTGRAY);
line(maxx/2-250+10,maxy/2+100,maxx/2-250+10,maxy/2+100+10);
line(maxx/2-250+10,maxy/2+100+10,maxx/2+250+10,maxy/2+100+10);
line(maxx/2+250+10,maxy/2+100+10,maxx/2+250+10,maxy/2-100+10);
line(maxx/2+250+10,maxy/2-100+10,maxx/2+250,maxy/2-100+10);
setfillstyle(SOLID_FILL,RED);
floodfill(maxx/2,maxy/2,WHITE);
}

void teren()
{
int maxx,maxy,midx,midy;
maxx=getmaxx();
maxy=getmaxy();
midx=maxx/2;
midy=maxy/2;
setcolor(BLACK);

//terenul
setlinestyle(SOLID_LINE, 1, THICK_WIDTH);
line(midx/2-18*7-1,midy-18*10-1,midx/2-18*7-1,midy+18*10+1);
line(midx/2-18*7-1,midy+10*18+1,midx/2-18-1,midy+10*18+1);
line(midx/2-18-1,  midy+10*18+1,midx/2-18-1,midy+11*18+1);
line(midx/2-18-1,  midy+11*18+1,midx/2+18+1,midy+11*18+1);
line(midx/2+18+1,  midy+11*18+1,midx/2+18+1,midy+10*18+1);
line(midx/2+18+1,  midy+10*18+1,midx/2+7*18+1,midy+10*18+1);
line(midx/2+7*18+1,midy+10*18+1,midx/2+7*18+1,midy-10*18-1);
line(midx/2+7*18+1,midy-10*18-1,midx/2+18+1,midy-10*18-1);
line(midx/2+18+1,  midy-10*18-1,midx/2+18+1,midy-11*18-1);
line(midx/2+18+1,  midy-11*18-1,midx/2-18-1,midy-11*18-1);
line(midx/2-18-1,  midy-11*18-1,midx/2-18-1,midy-10*18-1);
line(midx/2-18-1,  midy-18*10-1,midx/2-18*7-1,midy-18*10-1);
setcolor(GREEN);
setfillstyle(SOLID_FILL,GREEN);
floodfill(midx/2,midy,BLACK);

//liniile de pe teren
setcolor(BLACK);
setlinestyle(SOLID_LINE, 1, NORM_WIDTH);
line(midx/2-4*18,midy-10*18,midx/2-4*18,midy-7*18);
line(midx/2-4*18,midy-7*18,midx/2+4*18,midy-7*18);
line(midx/2+4*18,midy-7*18,midx/2+4*18,midy-10*18);
line(midx/2-18*2,midy-7*18,midx/2-18,midy-6*18);
line(midx/2-18,midy-6*18,midx/2+18,midy-6*18);
line(midx/2+18,midy-6*18,midx/2+2*18,midy-7*18);
rectangle(midx/2-3*18,midy-3*18,midx/2+3*18,midy+3*18);
line(midx/2-7*18,midy,midx/2+7*18,midy);
line(midx/2-4*18,midy+10*18,midx/2-4*18,midy+7*18);
line(midx/2-4*18,midy+7*18,midx/2+4*18,midy+7*18);
line(midx/2+4*18,midy+7*18,midx/2+4*18,midy+10*18);
line(midx/2-2*18,midy+7*18,midx/2-18,midy+6*18);
line(midx/2-18,midy+6*18,midx/2+18,midy+6*18);
line(midx/2+18,midy+6*18,midx/2+2*18,midy+7*18);
setcolor(BLACK);
rectangle(midx/2-1,midy+1,midx/2+1,midy-1);
}


void parteadr()
{
int maxx,maxy,midx,midy;
maxx=getmaxx();
maxy=getmaxy();
midx=maxx/2;
midy=maxy/2;
setcolor(CYAN);
settextstyle(2,0,7);

outtextxy(midx-10,midy/2,"Jucatorul 1");
outtextxy(midx-10+1,midy/2,"Jucatorul 1");
outtextxy(midx-10+2,midy/2,"Jucatorul 1");

outtextxy(midx+140,midy/2,"Jucatorul 2");
outtextxy(midx+140+1,midy/2,"Jucatorul 2");
outtextxy(midx+140+2,midy/2,"Jucatorul 2");
settextstyle(10,0,4);

outtextxy(midx+70,midy/2+80,"SCOR");
setcolor(BLACK);
rectangle(midx+60,midy/2+170,midx+200,midy/2+220);

settextstyle(10,0,4);
outtextxy(midx+75,midy/2+155,"0");
outtextxy(midx+160,midy/2+155,"0");
line(midx+130,midy/2+170,midx+130,midy/2+220);
}

int continuare()
{
if(getpixel(159-2,239-2)==GREEN)return 1;
if(getpixel(159  ,239-2)==GREEN)return 1;
if(getpixel(159+2,239-2)==GREEN)return 1;
if(getpixel(159+2,239+2)==GREEN)return 1;
if(getpixel(159  ,239+2)==GREEN)return 1;
if(getpixel(159-2,239+2)==GREEN)return 1;
return 0;   //daca NU se mai poate incepe de la mijloc odata
}

int gol()
{
int midy;
midy=getmaxy()/2;
if( (Y==midy-18*11) || (Y==midy+18*11)) return 1; //GOL!
return 0;//adica nu e gol
}

void final_joc()
{
char a, scor[10];

fereastramica();
settextstyle(7,0,2);

if(pct1 > pct2) outtextxy(getmaxx()/2-130,getmaxy()/2-50,"A castigat jucatorul 1 !!!");
else outtextxy(getmaxx()/2-130,getmaxy()/2-50,"A castigat jucatorul 2 !!!");

sprintf(scor,"%d",pct1);
outtextxy(getmaxx()/2-15,getmaxy()/2-30,scor);

outtextxy(getmaxx()/2,getmaxy()/2-30,":");

sprintf(scor,"%d",pct2);
outtextxy(getmaxx()/2+10,getmaxy()/2-30,scor);

outtextxy(getmaxx()/2-100,getmaxy()/2,"Mai jucati? (d/n) ");
setcolor(WHITE);
rectangle(getmaxx()/2-60,getmaxy()/2+45,getmaxx()/2-10,getmaxy()/2+65);
setfillstyle(SOLID_FILL,BLACK);
floodfill(getmaxx()/2-60+1,getmaxy()/2+45+1,WHITE);
gotoxy(34,19);
cin>>a;
if(a=='d'){
	cleardevice();
	pct1=pct2=0;
	joc();
	}
else exit(0);

}

void final_runda() //in caz de gol sau blocat
{
char a, scor[10];
int midx,midy;
midx=getmaxx()/2;
midy=getmaxy()/2;
//la_rand == cel care sa blocat / dat gol
if(blocat())  {
      fereastramica();
      settextstyle(7,0,2);
      outtextxy(getmaxx()/2-200,getmaxy()/2-50,"Te-ai blocat! Jocul se termina nedecis.");
	      }

if(gol())
	if(continuare())
	  {
	  setcolor(DARKGRAY); //aici sterge
	  settextstyle(10,0,4);

	  sprintf(scor,"%d",pct1);
	  outtextxy(midx+75,midy/2+155,scor);

	  sprintf(scor,"%d",pct2);
	  outtextxy(midx+160,midy/2+155,scor);
	  //line(midx+130,midy/2+170,midx+130,midy/2+220);

	  if(la_rand==1){ pct1++;  la_rand=2; }
	  else { pct2++; la_rand=1; }       //modifica scor

	  setcolor(BLACK);   //afiseaza scor
	  settextstyle(10,0,4);
	  sprintf(scor,"%d",pct1);
	  outtextxy(midx+75,midy/2+155,scor);
	  sprintf(scor,"%d",pct2);
	  outtextxy(midx+160,midy/2+155,scor);

	  if(la_rand==1) setcolor(RED);
	  else setcolor(BLUE);

	  moveto(159,239);
	  X=getx();
	  Y=gety();
	  if( pct1==3 || pct2==3) final_joc();
	  }
  else final_joc();
}

int blocat()
{
int midx, midy;
midx=getmaxx()/2;
midy=getmaxy()/2;

if((X==midx/2+(18*7) && Y==midy+18*10) || //jos dr
	 (X==midx/2+(18*7) && Y==midy-18*10) ||   //jos stg
		(X==midx/2-(18*7) && Y==midy+18*10) ||   //sus dr
		  (X==midx/2-(18*7) && Y==midy-18*10))     //sus stg
			  return 1;  //daca s-a ajuns in colturi
if(getpixel(X-2,Y+2)==0 || getpixel(X-2,Y+2)==1 || getpixel(X-2,Y+2)==4)
 if (getpixel(X,Y+2)==0 || getpixel(X,Y+2)==1   ||   getpixel(X,Y+2)==4)
  if (getpixel(X+2,Y+2)==0 || getpixel(X+2,Y+2)==1   ||   getpixel(X+2,Y+2)==4)
	if (getpixel(X+2,Y)==0 || getpixel(X+2,Y)==1   ||   getpixel(X+2,Y)==4)
	 if (getpixel(X+2,Y-2)==0 || getpixel(X+2,Y-2)==1   ||   getpixel(X+2,Y-2)==4)
	  if  (getpixel(X,Y-2)==0 || getpixel(X,Y-2)==1   ||   getpixel(X,Y-2)==4)
		if (getpixel(X-2,Y-2)==0 || getpixel(X-2,Y-2)==1   ||   getpixel(X-2,Y-2)==4)
		 if (getpixel(X-2,Y)==0 || getpixel(X-2,Y)==1   ||   getpixel(X-2,Y)==4)
			  return 1; // daca nu mai e nici o mutare posibila
return 0;
}

int se_schimba_jucatorul()
{
int i=0;
if(getpixel(X-2,Y+2)==0 || getpixel(X-2,Y+2)==1 || getpixel(X-2,Y+2)==4)i++;
if(getpixel(X,Y+2)==0 || getpixel(X,Y+2)==1   ||   getpixel(X,Y+2)==4)i++;
if(getpixel(X+2,Y+2)==0 || getpixel(X+2,Y+2)==1   ||   getpixel(X+2,Y+2)==4)i++;
if(getpixel(X+2,Y)==0 || getpixel(X+2,Y)==1   ||   getpixel(X+2,Y)==4)i++;
if(getpixel(X+2,Y-2)==0 || getpixel(X+2,Y-2)==1   ||   getpixel(X+2,Y-2)==4)i++;
if(getpixel(X,Y-2)==0 || getpixel(X,Y-2)==1   ||   getpixel(X,Y-2)==4)i++;
if(getpixel(X-2,Y-2)==0 || getpixel(X-2,Y-2)==1   ||   getpixel(X-2,Y-2)==4)i++;
if(getpixel(X-2,Y)==0 || getpixel(X-2,Y)==1   ||   getpixel(X-2,Y)==4)i++;
if(i>=2) return 0;
else return 1;
}

void joc()
{

int midx,midy,maxx,maxy;

midx = getmaxx() / 2;
midy = getmaxy() / 2;

maxx=getmaxx();
maxy=getmaxy();

//margineas=chenar
setcolor(WHITE);
rectangle(0,0,maxx,maxy);
rectangle(1,1,maxx-1,maxy-1);
rectangle(2,2,maxx-2,maxy-2);
rectangle(3,3,maxx-3,maxy-3);
rectangle(5,5,maxx-5,maxy-5);
rectangle(7,7,maxx-7,maxy-7);
setfillstyle(SOLID_FILL,DARKGRAY);
floodfill(4,47,WHITE);
floodfill(6,6,WHITE);
floodfill(22,22,WHITE);
teren();
parteadr();

int c;
la_rand=1;
//deseneaza careul in jurul "jucatorul 1"
setcolor(MAGENTA);
rectangle(midx-14,117,midx+118,147);
rectangle(midx-14-1,117-1,midx+118+1,147+1);
rectangle(midx-14-2,117-2,midx+118+2,147+2);
//sterge
setcolor(DARKGRAY);
rectangle(midx+137,117,midx+270,147);
rectangle(midx+137-1,117-1,midx+270+1,147+1);
rectangle(midx+137-2,117-2,midx+270+2,147+2);

moveto(midx/2,midy); //fixeaza curs in mij terenului
X=getx();
Y=gety();
putpixel(X,Y,WHITE); //ca sa porneasca de pe alb
setcolor(RED);
while(1)
{
 if(se_schimba_jucatorul() )
		if(la_rand==1){
					 la_rand=2;
					 //deseneaza in jurul jucaor2
					 setcolor(MAGENTA);
					 rectangle(midx+137,117,midx+270,147);
					 rectangle(midx+137-1,117-1,midx+270+1,147+1);
					 rectangle(midx+137-2,117-2,midx+270+2,147+2);
					 //sterge
					 setcolor(DARKGRAY);
					 rectangle(midx-14,117,midx+118,147);
					 rectangle(midx-14-1,117-1,midx+118+1,147+1);
					 rectangle(midx-14-2,117-2,midx+118+2,147+2);

					 setcolor(BLUE);
					 }
		else {
					 la_rand=1;
					 //deseneaza careul in jurul "jucatorul 1"
					 setcolor(MAGENTA);
					 rectangle(midx-14,117,midx+118,147);
					 rectangle(midx-14-1,117-1,midx+118+1,147+1);
					 rectangle(midx-14-2,117-2,midx+118+2,147+2);
					 //sterge
					 setcolor(DARKGRAY);
					 rectangle(midx+137,117,midx+270,147);
					 rectangle(midx+137-1,117-1,midx+270+1,147+1);
					 rectangle(midx+137-2,117-2,midx+270+2,147+2);

					 setcolor(RED);
			  }
 if( blocat() || gol())  final_runda(); //daca s-a terminat runda

 mutare:
 c=getch();
 switch (c) {
	 case SV :{
			if(getpixel(X-10,Y+10)==2) { //se verifica cu x+-10 si y+-10
						 //caci cateodata +-18 inseamna
				 X-=18;                   //o linie unde ARE voie sa ajunga
				 Y+=18;
				 lineto(X,Y);
				  }
			else goto mutare;
			  break;
			  }
	 case S: {
			 if(getpixel(X,Y+10)==2){
					 Y+=18;
					 lineto(X,Y);
					  }

			  else goto mutare;
			  break;}
	 case SE:{
			 if(getpixel(X+10,Y+10)==2){

					 X+=18;
					 Y+=18;
					 lineto(X,Y);
					  }

			 else goto mutare;
			 break;}
	 case E:{

			 if(getpixel(X+10,Y)==2){
					  X+=18;
					  lineto(X,Y);
					  }
			 else goto mutare;
			 break;}
	 case NE:{
			 if(getpixel(X+10,Y-10)==2){
					  X+=18;
					 Y-=18;
					  lineto(X,Y);
					  }

			 else goto mutare;
			 break;}
	 case N:{
			 if(getpixel(X,Y-10)==2){

					 Y-=18;
					  lineto(X,Y);
					  }

			 else goto mutare;
			 break;}
	 case NV:{
			 if(getpixel(X-10,Y-10)==2){
					  X-=18;
					 Y-=18;
					  lineto(X,Y);
					  }
			 else goto mutare;
			 break;}
	 case V:{
			 if(getpixel(X-10,Y)==2){
					  X-=18;
					  lineto(X,Y);
					  }
			 else goto mutare;
			break;}
	 case ESC: exit(0);
		 default : goto mutare;
		 }//se tremnina switch
	}//se termina while
}//se termina fct

void main()
{
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver, &gmode, "");
errorcode = graphresult();
if (errorcode != grOk)
{
   printf("Eroare grafica : %s\n", grapherrormsg(errorcode));
   printf("Apasa o tasta");
   getch();
   exit(1);
}

joc();
}

////////////////////////////////////////
////////////////////////////////////////
/// Program to draw the wire diagram ///
///////// of a flying aeroplane ////////
////////////////////////////////////////
/// The keys control the speed of the //
///////////////// plane ////////////////
////////////////////////////////////////
/// Pressing up arrow increases speed //
/// and pressing down arrow decreases //
///////////////// speed ////////////////
////////////////////////////////////////
////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>

int main() 
{
 int i,j=500;
 char k;
 int gd=DETECT,gm;
 initgraph(&gd,&gm,NULL);
 setbkcolor(WHITE);
 setcolor(BLACK);
 setlinestyle(0,0,3);
 fflush(stdin);
 while(1)
 {
  for(i=0;i<=550;i+=10)
  {
   if(kbhit())
   {
    k=getch();
    fflush(stdin);
    //printf("%d\n",k);
    if(k=='w')
    {
     if(j>=100)
     {
      j-=100;
     }
    }
    else if(k=='s')
    {
     j+=100;
    }
   }
   cleardevice();
   line(30+i,300,90+i,300);
   line(60+i,300,40+i,350);
   line(60+i,300,40+i,250);
   line(30+i,300,20+i,320);
   line(30+i,300,20+i,280);
   delay(j);
  }
 }
 return 0;
}

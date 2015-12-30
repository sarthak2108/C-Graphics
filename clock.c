////////////////////////////////////////
////////////////////////////////////////
/// Program to draw a real clock with //
/// hours, minutes and seconds hands ///
//// rotating around to count exact ////
///////////////// time /////////////////
////////////////////////////////////////
////////////////////////////////////////


#include<stdio.h>
#include<math.h>
#include<graphics.h>

int main() 
{
 long int i;
 int xs,ys,xh,yh,xm,ym,xs_old,ys_old,xh_old,yh_old,xm_old,ym_old,count,h,m,s;
 float deg1,deg2,deg3;
 //printf("%d:%d:%d\n",h,m,s);
 int gd=DETECT,gm;
 initgraph(&gd,&gm,NULL);
 setbkcolor(WHITE);
 setcolor(BLACK);
 circle(300,300,100);
 circle(300,300,110);
 setcolor(RED);
 floodfill(405,300,BLACK);
 setcolor(BLACK);
 for(i=0;i<12;i++)
 {
  line(300+0*cos(i*(3.14/6))+80*sin(i*(3.14/6)),300-0*sin(i*(3.14/6))+80*cos(i*(3.14/6)),300+0*cos(i*(3.14/6))+90*sin(i*(3.14/6)),300-0*sin(i*(3.14/6))+90*cos(i*(3.14/6)));
 }
 i=time(NULL);
 h=(i%86400)/3600-4;
 if(h>=12)
 {
  h=h-12;
 }
 m=(i%3600)/60;
 s=i%60;
 count=60*m+s;
 deg1=(3.14/30)*s;
 deg2=(3.14/30)*m;
 deg3=((3.14/6)*h)+((m/10)*(3.14/36));
 xs=0*cos(deg1)+80*sin(deg1);
 ys=-0*sin(deg1)+80*cos(deg1);
 xm=0*cos(deg2)+70*sin(deg2);
 ym=-0*sin(deg2)+70*cos(deg2);
 xh=0*cos(deg3)+60*sin(deg3);
 yh=-0*sin(deg3)+60*cos(deg3);
 xs_old=xs;
 ys_old=ys;
 xm_old=xm;
 ym_old=ym;
 xh_old=xh;
 yh_old=yh;
 setcolor(BLACK);
 line(300,300,300+xs,300-ys);
 line(300,300,300+xm,300-ym);
 line(300,300,300+xh,300-yh);
 while(1)
 {
  delay(1000);
  count++;
  deg1+=(3.14/30);
  if(count%60==0)
  {
   deg1=0;
   deg2+=(3.14/30);
   setcolor(WHITE);
   line(300,300,300+xm_old,300-ym_old);
   xm=0*cos(deg2)+70*sin(deg2);
   ym=-0*sin(deg2)+70*cos(deg2);
   setcolor(BLACK);
   line(300,300,300+xm,300-ym);
   xm_old=xm;
   ym_old=ym;
   setcolor(BLACK);
   line(300,300,300+xh_old,300-yh_old);
   line(300,300,300+xs_old,300-ys_old);
  }
  if(count%600==0)
  {
   deg3+=(3.14/36);
   if(deg3==2*3.14)
   {
    deg3=0;
   }
   setcolor(WHITE);
   line(300,300,300+xh_old,300-yh_old);
   xh=0*cos(deg3)*+60*sin(deg3);
   yh=-0*cos(deg3)+60*sin(deg3);
   setcolor(BLACK);
   line(300,300,300+xh,300-yh);
   xh_old=xh;
   yh_old=yh;
   setcolor(BLACK);
   line(300,300,300+xm_old,300-ym_old);
   line(300,300,300+xs_old,300-ys_old);
  }
  if(count==3600)
  {
   deg2=0;
   count=0;
  }
  setcolor(WHITE);
  line(300,300,300+xs_old,300-ys_old);
  xs=0*cos(deg1)+80*sin(deg1);
  ys=-0*sin(deg1)+80*cos(deg1);
  setcolor(BLACK);
  line(300,300,300+xs,300-ys);
  line(300,300,300+xm_old,300-ym_old);
  line(300,300,300+xh_old,300-yh_old);
  xs_old=xs;
  ys_old=ys;
 }
}

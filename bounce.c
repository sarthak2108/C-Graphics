////////////////////////////////////////
////////////////////////////////////////
//// Program to simulate a bouncing ////
/// ball with a damped sine function ///
////////////////////////////////////////
////////////////////////////////////////

#include<stdio.h>
#include<math.h>
#include<graphics.h>

int main() 
{
 int x,y,x_old,y_old;
 float a,af,pa,k;
 printf("\nEnter the value of the initial amplitude:");
 scanf("%f",&a);
 printf("\nEnter the value of the frequency:");
 scanf("%f",&af);
 printf("\nEnter the value of the phase angle:");
 scanf("%f",&pa);
 printf("\nEnter the value of the damping constant:");
 scanf("%f",&k);
 af=af/(2*3.14);
 pa=pa*(3.14/180);
 int gd=DETECT,gm;
 initgraph(&gd,&gm,NULL);
 setbkcolor(WHITE);
 setcolor(BLACK);
 line(0,442,600,442);
 x=0;
 if(sin((af*x/10)+pa)>=0)
 {
  y=(int)(a*sin((af*x/10)+pa)*exp((-k)*x));
 }
 else
 {
  y=-(int)(a*sin((af*x/10)+pa)*exp((-k)*x));
 }
 //printf("%d\n",(int)(a*(sin((af*x)+pa))*exp((-k)*x)));
 circle(50+x,400-y,40);
 //floodfill(50+x,400-y,BLACK);
 x_old=x;
 y_old=y;
 while(1)
 {
  //printf("%d %d\n",x,y);
  delay(50);
  cleardevice();
  setcolor(BLACK);
  line(0,442,600,442);
  x++;
  if(sin((af*x/10)+pa)>=0)
  {
   y=(int)(a*sin((af*x/10)+pa)*exp((-k)*x));
  }
  else
  {
   y=-(int)(a*sin((af*x/10)+pa)*exp((-k)*x));
  }
  x_old=x;
  y_old=y;
  circle(50+x,400-y,40);
  //floodfill(50+x,400-y,BLACK);
  //getch();
 }
 return 0;
}
  
 

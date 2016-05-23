

#include "ModelPlayer.h"
#include "Nokia5110.h"
#include "..//tm4c123gh6pm.h"
#include "TExaS.h"
#include "time.h"   // time()
#include "stdlib.h" // rand(), srand()

void ball_move (){
//@TO DO complete directions and check if valid state before move 
switch(d){
int z;
case 0:
//	up left y-- x--
z=ball_checkState(y-1,x-1);
SwitchStates(z);
if(z==0){
y--;
x--;
}
break;
case 1:
// up y--
z=ball_checkState(y-1,x);
SwitchStates(z);
if(z==0){
y--;
}
break;
case 2:
// up right y-- x++
z=ball_checkState(y-1,x+1);
SwitchStates(z);
if(z==0){
y--;
x++;
}
break;
case 3:
// down left y++ x--
z=ball_checkState(y+1,x-1);
SwitchStates(z);
if(z==0){
y++;
x--;
}
break;
case 4: 
// down  y++
z=ball_checkState(y+1,x);
SwitchStates(z);
if(z==0){
y++;
}
break;
case 5:
// down right y++ x++
z=ball_checkState(y+1,x+1);
SwitchStates(z);
if(z==0){
y++;
x++;
}
break;
default :
	break;
}
// ball_deleteCell();
}
void ball_init (){
	int i,j;
	d=1;
	x=10,y=9;
}
void ball_initlevel(){
	score=0;
	lifes=3;
	level=1;
}
void ball_ChangeDir(unsigned int state ){
if(state==1){ // if hits block move oppiste direction
if(d<=2)
	d=rand()%3+3; //move down
else
	d=rand()%3; // move up
}
if(state==2) // if hits slider move up
	d=rand()%3;

if(state==4)  //if hits the upper wall it will direct down 
	d=rand()%3+3;

if(state==3){ //if hits wall move in same direction
if(d>2)
	d=rand()%3+3; //move down
else
	d=rand()%3; 
}

}
	void ball_increaseScore(){
		score+=10*level;
	}

	int ball_checkState(int y,int x){
if(y>=GRIDH)                   // the ball missed the ball --> lose
return -1;
if(y<=0)                        //hits upper border of screen
return 4;
if(x>=GRIDW || x<0 )            //the next state is out of borders 
return 3; 
if(screen[y][x]==0)           // the next state is an empty cell
return 0;
if(screen[y][x]==1)           // the state is that your next cell is ocubed by block
{screen[y][x]=0; ball_increaseScore();
return 1;}
if(screen[y][x]==2)            //when the next state is the slider 
return 2;
  return -1;                      //the error case when none of the above

}
	
	void ball_deleteCell(){
		if( ball_checkState(y ,x-1)==1)   //check if u....
		{screen[y][x-1]=0;
			ball_increaseScore();}
		if( ball_checkState(y ,x+1)==1)   //check if u....
		{screen[y][x+1]=0;
			ball_increaseScore();}
		if( ball_checkState(y+1 ,x)==1)   //check if u....
		{screen[y+1][x]=0;
			ball_increaseScore();}
		if( ball_checkState(y-1,x)==1)   //check if u....
		{screen[y-1][x]=0;
			ball_increaseScore();}		
}
	void SwitchStates(int state){
		switch(state){
			//TO DO ::Esraaaa2 
			case -1:
			lifes--;
				break;
			case 0:  
						break;
			case 1:     //delete cell ..convert state from 1 to 0 .. increase score..change direction
				
			case 2:    //the ball is moving down when going up change direction choose from d=(4,5,6)
			case 4:
			case 3:
				 ball_ChangeDir(state);	
				 ball_deleteCell();
			  break;
			default:
				break;
				
		}	
	}

void setX(int ox){
x=ox;
}

void setY(int oy){
y=oy;
}

void setD(int dir){
d=dir;
}
void setScore(int S){
score=S;
}
void setLifes(int L){
lifes=L;
}
void setLevel(int L){
	level=L;
}

//getter

int GetX(){
return x;
}

int GetY(){
return y;
}

int GetD(){
return d;
}

int GetScore(){
return score;
}

int GetLifes(){
return lifes;
}

int GetLevel(){
	return level;
}

int GetScreen(int i,int j){
	return screen[i][j];
}
void setScreen(int i,int j,int state){
	screen[i][j]=state;
}
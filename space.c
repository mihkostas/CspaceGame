#include <stdio.h>
#include <conio.h> 
#include <stdlib.h>
#include <time.h>
#define N 6


struct point{int x;int y;int ys;};
void SLEEP(int);
void CreateTable(char***,int,int);
char keyInput(char**t,int *x,int *y);

int main(void){
 char **t;
 char **ranT;
 char i,j,lives = 3;
 int x=10,y=19;
 struct point enemis[N];
 struct point bullet;
 char shoot=0;
 char key;
 int ran_x;
 char s=0;
 
 srand(time(0));
 CreateTable(&t,20,20);
  CreateTable(&ranT,20,20);
  
for(i=0;i<20;i++){
   for(j=0;j<20;j++){
   	if(((rand()%(200+1-1)+1)/10 == 1) && i < 19)
	   ranT[i][j] = '.';
    else
	   ranT[i][j] = ' ';

   }
 } 

 for(i=0;i<20;i++){
   for(j=0;j<20;j++){
      t[i][j] = ' ';

   }
 }
 
 for(i=0;i<N;i++){
 	ran_x = rand()%(20)+1; 	
 	enemis[i].x = ran_x;
 	enemis[i].y = 1;
 	enemis[i].ys = rand()%(2)+1;
 	
 	
 	
 	
 	
 	
 	
 }
 
 
bullet.ys = 0;
  

while(1){

   for(i=0;i<N;i++){
   	t[enemis[i].y][enemis[i].x] = 233;
   }
  t[y][x] = 207;
  
  printf("%c",201);
  for(i=0;i<20*2;i++)printf("%c",205);
  printf("%c",187);
  printf("lives[%d] score[%d]",lives,s);
  printf("\n");
  for(i=0;i<20;i++){
  	printf("%c",186);
   for(j=0;j<20;j++){
   	  if(ranT[i][j]!=' ')printf(" %c",ranT[i][j]);
   	  else printf(" %c",t[i][j]);
      
   }
   printf("%c\n",186);
 }
  
  printf("%c",200);
  for(i=0;i<20*2;i++)printf("%c",205);
   printf("%c",188);
   




if(key = keyInput(t,&x,&y)){
if(key=='q')exit(-1);
if(shoot == 0){

 if(key == 'w'){
	bullet.y = y-1;
	bullet.x = x;
	bullet.ys = -1;
	shoot = 1;
		
     }
   }
}
  
  
  
for(i=0;i<N;i++){

  enemis[i].y+= enemis[i].ys;
  t[enemis[i].y-enemis[i].ys][enemis[i].x] = ' ';
   
  
  



  if(enemis[i].y >= 19){
    enemis[i].y = 1;
 	ran_x = rand()%(20)+1; 	
 	enemis[i].x = ran_x;
 	enemis[i].ys = rand()%(2)+1;
 	
}
  if(enemis[i].y == bullet.y-1  && enemis[i].x == bullet.x){
    enemis[i].y = 1;
 	ran_x = rand()%(20)+1; 	
 	enemis[i].x = ran_x;
 	enemis[i].ys = rand()%(2)+1;
 	s++;
 	
 	
 	
 	
 
} 	
 
}



   
  
  

bullet.y+= bullet.ys;

if(bullet.y <=1){
	shoot =0;
	bullet.ys =0;
	t[bullet.y+1][bullet.x] = ' ';

}

if(shoot){
  	t[bullet.y][bullet.x] = 248;
  	t[bullet.y+1][bullet.x] = ' ';
  	
  	
  }


for(i=0;i<N;i++){
	if(enemis[i].x == x){
		if(enemis[i].y == y-1)
		
		  lives--;
		  
	
}
	
	
}

 if(!lives){break;}

 SLEEP(5000);
 system("cls");


 
	
	
}
system("color c");
printf("\nYou Lose\n");
getchar();


free(t);

return 0;
}




void SLEEP(int time){
int c, d;
   
   for (c = 1; c <= time; c++)
       for (d = 1; d <= time; d++)
       {}

       
	
}
void CreateTable(char ***table,int h,int w){
	int i;
	*table = (char**)malloc(h*sizeof(char*));
	
	for(i=0;i<h;i++){
	  *(*table+i) = (char*)malloc(w*sizeof(char));
	}	
	
	
	
}

char keyInput(char**t,int *x,int *y){
char key;

if (kbhit()){
    key = getch();
    if(key == 'a'){
	  *x+=-1;
	  t[*y][(*x)+1] = ' ';
}
	if(key == 'd'){
		*x+=1;
		t[*y][(*x)-1] = ' ';   
}

	return key;
}
    return 0;
}



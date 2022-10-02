#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
int  CheckForWin();
void Drawboard();
void mark_board();
void Rules();
void score_board();
void final();
int t=1;
char p1[100],p2[100],temp[100];
int s1=0,s2=0;
char a[10]={'0','1','2','3','4','5','6','7','8','9'};
int main()
{ 
    system("color 3F");
    printf("\t\t\tTic-Tac-Toe\n\n\n");
    printf("\t\t\t----Player 1==X----\n\t\t\t----Player 2==O----\n\n\n");
    printf("\n\n\t\t ----NAME OF PLAYER 1 (____X____) ----\n\t\t ====> ");
    gets(p1);
    printf("\n\t\t ----NAME OF PLAYER 2 (____O____) ----\n\t\t ====> ");
    gets(p2);
    char yes[7];
    printf("==>  %s  ==  X\n==>  %s==  O\nDo you want to contiue with this or shall we exchange---- Press 'y' to change and 'n' to continue...",p1,p2);
    scanf("%s",&yes);
    if((yes[0]=='Y')||(yes[0]=='y'))
    {
     strcpy(temp,p1);
     strcpy(p1,p2);
     strcpy(p2,temp);	
    
	}
    printf("\n---- Do you want to know the RULES or need HELP?\n---- Press 'y' for yes and 'n' to continue...\n====> ");  
    char y[6];
    scanf("%s",&y);
    if((y[0]=='Y')||(y[0]=='y'))
    Rules();
    else
    system("cls"); 
    replay:
    for(t=1;t<=9;t++)
    {
	Drawboard();
	mark_board();
    CheckForWin();
    final();
  }
    
    if(s2-s1==2||s1-s2==2)
    printf("\t\t\t\n\n\n---END---");
    else
	{
	printf("\n---- Do you want to see your scores\n---- Press 'y' for yes and 'n' to continue...\n====> ");   
    scanf("%s",&y);
    if((y[0]=='Y')||(y[0]=='y'))
    {
     score_board();	
	}

	printf("\n---- Do you want to play again?\n---- Press 'y' for yes and 'n' to continue...\n====> ");   
    scanf("%s",&y);
    if((y[0]=='Y')||(y[0]=='y'))
    {
	system("cls");
	 int t=49;
	for(int i=1;i<=9;i++)
	{
	
	 a[i]=t;
	 t++;	
	}
    goto replay;
}
}
}

void Drawboard()
{ 
	printf("\t\t\tTic-Tac-Toe\n\n\n");
    
	printf("\n\t\t\t|\t|");
	printf("\n\t\t    %c   |   %c   |   %c   ",a[1],a[2],a[3]);
	printf("\n\t\t\t|\t|\t");
	printf("\n\t\t________|_______|_______");
	printf("\n\t\t\t|\t|");
	printf("\n\t\t    %c   |   %c   |   %c   ",a[4],a[5],a[6]);
	printf("\n\t\t\t|\t|\t");
	printf("\n\t\t________|_______|_______");
	printf("\n\t\t\t|\t|");
	printf("\n\t\t    %c   |   %c   |   %c   ",a[7],a[8],a[9]);
	printf("\n\t\t\t|\t|\t");
	printf("\n\t\t\t|\t|\t\n");
}
void mark_board()
{
  int n;
  h:
  	if(t%2!=0)
  	{
	  
  	puts(p1);
  	printf("||   X   ||");
    }
  	else
  	{
	puts(p2);
  	printf("||   O   ||");
   }
  printf(": ====> ");
  scanf("%d",&n);
    if(n>9||n<1||(a[n]=='O'||a[n]=='X'))
    {
    printf("Invalid move\n");
    goto h;
	}
	if(t!=9)
	system("cls");
    if(t%2==0)
    a[n]='O';
    else
    a[n]='X';
}
   int  CheckForWin()
   {
   if((a[1]=='X'&&a[2]=='X'&&a[3]=='X')||(a[4]=='X'&&a[5]=='X'&&a[6]=='X')||(a[7]=='X'&&a[8]=='X'&&a[9]=='X')||
       (a[1]=='X'&&a[4]=='X'&&a[7]=='X')||(a[2]=='X'&&a[5]=='X'&&a[8]=='X')||(a[3]=='X'&&a[6]=='X'&&a[9]=='X')||
       (a[1]=='X'&&a[5]=='X'&&a[9]=='X')||(a[3]=='X'&&a[5]=='X'&&a[7]=='X'))
	   {
   	
	   system("cls");	
	   Drawboard();
	   printf("------%s won--------",p1);
	   t=9;
       ++s1;
      }
      else if
	  ((a[1]=='O'&&a[2]=='O'&&a[3]=='O')||(a[4]=='O'&&a[5]=='O'&&a[6]=='O')||(a[7]=='O'&&a[8]=='O'&&a[9]=='O')||
       (a[1]=='O'&&a[4]=='O'&&a[7]=='O')||(a[2]=='O'&&a[5]=='O'&&a[8]=='O')||(a[3]=='O'&&a[6]=='O'&&a[9]=='O')||
       (a[1]=='O'&&a[5]=='O'&&a[9]=='O')||(a[3]=='O'&&a[5]=='O'&&a[7]=='O'))
	   {
	   	system("cls");
	    Drawboard();
   	    printf("------%s won-------",p2);
   	    t=9;
   	    ++s2;
      }
  
   
   else if (t==9)
	{
	{
	system("cls");
	Drawboard();
	printf("------DRAW-------");
    }   
}
}
void Rules()
{
system("cls");
printf("\n\t\t\t----RULES----\n[1] Each player take their turns to put their marks in empty squares \n    by pressing the number they want to put them in.\n");
printf("\n[2] The first player to get 3 of her marks in a row (up, down, across, or \n    diagonally) is the winner.\n");
printf("\n[3] When all 9 squares are full, the game is over. If no player has 3 marks\n    in a row, the game ends in a tie a.k.a Draw.\n\n");
}
void score_board()
{
	system("cls");
	printf("\n\t\t\t -----SCORES-----");
	printf("\n\t\t\t%s's score is %d\n",p1,s1);
	printf("\n\n\t\t\t%s's score is %d\n",p2,s2);
	
}
void final()
{
	if (s1-s2==2||s2-s1==2)
	{
	if(s1>s2)
	printf("\n---Congratulations!!!! hey %s well done, wowww you WON",p1);
	if(s2>s1)
	printf("\n---tCongratulations!!!! %s well done, wowww you WON",p2);	
	}
}

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include<time.h>
#define bool int/*use bool*/
#define true 1      
#define false 0 /*define the value of right and wrong*/       
FILE *fp;/*define a pointer*/         
bool judge=true;/*define bool*/

typedef struct/*make a struct*/
{
    char user[20];
    char code[20];
    int s;
}Users;
Users c;

int main()
{ 
start();
}

int start()
{
char a;
printf("###########################################################################\n");
printf("#                                                                         #\n");
printf("#                      Rock-Paper-Scissors Simulation                     #\n");
printf("#                                                                         #\n");
printf("#                                                                         #\n");
printf("#                  THE MOST BORING GAME YOU HAVE PLAYED !!!               #\n");
printf("#                                                                         #\n");
printf("#                                                                         #\n");
printf("#                  THE MOST BORING GAME YOU HAVE PLAYED !!!               #\n");
printf("#                                                                         #\n");
printf("#                                                                         #\n");
printf("#                  THE MOST BORING GAME YOU HAVE PLAYED !!!               #\n");
printf("#                                                                         #\n");
printf("#                                                                         #\n");
printf("#                  THE MOST BORING GAME YOU HAVE PLAYED !!!               #\n");
printf("#                                                                         #\n");
printf("#                                                                         #\n");
printf("#                               A: Login                                  #\n");
printf("#                                                                         #\n");
printf("#                                                                         #\n");
printf("#                               B:Register                                #\n");
printf("#                                                                         #\n");
printf("#                   pass any another key to quit the game.                #\n");
printf("###########################################################################\n");
a=getchar();/*get the char from user*/
if (a=='a')
 Login();
else if (a=='b')/*get the char from user*/
 Register();
else
 exit(0); 
}

int Register()
{
char t[20];
    do
    {system("cls");        
     printf("\n##################User registration##################");
     printf("\n#                     *User name:                   #\n");
     scanf("%s",c.user);/*get the char from user*/
     fp=fopen(c.user,"r");/*open the local file*/
     if(fp!=NULL)/*check the username is already registered or not*/
        {
     printf("\n!!!This user already exists!!!");
     fclose(fp);
     printf("\n#################continue to register?#################");
	 printf("\n#           pass Y to continue registration           #");
     if(getch()=='Y') return Register();/*get the char from user*/
     else return Login();
        }
     printf("\n                   *Password:                          \n");
     scanf("%s",c.code);/*get the char from user*/
     printf("\n                 *confirm password:                    \n");
     scanf("%s",t);/*get the char from the local file*/
     if(strcmp(c.code,t)!=0)/**/
     printf("\n#The passwords are inconsistent twice, please re-enter#");
    }
	while(strcmp(c.code,t)!=0);
    fp=fopen(c.user,"w");/*clean the data*/
    if(fp==NULL)
       {
          printf("\n!!!registration failed!!!");
          exit(0);
       }
    else
       {    
        system("cls");
        printf("\n*registration successful!");
        writein();           
        judge = false;
        Login();
        }

}
int writein()
   {
    if(fwrite(&c,sizeof(c),1,fp)!=1)
    {
        printf("\n\t\tWrite file error");
        exit(0);     
    }
   }	
Login()
{
char u[20],p[20],t[20];
system("cls");      
printf("\n##################User login##################");
printf("\n#                    User:                   #\n");
scanf("%s",u);/*get the char from user*/
fp=fopen(u,"r+");
t[0]='0';
if(fp==NULL)/*check the username is registered or not*/
 {   
  printf("\n*User does not exist, please register.*");
  printf("\n*       1.register   2.re-login       *");
  t[0]=getch();/*get the char from user*/
  if(t[0]=='1')
    {    
     system("cls");
     Register();
    }   
    else return Login();
  }  
	do
      {    
       if(judge==true) fread(&c,sizeof(Users),1,fp); 
        printf("\npassword:\n");
        scanf("%s",p);/*get the char from user*/
		printf("Loading...\n");
		Sleep(1500);
        if(strcmp(c.code,p)!=0)/*check the password is right or not*/
		{
           printf("\n*******!!!Woring Password!!!*******");
		   printf("#         1.quit   2.re-enter       #");
           t[0]=getch();
           printf("\n");
           if(t[0]=='1')/*back to the start interface*/
             { 
			  fclose(fp);
              return start();
     	 	 }
		   else Login();	  
        }      
        menu();
      }while(t[0]=='2');
}

computer(f)/*first subroutine*/
{
printf("computer select %d\n",f);/*hint the player what the computer chose*/
  if(f==1)/*chose stone*/
   {
   stone();
   }
 if(f==2)/*chose scissors*/
   {
   scissors();
   }
 if(f==3)/*chose paper*/
   {
   paper();
   } 
}
scissors()/*print the image of scissors on the screen*/
{
printf("##         ##\n");
printf(" ##       ##\n");
printf("  ##     ##\n" );
printf("   ##   ##  \n");
printf("    ## ##   \n");
printf("     ####   \n");
printf("    #####   \n ");
printf("   ### ###  \n ");
printf("  #### ####  \n");
printf(" ####   #### \n");
}

stone()/*print the image of stone on the screen*/
{
printf(" ## ##  ## ## \n");
printf("############# \n");
printf("############## \n");
printf("################ \n");
printf("################ \n");
printf("############### \n");
printf("############## \n");
}

paper()/*print the image of paper on the screen*/
{
printf("############ \n");
printf("#          # \n");
printf("#          # \n");
printf("#          # \n");
printf("#          # \n");
printf("#          # \n");
printf("#          # \n");
printf("############ \n");
}

game()
{   
char f=0,g=0,e=0,c=0,w,s=0;int a=0,b,i,v=0,j,t=0,x=0,u=0,k,h=0,l,d=0,m,n,o,p,q,r=0;
FILE *Data=fopen("data.txt","a");
if(Data==NULL)
  {
return 0;
  }
 fclose(Data);
 system("cls");
 printf("Welcome to the RPSS system\n");/*let the player enter the playname*/
 Sleep(1000);
 srand(time(0));
 x=rand()%(999-100+1)+100;
 printf("User ID:%d\n",x);
 Sleep(500);
 printf("Have a good game!");
 Sleep(1000);
 system("cls");
 printf("Please enter the number of the games you want to play...\n");
 scanf("%s",&a);/*ensure how many games the player want to play*/
 s=a+s;
 printf("We are goning to play %s games\n",&a);
 printf("Game will start in 3 seconds!");/*hint the player ready to play the game*/
 Sleep(3000);/*pause the system 3 seconds*/
 printf("\nThe Game Rules:\n1-paper\n2-scissors\n3-stone\nPlease select your choice:\n");/*print out the rules of the game*/


 while (d<=(a-49))
 {

 printf("Player select:");/*hint the player to enter the order*/
 scanf("%d",&e);/*input the order*/
 if(e==1)/*print out the image of stone*/
   {
   stone();
   }
 if(e==2)/*print out the image of scissors*/
   {
   scissors();
   }
 if(e==3)/*print out the image of paper*/
   {
   paper();
   }    

 srand(time(0));/*generating a random number*/
 f=rand()%3+1;/*generating a random number*/
 computer(f);/*turn to the subroutine-computer()*/
   if((e==1)&(f==2))/*judge the game's result(the next three are the same)*/	      	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  
   {
   printf("player win.\n");
   h++;/*player win h increase*/
   t++;
   }
   if((e==2)&(f==3))	       	   	   	   	   	   	   	   	   	   	   	   	   	   	   
   {
   printf("player win.\n");
   h++;
   t++;
   }
   if((e==3)&(f==1))	       	   	   	   	   	   	   	   	   	   	   	   	   	   	   	  
   {
   printf("player win.\n");
   h++;
   t++;
   }	      	      	       	    																	
   if((e==1)&(f==1))/*judge the game's result(the next three are the same)*/	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	  
   {printf("Tie.\n");
   d--;/*tie does not count in the effective game*/
   u++;
   }
   if((e==2)&(f==2))	  	  	  	  	  	  	  	  	  	  	  	  	  	  	 
   {printf("Tie.\n");
   d--;
   u++;
   }
   if((e==3)&(f==3))	  	  	  	  	  	  	  	  	  	  	  	  	  	  	 
   {printf("Tie.\n");
   d--;
   u++;
   }
 if((e==1)&(f==3))	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   
   {printf("computer win.\n");/*judge the game's result(the next three are the same)*/
   h--;/*computer win h decrease*/
   v++;
   }
 if ((e==2)&(f==1))	     	 	 	 	 	 	 	 	 	 	 	 	 	 
   {printf("computer win.\n");
   h--;
   v++;
   }
 if ((e==3)&(f==2))	     	 	 	 	 	 	 	 	 	 	 	 	 	 
   {printf("computer win.\n");
   h--;
   v++;
   }
printf("Next game:\n");
  d++;
 }
if(h>0)/*judge the game's final result*/
   {
   printf("player get the final win.\n");
   
   } 
else
   printf("computer get the final win.\n");
 fp=fopen("data.txt","a");
 fprintf(Data,"%c\t",s);
 fclose(Data);
 fopen("data.txt","a");
 fprintf(Data,"%d\t",t);
 fclose(Data);
 fopen("data.txt","a");
 fprintf(Data,"%d\t",u);
 fclose(Data);
 fopen("data.txt","a");
 fprintf(Data,"%d\t",v);
 fclose(Data);
 fopen("data.txt","a");
  if(t>v)
 {
 fprintf(Data,"Win\n",w);
 }
 else
 fprintf(Data,"Lose\n",w);/*input the game data*/
 fclose(Data);
 printf("Whether to continue the game?(Y/N)");
 if(getch()=='Y') return game();
     else return menu();
 }

menu()
{
char ch; int y=0;
FILE *Data;
system("cls");
printf("####################################################\n");
printf("#                      M E N U                     #\n");
printf("#                                                  #\n");
printf("#                                                  #\n");
printf("#                                                  #\n");
printf("#                                                  #\n");
printf("#                                                  #\n");
printf("#                  1.Game Start                    #\n");
printf("#                                                  #\n");
printf("#                  2.History                       #\n");
printf("#                                                  #\n");
printf("#                  3.Clear history                 #\n");
printf("#                                                  #\n");
printf("#                  4.sign out                      #\n");
printf("#                                                  #\n");
printf("#                                                  #\n");
printf("####################################################\n");
scanf("%d",&y);/*get the char from user*/
if(y==1) 
  {
  return game();
  }
if(y==2) 
  {
  T2();
  }
if(y==3)
  {
  T3();
  }
  else return menu();
if(y==4);
  {
  system("cls");
  return start();/*make the menu function*/
  }
}

T3()/*clean the data*/
{
FILE *Data=fopen("data.txt","a");
if(Data==NULL)
  {
return 0;
  }
 fclose(Data);
system("cls");
  fopen("data.txt","w");
  fclose(Data);
  printf("Game data has been cleared!");
  Sleep(1500);
  printf("pass 'E' to back to menu.");
   system("pause");
  if(getch()=='E')
  return start();
}

T2()/*output the local data*/
 {
 char ch;
 FILE *Data=fopen("data.txt","a");
if(Data==NULL)
  {
return 0;
  }
 fclose(Data);
 system("cls");
  Data=fopen("data.txt","r");
  printf("round of game:  wins:   lose:   winning rate:\n");
  ch=fgetc(Data);
  while(ch!=EOF)
   {
    putchar(ch);
	ch=fgetc(Data);
   }
 fclose(Data);
 printf("pass 'E' to back to menu.");
 system("pause");
 if(getch()=='E')
 return menu();
 }


/*
Name: Assignment 3 Name: 1719177.c
Copyright: Free
Author: Yu-Cheng.Lin
Description: Users can create accounts.(Account contains user name, password and game history ) 
Play a Game with computer. The Game called Paper-Scissor-Rock
*/
#include <stdio.h>                                    /* include standard library stdio.h for use of scanf() and printf() */
#include <string.h>                                   /* include standard library stdlib.h for use of Sleep() */
#include <conio.h>                                    /* include standard library stdlib.h for use of system() */
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include<time.h>
#define bool int                                      /*Use bool*/
#define true 1      
#define false 0                                       /*Define the value of right and wrong*/       
FILE *account;                                        /*Define a pointer*/
bool judge = true;                                    /*Define bool*/

typedef struct                                        /*Make a struct*/
{
	char user[20];                                    /*Define user*/
	char code[20];                                    /*Define code*/           
	int s;                                            /*Define variables*/
}Users;
Users c;

int main()
{
	Start();
}

int Start()
{
	char a;
	system("cls");
	printf("##################################=-###########################################-=###############################################\n");
	printf("||                                                                                                                            ||\n");
	printf("||                                   -Congratulations, you have entered a game!!!-                                            ||\n");
	printf("||                                                                                                                            ||\n");
	printf("||                  **                        * *                 * *                                                         ||\n");
	printf("||            **   *  *   **                 *    *             *    *                                                        ||\n");
	printf("||           *  *  *  *  *  *                 *    *           *    *                           *   *                         ||\n");
	printf("||           *  *  *  *  *  *                  *    *         *    *                    *   * *       * *   *                 ||\n");
	printf("||           *  *  *  *  *  *  **               *    *       *    *                   *                       * *  *          ||\n");
	printf("||           *  *  *  *  *  * *  *               *    *     *    *                    *                              *        ||\n");
	printf("||           *  *  *  *  *  * *  *                *    *   *    *                     *                              *        ||\n");
	printf("||           *  *  *  *  *  * *  *                 *    * *      * *                  *       *       *       *      *        ||\n");
	printf("||     **    *   **    **    *   *                 *          *      *              * *       *       *       *      *        ||\n");
	printf("||     *  *  *                   *                *  * *     *      *  *          *   *       *       *       *      *        ||\n");
	printf("||     *   * *                   *                 *     *  *      *    *        *    *       *       *       *      *        ||\n");
	printf("||      *    *                   *               *       *  *    *      *       *      *      *       *       * *  *          ||\n");
	printf("||       *                       *              *       *    * *      *           *      *  * *       * *   * *               ||\n");
	printf("||         *                    *               *      *       *    *               *           * * *                         ||\n");
	printf("||           *                 *                  *             * *                   *      *                                ||\n");
	printf("||             *  * * * * *  *                      * * *  *  * *                        *                                    ||\n");
	printf("||                                                Paper-Scissor-Rock                                                          ||\n");
	printf("||                                                                                                                            ||\n");
	printf("||                                                =>   A: Login                                                               ||\n");
	printf("||                                                                                                                            ||\n");
	printf("||                                                =>  B: Register                                                             ||\n");
	printf("||                                                                                                                            ||\n");
	printf("||                                    (pass any another key to exit the game)                                                 ||\n");
	printf("##################################=-###########################################-=###############################################\n");
	a = getch();                                    /*Get the char from user*/
	if (a == 'A')
		Login();
	else if (a == 'B')                              /*Get the char from user*/
		Register();
	else
		exit(0);
}

int Register()
{
	char Up[20];                                      /*Define a username and password to store keyboard input*/
	do
	{
		system("cls");
		printf("\n");
		printf("###############=-User registration-=################\n");
		printf("=> User name: ");
		scanf("%s", c.user);                          /*Get the char from user*/
		account = fopen(c.user, "r");                 /*Open the local file*/
		if (account != NULL)                          /*Check the username is already registered or not*/
		{
			printf("\n");
			printf(" -Sorry, this user already exists!!!-\n");
			fclose(account);
			printf("###############=-Do you want to re-register?-=################\n");
			Sleep(1000);
			printf("        ||                                         ||         \n");
			printf("#          -pass Y to continue registration-                 #\n");
			printf("        ||                                         ||         \n");
			printf("#     -pass any another key to return to the Login-          #\n");
			if (getch() == 'Y')
				return Register();                    /*Get the char from user*/
			else
				return Login();
		}
		printf("=> Password: ");
		scanf("%s", c.code);                          /*Get the char from user*/
		printf("\n");
		printf("=> confirm password: ");
		scanf("%s", Up);                              /*Get the char from the local file*/
		if (strcmp(c.code, Up) != 0)                  /*Confirm whether the two password inputs are the same*/
		{
			printf("\n");
			printf("- The passwords are inconsistent twice, please re-enter -");
			Sleep(2000);
		}
	} while (strcmp(c.code, Up) != 0);
			account = fopen(c.user, "w");             /*clean the data*/
			if (account == NULL)
			{
				printf("\n");
				printf(" -Sorry, registration failed!!!- ");
				Sleep(3000);
				exit(0);
			}
			else
			{
				system("cls");
				printf("\n");
				printf(" -Registration successful!!!- ");
				Sleep(3000);
				writein();
				judge = false;
				Login();
			}
}

int writein()
{
	if (fwrite(&c, sizeof(c), 1, account) != 1)              /*Write error exits the program*/
	{
		printf("\n");
		printf(" -Write file error- ");
		exit(0);
	}
}

int Login()
{
	char U[20], p[20], Up[20];
	system("cls");
	printf("\n");
	printf("###############=-User login-=################\n");
	printf("=> User: ");
	scanf("%s", U);                                           /*get the char from user*/
	account = fopen(U, "r+");                                 /*Determine whether the user name exists*/
	Up[0] = '0';
	if (account == NULL)                                      /*check the username is registered or not*/
	{
		printf("\n");
		printf(" -Sorry, this user does not exist, please register- \n");
		Sleep(1000);
		printf("            ||                        ||              \n");
		printf("      => 1. Register          => 2. Re-login          \n");
		printf("            ||                        ||              \n");
		printf("#   -pass any another key to return to the Start-    #\n");
		Up[0] = getch();                                       /*get the char from user*/
		if (Up[0] == '1')
		{
			system("cls");
			Register();
		}
		if (Up[0] == '2')                                 /*Get the char from user*/
		{
			system("cls");
			Login();
		}
		  else
			return Start();
	}
	do                                                         /*Verify that the password is correct*/
	{
		if (judge == true) fread(&c, sizeof(Users), 1, account);
		printf("\n");
		printf("=> password: ");
		scanf("%s", p);                                         /*get the char from user*/
		printf("-                  Loading...                    -\n");
		Sleep(1500);
		if (strcmp(c.code, p) != 0)                             /*check the password is right or not*/
		{
			printf("\n");
			printf("                -!!!Woring Password!!!-                 \n");
			Sleep(1000);
			printf("                   ||              ||                   \n");
			printf("#             => 1. Re-login    => 2. Quit             #\n");
			printf("#    -pass any another key to return to the Start-     #\n");
			Up[0] = getch();
			if (Up[0] == '1')
			{
				system("cls");
				Login();
			}
			else
			{
				system("cls");
				fclose(account);                                      /*Close the file to prevent incorrect operation*/
				 Start();
			}
		}
		menu();
	} while (Up[0] == '1');
}

int Game()
{
	int NPC, t, r = 0, w = 0, l = 0, d = 0, W=0, L=0, D=0,G=0;                        /*Define structure*/
	char choice, user[20];
	FILE *Data = fopen("data.txt", "a");
	if (Data == NULL)
	{
		return 0;
	}
	fclose(Data);
	system("cls");
	G++;
	printf("  Congratulations, you have entered a game!!!  \n");
	Sleep(2000);
	printf("           Try defeat me!!!                \n");
	Sleep(2000);
	printf(" Please enter the number of times you want to play: ");                     /*ask user to input the number of times*/
	while (scanf("%d", &t) != 1)                                                       /*If the number is invalid, please enter a new input number until the valid value is entered. */
	{
		fflush(stdin);
		printf("\n Please enter again the number of times you want to play: ");
	}
	printf("           Good Luck          \n");
	printf("       -Press the pause-      \n");                                       /*ask user to press the pause*/
	system("pause");
	system("cls");                                                                    /*Clear anything that has been printed in the output window*/
	printf("We will see who wins more and who wins!!\n");
	Sleep(2000);
	printf("*Note that a draw is counted*");
	Sleep(5000);
	system("cls");                                                                    /*Clear anything that has been printed in the output window*/
	for (;;)                                                                                                      /*The Round of Paper-Scissor-Rock*/
	{
		printf("you %d / computer %d/ dogfall %d\n", w, l, d);                                                                   /*Score*/
		if (w + l + d != t)
		{
			r++;
			printf("     Round %d     \n", r);                                                                    /*The second round*/
			printf("Commands: P=Paper, S=Scissor, R=Rock, L=Surrender\n");                                        /*ask user to have four choices*/
			printf("Please make your choice: ");                                                                  /*ask user to input a choice*/
			while (!(scanf("%s", &choice) && choice == 'P' || choice == 'S' || choice == 'R' || choice == 'L'))   /*If the choice is invalid, please enter a new input choice until the valid value is entered. */
			{
				printf("Please make your choice: ");
				fflush(stdin);                                                                                    /*clear the input buffer ready for the next character*/
			}                                                                                                     /*End of while*/
			switch (choice)
			{
	        case 'P':printf("                 **                    \n");
				printf("           **   *  *   **              \n");
				printf("          *  *  *  *  *  *             \n");
				printf("          *  *  *  *  *  *             \n");
				printf("          *  *  *  *  *  *  **         \n");
				printf("          *  *  *  *  *  * *  *        \n");
				printf("          *  *  *  *  *  * *  *        \n");
				printf("          *  *  *  *  *  * *  *        \n");
				printf("    **    *   **    **    *   *        \n");
				printf("    *  *  *                   *        \n");
				printf("    *   * *                   *        \n");
				printf("     *    *                   *        \n");
				printf("      *                       *        \n");
				printf("        *                    *         \n");
				printf("          *                 *          \n");
				printf("            *  * * * * *  *            \n");
				break;
			case 'S':printf("     * *                 * *           \n");
				printf("    *    *             *    *          \n");
				printf("     *    *           *    *           \n");
				printf("      *    *         *    *            \n");
				printf("       *    *       *    *             \n");
				printf("        *    *     *    *              \n");
				printf("         *    *   *    *               \n");
				printf("          *    * *      * *            \n");
				printf("           *          *      *         \n");
				printf("          *  * *     *      *  *       \n");
				printf("           *     *  *      *    *      \n");
				printf("         *       *  *    *      *      \n");
				printf("        *       *    * *      *        \n");
				printf("        *      *       *    *          \n");
				printf("          *             * *            \n");
				printf("            * * *  *  * *              \n");
				break;
			case 'R':printf("                                  \n");
				printf("                                       \n");
				printf("                 *   *                 \n");
				printf("         *   * *       * *   *         \n");
				printf("       *                       * *  *  \n");
				printf("       *                              *\n");
				printf("       *                              *\n");
				printf("       *       *       *       *      *\n");
				printf("     * *       *       *       *      *\n");
				printf("   *   *       *       *       *      *\n");
				printf("  *    *       *       *       *      *\n");
				printf(" *      *      *       *       * *  *  \n");
				printf("   *      *  * *       * *   * *       \n");
				printf("     *           * * *                 \n");
				printf("       *      *                        \n");
				printf("          *                            \n");
				break;
			case 'L':
				Sleep(1000);
				system("cls");
				printf("I'm very disappointed. You are Loser!!!\n");
				Sleep(2000);
				L++;
				account = fopen("data.txt", "a");
				fprintf(Data, "%d\t", L);
				fprintf(Data, "Lose\n", L);
				fclose(Data);
				return menu();
			default: printf("Commands: P=Paper, S=Scissor, R=Rock, L=Surrender\n");
				break;
			}

			printf("This is my choice!!!\n");                                                      /*NPC's choice*/
			srand((unsigned)time(NULL));
			NPC = rand() % 3;
			switch (NPC)
			{
			case 0:printf("                 **                    \n");
				printf("           **   *  *   **              \n");
				printf("          *  *  *  *  *  *             \n");
				printf("          *  *  *  *  *  *             \n");
				printf("          *  *  *  *  *  *  **         \n");
				printf("          *  *  *  *  *  * *  *        \n");
				printf("          *  *  *  *  *  * *  *        \n");
				printf("          *  *  *  *  *  * *  *        \n");
				printf("    **    *   **    **    *   *        \n");
				printf("    *  *  *                   *        \n");
				printf("    *   * *                   *        \n");
				printf("     *    *                   *        \n");
				printf("      *                       *        \n");
				printf("        *                    *         \n");
				printf("          *                 *          \n");
				printf("            *  * * * * *  *            \n");
				break;
			case 1:printf("     * *                 * *           \n");
				printf("    *    *             *    *          \n");
				printf("     *    *           *    *           \n");
				printf("      *    *         *    *            \n");
				printf("       *    *       *    *             \n");
				printf("        *    *     *    *              \n");
				printf("         *    *   *    *               \n");
				printf("          *    * *      * *            \n");
				printf("           *          *      *         \n");
				printf("          *  * *     *      *  *       \n");
				printf("           *     *  *      *    *      \n");
				printf("         *       *  *    *      *      \n");
				printf("        *       *    * *      *        \n");
				printf("        *      *       *    *          \n");
				printf("          *             * *            \n");
				printf("            * * *  *  * *              \n");
				break;
			case 2:printf("                                    \n");
				printf("                                       \n");
				printf("                 *   *                 \n");
				printf("         *   * *       * *   *         \n");
				printf("       *                       * *  *  \n");
				printf("       *                              *\n");
				printf("       *                              *\n");
				printf("       *       *       *       *      *\n");
				printf("     * *       *       *       *      *\n");
				printf("   *   *       *       *       *      *\n");
				printf("  *    *       *       *       *      *\n");
				printf(" *      *      *       *       * *  *  \n");
				printf("   *      *  * *       * *   * *       \n");
				printf("     *           * * *                 \n");
				printf("       *      *                        \n");
				printf("          *                            \n");
				break;
			  }                                                                                            /*End of NPC's switch()*/
			if ((choice == 'P'&&NPC == 2) || (choice == 'S'&&NPC == 0) || (choice == 'R'&&NPC == 1))     /*Decide to win*/
			{
				printf("You are Win!!!\n");
				w++;
			}
			if ((choice == 'P'&&NPC == 1) || (choice == 'S'&&NPC == 2) || (choice == 'R'&&NPC == 0))     /*Decide to lose*/
			{
				printf("You are Lose!!!\n");
				l++;
			}
			if ((choice == 'P'&&NPC == 0) || (choice == 'S'&&NPC == 1) || (choice == 'R'&&NPC == 2))     /*Decide to draw*/
			{
				printf("Oh, a draw!\n");
				d++;
			}
			Sleep(3000);
			system("cls");                                                                               /*Clear anything that has been printed in the output window*/
		}
		else
			break;
	}                                                                                                   /*End of for()*/
	if (w > l)                                                                                            /*Expression result of the win*/
	{
		printf("Oh no...you defeat me!!! Now,you can leave \n");
		W++;
	}
	if (l > w)                                                                                            /*Expression result of the lose*/
	{
		printf("Sorry,you can not defeat me...Go out!!\n");
		L++;
	}
	if (w == l)                                                                                         /*Expression result of the draw*/
	{
		printf("A draw??waste my time...\n");
		D++;
	}
	account = fopen("data.txt", "a");
	fprintf(Data, "%d\t", G);
	fprintf(Data, "%d\t", r);
	fprintf(Data, "%d\t", w);
	fprintf(Data, "%d\t", l);
	fprintf(Data, "%d\t", d);
	fclose(Data);
	fopen("data.txt", "a");
	if (w>l)
		fprintf(Data, "Win\n", W);
	if (w < l)
		fprintf(Data, "Lose\n", L);                         /*input the game data*/
	if (w == l)
		fprintf(Data, "Draw\n", D);
	fclose(Data);
	printf("  -Whether to continue the game?- \n");
	printf("        Y: Yes / N: No            \n");
	printf("       No => Return to Menu       \n");
	if (getch() == 'Y') 
		return Game();
	else 
		return menu();
}

int menu()                                                      /*make the menu function*/
{
	char ch; int b ;
	FILE *Data;
	system("cls");
	printf("#################=-#############-=####################\n");
	printf("||                    |     |                       ||\n");
	printf("||                  * M E N U *                     ||\n");
	printf("||                                                  ||\n");
	printf("||                                                  ||\n");
	printf("||                                                  ||\n");
	printf("||                                                  ||\n");
	printf("||               =>  1.Game Start                   ||\n");
	printf("||                                                  ||\n");
	printf("||                =>  2.History                     ||\n");
	printf("||                                                  ||\n");
	printf("||                =>  3.sign out                    ||\n");
	printf("||                                                  ||\n");
	printf("||                                                  ||\n");
	printf("#################=-#############-=####################\n");
	printf("\n");
	printf("=> Please make a choice: ");
	scanf("%d", &b);
	switch (b)
	{
	case 1:return Game();
	case 2: History();
	case 3: return Start();
	default:
	  {
			   printf("                 Please enter again                 ");
			   Sleep(3000);
			   return menu();
	  }
	}
}                                          

int History()                                                 /*Game record*/
{
	char ch; int c;
	system("cls");
	printf("\n");
	printf("###################################=-#############-=####################################\n");
	printf("||                                    |         |                                     ||\n");
	printf("||                                 * H i s t o r y *                                  ||\n");
	printf("||                                                                                    ||\n");
	printf("||                                                                                    ||\n");
	printf("||                                                                                    ||\n");
	printf("||     =>  1.View the total number and percentage of games won, lost and drawn        ||\n");
	printf("||                                                                                    ||\n");
	printf("||                              =>  2.Clear history                                   ||\n");
	printf("||                                                                                    ||\n");
	printf("||                              =>  3.Return to Menu                                  ||\n");
	printf("||                                                                                    ||\n");
	printf("||                                                                                    ||\n");
	printf("###################################=-#############-=####################################\n");
	printf("\n");
	printf("=> Please make a choice: ");
	scanf("%d", &c);
	switch (c)
	{
	case 1: 
		T1();
	case 2:
		T2();
	case 3:
		menu();
	default:
	  {
			   printf("\n                               -Please enter again-                               ");
			   Sleep(3000);
			   return menu();
	  }
	}
}

int T1()                                                      /*Watching Historical Records*/
{
	int D[100][6];
	char ch,i,j;
	FILE *Data = fopen("data.txt", "a");
	if (Data == NULL)
	{
		return 0;
	}
	fclose(Data);
	system("cls");
	Data = fopen("data.txt", "r");
	printf("Game    Round   Win    Lose    Draw    Result   \n");
	D[100][6] = fgetc(Data);
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 6; j++)
		{
			while (D[100][6] != EOF)
			{
				putchar(D[100][6]);
				D[100][6] = fgetc(Data);
			}
		}
	}
			fclose(Data);
			printf("\n    -pass 'pause' to back to menu-     ");
			system("pause");
				return History();
}

int T2()                                                         /*clean the data*/
{
	FILE *Data = fopen("data.txt", "a");
	if (Data == NULL)
	{
		return 0;
	}
	fclose(Data);
	system("cls");
	fopen("data.txt", "w");                                 /*Opening an existing file as a write is equivalent to clearing it*/
	fclose(Data);
	printf("\n");
	printf("   -All game data had been cleared!-   \n");
	Sleep(2000);
	printf("pass 'pause' to back to menu.");
	system("pause");
	return menu();
}
/*
Name: Assignment 2 Name: 1719177.c
Copyright: Free
Author: Yu-Cheng.Lin
Description: Play a Game with computer. The Game called Paper-Scissor-Rock 
*/
#include<stdio.h>                                           /* include standard library stdio.h for use of scanf() and printf() */
#include<windows.h>                                         /* include standard library stdlib.h for use of Sleep() */
#include<stdlib.h>                                          /* include standard library stdlib.h for use of system() */
#include<time.h> 

main()
{
	int NPC, t, r = 0, w = 0, l = 0,d=0;                        /*Define structure*/
	char name[100], choice;

	printf("Congratulations, you have entered a game!!!\n");
	Sleep(2000);                                           /*Stop two seconds*/
	printf("Please defeat me!!!\n");
	Sleep(2000);

	printf("                **                        * *                 * *                                                           \n");
	printf("          **   *  *   **                 *    *             *    *                                                          \n");
	printf("         *  *  *  *  *  *                 *    *           *    *                           *   *                           \n");
	printf("         *  *  *  *  *  *                  *    *         *    *                    *   * *       * *   *                   \n");
	printf("         *  *  *  *  *  *  **               *    *       *    *                   *                       * *  *            \n");
	printf("         *  *  *  *  *  * *  *               *    *     *    *                    *                              *          \n");
	printf("         *  *  *  *  *  * *  *                *    *   *    *                     *                              *          \n");
	printf("         *  *  *  *  *  * *  *                 *    * *      * *                  *       *       *       *      *          \n");
	printf("   **    *   **    **    *   *                 *          *      *              * *       *       *       *      *          \n");
	printf("   *  *  *                   *                *  * *     *      *  *          *   *       *       *       *      *          \n");
	printf("   *   * *                   *                 *     *  *      *    *        *    *       *       *       *      *          \n");
	printf("    *    *                   *               *       *  *    *      *       *      *      *       *       * *  *            \n");
	printf("     *                       *              *       *    * *      *           *      *  * *       * *   * *                 \n");
	printf("       *                    *               *      *       *    *               *           * * *                           \n");
	printf("         *                 *                  *             * *                   *      *                                  \n");
	printf("           *  * * * * *  *                      * * *  *  * *                        *                                      \n");
	printf("                                              Paper-Scissor-Rock                                                            \n");
	Sleep(2000);                                                                       /*The above is the introduction of the game. */
	printf("Player please enter your name: ");                                         /*ask user to input a name*/
	gets(name);
	Sleep(1000);
	printf("Please enter the number of times you want to play: ");                     /*ask user to input the number of times*/
	while (scanf("%d", &t) != 1)                                                       /*If the number is invalid, please enter a new input number until the valid value is entered. */
	{
		fflush(stdin);
		printf("Please enter again the number of times you want to play: ");
	}
	printf("           Good Luck          \n");
	printf("       -Press the pause-      \n");                                       /*ask user to press the pause*/
	system("pause");
	system("cls");                                                                    /*Clear anything that has been printed in the output window*/
	printf(name);
	printf(", the Game is starting.\n");
	Sleep(2000);
	printf("We will see who wins more and who wins!!\n");
	Sleep(2000);
	printf("*Note that a draw is counted*");
	Sleep(5000);
	system("cls");                                                                    /*Clear anything that has been printed in the output window*/

	for (;;)                                                                                                      /*The Round of Paper-Scissor-Rock*/
	{
		printf("you %d / computer %d/ dogfall %d\n", w, l,d);                                                                   /*Score*/
		if (w+l+d!=t)
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
			case 'P':printf("            **                    \n");
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
	       case 'S':printf(" * *                 * *           \n");
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
				return 0;
			default: printf("Commands: P=Paper, S=Scissor, R=Rock, L=Surrender\n");
				break;
			}                                                                                      /*End of player's switch()*/

			printf("This is my choice!!!\n");                                                      /*NPC's choice*/
			srand((unsigned)time(NULL));
			NPC = rand() % 3;
			switch (NPC)
			{
			case 0:printf("              **                    \n");
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
			case 1:printf("  * *                 * *           \n");
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
	if (w>l)                                                                                            /*Expression result of the win*/
		printf("Oh no...you defeat me!!! Now,you can leave \n");
	if (l>w)                                                                                            /*Expression result of the lose*/
		printf("Sorry,you can not defeat me...Go out!!\n");                                                     
	if (w == l)                                                                                         /*Expression result of the draw*/
		printf("A draw??waste my time...\n"); 
}


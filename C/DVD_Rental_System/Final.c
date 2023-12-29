#include<stdio.h>		                                /*C libraries used in this program */
#include<stdlib.h>
#include<windows.h>
#include<math.h>
#include<string.h>
void set();
void alter21();
void alter22();


struct dates                                            /*Declare structure type named titles to store variable*/
{
	char point1[999];
	char point2[999];
	char point3[999];
};
struct charge
{
	char price1[999];
	char price2[999];
	char price3[999];
	char price4[999];
};
struct titles                                           /*Declare structure type named titles to store variable*/
{
	char title[99];
	char information[99];
	char limits[99];
	char genre[99];
	char copies[999];
	char renttime[99];
	char rentyear[99];
	char rentmonth[99];
	char rentday[99];
};
struct customers
{
	char number[99];
	char name[99];
	char age[3];
	char telephone[21];
	char address[99];
	char pendingcharges[11];
	char history[99];
	char money[99];
	char returnyear[99];
	char returnmonth[99];
	char returnday[99];
};

void add(char*file);                                    /*A function to add a new file of titles*/
void edit(struct titles *movie, char*file);              /*A function to edit the titles*/
void delete(struct titles *movie, char*file);            /*A function to delete the contents of movies of the file*/
void add2(char*file2);
void edit2(struct customers *person, char*file2);
void delete2(struct customers *person, char*file2);
void list(char *file);                                  /*A function that lists the whole contents ofthe file*/
void list2(char *file2);                                /*A function that lists the whole contents ofthe file*/
void Delete();
void set(char*file21, char*file22);
void alter21(struct dates *point, char*file21);
void alter22(struct charge *price, char*file22);
void check(struct customers *person, char*file2);
void rent(struct titles *movie, char*file);
void returnn(struct titles *movie, char*file, struct customers *person, char*file2, struct dates *point, char*file21, struct charge *price, char*file22);

int main()
{
	int mark1 = 0, option, option1, option2, test1 = 0, test2, test3 = 0, choice, choice2, choice3;
	struct dates point;
	struct charge price;
	struct titles movie;
	struct customers person;
	FILE *fptr, *fptr2, *fptr21, *fptr22;                                                   /*Declare a file pointer*/
	char file[99999] = "movie.dat", file2[99999] = "customer.dat", file21[99999] = "point.dat", file22[99999] = "price.dat";               /*Declare an initialize a character array containing a filename*/
	fptr = fopen(file, "ab");
	fptr21 = fopen(file21, "ab");/*Try to open the file for writing or create the file if it doesn't exist - openmode is binary*/
	fptr22 = fopen(file22, "ab");                                               /*Try to open the file for writing or create the file if it doesn't exist - openmode is binary*/
	if (fptr == NULL)				                                     /*Test the success of opening the file, close the program if failed*/
	{
		printf("\nFailed opening the file, please restart the program\n");
		Sleep(2000);
		exit(0);
	}
	fclose(fptr);                                                        /*close the file*/
	fptr2 = fopen(file2, "ab");
	if (fptr2 == NULL)	 	 	 	                                     /*Test the success of opening the file, close the program if failed*/
	{
		printf("\nFailed opening the file, please restart the program\n");
		Sleep(2000);
		exit(0);
	}
	fclose(fptr2);
	if (fptr21 == NULL)				/*Test the success of opening the file, close the program if failed*/
	{
		printf("\nFailed opening the file, please restart the program\n");
		Sleep(2000);
		exit(0);
	}
	fclose(fptr21); /*close the file*/
	if (fptr22 == NULL)				/*Test the success of opening the file, close the program if failed*/
	{
		printf("\nFailed opening the file, please restart the program\n");
		Sleep(2000);
		exit(0);
	}
	fclose(fptr22); /*close the file*/	                                                /*close the file*/

	while (test1 == 0) 	 	 	                                          /*a while loop to keep the program running until the user selects option 3*/
	{
		Sleep(2000);
		system("cls");
		printf("please select from the following choices:\n\t1. Log in as a branch manager\n\t2. Log in as a rental desk worker.\n\t3. Exit the program\n");
		while (scanf("%d", &choice) != 1 || (choice < 1 || choice>3))		       /* Display menu and get user's choice and its validity*/
		{
			printf("Your choice is invalid\n");
			Sleep(2000);
			fflush(stdin);
			system("cls");
			printf("please select from the following choices:\n\t1. Log in as a branch manager\n\t2. Log in as a rental desk worker.\n\t3. Exit the program\n");
		}
		switch (choice) 	 	 	                                           /*perform selection to get user's choice*/
		{
		case 1:
			printf("Please select from the following choices:\n\t1. Add new titles and rental copies\n\t2. Edit titles and rental copies\n\t3. List title and rented copy\n\t4. Delete titles and rental copies\n\t5. Add new customers information\n\t6. Edit customers information\n\t7. Determine customer charges and penalties\n\t8. Delete customer information\n\t9. Set durations and charges\n\t10. Alter durations\n\t11. Alter charges\n\t12. Return\n");
			while (scanf("%d", &choice2) != 1 || (choice2 < 1 || choice2>11))	   /* Display menu and get user's choice and its validity*/
			{
				printf("Your choice is invalid\n");
				Sleep(2000);
				fflush(stdin);
				system("cls");
				printf("Please select from the following choices:\n\t1. Add new titles and rental copies\n\t2. Edit titles and rental copies\n\t3. List title and rented copy\n\t4. Delete titles and rental copies\n\t5. Add new customers information\n\t6. Edit customers information\n\t7. Determine customer charges and penalties\n\t8. Delete customer information\n\t9. Set durations and charges\n\t10. Alter durations\n\t11. Alter charges\n\t12. Return\n");
			}
			switch (choice2)
			{
			case 1:
				add(file);
				break;
			case 2:
				edit(&movie, file);
				break;
			case 3:
				list(file);
				break;
			case 4:
				delete(&movie, file);
				break;
			case 5:
				add2(file2);
				break;
			case 6:
				edit2(&person, file2);
				break;
			case 7:
				list2(file2);
				break;
			case 8:
				delete2(&person, file2);
				break;
			case 9:
				set(file21, file22);
				break;
            case 10:
                alter21(&point, file21);
				break;
			case 11:
				alter22(&price, file22);
				break;
			case 12:
				main();
				break;
			}
			break;
		case 2:
			printf("please select what you are going to do:\n\t1. Check whether the user exist\n\t2. Rent a DVD\n\t3. Return a DVD.\n\t4. Return\n");
			while (scanf("%d", &choice3) != 1 || (choice3 < 1 || choice3>4))		/* Display menu and get user's choice and its validity*/
			{
				printf("Your choice is invalid\n");
				Sleep(2000);
				fflush(stdin);
				system("cls");
				printf("please select what you are going to do:\n\t1. Check whether the user exist\n\t2. Rent a DVD\n\t3. Return a DVD.\n4. Return\n");
			}
			switch (choice3)/*perform selection to get user's choice*/
			{
			case 1:
				check(&person, file2);
				break;
			case 2:
				rent(&movie, file);
				break;
			case 3:
				returnn(&movie, file, &person, file2, &point, file21, &price, file22);
				break;
			case 4:
				main();
				break;
			}
			break;
		case 3:
			test1 = 1;
			break;

		}
	}
}
void add(char*file)
{
	struct titles movie;                                                /*declare a structure*/

	FILE *fptr;                                                     /*declare a file pointer*/
	fflush(stdin);
	system("cls");
	printf("Please input the title\n");
	while (scanf("%s", movie.title) == 0 || strlen(movie.title) > 100)
	{																/* checks the validity and the length of the string */
		printf("Please try again and make sure the username has no more than 100 characters");
		fflush(stdin);
		Sleep(2000);
		system("cls");
	}
	fflush(stdin);                                                  /*Ensure input buffer is empty*/
	printf("Please enter the information of the movie:\n\t");
	while (scanf("%s", movie.information) == 0 || strlen(movie.information) > 100)
	{																/* checks the validity and the length of the string */
		printf("Please try again and make sure the information has no more than 100 characters");
		fflush(stdin);
		Sleep(2000);
		system("cls");
	}
	fflush(stdin);
	printf("Please enter the age limits of the movie:\n\t");
	while (scanf("%s", movie.limits) == 0 || strlen(movie.limits) > 100)
	{																/* checks the validity and the length of the string */
		printf("Please try again and make sure the genre has no more than 100 characters");
		fflush(stdin);
		Sleep(2000);
		system("cls");
	}
	printf("Please enter the genre of the movie:\n\t");
	while (scanf("%s", movie.genre) == 0 || strlen(movie.genre) > 100)
	{																/* checks the validity and the length of the string */
		printf("Please try again and make sure the genre has no more than 100 characters");
		fflush(stdin);
		Sleep(2000);
		system("cls");
	}
	fflush(stdin);
	printf("Please enter the number of copies of the movie:\n\t");
	while (scanf("%s", movie.copies) == 0)
	{																/* checks the validity  of the string */
		printf("Please try again and make sure the validity  of the number");
		fflush(stdin);
		Sleep(2000);
		system("cls");
	}
	fflush(stdin);
	fptr = fopen(file, "a+b");                                         /*Try to open the file for writing or create the file if it doesn't exist in binary mode*/
	if (fptr == NULL) 		                                        /*Test the success of opening the file,close the program if fail*/
	{
		printf("\nFailed opening the file, please restart the program\n");
		Sleep(2000);
		exit(0);
	}
	else				                                             /*If successfully open the file, write the structure to the file*/
	{
		fwrite(&movie, sizeof(struct titles), 1, fptr);              /*write the structure to the file*/
	}
	fclose(fptr);                                                    /*close the file*/
}
void edit(struct titles *movie, char*file)
{

	FILE*fptr;                                                         /*declare a file pointer*/
	char edits[99];                                                    /*declare arrays to represent the user's input*/
	fflush(stdin);
	printf("Please input the title of movie which information you want to edit\n");
	while (scanf("%s", edits) == 0 || strlen(edits) > 100)              /*Test the validity of the input*/
	{
		printf("Please try again and make sure the title no more than 100 characters long\n");
		fflush(stdin);
		Sleep(2000);
		system("cls");
		printf("Please input the title of movie which information you want to edit\n");
	}
	fflush(stdin);
	fptr = fopen(file, "r+b");                                           /*Try to open the file for reading and writing or create the file if it doesn't exist in binary mode*/
	if (fptr == NULL)				                                  /*Test success of file opening*/
	{
		printf("\nFailed opening the file, please restart the program\n");
		Sleep(2000);
		exit(0);
	}
	else
	{
		while (fread(movie, sizeof(struct titles), 1, fptr) == 1 && (strcmp(movie->title, edits)))
		{
			continue;                                                /*continues the loop until the end of the file reached or the titles match*/
		}
	}
	if (strcmp(movie->title, edits))                                   /*test to see if the loop finished because the title has been found*/
	{
		printf("The title does not exist\n");
	}
	else
	{
		printf("The title has been found\n");
		fflush(stdin);
		Sleep(1000);
		system("cls");
		printf("The title is %s\nThe information:%s\nThe age limits:%s\n The genre:%s\n The number of copies:%s \n", movie->title, movie->information, movie->limits, movie->genre, movie->copies);
		fflush(stdin);
		Sleep(3000);
		system("cls");
		printf("Please input the new title\n");
		scanf("%s", &movie->title);
		printf("Please input the information\n");
		scanf("%s", &movie->information);
		printf("Please input the age limits\n");
		scanf("%s", &movie->limits);
		printf("Please input the genre\n");
		scanf("%s", &movie->genre);
		printf("Please input the number of copies\n");
		scanf("%s", &movie->copies);
		fflush(stdin);
		fseek(fptr, 0 , SEEK_SET);
		fwrite(movie, sizeof(struct titles), 1, fptr);
	}
	fclose(fptr);                                                      /*close the file*/
}
void delete(struct titles *movie, char*file)
{

	char sure[2];
	FILE*fptr;                                                   /*declare a file pointer*/
	char deletes[99];                                            /*declare arrays to represent the user's input*/
	fflush(stdin);
	printf("Please input the title of movie which information you want to delete\n");
	while (scanf("%s", deletes) == 0 || strlen(deletes) > 100)    /*Test the validity of the input*/
	{
		printf("Please try again and make sure the title no more than 100 characters long\n");
		fflush(stdin);
		Sleep(2000);
		system("cls");
		printf("Please input the title of movie which information you want to edit\n");
	}
	fflush(stdin);
	fptr = fopen(file, "r+b");                                      /*Try to open the file for reading and writing or create the file if it doesn't exist in binary mode*/
	if (fptr == NULL)			                               	 /*Test success of file opening*/
	{
		printf("\nFailed opening the file, please restart the program\n");
		Sleep(2000);
		exit(0);
	}
	else
	{
		while (fread(movie, sizeof(struct titles), 1, fptr) == 1 && (strcmp(movie->title, deletes)))
		{
			continue;                                            /*continues the loop until the end of the file reached or the titles match*/
		}
	}
	if (strcmp(movie->title, deletes))                           /*test to see if the loop finished because the title has been found*/
	{
		printf("The title does not exist\n");
	}
	else
	{
		printf("The title has been found\n");
		printf("Are you sure you want to delete the information of the movie?\n");
		printf("                      ( y / n )                              \n");
		scanf("%s", sure);
		if (strcmp(sure, "Y") == 0 || strcmp(sure, "y") == 0)
		{
			movie->title[99] = 0;
			movie->information[99] = 0;
			movie->limits[99] = 0;
			movie->genre[99] = 0;
			movie->copies[999] = 0;
			fseek(fptr, 0, SEEK_SET);
			fwrite(&movie, sizeof(struct titles), 1, fptr);
			printf("The information about the movie has been deleted\n");
		}
	}
	fclose(fptr);
}
void add2(char*file2)
{
	struct customers person;
	FILE *fptr2;                                                    /*declare a file pointer*/
	fflush(stdin);
	system("cls");
	printf("Please input the number\n");
	while (scanf("%s", person.number) == 0)
	{																/* checks the validity and the length of the string */
		printf("Please try again and make sure the number has no more than 100 characters");
		fflush(stdin);
		Sleep(2000);
		system("cls");
	}
	fflush(stdin);/*Ensure input buffer is empty*/
	printf("Please enter the name of the customer:\n\t");
	while (scanf("%s", person.name) == 0 || strlen(person.name) > 100)
	{																/* checks the validity and the length of the string */
		printf("Please try again and make sure the name has no more than 100 characters");
		fflush(stdin);
		Sleep(2000);
		system("cls");
	}
	fflush(stdin);
	printf("Please enter the age of the customer:\n\t");
	while (scanf("%s", person.age) == 0 || strlen(person.age) > 2)
	{																/* checks the validity and the length of the string */
		printf("Please try again and make sure the age has no more than 2 characters");
		fflush(stdin);
		Sleep(2000);
		system("cls");
	}
	printf("Please enter the telephone of the customer:\n\t");
	while (scanf("%s", person.telephone) == 0 || strlen(person.telephone) > 100)
	{																/* checks the validity and the length of the string */
		printf("Please try again and make sure the telephone has no more than 20 characters");
		fflush(stdin);
		Sleep(2000);
		system("cls");
	}
	fflush(stdin);
	printf("Please enter the address of the movie:\n\t");
	while (scanf("%s", person.address) == 0 || strlen(person.address) > 100)
	{																/* checks the validity  of the string */
		printf("Please try again and make sure the validity  of the address");
		fflush(stdin);
		Sleep(2000);
		system("cls");
	}
	fflush(stdin);
	fptr2 = fopen(file2, "a+b");                                    /*Try to open the file for writing or create the file if it doesn't exist in binary mode*/
	if (fptr2 == NULL) 	 	                                        /*Test the success of opening the file,close the program if fail*/
	{
		printf("\nFailed opening the file, please restart the program\n");
		Sleep(2000);
		exit(0);
	}
	else				                                             /*If successfully open the file, write the structure to the file*/
	{
		fwrite(&person, sizeof(struct customers), 1, fptr2);         /*write the structure to the file*/
	}
	fclose(fptr2);                                                   /*close the file*/
}
void edit2(struct customers *person, char*file2)
{

	FILE*fptr2;                                                  /*declare a file pointer*/
	char edits2[99];                                             /*declare arrays to represent the user's input*/
	fflush(stdin);
	printf("Please input the number of customer whose information you want to edit\n");
	while (scanf("%s", edits2) == 0 || strlen(edits2) > 100)      /*Test the validity of the input*/
	{
		printf("Please try again and make sure the number no more than 100 characters long\n");
		fflush(stdin);
		Sleep(2000);
		system("cls");
		printf("Please input the number of customer whose information you want to edit\n");
	}
	fflush(stdin);
	fptr2 = fopen(file2, "r+b");                                 /*Try to open the file for reading and writing or create the file if it doesn't exist in binary mode*/
	if (fptr2 == NULL)	 	 	                            	 /*Test success of file opening*/
	{
		printf("\nFailed opening the file, please restart the program\n");
		Sleep(2000);
		exit(0);
	}
	else
	{
		while (fread(person, sizeof(struct customers), 1, fptr2) == 1 && (strcmp(person->number, edits2)))
		{
			continue;                                            /*continues the loop until the end of the file reached or the number matches*/
		}
	}
	if (strcmp(person->number, edits2))                          /*test to see if the loop finished because the number has been found*/
	{
		printf("The customer does not exist\n");
	}
	else
	{
		printf("The customer has been found\n");
		fflush(stdin);
		Sleep(1000);
		system("cls");
		printf("The number is %s\nThe name is:%s\nThe age is:%s\n The telephone number:%s\n The address:%s\n", person->number, person->name, person->age, person->telephone, person->address);
		fflush(stdin);
		Sleep(3000);
		system("cls");
		printf("Please input the new number\n");
		scanf("%s", &person->number);
		printf("Please input the name\n");
		scanf("%s", &person->name);
		printf("Please input the age\n");
		scanf("%s", &person->age);
		printf("Please input the telephone\n");
		scanf("%s", &person->telephone);
		printf("Please input the address\n");
		scanf("%s", &person->address);
		fflush(stdin);
		fseek(fptr2, 0, SEEK_SET);
		fwrite(&person, sizeof(struct customers), 1, fptr2);

	}
	fclose(fptr2);                                               /*close the file*/
}
void delete2(struct customers *person, char*file2)
{

	char sure2[2];
	FILE*fptr2;                                                         /*declare a file pointer*/
	char deletes2[99];                                                  /*declare arrays to represent the user's input*/
	fflush(stdin);
	printf("Please input the number of customer whose information you want to delete\n");
	while (scanf("%s", deletes2) == 0 || strlen(deletes2) > 100)         /*Test the validity of the input*/
	{
		printf("Please try again and make sure the number no more than 100 characters long\n");
		fflush(stdin);
		Sleep(2000);
		system("cls");
		printf("Please input the number of customer whose information you want to edit\n");
	}
	fflush(stdin);
	fptr2 = fopen(file2, "r+b");                                        /*Try to open the file for reading and writing or create the file if it doesn't exist in binary mode*/
	if (fptr2 == NULL)	 	                              	 	        /*Test success of file opening*/
	{
		printf("\nFailed opening the file, please restart the program\n");
		Sleep(2000);
		exit(0);
	}
	else
	{
		while (fread(person, sizeof(struct customers), 1, fptr2) == 1 && (strcmp(person->number, deletes2)))
		{
			continue;                                                   /*continues the loop until the end of the file reached or the number matches*/
		}
	}
	if (strcmp(person->number, deletes2))                               /*test to see if the loop finished because the number has been found*/
	{
		printf("The person does not exist\n");
	}
	else
	{
		printf("The customer has been found\n");
		printf("Are you sure you want to delete the information of the customer?\n");
		printf("                        ( y / n )                               \n");
		scanf("%s", sure2);
		if (strcmp(sure2, "Y") == 0 || strcmp(sure2, "y") == 0)
		{
			person->number[99] = 0;
			person->name[99] = 0;
			person->age[3] = 0;
			person->telephone[21] = 0;
			person->address[99] = 0;
			fseek(fptr2, 0, SEEK_SET);
			fwrite(&person, sizeof(struct customers), 1, fptr2);
			printf("The information about the person has been deleted\n");
		}
	}
	fclose(fptr2);
}
void list(char*file)                                                        /*defined function list*/
{
	struct titles movie;                                                   /*declare a structure*/
	FILE*fptr;                                                              /*declare a file pointer*/
	fflush(stdin);
	system("cls");
	fptr = fopen(file, "r+b");                                              /*Try to open the file for writing or create the file if it doesn't exist - openmode is binary*/
	if (fptr == NULL)				                                        /*Test the success of opening the file, close the program if failed*/
	{
		printf("\nFailed opening the file, please restart the program\n");
		Sleep(2000);
		exit(0);
	}
	else                                                                   /*on successful opening of the file, read structures from file into the structure variable then print the values on the screen*/
	{
		while (fread(&movie, sizeof(struct titles), 1, fptr) == 1)	       /*while loop ends when reading the file returns the EOF marker value*/
		{
			printf("Title:\n => %s\n", movie.title);
			printf("Title information:\n => %s\n", movie.information);
			printf("Age limits:\n => %s\n", movie.limits);
			printf("Genre:\n => %s\n", movie.genre);
			printf("Copies:\n => %s\n\n", movie.copies);
		}
		printf("       -Press the pause-      \n");                                       /*ask user to press the pause*/
		system("pause");
	}
	fclose(fptr);                                                          /*close the file*/
}
void list2(char*file2)                                                         /*defined function list*/
{
	struct customers person;                                                   /*declare a structure*/
	FILE*fptr;                                                                 /*declare a file pointer*/
	fflush(stdin);
	system("cls");
	fptr = fopen(file2, "r+b");                                                /*Try to open the file for writing or create the file if it doesn't exist - openmode is binary*/
	if (fptr == NULL)				                                           /*Test the success of opening the file, close the program if failed*/
	{
		printf("\nFailed opening the file, please restart the program\n");
		Sleep(2000);
		exit(0);
	}
	else                                                                       /*on successful opening of the file, read structures from file into the structure variable then print the values on the screen*/
	{
		while (fread(&person, sizeof(struct customers), 1, fptr) == 1)	       /*while loop ends when reading the file returns the EOF marker value*/
		{
			printf("Number:\n => %s\n", person.number);
			printf("Name:\n => %s\n", person.name);

		}
		printf("       -Press the pause-      \n");                            /*ask user to press the pause*/
		system("pause");
	}
	fclose(fptr);                                                              /*close the file*/
}

void set(char*file21, char*file22)
{
	struct dates point;                                                        /*declare a structure*/
	struct charge price;                                                       /*declare a structure*/
	FILE *fptr21, *fptr22;                                                     /*declare a file pointer*/

	fflush(stdin);
	system("cls");

	printf("The charge standard is divided into 4 parts, so please input 3 critical points first.\n");
	printf("Please input the first critical point of the rental duration:\n");
	while (scanf("%s", &point.point1) != 1)
	{
		printf("\nPlease try again and make sure the fist critical point of the rental duration is a positive integer.\n");
		fflush(stdin);
		Sleep(2000);
		system("cls");
	}
	fflush(stdin);

	printf("Please input the second critical point of the rental duration:\n");
	while (scanf("%s", point.point2) != 1 )
	{
		printf("\nPlease try again and make sure the second critical point of the rental duration is a positive integer bigger than the first one.\n");
		fflush(stdin);
		Sleep(2000);
		system("cls");
	}
	fflush(stdin);

	printf("Please input the third critical point of the rental duration:\n");
	while (scanf("%s", point.point3) != 1 )
	{
		printf("\nPlease try again and make sure the third critical point of the rental duration is a positive integer bigger than the second one.\n");
		fflush(stdin);
		Sleep(2000);
		system("cls");
	}
	fflush(stdin);

	fptr21 = fopen(file21, "a+b");                                  /*Try to open the file for writing or create the file if it doesn't exist in binary mode*/
	if (fptr21 == NULL) 		                                 /*Test the success of opening the file,close the program if fail*/
	{
		printf("\nFailed opening the file, please restart the program\n");
		Sleep(2000);
		exit(0);
	}
	else		                                        		/*If successfully open the file, write the structure to the file*/
	{
		fwrite(&point, sizeof(struct dates), 1, fptr21);        /*write the structure to the file*/
	}
	fclose(fptr21);                                             /*close the file*/

	printf("Please input the price in the first interval:\n");
	while (scanf("%s", price.price1) != 1)
	{
		printf("\nPlease try again and make sure the charge1 is bigger than 0.\n");
		fflush(stdin);
		Sleep(2000);
		system("cls");
	}
	fflush(stdin);

	printf("Please input the price in the second interval:\n");
	while (scanf("%s", price.price2) != 1 )
	{
		printf("\nPlease try again and make sure the charge2 is bigger than charge1.\n");
		fflush(stdin);
		Sleep(2000);
		system("cls");
	}
	fflush(stdin);

	printf("Please input the price in the third interval:\n");
	while (scanf("%s", price.price3) != 1 )
	{
		printf("\nPlease try again and make sure the charge3 is bigger than charge2.\n");
		fflush(stdin);
		Sleep(2000);
		system("cls");
	}
	fflush(stdin);

	printf("Please input the price in the fourth interval:\n");
	while (scanf("%s", price.price4) != 1)
	{
		printf("\nPlease try again and make sure the charge4 is bigger than charge3.\n");
		fflush(stdin);
		Sleep(2000);
		system("cls");
	}
	fflush(stdin);

	fptr21 = fopen(file21, "a+b");                                  /*Try to open the file for writing or create the file if it doesn't exist in binary mode*/
	if (fptr21 == NULL) 		                                    /*Test the success of opening the file,close the program if fail*/
	{
		printf("\nFailed opening the file, please restart the program\n");
		Sleep(2000);
		exit(0);
	}
	else				                                            /*If successfully open the file, write the structure to the file*/
	{
		fwrite(&price, sizeof(struct charge), 1, fptr21);           /*write the structure to the file*/
	}
	fclose(fptr21);                                                 /*close the file*/

	fptr22 = fopen(file22, "a+b");                                  /*Try to open the file for writing or create the file if it doesn't exist in binary mode*/
	if (fptr22 == NULL) 	                                    	/*Test the success of opening the file,close the program if fail*/
	{
		printf("\nFailed opening the file, please restart the program\n");
		Sleep(2000);
		exit(0);
	}
	else				                                            /*If successfully open the file, write the structure to the file*/
	{
		fwrite(&price, sizeof(struct charge), 1, fptr22);           /*write the structure to the file*/
	}
	fclose(fptr22);                                                 /*close the file*/
}
void alter21(struct dates *point, char*file21)
{
	FILE*fptr21;                                                    /*declare a file pointer*/
	fflush(stdin);
	fptr21 = fopen(file21, "r+b");                                  /*Try to open the file for reading and writing or create the file if it doesn't exist in binary mode*/
	if (fptr21 == NULL)				                                /*Test success of file opening*/
	{
		printf("\nFailed opening the file, please restart the program\n");
		Sleep(2000);
		exit(0);
	}
	printf("Please input the new critical points of the rental duration.\n");
	printf("The first critical point is ");
	scanf("%s", &point->point1);
	printf("\nThe second critical point is ");
	scanf("%s", &point->point2);
	printf("\nThe third critical point is ");
	scanf("%s", &point->point3);
	fseek(fptr21, 0, SEEK_SET);
	fwrite(&point, sizeof(struct dates), 1, fptr21);
	fclose(fptr21);                                                  /*close the file*/
}
void alter22(struct charge *price, char*file22)
{
	FILE*fptr22;                                                     /*declare a file pointer*/
	fflush(stdin);
	fptr22 = fopen(file22, "r+b");                                  /*Try to open the file for reading and writing or create the file if it doesn't exist in binary mode*/
	if (fptr22 == NULL)				                                /*Test success of file opening*/
	{
		printf("\nFailed opening the file, please restart the program\n");
		Sleep(2000);
		exit(0);
	}
	printf("%s", &price->price1);
	printf("Please input the new charge.\n");
	printf("The price in the first interval is ");
	scanf("%s", &price->price1);
	printf("\nThe price in the second interval is ");
	scanf("%s", &price->price2);
	printf("\nThe price in the third interval is ");
	scanf("%s", &price->price3);
	printf("\nThe price in the fourth interval is ");
	scanf("%s", &price->price4);
	printf("%s", &price->price1);
	fseek(fptr22, 0, SEEK_SET);
	fwrite(&price, sizeof(struct charge), 1, fptr22);
	fclose(fptr22);                                                  /*close the file*/
}

void check(struct customers *person, char*file2)
{
	char *pa = (person->history);
	FILE*fptr2;                                                     /*declare a file pointer*/
	char checks[99];                                                /*declare arrays to represent the user's input*/
	fflush(stdin);
	printf("Please input the number of customer who you want to check whether he exists\n");
	while (scanf("%s", checks) == 0 || strlen(checks) > 100)        /*Test the validity of the input*/
	{
		printf("Please try again and make sure the number no more than 100 characters long\n");
		fflush(stdin);
		Sleep(2000);
		system("cls");
		printf("Please input the number of customer who you want to check whether he exists\n");
	}
	fflush(stdin);
	fptr2 = fopen(file2, "r+b");                                   /*Try to open the file for reading and writing or create the file if it doesn't exist in binary mode*/
	if (fptr2 == NULL)	 	 	                              	   /*Test success of file opening*/
	{
		printf("\nFailed opening the file, please restart the program\n");
		Sleep(2000);
		exit(0);
	}
	else
	{
		while (fread(person, sizeof(struct customers), 1, fptr2) == 1 && (strcmp(person->number, checks)))
		{
			continue;                                             /*continues the loop until the end of the file reached or the number matches*/
		}
	}
	if (strcmp(person->number, checks))                           /*test to see if the loop finished because the number has been found*/
	{
		printf("The customer does not exist\n");
		Sleep(2000);
	}
	else
	{
		pa++;
		fseek(fptr2, 0, SEEK_SET);
		fwrite(&person, sizeof(struct customers), 1, fptr2);
		printf("The customer has been found\n");
		fflush(stdin);
		Sleep(2000);
		system("cls");
	}
	fclose(fptr2);
}
void rent(struct titles *movie, char*file)
{
	char *pb = (movie->copies);
	FILE*fptr;/*declare a file pointer*/
	char rents[99];/*declare arrays to represent the user's input*/
	fflush(stdin);
	printf("Please input the title of movie which you want to rent\n");
	while (scanf("%s", rents) == 0 || strlen(rents) > 100) /*Test the validity of the input*/
	{
		printf("Please try again and make sure the title no more than 100 characters long\n");
		fflush(stdin);
		Sleep(1000);
		system("cls");
		printf("Please input the title of movie which you want to rent\n");
	}
	fflush(stdin);
	fptr = fopen(file, "r+b");/*Try to open the file for reading and writing or create the file if it doesn't exist in binary mode*/
	if (fptr == NULL)				/*Test success of file opening*/
	{
		printf("\nFailed opening the file, please restart the program\n");
		Sleep(1000);
		exit(0);
	}
	else
	{
		while (fread(movie, sizeof(struct titles), 1, fptr) == 1 && (strcmp(movie->title, rents)))
		{
			continue;/*continues the loop until the end of the file reached or the titles match*/
		}
	}
	if (strcmp(movie->title, rents))/*test to see if the loop finished because the title has been found*/
	{
		printf("The title does not exist\n");
	}
	else
	{
		if (*pb >= 1)
		{
			printf("Please input your rent year\n");
			while (scanf("%s", movie->rentyear) == 0)
			{																/* checks the validity  of the string */
				printf("Please try again and make sure the validity  of the number");
				fflush(stdin);
				Sleep(2000);
				system("cls");
			}
			fflush(stdin);
			printf("Please input your rent month\n");
			while (scanf("%s", movie->rentmonth) == 0)
			{																/* checks the validity  of the string */
				printf("Please try again and make sure the validity  of the number");
				fflush(stdin);
				Sleep(2000);
				system("cls");
			}
			fflush(stdin);
			printf("Please input your rent day\n");
			while (scanf("%s", movie->rentday) == 0)
			{																/* checks the validity  of the string */
				printf("Please try again and make sure the validity  of the number");
				fflush(stdin);
				Sleep(2000);
				system("cls");
			}
			fflush(stdin);
			printf("Please input your rent time\n");
			while (scanf("%s", movie->renttime) == 0)
			{																/* checks the validity  of the string */
				printf("Please try again and make sure the validity  of the number");
				fflush(stdin);
				Sleep(2000);
				system("cls");
			}
			fflush(stdin);
			fptr = fopen(file, "a+b");                                         /*Try to open the file for writing or create the file if it doesn't exist in binary mode*/
			if (fptr == NULL) 		                                        /*Test the success of opening the file,close the program if fail*/
			{
				printf("\nFailed opening the file, please restart the program\n");
				Sleep(1000);
				exit(0);
			}
			else				                                             /*If successfully open the file, write the structure to the file*/
			{
                fseek(fptr, 0, SEEK_SET);
				fwrite(&movie, sizeof(struct titles), 1, fptr);              /*write the structure to the file*/
			}
			printf("Rent successfully\n");
			fflush(stdin);
			Sleep(1000);
			system("cls");
			fclose(fptr);
		}
		else
		{
			printf("Sorry,this DVD has been rented");
			fclose(fptr);
		}
	}
	fclose(fptr);
}
void returnn(struct titles *movie, char*file, struct customers *person, char*file2, struct dates *point, char*file21, struct charge *price, char*file22)
{
	FILE *fptr, *fptr2, *fptr21, *fptr22;
	char *pb = (movie->copies);
	char *pc = (movie->renttime);
	char *pd = (person->money);
	char *pe = (point->point1);
	char *pf = (point->point2);
	char *pg = (point->point3);
	char *ph = (price->price1);
	char *pi = (price->price2);
	char *pj = (price->price3);
	char *pk = (price->price4);
	char *pl = (movie->rentyear);
	char *pm = (movie->rentmonth);
	char *pn = (movie->rentday);
	char *po = (person->returnyear);
	char *pp = (person->returnmonth);
	char *pq = (person->returnday);
	int day;
	int pentliay[99];
	char returns[99];
	fflush(stdin);
	system("cls");
	printf("Please input the title of movie which you want to return\n");
	while (scanf("%s", returns) == 0 || strlen(returns) > 100)     /*Test the validity of the input*/
	{
		printf("Please try again and make sure the title no more than 100 characters long\n");
		fflush(stdin);
		Sleep(1000);
		system("cls");
		printf("Please input the title of movie which you want to return\n");
	}
	fflush(stdin);
	fptr = fopen(file, "r+b");                                     /*Try to open the file for reading and writing or create the file if it doesn't exist in binary mode*/
	if (fptr == NULL)			                               	   /*Test success of file opening*/
	{
		printf("\nFailed opening the file, please restart the program\n");
		Sleep(1000);
		exit(0);
	}
	else
	{
		while (fread(movie, sizeof(struct titles), 1, fptr) == 1 && (strcmp(movie->title, returns)))
		{
			continue;                                             /*continues the loop until the end of the file reached or the titles match*/
		}
	}
	if (strcmp(movie->title, returns))                            /*test to see if the loop finished because the title has been found*/
	{
		printf("The title does not exist\n");
	}
	else
	{
		printf("Please input your return year\n");
		while (scanf("%s", person->returnyear) == 0)
		{																/* checks the validity  of the string */
			printf("Please try again and make sure the validity  of the number");
			fflush(stdin);
			Sleep(2000);
			system("cls");
		}
		fflush(stdin);
		printf("Please input your return month\n");
		while (scanf("%s", person->returnmonth) == 0)
		{																/* checks the validity  of the string */
			printf("Please try again and make sure the validity  of the number");
			fflush(stdin);
			Sleep(2000);
			system("cls");
		}
		fflush(stdin);
		printf("Please input your return day\n");
		while (scanf("%s", person->returnday) == 0)
		{																/* checks the validity  of the string */
			printf("Please try again and make sure the validity  of the number");
			fflush(stdin);
			Sleep(2000);
			system("cls");
		}
		fflush(stdin);
		day = *pl * 360 + *pm * 30 + *pn - *po * 360 - *pp * 30 - *pq;
		if (*pc <= day)
		{
			while (pc < pe)
			{
				pd = ph;
			}
			while (pe < pc&&pc < pg)
			{
				pd = pi;
			}
			while (pc > pg)
			{
				pd = pj;
			}
			printf("You need to pay %s\n", *pd);
			*pb++;
			fseek(fptr, 0, SEEK_SET);
			fwrite(&movie, sizeof(struct titles), 1, fptr);
			printf("Return successfully\n");
		}
		else
		{

			printf("Please input the penalty for the extra day:\n");
			while (scanf("%s", pentliay) == 0)
			{																/* checks the validity  of the string */
				printf("Please try again and make sure the validity  of the number:");
				fflush(stdin);
				Sleep(1000);
				system("cls");
			}
			*pd = *pj + (day - *pc) * pentliay[99];
			printf("You need to pay %s\n", pd);
			*pb++;
			fseek(fptr, 0, SEEK_SET);
			fwrite(&movie, sizeof(struct titles), 1, fptr);
			printf("Return successfully\n");
		}
	}
	fclose(fptr);
}

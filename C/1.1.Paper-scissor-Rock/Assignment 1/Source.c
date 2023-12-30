/*
Name: Assignment 1 Name: 1719177.c
Copyright: Free
Author: Yu-Cheng.Lin
Description: 1.Use a loop to add together the character values of the name entered 2.Divide the first 6 figures of the telephone number by the last 5 and store the result in a variable 
3.Convert the decimal number to its binary equivalent 4.Convert the temperature from degrees Celsius to degrees Fahrenheit and degrees Kelvin.
*/
#include<stdio.h>                         /* include standard library stdio.h for use of scanf() and printf() */
#include<math.h>                          /* include standard library stdio.h for use of double()*/
#include<string.h>                        /* include standard library stdio.h for use of char() and strlen() */
#include<stdlib.h>                        /* include standard library stdlib.h for use of exit() */

int main(void)                           /* define a function named main */
{
	int i, n = 0, a, m, u = 0, v = 0, num, decmial, h[100], binary, j = 0, Celsius, Fahrenheit, Kelvin;                /*Define structure*/
	double b, S;
	char name[20], number[20];

/*Use a loop to add together the character values of the name entered*/
	printf("Please enter your full name: ");                            /*ask user to input full name*/
	gets(name);
	printf("%s=", name);
	for (i = 0; name[i]; i++)
	{
		{
			a = name[i];
			if ((i) == '\0')
				printf("%d", a);
			else printf("+%d", a);
		}                                                              /*End of if-else*/
		n += name[i];
	}                                                                  /*End of the for*/
	printf("= %d\n", n);

/*Divide the first 6 figures of the telephone number by the last 5 and store the result in a variable*/
	for (;;)
	{
		printf("Please enter an 11-digit non-real telephone number:");/*ask user to input an 11-digit non-real telephone number*/
		scanf("%s", &number);                                      /* store the value of the input real number into variable telephone number using the scanf function */
		m = strlen(number);
		if (m == 11)
			break;
		continue;
	}                                                    /*End of for*/

	for (num = 0; number[num]; num++)
	{
		b = atoi(strlen(number));
		if (num <= 5)                                       /*get the top six digits of the telephone number*/
		{
			u += b*pow(10, 5 - num);
			prinft("%d", u);
		}
		else                                                /*get the latter five digits of the telephone number*/
			v += b*pow(10, 10 - num);
	}
	S = u / v;
	print("The top six telephone numbers are divided by the latter telephone number = %f", S);

/*Convert the decimal number to its binary equivalent*/
	printf("Please enter the decimal number: ");           /* ask user to input a decmial number*/
	scanf("%d", &decmial);                                 /* store the value of the input real number into variable Decmial using the scanf function */
	while (decmial)                                        /*Adopting the method of "excluding 2 remaining and arranging in reverse order"*/
	{
		h[j++] = decmial % 2;
		decmial /= 2;
	}                                                      /*End of while*/
	printf("The binary number:");                          /* display the Binary temperature at the given Decmial*/
	for (binary = j - 1; binary >= 0; binary--)
		printf("%d", h[binary]);
	printf("\n");

/*Convert the temperature from degrees Celsius to degrees Fahrenheit and degrees Kelvin.*/
	printf("Please enter the Celsius temperature: ");      /* ask user to input a Celsius*/
	if (scanf("%d", &Celsius) != 1)                        /* store the value of the input real number into variable Celsius using the scanf function */
		exit(0);                                        /* test the return value of scanf to make sure the read was successful. If the read failed exit the program */
	Fahrenheit = Celsius*1.8 + 32;                     /* compute the temperature at the given Celsius in degrees Fahrenheit according to the formula provided */
	Kelvin = Celsius + 273.15;                         /* compute the temperature at the given Celsius in degrees Kelvin according to the formula provided */
	printf("Fahrenheit temperature at Celsius %.2d is %.2d.\n", Celsius, Fahrenheit);      /* display the Fahrenheit temperature at the given Celsius */
	printf("Kelvin temperature at Celsius %.2d is %.2d.", Celsius, Kelvin);              /* display the Kelvin temperature at the given Celsius */
	return 0;
}



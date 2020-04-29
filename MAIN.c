#include<stdio.h>
#include<curses.h>
#include<string.h>
#include<stdlib.h>
#include</home/abishai/Documents/Secure-Programming-with-C/PbAbi.h>
#include</home/abishai/Documents/Secure-Programming-with-C/PbAbi2.h> //PRE08-C. Guarantee that header file names are unique
char n;
int* ptr;

struct fun
{
	void (*abc)(void);
	void (*xyz)(void);
};

struct fun fun = { .abc = stu , .xyz = admin};
int main()
{
	/*
	int flag = 0;
	int cnt = 0;
	int false1 = 0;
	int fptr;
	int* ptr;
	int rno;
	int year;
	int maxrollno;
	int num1;
	char branch[6], br1[6];
	char n;
	*/
	//clrscr

	while(1)
	{
		//clrscr();
		printf("\n\n\t\t\tWelcome to Voting System\n");

		printf("\n\t\t\t   1.Student panel \n\t\t\t   2.Admin panel \n\t\t\t   3.Exit \n\t\t\t   Option:");
		scanf(" %c",&n);


		if(n==49)
				fun.abc();
		else
		{	if(n==50)
				fun.xyz();
			else
			{
				if(n==51)
				{
					free(ptr);
					free(a);
					return 0;
				}
				else
				{
					printf("\nInvalid option");
					continue;
				}
			}
		}
	}
	return 0;
}

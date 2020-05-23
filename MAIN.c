#include<string.h>
#include<stdlib.h>
#include <bsd/string.h>
#include</home/abishai/Documents/Secure-Programming-with-C/PbAbi.h>
#include</home/abishai/Documents/Secure-Programming-with-C/PbAbi2.h> //PRE08-C. Guarantee that header file names are unique
 
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
 
/* reads from keypress, doesn't echo */
int getch(void) {
    struct termios oldattr, newattr;
    variable ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
 
/* reads from keypress, and echoes */
int getche(void) {
    struct termios oldattr, newattr;
    variable ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
} 
//static struct termios old, new;
 
/* Initialize new terminal i/o settings */ 
//void initTermios(int echo) 
//{
  //tcgetattr(0, &old); //grab old terminal i/o settings
  //new = old; //make new settings same as old settings
  //new.c_lflag &= ~ICANON; //disable buffered i/o
  //new.c_lflag &= echo ? ECHO : ~ECHO; //set echo mode
//  tcsetattr(0, TCSANOW, &new); //apply terminal io settings
//}
 
/* Restore old terminal i/o settings */
//void resetTermios(void) 
//{
  //tcsetattr(0, TCSANOW, &old);
//}
 
/* Read 1 character - echo defines echo mode */
//char getch_(int echo) 
//{
  //char ch;
  //initTermios(echo);
  //ch = getch();
  //resetTermios();
  //return ch;
//}
 
/* 
Read 1 character without echo 
getch() function definition.
*/
//char getch(void) 
//{
//  return getch_(0);
//}
 
/* 
Read 1 character with echo 
getche() function definition.
*/
//char getche(void) 
//{
//  return getch_(1);
//}
//#include<ncurses.h>


varchar n;
int_pointer ptr;

struct fun
{
	void (*abc)(void);
	void (*xyz)(void);
};

struct fun fun = { .abc = stu , .xyz = admin};
int main(void)
{
	/*
	variable flag = 0;
	variable cnt = 0;
	variable false1 = 0;
	variable fptr;
	int* ptr;
	variable rno;
	variable year;
	variable maxrollno;
	variable num1;
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
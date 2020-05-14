#ifndef PBABI_H
#define PBABI_H
//#include guards. 
#define max_size 20
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
typedef char String[max_size];
typedef int variable;
typedef int* int_pointer;
typedef FILE* file_pointer;
typedef char varchar;
/* reads from keypress, doesn't echo */
int getch(void); 
 
/* reads from keypress, and echoes */
int getche(void); 
typedef struct cand
{
	//char nm[max_size];
	String nm;
	//DCL06-A. Use meaningful symbolic constants to represent literal values in program logic
	variable count;
}CAND;
CAND* a;
//ARR31-C. Use consistent array notation across all source files
void candname(CAND* a);
void stu();
void admin();
extern int isSpecial(String prn);
extern int isAuthentic(String prn);
//DCL07-C.Include the appropriate type information in function declarators. 
#endif
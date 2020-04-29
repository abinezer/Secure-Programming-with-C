#ifndef PBABI_H
#define PBABI_H
//#include guards. 
#define max_size 20
typedef struct cand
{
	char nm[max_size];
	//DCL06-A. Use meaningful symbolic constants to represent literal values in program logic
	int count;
}CAND;
CAND* a;
//ARR31-C. Use consistent array notation across all source files
void candname(CAND* a);
void stu();
void admin();
extern int isSpecial(char prn[15]);
extern int isAuthentic(char prn[15]);
//DCL07-C.Include the appropriate type information in function declarators. 
#endif

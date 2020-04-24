#ifndef PBABI_H
#define PBABI_H

//Structure that holds candidate name and count of vote
typedef struct cand
{
	char nm[20];
	int count;
}CAND;
CAND* a;
extern void stu();
extern void admin();
extern int isSpecial(char prn[15]);
extern int isAuthentic(char prn[15]);
extern void candname(CAND* a);
extern void flcreate(int no);
extern void delFromfile(char sprn[15], int fno);

extern int flag = 0;
extern int cnt = 0;
extern int false1 = 0;
extern int fptr;
extern int* ptr;
extern int rno;
extern int year;
extern int maxrollno;
extern int num1;
extern char branch[6], br1[6];
extern char n;



#endif

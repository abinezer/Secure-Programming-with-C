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




#endif

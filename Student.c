#include<stdio.h>
#include<curses.h>
#include<string.h>
#include<stdlib.h>
#include</home/abishai/Documents/Secure-Programming-with-C/PbAbi.h>
#include</home/abishai/Documents/Secure-Programming-with-C/PbAbi2.h> //PRE08-C. Guarantee that header file names are unique
//Student Panel

int flag; int false1;
struct fun1
{
	int (*pqr)(char prn[15]);
	int (*lmn)(char prn[15]);
};

struct fun1 fun1 = { .pqr = isSpecial , .lmn = isAuthentic };
void stu()
{
	FILE* fp;
	CAND* b;

	//char prn[15],text[20],d;
	//char str[16],vprn[16];
	//DCL04-C not more than 1 var per declaration
	char prn[15];
	char text[20];
	//char d;
	char str[16];
	char vprn[16];
	char stp[2] = "0";
	int flg = 1;
	//int len,num,i,opt,j,res,k=0,nos,choice,roll,val;
	//DCL04-C not more than 1 var per declaration
	int len;
	int num;
	int i;
	//int opt;
	int j;
	int res;
	int k = 0;
	//int nos; //MSC13-A. Detect and remove unused values
	//int choice;
	//int roll;
	int val;
	//char no;
	char v1;
	char v2;

	b = a;

	while (1)
	{
	prn:
		//clrscr();
		printf("\n\n  To exit press 0");
		printf("\n  Please Don't Use Capital Letters");
		printf("\n  Enter PRN no:");
		scanf("%s", prn);
		if (strcmp(stp, prn) == 0) //EXP20-C explicitly check if condition.
			return;
		len = strlen(prn);
		if (len < 14 || len>14)
		{
			printf("\nInvalid PRN(Incorrect length)\nTry Again(Press Enter)");
			getchar();
			continue;
		}
		//val = isSpecial(prn);
		val = fun1.pqr(prn);
		if (val == 1)
		{
			printf("\n  Blank number");
			getchar();
			false1++;
			continue;
		}
		//res = isAuthentic(prn);
		res = fun1.lmn(prn);
		if (res != 1)
		{
			printf("\n  Try Again(Press Enter)");
			getchar();
			continue;
		}
		else
		{
			num = cnt;
			if (flag != 1)
			{
				if (ptr[rno - 1] != 0) //EXP20-C explicitly check if condition.
				{
					printf("\n  Your PRN entered is already voted\n  Contact Admin for furthur query");
					getchar();
					continue;
				}
			}
			else
			{
				//	checkfile:
				while (k < num)
				{
					sprintf(text, "a%d.txt", k + 1);
					fp = fopen(text, "r"); //FIO11-A. Take care when specifying the mode parameter of fopen()
					flg = 1;
					while (flg)
					{
						fgets(str, 99, fp);
						for (i = 0; i < (strlen(str) - 1); i++)
							vprn[i] = str[i];
						vprn[i] = '\0';
						if (strcmp(prn, vprn) == 0) //EXP20-C explicitly check if condition.
						{
							printf("\n  The PRN %s has already voted\nContact Admin if it weren't you...!", prn);
							fclose(fp);
							getchar();
							goto prn;
						}
						//FIO35-C. Use feof() and ferror() to detect end-of-file and file errors
						if (feof(fp) != 0)  //EXP20-C explicitly check the if condition.
						{
							flg = 0;
							fclose(fp);
						}
					}
					k++;

				}

			}
			printf("\n\n  Candidates for election:");
			j = 1;
			for (i = 0; i < num; i++)
			{
				printf("\n  %d. %s", j, (b + i)->nm);
				j++;
			}
		vote:
			while (1)
			{
				printf("\n\n  Your Vote(Enter Number):");
				v1 = getchar();
				printf("*");
				getchar();
				printf("\n  Confirm Your Vote:");
				v2 = getchar();
				printf("*");
				if (v1 == v2)
					break;
				else
				{
					//	_getch();
					printf("\n\n   Mismatch(Try Again)");
					continue;
				}
			}

			if ((v1 - 48) > num)
			{
				printf("\n  Invalid vote");
				getchar();
				goto vote;
				//	break;
			}
			else
			{
				printf("\n\nThanks for your precious vote(Press Enter)");


				ptr[rno - 1] = (v1 - 48);
				getchar();
				for (j = 0; j < num; j++)
				{
					if ((v1 - 48) == (j + 1))
					{
						(a + j)->count++;
						sprintf(text, "a%d.txt", (j + 1));
						fp = fopen(text, "r+");
						fprintf(fp, "%d", (a + j)->count);
						fseek(fp, 0, SEEK_END);
						fprintf(fp, "%s", prn);
						fputs("\n", fp);
						fclose(fp);
					}
				}
			}
		}

	}

}

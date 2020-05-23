#include<stdio.h>
//#include<ncurses.h>
#include<string.h>
#include<stdlib.h>
#include <bsd/string.h>
#include</home/abishai/Documents/Secure-Programming-with-C/PbAbi.h>
#include</home/abishai/Documents/Secure-Programming-with-C/PbAbi2.h> //PRE08-C. Guarantee that header file names are unique
//Student Panel

variable flag; variable false1;
/*
struct fun1
{
	variable (*pqr)(String prn);
	variable (*lmn)(String prn);
};

struct fun1 fun1 = { .pqr = isSpecial , .lmn = isAuthentic };
*/
void stu()
{
	file_pointer fp;
	CAND* b;

	//char prn[15],text[20],d;
	//char str[16],vprn[16];
	//DCL04-C not more than 1 var per declaration
	String prn;
	String text;
	//char d;
	String str;
	String vprn;
	String stp = "0";
	variable flg = 1;
	//variable len,num,i,opt,j,res,k=0,nos,choice,roll,val;
	//DCL04-C not more than 1 var per declaration
	variable len;
	variable num;
	variable i;
	//variable opt;
	variable j;
	variable res;
	variable k = 0;
	//variable nos; //MSC13-A. Detect and remove unused values
	//variable choice;
	//variable roll;
	variable val;
	//char no;
	varchar v1;
	varchar v2;

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
			getch();
			continue;
		}
		
		if(val == 0)
		{
			val = isSpecial(prn);
			fp = fopen("isSpecial.txt","a+");
			fprintf(fp, "%s\n", prn);
			fclose(fp);
		}
		//printf("isSpecial passed...");
		if (val == 1)
		{
			printf("\n  Blank number");
			getch();
			false1++;
			continue;
		}
		res = isAuthentic(prn);
		//res = fun1.lmn(prn);
		if (res != 1)
		{
			printf("\n  Try Again(Press Enter)");
			getch();
			continue;
		}
		else
		{
			num = numberOfCand;
			if (flag != 1)
			{
				if (ptr[rno - 1] != 0) //EXP20-C explicitly check if condition.
				{
					printf("\n  Your PRN entered is already voted\n  Contact Admin for furthur query");
					getch();
					continue;
				}
			}
			else
			{
				//	checkfile:
				while (k < num)
				{
					sprintf(text, "candidate%d.txt", k + 1);
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
							getch();
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
				v1 = getch();
				//printf("*");
				//getch();
				printf("\n  Confirm Your Vote:");
				v2 = getch();
				//printf("*");
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
				getch();
				goto vote;
				//	break;
			}
			else
			{
				printf("\n\nThanks for your precious vote(Press Enter)");
				ptr[rno - 1] = (v1 - 48);
				getch();
				for (j = 0; j < num; j++)
				{
					if ((v1 - 48) == (j + 1))
					{
						(a + j)->count++;
						sprintf(text, "candidate%d.txt", (j + 1));
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
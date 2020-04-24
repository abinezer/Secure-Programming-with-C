#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

//Student Panel

void stu()
{
	FILE* fp, * f1;
	CAND* b;

	//char prn[15],text[20],d;
	//char str[16],vprn[16];
	//DCL04-C not more than 1 var per declaration
	char prn[15];
	char text[20];
	char d;
	char str[16];
	char vprn[16];
	char stp[2] = "0";
	int flg = 1;
	//int len,num,i,opt,j,res,k=0,nos,choice,roll,val;
	//DCL04-C not more than 1 var per declaration
	int len;
	int num;
	int i;
	int opt;
	int j;
	int res;
	int k = 0;
	int nos;
	int choice;
	int roll;
	int val;
	char no;
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
			_getch();
			continue;
		}
		val = isSpecial(prn);
		if (val == 1)
		{
			printf("\n  Blank number");
			_getch();
			false1++;
			continue;
		}
		res = isAuthentic(prn);
		if (res != 1)
		{
			printf("\n  Try Again(Press Enter)");
			_getch();
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
					_getch();
					continue;
				}
			}
			else
			{
				//	checkfile:
				while (k < num)
				{
					sprintf(text, "a%d.txt", k + 1);
					fp = fopen(text, "r");
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
							_getch();
							goto prn;
						}
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
				v1 = _getch();
				printf("*");
				_getch();
				printf("\n  Confirm Your Vote:");
				v2 = _getch();
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
				_getch();
				goto vote;
				//	break;
			}
			else
			{
				printf("\n\nThanks for your precious vote(Press Enter)");


				ptr[rno - 1] = (v1 - 48);
				_getch();
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

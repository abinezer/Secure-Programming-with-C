#include<stdio.h>
#include<curses.h>
#include<string.h>
#include<stdlib.h>
#include</home/abishai/Documents/Secure-Programming-with-C/PbAbi.h>
#include</home/abishai/Documents/Secure-Programming-with-C/PbAbi2.h> //PRE08-C. Guarantee that header file names are unique
//MSC00-A. Compile cleanly at high warning levels

int flag ;
int false1 ;
//Structure that holds candidate name and count of vote
//DCL05-A. Use typedefs to improve code readability

//fn to store names of candidates standing for election

void candname(CAND* a)
{
	FILE* f1;
	printf("Enter Candidate name:");
	scanf("\n");
	//gets(a->nm);
	fgets(a->nm, 20, stdin); // STR31-C enough space for char data 
						   // and null terminator.
	a->count = 0;

	//Names are stored in text file
	f1 = fopen("PreviousElection.txt", "r+");
	fseek(f1, 0, SEEK_END);
	fprintf(f1, "\n%s", a->nm);
	fptr = ftell(f1);
	fclose(f1);

}
//FIO40-C. Reset strings on fgets() failure
//fn that creates number of files equal to number of candidates
//MSC07-A. Detect and remove dead code
void flcreate(int no)
{
	FILE* fp;
	int i;
	char text[20];
	//clrscr();

	for (i = 1; i <= no; i++)
	{
		sprintf(text, "a%d.txt", i);
		fp = fopen(text, "w");
		fprintf(fp, "0\n");
		fclose(fp);
	}
}

//MSC13-A. Detect and remove unused values
//MSC12-A. Detect and remove code that has no effect

//fn to delete illegal vote
//MSC04-A. Use comments consistently and in a readable fashion
void delFromfile(char sprn[15], int fno)
{
	FILE* fp;
	//int i=0,no,k=0,r=0,j=0,pos=0,flg=1;
	//DCL04-C No more than 1 var per declaration.
	int i = 0;
	int no;
	int k = 0;
	int r = 0;
	int j = 0;
	int pos = 0;
	int flg = 1;
	char str[16];
	char vprn[16];
	char text[20];
	//DCL32-C. Guarantee identifiers are unique
	//clrscr();
	no = cnt;
	if (flag != 1) //EXP20-C explicitly check if condition.
	{
		sprintf(text, "a%d.txt", fno);
		fp = fopen(text, "r");
		while (1)
		{
			fgets(str, 99, fp);
			for (i = 0; i < (strlen(str) - 1); i++)
				vprn[i] = str[i];
			vprn[i] = '\0';
			if (strcmp(sprn, vprn) == 0) //EXP20-C explicitly check if condition.
			{
				pos = ftell(fp);
				fclose(fp);
				fp = fopen(text, "r+");
				fseek(fp, pos, SEEK_SET);
				fseek(fp, -16, SEEK_CUR);
				for (j = 0; j < 14; j++)
					fprintf(fp, "%d", r);
				printf("\nVote for the PRN %s removed successfully", sprn);
				false1++;
				(a + fno - 1)->count--;
				fseek(fp, 0, SEEK_SET);
				fprintf(fp, "%d", (a + fno - 1)->count);
				fclose(fp);
				getchar();
				return;
			}
			//FIO35-C. Use feof() and ferror() to detect end-of-file and file errors
			if (feof(fp))
			{
				printf("\nNot Found");
				getchar();
				fclose(fp);
				break;
			}
		}
	}
	else
	{
		while (k < no)
		{
			sprintf(text, "a%d.txt", k + 1);
			fp = fopen(text, "r");
			//FIO11-A. Take care when specifying the mode parameter of fopen()
			flg = 1;
			while (flg)
			{
				if (fp == NULL) //EXP20-C explicitly check if condition.
					printf("File Doesn't Exist");
				fgets(str, 99, fp);
				for (i = 0; i < (strlen(str) - 1); i++)
					vprn[i] = str[i];
				vprn[i] = '\0';
				//if(!(strcmp(sprn,vprn)))
				if (strcmp(sprn, vprn) == 0)  //EXP20-C explicitly check if condition.
				{
					pos = ftell(fp);
					fclose(fp);
					fp = fopen(text, "r+");
					//FIO31-C. Do not simultaneously open the same file multiple times
					fseek(fp, pos, SEEK_SET);
					fseek(fp, -16, SEEK_CUR);
					for (j = 0; j < 14; j++)
						fprintf(fp, "%d", r);
					(a + k)->count--;
					fseek(fp, 0, SEEK_SET);
					fprintf(fp, "%d", (a + k)->count);
					fclose(fp);
					printf("\nVote for the PRN %s removed successfully", sprn);
					flg = 2;
					false1++;
					break;
				}
				if (flg == 2)
					break;
				//if(feof(fp))
				if (feof(fp) != 0)  //EXP20-C explicitly check if condition.
				{
					if (k == (no - 1))
						printf("Not Found");
					flg = 0;
					fclose(fp);
					//FIO46-C. Do not access a closed file
				}
			}
			k++;

		}
	}
	getchar();
}
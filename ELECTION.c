#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<C:\Abishai\SecureC_project\PbAbi.h>
#include<C:\Abishai\SecureC_project\PbAbi2.h> //PRE08-C. Guarantee that header file names are unique


//Structure that holds candidate name and count of vote
typedef struct cand
{
	 char nm[20];
	 int count;
}CAND;
CAND *a;





//fn to store names of candidates standing for election

void candname(CAND *a)
{
	FILE*f1;
	printf("Enter Candidate name:");
	scanf("\n");
	//gets(a->nm);
	fgets(a->nm,20,stdin); // STR31-C enough space for char data 
	                       // and null terminator.
	a->count=0;

	//Names are stored in text file
	f1=fopen("PreviousElection.txt","r+");
	fseek(f1,0,SEEK_END);
	fprintf(f1,"\n%s",a->nm);
	fptr=ftell(f1);
	fclose(f1);

}
//fn that creates number of files equal to number of candidates

void flcreate(int no)
{
	FILE *fp;
	int i;
	char text[20];
	//clrscr();

	for(i=1;i<=no;i++)
	{
		sprintf(text,"a%d.txt",i);
		fp=fopen(text,"w");
		fprintf(fp,"0\n");
		fclose(fp);
	}
}



//fn to delete illegal vote
void delFromfile(char sprn[15],int fno)
{
	FILE*fp;
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
	//clrscr();
	no=cnt;
	if(flag!=1) //EXP20-C explicitly check if condition.
	{
		sprintf(text,"a%d.txt",fno);
		fp=fopen(text,"r");
		while(1)
		{
			fgets(str,99,fp);
			for(i = 0; i <(strlen(str)-1); i++)
				vprn[i]=str[i];
			vprn[i]='\0';
			if(strcmp(sprn,vprn)==0) //EXP20-C explicitly check if condition.
			{
				pos=ftell(fp);
				fclose(fp);
				fp=fopen(text,"r+");
				fseek(fp, pos, SEEK_SET);
				fseek(fp, -16, SEEK_CUR);
				for(j=0;j<14;j++)
					fprintf( fp ,"%d", r);
				printf("\nVote for the PRN %s removed successfully",sprn);
				false1++;
				(a+fno-1)->count--;
				fseek(fp,0,SEEK_SET);
				fprintf(fp,"%d",(a+fno-1)->count);
				fclose(fp);
				_getch();
				return;
			}
			if(feof(fp))
			{
				printf("\nNot Found");
				_getch();
				fclose(fp);
				break;
			}
		}
	}
	else
	{
	while(k<no)
	{
		sprintf(text,"a%d.txt",k+1);
		fp=fopen(text,"r");
		flg=1;
		while(flg)
		{
			if(fp==NULL) //EXP20-C explicitly check if condition.
				printf("File Doesn't Exist");
			fgets(str,99,fp);
			for(i=0;i<(strlen(str)-1);i++)
					vprn[i]=str[i];
			vprn[i]='\0';
			//if(!(strcmp(sprn,vprn)))
			if(strcmp(sprn,vprn)==0)  //EXP20-C explicitly check if condition.
			{
				pos=ftell(fp);
				fclose(fp);
				fp=fopen(text,"r+");
				fseek(fp, pos, SEEK_SET);
				fseek(fp, -16, SEEK_CUR);
				for(j=0;j<14;j++)
					fprintf( fp ,"%d", r);
				(a+k)->count--;
				fseek(fp,0,SEEK_SET);
				fprintf(fp,"%d",(a+k)->count);
				fclose(fp);
				printf("\nVote for the PRN %s removed successfully",sprn);
				flg=2;
				false1++;
				break;
			}
			if(flg==2)
				break;
			//if(feof(fp))
			if(feof(fp) != 0)  //EXP20-C explicitly check if condition.
			{
				if(k==(no-1))
					printf("Not Found");
				flg=0;
				fclose(fp);
			}
		}
		k++;

	 }
	 }
	_getch();
}





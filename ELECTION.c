#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<C:\Abishai\SecureC_project\PbAbi.h>

/*
int flag = 0;
int cnt = 0;
int false1 = 0;


int fptr;
*/
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

/*
//fn to check valid PRN
int isSpecial(char prn[15])
{
	FILE *fp;
	char sprn[15];
	fp=fopen("blank.txt","r");
	while(feof(fp)==0)
	{
	    fgets(sprn,99,fp);
		sprn[14]='\0';
		//if(!strcmp(sprn,prn))  EXP20-C explicitly check if condition.
		if(strcmp(sprn,prn) == 0)
			return 1;
	}
	fclose(fp);
	return 0;
}

int isAuthentic(char prn[15])
{
	int i = 0;
	int j = 0;
	int no = 0;
	int yr = 0;
	char br[6];
	char d;   //DCL04-C No more than 1 var per declaration.
	while(i<4)
	{
		d=prn[i];
		yr=(yr*10)+(d-48);
		i++;
	}
	if(yr!=year)
	{
		printf("\n  Invalid PRN(Incorrect Year)");
		return 0;
	}
	num1=yr;
	while(i<9)
	{
		br[j]=prn[i];
		j++;
		i++;
	}
	br[j]='\0';
	strcpy(br1,br);
	//if(strcmp(br,branch))
	if(strcmp(br,branch) != 0)  //EXP20-C explicitly check if condition.
	{
		printf("\n  Invalid PRN(Incorrect Branch)");
		return 0;
	}
	while(i<14)
	{
		d=prn[i];
		no=(no*10)+(d-48);
		i++;
	}
	if(no>maxrollno||no<0)
	{
		printf("\n  Invalid PRN(Incorrect Number)");
		return 0;
	}
	rno=no;
	return 1;
}
*/

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


//#include<C:\Abishai\SecureC_project\Admin.h>
/*
//Admin Panel
void admin()
{
	FILE* f1,*fp,*fpb;
	//char user[15],pass[15],prn[15],text[20],nm[50],ch,sp;
	//DCL04-C Not more than 1 var per declaration.
	char user[15];
	char pass[15];
	char prn[15];
	char text[20];
	char nm[50];
	char ch;
	char sp;
	char str1[6]="Admin";
	char str2[8]="SR@3111";
	//int i,no,yr,n,j,max,opt,no1;
	//DCL04-C Not more than 1 var per declaration.
	int i;
	int no;
	int yr;
	int n;
	int j;
	int max;
	int opt;
	int no1;
	float tot=0.0;
	char null[2]="0";
	while(1)
	{
		//clrscr();
		printf("\nEnter username: ");
		scanf("%s",user);
		if((strcmp(user,str1))!=0) //EXP20-C explicitly check if condition.
		{
			printf("Wrong Username");
			_getch();
			continue;
		}
		else
		{       password:
			printf("Enter Password: ");
			for(i=0;i<7;i++)
			{
				pass[i]=_getch();
				printf("%c",'*');
			}
			pass[i]='\0';
			if((strcmp(pass,str2))!=0) //EXP20-C explicitly check if condition.
			{
				printf("\nWrong Password\n");
				_getch();
				goto password;
			}
			else
			{

			printf("\n\nADMIN LOGIN SUCCESSFULL(Press Enter)");
			_getch();
			while(1)
			{
				//clrscr();
				printf("\n1.New Election\n2.Continue Previous Election\n3.Delete Illegal Vote\n4.Result\n5.Logout\nOption:");
				scanf(" %c",&ch);
				switch(ch)
				{
					//TO TAKE NEW ELECTION
				  case '1':
					//clrscr();
					printf("\nNew Election Initiation:\n");
					f1=fopen("PreviousElection.txt","w");
					printf("\nElections for which Year: ");
					scanf("%d",&year);
					printf("Enter branch code:");
					scanf("%s",branch);
					printf("Enter max roll no.:");
					scanf("%d",&maxrollno);
					printf("Enter the no. of candidates:");
					scanf("%d",&no);
					ptr=(int*)malloc((maxrollno)*sizeof(int));
					for(i=0;i<maxrollno;i++)
						ptr[i]=0;
					fprintf(f1,"%d\n%s\n%d\n%d",year,branch,maxrollno,no);
					fclose(f1);
					flcreate(no);
					a=(CAND *)malloc(no*cand_size);
					cnt=no;

				       i=0;j=1;
				    while(i<no)
				    {
						printf("\n  %d.",j);
						candname((a+i));
						i++;j++;
					}

					while(1)
					{
					//clrscr();
					printf("\nPress 1 to exclude special PRNs\n(Press 0 to exit)");
					printf("\nOption:");
					scanf(" %c",&sp);
					if(sp=='0')
						return;
					else{
					if(sp=='1')
					{
							fpb=fopen("blank.txt","w");
							if(fpb==NULL)
							{
								printf("\nProcess Failed");
								_getch();
								break;
							}
							printf("\nEnter 0 to stop\nEnter blank");
							while(strcmp(prn,null)!=0)
							{
								printf("PRN:");
								scanf("%s",prn);
								fprintf(fpb,"%s",prn);
								fputs("\n",fpb);
								printf("\n");
							}
							sprintf(prn,"null");
							fclose(fpb);
					 }
					 else
					 {
							printf("\nInvalid option");
							_getch();
					 }
					 }
					 }

					return;


				//TO CONTINUE PREVIOUS ELECTION
				case '2':
					f1=fopen("PreviousElection.txt","r");
					if(f1==NULL)
						printf("Not Exist");
					fscanf(f1,"%d",&year);
					fseek(f1,2,SEEK_CUR);
					fscanf(f1,"%s",branch);
					fseek(f1,2,SEEK_CUR);
					fscanf(f1,"%d",&maxrollno);
					fseek(f1,2,SEEK_CUR);
					fscanf(f1,"%d",&cnt);
					a=(CAND *)malloc(cnt*cand_size); 
					// INT01-C use size_t to represent the size of an object
					for(i=0;i<cnt;i++)
					{	fseek(f1,2,SEEK_CUR);
						fscanf(f1,"%s",(a+i)->nm);
					}
					fclose(f1);
					flag=1;
					for(i=1;i<=cnt;i++)
					{
						sprintf(text,"a%d.txt",i);
						fp=fopen(text,"r+");
						fscanf(fp,"%d",&((a+i-1)->count));
						fclose(fp);
					}
					printf("Election Continued");
					_getch();
					break;

					//TO DELETE VOTE FOR SELECTED PRN
					case '3':
					printf("Search PRN:");
					scanf("%s",prn);
					if(flag!=1)
					{
						if(ptr[rno-1]!=0)
						{	delFromfile(prn,ptr[rno-1]);
							ptr[rno-1]=0;
						}
					}
					else
					{
						delFromfile(prn,ptr[rno-1]);
					}
					break;

				//TO DISPLAY RESULT
				 case '4':
					//clrscr();
					i=0;
					max=(a+i)->count;
					while(i<cnt-1)
					{
						if((a+i)->count>max)
							max=(a+i)->count;
						i++;
					}
					i=0;j=0;
					for(i=0;i<cnt-1;i++)
					{
						if(max==(a+i)->count)
						      j++;
					}
					if(j>1)
						printf("\n\n\n\t\tTIE");
					else
					{
						for(i=0;i<cnt-1;i++)
						{       if(max==(a+i)->count)
							{	printf("\n\n\n\t\t__________________________________________________");
								printf("\n\n\t\t      WINNER is %s with %d votes",(a+i)->nm,(a+i)->count);
								printf("\n\t\t__________________________________________________");
							 }
						}
					}
					tot=0;i=0;
					for(i=0;i<cnt;i++)
						tot+=((a+i)->count);
					printf("\n\n\n\t\t\t   Election statistics:\n");
					i=0;
					while(i<cnt)
					{
						printf("\n\t\t\tVotes for %s= %d",(a+i)->nm,(a+i)->count);
						i++;
					}

					printf("\n\n\t\t\tVoting Percentage:%0.2f %",(tot/maxrollno)*100);
					//printf("\n\t\t\tTotal Illegal attempts:%d",false);
					_getch();
				      //	flcreate(cnt);
					break;

				case '5':
					return;

				default:
					printf("Invalid Option");
					_getch();

				}
			}
		}
	}
}
}
*/
//#include<C:\Abishai\SecureC_project\Student.h>
/*
//Student Panel

void stu()
{
	FILE *fp,*f1;
	CAND *b;

	//char prn[15],text[20],d;
	//char str[16],vprn[16];
	//DCL04-C not more than 1 var per declaration
	char prn[15];
	char text[20];
	char d;
	char str[16];
	char vprn[16];
	char stp[2]="0";
	int flg=1;
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

	b=a;

	while(1)
	{
			prn:
			//clrscr();
			printf("\n\n  To exit press 0");
			printf("\n  Please Don't Use Capital Letters");
			printf("\n  Enter PRN no:");
			scanf("%s",prn);
			if(strcmp(stp,prn)==0) //EXP20-C explicitly check if condition.
				return;
			len=strlen(prn);
			if(len<14||len>14)
			{
				printf("\nInvalid PRN(Incorrect length)\nTry Again(Press Enter)");
				_getch();
				continue;
			}
			val=isSpecial(prn);
			if(val==1)
			{
				printf("\n  Blank number");
				_getch();
				false1++;
				continue;
			}
			res=isAuthentic(prn);
			if(res!=1)
			{
				printf("\n  Try Again(Press Enter)");
				_getch();
				continue;
			}
			else
			{
				num=cnt;
				if(flag!=1)
				{	if(ptr[rno-1]!=0) //EXP20-C explicitly check if condition.
					{
						printf("\n  Your PRN entered is already voted\n  Contact Admin for furthur query");
						_getch();
						continue;
					}
				}
				else
				{
				     //	checkfile:
					while(k<num)
					{
						sprintf(text,"a%d.txt",k+1);
						fp=fopen(text,"r");
						flg=1;
						while(flg)
						{
							fgets(str,99,fp);
							for(i=0;i<(strlen(str)-1);i++)
								vprn[i]=str[i];
							vprn[i]='\0';
							if(strcmp(prn,vprn)==0) //EXP20-C explicitly check if condition.
							{
								printf("\n  The PRN %s has already voted\nContact Admin if it weren't you...!",prn);
								fclose(fp);
								_getch();
								goto prn;
							}
							if(feof(fp) != 0)  //EXP20-C explicitly check the if condition.
							{
								flg=0;
								fclose(fp);
							}
						}
						k++;

					 }

				}
				printf("\n\n  Candidates for election:");
				j=1;
				for(i=0;i<num;i++)
				{
					printf("\n  %d. %s",j,(b+i)->nm);
					j++;
				}
				vote :
				 while(1)
				 {
					printf("\n\n  Your Vote(Enter Number):");
					v1=_getch();
					printf("*");
					_getch();
					printf("\n  Confirm Your Vote:");
					v2=_getch();
					printf("*");
					if(v1==v2)
						break;
					else
					{
					  //	_getch();
						printf("\n\n   Mismatch(Try Again)");
						continue;
					}
				}

				if((v1-48)>num)
				{
					printf("\n  Invalid vote");
					_getch();
					goto vote;
				       //	break;
				}
				else
				{
					printf("\n\nThanks for your precious vote(Press Enter)");


					ptr[rno-1]=(v1-48);
					_getch();
					for(j=0;j<num;j++)
					{
						if((v1-48)==(j+1))
						{
							(a+j)->count++;
							sprintf(text,"a%d.txt",(j+1));
							fp=fopen(text,"r+");
							fprintf(fp,"%d",(a+j)->count);
							fseek(fp,0,SEEK_END);
							fprintf( fp ,"%s", prn);
							fputs("\n",fp);
							fclose(fp);
						}
					}
				}
			}

	}

}
*/


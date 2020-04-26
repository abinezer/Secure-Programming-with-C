#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<C:\Abishai\SecureC_project\PbAbi.h>
#include<C:\Abishai\SecureC_project\PbAbi2.h>

int* ptr;
//Admin Panel
void admin()
{
	FILE* f1, * fp, * fpb;
	//char user[15],pass[15],prn[15],text[20],nm[50],ch,sp;
	//DCL04-C Not more than 1 var per declaration.
	char user[15];
	char pass[15];
	char prn[15];
	char text[20];
	char nm[50];
	char ch;
	char sp;
	char str1[6] = "Admin";
	char str2[8] = "SR@3111";
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
	float tot = 0.0;
	char null[2] = "0";
	// INT01-C use size_t to represent the size of an object
	size_t cand_size = sizeof(CAND);
	while (1)
	{
		//clrscr();
		printf("\nEnter username: ");
		scanf("%s", user);
		if ((strcmp(user, str1)) != 0) //EXP20-C explicitly check if condition.
		{
			printf("Wrong Username");
			_getch();
			continue;
		}
		else
		{
		password:
			printf("Enter Password: ");
			for (i = 0; i < 7; i++)
			{
				pass[i] = _getch();
				printf("%c", '*');
			}
			pass[i] = '\0';
			if ((strcmp(pass, str2)) != 0) //EXP20-C explicitly check if condition.
			{
				printf("\nWrong Password\n");
				_getch();
				goto password;
			}
			else
			{

				printf("\n\nADMIN LOGIN SUCCESSFULL(Press Enter)");
				_getch();
				while (1)
				{
					//clrscr();
					printf("\n1.New Election\n2.Continue Previous Election\n3.Delete Illegal Vote\n4.Result\n5.Logout\nOption:");
					scanf(" %c", &ch);
					switch (ch)
					{
						//TO TAKE NEW ELECTION
					case '1':
						//clrscr();
						printf("\nNew Election Initiation:\n");
						f1 = fopen("PreviousElection.txt", "w");
						printf("\nElections for which Year: ");
						scanf("%d", &year);
						printf("Enter branch code:");
						scanf("%s", branch);
						printf("Enter max roll no.:");
						scanf("%d", &maxrollno);
						printf("Enter the no. of candidates:");
						scanf("%d", &no);
						ptr = (int*)malloc((maxrollno) * sizeof(int));
						for (i = 0; i < maxrollno; i++)
							ptr[i] = 0;
						fprintf(f1, "%d\n%s\n%d\n%d", year, branch, maxrollno, no);
						fclose(f1);
						flcreate(no);
						a = (CAND*)malloc(no * cand_size);
						cnt = no;

						i = 0; j = 1;
						while (i < no)
						{
							printf("\n  %d.", j);
							candname((a + i));
							i++; j++;
						}

						while (1)
						{
							//clrscr();
							printf("\nPress 1 to exclude special PRNs\n(Press 0 to exit)");
							printf("\nOption:");
							scanf(" %c", &sp);
							if (sp == '0')
								return;
							else {
								if (sp == '1')
								{
									fpb = fopen("blank.txt", "w");
									if (fpb == NULL)
									{
										printf("\nProcess Failed");
										_getch();
										break;
									}
									printf("\nEnter 0 to stop\nEnter blank");
									while (strcmp(prn, null) != 0)
									{
										printf("PRN:");
										scanf("%s", prn);
										fprintf(fpb, "%s", prn);
										fputs("\n", fpb);
										printf("\n");
									}
									sprintf(prn, "null");
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
						f1 = fopen("PreviousElection.txt", "r");
						if (f1 == NULL)
							printf("Not Exist");
						fscanf(f1, "%d", &year);
						fseek(f1, 2, SEEK_CUR);
						fscanf(f1, "%s", branch);
						fseek(f1, 2, SEEK_CUR);
						fscanf(f1, "%d", &maxrollno);
						fseek(f1, 2, SEEK_CUR);
						fscanf(f1, "%d", &cnt);
						a = (CAND*)malloc(cnt * cand_size);
						// INT01-C use size_t to represent the size of an object
						for (i = 0; i < cnt; i++)
						{
							fseek(f1, 2, SEEK_CUR);
							fscanf(f1, "%s", (a + i)->nm);
						}
						fclose(f1);
						flag = 1;
						for (i = 1; i <= cnt; i++)
						{
							sprintf(text, "a%d.txt", i);
							fp = fopen(text, "r+");
							fscanf(fp, "%d", &((a + i - 1)->count));
							fclose(fp);
						}
						printf("Election Continued");
						_getch();
						break;

						//TO DELETE VOTE FOR SELECTED PRN
					case '3':
						printf("Search PRN:");
						scanf("%s", prn);
						if (flag != 1)
						{
							if (ptr[rno - 1] != 0)
							{
								delFromfile(prn, ptr[rno - 1]);
								ptr[rno - 1] = 0;
							}
						}
						else
						{
							delFromfile(prn, ptr[rno - 1]);
						}
						break;

						//TO DISPLAY RESULT
					case '4':
						//clrscr();
						i = 0;
						max = (a + i)->count;
						while (i < cnt - 1)
						{
							if ((a + i)->count > max)
								max = (a + i)->count;
							i++;
						}
						i = 0; j = 0;
						for (i = 0; i < cnt - 1; i++)
						{
							if (max == (a + i)->count)
								j++;
						}
						if (j > 1)
							printf("\n\n\n\t\tTIE");
						else
						{
							for (i = 0; i < cnt - 1; i++)
							{
								if (max == (a + i)->count)
								{
									printf("\n\n\n\t\t__________________________________________________");
									printf("\n\n\t\t      WINNER is %s with %d votes", (a + i)->nm, (a + i)->count);
									printf("\n\t\t__________________________________________________");
								}
							}
						}
						tot = 0; i = 0;
						for (i = 0; i < cnt; i++)
							tot += ((a + i)->count);
						printf("\n\n\n\t\t\t   Election statistics:\n");
						i = 0;
						while (i < cnt)
						{
							printf("\n\t\t\tVotes for %s= %d", (a + i)->nm, (a + i)->count);
							i++;
						}

						printf("\n\n\t\t\tVoting Percentage:%0.2f ", (tot / maxrollno) * 100);
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
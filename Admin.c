#include<stdio.h>
#include<curses.h>
#include<string.h>
#include<stdlib.h>
#include</home/abishai/Documents/Secure-Programming-with-C/PbAbi.h>
#include</home/abishai/Documents/Secure-Programming-with-C/PbAbi2.h> //PRE08-C. Guarantee that header file names are unique

//MSC00-A. Compile cleanly at high warning levels
int* ptr; int flag;
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
	//char nm[50];
	char ch;
	char sp;
	//DCL32-C. Guarantee identifiers are unique

	//char str2[8] = "SR@3111";
	//char str1[6] = "Admin";
	//STR05-A. Prefer making string literals const-qualified
	//any attempt made to change these leads to an error
	char const str1[6] = "Admin";
	//EXP31-C. Do not modify constant values
	//STR31-C. Guarantee that storage for strings has sufficient space for
	//character data and the null terminator

	char const str2[8] = "SR@3111";
	//STR30-C. Do not attempt to modify string literals
	//DCL03-A. Place const as the rightmost declaration specifier
	//int i,no,yr,n,j,max,opt,no1;
	//DCL04-C Not more than 1 var per declaration.
	int i;
	int no;
	//int yr;
	//int n;
	int j;
	int max;
	//int opt;
	//int no1;
	float tot = 0.0;
	char null[2] = "0";
	// INT01-C use size_t to represent the size of an object
	size_t cand_size = sizeof(CAND);
	while (1)
	{
		//clrscr();
		printf("\nEnter username: ");
		scanf("%s", user);
		if ((strcmp(user, str1)) != 0)
			//EXP20-C explicitly check if condition.
		{
			printf("Wrong Username");
			getchar();
			continue;
		}
		else
		{
		password:
			printf("Enter Password: ");
			for (i = 0; i < 7; i++)
			{
				pass[i] = getchar();
				printf("%c", '*');
			}
			pass[i] = '\0';
			if ((strcmp(pass, str2)) != 0)
				//EXP20-C explicitly check if condition.
			{
				printf("\nWrong Password\n");
				getchar();
				goto password;
			}
			else
			{

				printf("\n\nADMIN LOGIN SUCCESSFULL(Press Enter)");
				getchar();
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
						//FIO31-C. Do not simultaneously open the same file multiple times
						printf("\nElections for which Year: ");
						scanf("%d", &year);
						printf("Enter branch code:");
						scanf("%s", branch);
						printf("Enter max roll no.:");
						scanf("%d", &maxrollno);
						printf("Enter the no. of candidates:");
						scanf("%d", &no);

						//ptr = (int*)malloc((maxrollno) * sizeof(int));
						//MEM02-A. Do not cast the return value from malloc()
						ptr = (int*)malloc((maxrollno) * sizeof(int));

						//MEM03-A. Clear sensitive information stored in dynamic memory prior to
						//deallocation

						//MEM31-C. Free dynamically allocated memory exactly once
						//MEM34-C. Only free memory allocated dynamically


						for (i = 0; i < maxrollno; i++)
							ptr[i] = 0;
						fprintf(f1, "%d\n%s\n%d\n%d", year, branch, maxrollno, no);
						fclose(f1);
						flcreate(no);
						//ARR31-C. Use consistent array notation across all source files
						a = (CAND*)malloc(no * cand_size);
						//MEM01-A. Set pointers to dynamically allocated memory to NULL after they
						//are released
						//MEM31-C. Free dynamically allocated memory exactly once
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
									//FIO06-A. Create files with appropriate access permissions
									//FIO11-A. Take care when specifying the mode parameter of fopen()
									if (fpb == NULL)
									{
										printf("\nProcess Failed");
										getchar();
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
									getchar();
								}
							}
						}

						return;

						//MSC04-A. Use comments consistently and in a readable fashion
						//TO CONTINUE PREVIOUS ELECTION
					case '2':
						f1 = fopen("PreviousElection.txt", "r");
						//FIO11-A. Take care when specifying the mode parameter of fopen()
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
						//DCL01-A. Do not reuse variable names in sub-scopes
						for (i = 1; i <= cnt; i++)
						{
							sprintf(text, "a%d.txt", i);
							fp = fopen(text, "r+");
							//FIO31-C. Do not simultaneously open the same file multiple times
							fscanf(fp, "%d", &((a + i - 1)->count));
							fclose(fp);
						}
						printf("Election Continued");
						getchar();
						break;
						//MSC07-A. Detect and remove dead code
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
						//MSC13-A. Detect and remove unused values
						//MSC12-A. Detect and remove code that has no effect
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
						getchar();
						//	flcreate(cnt);
						break;

					case '5':
						return;

					default:
						printf("Invalid Option");
						getchar();

					}
				}
			}
		}
	}
}
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include<unistd.h>  //  for the  sleep  function  
#define MAX 100
int  verify_content() //  verify if the  voters  file  vontains  registered  voters  
{
	char line[100];
	FILE* file;
	file=fopen("Voters_CIN.txt","r");
	if(file==NULL)
	{
		printf("Could  not  open file  \n");
	}
	else  
	{
		while(fgets(line,sizeof(line),file)==NULL)
		{
		return  strlen(line);	
		}
	}
}
int  cin_registration(char  cin[])
{
	  char  line[100];
	  FILE* file =fopen("Voters_CIN.txt","r");
	  if(file==NULL)
	  {
	  	printf("Cannot  open  file  to  read  \n");
	  }
	  else
	  {
	
	  while(fgets(line ,sizeof(line),file)!=NULL)
	  {
	  	if(strstr(line,cin)!=NULL)
	  	{
	  		return  0; //  return  0  if   ound  
		  }
	return  1; //   return   1  if  not  found  
	  }
	}  
}
int  Percentage_result()
{
		double  T_num=0;
	double num=0; //  total  number of  voters 
	FILE* file;
	FILE *file1;
	char  line[100];
	file=fopen("Voters_CIN.txt","r");
	if(file==NULL)
	{
		printf("Could  not  open file  \n");
	}
	else  
	{
		while(fgets(line,sizeof(line),file)!=NULL)
		{
			if(isspace((unsigned char)*line))
			{
				T_num=T_num;
			}
			else
			T_num++;
		}
	fclose(file);
	file1=fopen("voters.txt","r");
	if(file1==NULL)
	{
		printf("Could  not  open file  \n");
	}
	else  
	{
		while(fgets(line,sizeof(line),file)!=NULL)
		{
			if(isspace((unsigned char)*line))
			{
				num=num;
			}
			else
			num ++;
		}
		fclose(file1);
	}
	}
	double  result= num / T_num;
	double result1=result*100;
printf("*****Percentage Voting  result *******\n");
printf("Total  number  of  voters  %.2lf\n",T_num);
printf("Total  number  of  voters  who voted  %.2lf\n",num);
if(T_num==0&&num==0)
{
	printf("Percentage  vote  0\n");
}
else if(T_num==0)
{
	printf("Math error \n");
}
else if(T_num<num)
{
		printf("Error  percentage  can  never  be  more than  100 \n");
}
else 
{
printf("Percentage  vote  %.2lf\n",result1);
}
}
int verify_CIN(char cin[]) {
    FILE *file;
    char line[100];
    file = fopen("voters.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file\n");
        return 0;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        if (strstr(line, cin) != NULL) {
            fclose(file);
            return 1;  // CIN found
        }
    }
    
    fclose(file);
    return 0;  // CIN not found
}

void register_voters(char cin[]) {
    FILE *file;
    file = fopen("voters.txt", "a");  // Append mode to preserve previous voters

    if (file == NULL) {
        printf("Could not open file\n");
        return;
    }

    fprintf(file, "%s\n", cin);
    fclose(file);
}

void candidate_registration(char name[][MAX], int num) {
    char filename[100];
    FILE *file;

    for (int i = 0; i < num; i++) {
        snprintf(filename, sizeof(filename), "Candidate_%d.txt", i + 1);
        file = fopen(filename, "w");

        if (file == NULL) {
            printf("Error: Could not open Candidate_%d.txt for registration\n", i + 1);
        } else {
            fprintf(file, "%s\n", name[i]);
            fclose(file);
        }
    }
}

void display_candidate(char name[][MAX], int num) {
    printf("THESE ARE THE VARIOUS CANDIDATES:\n");

    for (int i = 0; i < num; i++) {
        printf("%d. Candidate: %s\n", i + 1, name[i]);
    }
}

void duration_of_system(char name[][MAX], int num) {
    FILE *file;
    int age, choice1, duration;
    int voters[MAX] = {0};  // Array to store votes for each candidate
    int max = 0, winner_index = -1;
    char cin[10];

    time_t start_time, current_time;

    printf("Enter the duration of the voting system:\n");
    printf("1. Minutes\n2. Hours\n3. Days\n");
    scanf("%d", &choice1);

    printf("Enter the duration: ");
    scanf("%d", &duration);

    if (duration < 0) {
        printf("Error: Duration cannot be less than 0\n");
        return;
    }

    if (choice1 == 1) {
        duration *= 60;
    } else if (choice1 == 2) {
        duration *= 3600;
    } else if (choice1 == 3) {
        duration *= 86400;
    }
  time(&start_time);
    while (1) {
        time(&current_time);
        if (difftime(current_time, start_time) >= duration) {
            printf("\nTime is up!\n");
            printf("***** Voting Results *****\n");

            for (int i = 0; i < num; i++) {
                printf("Candidate %s had %d votes\n", name[i], voters[i]);

                if (voters[i] > max) {
                    max = voters[i];
                    winner_index = i;
                }
            }
Percentage_result();
            if (winner_index != -1) {
                printf("The winner is %s with %d votes!\n", name[winner_index], max);
            }
            break;
        }

        printf("\nEnter your CIN to vote: ");
        scanf("%s",cin);
 if (strlen(cin)>10||strlen(cin)<10){
            	printf("CIN  number  must  be    10 digit\n");
            continue;
        }
else if(verify_CIN(cin) ==1)
{
	     printf(" Already used CIN!\n");
	continue; 
}
        printf("Enter your age: ");
        scanf("%d", &age);

        if (age < 18) {
            printf("You are too young to vote!\n");
        } else if (age >= 18 && age <= 70) {
            printf("You are eligible to vote.\n");
            display_candidate(name, num);

            printf("Enter the number corresponding to your chosen candidate: ");
            scanf("%d", &choice1);

            if (choice1 >= 1 && choice1 <= num) {
                voters[choice1 - 1]++;
                register_voters(cin);
            } else {
                printf("Invalid choice. Vote not counted.\n");
            }
        } else {
            printf("You are too old to vote!\n");
        }
        sleep(1);
    }
}

int main() {
    char name[MAX][MAX];
    int num;
if(verify_content==0)
{
	printf("No voters  has registered  \n");
	return  0;
}
    printf("Enter the number of candidates: ");
    scanf("%d", &num);
if(num==1)
{
	printf("WE  Cannot  have  only  one  candidate  \n");
	
}
else  if(num<0)
{
	printf("Fatal  error  verify the  number  of  candidate  \n");
}
    for (int i = 0; i < num; i++) {
        printf("Enter the Name of candidate number %d: ", i + 1);
        scanf("%s", name[i]);
    }

    candidate_registration(name, num);
    duration_of_system(name, num);
    return 0;
}
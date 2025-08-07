#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int  register_CIN(char cin[])
{
	FILE* file;
	file=fopen("Voters_CIN.txt","a");  //  openthe file  in write  mode  
if(file==NULL)
{
	printf("Could  not  open  file (Voters_CIN.txt)\n");// 
	}
	else  
	{
		fprintf(file,"12345%s\n",cin);  //  write  in the  file 
		printf("Candidate register  successfully\n");  //   display  the  message  on the  screen 
		fclose(file);  //  close the  file 
		}	
}
 int  display_voter()
  {
  	char line[100];
  	FILE* file=fopen("Voters_CIN.txt","r");
  	if(file==NULL)
  	{
  		printf("Could  not  open file  (Voters _CIN)\n");
	  }
	  else 
	  {
	  	printf("Here  are  those  who  register  succcessfully\n");
	  	while(fgets(line,sizeof(line),file)!=NULL)
	  	{
	printf("%s\n",line);
		  }
	  }
  }
  int  check_CIN(char cin[])
  {
  	char  line[100];
  	FILE* file;
  	file=fopen("Voters_CIN.txt","r");
  	if(file==NULL)
  	{
  		printf("Could  not open file  \n");
	  }
	  else  
	  {
	  	while(fgets(line,sizeof(line),file)!=NULL)
	  	{
	  		if(strstr(line,cin)!=NULL)
	  		{
	  			return  1;
	  			fclose(file);
			  }
		  }
	  }
  }
int main()
{
	int  num;
	int  failed=0;
	int  success=0;
	char cin[100];
	 printf("WELCOME  TO THE  REGISTRATION  PROGRAM !!!!\n");
	 printf("\n");
	 printf("******************************************\n");
	printf("Enter the  number  of  voters  to  register  :\n");
	scanf("%d",&num);
	for(int i=1;i<=num;i++)
	{
	printf("Enter the  voters  CIN 	:12345");
	scanf("%s",&cin);
	if(isdigit(cin[0])&&strlen(cin)==5)
	{
		if(check_CIN(cin)==1)
		{
			printf("Voters  CIN cannot  be  thesame  \n");
				failed+=1;
			continue;
	}
		register_CIN(cin);
		success+=1;
		}
		else 
		{
			printf("Invalid  CIN\n"); //  invalid  CIN 
			printf("Candidate  didnot  register Try   later !!!  \n");
			failed+=1;
			}	
}
printf("\n\n");
printf("**********Result  of  registration***********\n");
printf("Total  number of  voters  who present for the registration is  %d\n",num);	
printf("Number who  register  successfully  %d \n",success);
printf("Number  who   didnot  register %d\n",failed);
if(failed==0)
{
	printf("Everbody  register  successfully\n");
}
else 
{
	printf("Every  body  did  not register \n");
	 display_voter();
}
}

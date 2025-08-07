#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h> // for the  gecth  function  
     #define  MAX  100
   int  verify_CIN(char  cin[]) //  unc*tion ot verify  the  Cin of the  Voter
   {
   	FILE* file;
   	FILE* file1;
   	char line[100];
   	file=fopen("Voters_CIN.txt","r");
   	if(file==NULL)
   	{
   		printf("Could  not open  file  Voters_CIN.txt\n");
   		return 0; //  exit if  could  not  open  file  
	   }
	   else 
	   {
	   	while(fgets(line,sizeof(line),file)!=NULL) //  reads the  file  line  by  line
	   	{
	   		if(strstr(line,cin)!=NULL)  //  look for  the  occurence  of  cin  in  line  
	   		{
	   		return  1; //  if  found  return  1
	   			fclose(file); //  close The  file  
			   }
		   }
		   printf("CIN  not  register  \n");
	   }
   }
   int  digit_length_verification(char  cin[]) //  function to verify   if the cin is   a digit   and  has length    10
   {
   	if(isdigit(cin[0])&&strlen(cin)==10)  //  use is digit function  to verify  if it  is a digut  
   	{
   		return 1; //  return 1 if the condidtion is  ok  
	   }
	   else  
	   {
	   	printf("Invalid CIN \n");
	   	return  0;  // retunr  0 if the condition is  not  ok  
	   }
   } 
   int verify_cin1(char  cin[])  //  verify  if the  ntered cin  has  not  already vote  
   {
   	char line[100];
   	FILE* file =fopen("voters.txt","r");
   	if(file==NULL)
   	{
   		printf("Could  not  open  file  Voters.txt\n");
   		return  0;  // return  0 if  could  not  open file  
	   }
	   else 
	   {
	   	while(fgets(line,sizeof(line),file)!=NULL)
	   	{
	   		if(strstr(line,cin)!=NULL)
	   		{
	   			printf("CIN  already  used  \n");
	   			return  1; //  if  found return  1 and  exit  
	   			fclose(file );  //  close the file  
			   }
		   }
		   return  0  ;  //  if  not  found 
	   }
   }
   int  register_used_CIN(char  cin[])  // functio to register the CIN which has been used  
   {
   	FILE* file;
   	file=fopen("voters.txt","a"); // open the  file in  appent mode 
   	if(file==NULL)
   	{
   		printf("could  not  open file to register  CIN \n");
	   }
	   else 
	   {
	   	fprintf(file,"%s\n",cin);
	   	fclose(file);
	   }
   }
   int result(int  num,int  voter[],char name[][MAX])
   {
   		char  line[100];
	double num2;
	double   num1;
	FILE* file=fopen("Voters_CIN.txt","r");
	if(file==NULL)
	{
		printf("Could  not open file  \n");
		return 0;
	}
	else  
	{
		while(fgets(line,sizeof(line),file)!=NULL)
		{
				if(isspace((unsigned char)*line))
			{
				num2=num2;
			}
			else
			num2=num2+1;
		}
		fclose(file);
		}
	FILE* file1=fopen("voters.txt","r");
	if(file1==NULL)
	{
		printf("Could  not  open file \n");
	}
	else  
	{
		while(fgets(line,sizeof(line),file)!=NULL)
		{
					if(isspace((unsigned char)*line))
			{
				num1=num1;
			}
			else
			num1++;
		}
		fclose(file1);
		}
	  printf("*********** GENERAL  RESULT*************!!!\n");  // print  the general result  
printf("NUmber of  those  who  register  %.2lf\n",num2);
printf("Number  of those  who voted  %.2lf \n",num1);
printf("Percentage  voted %.2lf percent\n",(num1/num2)*100);
printf("\n\n"); 
  printf("************Individual  result***********\n");   // print  individual result  for  each voter  
  for(int i=1;i<=num;i++)
  {
  	printf("Candidate %s  had %d  votes  given a percentage  of  %.2lf  percent\n",name[i],voter[i],(voter[i]/num2)*100);   // display the number of  votes each  candidate  had 
  }
   }
   int  voting_function(int  num,char name[][MAX]) // general  function  
   {
   	char cin[10];  // to get  CIN of  voters  
   	int  age;  // age  of the  voter 
   	int  voters[num]; // an  array  to  store  number of  votes  of each  voter 
   	int  winner_index;  
   	int choice=0;//  set  choice  to  zero  
   	for(int i=0;i<=num;i++)
   	{
   		voters[i]=0;  // set  all the  voters to  0 count  
	   }
	      	int max=voters[0];  // set  max  vote  to  vote[0]
   	while(1)
   	{
   	printf("Enter the  voters CIN  \n");  // enter  your  CIN to  vote  <18
   	scanf("%s",&cin);
   		if(strcmp(cin,"end")==0)  goto label1; 
   	printf("Enter your  age  :\n");
   	scanf("%d",&age);
   	if(age<18)  // verifies the  voters  age  if 
   	{
   		printf("You cannot  vote you are  too  young \n");
   		continue;
	   }
	   else  if(age>=18&&age<=75)
	   {
	   	printf("You can  vote\n");
   	if(strcmp(cin,"end")==0)  //  condition to  end the  voting session  
{
	label1:
	printf("********************Voting  Result *********************\n");   //print  result at the  end  of  th  voting  session 
	for(int i=1;i<=num;i++)
	{
		printf("Candidate %s had %d  votes \n",name[i],voters[i]);
		if(max<voters[i])
		{
			max=voters[i];
			winner_index=i;
		}
}
result(num,voters,name);
	printf("The winner is  %s with %d  votes  \n",name[winner_index],max); // display  the   winner  of the  voting session  
	printf("Congratulations ************* \n");  // remark  
	break;
}
   else if(verify_CIN(cin)==1&&verify_cin1(cin)==0&& digit_length_verification(cin)==1)  //  verify the  user  CIN  if  correct 
   	{ 
	   printf("Here are the various  candidate  \n") ;
   	for(int  i=1;i<=num;i++)
   	{
   		printf("%d  Candidate :%s\n",i,name[i]);
	   }
	   printf("Enter the  number corresponding to the  candidate  you which  to  vote(Nb  enter  0 to  make  a null  vote) "); // choose  who you want to  vote 
	scanf("%d",&choice);
	if(choice==0)
	{
		register_used_CIN(cin); 
	}
	else if(choice>=1&&choice<=num)
	{
		voters[choice]++;
	register_used_CIN(cin);
	}
	else 
	{
		printf("This was consider as  a null vote  \n");
		register_used_CIN(cin);
	}
	   }
}
else if(age>75) 
{
	printf("You are  too old to  vote  \n");
	continue;
}

}
}
int  main ()
{
	int  num;  // represent  the  number of  candidate  
	char name[MAX][MAX];  // to  store the  candidate  names 
	char  filename[100];
	FILE* file ;
	label1:
printf("Enter the  number of  candidate  present  for the  election  \n");
	scanf("%d",&num);
	if(num==1)  // verify  if  num  is  equal  to  0
	{
		printf("Sorry  we  cannot have  only  1 candidate  \n");
		goto label1;
	}
else  if(num<0)  //  verifie  if  num is not  less than  0
{
	printf("FATAL  EROOOR  candidate  number  cannot  be less than  0");
	goto  label1;
}
else 
{
	for(int i=1;i<=num;i++)
	{
		printf("Enter the   name  of  candidate %d \n",i); 
		scanf("%s",&name[i]);
	snprintf(filename,sizeof(filename),"Candidate_%d.txt",i);  //  create  a  constant  string  character
file=fopen(filename,"w");  //  open the  file  in Wirite  mode 
if(file==NULL)
{
printf("Could  not  open file  to register  candidate  name  \n");
return  0;  // exit if could  not  register  candidate  name 	
	}
	else  
	{
		fprintf(file,"%s",name[i]);  // write  each  name  in the  file  
		}	
}
fclose(file);  // close the  file 
}
 voting_function(num,name);  // called the  voting  function for iteration
}
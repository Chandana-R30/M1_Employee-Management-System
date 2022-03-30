#include<stdio.h>
#include <stdlib.h>

static int n=0;
struct EMPLOYEE
{
	int empID,age,salary,bonus,total;
	char name[10];
	
};
int main()
{
	void add();
	void password();
	void displayAll();
	void record();
	void del();
	void salarysheet();
	void modify();
	int i,count=0,a,n=0,r,m,ms;
	printf("\n\t\t\t\t********************************************************\n");
	printf("\n\t\t\t\t\t\t   EMPLOYEE RECORD SYSTEM\n");
	printf("\n\t\t\t\t********************************************************\n");

		while(1)
		{
		printf("\n----------------------");
		printf("\nChoose any option from below");
		printf("\n----------------------");
		printf("\n1.Add a record");
		printf("\n2.Delete a record");
		printf("\n3.Modify a record");
		printf("\n4.Salarysheet");
		printf("\n5.Search a record");
		printf("\n6.Display all records");
		printf("\n7.Exit");
		printf("\n----------------------\n");
		scanf("%d",&a);
		switch (a)
		{
			case 1:
			{
				
				add();	
				break;
			}
			case 2:
			{	
				
				del();
				break;
			}
			case 3:
			{
				
				modify();
				break;
			}
			case 4:
			{
				salarysheet();
				break;	
			}
			case 5:
			{
				record();
				break;
			}
			case 6:
			{
				displayAll();
				break;
			}
			case 7:
			{
				exit(0);
			}
				
		}
	}	
}
void add()
{
		int i;
		struct EMPLOYEE s;
		int size;
		FILE *fp;
		size=sizeof(s);
		fp=fopen("record.dat","ab");
 		printf("\nEnter employee identfication number for record\n");
		scanf("%d",&s.empID);
		printf("Enter Name\n");
		scanf("%s",s.name);
		printf("Enter Age\n");
		scanf("%d",&s.age);
		printf("Enter salary\n");
		scanf("%d",&s.salary);
		printf("Enter bonus\n");
		scanf("%d",&s.bonus);
		s.total=s.salary+s.bonus;
		fwrite(&s,size,1,fp);
		fclose(fp);	
		printf("\n New Record Successfully Added.");
}


void displayAll()
{
FILE *fp;
struct EMPLOYEE s;

fp=fopen("record.dat","rb");

printf("\n******************************************************\n\n");
printf("\t\t All Employee Details\n\n");
printf("********************************************************\n\n");


while(1)
{
fread(&s,sizeof(s),1,fp);

if(feof(fp))
{
break;
}
		printf("\nempID:%d\t",s.empID);
		printf("Name:%s\t",s.name);
		printf("Age:%d\t",s.age);
		printf("Total salary:%d\n",s.total);
}
printf("*********************************************************\n\n");

fclose(fp);
}
void record()
{
FILE *fp;
struct EMPLOYEE s;
int id,found=0;
fp=fopen("record.dat","rb");
printf("\nEnter the employee id no:");
scanf("%d",&id);
while(1)
{
fread(&s,sizeof(s),1,fp);
if(feof(fp))
{
break;
}
if(s.empID==id)
{
found=1;
printf("\n******************************************************\n\n");
printf("\t\t Employee Record of %d\n\n",s.empID);
printf("********************************************************\n\n");

		printf("empID:%d\t",s.empID);
		printf("Name:%s\t",s.name);
		printf("Age:%d\t",s.age);
		printf("TotalSalary:%d\n",s.total);

printf("*********************************************************\n\n");
}
}
if(found==0)
{
printf("\nNo Record Found");
}
fclose(fp);
}
void del()
{
FILE *fp,*fp1;
struct EMPLOYEE s,s1;
int id,found=0;

fp=fopen("record.dat","rb");
fp1=fopen("temp.dat","wb");

printf("\nEnter Employee Id to be Deleted:");
scanf("%d",&id);
while(1)
{
fread(&s,sizeof(s),1,fp);

if(feof(fp))
{
break;
}
if(s.empID==id)
{
found=1;
}
else
{
fwrite(&s,sizeof(s),1,fp1);
}
}
fclose(fp);
fclose(fp1);

if(found==0)
{
printf("No Record Found\n\n");
}
else
{
fp=fopen("record.dat","wb");
fp1=fopen("temp.dat","rb");

while(1)
{
fread(&s,sizeof(s),1,fp1);

if(feof(fp1))
{
break;
}
fwrite(&s,sizeof(s),1,fp);
}
}
fclose(fp);
fclose(fp1);
}
void salarysheet()
{
FILE *fp;
struct EMPLOYEE s;
int id,found=0;
fp=fopen("record.dat","rb");
printf("\nEnter the employee identification no:");
scanf("%d",&id);
while(1)
{
fread(&s,sizeof(s),1,fp);
if(feof(fp))
{
break;
}
if(s.empID==id)
{
found=1;
printf("\n******************************************************\n\n");
printf("\t\t Employee Salarysheet of %d\n\n",s.empID);
printf("********************************************************\n\n");

		printf("empID:%d\t",s.empID);
		printf("Name:%s\t",s.name);
		printf("Salary:%d\t",s.salary);
		printf("Bonus:%d\t",s.bonus);
		printf("Total salary:%d\t",s.total);
		

printf("**********************************************************\n\n");
}
}
if(found==0)
{
printf("\n No Record Found");
}
fclose(fp);
}
void modify()
{
FILE *fp,*fp1;
struct EMPLOYEE s;
int id,found=0;

fp=fopen("record.dat","rb");
fp1=fopen("temp.dat","wb");

printf("\nEnter Employee Id to be modified:");
scanf("%d",&id);

while(1)
{
fread(&s,sizeof(s),1,fp);

if(feof(fp))
{
break;
}
if(s.empID==id)
{
found=1;
		printf("Enter employee Id  No for record\n");
		scanf("%d",&s.empID);	
		//fflush(stdin);
		printf("Enter Name\n");
		scanf("%s",s.name);
		printf("Enter Age\n");
		scanf("%d",&s.age);
		printf("Enter Basic salary\n");
		scanf("%d",&s.salary);
		printf("Enter bonus salary\n");
		scanf("%d",&s.bonus);
		s.total=s.salary+s.bonus;
		
fwrite(&s,sizeof(s),1,fp1);
}
else
{
fwrite(&s,sizeof(s),1,fp1);
}
}
fclose(fp);
fclose(fp1);

if(found==0)
{
printf(" No Record Found\n\n");
}
else
{
fp=fopen("record.dat","wb");
fp1=fopen("temp.dat","rb");

while(1)
{
fread(&s,sizeof(s),1,fp1);

if(feof(fp1))
{
break;
}
fwrite(&s,sizeof(s),1,fp);
}

}
fclose(fp);
fclose(fp1);
}


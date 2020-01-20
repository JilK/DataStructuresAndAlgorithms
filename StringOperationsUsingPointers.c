#include<stdio.h>
#include<string.h>
void count(char *s);      
void substring(char *s);
int main()
{
char str[200];
char *p;             
p=&str;
printf("Enter a string: \n");
gets(str);
count(p);  
substring(p);
return 0;
}
void count(char *s)
{
int alpha=0,digit=0,space=0,spcl=0;
int i;
int l=strlen(s);
for(i=0;i<l;i++)
    {
if( (*(s+i)>='A' && *(s+i)<='Z') || (*(s+i)>='a' && *(s+i)<='z'))  // for alphabets
alpha++;
else if(*(s+i)>='0' && *(s+i)<='9')   // for numbers
digit++;
else if(*(s+i)==' ')   // for spaces
space++;
else
spcl++;  // for special characters
    }
printf("No. of digits in the string: %d\n",digit);
printf("No. of alphabets in the string: %d\n",alpha);
printf("No. of spaces in the string: %d\n",space);
printf("No. of special characters in the string: %d\n",spcl);
}
void substring(char *s)
{
int i,j,flag=0;
char substr[20];
printf("\nString: %s",s);
printf("\nEnter a substring: ");
gets(substr);
for(i=0;i<strlen(s);i++)
    {
flag=0;
for(j=0;j<strlen(substr);j++)
        {
if( *(s+i+j)!= *(substr+j))
            {
break;
            }
if(j == strlen(substr)-1)
            {
printf("substring found at index: %d \n",i);
            }
        }
    }
}

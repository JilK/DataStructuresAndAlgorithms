#include<stdio.h>
#include<conio.h>
int a[5],b[5],c[5];
int m,n,p,val,i,j,key,pos,temp;
void create();
void display();
void insert();
void del();
void merge();
int main()
{
int choice;
        do
            {

                printf("1.Create\n");
                printf("2.Display\n");
                printf("3.Insert\n");
                printf("4.Delete\n");
                printf("5.Merge\n");
                printf("6.Exit\n");
                printf("\nEnter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:         create();
                                        break;

                        case 2:         display();
                                        break;

                        case 3:         insert();
                                        break;

                        case 4:         del();
                                        break;

                        case 5:         merge();
                                        break;

                        case 6:         exit(0);
                                        break;

                        default:        printf("\nInvalid choice:\n");
                                        break;
                    }
        }
        while(choice!=6);
return 0;
}
void create()
{
        printf("\nEnter the size of the array elements:\t");
        scanf("%d",&n);
        printf("\nEnter the elements for the array:\n");
        for(i=0;i<n;i++)
        {
                scanf("%d",&a[i]);
        }
}
void display()
{
        int i;
        printf("\nThe array elements are:\n");
        for(i=0;i<n;i++)
            {
                 printf("%d\t",a[i]);
         }
 }
void insert()
{
    printf("\nEnter the position for the new element:\t");
    scanf("%d",&pos);
    printf("\nEnter the element to be inserted :\t");
    scanf("%d",&val);
    for(i=n-1;i>=pos;i--)
        {
                a[i+1]=a[i];
        }
        a[pos]=val;
        n=n+1;
}


void del()
{
        printf("\nEnter the position of the element to be deleted:\t");
        scanf("%d",&pos);
        val=a[pos];
        for(i=pos;i<n-1;i++)
        {
                a[i]=a[i+1];
        }
        n=n-1;
        printf("\nThe deleted element is =%d",val);
}

void merge()
{
        printf("\nEnter the size of the second array:\t");
        scanf("%d",&m);
        printf("\nEnter the elements for the second array:\n");
        for(i=0;i<m;i++)
        {
                scanf("%d",&b[i]);
        }
        for(i=0,j=0;i<n;i++,j++)
        {
                c[j]=a[i];
        }
        for(i=0;i<m;i++,j++)
        {
                c[j]=b[i];
        }
        p=n+m;
        printf("\nArray elements after merging:\n");
        for(i=0;i<p;i++)
        {
                printf("%d\t",c[i]);
        }
}


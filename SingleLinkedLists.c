#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *root=NULL;

int append();
void bubblesort(struct node *root);
int display();
int addatbegin();
int length();
int insert();
int del();

int main()
{
    int choice;

    do
    {
printf("Enter your choice:\n1.add at end\n2.add at begin\n3.length\n4.display\n5.insert\n6.delete\n7.bubblesort\n8.exit\n\n");
scanf("%d",&choice);
           switch(choice)
           {
               case 1:
                   {
append();
                    break;
                   }

               case 2:
                   {
addatbegin();
                      break;
                   }

               case 3:
                    {
                        int l=length();
printf("\nlength=%d\n",l);
                        break;
                    }
               case 4:
                    {
display();
                        break;
                    }
               case 5:
                    {
insert();
                        break;
                    }
               case 6:
                    {
del();
                        break;
                    }
               case 7:
                   {
bubblesort(root);
                        break;
                   }
               case 8:
                    {
printf("you have exited");
                        break;
                    }
           }

}while(choice!=8);

}

int append()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
printf("\nenter data\n");
scanf("%d",&temp->data);
    temp->link=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        struct node *p;
        p=root;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
    }

}
void bubblesort(struct node *root)
{
    int swapped, i;
    struct node *p1;
    struct node *p2 = NULL;
    int temp;

    if (root == NULL)
        return;

    do
    {
        swapped = 0;
        p1 = root;

        while (p1->link != p2)
        {
            if (p1->data > p1->link->data)
            {
                temp = p1->data;
                p1->data = p1->link->data;
                p1->link->data = temp;
                swapped = 1;
            }
            p1 = p1->link;
        }
        p2 = p1;
    }
    while (swapped);
}

int display()
{
    struct node *temp;
    temp=root;
    if(temp==NULL)
    {
printf("\nempty list\n");
    }
    else
    {
        while(temp!=NULL)
        {
printf("\n%d-->",temp->data);
            temp=temp->link;
        }
    }
printf("\n\n");
}

int addatbegin()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
printf("\nenter data\n");
scanf("%d",&temp->data);
    temp->link=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        temp->link=root;
        root=temp;
    }
}

int length()
{

        struct node *p;
        p=root;
        int count=0;
        while(p!=NULL)
        {
            p=p->link;
            count++;
        }
        return count;

}

int del()
{
    struct node *temp;
    int loc;
printf("\nenter location\n");
scanf("%d",&loc);
    if(loc>length())
    {
printf("\ninvalid location\n");

    }
    else if(loc==1)
    {
        temp=root;
        root=temp->link;
        temp->link=NULL;
        free(temp);
    }
else{
        struct node *p=root,*q;
        int i=1;
        while(i<loc-1)
        {
            p=p->link;
i++;
        }
        q=p->link;
        p->link=q->link;
        q->link=NULL;
        free(q);
    }

}

int insert()
{
    int loc,len,i=1;
    struct node *p,*temp;
printf("\nenterloc\n");
scanf("%d",&loc);
len=length();
    if(loc>len)
    {
printf("\ninvalid location\n");
printf("currently list is having %d locations\n,len");

    }
    else
    {
        p=root;
        while(i<loc-1)
        {
            p=p->link;
i++;
        }
        temp=(struct node*)malloc(sizeof(struct node));
printf("\nenter data\n");
scanf("%d",&temp->data);
        temp->link=p->link;
        p->link=temp;
    }
}

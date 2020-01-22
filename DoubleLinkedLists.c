#include<stdio.h>
#include<stdlib.h>
void append();
void bubblesort();
void display();
void addatbegin();
int length();
void insert();
void del();
struct node
{
int data;
struct node *right,*left;
};
struct node *root=NULL;

void main()
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
bubblesort();
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

void append()
{
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
printf("\nenter data\n");
scanf("%d",&temp->data);
temp->left=NULL;
temp->right=NULL;
if(root==NULL)
    {
root=temp;
    }
else
    {
struct node*p;
        p=root;
while(p->right!=NULL)
        {
            p=p->right;
        }
p->right=temp;
temp->left=p;
    }
}
void addatbegin()
{
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
printf("\nenter data\n");
scanf("%d",&temp->data);
temp->left=NULL;
temp->right=NULL;
if(root==NULL)
    {
root=temp;
    }
else
    {
temp->right=root;
root->left=temp;
root=temp;
    }
}
int length()
{
struct node *temp=root;
int count=0;
while(temp!=NULL)
  {
count++;
temp=temp->right;
  }
return count;
}
void display()
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
temp=temp->right;
        }
    }
printf("\n\n");
}
void insert()
{
struct node *temp,*p;
int loc,len,i=1;
printf("\nEnter location");
scanf("%d",&loc);
len=length();
if(loc>len)
    {
printf("Invalid location");
    }
else
    {
temp=(struct node *)malloc(sizeof(struct node));
printf("\nEnter node data");
scanf("%d",&temp->data);
temp->left=NULL;
temp->right=NULL;
        p=root;
while(i<loc-1)
        {
            p=p->right;
i++;
        }
temp->right=p->right;
p->right->left=temp;
temp->left=p;
p->right=temp;
    }

}
void del()
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
root=temp->right;
temp->left=NULL;
free(temp);
    }
else
    {
struct node *p=root,*q;
int i=1;
while(i<loc-1)
        {
            p=p->right;
i++;
        }
        q=p->right;
p->right=q->right;
        q->right->left=p;
free(q);
    }

}
void bubblesort()
{
int swapped;
struct node *p1;
struct node *p2 = NULL;
int temp;

if (root == NULL)
return;

do
    {
swapped = 0;
        p1 = root;

while (p1->right != p2)
        {
if (p1->data > p1->right->data)
            {
temp = p1->data;
                p1->data = p1->right->data;
                p1->right->data = temp;
swapped = 1;
            }
            p1 = p1->right;
        }
        p2 = p1;
    }
while (swapped);
}

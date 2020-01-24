#include<stdio.h>
void insert();
void del();
void display();
int a[50],front=-1,rear=-1;
void main()
{
int ch,n;
printf("enter the number of elements in queue\n");
scanf("%d",&n);
while(1){
printf("1.Insert\n2.Delete\n3.Display\n4.exit\n");
printf("enter the choice\n");
scanf("%d",&ch);
switch(ch)
        {
case 1:insert(n);break;
case 2:del(n);break;
case 3:display(n);break;
case 4:exit(1);break;
default:printf("invalid choice\n");
        }   }
getch();}
void insert(int n)
{
  if((front == 0 && rear == n-1) || (front == rear+1))
  {
    printf("Queue is full \n");
    return;
  }
  if (front == -1)
  {
    front = 0;
    rear = 0;
  }
  else
  {
    if(rear == n-1)
      rear = 0;
    else
      rear++;
  }
  int item;
  printf("enter the element to be inserted\n");
  scanf("%d",&item);
  a[rear] = item ;
}
void del(int n)
{
if (front == -1)
  {
    printf("Queue is empty\n");
    return ;
  }
  printf("Element deleted from queue is : %d\n",a[front]);
  if(front == rear)
  {
    front = -1;
    rear = -1;
  }
  else
  {
    if(front == n-1)
      front = 0;
    else
      front=front+1;
  }
}
void display(int n)
{
int i;
if (front == -1)
  {
    printf("Queue is empty\n");
    return ;
  }
else{
printf("the queue is ");
for(i=front;i<=rear;i++)
        {
printf(" %d ",a[i]);
printf("\n");
        }}}

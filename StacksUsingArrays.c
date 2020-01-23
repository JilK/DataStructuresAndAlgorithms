#include<stdio.h>
void push(int arr[]);
void pop(int arr[]);
void display(int arr[]);
int top;
top = -1;

int main()
{
    int arr[50],i,n;
    i=1;

    printf("--------------- STACK USING ARRAYS -------------------\n");
    while(i==1)
    {
        printf("\nEnter: \n");
        printf("1. to PUSH \n");
        printf("2. to POP \n");
        printf("3. to DISPLAY \n");
        printf("4. to EXIT \n");
        scanf("%d",&n);
        switch(n)
        {
            case 1: push(arr);
                    break;
            case 2: pop(arr);
                    break;
            case 3: display(arr);
                    break;
            case 4: i=2 ;
                    break;
           default: printf("Invalid number, enter a number from 1 to 4:\n");
        }
    }
    return 0;
}

void push(int arr[])
{
    if(top+1 == 50){
        printf("Stack is full! \n");
    }
    else{
    int n;
    printf("Enter a value: \n");
    scanf("%d",&n);
    top++;
    arr[top]=n;
    }
}

void pop(int arr[])
{
    if(top== -1){
        printf("Stack is empty. \n");
    }
    else{
    printf("Popped element: %d",arr[top]);
    top--;
    }
}
void display(int arr[])
{
    int i;
    for(i=0;i<=top;i++)
    {
        printf("%d -> ",arr[i]);
    }
}


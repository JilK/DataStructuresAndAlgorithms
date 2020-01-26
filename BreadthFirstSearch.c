#include <stdio.h>

void breadth_first_search(int adj[][5],int visited[],int start)
{
    int queue[5];
    int rear = -1;
    int front = -1;
    int i;
    queue[++rear] = start;
    visited[start] = 1;
    while(rear != front)
    {
        start = queue[++front];
        if(start == 5)
        printf("5\t");
        else
        printf("%c \t",start + 65);
        for(i = 0; i < 5; i++)
        {
            if(adj[start][i] == 1 && visited[i] == 0)
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}
int main()
{
    int visited[5] = {0};
    int adj[5][5], i, j;
    printf("\n Enter the adjacency matrix: ");
    for(i = 0; i < 5; i++)    for(j = 0; j < 5; j++)    scanf("%d", &adj[i][j]);
    breadth_first_search(adj,visited,0);
    return 0;
}

#include<stdio.h>
int mat[25][25],top=-1,stack[25],visited[25],size,flag=0;
int dfs(int currrent)
{
    int i;
    for ( i = 0; i < size; i++)
    {
        if (mat[currrent][i]==1)
        {
            if(visited[i]==0)
                return i;
        }
       
    }
    top--;
    if(top>-1)
        return dfs(stack[top]);
    else
    {
        flag=1;
        printf("\ncannot complete traversal\n");
       
    }
   
}
int main()
{
    int i, j,start,count=0,current;
    for ( i = 0; i < size; i++)
    {
        visited[i]=0;
    }
   
    printf("Enter number of elements in graph:");
    scanf("%d",&size);
    printf("Enter Adjacency matrix of Graph\n");
    for ( i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            scanf("%d",&mat[i][j]);
        }
       
    }
    printf("Enter which node to start:");
    scanf("%d",&start);
    printf("Order of traversal\n");
    current=start;
    visited[current]=1;
    top++;
    stack[top]=current;
    count++;
    printf("%d\t",current);
    while(count<size)
    {
       
        current=dfs(current);
        if(flag==1)
            break;
        visited[current]=1;
        top++;
        stack[top]=current;
        count++;
        printf("%d\t",current);
       

    }

   


}

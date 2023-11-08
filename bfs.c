#include<stdio.h>
int mat[25][25],front=-1,rear=-1,queue[25],visited[25],size,flag=0;
int main()
{
    int i, j,start,count=0,current,l,flag;
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
   
    front++;
    rear++;
    queue[rear]=current;
    count++;
    visited[current]=1;
    printf("%d\t",current);
    front++;
    while(count<size)
    {
       
        for ( i = 0; i < size; i++)
        {
            if (mat[current][i]==1)
            {
                if(visited[i]==0)
                {
                    flag=0;
                    for(l=front;l<=rear;l++)
                    {
                        if(queue[l]==i)
                        {  
                            flag=1;
                            break;
                        }      
                    }
                    if(flag==0)
                    {
                        rear++;
                        queue[rear]=i;
                    }  
                }
            }
        }
        current=queue[front];
        printf("%d\t",current);
        front++;
        count++;    
    }
}

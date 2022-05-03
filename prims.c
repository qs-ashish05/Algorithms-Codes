// for minimum spanning tree 

#include<stdio.h>

void prims(int n,int cost[10][10]){

    int u,v,min,mincost = 0,visited[10];
    int e =1;

    //  initializing visited
    for(int i =0;i<n;i++)
        visited[i] = 0;
    
    printf("\n the edges considered for MST are : ");
    visited[1] = 1;
    while (e<n)
    {
        for(int i=1,min=999;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(cost[i][j] < min){
                    if(visited[i] == 0)
                        continue;
                    else{
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if(visited[u] == 0 || visited[v] ==0){
            printf("%d Edge (%d,%d) = %d",e++,u,v,min);
            mincost = mincost + min;
            visited[v] = 1;
        }
        cost[u][v] = cost[v][u] = 999;
    }

    printf("\n Cost of constructing MST is %d",mincost);
    
}  // prims

int main(int argc, char const *argv[])
{
    int n,cost[10][10];

    printf("\nEnter no. of nodes :");
    scanf("%d",&n);

    printf("\nenter the adjacency mtx :");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    prims(n,cost);

    return 0;
}

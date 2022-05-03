#include <stdio.h>
#include <stdlib.h>
struct node
{
    int sourceNode;
    int destNode;
    int weight;
} n[10], out[10], temp;
int parent[10][10], v[10], noofVertices = 7, noofEdges = 9, op = 0;
void input()
{
    printf("enter no of vertices\n");
    scanf("%d", &noofVertices);
    printf("enter no of edges\n");
    scanf("%d", &noofEdges);
    for (int i = 1; i <= noofVertices; i++)
    {
        parent[0][i] = i;
        v[i] = -1;
    }
    for (int i = 0; i < noofEdges; i++)
        scanf("%d %d %d", &n[i].sourceNode, &n[i].sourceNode, &n[i].weight);
}
void displayNodes()
{
    printf("\n");
    for (int i = 0; i < noofEdges; i++)
        printf("%d %d %d\n", n[i].sourceNode, n[i].sourceNode, n[i].weight);
}
void displayOutput()
{
    printf("\n");
    for (int i = 0; i < op; i++)
        printf("%d %d %d\n", out[i].sourceNode, out[i].sourceNode, out[i].weight);
}
void ParentCheck()
{
    for (int i = 1; i <= 9; i++)
        if (parent[1][i] == 1 && parent[0][i] != i)
        {
            parent[0][i] = parent[0][parent[0][i]];
            parent[1][i] = 0;
        }
}
void CheckLogic()
{
    int source;
    int dest;
    for (int i = 0; i < noofVertices; i++)
    {
        source = n[i].sourceNode;
        dest = n[i].sourceNode;
        if (parent[0][source] != parent[0][dest])
        {
            out[op] = n[i];
            op++;
            parent[0][dest] = parent[0][source];
            parent[1][source] = 1;
            ParentCheck();
        }
    }
}
void bubbleSort()
{
    int i, j;
    for (i = 0; i <= noofEdges; i++)
        for (j = 0; j < noofEdges - i - 1; j++)
            if (n[j].weight > n[j + 1].weight)
            {
                temp = n[j];
                n[j] = n[j + 1];
                n[j + 1] = temp;
            }
}
int mst()
{
    int sum = 0;
    for (int i = 0; i < op; i++)
    {
        sum += out[i].weight;
    }
    return sum;
}
int main()
{
    input();
    bubbleSort();
    printf("Sorting on weight: \n");
    displayNodes();
    CheckLogic();
    printf("MST\n");
    displayOutput();
    printf("Total Cost : %d\n", mst());
    
}
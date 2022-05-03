#include <stdio.h>
#include <stdlib.h>
int m[10][10];
int no, maxcap;
struct node
{
    int p;
    int w;
} n[10], temp;
void Initialize()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            m[i][j] = 0;
        }
    }
}
void Display()
{
    for (int i = 0; i <= no; i++)
    {
        for (int j = 0; j <= maxcap; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}
void input(int no1)
{
    printf("enter profits");
    for (int i = 0; i < no1; i++)
    {
        scanf("%d", &n[i].p);
    }
    printf("enter weights");
    for (int i = 0; i < no1; i++)
    {
        scanf("%d", &n[i].w);
    }
}
int ma(float a, float b)
{
    if (a > b)
        return (int)a;
    else
        return (int)b;
}
void logic()
{
    int wei, pr, a, b;
    for (int i = 1; i <= no; i++)
    {
        for (int j = 1; j <= maxcap; j++)
        {
            wei = n[i - 1].w;
            pr = n[i - 1].p;
            a = m[i - 1][j];
            if (j - wei >= 0)
            {
                b = m[i - 1][j - wei] + pr;
                m[i][j] = ma(a, b);
            }
            else
            {
                m[i][j] = a;
            }
        }
    }
}
int final()
{
    int i = no;
    int j = maxcap;
    int a[10];
    int ac = 0;
    while (j > 0)
    {
        if (m[i][j] != m[i - 1][j])
        {
            a[ac] = i;
            ac++;
            j = j - n[i - 1].w;
        }
        i--;
    }
    printf("\nThe sequence is");
    for (int k = 0; k < ac; k++)
        printf("%d ", a[k]);
}
int main()
{
    Initialize();
    printf("No of Items: ");
    scanf("%d", &no);
    input(no);
    printf("Max Capacity: ");
    scanf("%d", &maxcap);
    logic();
    Display();
    final();
}
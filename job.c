#include <stdio.h>
#include <time.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void sort(int in[], int p[], int d[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j] < p[j + 1])
            {
                swap(&p[j], &p[j + 1]);
                swap(&in[j], &in[j + 1]);
                swap(&d[j], &d[j + 1]);
            }
        }
    }
}
void print(int in[], int p[], int d[], int size)
{
    int i;
    printf("Index      Profit       deadline\n");
    for (i = 0; i < size; i++)
    {

        printf("%d  %10d  %10d", in[i], p[i], d[i]);
        printf("\n");
    }
}
int main()
{
    int n, i, j = 0, k;
    printf("Enter the number of index :\n");
    scanf("%d", &n);
    printf("Enter the index profit and their deadline in order\n");
    int in[10], p[10], d[10], list[10];
    int profit = 0;

    double total_time;
    clock_t start, end;
    start = clock();

    for (i = 0; i < 10; i++)
    {
        list[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        printf("Process No: ");
        scanf("%d",&in[i]);
        printf("Profit: ");
        scanf("%d",&p[i]);
        printf("Deadline: ");
        scanf("%d",&d[i]);        
    }
    sort(in, p, d, n);
    print(in, p, d, n);
    for (i = 0; i < n; i++)
    {
        k = d[i];
        while (k > 0)
        {
            if (list[k] == 0)
            {
                list[k] = in[i];
                profit = profit + p[i];
                printf("Job no. %d in slot %d\n", in[i], i + 1);
                break;
            }
            else
            {
                k = k - 1;
            }
        }
    }
    printf("The sequence is : ");
    for (i = 1; i <= n; i++)
    {
        if (list[i] != 0)
        {
            printf("%d - ", list[i]);
        }
    }
    printf("\nThe total profit is :%d\n", profit);

    end = clock();

    total_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken is : %f\n", total_time);
}

#include <stdio.h>
#include <stdlib.h>

int n;
float max = 15;
float item[10];
float profit[10];
float weight[10];
float pbw[10];
int total = 0;

void swap(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

void sort()
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (pbw[j] < pbw[j + 1])
            {
                swap(&item[j], &item[j + 1]);
                swap(&profit[j], &profit[j + 1]);
                swap(&weight[j], &weight[j + 1]);
                swap(&pbw[j], &pbw[j + 1]);
            }

} // sort


void knapsack()
{
    //printf("\nstart of knapsack");
    for(int i=0;i<n;i++){
        //printf("\nfrom the for loop");
        if(max < weight[i] && max > 0){
           // printf("\ninside main logic");
            max = max - weight[i];
            total = total + profit[i];
            printf("\nitem selected = %f\nProfit obtained = %f\nRemaining capacity = %f",item[i],total,max);
        }
    }
// printf("\nend of knapsack");
} // ks

int main(int argc, char const *argv[])
{

    printf("Enter the no. of items : ");
    scanf("%d", &n);
    // printf("Enter maximum capacity : ");
    // scanf("%d", &max);

    printf("\nEnter the item no. , profit and weight is order ");
    for (int i = 0; i < n; i++)
    {
        printf("\nitem no. : ");
        scanf("%f", &item[i]);
        printf("item profit. : ");
        scanf("%f", &profit[i]);
        printf("item weight. : ");
        scanf("%f", &weight[i]);

        // calculating profit by weight ration
        pbw[i] = profit[i] / weight[i];
    }

    printf("\nGiven datas");
    printf("\n Item No.\t Profit \t Weight \t P/W ");
    for (int i = 0; i < n; i++)
    {
        printf("\n %0f\t %0f \t %0f \t %f", item[i], profit[i], weight[i], pbw[i]);
    }

    sort();

    printf("\n After sorting");
    printf("\n Item No.\t Profit \t Weight \t P/W ");
    for (int i = 0; i < n; i++)
    {
        printf("\n %0f\t %0f \t %0f \t %2f", item[i], profit[i], weight[i], pbw[i]);
    }



    knapsack();
    printf("\nHello world");
    return 0;
}

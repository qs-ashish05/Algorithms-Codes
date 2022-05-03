#include <stdio.h>
#include <stdlib.h>

void swap(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

void sort(float item[], float profit[], float weight[], float pbw[], int n)
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

int istake(int max,int weight){
    if(max > weight)
        return 1;
    else 
        return 0;
}

int main(int argc, char const *argv[])
{
    int n;
    float max;
    float item[10];
    float profit[10];
    float weight[10];
    float pbw[10];

    printf("Enter the no. of items : ");
    scanf("%d", &n);
    printf("Enter maximum capacity : ");
    scanf("%d", &max);

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

    sort(item, profit, weight, pbw, n);

    printf("\n After sorting");
    printf("\n Item No.\t Profit \t Weight \t P/W ");
    for (int i = 0; i < n; i++)
    {
        printf("\n %0f\t %0f \t %0f \t %2f", item[i], profit[i], weight[i], pbw[i]);
    }

    return 0;
}

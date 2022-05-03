#include<stdio.h>
#include<conio.h>
void swap(float *a,float *b){
    float temp = *a;
    *b = *a;
    *a = temp;
}
void bubbleSort(float item[],float pbw, int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
       for (j = 0; j < n-i-1; j++)   // note this
           if (pbw[j] > pbw[j+1]) 
              {
                  swap(&item[j],&item[j+1]);
                  swap(&pbw[j],&pbw[j+1]);
              }
              
}  // bubble sort

void main(int argc, char const *argv[])
{
    int max;
    int items[20];
    float profit[20];
    float weight[20];
    float pbw[20];
    int n;

    printf("Enter the number of nitems : ");
    scanf("%d",&n);

    printf("\nEnter the item number and their details in sequence :\n");
    for(int i = 0;i<n;i++){
        printf("\nitem id : ");
        scanf("%d",&items[i]);
        printf("\nprofit : ");
        scanf("%d",&profit[i]);
        printf("\nweight : ");
        scanf("%d",&weight[i]);
        pbw[i] = profit[i]/weight[i];
    }

printf("\nitem id |\t Weight |\t Profit/weight \n");
for(int i = 0;i<n;i++)
    printf("%d |\t %d |\t %d",items[i],weight[i],pbw[i])
}

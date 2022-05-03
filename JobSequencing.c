#include<stdio.h>
#include<conio.h>

void swap(int *a,int *b){

    int temp = *a;
    *a = *b;
    *b = temp;

}

void bublesort(int index[],int profit[], int deadline[],int n){
    for(int i = 0;i<n-1;i++)
        for (int j = 0; j < n-1; j++)
            if(profit[j] > profit[j+1]){

               swap(&index[j],&index[j+1]);
               swap(&profit[j],&profit[j+1]);
               swap(&deadline[j],&deadline[j+1]);
            }     
} // bublesort


void main(int argc, char const *argv[])
{
    int n;
    int index[20];
    int profit[20];
    int deadline[20];

    printf("Enter the number of index :");
    scanf("%d",&n);

    printf("Enter the profit and deadline of each job in sequence \n");
    for(int i = 0;i<n;i++){
        printf("Enter job id : ");
        scanf("%d",&index[i]);
        printf("Enter profit : ");
        scanf("%d",&profit[i]);
        printf("Enter deadline : ");
        scanf("%d",&deadline[i]);
    }
    
    printf("\nOriginal Sequence given\n");
    printf("\nJob |\tprofit |\tdeadline\n");
    for(int i=0;i<=n;i++)
        printf("%d |\t%d |\t%d\n",index[i],profit[i],deadline[i]);


    bublesort(index,profit,deadline,n);
  

    printf("\nSequence after sorting\n");
    printf("\nJob |\tprofit |\tdeadline\n");
    for(int i=0;i<=n;i++)
        printf("%d |\t%d |\t%d\n",index[i],profit[i],deadline[i]);
    
    int total=0;

} //main

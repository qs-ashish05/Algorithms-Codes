#include<stdio.h>
#include<conio.h>

void maximum(int arr[],int n){

    int max = arr[0];
    for(int i=1;i<n-1;i++){
        if(arr[i]>max)
            max = arr[i];
    }
printf("Maximum element is : %d",max);
} // maximum

int minimum(int arr[],int n){

    int min = arr[0];
    for(int i=1;i<n-1;i++){
        if(arr[i]<min)
            min = arr[i];
    }
printf("minimum element is : %d",min);
} // mminimum

int main(int argc, char const *argv[])
{
    int n;
    int arr[20];
    printf("Enter the size of array : ");
    scanf("%d",&n);

    printf("\nEnter the Elements : ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    printf("\nYour array is :");
    for(int i=0;i<n;i++)
        printf("%d\t",arr[i]);

    maximum(arr,n);
    minimum(arr,n);
    return 0;

}

#include<stdio.h>
#include<stdlib.h>

 void swap(int *a,int *b){
     int temp =* a;
     *a = *b;
     *b = temp;
}

// int partition(int arr[],int left,int right){

//     int pivot = arr[left];
//     int i = left +1;
//     int j = right;

//     while (1)
//     {
//         while (pivot >= arr[i]  && i<right)
//             {
//                 i = i +1;
//             }
//         while (pivot < arr[i])
//             {
//                 j = j - 1;
//             }
        
//         if (i<j){
//             swap(&arr[i],&arr[j]);
//         }
//         else{
//             swap(&arr[left],&arr[j]);
//             return j;
//         }    
//     }

// }
// void quicksort(int arr[],int left,int right,int n){

//     int s;
//     if(left < right){
//         s = partition(arr,left,right);
//         quicksort(arr,left,s-1,n);
//         quicksort(arr,s+1,right,n);
//     }
// }
void quicksort(int arr[],int left,int right,int n){

    int pivot = arr[0];
    int i = 0,j = right;
    printf("%d",arr[right]);
    
    while(left < right){
        for(i;i<n;i++){
            arr[i] > pivot;
            break;
        }
        for(j;j<=0;j--){
            arr[j] < pivot;
            break;
        }
        break;
    }
    swap(&arr[i],&arr[j]);
}

int main(int argc, char const *argv[])
{
    int n,arr[10];
    printf("Enter the size of array");
    scanf("%d",&n);

    printf("Enter elements of array");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    arr[n] = 999;
    quicksort(arr,0,n,n);

    printf("Sorted array");
    for(int i=0;i<n;i++)
         printf("%d\t",arr[i]);

    return 0;
}

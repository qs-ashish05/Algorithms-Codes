#include <stdio.h>
#include <conio.h>
// gcc Binarysearch.c -o Binarysearch

int binarySearchRecursive(int arr[], int left, int right, int x) 
{ 
    if (right >= left) { 
        int mid = (left + right) / 2; 
        if (arr[mid] == x) 
            return mid; 
        if (arr[mid] > x) 
            return binarySearchRecursive(arr, left, mid - 1, x); 
        return binarySearchRecursive(arr, mid + 1, right, x); 
    } 
    return -1; 
}
int binarySearchIterative(int arr[], int left, int right, int x) 
{ 
    while (left <= right) { 
        int mid = (left + right) / 2; 
        if (arr[mid] == x) 
            return mid; 
        if (arr[mid] < x) 
            left = mid + 1; 
        else
            right = mid - 1; 
    } 
    return -1; 
} 

void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              {
                  int temp = arr[j];
                  arr[j]=arr[j+1];
                  arr[j+1]=temp;
              }
}

void main(int argc, char const *argv[])
{
    int arr[50]; 
    int i,n, x,ch,result,firstOcc,lastOcc;
    printf("Input Size of array: ");
    scanf("%d",&n); 
    printf("Input Array: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
        bubbleSort(arr,n);
    printf("Sorted Array: ");
    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);

   printf("\nEnter the data to be searcged : ");
   scanf("%d",&x);

   result = binarySearchRecursive(arr,0,n-1,x);
   if(result == -1)
   printf("\nElement is not found");
   else
   printf("\nElement is present at index %d in sorted array",result);

}

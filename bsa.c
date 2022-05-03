#include<stdio.h>
int firstOccurence(int arr[], int first, int last, int x) 
{ 
    if (last >= first) { 
        int mid = (first + last) / 2; 
        if ((mid==0 || x>arr[mid-1]) && arr[mid] == x ) 
            return mid; 
        else if (arr[mid] > x) 
            return firstOccurence(arr, first, mid - 1, x); 
        return firstOccurence(arr, mid + 1, last, x); 
    } 
    return -1; 
}

int lastOccurence(int arr[], int first, int last, int x,int n) 
{ 
    if (last >= first) { 
        int mid = (first + last) / 2; 
        if ((mid==n-1 || x<arr[mid+1]) && arr[mid] == x ) 
            return mid; 
        else if (arr[mid] > x) 
            return lastOccurence(arr, first, mid - 1, x,n); 
        return lastOccurence(arr, mid + 1, last, x,n); 
    } 
    return -1; 
}
int binarySearchRecursive(int arr[], int first, int last, int x) 
{ 
    if (last >= first) { 
        int mid = (first + last) / 2; 
        if (arr[mid] == x) 
            return mid; 
        if (arr[mid] > x) 
            return binarySearchRecursive(arr, first, mid - 1, x); 
        return binarySearchRecursive(arr, mid + 1, last, x); 
    } 
    return -1; 
}
int binarySearchIterative(int arr[], int first, int last, int x) 
{ 
    while (first <= last) { 
        int mid = (first + last) / 2; 
        if (arr[mid] == x) 
            return mid; 
        if (arr[mid] < x) 
            first = mid + 1; 
        else
            last = mid - 1; 
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

void main()
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
    do{    
    printf("\nMENU\n1. Iterative Method\n2. Recursive Method\n3. First Occurence\n4. Last Occurence\n5. Total Occurences\n6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("Iterative Method\n");
            result = -1;
            printf("Enter number to be searched: ");
            scanf("%d",&x);
            result = binarySearchIterative(arr, 0, n - 1, x);
            if(result!=-1)
                printf("\nElement found at index : %d",result); 
            else
                printf("\nElement not found!"); 
            break;
        case 2:
            printf("Recursive Method\n");
            result = -1;
            printf("Enter number to be searched: ");
            scanf("%d",&x);
            result = binarySearchRecursive(arr, 0, n - 1, x);
            if(result!=-1)
                printf("\nElement found at index : %d",result); 
            else
                printf("\nElement not found!"); 
            break;
        case 3:
            printf("First Occurence Method\n");
            firstOcc = -1;
            printf("Enter number to be searched: ");
            scanf("%d",&x);
            firstOcc = firstOccurence(arr, 0, n - 1, x);
            if(firstOcc!=-1)
                printf("\nElement found at index : %d",firstOcc); 
            else
                printf("\nElement not found!"); 
            break;
        case 4:
            printf("Last Occurence Method\n");
            lastOcc = -1;
            printf("Enter number to be searched: ");
            scanf("%d",&x);
            lastOcc = lastOccurence(arr, 0, n - 1, x,n);
            if(lastOcc!=-1)
                printf("\nElement found at index : %d",lastOcc); 
            else
                printf("\nElement not found!"); 
            break;
        
        case 5:
            printf("Enter number to be searched: ");
            scanf("%d",&x);
            result=-1;
            result=(lastOccurence(arr,0,n-1,x,n)-firstOccurence(arr,0,n-1,x))+1;
            printf("\nTotal Occurences : %d",result);
            break;
        case 6:
            return;
        
    }
    }while(ch!=6);
}
#include<stdio.h>
#include<conio.h>
int max,min;

void minmax(int arr[],int left,int right){
    int tempMax, tempMin;
    if(left == right){
        min = arr[left];
        max = arr[left];  // or right
    }

    if(right == left + 1){
        if(arr[left]>arr[right]){
        min = arr[right];
        max = arr[left];
        }
        else{
        min = arr[left];
        max = arr[right];
        }
    }

    else{
        int mid = (left + right)/2;
        minmax(arr,left,mid);
        // tempMax = max;
        // tempMin = min;

        //  minmax(arr,mid+1,right);

        //  if(max > tempMax){
        //      max = tempMax;
        //  }
        //  if(min < tempMin){
        //      min = tempMin;
        // }
    }

} // min max


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

    
    min = arr[0];
    max = arr[0];
    minmax(arr,0,n-1);

    printf("\nMinimum element is : %d",min);
    printf("\nmaximum element is : %d",max);
    return 0;
}

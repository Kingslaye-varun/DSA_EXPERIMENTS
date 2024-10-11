#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

void display(int arr[],int N);

void insertionSort(int arr[],int N){
    for(int i=0;i<N;i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j]>key){
            arr[j+1] = arr[j];
            j = j - 1;
        }
    arr[j+1] = key;
    }
}

void bubbleSort(int arr[],int N){
    for(int i = 0; i<N;i++){
        for(int j = 0;j<(N-i-1);j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int arr[],int N){
    for(int i=0;i<N-1;i++){
        int minIndex = i;
        for(int j=i+1;j<N;j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        //printf("%d %d\n",arr[minIndex],minIndex);
        int temp = arr[minIndex];
        arr[minIndex]=arr[i];
        arr[i]=temp;
        //display(arr, N);
    }
}

void display(int arr[],int N){
    printf("Sorted Array: ");
    for(int i = 0;i<N;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void main(){
    int n;
    printf("Enter number of elements in array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter Elements of Array : \n");
    for(int i = 0;i < n;i++){
        printf("Enter element %d : ",(i+1));
        scanf("%d",&arr[i]);
    }
    int ch;
    printf("Enter choice of Sorting : \n1.Bubble Sort\n2.Insertion Sorting\n3.Selection Sorting\n");
    scanf("%d",&ch);
    switch(ch){
        case 1 :
            bubbleSort(arr,n);
            display(arr,n);
        break;
       
        case 2 :
            insertionSort(arr,n);
            display(arr,n);
        break;
       
        case 3 :
            selectionSort(arr,n);
            display(arr,n);
        break;
       
        default :
            printf("Invalid Input");
    }  
}
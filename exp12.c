#include <stdio.h>
#include <string.h>

int main() {
    char arr[4][20] = {"constitute", "contribute", "ide", "practice"};
    char search[20];
    printf("constitute, contribute, ide, practice ");
    printf("Enter the word to search:");
    scanf("%s" , search);
    int left = 0;
    int right = 4;
    int compare = 0;
    int mid;
    while (left <=right) {
        mid = left + ((right - left) / 2);
        compare = strcmp(search,arr[mid]);
        if (compare == 0){
            printf("%d" , mid);
            return mid;
        }
        else if (compare > 0){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    printf("NOT FOUND!");
    return 0;
}

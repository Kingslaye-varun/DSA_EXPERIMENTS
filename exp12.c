#include <stdio.h>
#include <string.h>

int main() {
    char arr[4][20] = {"constitute", "contribute", "ide", "practice"};
    char search[20];

    // Display the words
    printf("Words in the dictionary: constitute, contribute, ide, practice\n");
    printf("Enter the word to search: ");
    scanf("%s", search);

    int left = 0;
    int right = 3;  // Adjusted right index for 4 elements (0 to 3)
    int compare = 0;
    int mid;

    // Perform binary search
    while (left <= right) {
        mid = left + ((right - left) / 2);
        compare = strcmp(search, arr[mid]);

        if (compare == 0) {
            printf("Word '%s' found at index %d.\n", search, mid);
            return 0;  // Exit the program
        }
        else if (compare > 0) {
            left = mid + 1;  // Search in the right half
        }
        else {
            right = mid - 1;  // Search in the left half
        }
    }

    printf("NOT FOUND!\n");
    return 0;
}

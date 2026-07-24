#include <stdio.h>
#include <stdlib.h>
int main() {
    int N;
    printf("Enter the number of elements: ");
    scanf("%d", &N);
    int arr[N], result[N];
    printf("Enter %d sorted elements: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    int left = 0;
    int right = N - 1;
    int index = N - 1;
    while (left <= right) {
        if (abs(arr[left]) > abs(arr[right])) {
            result[index] = arr[left] * arr[left];
            left++;
        } else {
            result[index] = arr[right] * arr[right];
            right--;
        }
        index--;
    }
    printf("Sorted squared array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}
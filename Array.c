#include <stdio.h>
int main() {
    int N, P;
    printf("Enter the number of tasks: ");
    scanf("%d", &N);
    printf("Enter the maximum allowed energy consumption: ");
    scanf("%d", &P);
    int arr[N];
    printf("Enter the energy costs of %d tasks: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    int start = 0;
    int current_sum = 0;
    int maxLength = 0;
    for (int end = 0; end < N; end++) {
        current_sum = current_sum + arr[end];
        while (current_sum > P && start <= end) {
            current_sum = current_sum - arr[start];
            start++;
        }
        int length = end - start + 1;
        if (length > maxLength) {
            maxLength = length;
        }
    }
    printf("Max Length: %d\n", maxLength);
    return 0;
}
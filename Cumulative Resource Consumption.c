#include <stdio.h>

int main() {
    int N;

    printf("Enter the number of hours: ");
    scanf("%d", &N);

    int arr[N], prefix[N];

    printf("Enter %d packet counts: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    prefix[0] = arr[0];

    for (int i = 1; i < N; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    printf("Prefix Sum Array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", prefix[i]);
    }

    return 0;
}
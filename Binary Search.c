#include <stdio.h>

int main() {
    int N;
    printf("Enter the number of sectors: ");
    scanf("%d", &N);
    int arr[N];
    printf("Enter %d binary values (0 or 1): ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    int countOnes = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == 1)
            countOnes++;
    }
    if (countOnes <= 1) {
        printf("Min Swaps: 0");
        return 0;
    }
    int currentOnes = 0;
    for (int i = 0; i < countOnes; i++) {
        if (arr[i] == 1)
            currentOnes++;
    }
    int maxOnes = currentOnes;
    for (int i = countOnes; i < N; i++) {
        if (arr[i] == 1)
            currentOnes++;
        if (arr[i - countOnes] == 1)
            currentOnes--;
        if (currentOnes > maxOnes)
            maxOnes = currentOnes;
    }
    int minSwaps = countOnes - maxOnes;
    printf("Min Swaps: %d", minSwaps);
    return 0;
}
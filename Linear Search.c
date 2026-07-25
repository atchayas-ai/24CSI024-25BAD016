#include <stdio.h>
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int e;
    printf("Enter an element to be found: ");
    scanf("%d", &e);
    int flag = 0;
    int index;
    for(int i = 0; i < n; i++) {
        if(arr[i] == e) {
            index = i;
            flag = 1;
            break;
        }
    }
    if(flag == 1)
        printf("Element found at index %d", index);
    else
        printf("Element not found");
    return 0;
}

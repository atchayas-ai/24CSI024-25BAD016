#include <stdio.h>
int main()
{
    int n;
    int low, high, mid;
    int e;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the array elements (sorted): ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &e);
    low = 0;
    high = n - 1;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(e == a[mid])
        {
            printf("Element Found at index %d", mid);
            return 0;
        }
        else if(e < a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    printf("Element not found");
    return 0;
}

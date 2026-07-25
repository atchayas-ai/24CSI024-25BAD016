#include <stdio.h>
int main()
{
    int a[100], n, i, choice, pos, value;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("\n1.Insert\n2.Delete\n3.Update\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            printf("Enter position and value: ");
            scanf("%d%d", &pos, &value);
            for(i = n; i > pos; i--)
                a[i] = a[i - 1];
            a[pos] = value;
            n++;
            break;
        case 2:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            for(i = pos; i < n - 1; i++)
                a[i] = a[i + 1];

            n--;
            break;
        case 3:
            printf("Enter position and new value: ");
            scanf("%d%d", &pos, &value);
            a[pos] = value;
            break;
        default:
            printf("Invalid Choice");
            return 0;
    }
    printf("Updated List: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}

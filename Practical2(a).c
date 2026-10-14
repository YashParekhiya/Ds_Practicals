#include <stdio.h>

int main()
{
    int arr[20], n, i;
    int *ptr;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 1 || n > 20)
    {
        printf("Invalid number of elements!");
        return 1;
    }

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    ptr = &arr[n - 1];

    printf("Array elements in reverse order:\n");

    for (i = n - 1; i >= 0; i--)
    {
        printf("%d ", *ptr);
        ptr--;
    }

    return 0;
}
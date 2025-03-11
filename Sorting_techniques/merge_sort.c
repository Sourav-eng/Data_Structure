#include <stdio.h>
void printarray(int *a, int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        printf(" %d", a[i]);
    }
    printf("\n");
}

void mergesort(int *a, int low, int mid, int high)
{
    int i, j, k;
    int b[100];
    i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            k++;
            i++;
        }
        else
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}
void merge(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (high + low) / 2;
        merge(a, low, mid);
        merge(a, mid + 1, high);
        mergesort(a, low, mid, high);
    }
}

int main()
{
    int a[100];
    int i, n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    // int a[]={2,5,7,2,1,0,6.4};
    // int n = sizeof(a) / sizeof(a[0]);
    printf("before sort");
    printarray(a, n);
    printf("after sort");
    merge(a, 0, n-1);
    printarray(a, n);
}
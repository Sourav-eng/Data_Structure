#include <stdio.h>
void printarray(int *a, int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        printf(" %d", a[i]);
    }
    printf("\n");
}

int divide(int *a, int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

    } while (i < j);
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

void quicksort(int *a, int l, int h)
{
    int dividingpoint;
    if (l < h)
    {
        dividingpoint = divide(a, l, h);
        quicksort(a, l, dividingpoint - 1);
        quicksort(a, dividingpoint + 1, h);
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
    quicksort(a,0,n-1 );
    printarray(a, n);
}
#include <stdio.h>

void printarray(int *a, int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        printf(" %d", a[i]);
    }
    printf("\n");
}
void selectionsort(int *a, int n)
{
    int indmin;
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        indmin = i;
        for (int j = i + 1; j < n - 1; j++)
        {
            if (a[j] < a[indmin])
            {
                indmin = j;
            }
        }
        temp = a[i];
        a[i] = a[indmin];
        a[indmin] = temp;
    }
}
int main()
{
    int a[100];
    int i, n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    // int a[]={2,5,7,2,1,0,6.4};
    // int n = sizeof(a) / sizeof(a[0]);
    printf("before sort");
    printarray(a, n);
    printf("after sort");
    selectionsort(a, n);
    printarray(a, n);
}
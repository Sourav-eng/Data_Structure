#include <stdio.h>
void printarray(int *a, int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        printf(" %d", a[i]);
    }
    printf("\n");
}
void insertionsort(int *a, int n)
{
    int key;
    int j;
    for (int i = 1; i <= n - 1; i++)
    {
        key = a[i];
        j = i - 1;

        {
            while (j >= 0 && a[j] > key)
            {
                a[j + 1] = a[j];
                j = j - 1;
            }
        }
        a[j + 1] = key;
    }
}
int main()
{
    int a[] = {1, 4, 1, 66, 9,45,65,36,354,66,4,2, 100};
    int n = sizeof(a) / sizeof(a[0]);
    printf("before sort\n");
    printarray(a, n);
    insertionsort(a, n);
    printf("after sort\n");
    printarray(a, n);

}
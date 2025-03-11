#include <stdio.h>

void printarray(int *a, int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        printf(" %d", a[i]);
    }
    printf("\n");
}
void bubblesort(int *a, int n)
{
    int sorted = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        sorted = 1;
        for (int j = 0; j < n - i - 1; j++)
        {

            if (a[j] > a[j + 1])
            {
                int temp;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                sorted = 0;
            }
          
        }
        if(sorted){
            break;}
    }
}
int main()
{
    int a[] = {1, 4, 5 ,66 ,89 ,100};
    int n = 6;
    // printarray(a, n);
    bubblesort(a, n);
    printarray(a, n);
}
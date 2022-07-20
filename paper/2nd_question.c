#include <stdio.h>

    int sumup(int arr[])
    {
        int temp;
        temp = arr[0] + arr[3] + arr[6] + arr[9];
        return temp;
    }
int main()
{
    int arr[10];
    int sum = 0;
    for (int i = 0; i <= 9; i++)
    {
        printf("enter the number: ");
        scanf("%d", &arr[i]);
    }
    printf("%d", sumup(arr));

    return 0;
}
#include <stdio.h>

int yards2feet(int n)
{
    return 3 * n;
}
int feet2inches(int n)
{
    return 12 * n;
}
int inches2cms(int n)
{
    return 2.5 * n;
}

int main()
{
    int n;
    printf("Enter the value in yards: ");
    scanf("%d", &n);
    int temp1 = yards2feet(n);
    int temp2 = feet2inches(temp1);
    float temp3 = inches2cms(temp2);

    printf("Length in feet: %d\n", temp1);
    printf("Length in inches: %d\n", temp2);
    printf("Length in cms: %d\n", temp3);
    return 0;
}
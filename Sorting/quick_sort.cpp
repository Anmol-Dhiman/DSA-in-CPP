// in quick_sort we have to place the value in that way i.e. all the values smaller than
// that comes into left side and all the values larger than that comes to the right side

#include <iostream>
using namespace std;
void printing(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int swap_coding(int a[], int low, int high)
{
    // pivot is the value from where we have to find our i(larger value index as compare to pivot) and j(smaller value as compare to pivot)
    // here 2 is pivot value and we have to compare other values with this to find i and j
    // 2, 1, 3, 9, 4, 4, 8, 7, 5, 6
    int pivot = a[low];

    int i = low + 1;
    int j = high;

    do
    {
        // from this loop we will find the index whose value is larger than pivot starting from low + 1
        while (a[i] <= pivot && i < high)
        {
            i++;
        }
        // from this loop we will find the index whose value is smaller than pivot starting from high.
        while (a[j] >= pivot && j > low)
        {
            j--;
        }
        if (i < j)
        {
            swap(a[i], a[j]);
        }

    } while (i < j);
    // now we have the index whose value is smaller than pivot and after that index all the values are larger than pivot
    swap(a[j], a[low]);
    // returning the new index of the pivot value
    return j;
}
void quick_sort(int arr[], int low, int high)
{
    // we will use the recursive method to sort the array
    // this is the base case
    if (low >= high)
        return;
    int index;
    // we will find the index of new position of the pivot
    index = swap_coding(arr, low, high);
    // sort the left array form the new position of the pivot
    quick_sort(arr, low, index - 1);
    // sort the right array form the new position of the pivot
    quick_sort(arr, index + 1, high);
}
int main()
{
    // the sample input
    int arr[] = {2, 1, 3, 9, 4, 4, 8, 7, 5, 6};
    int n = 10;
    // printing before the sorting
    printing(arr, n);

    quick_sort(arr, 0, n - 1);
    // printing after sorting
    printing(arr, n);
    return 0;
}
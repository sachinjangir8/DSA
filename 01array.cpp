#include <iostream>
using namespace std;
// int arrays()
// {
// int arr[] = {8, 10, 5, 6, 7};
// int min = INT8_MAX;
// int index;
// for (int i = 0; i < 5; i++)
// {
//     if (min > arr[i])
//     {
//         min = arr[i];
//        index = i;
//     }
// }
// cout << min<<index << " is yhe min of on this arr. " << endl;
//     return 0;
// }
//                                                  q2 ......reverse an array
int array(int value[], int size)
{
    int start = 0;
    int end = size - 1;
    while (start < end)
    {
        swap(value[start], value[end]);
        start++;
        end--;
    }
    return 0;
}
int main()
{
    int n[] = {1, 2, 3, 4, 5, 8};
    int size = 6;
    // cout<< arrays();
    array(n, size);
    for (int i = 0; i < size; i++)
    {
        cout << n[i] << " ";
    }


    return 0;
}
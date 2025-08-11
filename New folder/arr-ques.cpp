#include <iostream>
using namespace std;
// int sum(int value[], int size)
// {
//     int sumaning = 0;
//     for (int i = 0; i < size; i++)
//     {
//         sumaning += value[i];
//     }
//     return sumaning;
// }
// int unique(int value1[], int value2[], int size1, int size2)
// {
//     int newarr = {};
//     for (int i = 0; i < size1; i++)
//     {
//         for (int j = 0; j < size2; j++)
//         {
//             if (value1[i] == value2[j])
//             {
//                 newarr = value1[i];
//             }
//         }
//         cout << newarr << " ";
//     }

//     return 0;
// }
int in1unique(int value1[], int size1)
{
    int start = value1[0];
    int next = value1[1];
    int temp = 0;
    for (int i = 0; i < size1; i++)
    {
        temp ^= value1[i];
    }
    cout << temp ;
    cout << " " << max(7, 5);

    return 0;
}

int main()
{
    int arr1[] = {4, 1, 47, 1, 33, 4, 3};
    // int arr2[] = {3, 5, 12, 6, 7};
    int size = 7;
    // int size2 = 3;
    // cout << sum(arr, size);
    // cout << unique(arr1, arr2, size, size2);
    in1unique(arr1, size);

    return 0;
}
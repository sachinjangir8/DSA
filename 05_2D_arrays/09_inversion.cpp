#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
// 1. brout force approch.....
// int main()
// {
//     int invcount = 0;
//     vector<int> ar = {5, 3, 6, 4, 8, 1};
//     for (int i = 0; i < ar.size() - 1; i++)
//     {
//         for (int j = 1; j < ar.size() - 1; j++)
//         {
//             if(ar[i]<ar[j]){
//                 invcount++;
//             }
//         }
//     }
//     cout << invcount;
// }

int merge(vector<int> &ar, int st, int mid, int end)
{
    vector<int> temp;
    int i = st, j = mid + 1;
    int inversion = 0;
    while (i <= mid && j <= end)
    {
        if (ar[i] <= ar[j])
        {
            temp.push_back(ar[i]);
            i++;
        }
        else
        {
            temp.push_back(ar[j]);
            j++;
            inversion += (mid - i + 1); // count inversion in left side...
        }
    }
    while (i <= mid)
    {
        temp.push_back(ar[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(ar[j]);
        j++;
    }
    for (int idx = 0; idx < temp.size(); idx++)
    {
        ar[idx + st] = temp[idx];
    }
    return inversion;
}

int mergesort(vector<int> &ar, int st, int end)
{
    if (st < end)
    {
        int mid = (st + end) / 2;
        // left side elem
        int leftinvert=mergesort(ar, st, mid);
        // right side elem...
        int rightinvert=mergesort(ar, mid + 1, end);
        // now sorting all elem
        int invert=merge(ar, st, mid, end);
        return leftinvert + rightinvert + invert;  // return total inversion..
    }
    return 0; // no inversion..
}

int main()
{
    vector<int> ar = {34, 54, 2, 34, 54, 23,344};
    int st = 0, end = ar.size() - 1;
    int ans=mergesort(ar, st, end);
    cout << "Total inversion : " << ans;
    return 0;
}
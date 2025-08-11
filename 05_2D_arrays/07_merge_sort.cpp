#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
void merge(vector<int> &ar, int st, int mid, int end)
{
    vector<int> temp;
    int i = st, j = mid + 1;
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
}

void mergesort(vector<int> &ar, int st, int end)
{
    if (st < end)
    {
        int mid = (st + end) / 2;
        // left side elem
        mergesort(ar, st, mid);
        // right side elem...
        mergesort(ar, mid + 1, end);
        // now sorting all elem
        merge(ar, st, mid, end);
    }
}

int main()
{
    vector<int> ar = {34, 54, 2, 34, 54, 23,344};
    int st = 0, end = ar.size() - 1;
    mergesort(ar, st, end);
    for (int val : ar)
    {
        cout << val << " ";
    }
    cout << end;
    return 0;
}
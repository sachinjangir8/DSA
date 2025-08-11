#include <iostream>
using namespace std;
int main()
{

    // char star = 'g';
    // for (char i = 'a'; i < star; i++)
    // {
    //     for (char j = i; j > 'a'; j--)
    //     {
    //         cout << j << " ";
    //         // star += 1;
    //     }
    //     cout << endl;
    // }

    //                                                         q2.>>>
    // for (int i = 0; i < 6; i++)
    // {
    //     for (int sp = 0; sp < i; sp++)
    //     {
    //         cout << ' '; // that llop printing spaces on it......
    //     }
    //     for (int j = i; j < 6; j++)
    //     {
    //         cout << i;
    //         // cout << 'x' << ' '; // try it.......
    //     }
    //     cout << endl;
    // }

    //                                                        q3..>>>>>
    // for (int i = 0; i < 7; i++)
    // {
    //     int a = 1;
    //     for (int sp = i; sp < 7; sp++)
    //     {
    //         cout << '*';
    //         // a += 1;
    //     }
    //     cout << endl;
    // }
    //                                                       q4...>>>>>>>>>>>>>>
    // int a = 1;
    // for (int i = 0; i < 7; i++)
    // {
    //     for (int sp = i; sp < 7; sp++)
    //     {
    //         cout << ' ';
    //     }
    //     for (int j = 0; j < i; j++)
    //     {
    //         cout << j;
    //     }
    //     for (int k = i; k >= 0; k--)
    //     {
    //         cout << k;
    //         // a += 1;
    //     }

    //     cout << endl;
    // }
    //                                                  q5..>>>>>butterfly pattern
    int n = 5;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << '*';
        }
        for (int j = i; j <= n; j++)
        {
            cout << ' ';
        }
        for (int j = i; j <= n; j++)
        {
            cout << ' ';
        }
        for (int j = 0; j <= i; j++)
        {
            cout << '*';
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {

        for (int j = i; j <= n; j++)
        {
            cout << '*';
        }
        for (int j = 0; j <= i; j++)
        {
            cout << ' ';
        }
        for (int j = 0; j <= i; j++)
        {
            cout << ' ';
        }
        for (int j = i; j <= n; j++)
        {
            cout << '*';
        }

        cout << endl;
    }

    //                                                         q5 last ....>>>>summery
    // for (int i = 0; i < 7; i++)
    // {
    //     for (int j = 0; j < i; j++)
    //     {
    //         cout << '*';
    //     }
    //     cout << endl;
    // }

    return 0;
}
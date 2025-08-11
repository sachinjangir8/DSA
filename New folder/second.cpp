#include <iostream>
using namespace std;
int fact(int a)
{
    int num = 1;
    for (int i = 1; i <= a; i++)
    {
        num *= i;
        cout << " output " << num;
        // cout << "value of i is " << i << ' ';
    }
    return num;
}
int red(int n, int r)
{
    int a = fact(n);
    int b = fact(r);
    int c = fact(n - r);
    int ncr = (a) / (b * c);
    return ncr;
}
int febinocchi(int value)
{
    int num1 = 0;
    int num2 = 1;
    int all;
    for (int i = 2; i <= value; i++)
    {
        all = num1 + num2;
        num1 = num2;
        num2 = all;
        cout << " " << all << ' ';
    }

    return all;
}
//                                        qus fibonacchi ...........................
int main()
{
    int n = 5;
    // cin >> n;
    int r = 5;
    cout << red(n, r) << endl;
    cout << febinocchi(n);

    return 0;
}

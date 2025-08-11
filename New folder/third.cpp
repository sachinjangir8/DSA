#include <iostream>
using namespace std;
int binary(int number)
{
    int pow = 1;
    int ans = 0;
    while (number > 0 || number < 0)
    {
        int rem = number % 2;
        number = number / 2;
        ans += (rem * pow);
        pow *= 10;
    }
    if (ans == -ans)
    {
        cout << '1' << ans;
    }
    else
    {
        cout << '0' << ans;
    }
    return ans;
}
int main()
{
    int num = -11;
    binary(num);
    // cout << binary(num);
    // for (size_t i = 0; i <= num; i++)
    // {
    //     /* code */
    //     cout << binary(i);
    //     cout << "   is binary number of " << i;
    //     cout << endl;
    // }
    return 0;
}
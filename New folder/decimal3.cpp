#include <iostream>
using namespace std;
int decimal(int bin)
{
    int ans = 0;
    int pow = 1;
    while (bin > 0)
    {
        int rem = bin % 2;
        bin = bin / 10;
        ans += (rem * pow);
        pow *= 2;
    }
    return ans;
}
int main()
{
    int binary = 14;
    cout << decimal(binary);
    return 0;
}
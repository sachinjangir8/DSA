#include <iostream>
using namespace std;
int finding(int value)
{
    //                                 this is your way to find out the power of 2 did you got it................
    int num = value;
    while (num != 0)
    {
        num = num / 2;
        cout << num << " " << endl;
        if (num % 2 == 0)
        {
            cout << "the number " << value << " is the power of 2" << endl;
        }
        else
        {
            cout << "wrong input" << endl;
        }
    }
    int leftsift = (value << 1);
    cout << leftsift;
    if (leftsift % 2 == 0 && value % 2 == 0)
    {
        cout << value << " is the power of 2";
    }
    else
    {
        cout << value << " is not the power of 2";
    }
}
int main()
{
    int n;
    cin >> n;
    cout<<finding(n);

    return 0;
}

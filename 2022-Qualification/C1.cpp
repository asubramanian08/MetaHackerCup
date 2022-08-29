// Official: 14 points
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int tests, n;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n;
        cout << "Case #" << (test + 1) << ":" << endl;
        string str;
        cin >> str;
        int start = 0;
        if (str[0] == '-')
            start = 1 << 8;
        for (int i = 1; i < n; i++)
        {
            int curr = start + i;
            for (int j = 8; j >= 0; j--)
                if (curr & (1 << j))
                    cout << '.';
                else
                    cout << '-';
            cout << endl;
        }
    }
    return 0;
}
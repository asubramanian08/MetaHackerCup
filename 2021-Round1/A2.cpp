// All correct
#include <iostream>
#include <string>
using namespace std;

#define MOD 1000000007
#define ADD(x, y) (((x) + (y)) % MOD)
#define ADD_TO(x, y) (x = ADD((x), (y)))
#define INC(x) ADD_TO(x, 1)

int main(void)
{
    // read
    int tests, k;
    string str;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> k;
        cin >> str;

        // setup
        char type = str[0];
        long long left = 0, started = -1, ans = 0, totalLen = 0;

        // Compute
        for (char ch : str)
        {
            INC(totalLen);
            if (type == 'F' || ch == type)
                started = totalLen, type = ch;
            if (ch != type && ch != 'F') // this is a flip
            {
                ADD_TO(left, started);
                started = totalLen, type = ch;
            }
            ADD_TO(ans, left);
        }

        // print
        cout << "Case #" << (test + 1) << ": " << ans << endl;
    }
    return 0;
}
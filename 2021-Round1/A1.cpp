// All correct
#include <iostream>
using namespace std;

int main(void)
{
    int tests, k;
    char ch;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> k;
        int ans = 0;
        char state = 'F';
        for (int i = 0; i < k; i++)
        {
            cin >> ch;
            if (state != 'F' && ch != 'F' && ch != state)
                ans++;
            if (ch != 'F')
                state = ch;
        }
        cout << "Case #" << (test + 1) << ": " << ans << endl;
    }
    return 0;
}
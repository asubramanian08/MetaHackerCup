// Wrong on 3 test cases (Note the error is somewhere in the else code block)
#include <iostream>
#include <string>
using namespace std;

#define MOD 1000000007
#define ADD(x, y) (((x) + (y)) % MOD)
#define ADD_TO(x, y) (x = ADD((x), (y)))
#define INC(x) ADD_TO(x, 1)
#define MUL(x, y) (((x) * (y)) % MOD)
#define SUB(x, y) (((x) - (y) + MOD) % MOD)

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
        long long left = 0, flips = 0, spaces = 0, started = -1, ans = 0;
        long long totalLen = 0, firstO = MOD, firstX = MOD;

        // Compute
        for (char ch : str)
        {
            // General stuff
            if (ch != '.')
                INC(totalLen);
            if (firstO == MOD && ch == 'O')
                firstO = totalLen;
            if (firstX == MOD && ch == 'X')
                firstX = totalLen;

            // Specific values
            if (ch != '.')
            {
                if (type == 'F' || ch == type)
                    started = totalLen, type = ch;
                if (ch != type && ch != 'F') // this is a flip
                {
                    ADD_TO(left, started);
                    INC(flips);
                    ADD_TO(spaces, SUB(totalLen, started + 1));
                    started = totalLen, type = ch;
                }
                ADD_TO(ans, left);
            }

            // repeat string - '.'
            else
            {
                // Duplication changes
                ADD_TO(ans, ans);
                ADD_TO(ans, MUL(totalLen, SUB(MUL(flips, totalLen), spaces)));
                ADD_TO(left, ADD(left, MUL(flips, totalLen)));
                ADD_TO(flips, flips);
                ADD_TO(spaces, spaces);

                // If there is a flip in the middle
                if (type != 'F' && ((type == 'O') == (firstX < firstO)))
                {
                    ADD_TO(left, started);
                    INC(flips);
                    long long first = (type == 'O' ? firstX : firstO);
                    ADD_TO(spaces, ADD(first, SUB(totalLen, started)) - 1);
                    ADD_TO(ans, MUL(started, SUB(totalLen, first) + 1));
                }

                // More changes
                ADD_TO(started, totalLen);
                ADD_TO(totalLen, totalLen);
            }
        }

        // print
        cout << "Case #" << (test + 1) << ": " << ans << endl;
    }
    return 0;
}
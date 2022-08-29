// Official: 9 points
#include <iostream>
using namespace std;

int main(void)
{
    int tests, n, m;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n >> m;
        bool hasTree = false;
        char ch;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> ch;
                if (ch == '^')
                    hasTree = true;
            }
        if ((n == 1 || m == 1) && hasTree)
            cout << "Case #" << (test + 1) << ": Impossible" << endl;
        else
        {
            cout << "Case #" << (test + 1) << ": Possible" << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                    cout << (hasTree ? '^' : '.');
                cout << endl;
            }
        }
    }
    return 0;
}
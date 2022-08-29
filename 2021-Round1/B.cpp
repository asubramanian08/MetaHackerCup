// All correct
#include <iostream>
using namespace std;

int main(void)
{
    int tests, n, m, a, b;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n >> m >> a >> b;
        bool possible = (a >= n + m - 1) && (b >= n + m - 1);
        cout << "Case #" << (test + 1) << ": " << (possible ? "Possible" : "Impossible") << endl;
        if (!possible)
            continue;
        cout << (a - n - m + 2) << ' ';
        for (int i = 1; i < m - 1; i++)
            cout << "1000 ";
        cout << (b - n - m + 2) << endl;
        for (int i = 1; i < n - 1; i++)
        {
            cout << "1 ";
            for (int j = 1; j < m - 1; j++)
                cout << "1000 ";
            cout << 1 << endl;
        }
        for (int i = 1; i < m; i++)
            cout << "1 ";
        cout << 1 << endl;
    }
    return 0;
}
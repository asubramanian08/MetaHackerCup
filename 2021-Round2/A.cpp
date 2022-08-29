// 3:16 - 3:58
#include <iostream>
#include <algorithm>
using namespace std;
using pib = pair<int, bool>;

int main(void)
{
    int tests, n, m;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n >> m;
        pib *prev = new pib[m];
        pib *curr = new pib[m];
        for (int i = 0; i < m; i++)
        {
            cin >> prev[i].first;
            prev[i].second = true;
        }
        int cost = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> curr[j].first;
            sort(curr, curr + m);
            sort(prev, prev + m);
            int prevPos = 0;
            for (int j = 0; j < m; j++)
            {
                while (prevPos < m && prev[prevPos].first < curr[j].first)
                    cost += (prev[prevPos++].second == false);
                if (prevPos == m || prev[prevPos].first != curr[j].first)
                    curr[j].second = false;
                else
                    curr[j].second = prev[prevPos].second, prevPos++;
            }
            while (prevPos < m)
                cost += (prev[prevPos++].second == false);
            swap(curr, prev);
        }
        cout << "Case #" << (test + 1) << ": " << cost << endl;
    }
}
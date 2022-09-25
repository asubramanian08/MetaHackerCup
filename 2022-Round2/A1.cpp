// Official: 10 points
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests, n, range[26], range2[26];
    int PS[1000010][26];
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        string str;
        cin >> str >> n;
        for (int i = 0; i < 26; i++)
            PS[0][i] = 0;
        for (int i = 1; i <= str.size(); i++)
        {
            for (int j = 0; j < 26; j++)
                PS[i][j] = PS[i - 1][j];
            PS[i][str[i - 1] - 'a']++;
        }
        int ans = 0, p1, p2;
        for (int j = 0; j < n; j++)
        {
            cin >> p1 >> p2;
            for (int i = 0; i < 26; i++)
                range[i] = PS[p2][i] - PS[p1 - 1][i];
            int odd = 0, extra = 0;
            for (int i = 0; i < 26; i++)
                if (range[i] % 2 == 1)
                {
                    odd++;
                    extra = i;
                }
            if (odd != 1)
                continue;
            range[extra]--;
            bool works = true;
            for (int i = 0; i < 26; i++)
            {
                range2[i] = PS[(p1 + p2) / 2 - 1][i] - PS[p1 - 1][i];
                works = works && (range[i] - range2[i] == range2[i]);
            }
            if (!works)
            {
                works = true;
                range2[extra]--;
                range2[str[(p1 + p2) / 2 - 1] - 'a']++;
                for (int i = 0; i < 26; i++)
                    works = works && (range[i] - range2[i] == range2[i]);
            }
            ans += works;
        }
        cout << "Case #" << (test + 1) << ": " << ans << endl;
    }
}
// 4:30 - 4:53
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int tests, r, c, k, curr;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> r >> c >> k;
        k--;
        string *grid = new string[r];
        for (int i = 0; i < r; i++)
            cin >> grid[i];
        int *carsAt = new int[c];
        for (int i = 0; i < c; i++)
            carsAt[i] = 0;
        for (int i = k + 1; i < r; i++)
            for (int j = 0; j < c; j++)
                if (grid[i][j] == 'X')
                    carsAt[j]++;
        int ans = 1'000'000'000;
        for (int i = k; i >= 0; i--)
        {
            curr = k - i;
            for (int j = 0; j < c; j++)
                if (grid[i][j] == 'X')
                    curr++, carsAt[j]++;
                else
                    curr += carsAt[j] >= r - k;
            ans = min(ans, curr);
        }
        curr = k + 1;
        for (int i = 0; i < c; i++)
        {
            curr += carsAt[i] >= r - k;
            carsAt[i] = 0;
        }
        ans = min(ans, curr);
        for (int i = 0; i < k; i++)
            for (int j = 0; j < c; j++)
                if (grid[i][j] == 'X')
                    carsAt[j]++;
        for (int i = k; i < r; i++)
        {
            curr = i - k;
            for (int j = 0; j < c; j++)
                if (grid[i][j] == 'X')
                    curr++, carsAt[j]++;
                else
                    curr += carsAt[j] >= k + 1;
            ans = min(ans, curr);
        }
        curr = r - k;
        for (int j = 0; j < c; j++)
            curr += carsAt[j] >= k + 1;
        ans = min(ans, curr);
        cout << "Case #" << (test + 1) << ": " << ans << endl;
    }
}
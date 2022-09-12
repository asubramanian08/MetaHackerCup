// Official: 12 points
#include <iostream>
#include <cassert>
using namespace std;
#define MOD 1000000007
#define RANGE 3010
using ll = long long;

// Variables
ll tests, totalCost, n, q, x, y;
ll xTrees[RANGE], yTrees[RANGE], xWells[RANGE], yWells[RANGE];

int main(void)
{
    // read
    iostream::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n;
        for (int i = 0; i < RANGE; i++)
            xTrees[i] = yTrees[i] = xWells[i] = yWells[i] = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            xTrees[x]++;
            yTrees[y]++;
        }
        cin >> q;
        for (int i = 0; i < q; i++)
        {
            cin >> x >> y;
            xWells[x]++;
            yWells[y]++;
        }

        // Calculate total cost and print
        totalCost = 0;
        for (int i = 0; i < RANGE; i++)
            for (int j = 0; j < RANGE; j++)
                if ((xTrees[i] && xWells[j]) || (yTrees[i] && yWells[j]))
                {
                    ll currX = (xTrees[i] * xWells[j]) % MOD * ((j - i) * (j - i)) % MOD;
                    ll currY = (yTrees[i] * yWells[j]) % MOD * ((j - i) * (j - i)) % MOD;
                    totalCost = (totalCost + currX % MOD + currY % MOD) % MOD;
                }
        cout << "Case #" << (test + 1) << ": " << totalCost << endl;
    }
    return 0;
}
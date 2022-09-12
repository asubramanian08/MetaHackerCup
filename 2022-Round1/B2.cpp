// Official: 18 points
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
#define MOD 1000000007
using ll = long long;

// Variables
ll tests, totalCost, n, q;
ll xTrees[500010], yTrees[500010], xWells[500010], yWells[500010];

// Functions
ll jump(ll hops, ll nodes, ll toAdd, ll currCost, ll pastTrees)
{
    if (hops == 0)
        return currCost;
    toAdd = (toAdd + (2 * nodes) % MOD - pastTrees + MOD) % MOD;
    currCost = (currCost + toAdd) % MOD;
    hops--;
    if (hops == 0)
        return currCost;
    return (currCost + (hops * toAdd % MOD) + (hops * (hops + 1) % MOD * nodes % MOD)) % MOD;
}

void calcCost()
{
    ll i, j, last, toAdd, currCost, pastTrees;

    currCost = i = j = toAdd = pastTrees = 0;
    last = min(xTrees[0], xWells[0]);
    while (i < n || j < q)
        if (i < n && (j == q || xTrees[i] < xWells[j]))
        {
            if (xTrees[i] > last)
            {
                ll temp = jump(xTrees[i] - last - 1, i, toAdd, currCost, pastTrees);
                currCost = jump(xTrees[i] - last, i, toAdd, currCost, pastTrees);
                toAdd = (currCost - temp + MOD) % MOD;
                pastTrees = 1, last = xTrees[i];
            }
            else
                pastTrees++;
            i++;
        }
        else // if (j < q && (i == n || xWells[j] < xTrees[i]))
        {
            if (xWells[j] > last)
            {
                ll temp = jump(xWells[j] - last - 1, i, toAdd, currCost, pastTrees);
                currCost = jump(xWells[j] - last, i, toAdd, currCost, pastTrees);
                toAdd = (currCost - temp + MOD) % MOD;
            }

            totalCost = (currCost + totalCost) % MOD;
            last = xWells[j];
            pastTrees = 0;
            j++;
        }

    currCost = toAdd = pastTrees = 0, i = n - 1, j = q - 1;
    last = max(xTrees[i], xWells[j]);
    while (i >= 0 || j >= 0)
        if (i >= 0 && (j == -1 || xTrees[i] > xWells[j]))
        {
            if (xTrees[i] < last)
            {
                ll temp = jump(last - xTrees[i] - 1, n - i - 1, toAdd, currCost, pastTrees);
                currCost = jump(last - xTrees[i], n - i - 1, toAdd, currCost, pastTrees);
                toAdd = (currCost - temp + MOD) % MOD;
                pastTrees = 1, last = xTrees[i];
            }
            else
                pastTrees++;
            i--;
        }
        else // if (j >= 0 && (i == -1 || xWells[j] > xTrees[i]))
        {
            if (xWells[j] < last)
            {
                ll temp = jump(last - xWells[j] - 1, n - i - 1, toAdd, currCost, pastTrees);
                currCost = jump(last - xWells[j], n - i - 1, toAdd, currCost, pastTrees);
                toAdd = (currCost - temp + MOD) % MOD;
            }

            totalCost = (currCost + totalCost) % MOD;
            last = xWells[j];
            pastTrees = 0;
            j--;
        }
}

int main(void)
{
    // read
    iostream::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> xTrees[i] >> yTrees[i];
        cin >> q;
        for (int i = 0; i < q; i++)
            cin >> xWells[i] >> yWells[i];
        sort(xTrees, xTrees + n);
        sort(yTrees, yTrees + n);
        sort(xWells, xWells + q);
        sort(yWells, yWells + q);

        // Calculate total cost and print
        totalCost = 0;
        calcCost();
        for (int i = 0; i < n; i++)
            swap(xTrees[i], yTrees[i]);
        for (int i = 0; i < q; i++)
            swap(xWells[i], yWells[i]);
        calcCost();
        cout << "Case #" << (test + 1) << ": " << totalCost << endl;
    }
    return 0;
}
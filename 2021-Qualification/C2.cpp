#include <iostream>
#include <vector>
using namespace std;
#define MAX_N 50
#define MAX_K 51

int tests, DP[MAX_N][MAX_K][2], n, k, gold[MAX_N], DP2[MAX_K][2][2];
vector<int> tree[MAX_N];

void recursion(int nd)
{
    for (int i = 1; i <= k; i++)
    {
        DP[nd][i][0] = 0;
        DP[nd][i][1] = gold[nd];
        DP2[i][0][0] = DP2[i][0][1] =
            DP2[i][1][0] = DP2[i][1][1] = 0;
    }
    for (int next : tree[nd])
    {
        recursion(next);
        for (int i = 1; i <= k; i++)
    }
}

int main(void)
{
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> gold[i];
            tree[i].clear();
        }
        for (int i = 1; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        recursion(0);
        cout << "Case #" << test << ": " << DP[0][k][1] << endl;
    }
    return 0;
}
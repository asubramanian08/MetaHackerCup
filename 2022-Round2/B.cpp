// Official: 18 points
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
#define MOD 1000000007

#define MAX_N 1000010
ll startDay[MAX_N], endDay[MAX_N], buyPrice[MAX_N], sellPrice[MAX_N];
map<ll, vector<ll>> daysBuy, daysSell;
vector<ll> kProfitablePaths[MAX_N];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll tests, n, k;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n >> k;
        daysBuy.clear();
        daysSell.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> startDay[i] >> endDay[i] >> buyPrice[i] >> sellPrice[i];
            daysBuy[startDay[i]].push_back(i);
            daysSell[endDay[i]].push_back(i);
            kProfitablePaths[i].clear();
        }
        for (auto &day : daysBuy)
        {
            vector<pii> buyers(day.second.size());
            for (int i = 0; i < day.second.size(); i++)
                buyers[i] = {buyPrice[day.second[i]], day.second[i]};
            sort(buyers.begin(), buyers.end());

            vector<ll> paths;
            auto sellers = daysSell[day.first];
            sort(sellers.begin(), sellers.end(), [](ll a, ll b)
                 { return sellPrice[a] < sellPrice[b]; });
            auto seller = sellers.begin();
            for (int j = 0; j < buyers.size(); j++)
            {
                while (seller != sellers.end() && sellPrice[*seller] < buyers[j].first)
                {
                    for (auto path : kProfitablePaths[*seller])
                        paths.push_back(path - sellPrice[*seller]);
                    seller++;
                }
                sort(paths.begin(), paths.end(), greater<ll>());
                if (paths.size() > k)
                    paths.resize(k);
                for (int i = 0; i < paths.size() && i < k; i++)
                    kProfitablePaths[buyers[j].second].push_back(paths[i] + buyers[j].first);
                kProfitablePaths[buyers[j].second].push_back(0);
            }
        }
        vector<ll> finalPaths;
        for (int i = 0; i < n; i++)
            finalPaths.insert(finalPaths.end(), kProfitablePaths[i].begin(), kProfitablePaths[i].end());
        sort(finalPaths.begin(), finalPaths.end(), greater<ll>());
        long long ans = 0;
        for (int i = 0; i < k && i < finalPaths.size(); i++)
            if (finalPaths[i] > 0)
                ans = (ans + finalPaths[i]) % MOD;
        cout << "Case #" << (test + 1) << ": " << ans << endl;
    }
}
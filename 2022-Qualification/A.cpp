// Official: 9 points
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

int tests, styles[110], n, k;
bool canSort()
{
    int left = 1, right = 0, lastRight = -1;
    for (int i = 1; i < n; i++)
        if (styles[i] != styles[i - 1])
            left++;
        else
        {
            if (styles[i] == lastRight)
                return false;
            right++;
            lastRight = styles[i];
        }
    int show1 = right, show2 = right;
    show1 += (left - right) / 2;
    show2 += (left - right + 1) / 2;
    return show2 <= k;
}

int main(void)
{
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> styles[i];
        sort(styles, styles + n);
        int count1 = 0, count2 = 0, occ = 1;
        bool works = true;
        for (int i = 1; i < n && works; i++)
            if (styles[i] != styles[i - 1])
            {
                if (occ > 2)
                    works = false;
                else if (occ == 2)
                    count2++;
                else
                    count1++;
                occ = 1;
            }
            else
                occ++;
        if (occ > 2)
            works = false;
        else if (occ == 2)
            count2++;
        else
            count1++;
        if (works)
            assert(count1 + 2 * count2 == n);
        if (works && (k - count2) * 2 >= count1)
        {
            assert(canSort());
            cout << "Case #" << (test + 1) << ": YES" << endl;
        }
        else
        {
            cout << "Case #" << (test + 1) << ": NO" << endl;
            assert(!works || k * 2 < n);
        }
    }
    return 0;
}
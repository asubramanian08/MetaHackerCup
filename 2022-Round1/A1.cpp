// Official: 10 points
#include <iostream>
#include <cassert>
using namespace std;
#define MOD 1000000007
#define MULT 13

long long tests, A[500010], B[500010], n, k, A_hash, B_hash, rem_mult;
void compute_hash(bool is_A)
{
    long long hash = 0;
    for (int i = 0; i < n; i++)
        hash = (hash * MULT + (is_A ? A : B)[i]) % MOD;
    (is_A ? A_hash : B_hash) = hash;
}

bool same_number()
{
    bool ret = true;
    for (int i = 1; i < n && ret; i++)
        ret = A[i] == A[0];
    return ret;
}

int main(void)
{
    // read
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> A[i];
        for (int i = 0; i < n; i++)
            cin >> B[i];

        // determine if B is a cyclic shift of A
        compute_hash(true), compute_hash(false);
        rem_mult = 1;
        for (int i = 1; i < n; i++)
            rem_mult = (rem_mult * MULT) % MOD;
        bool is_cycle = false;
        for (int i = 0; i < n && !is_cycle; i++)
        {
            if (A_hash == B_hash)
                is_cycle = true;
            B_hash = (B_hash - (rem_mult * B[i] % MOD) + MOD) % MOD;
            B_hash = (B_hash * MULT + B[i]) % MOD;
        }

        // determine if A == B
        bool is_equal = true;
        for (int i = 0; i < n && is_equal; i++)
            if (A[i] != B[i])
                is_equal = false;

        if (!is_cycle)
            cout << "Case #" << (test + 1) << ": NO" << endl;
        else if (k == 0 || same_number())
            cout << "Case #" << (test + 1) << ": " << (is_equal ? "YES" : "NO") << endl;
        else if (k == 1)
            cout << "Case #" << (test + 1) << ": " << (!is_equal ? "YES" : "NO") << endl;
        else if (k % 2 == 1)
            cout << "Case #" << (test + 1) << ": " << (n > 2 || !is_equal ? "YES" : "NO") << endl;
        else // if (k % 2 == 0)
            cout << "Case #" << (test + 1) << ": " << (n > 2 || is_equal ? "YES" : "NO") << endl;
    }
    return 0;
}
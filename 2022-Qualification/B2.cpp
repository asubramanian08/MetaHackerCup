// Official: 17 points - Not Submitted
#include <iostream>
using namespace std;

int tests, n, m;
char pic[3010][3010];
bool works = true;
int x[] = {0, -1, 0, +1};
int y[] = {-1, 0, +1, 0};

bool lonely(int r, int c)
{
    int friends = 0;
    for (int i = 0; i < 4; i++)
    {
        char ch = pic[x[i] + r][y[i] + c];
        friends += (ch == '.' || ch == '^');
    }
    return friends < 2;
}
void DFS(int r, int c)
{
    if (pic[r][c] == '#' || pic[r][c] == '*' || !lonely(r, c))
        return;
    if (pic[r][c] == '^')
        works = false;
    pic[r][c] = '*';
    for (int i = 0; i < 4; i++)
        DFS(x[i] + r, y[i] + c);
}

int main(void)
{
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        cin >> n >> m;
        for (int i = 0; i <= n + 1; i++)
            for (int j = 0; j <= m + 1; j++)
                if (0 < i && i <= n && 0 < j && j <= m)
                    cin >> pic[i][j];
                else
                    pic[i][j] = '#';
        works = true;
        for (int i = 1; i <= n && works; i++)
            for (int j = 1; j <= m && works; j++)
                DFS(i, j);
        cout << "Case #" << (test + 1) << ": " << (works ? "Possible" : "Impossible") << endl;
        if (works)
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                    if (pic[i][j] == '*')
                        cout << '.';
                    else if (pic[i][j] == '.')
                        cout << '^';
                    else
                        cout << pic[i][j];
                cout << endl;
            }
    }
    return 0;
}
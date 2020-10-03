#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles)
{
    int memo[101][101] = {0, };
    
    for (int i = 1; i < m; ++i)
        memo[1][i] = 1;
    
    for (int i = 1; i < n; ++i)
        memo[i][1] = 1;
    
    for (int i = 0; i < puddles.size(); ++i)
        memo[puddles[i][1]][puddles[i][0]] = -1;
    
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (i == 1 && j == 1)   { continue; }
            if (memo[i][j] == -1)   { memo[i][j] = 0; }
            else                    { memo[i][j] = (memo[i - 1][j] + memo[i][j - 1]) % 1000000007; }
        }
    }
    
    return memo[n][m];
}

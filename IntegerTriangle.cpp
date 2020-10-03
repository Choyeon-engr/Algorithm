#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle)
{
    int answer = 0, n = triangle.size();
    int memo[502][502];
    
    memo[0][0] = triangle[0][0];
    memo[1][0] = memo[0][0] + triangle[1][0];
    memo[1][1] = memo[0][0] + triangle[1][1];
    
    for (int i = 2; i < n; ++i)
    {
        for (int j = 0; j < triangle[i].size(); ++j)
        {
            if (j == 0)                             { memo[i][j] = memo[i - 1][0] + triangle[i][j]; }
            else if (j == triangle[i].size() - 1)   { memo[i][j] = memo[i - 1][j - 1] + triangle[i][j]; }
            else
            {
                if (memo[i - 1][j - 1] >= memo[i - 1][j])
                    memo[i][j] = memo[i - 1][j - 1] + triangle[i][j];
                else
                    memo[i][j] = memo[i - 1][j] + triangle[i][j];
            }
        }
    }
    
    for (int i = 0; i < n; ++i)
        if (answer < memo[n - 1][i])    { answer = memo[n - 1][i]; }
    
    return answer;
}

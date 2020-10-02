#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes)
{
    sort(routes.begin(), routes.end());
    int answer = 1, minRange = routes[0][1];
    
    for (int i = 0; i < routes.size() - 1; ++i)
    {
        if (minRange > routes[i][1]) { minRange = routes[i][1]; }
        if (minRange < routes[i + 1][0])
        {
            ++answer;
            minRange = routes[i + 1][1];
        }
    }
    
    return answer;
}

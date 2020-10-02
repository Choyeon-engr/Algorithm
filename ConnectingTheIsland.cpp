#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int getParent(vector<int>& parents, int x)
{
    if (parents[x] == x)    { return x; }
    
    return parents[x] = getParent(parents, parents[x]);
}

void unionParent(vector<int>& parents, int a, int b)
{
    a = getParent(parents, a);
    b = getParent(parents, b);
    
    a < b ? parents[b] = a : parents[a] = b;
}

bool find(vector<int>& parents, int a, int b)
{
    a = getParent(parents, a);
    b = getParent(parents, b);
    
    return a == b;
}

int solution(int n, vector<vector<int>> costs)
{
    int answer = 0, max = 0;
    vector<int> parents;
    
    sort(costs.begin(), costs.end(), cmp);
    
    for (auto cost : costs)
        if (max < cost[1])  { max = cost[1]; }
    
    for (int i = 0; i <= max; ++i)  { parents.emplace_back(i); }
    
    for (auto cost : costs)
    {
        if (!find(parents, cost[0], cost[1]))
        {
            answer += cost[2];
            unionParent(parents, cost[0], cost[1]);
        }
    }
        
    return answer;
}

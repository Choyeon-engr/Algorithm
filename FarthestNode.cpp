#include <vector>
#include <algorithm>

using namespace std;

void bfs(int curNode, vector<vector<bool>>& graph, vector<int>& distance, vector<int> v)
{
    vector<int> tmp;
    
    while (!v.empty())
    {
        for (int i = 1; i < graph.size(); ++i)
        {
            if (graph[v[0]][i] && !distance[i])
            {
                tmp.emplace_back(i);
                distance[i] = curNode;
            }
        }
        
        v.erase(v.begin());
    }
    
    if (!tmp.empty())   { bfs(curNode + 1, graph, distance, tmp); }
}

int solution(int n, vector<vector<int>> edge)
{
    int answer = 0;
    vector<vector<bool>> graph(n, vector<bool>(n, false));
    vector<int> distance(n, 0);
    
    for (auto e : edge)
    {
        graph[e[0] - 1][e[1] - 1] = true;
        graph[e[1] - 1][e[0] - 1] = true;
    }
    
    bfs(1, graph, distance, {0});
    
    int max = *max_element(distance.begin(), distance.end());
    
    for (auto d : distance)
        if (d == max)   { ++answer; }
    
    return answer;
}

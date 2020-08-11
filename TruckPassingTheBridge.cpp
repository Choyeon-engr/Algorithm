#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0, acrossWeights = 0, next = 0, over = 0;
    queue<int> across;
    
    while (over < truck_weights.size())
    {
        if (across.size() && across.front() + bridge_length <= answer)
        {
            across.pop();
            acrossWeights -= truck_weights[over++];
        }
        
        if (across.size() < bridge_length && acrossWeights + truck_weights[next] <= weight)
        {
            across.emplace(answer);
            acrossWeights += truck_weights[next++];
        }
        
        ++answer;
    }
    
    return answer;
}

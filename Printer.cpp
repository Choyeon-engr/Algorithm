#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    
    for (int i = 0; i < priorities.size(); ++i)
    {
        q.emplace(i, priorities[i]);
        pq.emplace(priorities[i]);
    }
    
    while (true)
    {
        int idx = q.front().first;
        int priority = q.front().second;
        q.pop();
        
        if (priority == pq.top())
        {
            ++answer;
            
            if (idx == location)
                break;
            
            pq.pop();
        }
        
        q.emplace(idx, priority);
    }
    
    return answer;
}

#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct cmp
{
    bool operator()(vector<int> a, vector<int> b)
    {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs)
{
    int answer = 0, i = 0, ms = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    
    sort(jobs.begin(), jobs.end());
    
    while (i < jobs.size() || !pq.empty())
    {
        if (i < jobs.size() && jobs[i][0] <= ms)
        {
            pq.emplace(jobs[i++]);
            continue;
        }
        
        if(!pq.empty())
        {
            ms += pq.top()[1];
            answer += ms - pq.top()[0];
            pq.pop();
        }
        else
            ms = jobs[i][0];
    }
    
    return answer / jobs.size();
}

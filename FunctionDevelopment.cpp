#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    int idx = 0;
    vector<int> answer;
    
    while (true)
    {
        if (idx == progresses.size())
            break;
        
        for (int i = 0; i < progresses.size(); ++i)
            progresses[i] += speeds[i];
        
        int cnt = 0;
        
        for (idx = idx; idx < progresses.size(); ++idx)
        {
            if (progresses[idx] >= 100)
                ++cnt;
            else
                break;
        }
        
        if (cnt)
            answer.emplace_back(cnt);
    }
    
    return answer;
}

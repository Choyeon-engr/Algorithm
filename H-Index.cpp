#include <vector>

using namespace std;

int solution(vector<int> citations)
{
    int answer = 0, cnt;
    
    for (int i = 0; i <= citations.size(); ++i)
    {
        cnt = 0;
        
        for (int j = 0; j < citations.size(); ++j)
            if (citations[j] >= i)  { ++cnt; }
        
        if (cnt >= i && citations.size() - cnt <= i)
            answer = (answer > i ? answer : i);
    }
    
    return answer;
}

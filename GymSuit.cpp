#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = n;
    
    for (int i = 0; i < lost.size(); ++i)
        for (int j = 0; j < reserve.size(); ++j)
            if (lost[i] == reserve[j])
            {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
            }
    
    for (int i = 0; i < lost.size(); ++i)
    {
        bool flag = true;
        
        for (int j = 0; j < reserve.size(); ++j)
            if (lost[i] - 1 <= reserve[j] && lost[i] + 1 >= reserve[j])
            {
                flag = false;
                reserve.erase(reserve.begin() + j);
                break;
            }
        
        if (flag)
            --answer;
    }
    
    return answer;
}

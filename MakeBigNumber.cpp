#include <string>

using namespace std;

string solution(string number, int k)
{
    string answer = "";
    int start = 0;
    
    for (int i = 0; i < number.size() - k; ++i)
    {
        char maxNum = number[start];
        int maxIdx = start;
        
        for (int j = start; j <= k + i; ++j)
        {
            if (maxNum < number[j])
            {
                maxNum = number[j];
                maxIdx = j;
            }
        }
        
        answer += maxNum;
        start = maxIdx + 1;
    }
    
    return answer;
}

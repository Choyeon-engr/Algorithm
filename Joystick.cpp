#include <string>
#include <cmath>

using namespace std;

int solution(string name)
{
    int answer = 0, n = name.size(), turn = n - 1;
    
    for (int i = 0; i < n; ++i)
    {
        int front = name[i] - 'A';
        int rear = 'Z' - name[i] + 1;
        
        if (front > rear)   { answer += rear; }
        else                { answer += front; }
        
        int next = i + 1;
        
        while (next < n && name[next] == 'A') { ++next; }
        
        turn = min(turn, i + n - next + min(i, n - next));
    }
    
    answer += turn;
    
    return answer;
}

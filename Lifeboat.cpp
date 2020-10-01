#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0, front = 0, rear = people.size() - 1;
    
    sort(people.begin(), people.end());
    
    while (front < rear)
    {
        if (people[front] + people[rear] <= limit)
        {
            ++front;
            --rear;
        }
        else
            --rear;
        
        ++answer;
    }
    
    return answer;
}

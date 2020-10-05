#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times)
{
    long long answer = 0, min = 1, max, avg, howMany = 0;
    max = *max_element(times.begin(), times.end()) * (long long)n;
    
    while(min <= max)
    {
        avg = (min + max) / 2;
        
        for (auto time: times)  { howMany += avg / time; }
        
        if (n <= howMany)
        {
            answer = avg;
            max = avg - 1;
        }
        else    { min = avg + 1; }
        
        howMany = 0;
    }
    
    return answer;
}

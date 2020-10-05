#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n)
{
    int left = 1, right = distance;

    sort(rocks.begin(), rocks.end());
    rocks.emplace_back(distance);

    while (left <= right)
    {
        int middle = (left + right) / 2, removed = 0;
        
        while (rocks[removed] < middle)  { ++removed; }

        int p = removed;

        for (int i = removed + 1; i < rocks.size(); ++i)
        {
            if ((rocks[i] - rocks[p]) < middle) { if (++removed > n)  { break; } }
            else                                { p = i; }
        }

        if (removed <= n)   { left = middle + 1; }
        else                { right = middle - 1; }
    }

    return left - 1;
}

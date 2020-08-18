#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;
    
    for (int i = 0; i < commands.size(); ++i)
    {
        vector<int> sortArray;
        for (int j = commands[i][0] - 1; j < commands[i][1]; ++j)
            sortArray.emplace_back(array[j]);
        
        sort(sortArray.begin(), sortArray.end());
        
        answer.emplace_back(sortArray[commands[i][2] - 1]);
    }
    
    return answer;
}

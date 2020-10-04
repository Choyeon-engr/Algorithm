#include <string>
#include <vector>

using namespace std;

int answer = 50;

void dfs(string begin, string target, vector<string> words, vector<bool> isUsed, int count = 0)
{
    for (int i = 0; i < words.size(); ++i)
    {
        int cnt = 0;
        
        for (int j = 0; j < words[i].size(); ++j)
            if (!isUsed[i] && begin[j] != words[i][j])  { ++cnt; }
        
        if (cnt == 1)
        {
            if (target == words[i] && answer > count + 1)
            {
                answer = count + 1;
                return;
            }
            
            isUsed[i] = true;
            dfs(words[i], target, words, isUsed, count + 1);
            isUsed[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words)
{
    vector<bool> isUsed(words.size(), false);
    
    dfs(begin, target, words, isUsed);
    
    if (answer == 50)   { return 0; }
    
    return answer;
}

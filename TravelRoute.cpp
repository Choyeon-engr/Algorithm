#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> answer;

void dfs(vector<vector<string>>& tickets, vector<pair<int, int>>& isUsed, string from, int count)
{
    if (count == tickets.size())
    {
        vector<string> ans;
        vector<pair<int, int>> uses = isUsed;
        
        sort(uses.begin(), uses.end());
        
        for (auto use : uses)   { ans.emplace_back(tickets[use.second][0]); }
        ans.emplace_back(tickets[uses[uses.size() - 1].second][1]);
        
        answer.emplace_back(ans);
        
        return;
    }
    
    for (int i = 0; i < tickets.size(); ++i)
    {
        if (isUsed[i].second == -1 && tickets[i][0] == from)
        {
            isUsed[i] = {count, i};
            dfs(tickets, isUsed, tickets[i][1], count + 1);
            isUsed[i] = {0, -1};
        }
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    vector<pair<int, int>> isUsed(tickets.size(), {0, -1});
    
    dfs(tickets, isUsed, "ICN", 0);
    sort(answer.begin(), answer.end());
    
    return answer[0];
}

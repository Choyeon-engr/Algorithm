#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(pair<string, int>a, pair<string, int>b)
{
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    map<string, int> cntByGenres;
    vector<pair<string, int>> rankByCnt;
    
    for (int idx = 0; idx < genres.size(); ++idx)
        cntByGenres[genres[idx]] += plays[idx];
    
    for (auto itr = cntByGenres.begin(); itr != cntByGenres.end(); ++itr)
        rankByCnt.emplace_back(itr->first, itr->second);
    
    sort(rankByCnt.begin(), rankByCnt.end(), compare);
    
    for (auto i = rankByCnt.begin(); i != rankByCnt.end(); ++i)
    {
        int first = 0, second = 0, firstIdx = 0, secondIdx = 0;
        
        for (int j = 0; j < genres.size(); ++j)
        {
            if (i->first == genres[j])
            {
                if (plays[j] > first)
                {
                    second = first;
                    secondIdx = firstIdx;
                    first = plays[j];
                    firstIdx = j;
                }
                
                else if (plays[j] > second)
                {
                    second = plays[j];
                    secondIdx = j;
                }
            }
        }
        
        answer.emplace_back(firstIdx);
        if (second > 0)
            answer.emplace_back(secondIdx);
    }
    
    return answer;
}

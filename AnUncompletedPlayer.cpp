#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    map<string, int> cRunner;
    
    for (string p : participant)
        ++cRunner[p];
    
    for (string c : completion)
        --cRunner[c];
    
    for (auto i = cRunner.begin(); i != cRunner.end(); ++i)
        if (i->second)
        {
            answer = i->first;
            break;
        }
    
    return answer;
}

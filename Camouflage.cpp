#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    map<string, int> quantityByType;
    
    for (vector<string> cloth : clothes)
        ++quantityByType[cloth[1]];
    
    for (auto i = quantityByType.begin(); i != quantityByType.end(); ++i)
        answer *= i->second + 1;
    
    return --answer;
}

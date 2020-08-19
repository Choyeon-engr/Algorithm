#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers)
{
    string answer = "";
    vector<string> strNumbers;
    
    for (int number : numbers)
        strNumbers.emplace_back(to_string(number));
    
    sort(strNumbers.begin(), strNumbers.end(), cmp);
    
    for (string strNumber : strNumbers)
        answer += strNumber;
    
    if (answer[0] == '0')
        return "0";
    
    return answer;
}

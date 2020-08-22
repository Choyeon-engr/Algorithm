#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int number)
{
    if (number < 2)
        return false;
    
    for (int i = 2; i * i <= number; ++i)
        if (!(number % i))
            return false;
    
    return true;
}

int solution(string numbers)
{
    int answer = 0;
    vector<int> vNumbers, allNumbers;
    
    for (int i = 0; i < numbers.size(); ++i)
        vNumbers.emplace_back(numbers[i] - '0');
    
    sort(vNumbers.begin(), vNumbers.end());
    
    do
    {
        for (int i = 0; i <= vNumbers.size(); ++i)
        {
            int tmp = 0;
            
            for (int j = 0; j < i; ++j)
            {
                tmp = tmp * 10 + vNumbers[j];
                allNumbers.emplace_back(tmp);
            }
        }
    } while (next_permutation(vNumbers.begin(), vNumbers.end()));
    
    sort(allNumbers.begin(), allNumbers.end());
    allNumbers.erase(unique(allNumbers.begin(), allNumbers.end()), allNumbers.end());
    
    for (int i = 0; i < allNumbers.size(); ++i)
        if (isPrime(allNumbers[i]))
            ++answer;
    
    return answer;
}

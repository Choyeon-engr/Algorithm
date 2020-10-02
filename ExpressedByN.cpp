int answer = 9;

void dfs(int N, int number, int cnt, int curNum)
{
    if (cnt >= 9)   { return; }
    if (number == curNum)
    {
        answer = (answer < cnt ? answer : cnt);
        return;
    }
    
    int tmp = 0;
    for (int i = 0; i + cnt < 9; ++i)
    {
        tmp = tmp * 10 + N;
        dfs(N, number, cnt + 1 + i, curNum + tmp);
        dfs(N, number, cnt + 1 + i, curNum - tmp);
        dfs(N, number, cnt + 1 + i, curNum * tmp);
        dfs(N, number, cnt + 1 + i, curNum / tmp);
    }
}

int solution(int N, int number)
{
    dfs(N, number, 0, 0);
    
    if (answer == 9)    { return -1; }
    
    return answer;
}

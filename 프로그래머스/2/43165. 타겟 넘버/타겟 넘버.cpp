#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(const vector<int>&numbers, int target, int sum, int index)
{
    if(index == numbers.size() && sum == target)
    {
        return 1;
    }
    else if(index == numbers.size() && sum != target)
    {
        return 0;
    }
    int left = dfs(numbers, target, sum - numbers[index], index+1);
    int right = dfs(numbers, target, sum + numbers[index], index+1);
    return (left+right);
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    int index=0;
    answer = dfs(numbers, target, 0, index);
    
    return answer;
}
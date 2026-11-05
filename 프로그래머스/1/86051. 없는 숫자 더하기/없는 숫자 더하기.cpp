#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> numbers) {
    int answer = -1;
    sort(numbers.begin(), numbers.end());
    int index=0;
    vector<int> remain_nums;
    
    int sum_remain=0;
    for(int i=0;i<10;i++)
    {
        if(index<numbers.size() && numbers[index]==i)
        {
            index++;
        }
        else
        {
            sum_remain+=i;
            //remain_nums.push_back(i);
        }
    }
    answer=sum_remain;
    
    return answer;
}
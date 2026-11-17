#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> one = {1, 2, 3, 4, 5};
    vector<int> two = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> three = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int index=0;
    int one_max = 5;
    int two_max = 8;
    int three_max = 10;
    
    int one_index=0;
    int two_index=0;
    int three_index=0;
    
    pair<int,int> one_count={0, 1};
    pair<int,int> two_count={0, 2};
    pair<int,int> three_count={0, 3};
    for(const auto& an : answers)
    {
        one_index=index%one_max;
        two_index=index%two_max;
        three_index=index%three_max;
        if(one[one_index]==an)
            one_count.first++;
        if(two[two_index]==an)
            two_count.first++;
        if(three[three_index]==an)
            three_count.first++;
        
        index++;
    }
    vector<pair<int, int>> counts = {one_count,two_count,three_count};
    sort(counts.begin(), counts.end(), greater<pair<int, int>>());
    
    answer.push_back(counts[0].second);
    if(counts[0].first == counts[1].first)
    {
        answer.push_back(counts[1].second);
    }
    if(counts[0].first == counts[2].first)
    {
        answer.push_back(counts[2].second);
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}
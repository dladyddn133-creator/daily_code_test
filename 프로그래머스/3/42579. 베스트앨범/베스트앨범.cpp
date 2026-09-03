#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<pair<int, int>>> count_genres;
    vector<pair<string, int>> ordered_genres;
    
    for(int i=0;i<genres.size();i++)
    {
        count_genres[genres[i]].push_back({plays[i], i});
    }
    for(auto& x : count_genres)
    {
        int sum = 0;
        for(int i=0;i<x.second.size();i++)
        {
            sum+=x.second[i].first;
        }
        ordered_genres.push_back({x.first, sum}); 
        
        sort(x.second.begin(),x.second.end(),
            [](const auto& a, const auto& b)
             {
                 if(a.first == b.first)
                 {
                     return a.second < b.second;
                 }
                 else 
                     return a.first > b.first;
             });
    }
    sort(ordered_genres.begin(),ordered_genres.end(),
        [](const auto& a, const auto& b)
         {
             return a.second > b.second;
         });
    for(const auto& x : ordered_genres)
    {
        answer.push_back(count_genres[x.first][0].second);
        if(count_genres[x.first].size()>=2){
            answer.push_back(count_genres[x.first][1].second);
        }
    }
    
    return answer;
}
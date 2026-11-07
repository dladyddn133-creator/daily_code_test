#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string,int> score_name;
    int index=0;
    for(const auto & na : name)
    {
        score_name[na] = yearning[index++];
    }
    for(int i=0;i<photo.size();i++)
    {
        int total_score=0;
        for(const auto& mem : photo[i])
        {
            total_score+=score_name[mem];
        }
        answer.push_back(total_score);
    }
    
    return answer;
}
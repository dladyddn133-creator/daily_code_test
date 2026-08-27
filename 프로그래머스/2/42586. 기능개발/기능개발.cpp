#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> requir;
    for(int i=0; i <progresses.size(); i++)
    {
        requir.push_back((100 - progresses[i] + speeds[i] -1)/speeds[i]);
    }
    int count = 0;
    int local_max=0;
    
    for(int i=0;i<requir.size();i++)
    {
        if(i==0)
        {
            count++;
            local_max=requir[0];
        }
        else if(local_max < requir[i])
        {
            answer.push_back(count);
            count=1;
            local_max = requir[i];
        }
        else
        {
            count++;
        }
    }
    
    answer.push_back(count);
    
    
    return answer;
}
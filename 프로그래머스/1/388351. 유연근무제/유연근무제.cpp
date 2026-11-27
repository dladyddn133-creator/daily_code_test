#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for(auto& sc : schedules)
    {
        int hour = sc/100;
        int to_min = hour *60;
        int min = sc % 100;
        sc = to_min + min;
        // cout <<sc<<'\n';
    }
    
    for(auto& t_row: timelogs)
    {
        for(auto& t_col : t_row)
        {
            int hour = t_col/100;
            int to_min = hour *60;
            int min = t_col % 100;
            t_col = to_min + min;
        }
    }
    int sc_size = (int)schedules.size();
    for(int i=0;i<sc_size;i++)
    {
        int count=0;
        for(int j=0;j<7;j++)
        {
            if((startday < 7) && (j == 7-startday || j == 6-startday))
                continue;
            if((startday == 7) && (j == 0 || j == 6))
                continue;
            if(timelogs[i][j] <= schedules[i]+10)
                count++;
        }
        if(count==5)
            answer++;
    }
    
    return answer;
}
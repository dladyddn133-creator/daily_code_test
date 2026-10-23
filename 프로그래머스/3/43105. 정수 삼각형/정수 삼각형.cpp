#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    int size_triangle = triangle.size();
    vector<vector<int>> floor_dp(size_triangle);
    
    int index_floor=0;
    for(const auto &x : triangle)
    {
        if(index_floor == 0)
        {
            floor_dp[index_floor++].push_back(x[0]);
        }
        else
        {
            for(int i=0;i<x.size();i++)
            {
                if(i==0)
                {
                    floor_dp[index_floor].push_back(x[i]+floor_dp[index_floor-1][i]);
                }
                else if(i == (x.size()-1))
                {
                    floor_dp[index_floor].push_back(x[i]+floor_dp[index_floor-1][i-1]);
                }
                else
                {
                    int left;
                    int right;
                    left = x[i]+floor_dp[index_floor-1][i-1];
                    right = x[i]+floor_dp[index_floor-1][i];
                    if(left > right)
                    {
                        floor_dp[index_floor].push_back(left);
                    }
                    else
                    {
                        floor_dp[index_floor].push_back(right);
                    }
                }
            }
            index_floor++;
        }
    }
    answer = *max_element(floor_dp[index_floor-1].begin(),floor_dp[index_floor-1].end());
    
    // cout << floor_dp[0][0];
    
    return answer;
}
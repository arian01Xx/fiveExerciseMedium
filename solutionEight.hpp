#ifndef SOLUTION_EIGHT_HPP
#define SOLUTION_EIGHT_HPP

#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <cmath>

using namespace std;

class SolutionEight{
public:
	int maximalNetworkRank(int n, vector<vector<int>>& roads){
		vector<int> degree(n,0);
		vector<vector<bool>> connected(n, vector<bool>(n,false));
		for(auto& x: roads){
			int i=x[0]; 
			int j=x[1];
			degree[i]++;
			degree[j]++;
			connected[i][j]=true;
			connected[j][i]=true;
		}
		int ans=INT_MAX;
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				int i_rank=degree[i];
				int j_rank=degree[j];
				int total=i_rank+j_rank;
				if(connected[i][j]){
					total--;
				}
				ans=max(ans,total);
			}
		}
		return ans;
	}
};

#endif
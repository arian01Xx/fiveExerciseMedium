#ifndef SOLUTION_NINE_HPP
#define SOLUTION_NINE_HPP

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

class SolutionNine{
public:
	long long ans=0; int s;
	int dfs(int i, int prev, vector<vector<int>>& graph, int people=1){
		for(int& x: graph[i]){
			if(x==prev) continue;
			people+=dfs(x,i,graph);
		}
		if(i!=0) ans+=(people+s-1)/s;
		return people;
	}
	long long minimumFuelCost(vector<vector<int>>& roads, int seats){
		vector<vector<int>> graph(roads.size()+1); s=seats;
		for(vector<int>& r: roads){
			graph[r[0]].push_back(r[1]);
			graph[r[1]].push_back(r[0]);
		}
		dfs(0,0,graph);
		return ans;
	}
};

#endif
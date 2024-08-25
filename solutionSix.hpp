#ifndef SOLUTION_SIX_HPP
#define SOLUTION_SIX_HPP

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

class SolutionSix{
public:
	int minCostConnectPoints(vector<vector<int>>& points){
		vector<vector<pair<int,int>>> adj_list(points.size(), vector<pair<int,int>>());
		for(int i=0; i<points.size(); i++){
			vector<int> curr=points[i];
			for(int j=0; j<points.size(); j++){
				if(j==i) continue;
				adj_list[i].push_back({abs(curr[0]-points[j][0])+abs(curr[1]-points[j][1]), j});
			}
		}
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
		vector<int> visited(points.size(),0);
		pq.push({0,0});
		int ans=0;
		while(!pq.empty()){
			int curr=pq.top().second;
			int wt=pq.top().first;
			pq.pop();
			if(visited[curr]) continue;
			visited[curr]=true;
			ans+=wt;
			for(pair<int,int> neighbor: adj_list[curr]){
				if(visited[neighbor.second]) continue;
				pq.push(neighbor);
			}
		}
		return ans;
	}
};

#endif
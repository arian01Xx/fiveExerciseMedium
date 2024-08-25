#ifndef SOLUTION_TEN_HPP
#define SOLUTION_TEN_HPP

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

class SolutionTen{
public:
	vector<int> eventualSafeNodes(vector<vector<int>>& graph){
		int n=graph.size();
		vector<int> adj[n];
		vector<int> topo;
		queue<int> q;
		vector<int> inDegree(n,0);
		for(int i=0; i<n; i++){
			for(int j=0; j<graph[i].size(); j++){
				adj[graph[i][j]].push_back(i);
			}
		}
		for(int i=0; i<n; i++){
			for(auto it: adj[i]){
				inDegree[i]++;
			}
		}
		for(int i=0; i<n; i++){
			if(inDegree[i]==0) q.push(i);
		}
		while(!q.empty()){
			int node=q.front();
			q.pop();
			topo.push_back(node);
			for(auto it: adj[node]){
				inDegree[it]--;
				if(inDegree[it]==0) q.push(it);
			}
		}
		sort(topo.begin(), topo.end());
		return topo;
	}
};

#endif
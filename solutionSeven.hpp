#ifndef SOLUTION_SEVEN_HPP
#define SOLUTION_SEVEN_HPP

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

class SolutionSeven{
public:
	void DFS(int node, unordered_map<int,vector<int>> adj, unordered_map<int,bool> visited,
	         int edgesCount, int verticesCount){
		visited[node]=true;
		verticesCount++;
		for(int adjNode: adj[node]){
			edgesCount++;
			if(!visited[adjNode]){
				DFS(adjNode,adj,visited,edgesCount,verticesCount);
			}
		}
	}
	int countCompleteComponents(int n, vector<vector<int>>& edges){
		unordered_map<int,vector<int>> adj;
		unordered_map<int,bool> visited;
		for(int i=0; i<edges.size(); i++){
			adj[edges[i][0]].push_back(edges[i][1]);
			adj[edges[i][1]].push_back(edges[i][0]);
		}
		int ans=0;
		for(int i=0; i<n; i++){
			int edgesCount=0;
			int verticesCount=0;
			if(!visited[i]){
				DFS(i,adj,visited,edgesCount,verticesCount);
				if(verticesCount*(verticesCount-1)==edgesCount) ans++;
			}
		}
		return ans;
	}
};

#endif
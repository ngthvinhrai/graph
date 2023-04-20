#include<bits/stdc++.h>
#include"graph.cpp"
using namespace std;

int main(){
//	int n,m; cin >>n>>m;
//	list<pair<int,int>> graph[n+1];
//	for (int i=0; i<m;i++){
//		int x, y, w; cin>>x>>y>>w;
//		graph[x].push_back({y,w});
//		graph[y].push_back({x,w});
//	}
//	Graph<int> dothi(n,m,graph);
	Graph<int> dothi;
	dothi.read_fromFile("file.txt");
	dothi.write_toFile("dothi.txt");
	dothi.printList();
	dothi.ConComp();
	dothi.graphSearching();
	dothi.dijktra(1,2);
}

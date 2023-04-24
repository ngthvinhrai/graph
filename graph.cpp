#include<bits/stdc++.h>
#include<iostream>
#include<conio.h>
using namespace std;
bool visited_comp[9];

class Graph{
	unsigned int v,e;
	list<pair<int,int>> *vertex;
	bool cc;
	public:
		Graph(){
			v=e=0;
			vertex = new list<pair<int,int>>[v+1];
			cc = 0;
		}
		Graph(unsigned int dinh, unsigned int canh, list<pair<int,int>> *ke){
			v = dinh;
			e = canh;
			vertex = ke;
		}
		unsigned int getVertex(){
			return v;
		}
		unsigned int getEdge(){
			return e;
		}
		void read_fromFile(string file_name){
			ifstream file;
			file.open(file_name);
			file >> v >> e;
			vertex = new list<pair<int,int>>[v+1];
			for (int i=1;i<=e;i++){
				int x,y;
				int w;
				file >> x >>y >> w;
				vertex[x].push_back({y,w});
				vertex[y].push_back({x,w});
			}
			file.close();
		}
		void write_toFile(string file_name){
			ofstream file(file_name);
			file<<v<<" "<<e<<endl;
			for (int i=1;i<=v;i++){
				for (pair<int,int> x:vertex[i])
					if (i<x.first)	file<<i<<" "<<x.first<<" "<<x.second<<endl;
//				cout<<endl;
			}
			file.close();
		}
		void DFS_comp(int i, bool visited_comp[]){
			visited_comp[i] = true;
			cout<<i<<" ";
			for(pair<int,int> x:vertex[i]){
				if(!visited_comp[x.first])
					DFS_comp(x.first, visited_comp);
			}
		}
		void ConComp(){
			int ans = 0;
			bool *visited_comp = new bool[v+1];
			for(int i=1;i<=v;i++)
				visited_comp[i] = false;
			cout<<"Cac thanh phan lien thong: "<<endl;
			for (int i=1;i<=v;i++){
				if(!visited_comp[i]){
					ans++;
					DFS_comp(i, visited_comp);
					cout<<endl;
				}		
			}
			if (ans==1) cc=1;
			else cc=0;
			delete[] visited_comp;
		}
		void DFS(int i, bool visited[]){
			if (cc==1){
				cout<<"DFS: ";
				DFS_comp(i,visited);
				cout<<endl;
			}
			else cout<<"Khong duyet vi khong lien thong!!";
		}
		void BFS(int i, bool visited[]){
			cout<<"BFS: ";
			queue<int> q;
			q.push(i);
			visited[i] = true;
			while(!q.empty()){
				int v = q.front();
				q.pop();
				cout<<v<<" ";
				for (pair<int,int> x:vertex[v]){
					if(!visited[x.first]){
						q.push(x.first);
						visited[x.first] = true;
					}
				}
			}
			cout<<endl;
		}
		void graphSearching(){
			cout<<"1. DFS"<<endl;
			cout<<"2. BFS"<<endl;
			int n;
			cout<<"Chon phuong thuc duyet cay: "; cin>>n;
			switch(n){
				case 1: DFS(1, visited_comp);break;
				case 2: BFS(1, visited_comp);break;
			}
		}
		void dijktra(int start, int finish){
			int distance[v+1]; int pre[v+1];
			for(int i=1;i<=v;i++)
				distance[i] = 1e+9;
			distance[start] = 0;
			pre[start] = start;
			queue<pair<int,int>> Q;
			Q.push({start,0});
			while(!Q.empty()){
				pair<int,int> top;
				top = Q.front();
				Q.pop();
				int u = top.first;
				int kc = top.second;
				if(kc>distance[u]) continue;
				for (pair<int,int> next:vertex[u]){
					int v = next.first;
					int w = next.second;
					if(distance[v]>distance[u]+w){
						distance[v] = distance[u]+w;
						Q.push({v,distance[v]});
						pre[v] = u;
					} 
				}
			}
			cout<<"Khoang cach ngan nhat tu "<<start<<"->"<<finish<<": "<<distance[finish]<<endl;
			vector<int> path;
			cout<<"Duong di ngan nhat tu "<<start<<"->"<<finish<<": ";
			while(1){
				path.push_back(finish);
				if(finish == start) break;
				finish = pre[finish];
			}
			for(vector<int>::reverse_iterator it=path.rbegin(); it!=path.rend(); it++)
				cout<<*it<<" ";
		}
		void printList(){
			for(int i=1;i<=v;i++){
				for(pair<int,int> x:vertex[i]){
					if(i<x.first)
						cout<<i<<"-"<<x.first<<": "<<x.second<<endl;
				}
			}
		}
};


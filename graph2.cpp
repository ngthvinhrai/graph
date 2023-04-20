#include<bits/stdc++.h>
using namespace std;

template<class T>
class Node{
	T elem;
	T weight;
	Node *next;
	public:
		Node(){
			elem = 0;
			next = NULL;
		}
		Node(T elem, Node<T> *N=NULL){
			this->elem = elem;
			next = N;
		}
		T getElem(){
			return elem;
		}
		void setElem(T e){
			elem = e;
		}
		Node<T> *&getNext(){
			return next;
		}
};

int main(){
	list<Node<int>> *vertex = new list<Node<int>>[2];
	vertex[0].push_back(2);
	vertex[0].push_back(23);
	vertex[0].push_back(24);
	for (auto x:vertex[0])
		cout<<x.getNext()<<endl;

}

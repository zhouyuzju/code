#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

struct node{
	int key;
	int address;
	int next;
	node(int key,int addr,int next): key(key),address(addr),next(next){}
};

bool cmp(node* a, node* b){
	return a->key < b->key;
}

int main(){
	int N,head;
	scanf("%d%d",&N,&head);
	vector<node*> list;
	map<int,node*> nodes;
	for(int i = 0;i < N;i++){
		int addr,key,next;
		scanf("%d%d%d",&addr,&key,&next);
		node* anode = new node(key,addr,next);
		nodes[addr] = anode;
	}
	int tmp = head;
	while(nodes.find(tmp) != nodes.end() && tmp != -1){
		list.push_back(nodes[tmp]);
		tmp = nodes[tmp]->next;
	}
	sort(list.begin(),list.end(),cmp);
	if(list.size() > 0)
		printf("%d %05d\n",list.size(),list[0]->address);
	else
		printf("%d %d\n",list.size(),-1);

	for(int i = 0;i < list.size();i++)
		if(i == list.size() - 1)
			printf("%05d %d %d\n",list[i]->address,list[i]->key,-1);
		else
			printf("%05d %d %05d\n",list[i]->address,list[i]->key,list[i + 1]->address);

	return 0;
}

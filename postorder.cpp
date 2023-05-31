#include"opce_stablo.h"
#include"red_polje.h"
#include"stog_pok.h"
#include<iostream>
#include<cstdlib>
using namespace std;
//inorder, postoreder


template <typename nodetype>
void DFS_Postorder(Tree<nodetype> &t, typename Tree<nodetype>::node n){
	Stack<typename Tree<nodetype>::node> s;
	typename Tree<nodetype>::node p = n;
	while(p != t.lambda){
		s.Push(p);
		p = t.FirstChild(p);
	}
	while(!s.IsEmpty()){
		p = s.Top();
		s.Pop();
		std::cout << t.Label(p) << " ";
		p = t.NextSibling(p);
		while(p != t.lambda){
			s.Push(p);
			p = t.FirstChild(p);
		}
	}
}

int main(){
	Tree<int> t(4);
	t.CreateChild(t.Root(), 8);
  	t.CreateChild(t.Root(), 6);
  	t.CreateChild(t.Root(), 7);
  	t.CreateChild(t.FirstChild(t.Root()), 8);
  	t.CreateChild(t.FirstChild(t.Root()), 2);
  	t.CreateChild(t.FirstChild(t.FirstChild(t.Root())), 1);
  	t.CreateChild(t.FirstChild(t.FirstChild(t.Root())), 3);
  	t.CreateChild(t.NextSibling(t.FirstChild(t.Root())), 5);
  	t.CreateChild(t.FirstChild(t.NextSibling(t.FirstChild(t.Root()))), 2);
  	t.CreateChild(t.FirstChild(t.NextSibling(t.FirstChild(t.Root()))), 9);
  	
  	DFS_Postorder(t, t.Root());
  	
	return 0;
}

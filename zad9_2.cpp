#include"opce_stablo.h"
#include"red_polje.h"
#include"stog_pok.h"
#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;


    

int main(){
	Tree<int> T(4);
	Tree<int>::node root = T.Root();

	T.CreateChild(root, 7);
	Tree<int>::node child7 = T.FirstChild(root);
	T.CreateChild(root, 6);
	Tree<int>::node child6 = T.FirstChild(root);
	T.CreateChild(root, 8);
	Tree<int>::node child8 = T.FirstChild(root);
	
	T.CreateChild(child7, 2);
	Tree<int>::node child7_2 = T.FirstChild(child7);

	T.CreateChild(child7, 8);
	Tree<int>::node child7_8 = T.FirstChild(child7);

	T.CreateChild(child8,5);
	Tree<int>::node child8_5 = T.FirstChild(child8);
	
	T.CreateChild(child7_2, 3);
	Tree<int>::node child7_2_3 = T.FirstChild(child7_2);
	T.CreateChild(child7_8, 1);
	Tree<int>::node child7_8_1 = T.FirstChild(child7_8);
	T.CreateChild(child8_5, 9);
	Tree<int>::node child8_5_9 = T.FirstChild(child8_5);
	T.CreateChild(child8_5,2);
	Tree<int>::node child8_5_2 = T.FirstChild(child8_5);
	
std::queue<Tree<int>::node> queue;
	queue.push(T.Root());
	
	while(!queue.empty()){
		Tree<int>::node curr = queue.front();
		queue.pop();
		
		if (T.FirstChild(curr) != T.lambda && T.NextSibling(T.FirstChild(curr)) == T.lambda)
			std::cout << T.Label(curr) << " ";
		
		if (T.FirstChild(curr) != T.lambda){
			Tree<int>::node next = T.FirstChild(curr);
			while(next != T.lambda){
				queue.push(next);
				next = T.NextSibling(next);
			}
		}
	}
	
    return 0;
}

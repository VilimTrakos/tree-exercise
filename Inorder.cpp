#include"opce_stablo.h"
#include"red_polje.h"
#include"stog_pok.h"
#include<iostream>
#include<cstdlib>
using namespace std;

template <typename nodetype>
void inOrder(Tree<int>::node n, Tree<nodetype> &t){
  if (n != t.lambda){
    inOrder(t.FirstChild(n), t);
    std::cout << t.Label(n) << std::endl;
    inOrder(t.NextSibling(n), t);
  }
}


int main(){

  Tree<int> t(4);
  t.CreateChild(t.Root(), 2);
  t.CreateChild(t.Root(), 6);
  t.CreateChild(t.Root(), 7);
  t.CreateChild(t.FirstChild(t.Root()), 1);
  t.CreateChild(t.FirstChild(t.Root()), 8);
  t.CreateChild(t.FirstChild(t.FirstChild(t.Root())), 3);
  t.CreateChild(t.FirstChild(t.FirstChild(t.Root())), 7);
  t.CreateChild(t.NextSibling(t.FirstChild(t.Root())), 9);
  t.CreateChild(t.FirstChild(t.NextSibling(t.FirstChild(t.Root()))), 2);
  t.CreateChild(t.FirstChild(t.NextSibling(t.FirstChild(t.Root()))), 6);
  inOrder(t.Root(), t);
  

	return 0;
}

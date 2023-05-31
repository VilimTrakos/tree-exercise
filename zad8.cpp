#include"opce_stablo.h"
#include"red_polje.h"
#include<iostream>
#include<queue>
#include<cstdlib>
using namespace std;

typedef Tree<int>::node node;
void reverseLevelorder(node root, Tree<int>& t){
    if(!t.IsEmpty()){
        int maxLevel = 0;
        queue<pair<node, int> > q;
        q.push({root, 0});
        while(!q.empty()){
            pair<node, int> p = q.front();
            q.pop();
            if(p.second > maxLevel)
                maxLevel = p.second;
            node tmp = t.FirstChild(p.first);
            while(tmp != t.lambda){
                q.push({tmp, p.second+1});
                tmp = t.NextSibling(tmp);
            }
        }
        while(maxLevel >= 0){
            queue<node> qLevel;
            q.push({root, 0});
            while(!q.empty()){
                pair<node, int> p = q.front();
                q.pop();
                if(p.second == maxLevel)
                    qLevel.push(p.first);
                node tmp = t.FirstChild(p.first);
                while(tmp != t.lambda){
                    q.push({tmp, p.second+1});
                    tmp = t.NextSibling(tmp);
                }
            }
            while(!qLevel.empty()){
                cout << t.Label(qLevel.front()) << " ";
                qLevel.pop();
            }
            maxLevel--;
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
  reverseLevelorder(t.Root(), t);
  

	return 0;
}

#include"opce_stablo.h"
#include"red_polje.h"
#include<iostream>
#include<cstdlib>
#include <string>
using namespace std;


void Insert(Tree<char>& T, string s){
    Tree<char>::node n = T.Root();
    for(int i = 0; i < s.size(); i++){
        Tree<char>::node child = T.FirstChild(n);
        while(child != T.lambda && T.Label(child) != s[i])
            child = T.NextSibling(child);
        if(child == T.lambda){
            T.CreateChild(n, s[i]);
            n = T.FirstChild(n);
        }
        else
            n = child;
    }
}

bool IsElement(Tree<char>& T, string s){
    Tree<char>::node n = T.Root();
    for(int i = 0; i < s.size(); i++){
        Tree<char>::node child = T.FirstChild(n);
        while(child != T.lambda && T.Label(child) != s[i])
            child = T.NextSibling(child);
        if(child == T.lambda)
            return false;
        else
            n = child;
    }
    return true;
}

int main(){
    Tree<char> T(' ');

    Insert(T, "apple");
    Insert(T, "app");
    Insert(T, "base");
    Insert(T, "ball");
    
    if(IsElement(T, "apple"))
        cout << "apple is in the tree." << endl;
    else
        cout << "apple is not in the tree." << endl;
    
    if(IsElement(T, "basement"))
        cout << "basement is in the tree." << endl;
    else
        cout << "basement is not in the tree." << endl;
    
    return 0;
}


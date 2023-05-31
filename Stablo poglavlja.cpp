#include"opce_stablo.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    Tree<string> tree;
    vector<string> str;
    ifstream file;
    file.open("text.txt");
    string line;
    while (getline(file, line))
    {
        str.push_back(line);
    }
    for (int i = 0; i < str.size(); i++)
    {
        int tabs = 0;
        for (int j = 0; j < str[i].size(); j++)
        {
            if (str[i][j] == '\t')
                tabs++;
        }
        if (tabs == 0)
        {
            tree.CreateRoot(str[i]);
        }
        else
        {
            vector<string> subStr;
            string temp;
            for (int j = 0; j < str[i].size(); j++)
            {
                if (str[i][j] == '\t')
                {
                    subStr.push_back(temp);
                    temp = "";
                }
                else
                {
                    temp += str[i][j];
                }
            }
            if (subStr.size() == tabs)
            {
                subStr.push_back(temp);
            }
            Tree<string>::node currentNode = tree.Root();
            for (int j = 0; j < tabs; j++)
            {
                bool found = false;
                for (Tree<string>::node node = tree.FirstChild(currentNode); node != tree.lambda; node = tree.NextSibling(node))
                {
                    if (tree.Label(node) == subStr[j])
                    {
                        found = true;
                        currentNode = node;
                        break;
                    }
                }
                if (!found)
                {
                    tree.CreateChild(currentNode, subStr[j]);
                    currentNode = tree.FirstChild(currentNode);
                }
            }
            tree.CreateChild(currentNode, subStr[tabs]);
        }
    }
    file.close();
    return 0;
}

#include"opce_stablo.h"
#include"red_polje.h"
#include"stog_pok.h"
#include<iostream>
#include<cstdlib>
#include <fstream>
#include <string>


using namespace std;

int main() 
{
    Tree<string> tree;

    ifstream inFile;
    inFile.open("text.txt");

    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    string label;
    Tree<string>::node current;

    // Read the headings from the first column.
    while (inFile >> label) {
        tree.CreateRoot(label);
        current = tree.Root();
        break;
    }

    // Read the chapters, which are moved one tab to the right.
    while (inFile >> label) {
        tree.CreateChild(current, label);
        current = tree.FirstChild(current);

        // Read the sub-chapters, which are moved two tabs to the right.
        while (inFile >> label) {
            if (label.at(0) == '\t') {
                tree.CreateChild(current, label.substr(1, label.length() - 1));
                current = tree.FirstChild(current);
            }
            else {
                break;
            }
        }

        // Move up until we find the parent of the chapter.
        while (tree.Parent(current) != tree.lambda) {
            current = tree.Parent(current);
        }
    }

    inFile.close();

    cout << "General Tree of Chapters and Sub-Chapters" << endl << endl;

    // Print the tree.
    Tree<string>::node n;
    n = tree.Root();
    while (n != tree.lambda) {
        cout << tree.Label(n) << endl;

        Tree<string>::node c = tree.FirstChild(n);
        while (c != tree.lambda) {
            cout << "\t" << tree.Label(c) << endl;
            c = tree.NextSibling(c);
        }

        n = tree.NextSibling(n);
    }

    return 0;
}


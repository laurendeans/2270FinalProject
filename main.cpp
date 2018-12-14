
#include <iostream>
#include <fstream>
#include <string>

#include <stdlib.h>
#include <stdio.h>



#include "AutoComplete.h"

using namespace std;



int main() {
    struct TrieNode *root = init_Node();
    string prefix;
    readinfile(root, "wordlist.txt");
    cout << "\n****** Welcome! ******\nI have already added the dictionary to the Trie Structure." << endl;
    cout << "\nEnter a prefix (or word): " << endl;
    cin >> prefix;
    cout << "\nThanks! \nI will now perform autocomplete operations using the prefix:  " << "'" << prefix << "'\n" << endl;
 

}
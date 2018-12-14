
//AutoComplete.cpp
//Lauren Deans CSCI 2270 Final Project


#include <iostream>
#include <fstream>
#include <string>

#include "AutoComplete.h"


using namespace std;

#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) (((int)(c)) - (int)'a')
#define INDEX_TO_CHAR(i) (char(i+97))
#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])



//initializes a new node pointer that sets children pointers to NULL for ALPHABET_SIZE, sets isEndWord to false
struct TrieNode *init_Node(){
    struct TrieNode *disNode = new TrieNode;
    disNode->isEndWord = false;
    for(int i=0; i < ALPHABET_SIZE; i++){
        disNode->children[i] = NULL;
    }
return disNode;
}

//inserts a word into a TRIE structure
//marks isEndOfWord as true at the last node
void Insert_Trie(struct TrieNode *root, string word){ 
    struct TrieNode *disNode = root; 
    for(int i=0; i < word.length(); i++){ 
        int index = CHAR_TO_INDEX(word[i]); 
        if(!disNode->children[index]) 
            disNode->children[index] = init_Node();
        disNode = disNode->children[index];
    } 
disNode->isEndWord = true; 
}

//search helper to inidicate if a word exists in the trie, returns true if in trie, false otherwise
bool search_helper(struct TrieNode *root, string word){ 
    struct TrieNode *disNode = root; 
    for(int i=0; i < word.length(); i++){ 
        int index = CHAR_TO_INDEX(word[i]); 
        if(!disNode->children[index]) 
            return false;
        disNode = disNode->children[index]; 
    } 
return (disNode != NULL && disNode->isEndWord); 
}

//returns true if at the last node in trie
bool isLeafNode(struct TrieNode *root){ 
    for(int i=0; i<ALPHABET_SIZE; i++) 
        if (root->children[i]) 
            return false; 
    return true; 
}

//displays content of trie on new lines each
void display(struct TrieNode *root, char str[], int linenum){  
    if (isLeafNode(root)){ 
        str[linenum] = '\0'; 
        cout << str << endl; 
    } 
    for(int i=0; i<ALPHABET_SIZE; i++){ 
        if (root->children[i]){ 
            str[linenum] = i + 'a'; 
            display(root->children[i], str, linenum + 1);

        }   
    } 
}

//a bool function that reads in a file (wordlist.txt this project) and inserts it into a trie
bool readinfile(struct TrieNode *root,string fileName){
    string line;
    ifstream myfile (fileName);
    if(myfile.is_open()){
        while(getline(myfile,line)){
            Insert_Trie(root,line);
        }
        myfile.close();
        return true;
    }
    else{
        cout << "FILE DID NOT LOAD SUCCESSFULLY." << "\n";
        return false;
    }
}



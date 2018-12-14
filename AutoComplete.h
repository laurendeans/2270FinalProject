#ifndef AutoComplete_h
#define AutoComplete_h

#include <string>

using namespace std;

#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) (((int)(c)) - (int)'a')
#define INDEX_TO_CHAR(i) (char(i+97))
#define ARRAY_SIZE(a) sizeof(a) / sizeof(a[0])


//structure definition
struct TrieNode{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndWord;
};

//initializes new trie node, sets pointers to ALPHABET_SIZE number of children
struct TrieNode *init_Node();
//adds a word to the trie structure
void Insert_Trie(struct TrieNode *root, string word);
//bool function to inidicate whether a search object is in trie, returns true if found, false otherwise
bool search_helper(struct TrieNode *root, string word);
    //
bool isLeafNode(struct TrieNode *root);
//
void display(struct TrieNode *root, char str[], int level);
//
bool readinfile(struct TrieNode *root,string fileName);










#endif




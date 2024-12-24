#include <bits/stdc++.h>
using namespace std;
class TrieNode{
    bool isEnd;
    unordered_map<char, TrieNode*> children;
    public:
    bool childExist(char c)
    {
        if(this->children.find(c) != children.end())
        {
            return true;
        }
        return false;
    }
    int childCount()
    {
        int cnt = 0;
        for(auto it : children)
        {
            cnt++;
        }
        return cnt;
    }
    void createNode(char c)
    {
        if(this->children.find(c) != children.end())
        {
            cout << "Error child already exist\n";
            return;
        }
        TrieNode * tmp = new TrieNode;
        children[c] = tmp;
    }
    void display(string ds, TrieNode * tmp)
    {
        if(tmp->isEnd)
        {
            cout << ds << "\n";
        }
        for(auto it : tmp->children)
        {
            ds.push_back(it.first);
            display(ds,it.second);
            ds.pop_back();
        }
        return;
    }
    void display1(string ds, TrieNode * tmp)
    {
        if(tmp->isEnd && tmp->childCount() == 0)
        {
            cout << ds << "\n";
        }
        for(auto it : tmp->children)
        {
            ds.push_back(it.first);
            display1(ds,it.second);
            ds.pop_back();
        }
        return;
    }
    void makeItEnd()
    {
        this->isEnd = true;
    }
    TrieNode * goToChild(char c){
        if(this->children.find(c) == children.end())
        {
            cout << "Error child does not exist\n";
            return NULL;
        }
        return children[c];
    }
    TrieNode() :isEnd(false)
    {
    }
};
class Trie{
    TrieNode * root;
    public:
    Trie() : root(NULL) {}
    void insert(string s)
    {
        if(root == NULL)
        {
            root = new TrieNode;
        }
        TrieNode * node = root;
        for(auto it : s)
        {
            if(!node->childExist(it))
            {
               node->createNode(it);
            }
            node = node->goToChild(it); 
        }
        node->makeItEnd();
    }
    void wordStartingFromRoot()
    {
        string s;
        root->display(s,root);
    }
    void groupOfNonPrefixWords()
    {
        string s;
        root->display1(s,root);
    }
    bool search(string s)
    {
        if(root == NULL) {
            cout << "No Words in Trie\n";
            return false;
        }
        TrieNode * node = root;
        for(auto it : s)
        {
            if(!node->childExist(it)){
                cout << "Word not found\n";
                return false;
            }
            else{
                node = node->goToChild(it);
            }
        }
        return true;
    }
};
int main()
{
    Trie sumit;
    sumit.insert("ab");
    sumit.insert("ba");
    sumit.insert("bb");
    sumit.insert("aa");
    sumit.insert("aaa");
    sumit.insert("bbb");
    sumit.insert("baba");
    sumit.insert("abba");
    sumit.groupOfNonPrefixWords();
    return 0;
}
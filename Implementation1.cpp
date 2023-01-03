/*
LRU Cache Project -> Doubly Linked List and Hashmap Implementation

Insertion, Deletion,
Time Complexity: O(1) Time most Operations

Aditya Jamwal

*/

#include<list>
#include<string>
#include<unordered_map>
#include<iostream>
using namespace std;

/// STL Container List and STL Container Map

class Node{
public:
    string key;
    int val;
    Node(string key, int val){
        this->key=key;
        this->val=val;
    }
};

class LRUCache{
public:
    int maxSize;
    list<Node> l;
    unordered_map<string, list<Node>::iterator > mp;        /// Defining String with Address of STL container object
    LRUCache(int maxSize){
        this->maxSize=maxSize > 1 ? maxSize : 1;
    }

    void insertKeyValue(string key, int val){
        if(mp.count(key)!=0){
            auto it=mp[key];
            it->val=val;
        }else{
            if(l.size()==maxSize){
                Node last=l.back();
                mp.erase(last.key);
                l.pop_back();
            }
            Node n(key, val);
            l.push_front(n);
            mp[key]=l.begin();
        }
    }

    int* getValue(string key){
        if(mp.count(key)!=0){
            auto it=mp[key];
            int val=it->val;
            l.push_front(*it);
            l.erase(it);
            mp[key]=l.begin();
        return &l.begin()->val;
        }
    return NULL;
    }
    string mostRecentKey(){
        return l.front().key;
    }
};
int main(){
    LRUCache lru(3);
    lru.insertKeyValue("mango", 10);
    lru.insertKeyValue("apple", 20);
    lru.insertKeyValue("banana", 30);
    cout<<lru.mostRecentKey()<<endl;
    lru.insertKeyValue("mango", 40);
    cout<<lru.mostRecentKey()<<endl;

    int *orders=lru.getValue("mango");
    if(orders!=NULL){
        cout<<"Orders of Mango "<<*orders<<endl;
    }
    lru.insertKeyValue("guava", 50);
    if(lru.getValue("apple")==NULL){
        cout<<"Apple doesn't exist";
    }
    if(lru.getValue("mango")==NULL){
        cout<<"Mango doesn't exist";
    }
    if(lru.getValue("guava")==NULL){
        cout<<"Guava doesn't exist";
    }
    if(lru.getValue("banana")==NULL){
        cout<<"Banana doesn't exist";
    }
}


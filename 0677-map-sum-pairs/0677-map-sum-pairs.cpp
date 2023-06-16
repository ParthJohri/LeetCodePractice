#include<bits/stdc++.h>
using namespace std;
struct Node {
	Node *links[26];
    int value=0;
	//checks if the reference trie is present or not
	bool containsKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}
	//creating reference trie
	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
	}
	//to get the next node for traversal
	Node *get(char ch) {
		return links[ch - 'a'];
	}
};
class MapSum {
public:
    Node* root;
    unordered_map<string,int> mp;
    MapSum() {
        root=new Node();
    }
    
    void insert(string key, int val) {
        Node *node = root;
        int temp=val-mp[key];
		for (int i = 0; i < key.size(); i++) {
			if (!node->containsKey(key[i])) {
				node->put(key[i], new Node());
			}
			//moves to reference trie
			node = node->get(key[i]);
            node ->value+=temp;
		}
        mp[key]=val;
    }
    
    int sum(string prefix) {
        Node* node = root;
		for (int i = 0; i < prefix.size(); i++) {
			if (!node->containsKey(prefix[i])) {
				return 0;
			}
			node = node->get(prefix[i]);
		}
		return node->value;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
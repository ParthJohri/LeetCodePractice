
struct Node {
	Node *links[26];
	bool flag = false;
	int cntEndWith = 0;
  	int cntPrefix = 0;
    int count=0;
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
	//setting flag to true at the end of the word
	void setEnd() {
		flag = true;
	}
	//checking if the word is completed or not
	bool isEnd() {
		return flag;
	}
	void increaseEnd() {
    cntEndWith++;
  	}
  	void increasePrefix() {
    cntPrefix++;
  	}
  	void deleteEnd() {
    cntEndWith--;
  	}
  	void reducePrefix() {
    cntPrefix--;
  	}
  	int getEnd() {
    return cntEndWith;
  	}
  	int getPrefix() {
    return cntPrefix;
  	}
};
class Trie {
private:
	Node* root;
public:
	Trie() {
		//creating new obejct
		root = new Node();
	}

	void insert(string word) {
		//initializing dummy node pointing to root initially
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
            
			if (!node->containsKey(word[i])) {
				node->put(word[i], new Node());
			}
            node->links[word[i]-'a']->count++;
			//moves to reference trie
			node = node->get(word[i]);
			node -> increasePrefix();
		}
		node->setEnd();
		node -> increaseEnd();
	}

	bool search(string word) {
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containsKey(word[i])) {
				return false;
			}
			node = node->get(word[i]);
		}
		return node->isEnd();
	}

	bool startsWith(string prefix) {
		Node* node = root;
		for (int i = 0; i < prefix.size(); i++) {
			if (!node->containsKey(prefix[i])) {
				return false;
			}
			node = node->get(prefix[i]);
		}
		return true;
	}

	int countWordsEqualTo(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->getEnd();
    }

    int countPrefix(string &word){
        Node* node=root;
        int ans=0;
        for(auto i:word){
            if(node->containsKey(i)){
                ans+=node->links[i-'a']->count;
            }
            node=node->get(i);
        }
        return ans;
    }

  int countWordsStartingWith(string & word) {
    Node * node = root;
    for (int i = 0; i < word.length(); i++) {
      if (node -> containsKey(word[i])) {
        node = node -> get(word[i]);
      } else {
        return 0;
      }
    }
    return node -> getPrefix();
  }

  void erase(string & word) {
    Node * node = root;
    for (int i = 0; i < word.length(); i++) {
      if (node -> containsKey(word[i])) {
        node = node -> get(word[i]);
        node -> reducePrefix();
      } else {
        return;
      }
    }
    node -> deleteEnd();
  }
};


class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie t;
        vector<int> ans;
        for(auto i:words) {
            t.insert(i);
        }
        for(auto i:words){
            int count=t.countPrefix(i);
            ans.push_back(count);
        }
        return ans;
    }
};
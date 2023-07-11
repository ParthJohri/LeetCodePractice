
#define MAXN 100001
#define INF 1e18+1

struct Node {
	Node *links[26];
	bool flag = false;
	int cntEndWith = 0;
  	int cntPrefix = 0;
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

    string prefixRoot(string&word){
        Node* node = root;
        string ans = "";
        for(int i=0;i<word.length();i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                ans += word[i];
                if((node->getEnd())) return ans;
            }
            else break;
        }
        if(!(node->getEnd())) ans = word;
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
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string> words;
        Trie t;
        string ans="";
        for(auto i:dictionary){
            t.insert(i);
        }
        string word="";
        for(auto i:sentence){
            if(i!=' '){
                word+=i;
            }
            else{
                words.push_back(word);
                word="";
            }
        }
        words.push_back(word);
        for(auto i:words){
            string temp=t.prefixRoot(i);
            ans+=temp+" ";
        }
        return ans.substr(0,ans.length()-1);
    }
};
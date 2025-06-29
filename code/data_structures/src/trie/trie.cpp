// trie.cpp
// Trie implementation in C++

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        fill(begin(children), end(children), nullptr);
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int i = ch - 'a';
            if (!node->children[i])
                node->children[i] = new TrieNode();
            node = node->children[i];
        }
        node->isEnd = true;
    }

    bool search(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int i = ch - 'a';
            if (!node->children[i])
                return false;
            node = node->children[i];
        }
        return node->isEnd;
    }

    bool startsWith(const string& prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            int i = ch - 'a';
            if (!node->children[i])
                return false;
            node = node->children[i];
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << "Search 'apple': " << trie.search("apple") << endl;     // true
    cout << "Search 'app': " << trie.search("app") << endl;         // false
    cout << "StartsWith 'app': " << trie.startsWith("app") << endl; // true
    trie.insert("app");
    cout << "Search 'app': " << trie.search("app") << endl;         // true
    return 0;
}
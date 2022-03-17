#include "head.h"

class Trie {
private:
    vector<Trie*> children;
    bool isEnd;

    Trie* searchPrefix(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }

public:
    Trie() : children(26), isEnd(false) {}

    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (node->children[ch] == nullptr || !node->children[ch]->isEnd) {
                return false;
            }
            node = node->children[ch];
        }
        return true;
    }

    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie tree;
        for (auto word : words) {
            tree.insert(word);
        }
        string res = "";
        for (auto word : words) {
            if (tree.search(word)) {
                if (word.size() > res.size() || (word.size() == res.size() && word < res)) {
                    res = word;
                }
            }
        }
        return res;
    }
};
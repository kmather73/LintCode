/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */
class TrieNode {
public:
    // Initialize your data structure here.
    std::unordered_map<char, TrieNode* > letters;
    TrieNode() {
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *temp = root;
        for(char c : word){
            if ( temp->letters.find( c ) == temp->letters.end() )
                temp->letters[ c ] = new TrieNode;
            temp = temp->letters[ c ];
        }
        temp->letters['$'] = new TrieNode;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *temp = root;
        for(char c: word){
            if ( temp->letters.find( c ) == temp->letters.end() )
                return false;
            temp = temp->letters[ c ];
        }
        
        return temp->letters.find( '$' ) != temp->letters.end();
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *temp = root;
        for(char c: prefix){
            if ( temp->letters.find( c ) == temp->letters.end() )
                return false;
            temp = temp->letters[ c ];
        }
        return true;
    }

private:
    TrieNode* root;
};

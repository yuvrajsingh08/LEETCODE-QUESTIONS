class TrieNode{
  public:
    char value;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char val) {
      this->value = val;
      for(int i=0; i<26; i++) {
        children[i] = NULL;
      }
      this->isTerminal = false;
    }
};
void insertWord(TrieNode* root, string word) {
    if(word.size() == 0) {
        // means terminal
        root->isTerminal = true;
        return;
    }
    char c = word[0];
    if(root->children[c-'a'] == NULL) {
        root->children[c-'a'] = new TrieNode(c);
    } 
    
    return insertWord(root->children[c-'a'], word.substr(1));


}

bool searchWord(TrieNode* root, string word, int i) {
  //base case
  if(i == word.length()){
    return root->isTerminal;
   }
   char val=word[i++];
   int index=val-'a';
   if(root->children[index] != NULL){
      return searchWord(root->children[index],word,i);
    }
    return false;
}

bool  startsWithPrefix(TrieNode* root, string word){
    if(word.length() == 0){
      return true;
    }  
    char val=word[0];
    int index=val-'a';
    if(root->children[index] != NULL){
       return startsWithPrefix(root->children[index],word.substr(1));
    }
    return false;
}


class Trie {
    public:
    TrieNode* root ;
    Trie() {
         root = new TrieNode('-');
    }
    
    void insert(string word) {
         insertWord(root, word);
    }
    
    bool search(string word) {
       return searchWord(root, word,0);
    }
    
    bool startsWith(string prefix) {
        return startsWithPrefix(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
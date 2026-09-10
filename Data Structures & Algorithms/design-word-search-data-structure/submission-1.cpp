
class TrieNode{
    public:
        TrieNode* characters[26] = {}; //array of 26 trie nodes representing the next character sequence
        bool end = false;
        bool isHead = false;       
};

class WordDictionary {

public:
    TrieNode* head = new TrieNode();;
    
    WordDictionary() {
        head->isHead = true;
    }
    
    void addWord(string word) {
        TrieNode* curr = head;
        for(const auto c: word){
            if(curr->characters[c - 'a'] == nullptr){
                curr->characters[c - 'a'] = new TrieNode();
            }
            curr = curr->characters[c-'a'];
        }
        curr->end = true;
    }
    bool search(string word, TrieNode* curr){
        for(int i =0; i < word.size(); i++){
            char c = word[i];
            if(c == '.'){

                string trimmed = word.substr(i + 1);
                for(TrieNode* n : curr->characters){
                    if(n != nullptr){
                        if(search(trimmed, n)){
                            return true;
                        }
                    }
                }
                return false;
            }
            if(curr->characters[c-'a'] == nullptr){
                return false;
            }
            curr = curr->characters[c-'a'];
        }
        return curr->end;
    }
    bool search(string word) {
        TrieNode* curr = head;
        for(int i =0; i < word.size(); i++){
            char c = word[i];
            if(c == '.'){

                string trimmed = word.substr(i + 1);
                for(TrieNode* n : curr->characters){
                    if(n != nullptr){
                        if(search(trimmed, n)){
                            return true;
                        }
                    }
                }
                return false;
            }
            if(curr->characters[c-'a'] == nullptr){
                return false;
            }
            curr = curr->characters[c-'a'];
        }
       
        return curr->end;
    }
};

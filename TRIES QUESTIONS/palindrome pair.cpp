/*Palindrome Pair
Send Feedback
Given 'n' number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word, which itself is a palindrome.
The function should return either true or false. You don't have to print anything.
Input Format :
The first line of the test case contains an integer value denoting 'n'.

The following contains 'n' number of words each separated by a single space.
Output Format :
The first and only line of output contains true if the conditions described in the task are met and false otherwise.
Constraints:
0 <= n <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4
abc def ghi cba
Sample Output 1 :
true
Explanation of Sample Input 1:
"abc" and "cba" forms a palindrome
Sample Input 2 :
2
abc def
Sample Output 2 :
false
Explanation of Sample Input 2:
Neither their exists a pair which forms a palindrome, nor any of the words is a palindrome in itself. Hence, the output is 'false.'
*/
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
            this->count++;
        }
    }
 // bool isPalindromePair(vector<string> words)
    /*..................... Palindrome Pair................... */
bool empty(TrieNode *root){
        for(int i=0;i<26;i++){
            if(root->children[i]!=NULL)
                return false;
        }
        return true;
    }
    bool palin(string word){
        for(int i=0,j=word.length()-1;i<=j;i++,j--){
            if(word[i]!=word[j]){
                return false;
            }
        }
        return true;
    }
    int getindex(TrieNode *root){
        for(int i=0;i<26;i++){
            if(root->children[i]!=NULL){
                return i;
            }
        }
        return -1;
    }
    bool check(TrieNode* root,string str){
        if(root->childCount==0)
        {
            if(palin(str))
                return true;
        return false;
        }
        int childindex=getindex(root);
        TrieNode* child=root->children[childindex];
        char s=childindex+'a';
        str=str+s;
        return check(child,str);
    }
    bool newsearch(TrieNode* root,string word){
        if(word.size() == 0)
        {
            
            return true;
        }
         if(word.size()==1)
         {
             if(root->isTerminal)
             {
                 return true;
             }
         }
        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else
            return false;
        return newsearch(child,word.substr(1));
    }
    bool search(vector<string> arr){
        for(int i=0;i<arr.size();i++){
            string str=arr[i];
            string reverse="";
            for(int j=str.length()-1;j>=0;j--){
                reverse=reverse+str[j];
            }
            if(newsearch(root,reverse)||newsearch(root,reverse.substr(1)))
                return true;
        }
            return false;
    }
	bool isPalindromePair(vector<string> words) {
        if(words.size()==0){
            return false;
        }
        for(int i=0;i<words.size();i++){
            string s=words[i];
            add(s);
        }
        return search(words);
		// Complete this function
		// Return true or false.
	}
};

/*
Code: BST Class
Send Feedback
Implement the BST class which includes following functions -
1. search
Given an element, find if that is present in BST or not. Return true or false.
2. insert -
Given an element, insert that element in the BST at the correct position. If element is equal to the data of the node, insert it in the left subtree.
3. delete -
Given an element, remove that element from the BST. If the element which is to be deleted has both children, replace that with the minimum element from right sub-tree.
4. printTree (recursive) -
Print the BST in ithe following format -
For printing a node with data N, you need to follow the exact format -
N:L:x,R:y
where, N is data of any node present in the binary tree. x and y are the values of left and right child of node N. Print the children only if it is not null.
There is no space in between.
You need to print all nodes in the recursive format in different lines.
*/
/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
	
***********************************************************/

class BST {
    // Define the data members
  BinaryTreeNode<int>* root;

	public:

	BST() {
		root = NULL;
	}

	~BST() {
		delete root;
	}
	/*----------------- Public Functions of BST -----------------*/
    private:
    BinaryTreeNode<int> *remove(int data, BinaryTreeNode<int>* node){
        if(node==NULL){
            return NULL;
        }
        if (node->data < data){
            node->right = remove(data,node->right);
            //return node;  here return node
        }
        else if(node->data > data){
            node->left = remove(data,node->left);
            //return node;  here 
        }
        else{
            if(node->left==NULL && node->right==NULL ){
                delete node;
                return NULL;
            }
            else if(node->left==NULL){
                BinaryTreeNode<int>* temp = node->right;
                node->right=NULL;
                delete node;
                return temp;
            }
            else if(node->right==NULL){
                BinaryTreeNode<int>* temp = node->left;
                node->left=NULL;
                delete node;
                return temp;
            }
            else {
                BinaryTreeNode<int>* min = node->right;
                while (min->left != NULL) {
					min = min->left;
            }
               int rightMin = min->data;
				node->data = rightMin;
				node->right = remove(rightMin, node->right);
				return node; 
        }
    }
    }
    private:
    void print(BinaryTreeNode<int>* root){         //
        if(root==NULL){
            return ;
        }
        cout<<root->data<<":";
        
        if (root->left!= NULL && root->right != NULL){
        	cout << "L:" << root->left->data<< ",R:" << root->right->data;
            
        } 
        else if ( root->left  == NULL && root->right != NULL){
        	cout << "R:" << root->right->data;
        }
        else if (root->left != NULL && root->right == NULL){
			cout << "L:" << root->left->data<<",";
        	
        }
        cout << endl;
		print(root->left);
		print(root->right);
        
        
    }
    public: 
    void remove(int data) { 
        // Implement the remove() function
       root = remove(data,root);
    }
    public:
    void print() { 
        // Implement the print() function
        print(root);
    }
    private:
    BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int>* node){
        if(node==NULL){
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode; 
        }
        if(node->data>=data){        //
           node->left = insert(data,node->left);
        }
        else{
           node->right = insert(data,node->right);
        }
        return node;
    }
    public: 
    void insert(int data) { 
        // Implement the insert() function
        this->root = insert(data,this->root);
    }

   /* bool search(int data) {
		// Implement the search() function 
        }*/
    private:
    bool search(int data, BinaryTreeNode<int>* node){
        if(node==NULL){
            return false;
        }
        if(node->data==data){
            return true;
        }
        else if(node->data<data){
           return search(data,node->right); 
        }
        else{
            return search(data,node->left);
        }
    }
    public:
	bool search(int data) {
		return search(data, root);
	}
};

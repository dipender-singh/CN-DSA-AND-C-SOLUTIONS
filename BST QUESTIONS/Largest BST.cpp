/*
Largest BST
Send Feedback
Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format:
The first and only line of output contains the height of the largest BST.
Constraints:
Time Limit: 1 second
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
2
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
/*
#include<bits/stdc++.h>
class Pair{
    public:
    bool isbst;
    int h;
    int min;
    int max;
};
Pair helper(BinaryTreeNode<int> *root){
    if(root==NULL){
        Pair obj;
        obj.isbst=true;
        obj.h=0;
        obj.min=INT_MAX;
        obj.max=INT_MIN;
        return obj;
    }
    Pair left = helper(root->left);
    Pair right = helper(root->right);
     
    int minimum = min(root->data,min(left.min,right.min));
    int maximum = max(root->data,max(left.max,right.max));
    bool isbstfinal = (root->data > left.max) && (root->data < right.max) && left.isbst && right.isbst;
    
    Pair obj;
    obj.max = maximum;
    obj.min = minimum;
    obj.isbst = isbstfinal;
    if(isbstfinal)
    {
        obj.h= 1+max(left.h,right.h);
    }
    else   obj.h= max(left.h,right.h);
    return obj;
    
}
int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
    return helper(root).h;
    
}*/
#include<climits>
#include<cmath>
class Pair{
    
   public:
  int minimum;
  int maximum;
  bool bst;
   int height;
};

Pair BST(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
       Pair obj;
        obj.minimum =INT_MAX;
        obj.maximum = INT_MIN;
        obj.bst = true;
        obj.height=0;
    return obj;
    }
    
    Pair left= BST(root->left);
    Pair right =BST(root->right);
    
    int minimum=min(root->data,min(left.minimum,right.minimum));
    int maximum=max(root->data,max(left.maximum,right.maximum));
    bool  isBSTfinal=(root->data >left.maximum) && (root->data < right.minimum) && left.bst && right.bst;
   
    Pair obj;
    obj.minimum=minimum;
    obj.maximum=maximum;
    obj.bst=isBSTfinal;
    if(isBSTfinal)
    {
        obj.height= 1+max(left.height,right.height);
    }
    else   obj.height= max(left.height,right.height);
    return obj;
    
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
    return BST(root).height;
    }

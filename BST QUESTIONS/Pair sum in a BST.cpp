/*
Pair sum in a BST
Send Feedback
Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. You can use extra space of the order of O(log n).
Note:
1. Assume BST contains all unique elements.
2. In a pair, print the smaller element first.
Input Format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
The following line of input contains an integer, that denotes the value of S.
Output format:
You have to print each pair in a different line (pair elements separated by space). The order of different pairs, to be printed, does not matter.
Constraints:
Time Limit: 1 second   
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12
Sample Output 1:
2 10
5 7
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
#include<bits/stdc++.h>
int helper(BinaryTreeNode<int> *root,vector<int> &ans){
    if(root==NULL){
        return NULL;
    }
    ans.push_back(root->data);
    helper(root->left,ans);
    helper(root->right,ans);
}
void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    // Write your code here
    vector<int> ans;
    helper(root,ans);
    sort(ans.begin(),ans.end());
    int i=0,j=ans.size()-1;
    while(i<j){
        if(ans[i]+ans[j]==s){
            cout<<ans[i]<<" "<<ans[j];
            i++;
            j--;
        }
        else if(ans[i] + ans[j] > s){
            j--;
        }
        else if(ans[i] + ans[j] < s){
            i++;
        }
        cout<<endl;
    }
}

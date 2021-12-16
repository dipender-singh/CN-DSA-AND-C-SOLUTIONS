/*
ZigZag tree
Send Feedback
Given a binary tree, print the zig zag order. In zigzag order, level 1 is printed from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output Format:
The binary tree is printed level wise, as described in the task. Each level is printed in new line.
Constraints
Time Limit: 1 second
Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
5
10 6
2 3
9
*/

#include<bits/stdc++.h>

void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL){
        return;
    }
    stack<BinaryTreeNode<int>*> s1;
    stack<BinaryTreeNode<int>*> s2;
    s1.push(root);
    while(s1.size()!=0 || s2.size()!=0){
        while(s1.size()!=0){
        BinaryTreeNode<int>* front = s1.top();
        s1.pop();
        cout<<front->data<<" ";
       // if(s1.size()==0){
         //   cout<<endl;
        //}
        if(front->left!=NULL){
            s2.push(front->left);
        }
        if(front->right!=NULL){
            s2.push(front->right);
        }
        }
        cout<<endl;
        while(s2.size()!=0){
           BinaryTreeNode<int>* front = s2.top();
        s2.pop();
        cout<<front->data<<" ";
 //       if(s2.size()==0){
   //         cout<<endl;
     //   }
        if(front->right!=NULL){
            s1.push(front->right);
        }
        if(front->left!=NULL){
            s1.push(front->left);
        }  
        }
        cout<<endl;
}
}

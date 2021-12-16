/*
Node with maximum child sum
Send Feedback
Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space. 
Output format :
The first and only line of output contains the data of the node with maximum sum, as described in the task.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
Sample Output 1 :
1
*/
int sumdadson(TreeNode<int>* root)
{
    int x=0;
    if(root==NULL)
        return x;
    
    for(int i=0;i<root->children.size();i++)
    {
        x=x+root->children[i]->data;
    }
    
    return x+root->data;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL || root->children.size()==0)
        return root;
    
    TreeNode<int>* curr=NULL;
    TreeNode<int>* max=NULL;
    int maxi=0;
    int curri=0;
    for(int i=0;i<root->children.size();i++)
    {
        curr=maxSumNode(root->children[i]);
        if(max==NULL)
        {
            max=curr;
            maxi=sumpapabeta(max);
        }
        else
        {
            int curri=sumpapabeta(curr);
            if(curri>maxi)
            {
                max=curr;
                maxi=curri;
            }
        }
    }
    
    int a=sumpapabeta(root);
    
    if(a>maxi)
    {
        return root;
    }
    else
        return max;
}

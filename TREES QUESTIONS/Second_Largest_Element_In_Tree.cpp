/*
Second Largest Element In Tree
Send Feedback
Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
Output Format :
The first and only line of output contains data of the node with second largest data.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40
*/


template <typename T>
class SecondLargestReturnType {
    public:
    TreeNode<T> *largest;
    TreeNode<T> *secondLargest;
    SecondLargestReturnType(TreeNode<T> *first, TreeNode<T> *second) {
        this->largest = first;
        this->secondLargest = second;
    }
};
SecondLargestReturnType<int> *getSecondLargestNodeHelper(TreeNode<int> *root) {
    // if (root == NULL) {
    // 	return new SecondLargestReturnType<int>(NULL, NULL);
    // }
     SecondLargestReturnType<int> *ans = new SecondLargestReturnType<int>(root, NULL);
    for (int i = 0; i < root->children.size(); i++) {
            SecondLargestReturnType<int> *childAns = getSecondLargestNodeHelper(root->children[i]);
            if (childAns->largest->data > ans->largest->data) {
            if (childAns->secondLargest == NULL) {
                ans->secondLargest = ans->largest;
                ans->largest = childAns->largest;
            } else {
            if (childAns->secondLargest->data > ans->largest->data) {
                ans->secondLargest = childAns->secondLargest;
                ans->largest = childAns->largest;
            } else {
                    ans->secondLargest = ans->largest;
                    ans->largest = childAns->largest;
                }
            }
        } else {
            if (ans->largest->data != childAns->largest->data && (ans->secondLargest == NULL || childAns->largest->data > ans->secondLargest->data)) {
                ans->secondLargest = childAns->largest;
            }
        }
    }
	return ans;
}
TreeNode<int> *getSecondLargestNode(TreeNode<int> *root) {
	return getSecondLargestNodeHelper(root)->secondLargest;
}


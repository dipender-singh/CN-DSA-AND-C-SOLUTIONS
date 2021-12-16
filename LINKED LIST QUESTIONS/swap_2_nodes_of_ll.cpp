/*Swap two Nodes of LL
Send Feedback
You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' Swap the nodes that are present at the 'i-th' and 'j-th' positions.
Note :
Remember, the nodes themselves must be swapped and not the datas.

No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains two integer values 'i,' and 'j,' respectively. A single space will separate them.
 Remember/consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= i < M
0 <= j < M

Time Limit: 1sec
Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3 4
Sample Output 1 :
3 4 5 6 2 1 9 
 Sample Input 2 :
2
10 20 30 40 -1
1 2
70 80 90 25 65 85 90 -1
0 6
 Sample Output 2 :
10 30 20 40 
90 80 90 25 65 85 70 
*/
Node *swapNodes(Node *head, int i, int j)
{
    Node *p1=NULL;
    Node *p2=NULL;
    Node *c1=NULL;
    Node *c2=NULL;
	//Write your code here
 Node *temp = head, *prev = NULL; 
  Node *Node1 = NULL, *Node2 = NULL, *Node1_prev = NULL, *Node2_prev = NULL;
  int pos = 0;
    
    // if i and j are equal
    if(i == j) return head; //No changes
    
    while(temp != NULL) {
        if(pos == i) {
            Node1_prev = prev; 
            Node1 = temp;
        }
        else if(pos == j) {
            Node2_prev = prev; Node2 = temp;
        }
        prev = temp;
        temp = temp -> next; pos++; 
    }
    if(Node1_prev != NULL) {
        Node1_prev -> next = Node2;
    }
    else { 
        head = Node2;
    }
    if(Node2_prev != NULL) { 
        Node2_prev -> next = Node1; 
    }
    else {
        head = Node1;
    }
    Node *temp1 = Node2 -> next;
    Node2 -> next = Node1 -> next; 
    Node1 -> next = temp1;
    return head;
}

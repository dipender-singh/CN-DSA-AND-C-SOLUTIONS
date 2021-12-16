/*Code: Merge Two Sorted LL
Send Feedback
You have been given two sorted(in ascending order) singly linked lists of integers.
Write a function to merge them in such a way that the resulting singly linked list is also sorted(in ascending order) and return the new head to the list.
Note :
Try solving this in O(1) auxiliary space.

No need to print the list, it has already been taken care.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the first sorted singly linked list separated by a single space. 

The second line of the input contains the elements of the second sorted singly linked list separated by a single space. 
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output :
For each test case/query, print the resulting sorted singly linked list, separated by a single space.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t = 10^2
0 <= N <= 10 ^ 4
0 <= M <= 10 ^ 4
Where N and M denote the sizes of the singly linked lists. 

Time Limit: 1sec
Sample Input 1 :
1
2 5 8 12 -1
3 6 9 -1
Sample Output 1 :
2 3 5 6 8 9 12 
Sample Input 2 :
2
2 5 8 12 -1
3 6 9 -1
10 40 60 60 80 -1
10 20 30 40 50 60 90 100 -1
Sample Output 2 :
2 3 5 6 8 9 12 
10 10 20 30 40 40 50 60 60 60 80 90 100
*/
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    if(head1 == NULL && head2 == NULL){
        return head1;
    }
    else if(head1 == NULL){
        return head2;
    }
    else if(head2 == NULL){
        return head1;
    }
    Node *fh=NULL;
    Node *ft=NULL;
    if(head1->data == head2->data){
        fh = head1;
        ft = head1;
        head1=head1->next;
    }
    else{
    if(head1->data<head2->data){
        fh = head1;
        ft = head1;
        head1=head1->next;
    }
    else{
        fh = head2;
        ft = head2;
        head2=head2->next;
    }
    while(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data){
       ft = head1;
       ft = head1;
        head1=head1->next;
    }
    else{
       ft->next = head2;
       ft = head2;
        head2=head2->next;
    }
    }
    if(head1==NULL){
        ft->next=head2;
    }   
    else if(head2==NULL){
        ft->next=head1;
    }
    return fh;
    }
}

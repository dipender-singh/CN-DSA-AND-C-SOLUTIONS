void printReverse(Node *head)
{
    //Write your code here
    if(head==NULL){
        return ;
    }
    printReverse(head->next);
    cout<<head->data<<" ";
}

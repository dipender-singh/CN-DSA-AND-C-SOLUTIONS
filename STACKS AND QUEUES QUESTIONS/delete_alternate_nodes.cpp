void delete_alternate_node_LinkedList(Node *head) {
 if (head == NULL)  
        return;  
    Node *prev = head;  
    Node *node = head->next;  
  
    while (prev != NULL && node != NULL)  
    {  
        prev->next = node->next;  
  
        
        free(node);  
        prev = prev->next;  
        if (prev != NULL)  
            node = prev->next;  
    }  
    
}

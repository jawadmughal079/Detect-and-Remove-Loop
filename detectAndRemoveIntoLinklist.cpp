/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };
Node* floydDetectLoop(Node* head) {

    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast !=NULL) {
        
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast) {
            return slow;
        }
    }

    return NULL;

}

Node* getStartingNode(Node* head) {

    if(head == NULL) 
        return NULL;

    Node* intersection = floydDetectLoop(head);
    
    if(intersection == NULL)
        return NULL;
    
    Node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }  

    return slow;

}

Node *removeLoop(Node *head)
{
    if( head == NULL)
        return NULL;

    Node* startOfLoop = getStartingNode(head);
    
    if(startOfLoop == NULL)
        return head;
    
    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop) {
        temp = temp -> next;
    } 

    temp -> next = NULL;
    return head;
}
*************************************************/
Node *findLoop(Node * head)
{
    Node * slow = head;
    Node * fast = head;
    if(head==NULL)
        return NULL;
    while(fast!=NULL && fast->next !=NULL)
    {
        fast = fast->next->next;
        slow = slow ->next;
        if(slow == fast )
        {
            return fast;
        }
        
    }
    return NULL;
}
Node * begginOfLoop(Node * head)
{
    Node * start = findLoop(head);
    if(start == NULL)
    {
        return NULL;
    }
    Node * temp = head;
    while(temp!=start)
    {
        start= start->next;
        temp = temp->next;
    }
    return temp;
}
Node *removeLoop(Node *head)
{
    // Write your code here.
    if(head==NULL)
        return head;
    
    Node * remove = begginOfLoop(head);
    Node * temp = remove;
    if(remove==NULL)
    {
        return head;
    }
    while(temp->next!= remove )
    {
        temp = temp->next;
    }
    temp -> next= NULL;
    return head;
}

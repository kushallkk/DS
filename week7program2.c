struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast->next!=NULL){
        slow=slow->next;
        if(fast->next->next==NULL)
         break;
        fast=fast->next->next;
    }
    return(slow);
}

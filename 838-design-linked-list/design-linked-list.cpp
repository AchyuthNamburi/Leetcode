class MyLinkedList {
public:
    ListNode * head=NULL;

    MyLinkedList() {
        
    }
    
    int get(int index) {
        int l=0;
        ListNode * temp2=head;
        while(temp2){
            temp2=temp2->next;
            l++;
        }
        if(index>=l) return -1;

        int cnt=0;
        ListNode * temp=head;
        while(temp && cnt<index){
            temp=temp->next;
            cnt++;
        }

        return temp->val;
        
        
    }
    
    void addAtHead(int val) {
        ListNode* newNode=new ListNode(val);
        newNode->next=head;
        head=newNode;
        
    }
    
    void addAtTail(int val) {
        ListNode* newNode=new ListNode(val);
        if(head==NULL){
            head=newNode;
            return;
        }
        
        ListNode* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        
        temp->next=newNode;
        
    }
    
    void addAtIndex(int index, int val) {
        int l=0;
        ListNode * temp2=head;
        while(temp2){
            temp2=temp2->next;
            l++;
        }
        if(index>l) return;
        
        if(head==NULL || index==0){
             ListNode* newNode=new ListNode(val);
            newNode->next=head;
            head=newNode;
            return;
        }

        ListNode* temp=head;
        int cnt=0;
        while(cnt<index-1 && temp->next){
            temp=temp-> next;
            cnt++;
        }
        ListNode * newNode=new ListNode(val);
        ListNode * after=temp->next;
        temp->next=newNode;
        newNode->next=after;
        
    }
    
    
    void deleteAtIndex(int index) {
        if (index < 0 || head == NULL) return;

        if (index == 0) {  // delete the head node
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        ListNode* temp = head;
        int cnt = 0;

        while (temp && cnt < index - 1) {
            temp = temp->next;
            cnt++;
        }

        if (temp == NULL || temp->next == NULL) return;

        ListNode* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }

};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
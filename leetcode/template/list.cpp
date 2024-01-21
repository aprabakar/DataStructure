//basic iteration

 ListNode *prev, *curr = head;
  prev = NULL;

  while(curr){
      ListNode* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
  }

  return prev;

//Using stack

if ((!head) || (!head->next) || (!head->next->next)) return; // Edge cases

stack<ListNode*> my_stack;
ListNode* ptr = head;
int size = 0;
while (ptr != NULL) // Put all nodes in stack
{
    my_stack.push(ptr);
    size++;
    ptr = ptr->next;
}

ListNode* pptr = head;
for (int j=0; j<size/2; j++) // Between every two nodes insert the one in the top of the stack
{
    ListNode *element = my_stack.top();
    my_stack.pop();
    element->next = pptr->next;
    pptr->next = element;
    pptr = pptr->next->next;
}
pptr->next = NULL;

// Adding as sum
int carry = 0;
  int sum = 0;
  ListNode* res= new ListNode(-1);
  ListNode* head = res;
  // 1 4 3 4 -> 4341
  // 5 6 4   -> 465
  // 6 0 8 4 -> 4806
  while (l1 || l2){
      if(l1){
          sum += l1->val;
          l1 =l1->next;
      }
      if(l2){
          sum += l2->val;
          l2 =l2->next;
      }
      
      sum += carry;
      ListNode* curr = new ListNode(sum%10);
      res->next = curr;
      res = res->next;
      carry = sum/10;
      sum = 0;
  }
  
  if(carry){
      ListNode* last = new ListNode(carry);
      res->next = last;
  }
  
  return head->next;     

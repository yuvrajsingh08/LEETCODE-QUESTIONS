/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int county(ListNode* head) {
        int len=0;
        while(head!=NULL){
            head=head->next;
            len++;
        }
       
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
      if(head == NULL || head->next == NULL) {
          return head;
      }
      int count=0;
      int l=county(head);
      k=k%l;
        while(count<k){
            int i=1;
            ListNode* temp1=head;
            ListNode* temp=head;
            while(i!=(l-1)){
              temp1=temp1->next;
              i++;
            }
            temp1->next->next=head;
            head=temp1->next;
            temp1->next=NULL;
            //  ListNode* temp2=temp1->next;
            // temp1->next=NULL;
            // temp2->next=temp;
            // head=temp2;
            count++;
        }
        return head;
    }
};
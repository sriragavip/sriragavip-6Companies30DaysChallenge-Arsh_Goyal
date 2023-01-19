class Solution {
public:
    
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        unordered_map<int, ListNode*> prefix_sum_to_node;
        if (head == nullptr){
            return nullptr;
        }
        ListNode* guard = new ListNode(0);
        guard->next = head;
        head = guard;
   
        ListNode* p = head;
        int prefix_sum = 0;
        bool happen_change = false;
        while(p != nullptr){
            prefix_sum += p->val;
            if (prefix_sum_to_node.count(prefix_sum) == 0){
                prefix_sum_to_node.insert({prefix_sum, p});
            }
            else{
                happen_change = true;
                ListNode* pre_p = prefix_sum_to_node[prefix_sum];
                ListNode* next_p = p->next;
                pre_p->next = next_p;
                p = pre_p;
            }
            p = p->next;
        }
        while(head != nullptr){
            if (head->val == 0){
                head = head->next;    
            }
            else{
                break;
            } 
        }        
        if (happen_change){
            return removeZeroSumSublists(head);
        }
        return head;
    }
};
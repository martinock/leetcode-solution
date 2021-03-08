// WRITER NOTE: This is not my solution
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, std::vector<int>, std::greater<int> > result ;
        ListNode* res = new ListNode();
        ListNode* start = new ListNode();
        
        for(int i = 0 ; i < lists.size() ; i++) {
            ListNode* tempList = lists[i] ;
            
            while(tempList != NULL) {
                result.push(tempList->val) ;
                tempList = tempList->next;
            }
        }
        start->next = res ;
        while(!result.empty()){
            int val = result.top();
            ListNode* temp = new ListNode(val) ;
            res->next = temp;
            res = res->next;
            result.pop();
        }
        
        return start->next->next;
    }
};
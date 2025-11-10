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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // ✅ Min-heap (priority queue) that stores {value, pointer to node}
        // We use "greater<>" so that smallest value is always on top
        priority_queue<pair<int, ListNode*>,
            vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        // ✅ Step 1: Push the head node of each linked list into the heap
        // Why? Each head contains the smallest element of that list
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) { // list is not empty
                pq.push({lists[i]->val, lists[i]});
            }
        }

        // ✅ Create a dummy node to help build the merged result list easily
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;  // temp will move along and build final list

        // ✅ Step 2: Process the heap until all nodes are merged
        while (!pq.empty()) {

            // Get the smallest element from the heap
            //we can use auto it=pq.top() too
            pair<int, ListNode*> it = pq.top();
            pq.pop();

            // If this node has a next node, push the next node into the heap
            // Why? Now this next node is the new candidate for smallest
            if (it.second->next) {
                pq.push({it.second->next->val, it.second->next});
            }

            // Attach the extracted node to the merged list
            temp->next = it.second;
            temp = temp->next;
        }

        // ✅ dummy->next is the actual head of the merged sorted list
        return dummy->next;
    }
};

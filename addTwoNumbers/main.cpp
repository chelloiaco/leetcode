#include <iostream>
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0), next(nullptr) {}
    ListNode(int x)
        : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next)
        : val(x), next(next) {}
};

class Solution {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // sum
        ListNode* current = new ListNode();
        ListNode* result = current;
        int carryover{0};
        bool last_run{false};
        while (!last_run) {
            carryover = 0;
            // Check for last run
            if (l1->next == nullptr && l2->next == nullptr) {
                last_run = true;
            }
            current->val += l1->val + l2->val;
            carryover = (current->val - current->val % 10) / 10;
            current->val = current->val % 10;

            // Break out of while loop earlier
            if (last_run && !carryover) {
                break;
            }

            // syncronize lists so we can continue accessing values
            if (l1->next != nullptr && l2->next == nullptr) {
                l2->next = new ListNode();
            } else if (l1->next == nullptr && l2->next != nullptr) {
                l1->next = new ListNode();
            }
            l1 = l1->next;
            l2 = l2->next;

            // Initialize next result node
            current->next = new ListNode(carryover);
            current = current->next;
        }

        return result;
    }
};


int main() {
    Solution sl{};
    int test1[] = {9, 9, 9, 9, 9, 9, 9};
    int test2[] = {9, 9, 9, 9};

    ListNode* tmp = new ListNode();
    ListNode* l1 = tmp;
    for (size_t i = 0; i < sizeof(test1) / sizeof(test1[0]) - 1; i++) {
        tmp->val = test1[i];
        tmp->next = new ListNode(test1[i + 1]);
        tmp = tmp->next;
    }


    tmp = new ListNode();
    ListNode* l2 = tmp;
    for (size_t i = 0; i < sizeof(test2) / sizeof(test2[0]) - 1; i++) {
        tmp->val = test2[i];
        tmp->next = new ListNode(test2[i + 1]);
        tmp = tmp->next;
    }


    ListNode* result{sl.addTwoNumbers(l1, l2)};
    while (true) {
        std::cout << result->val << ", ";
        if (result->next == nullptr) {
            break;
        }
        result = result->next;
    }
    std::cout << std::endl;

    // [8,9,9,9,0,0,0,1]
}
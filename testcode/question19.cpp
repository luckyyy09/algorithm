/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pre = new ListNode(0);
        pre->next = head;
        ListNode *first = pre;
        for (int i = 0; i < n; i++) {
            head = head->next;
        }
        while (head != nullptr)
        {
            head = head->next;
            first = first->next;
        }
        first->next = first->next->next;
        ListNode *ret = pre->next;
        delete pre;
        return ret;

    }
};
// @lc code=end


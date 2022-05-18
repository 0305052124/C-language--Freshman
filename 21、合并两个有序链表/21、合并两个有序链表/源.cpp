#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    struct ListNode* head = NULL, * tail = NULL;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            if (tail == NULL)  head = tail = list1;
            else
            {
                tail->next = list1;
                tail = tail->next;
            }
            list1 = list1->next;
        }
        else
        {
            if (tail == NULL)  head = tail = list2;
            else
            {
                tail->next = list2;
                tail = tail->next;
            }
            list2 = list2->next;
        }
    }
    if (list1) tail->next = list1;
    if (list2) tail->next = list2;
    return head;
}
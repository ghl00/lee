#include "mylist.h"

ListNode* remove_if(ListNode* head)
{
    for (ListNode* cur = head, *prev = NULL; cur != NULL; )
    {
        ListNode* tmp = cur->next;
        if (cur->val == 2)
        {
            if (prev)
            {
                prev->next = tmp;
            }
            else
            {
                head = cur->next;
            }
            free(cur);
        }
        else
        {
            prev = cur;
        }
        cur = tmp;
    }

    return head;
}

void remove_if(ListNode** head)
{
    for (ListNode** cur = head; *cur != NULL;)
    {
        ListNode* tmp = *cur;
        if ((*cur)->val == 2)
        {
            *cur = (*cur)->next;
            free(tmp);
        }
        else
        {
            cur = &(*cur)->next;
        }
    }
}

void insert(ListNode** head, std::vector<int>& v)
{
    for (auto it : v)
    {
        ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
        new_node->val = it;
        new_node->next = *head;
        *head = new_node;
    }

}

void print(ListNode* head)
{
    for (ListNode* cur = head; cur != NULL; cur = cur->next)
    {
        printf(" %d", cur->val);
    }
    printf("\n");
}

bool palind(ListNode* head)
{
    bool result = false;
    int size = 0;
    for (ListNode* cur = head; cur != NULL; size++, cur = cur->next)
        ;
    if (size == 0)
    {
        result = false;
    }
    else if (size == 1)
    {
        result = true;
    }
    else
    {
        ListNode* cur = head;
        for (int i = 0; i < size / 2; cur = cur->next, i++);
        ListNode* lhead = cur;
        //lhead = reverse(lhead);
        {
            if (lhead != NULL && lhead->next != NULL)
            {
                ListNode* cur = lhead->next;
                ListNode* pre = lhead;
                pre->next = NULL;
                for (; cur != NULL;)
                {
                    ListNode* tmp = cur->next;
                    cur->next = pre;
                    pre = cur;
                    cur = tmp;
                }
                lhead = pre;
            }
        }
        //print(lhead);
        ListNode* ftemp = head;
        ListNode* ltemp = lhead;
        for (int i = 1; i <= size / 2; i++)
        {
            if (ftemp->val == ltemp->val)
            {
                result = true;
                ftemp = ftemp->next;
                ltemp = ltemp->next;
            }
            else
            {
                result = false;
                break;
            }
        }
        //lhead = reverse(lhead);
        {
            if (lhead != NULL && lhead->next != NULL)
            {
                ListNode* cur = lhead->next;
                ListNode* pre = lhead;
                pre->next = NULL;
                for (; cur != NULL;)
                {
                    ListNode* tmp = cur->next;
                    cur->next = pre;
                    pre = cur;
                    cur = tmp;
                }
                lhead = pre;
            }
        }
        //print(lhead);
    }
    return result;
}

ListNode* reverse(ListNode* head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode* cur = head->next;
    ListNode* pre = head;
    pre->next = NULL;
    for (; cur != NULL;)
    {
        ListNode* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

ListNode* bind2(ListNode* list1, ListNode* list2)
{
    ListNode* head = nullptr;
    int check_list = 0;
    for (ListNode *cur1 = list1, *cur2 = list2; ; )
    {
        if (cur1 != NULL && cur2 != NULL)
        {
            ListNode* tmp1 = cur1->next;
            ListNode* tmp2 = cur2->next;
            if (check_list == 0)
            {
                if (cur2->val <= cur1->val)
                {
                    if ((cur2->next == NULL) || (cur2->next != NULL && cur2->next->val > cur1->val))
                    {
                        cur2->next = cur1;
                        check_list = 1;
                    }
                    else
                    {
                        check_list = 2;
                    }
                    if (head == NULL && cur2 == list2)
                    {
                        head = list2;
                    }
                    cur2 = tmp2;
                }
                else
                {
                    if ((cur1->next == NULL) || (cur1->next != NULL && cur1->next->val > cur2->val))
                    {
                        cur1->next = cur2;
                        check_list = 2;
                    }
                    else
                    {
                        check_list = 1;
                    }
                    if (head == NULL && cur1 == list1)
                    {
                        head = list1;
                    }
                    cur1 = tmp1;
                }
            }
            else if (check_list == 2)
            {

                if ((cur2->next == NULL) || (cur2->next != NULL && cur2->next->val > cur1->val))
                {
                    cur2->next = cur1;
                    check_list = 1;
                }
                else
                {
                    check_list = 2;
                }
                cur2 = tmp2;
            }
            else if (check_list == 1)
            {
                if ((cur1->next == NULL) || (cur1->next != NULL && cur1->next->val > cur2->val))
                {
                    cur1->next = cur2;
                    check_list = 2;
                }
                else
                {
                    check_list = 1;
                }
                cur1 = tmp1;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = (list1 != NULL) ? list1 : list2;
            }
            break;
        }
    }
    return head;
}

ListNode* remove_if_n(ListNode* head, int n)
{
    std::vector<ListNode*> vp;
    for (ListNode* cur = head; cur != NULL; cur = cur->next)
    {
        vp.push_back(cur);
    }
    int size_vp = vp.size();
    int del_idx = size_vp - n;
    ListNode* tmp = nullptr;
    if (del_idx == 0)
    {
        tmp = head;
        head = head->next;
    }
    else if (del_idx == size_vp - 1)
    {
        tmp = vp[del_idx];
        vp[del_idx - 1]->next = nullptr;
    }
    else
    {
        tmp = vp[del_idx];
        vp[del_idx - 1]->next = vp[del_idx]->next;
    }
    delete tmp;
    return head;
}

ListNode* sum2(ListNode* l1, ListNode* l2)
{
    ListNode* cur1 = l1;
    ListNode* cur2 = l2;
    ListNode* cur = nullptr;
    ListNode* head = nullptr;
    int carry = 0;
    for (; cur1 != nullptr || cur2 != nullptr;)
    {
        int var1 = (cur1 == nullptr ? 0 : cur1->val);
        int var2 = (cur2 == nullptr ? 0 : cur2->val);
        if (head == nullptr)
        {
            cur = (ListNode*)new ListNode;
            cur->val = (var1 + var2 + carry) % 10;
            cur->next = nullptr;
            head = cur;
        }
        else
        {
            ListNode* tmp = (ListNode*)new ListNode;;
            tmp->val = (var1 + var2 + carry) % 10;
            tmp->next = nullptr;
            cur->next = tmp;
            cur = tmp;
        }
        carry = (var1 + var2 + carry) / 10;
        
        if (cur1 != nullptr)
        {
            cur1 = cur1->next;
        }
        if (cur2 != nullptr)
        {
            cur2 = cur2->next;
        }
    }
    if (carry != 0)
    { 
        ListNode* tmp = (ListNode*)new ListNode;;
        tmp->val = carry;
        tmp->next = nullptr;
        cur->next = tmp;
    }
    return head;
}

ListNode* swap(ListNode* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode* pre = head;
    ListNode* ppre = nullptr;
    head = nullptr;
    for (; pre != nullptr;)
    {
        ListNode* cur = pre->next;
        if (cur == nullptr)
        {
            break;
        }

        ListNode* tmp = cur->next;
        cur->next = pre;
        pre->next = tmp;
        if (head == nullptr)
        {
            head = cur;
        }
        if (ppre)
        {
            ppre->next = cur;
        }
        ppre = pre;
        pre = tmp;
    }
    return head;
}
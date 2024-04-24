#pragma once
#include "lee.h"

class ListNode
{
public:
    int         val;
    ListNode*   next;
};

void remove_if(ListNode** head);
void insert(ListNode** head, std::vector<int>& v);
void print(ListNode* head);
ListNode* reverse(ListNode* head);
bool palind(ListNode* head);
ListNode* bind2(ListNode* list1, ListNode* list2);
ListNode* remove_if_n(ListNode* head, int n);
ListNode* sum2(ListNode* l1, ListNode* l2);

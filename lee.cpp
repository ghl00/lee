#include "mylist.h"

int main()
{
    ListNode* head = NULL;
    std::vector<int> v{4, 3, 2, 6,5,1};
    insert(&head, v);
    print(head);

    ListNode* head2 = NULL;
    std::vector<int> v2{1};
    insert(&head2, v2);
    print(head2);

    //std::cout << "(case1) remove 2: ";
    //remove_if(&head);
    //print(head);

    //std::cout << "(case2) reverse: ";
    //head = reverse(head);
    //print(head);

    //std::cout << "(case3) palind: " <<(palind(head) ? "true\n" : "false\n");

    //std::cout << "(case4) bind2: ";
    //print(bind2(head, head2));

    /*head = remove_if_n(head, 2);*/
	return 0;
}



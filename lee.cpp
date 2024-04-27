#include "mylist.h"
#include "mytree.h"
int main()
{
    ListNode* head = NULL;
    std::vector<int> v{0,4,3,5,3,-1};
    insert(&head, v);
    //print(head);

    ListNode* head2 = NULL;
    std::vector<int> v2{9,4,6,5};
    insert(&head2, v2);
    //print(head2);

    //std::cout << "(case1) remove 2: ";
    //remove_if(&head);
    //print(head);

    //std::cout << "(case2) reverse: ";
    //head = reverse(head);
    //print(head);

    //std::cout << "(case3) palind: " <<(palind(head) ? "true\n" : "false\n");

    //std::cout << "(case4) bind2: ";
    //print(bind2(head, head2));

    //std::cout << "(case5) remove n: ";
    //head = remove_if_n(head, 1);
    //print(head);

    //std::cout << "(case6) sum2: ";
    //print(sum2(head, head2));

    //std::cout << "(case7) swap: ";
    //print(swap(head));

    //std::cout << "(case8) sort: ";
    //print(sort(head));

    TreeNode* root = nullptr;
    std::vector<int> vt{27, 14, 35, 10, 19, 31, 42};
    for (auto it:vt)
    {
        root = InsertNode(root, it);
    }
    std::cout << "In:";
    InOrderTraverse(root);
    std::cout << "\n";

    //std::cout << "Pre:";
    //PreOrderTraverse(root);
    //std::cout << "\n";

    //std::cout << "Post:";
    //PostOrderTraverse(root);
    //std::cout << "\n";

    //std::cout << "Level:";
    //LevelOrderTraverse(root);
    //std::cout << "\n";

    //std::cout << maxDepth(root) << "\n";

    //std::vector<int> vtree = inorderTraversal(root);
    //std::cout << "in:";
    //for (auto it : vtree)
    //{
    //    std::cout << " " << it;
    //}
    return 0;
}



#include "../data_structure/list_node.hpp"

namespace leetcode
{

template <typename T>
ListNode<T> *swapPairs(ListNode<T> *head)
{
    if (!head)
    {
        return nullptr;
    }
    else if (!head->next)
    {
        return head;
    }
    else
    {
        ListNode<T> *new_head = head->next;
        head->next = swapPairs(new_head->next);
        new_head->next = head;
        return new_head;
    }
}

} // namespace leetcode

#include "../data_structure/list_node.hpp"

namespace leetcode
{

template <
    typename T,
    typename UnaryPredicate>
static constexpr ListNode<T> *
removeElements_If(ListNode<T> *head, const UnaryPredicate &pred)
{
    if (!head)
    {
        return nullptr;
    }
    else if (pred(head->val))
    {
        ListNode<T> *result = removeElements_If(head->next, pred);
        head->next = nullptr;
        delete head;
        return result;
    }
    else
    {
        if (!head->next)
        {
            return head;
        }
        else
        {
            if (pred(head->next->val))
            {
                ListNode<T> *tmp = head->next;
                head->next = removeElements_If(head->next->next, pred);
                tmp->next = nullptr;
                delete tmp;
                return head;
            }
            else
            {
                head->next = removeElements_If(head->next, pred);
                return head;
            }
        }
    }
}

template <typename T>
static constexpr ListNode<T> *
removeElements(ListNode<T> *head, const T &val)
{
    if (!head)
    {
        return nullptr;
    }
    else if (head->val == val)
    {
        ListNode<T> *result = removeElements(head->next, val);
        head->next = nullptr;
        delete head;
        return result;
    }
    else
    {
        if (!head->next)
        {
            return head;
        }
        else
        {
            if (head->next->val == val)
            {
                ListNode<T> *tmp = head->next;
                head->next = removeElements(head->next->next, val);
                tmp->next = nullptr;
                delete tmp;
                return head;
            }
            else
            {
                head->next = removeElements(head->next, val);
                return head;
            }
        }
    }
}

} // namespace leetcode

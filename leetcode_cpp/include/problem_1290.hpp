#include "../data_structure/list_node.hpp"

namespace leetcode
{

template <typename T>
std::size_t getDecimalValue(const ListNode<T> *head)
{
    std::size_t result = 0;
    std::size_t pow = 1;
    while (head)
    {
        result = result << 1;
        result |= head->val;
        head = head->next;
    }
    return result;
}

}; // namespace leetcode

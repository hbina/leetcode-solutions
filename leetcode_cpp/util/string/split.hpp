#pragma once

#include <string>

namespace util
{
namespace string
{

template <
    typename OutputIterator,
    typename = std::enable_if<
        std::is_same_v<
            std::iterator_traits<OutputIterator::iterator>::value_type,
            std::string>>>
OutputIterator split(
    const std::string &input,
    const std::string &delimiter)
{
    OutputIterator result;
    std::size_t iter_begin = 0;
    auto find = input.find(delimiter, 0);

    while (find != std::string::npos)
    {
        std::string token = input.substr(iter_begin, find - iter_begin);
        result.push_back(std::move(token));

        iter_begin = find + delimiter.length();
        find = input.find(delimiter, iter_begin);
    }
    if (iter_begin != input.length())
    {
        std::string token = input.substr(iter_begin, input.length());
        result.push_back(std::move(token));
    }
    return result;
}

template <
    typename OutputIterator,
    typename UnaryPredicate>
OutputIterator split_if(
    std::string::const_iterator iter_begin,
    std::string::const_iterator iter_end,
    const UnaryPredicate &delimiter)
{
    //  FIXME   ::  How the heck do I implement this
    return {};
}

} // namespace string
} // namespace util
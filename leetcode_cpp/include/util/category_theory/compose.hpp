#include <utility>

static constexpr auto const id = [](auto &&t) -> decltype(t) && { return std::forward<decltype(t)>(t); };

template <typename G, typename F>
static constexpr auto operator*(G &&g, F &&f)
{
    return [g, f](auto &&t) { return g(f(std::forward<decltype(t)>(t))); };
}

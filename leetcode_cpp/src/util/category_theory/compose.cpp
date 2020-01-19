#include "doctest/doctest.h"

#include "util/category_theory/compose.hpp"

static constexpr auto two = []() -> int { return 2; };
template <typename NumType = int>
static constexpr auto add_2 = [](const NumType &v) -> NumType { return v + 2; };
template <typename NumType = int>
static constexpr auto times_10 = [](const NumType &v) -> NumType { return v * 10; };
static constexpr auto g_after_f = add_2<> * times_10<>;

TEST_CASE("compose")
{
    CHECK(22 == (g_after_f)(two()));
}

import unittest
from typing import List


class Solution:
    def canPartition(self, nums: List[int]) -> bool:

        total_sum = sum(nums, 0)
        if total_sum % 2 != 0:
            return False
        else:
            nums.sort(key=lambda x: x, reverse=True)
            return canPartition_recursion(nums, 0, total_sum, int(total_sum/2))


def canPartition_recursion(nums: List[int], current_index: int, whats_left: int, local_goal: int) -> True:
    if current_index >= len(nums):
        return False
    elif local_goal > whats_left:
        return False
    elif local_goal == whats_left:
        return True
    else:
        next_index = current_index + 1
        next_whats_left = whats_left - nums[current_index]
        if local_goal > nums[current_index]:
            return (
                canPartition_recursion(nums, next_index, next_whats_left, local_goal-nums[current_index]) or
                canPartition_recursion(nums, next_index, next_whats_left, local_goal)
            )
        elif local_goal == nums[current_index]:
            return True
        else:
            return canPartition_recursion(nums, next_index, next_whats_left, local_goal)


class SimpleTest(unittest.TestCase):

    # Returns True or False.
    def test(self):
        s = Solution()
        test_1: bool = s.canPartition([1, 5, 11, 5]) is True
        test_2: bool = s.canPartition([1, 2, 5]) is False
        test_3: bool = s.canPartition([1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 100]
                                      ) is False
        test_4: bool = s.canPartition([1, 2, 3, 4, 5, 6, 7]) is True
        self.assertTrue(test_1 and test_2 and test_3 and test_4)


if __name__ == '__main__':
    unittest.main()

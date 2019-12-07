import unittest
from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort(key=lambda y: y)
        result = []
        for x in range(0, len(nums) - 2):
            if x > 0 and nums[x] == nums[x - 1]:
                continue
            else:
                left_pointer = x + 1
                right_pointer = len(nums) - 1
                while left_pointer < right_pointer:
                    local_sum = nums[x] + \
                                nums[left_pointer] + nums[right_pointer]
                    if local_sum == 0:
                        result.append(
                            [nums[x], nums[left_pointer], nums[right_pointer]])
                        # Skip identical numbers
                        while left_pointer + 1 < right_pointer and nums[left_pointer] == nums[left_pointer + 1]:
                            left_pointer = left_pointer + 1
                        while left_pointer < right_pointer - 1 and nums[right_pointer] == nums[right_pointer - 1]:
                            right_pointer = right_pointer - 1
                        left_pointer = left_pointer + 1
                        right_pointer = right_pointer - 1
                    elif local_sum > 0:
                        right_pointer = right_pointer - 1
                    else:
                        left_pointer = left_pointer + 1
        return result


class SimpleTest(unittest.TestCase):

    # Returns True or False.
    def test(self):
        s = Solution()
        self.assertTrue(s.threeSum([-1, 0, 1, 2, -1, -4])
                        == [[-1, -1, 2], [-1, 0, 1]])


if __name__ == '__main__':
    unittest.main()

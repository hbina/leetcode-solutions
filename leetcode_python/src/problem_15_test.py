import unittest
from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort(key=lambda x: x)
        result = []
        for iter in range(0, len(nums)-2):
            if iter > 0 and nums[iter] == nums[iter-1]:
                continue
            else:
                left_pointer = iter + 1
                right_pointer = len(nums)-1
                while left_pointer < right_pointer:
                    local_sum = nums[iter] + \
                        nums[left_pointer] + nums[right_pointer]
                    if local_sum == 0:
                        result.append(
                            [nums[iter], nums[left_pointer], nums[right_pointer]])
                        # Skip identical numbers
                        while left_pointer + 1 < right_pointer and nums[left_pointer] == nums[left_pointer + 1]:
                            left_pointer = left_pointer + 1
                        while left_pointer < right_pointer-1 and nums[right_pointer] == nums[right_pointer - 1]:
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

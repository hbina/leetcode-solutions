import unittest
from typing import List


class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        #   TODO    ::  Check for trivial case when len(nums) == 4
        nums.sort(key=lambda y: y)
        result = []

        return result


class SimpleTest(unittest.TestCase):

    # Returns True or False.
    def test(self):
        s = Solution()
        self.assertTrue(s.fourSum([1, 0, -1, 0, -2, 2], 0)
                        == [
                            [-1, 0, 0, 1],
                            [-2, -1, 1, 2],
                            [-2, 0, 0, 2]
                        ])


if __name__ == '__main__':
    unittest.main()

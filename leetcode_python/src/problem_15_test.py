import unittest


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        [[]]


class SimpleTest(unittest.TestCase):

    # Returns True or False.
    def test(self):
        s = Solution()
        return s.threeSum([-1, 0, 1, 2, -1, -4]) == [[-1, 0, 1], [-1, -1, 2]]


if __name__ == '__main__':
    unittest.main()

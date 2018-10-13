using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace leetcode_csharp
{
    static class Problem561
    {
        public static int ArrayPairSum(int[] nums)
        {
            int sum = 0;
            if (!((nums.GetLength(0) % 2).Equals(0)))
            {
                throw new System.ArgumentException("given array is not even");
            }
            else
            {
                //nums = InsertionSort.Sort(nums);
                Array.Sort(nums);
                Tools.PrintContent(nums);
                for (int a = 0; a < nums.GetLength(0); a += 2)
                {
                    Console.WriteLine($"index {a} adding {sum} += {nums[a]}");
                    sum += nums[a];
                }
            }
            return sum;
        }
    }
}

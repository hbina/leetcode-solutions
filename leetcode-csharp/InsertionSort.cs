using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace leetcode_csharp
{
    static class InsertionSort
    {
        public static int[] Sort(int[] narr)
        {
            for (int a = 0; a < narr.GetLength(0); a++)
            {
                for (int b = a; b > 0; b--)
                {
                    if (narr[b].CompareTo(narr[b - 1]) < 0)
                    {
                        int tmp = narr[b];
                        narr[b] = narr[b - 1];
                        narr[b - 1] = tmp;
                    }
                }
            }
            return narr;
        }

        public static void VerifyAlg()
        {
            int[] arr = new int[] { 6, 5, 4, 3, 2, 1 };
            Console.WriteLine($"verifying InsertionSort Sort with arr:");
            Tools.PrintContent(arr);
            arr = Sort(arr);
            for (int a = 0; a < arr.GetLength(0); a++)
            {
                Console.Write(arr[a] + " ");
            }
        }
    }
}

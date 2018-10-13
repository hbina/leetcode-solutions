using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace leetcode_csharp
{
    static class SelectionSort
    {
        public static int[] Sort(int[] arr)
        {
            for (int a = 0; a < arr.GetLength(0); a++)
            {
                int mi = a;
                for (int b = a; b < arr.GetLength(0); b++)
                {
                    if (arr[mi] > arr[b])
                    {
                        mi = b;
                    }
                }
                int tmp = arr[a];
                arr[a] = arr[mi];
                arr[mi] = tmp;
            }
            return arr;
        }

        public static void VerifyAlg()
        {
            int[] arr = new int[] { 6, 5, 4, 3, 99, 1 };
            Tools.PrintContent(arr);
            arr = Sort(arr);
            Tools.PrintContent(arr);
        }
    }
}

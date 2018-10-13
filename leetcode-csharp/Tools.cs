using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace leetcode_csharp
{
    static class Tools
    {
        public static void PrintContent(int[] arr)
        {
            for (int a = 0; a < arr.GetLength(0); a++)
            {
                Console.Write(arr[a] + " ");
            }
            Console.WriteLine("");
        }
    }
}

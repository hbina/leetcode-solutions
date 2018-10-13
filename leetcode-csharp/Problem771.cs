using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms.DataVisualization.Charting;

namespace leetcode_csharp
{
    class Problem771
    {
        /// <summary>
        /// This solution is at most O(n) but the space is also O(n).
        /// This is good if j and s are extremely large, but if they 
        /// are small, it might not be worth it to erect a dictionary 
        /// instead of just iterating them over.
        /// </summary>
        /// <param name="J"></param>
        /// <param name="S"></param>
        /// <returns></returns>
        public static int NumJewelsInStones(String J, String S)
        {
            int result = 0;
            Dictionary<char, bool> dict = new Dictionary<char, bool>();
            foreach (char c in J)
            {
                dict.Add(c, true);
            }

            foreach (char c in S)
            {
                if (dict.ContainsKey(c))
                {
                    result++;
                }
            }
            return result;
        }

        public static void visualizeImage()
        {
            Chart chart = new Chart();
        }
    }
}

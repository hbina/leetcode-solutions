using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace leetcode_csharp
{
    public class Problem728
    {
        public static IList<int> SelfDividingNumbers(int left, int right)
        {
            IList<int> myl = new List<int>();

            for (; left <= right; left++)
            {
                myl.Add(left);
                foreach (char c in left.ToString())
                {
                    int a = Int32.Parse(c + "");
                    if (a == 0)
                    {
                        myl.Remove(left);
                    }
                    else if ((left % a) != 0)
                    {
                        myl.Remove(left);
                    }
                }
            }

            return myl;
        }
    }
}

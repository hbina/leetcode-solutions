using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace leetcode_csharp
{
    class Problem804 : LeetCodeSolutions
    {
        public static int UniqueMorseRepresentations(string[] words)
        {
            String[] morseCodeMap = {
            ".-","-...","-.-.","-..",".","..-.","--.","....",
            "..",".---","-.-",".-..","--","-.","---",".--.",
            "--.-",".-.","...","-","..-","...-",".--","-..-",
            "-.--","--.."};
            Int32 LOWERCASE_CHAR_BEGIN = 97;
            Int32 CHAR_COUNT = 26;

            Dictionary<char, String> dict = new Dictionary<char, string>();
            Int32 uniqueCount = 0;
            Dictionary<String, bool> dict2 = new Dictionary<String, bool>();

            for (int a = 0; a < CHAR_COUNT; a++)
            {
                dict.Add((char)(a + LOWERCASE_CHAR_BEGIN), morseCodeMap[a]);
            }
            for (int a = 0; a < words.GetLength(0); a++)
            {
                String transString = "";
                for (int b = 0; b < words[a].Length; b++)
                {
                    transString += dict[words[a][b]];
                }
                if (!dict2.ContainsKey(transString))
                {
                    uniqueCount++;
                    dict2.Add(transString, true);
                }
            }
            return uniqueCount;
        }
    }

}

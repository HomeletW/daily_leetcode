/**
 * 68. Text Justification
 * https://leetcode.com/problems/text-justification/description/
 */

#include "my_util.hpp"
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        // greedily fetch each words, if it fits on current line, then do so
        // otherwise, push it to next

        vector<string> result;

        // start a new line
        auto lineBegin = words.begin();
        int lineWidth = lineBegin->size();
        for (auto word = words.begin() + 1; word != words.end(); ++word)
        {
            // check if word can be fitted into current line
            if (lineWidth + word->size() + 1 <= maxWidth)
            {
                // can fit, and move on
                lineWidth += word->size() + 1;
            }
            else
            {
                // cannot fit, push the previous line
                result.push_back(joinAndJustify(lineBegin, word, lineWidth, maxWidth));
                // start a new line
                lineBegin = word;
                lineWidth = lineBegin->size();
            }
        }

        // if there are remaining words in a line, put them left aligned
        if (lineBegin != words.end())
        {
            string lastLine = *(lineBegin++);
            while (lineBegin != words.end())
            {
                lastLine.push_back(' ');
                lastLine.insert(lastLine.end(), lineBegin->begin(), lineBegin->end());
                ++lineBegin;
            }
            // pad the ends
            pads(lastLine, maxWidth - lastLine.size());
            result.push_back(lastLine);
        }

        return result;
    }
private:
    string joinAndJustify(vector<string>::iterator begin, vector<string>::iterator end, int lineWidth, int maxWidth)
    {
        // calculate how many total spaces needs to be padded
        // each word were already appended a space, except the last one (the -1 accounts for this)
        int wordCounts = distance(begin, end);
        int spaceCounts = wordCounts - 1;  // the amount of empty spaces in between words
        int padCounts = maxWidth - lineWidth + spaceCounts;
        int basePads = spaceCounts > 0 ? padCounts / spaceCounts : padCounts;
        int remiPads = spaceCounts > 0 ? padCounts % spaceCounts : 0;

        string result;
        auto word = begin;
        while (word != end)
        {
            result.insert(result.end(), word->begin(), word->end());
            if (word == begin || word + 1 != end)
            {
                pads(result, basePads + (remiPads-- > 0));
            }
            ++word;
        }

        return result;
    }

    template<char pad = ' '>
    void pads(string& out, int amount)
    {
        while (amount != 0)
        {
            out.push_back(pad);
            --amount;
        }
    }
};

int main()
{
//    vector<string> words{"This", "is", "an", "example", "of", "text", "justification."};
//    vector<string> words{"What", "must", "be", "acknowledgment", "shall", "be."};
//    vector<string> words{"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    vector<string> words{"ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country"};
    auto result = Solution().fullJustify(words, 16);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << "\"" << result[i] << "\"" << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;


//https://leetcode.com/problems/word-ladder/description/

class Solution
{
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string> &wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (dict.find(endWord) == dict.end())
            return 0;

        queue<string> q;
        q.push(beginWord);
        int Level = 1;

        while (!q.empty())
        {
            int n = q.size();

            while (n--)
            {
                string word = q.front();
                q.pop();

                for (int i = 0; i < word.size(); i++)
                {
                    char original = word[i];

                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        word[i] = ch;
                        if (word == endWord)
                            return Level + 1;
                        if (dict.find(word) != dict.end())
                        {
                            q.push(word);
                            dict.erase(
                                word); // mark it visited otherwise create loop
                        }
                    }
                    word[i] = original;
                }
            }

            Level++;
        }
        return 0;
    }
};
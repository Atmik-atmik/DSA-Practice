#include <string>
#include <vector>
using namespace std;



#include <string>
#include <vector>
using namespace std;

class Solution {
public:

    //can't understna lps array
    //You assumed prefix and suffix must be disjoint. That’s not true. They are allowed to overlap
    //when lps[len] != lps[i] && len !=0 then next character is 
    //of pat is lps[len-1] which is last char of lps found , not
    //character just before pat[len] ,i.e pat[len-1], I got this 
    //confusion
    //when pat[len] == pat[i] then this len is from 0...i but when 
    //pat[len] != pat[i] then len is from 0....len
    
    //DOUBT:  if pat[len] != pat[i] then why len is changed?
    
    //Ask to myself how lps is found in a string , simple starting from 0 and 1
    //if anything not matches then again start from 0 and 2 and keep doing it
    //untile i != m;
    
    // Build LPS (longest proper prefix which is also suffix) for pattern
    void buildLPS(const string &pat, vector<int> &lps) {
        int m = pat.size();
        lps.assign(m, 0);
        int len = 0;       // length of previous longest prefix suffix
        int i = 1;
        while (i < m) {
            if (pat[i] == pat[len]) {
                ++len;
                lps[i] = len;
                ++i;
            } else {
                if (len != 0) len = lps[len - 1];
                else { lps[i] = 0; ++i; }
            }
        }   
    }

    bool areRotations(string &s1, string &s2) {
        int n = s1.size();
        if (n != (int)s2.size()) return false;
        if (n == 0) return true; // both empty

        // Prepare LPS for pattern = s2
        vector<int> lps;
        buildLPS(s2, lps);

        // KMP search of pattern s2 in virtual text s1+s1 (length = 2*n)
        int i = 0; // index in virtual text
        int j = 0; // index in pattern s2
        int limit = 2 * n; // search over s1+s1f
        while (i < limit) {
            char tc = s1[i % n]; // virtual text char
            if (tc == s2[j]) {
                ++i; ++j;
                if (j == n) return true; // full match found
            } else {
                if (j != 0) j = lps[j - 1];
                else ++i;
            }
            // Optional small optimization: if (i - j >= n) break; 
            // but main loop is already linear so not required.
        }
        return false;
    }
};

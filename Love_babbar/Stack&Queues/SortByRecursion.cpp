#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    void insertSorted(stack<int> &st, int element) {
        
        if (st.empty() || st.top() <= element) {
            st.push(element);
            return;
        }

        
        int topElement = st.top();
        st.pop();
        insertSorted(st, element);

        
        st.push(topElement);
    }

    void sortStack(stack<int> &st) {
        
        if (st.empty()) return;

        
        int topElement = st.top();
        st.pop();

        
        sortStack(st);

        
        insertSorted(st, topElement);
    }
};

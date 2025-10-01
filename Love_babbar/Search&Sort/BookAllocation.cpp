#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
//in this case its not possible that books are allocated and somestudent doesn't get book.
//that can happen when k> n;
    bool isPossible(vector<int> &arr, int k, int mid, int n) {
        int studentCnt = 1;
        int pageSum = 0;

        for (int i = 0; i < n; i++) {
            if (pageSum + arr[i] <= mid) {
                pageSum += arr[i];
            } else {
                studentCnt++;
                if (studentCnt > k || arr[i] > mid) return false;
                pageSum = arr[i];
            }
        }
        return true;
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (n == 0 || k > n) return -1;

        int sum = accumulate(arr.begin(), arr.end(), 0);
        int s = 0;
        int e = sum;
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (isPossible(arr, k, mid, n)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1; //some books are not allocated, either no. of more stdent needed or an elemnt is greater than mid
            }
        }
        return ans;
    }
};

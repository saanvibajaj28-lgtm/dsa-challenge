# Day 1 - Striver SDE Sheet Challenge

## Problem 1: Set Matrix Zeroes

**Problem Statement:** Given a matrix, if an element is 0, set the entire row and column to 0. Do this in-place while maintaining O(1) extra space (excluding the output).

**Approach:** Use the first row and first column as markers. Track separately if the first row/column themselves need to be zeroed.

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstRowZero = false;
        bool firstColZero = false;
        
        // Check if first row needs to be zeroed
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }
        
        // Check if first column needs to be zeroed
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }
        
        // Mark zeros in first row and column
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // Set matrix to zero based on markers
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Handle first row
        if (firstRowZero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        
        // Handle first column
        if (firstColZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
```

**Time Complexity:** O(m × n)  
**Space Complexity:** O(1)

---

## Problem 2: Pascal's Triangle I (Element at Row and Column)

**Problem Statement:** Given row number `r` and column number `c` (1-indexed), return the element at that position in Pascal's Triangle.

**Approach:** Use the formula for binomial coefficient: C(n, k) = n! / (k! × (n-k)!)

```cpp
class Solution {
public:
    int pascalTriangleI(int r, int c) {
        int n = r - 1;
        int k = c - 1;
        int res = 1;
        
        for (int i = 0; i < k; i++) {
            res *= (n - i);
            res /= (i + 1);
        }
        
        return res;
    }
};
```

**Time Complexity:** O(c)  
**Space Complexity:** O(1)

---

## Problem 3: Next Permutation

**Problem Statement:** Modify the array in-place to contain the next lexicographically greater permutation. If no such permutation exists, arrange in ascending order.

**Approach:**
1. Find the largest index `i` where `nums[i] < nums[i+1]`
2. If no such index exists, reverse the entire array
3. Find the largest index `j > i` where `nums[j] > nums[i]`
4. Swap `nums[i]` and `nums[j]`
5. Reverse the suffix starting at `nums[i+1]`

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;
        
        // Step 1: Find the largest index i where nums[i] < nums[i+1]
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }
        
        // Step 2: If no such index exists, reverse entire array
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // Step 3: Find largest index j > index where nums[j] > nums[index]
        for (int i = n - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }
        
        // Step 4: Reverse the suffix
        reverse(nums.begin() + index + 1, nums.end());
    }
};
```

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

---

**Date:** Day 1 of Striver's SDE Sheet Challenge  
**Status:** ✅ Completed

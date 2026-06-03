class Solution {
public:
    int pascalTriangleI(int r, int c) {
int n = r-1;
int k = c-1;
int res =1;
for(int i=0;i<k;i++){
    res*=(n-i);
    res/=(i+1);
}
return res;
    }
};
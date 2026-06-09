#include <iostream>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int open = 0, close = 0;
        for (char c : s) {
            if (c == '(') open++;
            else close++;
        }

        if (open != close) {
            cout << 2 << endl;
            continue;
        }

        int bal = 0, mn = 0;
        for (char c : s) {
            if (c == '(') bal++;
            else bal--;

            mn = min(mn, bal);
        }

        if (mn == 0) {
            cout << 0 << endl;
        } else {
            int swaps = (-mn + 1) / 2; 

            if (swaps == 1) cout << 1 << endl;
            else cout << 2 << endl;
        }
    }

    return 0;
}
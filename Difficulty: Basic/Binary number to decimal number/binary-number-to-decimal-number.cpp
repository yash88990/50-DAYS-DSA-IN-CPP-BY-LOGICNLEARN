//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int binaryToDecimal(string &b) {
        // Code here.
       int dec = 0 , power = 0;
       for(int i = b.length() - 1 ; i >= 0 ; i--){
           if(b[i] == '1'){
               dec += pow(2, power);
           }
           power++;
       }
       return dec;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.binaryToDecimal(str);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
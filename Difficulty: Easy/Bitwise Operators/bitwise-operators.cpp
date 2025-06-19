// Function to perform bitwise manipulations
// a, b and c are input integers
void bitWiseOperation(int a, int b, int c) {

    // Your code here
    int d = a^a;
    int e = c^b;
    int f = a&b;
    int g = c | d;
    
    cout<<d<<endl<<e<<endl<<f<<endl<<g<<endl<<(~e)<<endl;

}
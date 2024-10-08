#include<iostream>
using namespace std;

int main(){
    cout << "Program to convert decimal to binary" << endl;
    cout << "Enter number to convert it into binary: ";
    
    int n;
    cin >> n;

    string binary = "";  // Use a string to construct the binary representation efficiently
    
    if(n == 0) {
        binary = "0";
    } else {
        while(n != 0) {
            int bit = n & 1;  // Extract the last bit
            binary = to_string(bit) + binary;  // Prepend the bit to the binary string
            n = n >> 1;  // Right shift to process the next bit
        }
    }
    
    cout << "Answer is: " << binary << endl;
    
    return 0;
}

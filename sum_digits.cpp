#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cout << "Koi bhi number dalein: ";
    cin >> n;

    while (n > 0) {
        int lastDigit = n % 10; // आखिरी नंबर निकालने के लिए
        sum = sum + lastDigit;  // सम में जोड़ने के लिए
        n = n / 10;            // आखिरी नंबर को हटाने के लिए
    }

    cout << "Sabhie anko ka jod hai: " << sum << endl;
    return 0;
}

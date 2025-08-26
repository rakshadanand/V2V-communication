
// V2V LiFi Simulation (C++) - manual style
// NOTE: Just a simple demo, not optimized!

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector<int> addNoise(const vector<int>& bits) {
    vector<int> noisy = bits;
    for (int i = 0; i < (int)bits.size(); i++) {
        if (rand() % 20 == 0) { // random error
            noisy[i] = !bits[i];
        }
    }
    return noisy;
}

int main() {
    vector<int> tx = {1,0,1,1,0,0,1}; // some dummy data
    cout << "TX bits: ";
    for (int b: tx) cout << b;
    cout << endl;

    auto noisy = addNoise(tx);

    cout << "RX bits: ";
    for (int b: noisy) cout << b;
    cout << endl;

    return 0;
}

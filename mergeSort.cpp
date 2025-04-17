#include <iostream>
using namespace std;

int arr[20], B[20];

int n;

void input() {
    while (true) {
        cout << "Masukkan Panjang element array: ";
        cin >> n;

        if (n<= 20) {
            break;
        }
        else {
            cout << "\nMaksimal panjang array adalah 20";
        }
    }

    cout << "\n======================\n";
    cout << "\nInputkan Isi Element Array";
    cout << "\n======================" << endl;

    for (int i =0; i < n; i++) {
        cout << "Array index ke - " << i << ": ";
        cin >> arr[i];
    }
}

void mergeSort(int low, int high) {
    //step 1
    if (low >= high) {
        return; //step 1.a
    }

    int mid = (low + high) / 2; //step 2

    
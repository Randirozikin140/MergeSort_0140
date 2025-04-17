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
    //step 1  Jika low lebih besar atau sama dengan high, berarti hanya ada satu elemen, sehingga langsung kembali
    if (low >= high) {
        return; //step 1.a
    }

    int mid = (low + high) / 2; //step 2  Menentukan titik tengah dari array: mid = (low + high) / 2

    //step 3  fungsi mergeSort secara rekursif untuk mengurutkan bagian pertama dan bagian kedua
    mergeSort(low, mid); //step 3.a (bagian pertama)
    mergeSort(mid + 1, high); //step 3.b (bagian kedua)

    //step 4  Proses penggabungan dua bagian yang telah terurut: Membandingkan elemen dari kedua bagian, dan menyusun dalam array B dalam urutan yang benar.Jika masih ada elemen tersisa di salah satu bagian, dimasukkan ke dalam array B
    int i, j;
    i = low;   //step 4.a
    j = mid + 1; //step 4.b

    int k = low; //step 4.c

    while(i <= mid&& j <= high) { //step 4.d
        if(arr[i] <= arr[j]) { //step 4.d.i
            B[k] <= arr[i];
            i++;
        } else {
            B[k] = arr[j];
            j++;
        }
        k++; //step 4.d.ii
    }

    //step 4.e
    while(j <= high ) {
        B[k] = arr[j];
        j++;
        k++;
    }

    //step 4.f
    while(i <= mid) {
        B[k] = arr[i];
        i++;
        k++;
    }

    //step 5  Memindahkan isi array B kembali ke arr, sehingga membuat array utama menjadi terurut.
    for (int y = low; y <= high; y++) {
        arr[y] = B[y];
    }
}

void ooutput() {
    cout  << "\nData setelah diurutkan (MergeSort): ";
    for (int i = 0; i < n; i++ ) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    input();
    mergeSort(0, n - 1); 
    ooutput(); 
}
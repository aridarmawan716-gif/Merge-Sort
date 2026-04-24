#include <iostream>
using namespace std;

// Fungsi untuk menggabungkan dua sub-array yang terurut
void Merge(int *a, int from, int to, int mid) {
    int i = from;       // Indeks untuk sub-array kiri
    int j = mid + 1;    // Indeks untuk sub-array kanan
    int k = 0;          // Indeks untuk array sementara
    
    int temp[to - from + 1]; // Array sementara untuk menampung hasil penggabungan

    // Membandingkan elemen dari sub-array kiri dan kanan
    while (i <= mid && j <= to) {
        if (a[i] < a[j]) {
            temp[k] = a[i];
            i++;
        } else {
            temp[k] = a[j];
            j++;
        }
        k++;
    }

    // Memasukkan sisa elemen dari sub-array kiri (jika ada)
    while (i <= mid) {
        temp[k] = a[i];
        i++;
        k++;
    }

    // Memasukkan sisa elemen dari sub-array kanan (jika ada)
    while (j <= to) {
        temp[k] = a[j];
        j++;
        k++;
    }

    // Menyalin kembali elemen dari array sementara ke array asli
    for (i = from, k = 0; i <= to; i++, k++) {
        a[i] = temp[k];
    }
}

// Fungsi utama MergeSort sesuai logika pada gambar
void MergeSort(int *a, int from, int to) {
    int mid;
    if (from < to) {
        mid = (from + to) / 2;

        // Bagi (Divide) menjadi bagian kiri dan kanan secara rekursif
        MergeSort(a, from, mid);
        MergeSort(a, mid + 1, to);

        // Taklukkan/Gabungkan (Conquer/Merge)
        Merge(a, from, to, mid);
    }
}

// Fungsi untuk mencetak array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int data[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(data) / sizeof(data[0]);

    cout << "Array sebelum diurutkan: ";
    printArray(data, n);

    // Pemanggilan awal MergeSort (dari indeks 0 sampai n-1)
    MergeSort(data, 0, n - 1);

    cout << "Array setelah diurutkan: ";
    printArray(data, n);

    return 0;
}

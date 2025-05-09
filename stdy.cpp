#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// Konstanta biaya per SKS
const int BIAYA_PER_SKS = 125000;

int main() {
    // Data mahasiswa
    string nim, nama;
    int jumlahMataKuliah, totalSeluruhSKS = 0;

    // Menyimpan daftar mata kuliah dan SKS-nya
    vector<string> daftarNamaMatkul;
    vector<int> daftarJumlahSKS;

    // Input NIM dan Nama Mahasiswa
    cout << "Masukkan NIM: ";
    getline(cin, nim);
    cout << "Masukkan Nama Mahasiswa: ";
    getline(cin, nama);

    // Input jumlah mata kuliah
    cout << "Masukkan jumlah mata kuliah yang diambil: ";
    cin >> jumlahMataKuliah;
    cin.ignore(); // Menghindari masalah newline

    // Input nama mata kuliah dan jumlah SKS-nya
    for (int i = 0; i < jumlahMataKuliah; i++) {
        string namaMatkul;
        int jumlahSKS;

        cout << "\nMata kuliah ke-" << i + 1 << endl;
        cout << "  Nama Mata Kuliah: ";
        getline(cin, namaMatkul);

        cout << "  Jumlah SKS: ";
        cin >> jumlahSKS;
        cin.ignore();

        // Simpan ke daftar
        daftarNamaMatkul.push_back(namaMatkul);
        daftarJumlahSKS.push_back(jumlahSKS);

        // Tambah total SKS
        totalSeluruhSKS += jumlahSKS;
    }

    // Hitung total biaya dan diskon
    int totalBiaya = totalSeluruhSKS * BIAYA_PER_SKS;
    float potonganDiskon = totalBiaya * 0.15;
    float totalBayarSetelahDiskon = totalBiaya - potonganDiskon;

    // Tampilkan hasil
    cout << "\n========== RINCIAN PEMBAYARAN ==========" << endl;
    cout << "NIM              : " << nim << endl;
    cout << "Nama Mahasiswa   : " << nama << endl;

    cout << "\nDaftar Mata Kuliah dan SKS:" << endl;
    for (int i = 0; i < jumlahMataKuliah; i++) {
        cout << " - " << daftarNamaMatkul[i] << " (" << daftarJumlahSKS[i] << " SKS)" << endl;
    }

    // Format angka tanpa koma
    cout << fixed << setprecision(0);
    cout << "\nTotal SKS               : " << totalSeluruhSKS << endl;
    cout << "Biaya Tanpa Diskon      : Rp" << totalBiaya << endl;
    cout << "Potongan Pandemi (15%)  : Rp" << potonganDiskon << endl;
    cout << "Total yang Harus Dibayar: Rp" << totalBayarSetelahDiskon << endl;

    return 0;
}


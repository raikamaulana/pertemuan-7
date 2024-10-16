#include <iostream>
#include <string>
using namespace std;

void kecilKeTerbesar(int nilai[10], string nama[10]){
    for (int i = 0; i < 10 - 1; i++){
        for (int j = 0; j < 10 - i - 1; j++){
            if (nilai[j] > nilai[j + 1]){
                int n = nilai[j];
                nilai[j] = nilai[j + 1];
                nilai[j + 1] = n;

                string m = nama[j];
                nama[j] = nama[j + 1];
                nama[j + 1] = m;
            }
        }
    }
}

void tampilTertinggi(int nilai[10], int sessNilai[10], string sessNama[10]){
    cout << "=====================================================" << endl;
    cout << "Nilai UTS Tertinggi : " << nilai[9] << endl;
    for (int i = 0; i < 10; i++){
        if (nilai[9] == sessNilai[i]){
            cout << endl;
            cout << "Absen ke-" << i + 1 << endl;
            cout << "Nama Mahasiswa : " << sessNama[i] << endl;
            cout << "Nilai          : " << sessNilai[i] << endl;
            cout << "Berada di Index ke-" << i << endl;
            cout << "nilaiAlprog[" << i << "] dan namaMHS[" << i << "]" << endl;
        }
    }
    cout << endl;
    cout << "=====================================================" << endl;
}

int main(){
    string namaMHS[10], sessionNama[10], nullNilai[10], nullCari;
    int nilaiAlprog[10], sessionNilai[10], cariNilai;
    char pilih;
    bool tidakDitemukan = false;

    cout << "=============== Sistem Input Nilai Algoritma dan Pemrograman ===============" << endl << endl;
    cout << "Selamat Datang Civitas Akademika UNSIKA." << endl;
    cout << "Sistem  ini digunakan untuk  meng-input" << endl;
    cout << "Nilai UTS Mata Kuliah Kelas 1B Informatika 2024." << endl << endl;
    cout << "Sistem ini memiliki fitur : " << endl;
    cout << "- Tampil Nilai Tertinggi Mahasiswa" << endl;
    cout << "- Mencari Data Nilai Mahasiswa Berdasarkan Nilai" << endl << endl;
    cout << "Dosen          : Intan Purnamasari, M.Kom" << endl;
    cout << "Asisten Dosen  : Aditya Rizky Darmawan" << endl;
    cout << "Kriteria Nilai : UTS" << endl;
    cout << "Kelas          : 1B Informatika (10 Mahasiswa)" << endl << endl;

    // Mengisi data nilai ke variabel nilaiAlprog
    for (int i = 0; i < 10; i++){
        // perulangan jika input nilai < 0 atau nilai > 100
        cout << "Absen ke-" << i + 1 << endl;
        do {
            cout << "Nama Mahasiswa  : " << endl << "=> ";
            getline(cin, namaMHS[i]);
            if (namaMHS[i] == "") {
                cout << "Nama tidak boleh kosong." << endl << endl;
            }
        } while (namaMHS[i] == "");

        do {
            // agar data nilai dapat dicek jika kosong, maka harus dari string dahulu
            do {
                cout << "Nilai (0 - 100) : " << endl << "=> ";
                getline(cin, nullNilai[i]);
                if (nullNilai[i] == "") {
                    cout << "Nilai tidak boleh kosong." << endl << endl;
                }
            } while (nullNilai[i] == "");

            // konversi string ke integer
            nilaiAlprog[i] = stoi(nullNilai[i]);

            if (nilaiAlprog[i] < 0 || nilaiAlprog[i] > 100){
                cout << endl << "Mohon input nilai 0 - 100" << endl << endl;
            }
        } while (nilaiAlprog[i] < 0 || nilaiAlprog[i] > 100);
        cout << endl;
    }

    /* Menyimpan susunan awal nilai ke variabel sessionNilai sebelum diurutkan
    untuk mengambil index array saat nilai yang dicari user ada */
    for (int i = 0; i < 10; i++){
        sessionNilai[i] = nilaiAlprog[i];
        sessionNama[i] = namaMHS[i];
    }

    // mengurutkan nilai dari terkecil ke terbesar
    kecilKeTerbesar(nilaiAlprog, namaMHS);
    // jika tak pakai function
    /* for (int i = 0; i < 5 - 1; i++){
        for (int j = 0; j < 5 - i - 1; j++){
            if (nilaiAlprog[j] > nilaiAlprog[j + 1]){
                int n = nilaiAlprog[j];
                nilaiAlprog[j] = nilaiAlprog[j + 1];
                nilaiAlprog[j + 1] = n;

                string m = namaMHS[j];
                namaMHS[j] = namaMHS[j + 1];
                namaMHS[j + 1] = m;
            }
        }
    } */

    // menampilkan nilai tertinggi
    tampilTertinggi(nilaiAlprog, sessionNilai, sessionNama);
    // jika tak pakai function
    /*
    cout << "=====================================================" << endl;
    cout << "Nilai UTS Tertinggi : " << nilaiAlprog[4] << endl;
    for (int i = 0; i < 5; i++){
        if (nilaiAlprog[4] == sessionNilai[i]){
            cout << endl;
            cout << "Absen ke-" << i + 1 << endl;
            cout << "Nama Mahasiswa : " << sessionNama[i] << endl;
            cout << "Nilai          : " << sessionNilai[i] << endl;
            cout << "Berada di Index ke-" << i << endl;
            cout << "nilaiAlprog[" << i << "] dan namaMHS[" << i << "]" << endl;
        }
    }
    cout << endl;
    cout << "=====================================================" << endl; */

    do {
        do {
            tidakDitemukan = false;
            do {
                cout << "\nCari data berdasarkan Nilai (1-100) : ";
;               getline(cin, nullCari);

                if (nullCari == ""){
                    cout << "Nilai tidak boleh kosong." << endl;
                }
            } while (nullCari == "");

            cariNilai = stoi(nullCari);

            if (cariNilai < 0 || cariNilai > 100){
                cout << endl << "Mohon input nilai 0 - 100" << endl;
            }
        } while (cariNilai < 0 || cariNilai > 100);

        for (int i = 0; i < 10; i++){
            if (cariNilai == sessionNilai[i]){
                cout << endl << "Data Nilai " << cariNilai << " Ditemukan!" << endl;
                tidakDitemukan = true;
                break;
            }
        }

        if (tidakDitemukan == false){
            cout << endl << "Data Nilai " << cariNilai << " Tidak Ada!" << endl;
        }

        for (int i = 0; i < 10; i++){
            if (cariNilai == sessionNilai[i]){
                cout << endl;
                cout << "Absen ke-" << i + 1 << endl;
                cout << "Nama Mahasiswa : " << sessionNama[i] << endl;
                cout << "Nilai          : " << sessionNilai[i] << endl;
                cout << "Berada di Index ke-" << i << endl;
                cout << "nilaiAlprog[" << i << "] dan namaMHS[" << i << "]" << endl;
            }
        }

        do {
            cout << endl << "Apakah ingin mencari data kembali? (y/n)\n=> ";
            cin >> pilih;

            if (pilih != 'y' && pilih != 'Y' && pilih != 'n' && pilih != 'N'){
                cout << "Pilihan tidak valid! Mohon Input Kembali." << endl;
            }
            cin.ignore();
        } while (pilih != 'y' && pilih != 'Y' && pilih != 'n' && pilih != 'N');

    } while (pilih == 'y' || pilih == 'Y');

    cout << endl << "Anda keluar dari program. Terima Kasih" << endl;

    return 0;
}

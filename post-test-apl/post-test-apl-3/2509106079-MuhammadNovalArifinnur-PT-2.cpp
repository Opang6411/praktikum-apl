#include <iostream>
using namespace std;

// Struct
struct Barang {
    string nama;
    string lokasi;
};


// Fungsi Tampilkan Data
void lihatBarang(Barang barang[], int jumlah) {
    cout << "\nDaftar Barang\n";
    for(int i = 0; i < jumlah; i++) {
        cout << i+1 << ". " << barang[i].nama << " - " << barang[i].lokasi << endl;
    }
}


// Fungsi Menambah Barang
void tambahBarang(Barang barang[], int &jumlah) {
    cout << "Nama Barang: ";
    getline(cin, barang[jumlah].nama);

    cout << "Lokasi Ditemukan: ";
    getline(cin, barang[jumlah].lokasi);

    jumlah++;
}


// Fungsi Edit Barang
void editBarang(Barang barang[], int jumlah) {
    int edit;

    lihatBarang(barang, jumlah);

    cout << "Pilih nomor barang: ";
    cin >> edit;
    cin.ignore();

    cout << "Nama baru: ";
    getline(cin, barang[edit-1].nama);

    cout << "Lokasi baru: ";
    getline(cin, barang[edit-1].lokasi);
}


// Fungsi Hapus Barang
void hapusBarang(Barang barang[], int &jumlah) {
    int hapus;

    lihatBarang(barang, jumlah);

    cout << "Pilih nomor barang: ";
    cin >> hapus;
    cin.ignore();

    for(int i = hapus-1; i < jumlah; i++) {
        barang[i] = barang[i+1];
    }

    jumlah--;
}


//Fungsi Login Admin
bool loginAdmin() {
    string user, pass;
    int kesempatan = 2;

    while(kesempatan >= 0) {
        cout << "\nLogin Admin\n";
        cout << "Username: ";
        getline(cin, user);

        cout << "Password: ";
        getline(cin, pass);

        if(user == "Muhammad Noval Arifinnur" && pass == "079") {
            return true;
        }
        else if(kesempatan == 0) {
            return 0;
        }
        else {
            kesempatan--;
            cout << "Login salah! Sisa kesempatan: " << kesempatan+1 << endl;
        }
    }

    return false;
}


// Fungsi Menu Admin
void menuAdmin(Barang barang[], int &jumlah) {
    string menuAdmin = "0";

    while(menuAdmin != "5") {

        cout << "\n===== MENU ADMIN =====\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Lihat Barang\n";
        cout << "3. Edit Barang\n";
        cout << "4. Hapus Barang\n";
        cout << "5. Kembali\n";
        cout << "Pilih: ";
        getline(cin, menuAdmin);

        if(menuAdmin == "1") {
            tambahBarang(barang, jumlah);
        }
        else if(menuAdmin == "2") {
            lihatBarang(barang, jumlah);
        }
        else if(menuAdmin == "3") {
            editBarang(barang, jumlah);
        }
        else if(menuAdmin == "4") {
            hapusBarang(barang, jumlah);
        }
        else {
            cout << "Pilihan tidak valid";
        }
    }
}


// Fungsi Menu User
void menuUser(Barang barang[], int &jumlah) {
    string menuUser = "0";

    while(menuUser != "3") {

        cout << "\n===== MENU PENGGUNA =====\n";
        cout << "1. Lihat Barang\n";
        cout << "2. Laporkan Barang Hilang\n";
        cout << "3. Kembali\n";
        cout << "Pilih: ";
        getline(cin, menuUser);

        if(menuUser == "1") {
            lihatBarang(barang, jumlah);
        }
        else if(menuUser == "2") {
            cout << "Nama Barang Hilang: ";
            getline(cin, barang[jumlah].nama);

            cout << "Lokasi Terakhir: ";
            getline(cin, barang[jumlah].lokasi);

            jumlah++;
            cout << "Laporan berhasil ditambahkan.\n";
        }
    }
}


// Main Code
int main() {

    Barang barang[100];
    int jumlah = 0;
    string menuAwal = "0";

    while(menuAwal != "3") {

        cout << "\n===== LOST AND FOUND =====\n";
        cout << "1. Login Admin\n";
        cout << "2. Pengguna\n";
        cout << "3. Keluar\n";
        cout << "Pilih: ";
        getline(cin, menuAwal);

        if(menuAwal == "1") {
            if(loginAdmin()) {
                menuAdmin(barang, jumlah);
            }
        }
        else if(menuAwal == "2") {
            menuUser(barang, jumlah);
        }
    }
}
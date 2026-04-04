#include <iostream>
using namespace std;

// Struct
struct Barang {
    string nama;
    string lokasi;
};

// Tampilkan Data
void lihatBarang(Barang *barang, int jumlah) {
    if(jumlah == 0) {
        cout << "Data kosong.\n";
        return;
    }

    cout << "\nDaftar Barang\n";
    for(int i = 0; i < jumlah; i++) {
        cout << i+1 << ". " << barang[i].nama 
            << " - " << barang[i].lokasi << endl;
    }
}

// Tambah Barang
void tambahBarang(Barang *barang, int *jumlah) {
    cout << "Nama Barang: ";
    getline(cin, barang[*jumlah].nama);

    cout << "Lokasi Ditemukan: ";
    getline(cin, barang[*jumlah].lokasi);

    (*jumlah)++;
}

// Edit Barang
void editBarang(Barang *barang, int jumlah) {
    if(jumlah == 0) {
        cout << "Data kosong.\n";
        return;
    }

    int edit;
    lihatBarang(barang, jumlah);

    cout << "Pilih nomor barang: ";
    cin >> edit;
    cin.ignore();

    if(edit < 1 || edit > jumlah) {
        cout << "Tidak valid!\n";
        return;
    }

    cout << "Nama baru: ";
    getline(cin, barang[edit-1].nama);

    cout << "Lokasi baru: ";
    getline(cin, barang[edit-1].lokasi);
}

// Hapus Barang
void hapusBarang(Barang *barang, int *jumlah) {
    if(*jumlah == 0) {
        cout << "Data kosong.\n";
        return;
    }

    int hapus;
    lihatBarang(barang, *jumlah);

    cout << "Pilih nomor barang: ";
    cin >> hapus;
    cin.ignore();

    if(hapus < 1 || hapus > *jumlah) {
        cout << "Tidak valid!\n";
        return;
    }

    for(int i = hapus-1; i < (*jumlah)-1; i++) {
        barang[i] = barang[i+1];
    }

    (*jumlah)--;
}

// Login Admin
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
        } else {
            if(kesempatan == 0) {
                return false;
            }
            cout << "Salah! Sisa: " << kesempatan << endl;
            kesempatan--;
        }
    }
    return false;
}

// Menu Admin
void menuAdmin(Barang *barang, int *jumlah) {
    string menu = "0";

    while(menu != "5") {
        cout << "\n===== MENU ADMIN =====\n";
        cout << "1. Tambah\n2. Lihat\n3. Edit\n4. Hapus\n5. Kembali\n";
        cout << "Pilih: ";
        getline(cin, menu);

        if(menu == "1") {
            tambahBarang(barang, jumlah);
        }
        else if(menu == "2") {
            lihatBarang(barang, *jumlah);
        }
        else if(menu == "3") {
            editBarang(barang, *jumlah);
        }
        else if(menu == "4") {
            hapusBarang(barang, jumlah);
        }
    }
}

// Menu User
void menuUser(Barang *barang, int *jumlah) {
    string menu = "0";

    while(menu != "3") {
        cout << "\n===== MENU USER =====\n";
        cout << "1. Lihat\n2. Lapor\n3. Kembali\n";
        cout << "Pilih: ";
        getline(cin, menu);

        if(menu == "1") {
            lihatBarang(barang, *jumlah);
        }
        else if(menu == "2") {
            cout << "Nama Barang: ";
            getline(cin, barang[*jumlah].nama);

            cout << "Lokasi: ";
            getline(cin, barang[*jumlah].lokasi);

            (*jumlah)++;
        }
    }
}

// Main
int main() {
    Barang barang[100];
    int jumlah = 0;
    string menu = "0";

    while(menu != "3") {
        cout << "\n===== LOST AND FOUND =====\n";
        cout << "1. Admin\n2. User\n3. Keluar\n";
        cout << "Pilih: ";
        getline(cin, menu);

        if(menu == "1") {
            if(loginAdmin()) {
                menuAdmin(barang, &jumlah); 
            }
        }
        else if(menu == "2") {
            menuUser(barang, &jumlah); 
        }
    }
}
#include <iostream>
using namespace std;

// Struct
struct Barang {
    int id;
    string nama;
    string lokasi;
};

// FUNGSI TAMPIL 
void lihatBarang(Barang *barang, int jumlah) {
    if(jumlah == 0) {
        cout << "Data kosong.\n";
        return;
    }

    cout << "\nDaftar Barang\n";
    for(int i = 0; i < jumlah; i++) {
        cout << i+1 << ". ID: " << barang[i].id
            << " | " << barang[i].nama 
            << " - " << barang[i].lokasi << endl;
    }
}

// FUNGSI TAMBAH 
void tambahBarang(Barang *barang, int *jumlah) {
    cout << "ID Barang: ";
    cin >> barang[*jumlah].id;
    cin.ignore();

    cout << "Nama Barang: ";
    getline(cin, barang[*jumlah].nama);

    cout << "Lokasi Ditemukan: ";
    getline(cin, barang[*jumlah].lokasi);

    (*jumlah)++;
}

// FUNGSI EDIT 
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

    cout << "ID baru: ";
    cin >> barang[edit-1].id;
    cin.ignore();

    cout << "Nama baru: ";
    getline(cin, barang[edit-1].nama);

    cout << "Lokasi baru: ";
    getline(cin, barang[edit-1].lokasi);
}

// FUNGSI HAPUS 
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

// FUNGSI-FUNGSI SORTING

// 1. Bubble Sort (Nama Ascending)
void sortNamaAsc(Barang *barang, int jumlah) {
    for(int i = 0; i < jumlah-1; i++) {
        for(int j = 0; j < jumlah-i-1; j++) {
            if(barang[j].nama > barang[j+1].nama) {
                swap(barang[j], barang[j+1]);
            }
        }
    }
    cout << "Sorting Nama Ascending berhasil!\n";
}

// 2. Selection Sort (ID Descending)
void sortIdDesc(Barang *barang, int jumlah) {
    for(int i = 0; i < jumlah-1; i++) {
        int maxIdx = i;
        for(int j = i+1; j < jumlah; j++) {
            if(barang[j].id > barang[maxIdx].id) {
                maxIdx = j;
            }
        }
        swap(barang[i], barang[maxIdx]);
    }
    cout << "Sorting ID Descending berhasil!\n";
}

// 3. Insertion Sort (Lokasi Ascending)
void sortLokasiAsc(Barang *barang, int jumlah) {
    for(int i = 1; i < jumlah; i++) {
        Barang key = barang[i];
        int j = i - 1;

        while(j >= 0 && barang[j].lokasi > key.lokasi) {
            barang[j+1] = barang[j];
            j--;
        }
        barang[j+1] = key;
    }
    cout << "Sorting Lokasi Ascending berhasil!\n";
}

// FUNGSI LOGIN
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
            if(kesempatan == 0) return false;
            cout << "Salah! Sisa: " << kesempatan << endl;
            kesempatan--;
        }
    }
    return false;
}

// FUNGSI MENU ADMIN 
void menuAdmin(Barang *barang, int *jumlah) {
    string menu = "0";

    while(menu != "8") {
        cout << "\n===== MENU ADMIN =====\n";
        cout << "1. Tambah\n2. Lihat\n3. Edit\n4. Hapus\n";
        cout << "5. Sort Nama (Asc)\n6. Sort ID (Desc)\n7. Sort Lokasi (Asc)\n8. Kembali\n";
        cout << "Pilih: ";
        getline(cin, menu);

        if(menu == "1") tambahBarang(barang, jumlah);
        else if(menu == "2") lihatBarang(barang, *jumlah);
        else if(menu == "3") editBarang(barang, *jumlah);
        else if(menu == "4") hapusBarang(barang, jumlah);
        else if(menu == "5") sortNamaAsc(barang, *jumlah);
        else if(menu == "6") sortIdDesc(barang, *jumlah);
        else if(menu == "7") sortLokasiAsc(barang, *jumlah);
    }
}

// FUNGSI MENU USER 
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
            cout << "ID Barang: ";
            cin >> barang[*jumlah].id;
            cin.ignore();

            cout << "Nama Barang: ";
            getline(cin, barang[*jumlah].nama);

            cout << "Lokasi: ";
            getline(cin, barang[*jumlah].lokasi);

            (*jumlah)++;
        }
    }
}

// FUNGSI MAIN 
int main() {
    Barang barang[100];
    int jumlah = 10;
    string menu = "0";

    // ===== DATA AWAL (ID 1–10) =====
    barang[0] = {1, "Dompet", "Kantin"};
    barang[1] = {2, "HP Samsung", "Kelas A"};
    barang[2] = {3, "Kunci Motor", "Parkiran"};
    barang[3] = {4, "Tas Hitam", "Perpustakaan"};
    barang[4] = {5, "Botol Minum", "Lapangan"};
    barang[5] = {6, "Helm", "Parkiran"};
    barang[6] = {7, "Jam Tangan", "Kelas B"};
    barang[7] = {8, "Charger", "Ruang Lab"};
    barang[8] = {9, "Sepatu", "Mushola"};
    barang[9] = {10, "Kacamata", "Aula"};

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
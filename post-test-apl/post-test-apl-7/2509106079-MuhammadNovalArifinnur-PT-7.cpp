#include <iostream>
using namespace std;

// Struct
struct Barang {
    int id;
    string nama;
    string lokasi;
};

// VALIDASI INPUT ANGKA
void inputID(int &id) {
    while(true) {
        try {
            if(!(cin >> id)) {
                throw "Input harus angka!";
            }
            cin.ignore();
            break;
        }
        catch(const char* msg) {
            cout << msg << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Coba lagi: ";
        }
    }
}

// TAMPIL
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

// TAMBAH
void tambahBarang(Barang *barang, int *jumlah) {
    if(*jumlah >= 100) {
        cout << "Data penuh!\n";
        return;
    }

    cout << "ID Barang: ";
    inputID(barang[*jumlah].id);

    cout << "Nama Barang: ";
    getline(cin, barang[*jumlah].nama);

    cout << "Lokasi: ";
    getline(cin, barang[*jumlah].lokasi);

    (*jumlah)++;
}

// EDIT
void editBarang(Barang *barang, int jumlah) {
    try {
        if(jumlah == 0) throw "Data kosong!";

        int edit;
        lihatBarang(barang, jumlah);

        cout << "Pilih nomor: ";
        inputID(edit);

        if(edit < 1 || edit > jumlah) {
            throw "Pilihan tidak valid!";
        }

        cout << "ID baru: ";
        inputID(barang[edit-1].id);

        cout << "Nama baru: ";
        getline(cin, barang[edit-1].nama);

        cout << "Lokasi baru: ";
        getline(cin, barang[edit-1].lokasi);
    }
    catch(const char* msg) {
        cout << msg << endl;
    }
}

// HAPUS
void hapusBarang(Barang *barang, int *jumlah) {
    try {
        if(*jumlah == 0) throw "Data kosong!";

        int hapus;
        lihatBarang(barang, *jumlah);

        cout << "Pilih nomor: ";
        inputID(hapus);

        if(hapus < 1 || hapus > *jumlah) {
            throw "Pilihan tidak valid!";
        }

        char konfirmasi;
        cout << "Yakin hapus? (y/n): ";
        cin >> konfirmasi;
        cin.ignore();

        if(konfirmasi != 'y' && konfirmasi != 'Y') return;

        for(int i = hapus-1; i < (*jumlah)-1; i++) {
            barang[i] = barang[i+1];
        }

        (*jumlah)--;
    }
    catch(const char* msg) {
        cout << msg << endl;
    }
}

// SORTING
void sortNamaAsc(Barang *barang, int jumlah) {
    for(int i = 0; i < jumlah-1; i++) {
        for(int j = 0; j < jumlah-i-1; j++) {
            if(barang[j].nama > barang[j+1].nama) {
                swap(barang[j], barang[j+1]);
            }
        }
    }
    cout << "Sorting Nama ASC berhasil\n";
}

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
    cout << "Sorting ID DESC berhasil\n";
}

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
    cout << "Sorting Lokasi ASC berhasil\n";
}

// SORT ID ASC (untuk binary)
void sortIdAsc(Barang *barang, int jumlah) {
    for(int i = 0; i < jumlah-1; i++) {
        for(int j = 0; j < jumlah-i-1; j++) {
            if(barang[j].id > barang[j+1].id) {
                swap(barang[j], barang[j+1]);
            }
        }
    }
}

// ===== SEARCHING =====

// Linear Search (Nama)
void cariNama(Barang *barang, int jumlah) {
    string cari;
    cout << "Masukkan nama barang: ";
    getline(cin, cari);

    bool ketemu = false;

    for(int i = 0; i < jumlah; i++) {
        if(barang[i].nama == cari) {
            cout << "Ditemukan -> ID: " << barang[i].id
                << " | Lokasi: " << barang[i].lokasi << endl;
            ketemu = true;
        }
    }

    if(!ketemu) cout << "Tidak ditemukan\n";
}

// Binary Search (ID)
void cariIdBinary(Barang *barang, int jumlah) {
    int cari;
    cout << "Masukkan ID: ";
    inputID(cari);

    sortIdAsc(barang, jumlah);

    int kiri = 0, kanan = jumlah - 1;
    bool ketemu = false;

    while(kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;

        if(barang[tengah].id == cari) {
            cout << "Ditemukan -> Nama: " << barang[tengah].nama
                << " | Lokasi: " << barang[tengah].lokasi << endl;
            ketemu = true;
            break;
        }
        else if(cari < barang[tengah].id) {
            kanan = tengah - 1;
        }
        else {
            kiri = tengah + 1;
        }
    }

    if(!ketemu) cout << "Tidak ditemukan\n";
}

// LOGIN
bool loginAdmin() {
    string user, pass;
    int kesempatan = 2;

    string adminUser = "Muhammad Noval Arifinnur";
    string adminPass = "079";

    while(kesempatan >= 0) {
        try {
            cout << "\nLogin Admin\n";
            cout << "Username: ";
            getline(cin, user);

            cout << "Password: ";
            getline(cin, pass);

            if(user != adminUser || pass != adminPass) {
                throw "Username atau Password salah!";
            }

            return true;
        }
        catch(const char* msg) {
            if(kesempatan == 0) {
                cout << msg << endl;
                return false;
            }
            cout << msg << " Sisa: " << kesempatan << endl;
            kesempatan--;
        }
    }
    return false;
}

// MENU ADMIN
void menuAdmin(Barang *barang, int *jumlah) {
    string menu = "0";

    while(menu != "10") {
        try {
            cout << "\n===== MENU ADMIN =====\n";
            cout << "1. Tambah\n2. Lihat\n3. Edit\n4. Hapus\n";
            cout << "5. Sort Nama\n6. Sort ID Desc\n7. Sort Lokasi\n";
            cout << "8. Cari Nama\n9. Cari ID (Binary)\n10. Kembali\n";
            cout << "Pilih: ";
            getline(cin, menu);

            if(menu < "1" || menu > "10") {
                throw "Menu tidak tersedia!";
            }

            if(menu == "1") tambahBarang(barang, jumlah);
            else if(menu == "2") lihatBarang(barang, *jumlah);
            else if(menu == "3") editBarang(barang, *jumlah);
            else if(menu == "4") hapusBarang(barang, jumlah);
            else if(menu == "5") sortNamaAsc(barang, *jumlah);
            else if(menu == "6") sortIdDesc(barang, *jumlah);
            else if(menu == "7") sortLokasiAsc(barang, *jumlah);
            else if(menu == "8") cariNama(barang, *jumlah);
            else if(menu == "9") cariIdBinary(barang, *jumlah);
        }
        catch(const char* msg) {
            cout << msg << endl;
        }
    }
}

// MENU USER
void menuUser(Barang *barang, int *jumlah) {
    string menu = "0";

    while(menu != "3") {
        try {
            cout << "\n===== MENU USER =====\n";
            cout << "1. Lihat\n2. Lapor\n3. Kembali\n";
            cout << "Pilih: ";
            getline(cin, menu);

            if(menu < "1" || menu > "3") {
                throw "Menu tidak tersedia!";
            }

            if(menu == "1") lihatBarang(barang, *jumlah);
            else if(menu == "2") {
                if(*jumlah >= 100) throw "Data penuh!";

                cout << "ID Barang: ";
                inputID(barang[*jumlah].id);

                cout << "Nama Barang: ";
                getline(cin, barang[*jumlah].nama);

                cout << "Lokasi: ";
                getline(cin, barang[*jumlah].lokasi);

                (*jumlah)++;
            }
        }
        catch(const char* msg) {
            cout << msg << endl;
        }
    }
}

// MAIN
int main() {
    Barang barang[100];
    int jumlah = 10;
    string menu = "0";

    // DATA AWAL
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
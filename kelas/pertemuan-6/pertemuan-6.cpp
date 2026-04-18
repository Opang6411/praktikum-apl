#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
    srand(time(0));

    int saldo = 500000;
    int taruhan , tebakan;
    float kaliMenang = 0.0, kaliKalah = 0.0;

    cout << "=== SIMULASI JUDI NOMOR ===" << endl;
    cout << "=== INI HANYA SIMULASI SUPAYA ORANG BERHENTI MAIN JUDI! ===" << endl;

    while (saldo > 0) { 
        cout << "\nSaldo Anda: Rp" << saldo << " | Menang: " << kaliMenang << " | Kalah: " << kaliKalah << endl;
        cout << "Pasang taruhan (Ketik 0 untuk membatalkan): " << endl;
        cin >> taruhan;

        if (taruhan == 0) break; //Kalau mau berhenti main
        if (taruhan > saldo){
            cout << "Saldo Anda tidak cukup!" << endl;
            continue;
        }
        cout << "Pilih Nomor (1-10): ";
        cin >> tebakan;

        int hasil =  rand() % 10 + 1; // Untuk menghitung angka yg keluar nantinya
        cout << "Nomor keluar: " << hasil << endl;

        if (tebakan == hasil){
            saldo += (taruhan*9);
            kaliMenang++;
            cout << "GACOR!!! Bandar lagi baik nih!" << endl;
        } else{
            saldo -= taruhan;
            kaliKalah++;
            cout << "KASIAN DEH LO! Donasi ke Bandar" << endl;
        }
    }
    cout << "\n=== LAPORAN AKHIR ===" << endl; //Jika saldo habis atau berhenti main
    cout << "Total Menang: " << kaliMenang << endl;
    cout << "Total Kalah: " << kaliKalah << endl;
    cout << "Persentase kamu menang: " << kaliMenang/kaliKalah*100 << " %" << endl;
    cout << "Sisa saldo: Rp" << saldo << endl;

    if (kaliKalah > kaliMenang){
        cout << "Secara statistik, kamu rugi!" << endl;
    }
    cout << endl;

    return 0;
}
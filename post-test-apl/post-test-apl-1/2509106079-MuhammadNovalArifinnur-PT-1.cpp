#include <iostream>
using namespace std;



int main()
{
    for (int i = 1; i <=3; i++){
    string inputnama;
    string inputpass;

    cout << "Masukkan Nama : ";
    getline (cin,inputnama);
    cout << "Masukkan Password : ";
    getline (cin,inputpass);

    if (inputnama == "Muhammad Noval Arifinnur" && inputpass == "079")
    {
        while (true){
        long nilai, meter_ke_cm, km_ke_meter, km_ke_cm;
        double cm_ke_km, meter_ke_km, cm_ke_meter;
        int inputpil;
        cout << "Sistem Konversi Nilai Kilometer, Meter, dan Centimeter" << endl;
        cout << "Silahkan pilih satuan untuk di konversi(1, 2, atau 3)" << endl;
        cout << "1. Kilometer" <<endl;
        cout << "2. Meter" << endl;
        cout << "3. Centimeter" << endl;
        cout << "4. Keluar" << endl;
        cout << "Masukkan Pilihan : ";
        cin >> inputpil;

        if (inputpil==1){
            cout << "Masukkan nilai kilometer(angka) : ";
            cin >> nilai;
            km_ke_meter = nilai*1000;
            km_ke_cm = nilai*100000;
            cout << "Ke meter ="; cout << km_ke_meter << "M" << endl;
            cout << "Ke centimeter ="; cout << km_ke_cm << "CM" <<endl;
        }
        else if (inputpil==2){
            cout << "Masukkan nilai meter(angka) : ";
            cin >> nilai;
            meter_ke_km = nilai/1000.0;
            meter_ke_cm = nilai*100;
            cout << "Ke kilometer ="; cout << meter_ke_km << "KM"<< endl;
            cout << "Ke centimeter ="; cout << meter_ke_cm << "CM" << endl;
        }
        else if (inputpil==3){
            cout << "Masukkan nilai centimeter(angka) : ";
            cin >> nilai;
            cm_ke_km = nilai/100000.0;
            cm_ke_meter = nilai/100.0;
            cout << "Ke kilometer ="; cout << cm_ke_km << "KM" << endl;
            cout << "Ke meter ="; cout << cm_ke_meter << "M" << endl;
        }
        else if (inputpil==4){
            cout << "Terima Kasih telah menggunakan program ini" << endl;
            return 0;
        }
        else{
            cout << "Sepertinya ada kesalahan pada input. Coba lagi" << endl;
        }
    }
    }
    else {
        cout << "Maaf Nama atau Password Salah" << endl;
    }
    }
cout << "Maaf percobaan login telah habis";

    return 0;
}


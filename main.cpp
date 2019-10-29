#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

vector<string> Monster {"Monster Api", "Monster Pohon", "Monster BatuApi", "Robot Listrik"};
vector<int> Demage_Monster {20, 25, 30, 35};
vector<string> Senjata {"Pistol Air", "Pistol Api", "Katana", "Hammer", "Pistol Magma"};
vector<int> Demage_S_Api {25, 5, 5, 5, 10};
vector<int> Demage_S_Kayu {5, 25, 15, 10, 25};
vector<int> Demage_S_Batu {10, 5, 10, 25, 30};
vector<int> Demage_S_Besi {10, 15, 5, 25, 30};
vector<int> MedKit {100};
vector<int> Inventory {11};
vector<int> Alat_Aktif {11};
vector<int>::iterator penunjuk;
int level = 1;
int jmlInv = 2;

void Peralatan(int i){
    if( i > 20){
        i = i - 21;
        cout <<"MedKit " << MedKit[i] << " HP" << endl;
    }else if(i > 10){
        i = i - 11;
        cout <<"Senjata " << Senjata[i] << endl;
        cout <<"      Demage : Api " << Demage_S_Api[i] << " | Kayu "<< Demage_S_Kayu[i] << " | Batu " << Demage_S_Batu[i] << " | Besi "<< Demage_S_Besi[i] << endl;
    }
}

void Data_Inventory(){
    cout << "==================INVENTORY==================Jumlah "<< Inventory.size() << " | Slot Kosong " << (jmlInv - Inventory.size())  << endl;
    int no = 1;
    cout << "__________________________________________________________________________\n" << endl;
    for(penunjuk = Inventory.begin(); penunjuk != Inventory.end(); ++penunjuk){
        cout << "[ " << no << " ] ";
        Peralatan(*penunjuk);
        no++;
        cout << "__________________________________________________________________________\n" << endl;
    }
}

void Data_Senjata(){
    int temp;
    int no = 1;
    for(penunjuk = Inventory.begin(); penunjuk != Inventory.end(); ++penunjuk){
        if(*penunjuk > 10 && *penunjuk < 20){
            cout << "[ " << no << " ] ";
            temp = *penunjuk;
            temp = temp - 11;
            cout <<"Senjata " << Senjata[temp] << endl;
        }
        no++;
    }
}

void Data_MedKit(){
    int temp;
    int no = 1;
    for(penunjuk = Inventory.begin(); penunjuk != Inventory.end(); ++penunjuk){
        if(*penunjuk > 20 && *penunjuk < 30){
            cout << "[ " << no << " ] ";
            temp = *penunjuk;
            temp = temp - 21;
            cout <<"MedKit " << MedKit[temp] << " HP" << endl;
        }
        no++;
    }
}


int val_Alat_Aktif(int data){
    for(penunjuk = Alat_Aktif.begin(); penunjuk != Alat_Aktif.end(); ++penunjuk){
        if(*penunjuk == data){
            return 1;
        }
    }
    return 0;
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    string nama;
    int no;
    int pilih1, pilih1_1, pilih_Inv, pilih_serangan;
    char ulang1 = 'Y', ulang1_1 = 'Y';
    int TempInt, TempInt2;
    char TempChar;
    int TempSerangan;
    int DarahKamu = 100, TempDK;
    int DarahMusuh;
    int random;
    cout << "==========Selamat Datang Di Game Batle Element==========" << endl;
    cout << "Silahkan Masukkan Nama Anda " << endl;
    cout << "Nama = ";
    cin >>nama;



    cout << "\nHai " << nama << endl;
    cout << "Disini Kamu Akan Menjadi Pahlawan Pembasmi Kejahatan\n" << endl;
    while(ulang1 == 'Y'){
        ulang1_1 = 'Y';
        cout << "=============MENU UTAMA============"<< endl;
        cout << "1. Inventori                      |" << endl;
        for(TempInt = 2; TempInt <= (level+1); TempInt++){
                cout << TempInt << ". Mainkan Game Level "<< TempInt-1 <<"           |" << endl;
        }
        cout << "0. Tutup Game                     |" << endl;
        cout << "__________________________________|" << endl;
        cout << "Pilihan ? ";
        cin >> pilih1;
        if(pilih1 == 1){
            while(ulang1_1 == 'Y'){
                cout << "\n" << endl;
                if(Inventory.size() == 0){
                    cout << "Inventory Masih Kosong \n" << endl;
                }else{
                    Data_Inventory();
                }
                cout << "=============MENU INVENTORI============"<< endl;
                cout << "1. Tambah Inventori                   |" << endl;
                cout << "2. Hapus Inventori                    |" << endl;
                cout << "0. Kembali Ke Menu Utama              |" << endl;
                cout << "______________________________________|" << endl;
                cout << "Pilihan ? ";
                cin >> pilih1_1;
                if(pilih1_1 == 1){
                    if(Inventory.size() >= jmlInv){
                        cout << "\nInventory Penuh" << endl;
                    }else{
                        cout << "\n==================================Peralatan=============================="<< endl;
                        no = 1;
                        cout << "__________________________________________________________________________\n" << endl;
                        for(penunjuk = Alat_Aktif.begin(); penunjuk != Alat_Aktif.end(); ++penunjuk){
                            cout << "[ " << no << " ] ";
                            Peralatan(*penunjuk);
                            no++;
                            cout << "__________________________________________________________________________\n" << endl;
                        }
                        cout << "Pilih Peralatan Yang Ingin Dimasukkan Ke Inventori" << endl;
                        cout << "Pilihan ? ";
                        cin >> pilih_Inv;
                        if(pilih_Inv > Alat_Aktif.size() || pilih_Inv < 1){
                            cout << "\nPilihan Alat Salah\n" << endl;
                        }else{
                            TempInt = 0;
                            for(penunjuk = Inventory.begin(); penunjuk != Inventory.end(); ++penunjuk){
                                if(*penunjuk == Alat_Aktif[(pilih_Inv-1)]){
                                    TempInt = 1;
                                    cout << *penunjuk << Alat_Aktif[pilih_Inv]<< endl;
                                }
                            }
                            if(TempInt == 1){
                                cout << "\nAlat Sudah Ada Di Inventori" << endl;
                            }else{
                                Inventory.push_back(Alat_Aktif[(pilih_Inv-1)]);
                                cout << "\nAlat Berhasil Ditambahkan Di Inventori"<< endl;
                            }
                        }

                    }
                }else if(pilih1_1 == 2){
                    if(Inventory.size() == 0){
                        cout << "Inventory Masih Kosong" << endl;
                    }else{
                        cout << "Hapus Inventory Yang Ke : ";
                        cin >> TempInt;
                        if(TempInt > Inventory.size() || TempInt < 1){
                            cout << "\nPilihan Hapus Inventory Salah" << endl;
                        }else{
                            Inventory.erase(Inventory.begin()+(TempInt-1));
                            cout << "\nBerhasil Menghapus Inventory" << endl;
                        }

                    }
                }else if(pilih1_1 == 0){
                    ulang1_1 = 'N';
                    cout << endl;
                }
            }
        }else if(pilih1 >= 2 && pilih1 <= 5 && (pilih1-1) <= level){
            TempInt2 = 0;
            cout << "\nBersiaplah...\nDi Level " << (pilih1 - 1) << " Ini Kamu Akan Menghadapi "<< Monster[(pilih1 - 2)] << endl;
            cout << "Isi Dari Inventori Kamu Yang Akan Digunakan Untuk Menghadapi Monster Ini\n" << endl;
            Data_Inventory();
            cout << "Lanjutkan Y/N ?";
            cin >> TempChar;
            if(TempChar == 'Y' || TempChar == 'y'){
                cout <<"\n\nMusuh Kamu " << Monster[(pilih1 - 2)] << " Sudah Ada Di Depanmu" << endl;
                TempDK = DarahKamu;
                DarahMusuh = 100;
                no = 1;
                while(TempDK > 0 && DarahMusuh > 0){
                    cout << "\n\n==========================================================================="<<endl;
                    cout << "Darah Kamu " << TempDK << "                                 Darah Musuh "<< DarahMusuh << endl << endl;
                    if(no %2 != 0){
                        cout << "Serang Musuh / Lakukan Penyembuhan" << endl;
                        Data_Senjata();
                        if(TempInt2 == 0){
                            Data_MedKit();
                        }
                        cout << "Pilihan ?";
                        cin >> pilih_serangan;
                        TempInt = Inventory[(pilih_serangan-1)];
                        if(pilih_serangan < 1 || pilih_serangan > Inventory.size()){
                            cout << "Kamu Salah Memilih Pilihan" << endl;
                        }else if(TempInt > 20){
                            if(TempInt2 == 0){
                                TempInt = TempInt - 21;
                                TempInt = MedKit[TempInt];
                                TempDK = TempDK  + TempInt;
                                cout << "Nyawa Kamu Bertambah " << TempInt << endl;
                                TempInt2 = 1;
                            }else{
                                cout << "Kamu Salah Memilih Pilihan" << endl;
                            }
                        }else{
                            TempInt = TempInt - 11;
                            if((pilih1 - 1) == 1){
                                TempSerangan = Demage_S_Api[(TempInt)];
                            }else if((pilih1 - 1) == 2){
                                TempSerangan = Demage_S_Kayu[(TempInt)];
                            }else if((pilih1 - 1) == 3){
                                TempSerangan = Demage_S_Batu[(TempInt)];
                            }else{
                                TempSerangan = Demage_S_Besi[(TempInt)];
                            }
                            DarahMusuh = DarahMusuh - TempSerangan;
                            cout << "Nyawa Musuh Berkurang " << TempSerangan << endl;
                        }
                    }else{
                        cout << Monster[(pilih1 - 2)] << " Menyerang Kamu, Dan Kamu Terkena Serangannya" << endl;
                        TempDK = TempDK - Demage_Monster[(pilih1 - 2)];
                        cout << "Nyawa Kamu Berkurang "<< Demage_Monster[(pilih1 - 2)] << endl;
                    }
                    no++;
                    cout << "==========================================================================="<<endl<<endl;
                }
                if(TempDK <= 0){
                    cout << "\nKAMU KALAH\n" << endl;
                }else{
                    cout << "\nSELAMAT "<< nama <<" KAMU BERHASIL MENGALAHKAN "<< Monster[(pilih1 - 2)] << endl;
                    cout << "BONUS : " << endl;
                    if((pilih1 - 1) == 1){
                        random = 2;
                    }else if((pilih1 - 1) == 2){
                        random = rand() % 2 + 3;
                    }else{
                        random = rand() % 2 + 4;
                    }
                    random = random + 10;
                    TempInt = val_Alat_Aktif(random);
                    if(TempInt == 0){
                        Alat_Aktif.push_back(random);
                    }
                    cout << "1. ";
                    Peralatan(random);
                    random = 1;
                    random = random + 20;
                    TempInt = val_Alat_Aktif(random);
                    if(TempInt == 0){
                        Alat_Aktif.push_back(random);
                    }
                    cout << "2. ";
                    Peralatan(random);
                    cout << endl << endl;
                    if(level == 4){

                    }else if(level == (pilih1 - 1)){
                        level = level + 1;
                        jmlInv = jmlInv + 1;
                    }
                }
            }
        }else if(pilih1 == 0){
            ulang1 = 'N';
            cout << "...................................................................."<< endl;
        }else{

        }
    }
    cout << "Thank You" << endl;
    return 0;
}

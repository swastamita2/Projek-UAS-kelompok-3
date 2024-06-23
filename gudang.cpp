	//NB: //Usernam = Kelompok3 (K besar), pw= 123
	#include <iostream> // Digunakan untuk menjalankan perintah input dan output, seperti cin, cout.
	#include <conio.h>  // Digunakan untuk antarmuka dengan pengguna, seperti getch
	#include <iomanip>  // Digunakan untuk manipulasi I/O seperti setw
	#include <cstring>  // Digunakan untuk operasi pada string (strcpy)
	
	using namespace std; // Menggunakan skope std sebagai nama skope untuk penggunaan instruksi, misalnya std::cin std::cout 
	
	// Struktur data untuk menyimpan informasi barang
	typedef struct {
	    int kode;         // Kode barang
	    char nama[20];    // Nama barang
	    int stock;        // Stok barang
	    char lokasi[20];  // Lokasi penyimpanan barang
	} brg;
	
	// Deklarasi array barang dan variabel pendukung
	brg barang[5];
	brg temp;
	int n;
	
	// Fungsi untuk membersihkan layar
	void clearScreen() {
	    system("cls"); // Digunakan untuk membersihkan layar output
	}
	
	// Fungsi untuk input data barang
	void inputBarang() {
	    char yn;
	    do {
	        clearScreen(); // Membersihkan layar setiap kali memasukkan data
	        cout << "\nMasukkan Banyak Data = ";
	        cin >> n; // Memasukkan jumlah data yang akan dimasukkan
	        cin.ignore(); // Membersihkan buffer untuk menghindari masalah pada getline
	
	        for (int i = 0; i < n; i++) {
	            cout << endl;
	            cout << " Data ke-" << (i + 1) << ":" << endl;
	            cout << " Input Kode Sepatu  : ";
	            cin >> barang[i].kode; // Memasukkan kode sepatu
	            cin.ignore(); // Membersihkan buffer
	            cout << " Input Nama Sepatu  : ";
	            cin.getline(barang[i].nama, 20); // Memasukkan nama sepatu
	            cout << " Input Stock Sepatu : ";
	            cin >> barang[i].stock; // Memasukkan stok sepatu
	            cin.ignore(); // Membersihkan buffer
	            cout << " Input Lokasi Sepatu: ";
	            cin.getline(barang[i].lokasi, 20); // Memasukkan lokasi sepatu
	            cout << endl;
	        }
	
	        cout << "Apakah Anda Ingin Menambahkan Data Lagi ? (y/n) :";
	        cin >> yn; // Menanyakan apakah ingin menambahkan data lagi
	        cin.ignore(); // Membersihkan buffer
	
	    } while (yn == 'y' || yn == 'Y'); // Mengulang jika jawaban adalah y atau Y
	}
	
	// Fungsi untuk menampilkan data barang
	void tampilBarang() {
	    clearScreen(); // Membersihkan layar sebelum menampilkan data
	    cout << "\nDaftar Sepatu Anda:\n";
	    cout << "+------------+--------------------+-------------+--------------------+\n";
	    cout << "| Kode Sepatu| Nama Sepatu        | Stock Sepatu| Lokasi Sepatu      |\n";
	    cout << "+------------+--------------------+-------------+--------------------+\n";
	
	    for (int j = 0; j < n; j++) { // Menampilkan data barang dalam tabel
	        cout << "| " << setw(10) << barang[j].kode 
	             << " | " << setw(18) << barang[j].nama 
	             << " | " << setw(11) << barang[j].stock 
	             << " | " << setw(18) << barang[j].lokasi << " |\n";
	    }
	
	    cout << "+------------+--------------------+-------------+--------------------+\n";
	
	    system("pause"); // Menunggu pengguna menekan tombol sebelum melanjutkan
	}
	
	// Fungsi untuk mengurutkan data barang berdasarkan kode menggunakan Bubble Sort
	void urutBarang() {
	    clearScreen(); // Membersihkan layar sebelum mengurutkan data
	    for (int i = 0; i < n; i++) { // Loop untuk melakukan Bubble Sort
	        for (int j = 0; j < n - 1; j++) {
	            if (barang[j].kode > barang[j + 1].kode) { // Jika kode barang saat ini lebih besar dari berikutnya, tukar
	                temp = barang[j];
	                barang[j] = barang[j + 1];
	                barang[j + 1] = temp;
	            }
	        }
	    }
	
	    cout << "\nSetelah Diurutkan Berdasarkan Kode Terkecil:\n";
	    cout << "+------------+--------------------+-------------+--------------------+\n";
	    cout << "| Kode Sepatu| Nama Sepatu        | Stock Sepatu| Lokasi Sepatu      |\n";
	    cout << "+------------+--------------------+-------------+--------------------+\n";
	
	    for (int j = 0; j < n; j++) { // Menampilkan data yang telah diurutkan
	        cout << "| " << setw(10) << barang[j].kode 
	             << " | " << setw(18) << barang[j].nama 
	             << " | " << setw(11) << barang[j].stock 
	             << " | " << setw(18) << barang[j].lokasi << " |\n";
	    }
	
	    cout << "+------------+--------------------+-------------+--------------------+\n";
	
	    system("pause"); // Menunggu pengguna menekan tombol sebelum melanjutkan
	}
	
	// Fungsi untuk mencari data barang berdasarkan kode
	void cariBarang() {
	    clearScreen(); // Membersihkan layar sebelum melakukan pencarian
	    int cari, ada;
	    char yn;
	    do {
	        ada = 0; // Mengatur indikator ditemukan menjadi 0
	        cout << "Masukkan Kode Barang Untuk Mencari :";
	        cin >> cari; // Memasukkan kode barang yang ingin dicari
	
	        for (int j = 0; j < n; j++) { // Mencari barang berdasarkan kode
	            if (barang[j].kode == cari) { // Jika ditemukan, tampilkan data barang
	                ada = 1; // Mengatur indikator ditemukan menjadi 1
	                cout << "+------------+--------------------+-------------+--------------------+\n";
	                cout << "| Kode Sepatu| Nama Sepatu        | Stock Sepatu| Lokasi Sepatu      |\n";
	                cout << "+------------+--------------------+-------------+--------------------+\n";
	                cout << "| " << setw(10) << barang[j].kode 
	                     << " | " << setw(18) << barang[j].nama 
	                     << " | " << setw(11) << barang[j].stock 
	                     << " | " << setw(18) << barang[j].lokasi << " |\n";
	                cout << "+------------+--------------------+-------------+--------------------+\n";
	                break; // Keluar dari loop jika barang ditemukan
	            }
	        }
	
	        if (ada == 0) { // Jika barang tidak ditemukan
	            cout << " Data Tidak Ditemukan" << endl;
	        }
	
	        cout << "Apakah Anda Ingin Mencari Data Lagi ? (y/n) :";
	        cin >> yn; // Menanyakan apakah ingin mencari data lagi
	        cin.ignore(); // Membersihkan buffer
	
	    } while (yn == 'y' || yn == 'Y'); // Mengulang jika jawaban adalah y atau Y
	}
	
	// Fungsi utama
	int main() {
	    clearScreen(); // Membersihkan layar
	
	    int pil;
	    char ch;
	
	    // Membuat username dan password
	login:
	    string user = "";
	    string pass = "";
	    cout << "\n\n\n\n\n\n\n\n";
	    cout << "\t\t ------- Program Aplikasi Sederhana Gudang Sorting PT Sepatu Mas Indonesia--------\n\n";
	    cout << "\t\t\t  Username : "; cin >> user; // Memasukkan username
	    cout << "\t\t\t  Password : ";
	    ch = _getch(); // Membaca karakter tanpa menampilkannya di layar
	    while (ch != 13) { // Karakter 13 adalah enter
	        pass.push_back(ch); // Menambahkan karakter ke password
	        cout << '*'; // Menampilkan '*' sebagai pengganti karakter yang dimasukkan
	        ch = _getch(); // Membaca karakter berikutnya
	    }
	    cout << endl;
	
	    // Memeriksa username dan password
	    if (user == "Kelompok3" && pass == "123") { // Validasi username dan password
	        cout << "\n\n Anda berhasil login. \n" << endl;
	        system("pause"); // Menunggu pengguna menekan tombol
	        clearScreen(); // Membersihkan layar
	    } else { // Jika username atau password salah
	        cout << " Password Anda Salah \n";
	        system("pause"); // Menunggu pengguna menekan tombol
	        clearScreen(); // Membersihkan layar
	        goto login; // Kembali ke login
	    }
	
	    // End membuat username dan password
	
	    // Menampilkan menu utama
	    while (true) {
	        clearScreen(); // Membersihkan layar setiap kali menampilkan menu
	        cout << "---- Aplikasi Sederhana Gudang Sorting PT Sepatu Mas Indonesia ----" << endl;
	        cout << "-------- Menu ----------\n";
	        cout << " 1. Input Barang       \n";
	        cout << " 2. Daftar Barang       \n";
	        cout << " 3. Pengurutan     \n";
	        cout << " 4. Pencarian  \n";
	        cout << " 5. Exit                \n";
	        cout << "----------------------\n";
	        cout << "Masukan Pilihan anda [1 s.d. 5] = ";
	        cin >> pil; // Memasukkan pilihan menu
	
	        switch (pil) { // Menjalankan fungsi sesuai pilihan
	            case 1:
	                inputBarang(); // Memanggil fungsi inputBarang
	                break;
	            case 2:
	                tampilBarang(); // Memanggil fungsi tampilBarang
	                break;
	            case 3:
	                urutBarang(); // Memanggil fungsi urutBarang
	                break;
	            case 4:
	                cariBarang(); // Memanggil fungsi cariBarang
	                break;
	            case 5:
	                cout << "-- Anda Telah Logout -- \n";
	                cout << "-- Program Aplikasi Sederhana Gudang Sorting PT Sepatu Mas Indonesia --\n";
	                system("pause"); // Menunggu pengguna menekan tombol
	                clearScreen(); // Membersihkan layar
	                goto login; // Kembali ke login
	            default:
	                cout << "Pilihan tidak valid. Coba lagi." << endl;
	                system("pause"); // Menunggu pengguna menekan tombol
	                break;
	        }
	    }
	
	    return 0; // Mengakhiri program
	}


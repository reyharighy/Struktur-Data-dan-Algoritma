/*
    File ini digunakan sebagai antarmuka untuk seluruh subProgram yang ada di dalam Chapter Antrian (Queue). Setiap objek kelas 
    yang dideklarasikan di dalam file ini menyediakan berbagai fungsi spesifik yang dienkapsulasi untuk melakukan aktivitas pengoperasian 
    atau manipulasi data beserta attribute members yang diperlukan.
*/

#ifndef QUEUE_CHAPTER
#define QUEUE_CHAPTER

#include "../Program Interface Files/programInterface.hpp"
#include "../Custom Utility Files/customUtility.hpp"

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Deklarasi awal untuk objek kelas dengan nama tugas Implementasi Antrian dengan Array Terbatas.
----------------------------------------------------------------------------------------------------------------------------------------*/

class QueueTwoOne: public Program {
private:
    bool isCapacitySet {false}; // Inisialisasi variabel boolean untuk mengecek apakah kapasitas sudah di-set atau belum
    int capacity {0}; // Inisialisasi variabel untuk mengecek kapasitas antrian
    int filledCapacity {0}; // Inisialisasi variabel untuk mengecek kapasitas yang sudah terisi
    std::string invalidIntInput;
    std::string* arrayPointer = nullptr; // Pointer untuk menunjuk ke array yang menyimpan data
    void menuInterface();
    void push();
    void flush ();

public:
    void start() override; // Metode polymorphism untuk menjalankan program
    ~QueueTwoOne(); // Destructor untuk mencegah memory leaks pada variabel "arrayPointer"
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 2: Deklarasi awal untuk objek kelas dengan nama tugas Implementasi Antrian dengan Array Terbatas dan Proses Penyisipan Data.
----------------------------------------------------------------------------------------------------------------------------------------*/

class QueueTwoTwo: public Program {
private:
    bool isCapacitySet {false}; // Inisialisasi variabel boolean untuk mengecek apakah kapasitas sudah di-set atau belum
    int capacity {0}; // Inisialisasi variabel untuk mengecek kapasitas antrian
    int filledCapacity {0}; // Inisialisasi variabel untuk mengecek kapasitas yang sudah terisi
    std::string invalidIntInput;
    std::string* arrayPointer = nullptr; // Pointer untuk menunjuk ke array yang menyimpan data
    void menuInterface();
    void push();
    void pop();
    void display();

public:
    void start() override; // Metode polymorphism untuk menjalankan program
    ~QueueTwoTwo(); // Destructor untuk mencegah memory leaks pada variabel "arrayPointer"
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 2.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 3: Deklarasi awal untuk objek kelas dengan nama tugas Implementasi Antrian dengan Array Terbatas dan Proses Penyisipan Data.
----------------------------------------------------------------------------------------------------------------------------------------*/

class QueueTwoThree: public Program {
private:
    int filledNumber {0}; // Inisialisasi variabel untuk mengecek jumlah data yang sudah terisi
    std::string invalidIntInput;
    std::vector<std::string> array {}; // Inisialisasi vector untuk menyimpan data
    void menuInterface();
    void push();
    void pop();
    void display();

public:
    void start() override; // Metode polymorphism untuk menjalankan program
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 3.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 4: Deklarasi awal untuk objek kelas dengan nama tugas Implementasi linked list untuk mencari data.
----------------------------------------------------------------------------------------------------------------------------------------*/

class QueueTwoFour: public Program {
private:
    class linkedList { // Kelas untuk menyimpan data yang akan dicari
    public:
        std::string dataCodename, theData;
        linkedList(std::string dataCodenameInput, std::string theDataInput) : dataCodename(dataCodenameInput), theData(theDataInput) {}
    };
    int filledNumber {0}; // Inisialisasi variabel untuk mengecek jumlah data yang sudah terisi
    std::string invalidIntInput;
    std::vector<linkedList> array; // Inisialisasi vector untuk menyimpan data
    void menuInterface();
    void push();
    void pop();
    void find();
    void display();

public:
    void start() override; // Metode polymorphism untuk menjalankan program
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 4.
----------------------------------------------------------------------------------------------------------------------------------------*/

#endif
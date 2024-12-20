/*
    File ini digunakan sebagai antarmuka untuk seluruh subProgram yang ada di dalam Chapter Tumpukan (Stack). Setiap objek kelas 
    yang dideklarasikan di dalam file ini menyediakan berbagai fungsi spesifik yang dienkapsulasi untuk melakukan aktivitas pengoperasian 
    atau manipulasi data beserta attribute members yang diperlukan.
*/

#ifndef STACK_CHAPTER
#define STACK_CHAPTER

#include "../Program Interface Files/programInterface.hpp"
#include "../Custom Utility Files/customUtility.hpp"
#include <cmath>

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Deklarasi awal untuk objek kelas dengan nama tugas Konversi Bilangan Biner Bilangan Basis Lain.
----------------------------------------------------------------------------------------------------------------------------------------*/

class StackOneOne: public Program {
private:
    std::string invalidIntInput, invalidFloatInput;
    double decimalValue; // Inisialisasi variabel untuk menyimpan nilai desimal
    bool isDecimalSet {false}; // Inisialisasi variabel boolean untuk mengecek apakah nilai decimal sudah di-set atau belum
    std::vector<short> stack {}; // Inisialisasi vector untuk menyimpan hasil konversi
    std::map<short, std::string> hexadecimalAlpha {{10, "A"}, {11, "B"}, {12, "C"}, {13, "D"}, {14, "E"}, {15, "F"}}; // Inisialisasi map untuk konversi ke hexadecimal
    void menuInterface();
    void setDecimalValue();
    void calculateConversion(const short);

public:
    void start() override; // Metode polymorphism untuk menjalankan program
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 2: Deklarasi awal untuk objek kelas dengan nama tugas Implementasi Tumpukan dengan Array Terbatas.
----------------------------------------------------------------------------------------------------------------------------------------*/

class StackOneTwo: public Program {
private:
    bool isCapacitySet {false};
    int capacity {0}; // Inisialisasi variabel untuk mengecek kapasitas tumpukan
    int filledCapacity {0}; // Inisialisasi variabel untuk mengecek kapasitas yang sudah terisi
    std::string invalidIntInput;
    std::string* stackPointer = nullptr; // Pointer untuk menunjuk ke array yang menyimpan data
    void menuInterface();
    void push();
    void flush();

public:
    void start() override; // Metode polymorphism untuk menjalankan program
    ~StackOneTwo(); // Destructor untuk mencegah memory leaks pada variabel "stackPointer"
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 2.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 3: Deklarasi awal untuk objek kelas dengan nama tugas Implementasi Tumpukan dengan Array Dinamis.
----------------------------------------------------------------------------------------------------------------------------------------*/

class StackOneThree: public Program {
private:
    int filledNumber {0}; // Inisialisasi variabel untuk mengecek jumlah data yang sudah terisi
    std::string invalidIntInput;
    std::vector<std::string> stack {}; // Inisialisasi vector untuk menyimpan data
    void menuInterface();
    void push();
    void flush();

public:
    void start() override; // Metode polymorphism untuk menjalankan program
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 3.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 4: Deklarasi awal untuk objek kelas dengan nama tugas Implementasi Tumpukan untuk Pembalikan String.
----------------------------------------------------------------------------------------------------------------------------------------*/

class StackOneFour: public Program {
private:
    std::string invalidIntInput;
    std::vector<char> stack {}; // Inisialisasi vector untuk menyimpan data
    void menuInterface();
    void getReversedInput();

public:
    void start() override; // Metode polymorphism untuk menjalankan program
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 4.
----------------------------------------------------------------------------------------------------------------------------------------*/

#endif

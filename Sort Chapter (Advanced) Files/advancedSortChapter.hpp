/*
    File ini digunakan sebagai antarmuka untuk seluruh subProgram yang ada di dalam Chapter Urutan Tingkat Lanjut (Advanced Sort). Setiap objek 
    kelas yang dideklarasikan di dalam file ini menyediakan berbagai fungsi spesifik yang dienkapsulasi untuk melakukan aktivitas pengoperasian 
    atau manipulasi data beserta attribute members yang diperlukan.
*/

#ifndef SORT_CHAPTER_ADVANCED
#define SORT_CHAPTER_ADVANCED

#include "../Program Interface Files/programInterface.hpp"
#include "../Custom Utility Files/customUtility.hpp"

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Deklarasi awal untuk objek kelas dengan nama tugas mengurutkan data menggunakan In Place Sort.
----------------------------------------------------------------------------------------------------------------------------------------*/

class SortFiveOne: public Program {
private:
    std::string invalidIntInput;
    std::vector<long> array, arrayClone {}; // Inisialisasi vector untuk menyimpan data integer
    std::vector<std::string> arrayString, arrayStringClone {}; // Inisialisasi vector untuk menyimpan data string
    void inPlaceSort(std::vector<long>& array, bool ascending) { // Fungsi untuk mengurutkan data integer secara in-place
        std::cout << "Data sebelum diurutkan: " << array << std::endl;
        for (int i = array.size() - 1; i >= 0; i--) {
            int k = i;
            bool swap = false;
            for (int j = 0; j < i; j++) {
                if ((ascending && array[j] > array[k]) || (!ascending && array[j] < array[k])) {
                    k = j;
                    swap = true;
                }
            }
            if (swap) {
                std::swap(array[i], array[k]);
                std::cout << array << " => " << array[i] << " bertukar dengan " << array[k];
            } else {
                std::cout << array << " => Tidak ada pertukaran";
            }
            std::cout << std::endl;
        }
        std::cout << "Data setelah diurutkan: " << array << std::endl;
    }

    void inPlaceSortString(std::vector<std::string>& arrayString, bool ascending) { // Fungsi untuk mengurutkan data string secara in-place
        std::cout << "Data sebelum diurutkan: " << arrayString << std::endl;
        for (int i = arrayString.size() - 1; i >= 0; i--) {
            int k = i;
            bool swap = false;
            for (int j = 0; j < i; j++) {
                if ((ascending && arrayString[j] > arrayString[k]) || (!ascending && arrayString[j] < arrayString[k])) {
                    k = j;
                    swap = true;
                }
            }
            if (swap) {
                std::swap(arrayString[i], arrayString[k]);
                std::cout << arrayString << " => " << arrayString[i] << " bertukar dengan " << arrayString[k];
            } else {
                std::cout << arrayString << " => Tidak ada pertukaran";
            }
            std::cout << std::endl;
        }
        std::cout << "Data setelah diurutkan: " << arrayString << std::endl;
    }
    void menuInterface();
    void sort();
    void preview();
    void del();
    void push();
public:
    void start() override; // Metode polymorphism untuk menjalankan program
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 2: Deklarasi awal untuk objek kelas dengan nama tugas mengurutkan data menggunakan Shell Sort.
----------------------------------------------------------------------------------------------------------------------------------------*/

class SortFiveTwo: public Program {
private:
    std::string invalidIntInput;
    std::vector<long> array, arrayClone {}; // Inisialisasi vector untuk menyimpan data integer
    std::vector<std::string> arrayString, arrayStringClone {}; // Inisialisasi vector untuk menyimpan data string
    void shellSort(std::vector<long>& array, bool ascending) { // Fungsi untuk mengurutkan data integer menggunakan Shell Sort
        std::cout << "Data sebelum diurutkan: " << array << std::endl;
        int gap = 1;
        while (gap < array.size() / 3) {
            gap = 3 * gap + 1; // Menghitung nilai awal gap sesuai dengan rumus 3h + 1
        }
        while (gap > 0) {
            for (int i = gap; i < array.size(); i++) {
                int k = i;
                bool swap = false;
                while (k >= gap && ((ascending && array[k - gap] > array[k]) || (!ascending && array[k - gap] < array[k]))) {
                    std::swap(array[k], array[k - gap]);
                    k -= gap;
                    swap = true;
                }
                if (gap == 1) {
                    std::cout << "gap = " << gap << " : ";
                    for (int j = 0; j < array.size(); j++) {
                        std::cout << array[j];
                        if (j < array.size() - 1) std::cout << " - ";
                    }
                    std::cout << " => ";
                    if (swap) {
                        std::cout << array[k] << " pindah ke depan " << array[k + gap];
                    } else {
                        std::cout << "Tidak ada pertukaran";
                    }
                    std::cout << std::endl;
                } else {
                    std::cout << "gap = " << gap << " : ";
                    for (int j = 0; j < array.size(); j++) {
                        std::cout << array[j];
                        if (j < array.size() - 1) std::cout << " - ";
                    }
                    std::cout << " => ";
                    if (swap) {
                        std::cout << array[k + gap] << " bertukar dengan " << array[k];
                    } else {
                        std::cout << "Tidak ada pertukaran";
                    }
                    std::cout << std::endl;
                }
            }
            gap /= 3;
        }
        std::cout << "Data setelah diurutkan: " << array << std::endl;
    }
    
    void shellSortString(std::vector<std::string>& arrayString, bool ascending) { // Fungsi untuk mengurutkan data string menggunakan Shell Sort
        std::cout << "Data sebelum diurutkan: " << arrayString << std::endl;
        int gap = 1;
        while (gap < arrayString.size() / 3) {
            gap = 3 * gap + 1; // Menghitung nilai awal gap sesuai dengan rumus 3h + 1
        }
        while (gap > 0) {
            for (int i = gap; i < arrayString.size(); i++) {
                int k = i;
                bool swap = false;
                while (k >= gap && ((ascending && arrayString[k - gap] > arrayString[k]) || (!ascending && arrayString[k - gap] < arrayString[k]))) {
                    std::swap(arrayString[k], arrayString[k - gap]);
                    k -= gap;
                    swap = true;
                }
                if (gap == 1) {
                    std::cout << "gap = " << gap << " : ";
                    for (int j = 0; j < arrayString.size(); j++) {
                        std::cout << arrayString[j];
                        if (j < arrayString.size() - 1) std::cout << " - ";
                    }
                    std::cout << " => ";
                    if (swap) {
                        std::cout << arrayString[k] << " pindah ke depan " << arrayString[k + gap];
                    } else {
                        std::cout << "Tidak ada pertukaran";
                    }
                    std::cout << std::endl;
                } else {
                    std::cout << "gap = " << gap << " : ";
                    for (int j = 0; j < arrayString.size(); j++) {
                        std::cout << arrayString[j];
                        if (j < arrayString.size() - 1) std::cout << " - ";
                    }
                    std::cout << " => ";
                    if (swap) {
                        std::cout << arrayString[k + gap] << " bertukar dengan " << arrayString[k];
                    } else {
                        std::cout << "Tidak ada pertukaran";
                    }
                    std::cout << std::endl;
                }
            }
            gap /= 3;
        }
        std::cout << "Data setelah diurutkan: " << arrayString << std::endl;
    }
    void menuInterface();
    void sort();
    void preview();
    void del();
    void push();
public:
    void start() override; // Metode polymorphism untuk menjalankan program
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 2.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 3: Deklarasi awal untuk objek kelas dengan nama tugas mengurutkan data menggunakan Merge Sort.
----------------------------------------------------------------------------------------------------------------------------------------*/

class SortFiveThree: public Program {
private:
    void menuInterface();
    void sort();
    void preview();
    void del();
    void push();
public:
    void start() override; // Metode polymorphism untuk menjalankan program
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 3.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 4: Deklarasi awal untuk objek kelas dengan nama tugas mengurutkan data menggunakan Quick Sort.
----------------------------------------------------------------------------------------------------------------------------------------*/

class SortFiveFour: public Program {
private:
    void menuInterface();
    void sort();
    void preview();
    void del();
    void push();
public:
    void start() override; // Metode polymorphism untuk menjalankan program
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 4.
----------------------------------------------------------------------------------------------------------------------------------------*/

#endif
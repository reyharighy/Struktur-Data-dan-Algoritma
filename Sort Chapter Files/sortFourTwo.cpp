/*
    File ini berisi implementasi dari berbagai fungsi yang dideklarasikan di dalam file "sortChapter.hpp" untuk tugas dengan nama
    mengurutkan data menggunakan Insertion Sort. 
*/

#include "sortChapter.hpp"

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Fungsi "menuInterface" bertujuan untuk menampilkan daftar proses pengoperasian atau manipulasi yang bisa dilakukan
    terhadap data dalam lingkup dari program yang ditentukan.
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourTwo::menuInterface() {
    std::cout << "\n\nPilih menu untuk pengoperasian pada sort:\n"
              << "  1. Masukkan data baru\n  2. Urutkan data\n  3. Lihat Program-program lain\n => ";
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 2: Fungsi "push" bertujuan untuk menyisipkan data baru ke dalam tipe data collections sesuai urutan abjad yang disertai dengan 
    beberapa skenario error handling sesuai dengan prasyarat yang ditentukan di dalam program.
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourTwo::push() {
    std::cout << "Masukan data baru => ";
    std::string theData {titleCase()}; // Akses ke fungsi PART 5 dari "customUtility.hpp"

    if (theData.empty()) { // Data baru tidak valid jika input kosong
        std::cout << "<Tidak ada data baru yang dimasukan>";
    } else {
        bool isLast {true};

        for (size_t i = 0; i < array.size(); i++) {
            if (theData.compare(array[i]) < 0) {
                if (array.size() == 1) {
                    array.push_back(array[i]);
                } else {
                    array.push_back(array[array.size() - 1]);

                    for (size_t j = array.size() - 1; j > i; j--) {
                        array[j] = array[j - 1];
                    }
                }

                array[i] = theData;
                isLast = false;
                break;
            }
        }

        if (isLast) {
            array.push_back(theData);
        }

        filledNumber++;
        std::cout << "<Data " << '"' << theData << '"' << " berhasil ditambahkan>";
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 2.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 3: Fungsi "sort" bertujuan untuk mengurutkan semua data menggunakan teknik pengurutan Insertion Sort.
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourTwo::sort() {

}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 3.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 4: Fungsi "start" adalah implementasi metode polymorphism untuk menjalankan program sesuai dengan logis yang ditampilkan
    oleh standard output dari "menuInterface".
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourTwo::start() {
    while (true) {
        menuInterface();
        short menuChosen {short(inputIntValidator(&invalidIntInput))}; // Akses ke fungsi PART 2 dari "customUtility.hpp"

        if (menuChosen >= 1 && menuChosen <= 3) {
            if (menuChosen == 1) {
                push();
            } else if (menuChosen == 2) {
                sort();
            } else {
                break;
            }
        } else {
            invalidMenuChosen(&menuChosen, &invalidIntInput); // Akses ke fungsi PART 4 dari "customUtility.hpp"
        }

        outputBuffer(); // Akses ke fungsi PART 3 dari "customUtility.hpp"
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE PART 4.
----------------------------------------------------------------------------------------------------------------------------------------*/
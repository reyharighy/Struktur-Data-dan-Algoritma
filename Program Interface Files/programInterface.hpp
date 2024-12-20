/*
    File ini digunakan sebagai antarmuka untuk memudahkan proses penjelajahan ke berbagai subprogram dari seluruh chapter yang 
    ditugaskan pada mata pelajaran ini. Berperan juga sebagai base class untuk seluruh derived class yang menjalankan tiap subprogram. 
    Dengan kata lain, juga berperan dalam menyediakan fungsi abstraksi dalam menjalankan tiap fungsi yang tersedia.
*/

#ifndef PROGRAM_INTERFACE_H
#define PROGRAM_INTERFACE_H

#include <iostream>
#include <string>
#include <map>
#include <memory>

/*----------------------------------------------------------------------------------------------------------------------------------
    PART 1: Deklarasi awal dari objek Program dalam menjalankan setiap subprogram pada tiap chapter. Definisi tiap fungsi ada
    di file "programInterface.cpp".
----------------------------------------------------------------------------------------------------------------------------------*/

class Program { 
public:
    virtual void start() = 0; // Metode polymorphism untuk menjalankan tiap program derived class
    short taskList(const short*); // Definisi ada di PART 1
    bool subProgramSelection(const short*, std::string*, std::map<const short, Program*>*); // Definisi ada di PART 2
};

/*----------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------*/

#endif

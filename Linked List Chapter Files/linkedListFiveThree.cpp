#include <iostream>
#include <string>
#include "implementations.hpp"
#include "linkedlist.hpp"
#include "declaration.hpp"

namespace LinkedListChapter {
    namespace QueueDemo {
        void display(Implementations::Queue<std::string> q) {
            auto output = q;
            if (output.isEmpty()) {
                std::cout << "(kosong)";
            }
            while (!output.isEmpty()) {
                std::cout << output.dequeue() << "; ";
            }
        }

        int demo() {
            std::cout << "Masukkan banyaknya anggota maks.: ";
            size_t size;
            std::cin >> size;
            auto q{Implementations::Queue<std::string>(size)};

            while (true) {
                std::cout << "Anggota antrian: ";
                display(q);
                std::cout << "\n[(1) Tambah | (2) Ambil | (3) Keluar]: ";
                int choice;
                std::cin >> choice;
                switch (choice) {
                    case 1: {
                        std::cin.ignore();
                        std::string input;

                        std::cout << "Masukkan data: ";
                        std::getline(std::cin, input);
                        try {
                            q.enqueue(input);
                        } catch (const std::out_of_range& e) {
                            std::cout << "Antrian penuh.\n";
                        }
                        break;
                    }
                    case 2: {
                        try {
                            std::string data = q.dequeue();
                            std::cout << "Data yang diambil: " << data << "\n";
                        }
                        catch (const std::out_of_range& e) {
                            std::cout << "Antrian kosong.\n";
                        }
                        break;
                    }
                    case 3:
                        return 0;
                        break;
                    default:
                        break;
                }
            }
            return 0;
        }   
    }
}
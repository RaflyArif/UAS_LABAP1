#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

struct Note {
    int id;
    std::string title;
    std::string content;
};

std::vector<Note> notes;
int nextNoteId = 1;

void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void createNote() {
    Note note;
    note.id = nextNoteId++;
    std::cout << "Masukkan judul note: ";
    std::getline(std::cin, note.title);

    std::cout << "Masukkan konten note: ";
    std::getline(std::cin, note.content);

    notes.push_back(note);
    std::cout << "Note berhasil dibuat!" << std::endl;
}

void displayNotes() {
    if (notes.empty()) {
        std::cout << "Tidak ada notes ditemukan." << std::endl;
        return;
    }

    std::cout << "------ Notes ------" << std::endl;
    for (const auto& note : notes) {
        std::cout << "ID: " << note.id << std::endl;
        std::cout << "Judul: " << note.title << std::endl;
        std::cout << "Konten: " << note.content << std::endl;
        std::cout << "-------------------" << std::endl;
    }
}

void viewNote() {
    if (notes.empty()) {
        std::cout << "Tidak ada notes ditemukan." << std::endl;
        return;
    }

    int id;
    std::cout << "EnMasukkan ID Note yang ingin dilihat: ";
    while (!(std::cin >> id) || id < 1) {
        clearInputBuffer();
        std::cout << "Invalid input. Masukkan ID bilangan integer positif: ";
    }
    clearInputBuffer();

    auto it = std::find_if(notes.begin(), notes.end(), [&id](const Note& note) {
        return note.id == id;
    });

    if (it != notes.end()) {
        std::cout << "------ Note ------" << std::endl;
        std::cout << "ID: " << it->id << std::endl;
        std::cout << "Judul: " << it->title << std::endl;
        std::cout << "Konten: " << it->content << std::endl;
        std::cout << "-------------------" << std::endl;
    } else {
        std::cout << "Note tidak ditemukan." << std::endl;
    }
}

void updateNote() {
    if (notes.empty()) {
        std::cout << "Tidak ada notes ditemukan." << std::endl;
        return;
    }

    int id;
    std::cout << "Masukkan ID Note yang ingin diubah: ";
    while (!(std::cin >> id) || id < 1) {
        clearInputBuffer();
        std::cout << "Invalid input. Masukkan ID bilangan integer positif: ";
    }
    clearInputBuffer();

    auto it = std::find_if(notes.begin(), notes.end(), [&id](const Note& note) {
        return note.id == id;
    });

    if (it != notes.end()) {
        std::cout << "Masukkan konten baru: ";
        std::getline(std::cin, it->content);
        std::cout << "Note berhasil diupdate!" << std::endl;
    } else {
        std::cout << "Note tidak ditemukan." << std::endl;
    }
}

void deleteNote() {
    if (notes.empty()) {
        std::cout << "Tidak ada notes ditemukan" << std::endl;
        return;
    }

    int id;
    std::cout << "Masukkan ID yang ingin dihapus: ";
    while (!(std::cin >> id) || id < 1) {
        clearInputBuffer();
        std::cout << "Invalid input. Masukkan bilangan integer positif ID: ";
    }
    clearInputBuffer();

    auto it = std::find_if(notes.begin(), notes.end(), [&id](const Note& note) {
        return note.id == id;
    });

    if (it != notes.end()) {
        notes.erase(it);
        std::cout << "Sukses hapus note!" << std::endl;
    } else {
        std::cout << "Note tidak ditemukan." << std::endl;
    }
}

int main() {
    int choice;

    do {
        std::cout << "------ Menu ------" << std::endl;
        std::cout << "1. Buat note" << std::endl;
        std::cout << "2. Lihat semua notes" << std::endl;
        std::cout << "3. Lihat note" << std::endl;
        std::cout << "4. Update note" << std::endl;
        std::cout << "5. Hapus note" << std::endl;
        std::cout << "6. Keluar" << std::endl;
        std::cout << "------------------" << std::endl;
        std::cout << "Masukkan Pilihan (1-6): ";

        while (!(std::cin >> choice) || choice < 1 || choice > 6) {
            clearInputBuffer();
            std::cout << "Invalid input. Mohon masukkan nomor antara 1 sampai 6: ";
        }
        clearInputBuffer();

        switch (choice) {
            case 1:
                createNote();
                break;
            case 2:
                displayNotes();
                break;
            case 3:
                viewNote();
                break;
            case 4:
                updateNote();
                break;
            case 5:
                deleteNote();
                break;
            case 6:
                std::cout << "Keluar program!" << std::endl;
                break;
        }
    } while (choice != 6);

    return 0;
}


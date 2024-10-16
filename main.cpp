#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

struct Book {
    std::string title;
    std::string author;
    std::string publication_year;
    std::string genre;

    void display() const {
        std::cout << "Title: " << title << "\n"
                  << "Author: " << author << "\n"
                  << "Year: " << publication_year << "\n"
                  << "Genre: " << genre << "\n";
    }
};

class LibraryManager {
private:
    std::vector<Book> books;

public:
    // Adding a new book
    void addBook(const Book& book) {
        books.push_back(book);
        std::cout << "Book added successfully.\n";
    }

    // Edit a book
    void editBook(int index, const Book& updated_book) {
        if (index >= 0 && index < books.size()) {
            books[index] = updated_book;
            std::cout << "Book updated successfully.\n";
        } else {
            std::cout << "Invalid index.\n";
        }
    }

    // Delete a book
    void deleteBook(int index) {
        if (index >= 0 && index < books.size()) {
            books.erase(books.begin() + index);
            std::cout << "Book deleted successfully.\n";
        } else {
            std::cout << "Invalid index.\n";
        }
    }

    // Search by book title
    void searchByTitle(const std::string& title) const {
        for (const auto& book : books) {
            if (book.title == title) {
                book.display();
            }
        }
    }

    // Sort books by title
    void sortBooksByTitle(bool ascending = true) {
        std::sort(books.begin(), books.end(), [&](const Book& a, const Book& b) {
            return ascending ? a.title < b.title : a.title > b.title;
        });
        std::cout << "Books sorted successfully.\n";
    }

    // Display all books
    void displayAllBooks() const {
        for (const auto& book : books) {
            book.display();
            std::cout << "-------------------------\n";
        }
    }

    // Import books from file
    void importBooks(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            Book book;
            while (file >> book.title >> book.author >> book.publication_year >> book.genre) {
                books.push_back(book);
            }
            file.close();
            std::cout << "Books imported successfully.\n";
        } else {
            std::cout << "Failed to open file.\n";
        }
    }

    // Export books to file
    void exportBooks(const std::string& filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& book : books) {
                file << book.title << " "
                     << book.author << " "
                     << book.publication_year << " "
                     << book.genre << "\n";
            }
            file.close();
            std::cout << "Books exported successfully.\n";
        } else {
            std::cout << "Failed to open file.\n";
        }
    }
};

int main() {
    LibraryManager manager;
    int choice;
    do {
        std::cout << "1. Add Book\n";
        std::cout << "2. Edit Book\n";
        std::cout << "3. Delete Book\n";
        std::cout << "4. Search by Title\n";
        std::cout << "5. Sort Books by Title\n";
        std::cout << "6. Display All Books\n";
        std::cout << "7. Import Books\n";
        std::cout << "8. Export Books\n";
        std::cout << "9. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        if (choice == 1) {
            Book book;
            std::cout << "Enter book title: ";
            std::cin >> book.title;
            std::cout << "Enter book author: ";
            std::cin >> book.author;
            std::cout << "Enter publication year: ";
            std::cin >> book.publication_year;
            std::cout << "Enter genre: ";
            std::cin >> book.genre;
            manager.addBook(book);
        } else if (choice == 2) {
            int index;
            Book book;
            std::cout << "Enter book index to edit: ";
            std::cin >> index;
            std::cout << "Enter new title: ";
            std::cin >> book.title;
            std::cout << "Enter new author: ";
            std::cin >> book.author;
            std::cout << "Enter new publication year: ";
            std::cin >> book.publication_year;
            std::cout << "Enter new genre: ";
            std::cin >> book.genre;
            manager.editBook(index - 1, book);
        } else if (choice == 3) {
            int index;
            std::cout << "Enter book index to delete: ";
            std::cin >> index;
            manager.deleteBook(index - 1);
        } else if (choice == 4) {
            std::string title;
            std::cout << "Enter book title to search: ";
            std::cin >> title;
            manager.searchByTitle(title);
        } else if (choice == 5) {
            bool ascending;
            std::cout << "Sort ascending? (1 for Yes, 0 for No): ";
            std::cin >> ascending;
            manager.sortBooksByTitle(ascending);
        } else if (choice == 6) {
            manager.displayAllBooks();
        } else if (choice == 7) {
            std::string filename;
            std::cout << "Enter filename to import: ";
            std::cin >> filename;
            manager.importBooks(filename);
        } else if (choice == 8) {
            std::string filename;
            std::cout << "Enter filename to export: ";
            std::cin >> filename;
            manager.exportBooks(filename);
        }
    } while (choice != 9);

    return 0;
}

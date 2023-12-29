#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Book {
public:
    string title;
    string author;
    int id;
    bool available;

    Book(string title, string author, int id) : title(title), author(author), id(id), available(true) {}
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void displayBooks() {
        cout << "Library Books:\n";
        for (const auto& book : books) {
            cout << "ID: " << book.id << "\tTitle: " << book.title << "\tAuthor: " << book.author
                 << "\tStatus: " << (book.available ? "Available" : "Not Available") << endl;
        }
    }

    void borrowBook(int bookId) {
        auto it = find_if(books.begin(), books.end(), [bookId](const Book& b) {
            return b.id == bookId && b.available;
        });

        if (it != books.end()) {
            it->available = false;
            cout << "Book successfully borrowed!\n";
        } else {
            cout << "Book not available or does not exist.\n";
        }
    }

    void returnBook(int bookId) {
        auto it = find_if(books.begin(), books.end(), [bookId](const Book& b) {
            return b.id == bookId && !b.available;
        });

        if (it != books.end()) {
            it->available = true;
            cout << "Book successfully returned!\n";
        } else {
            cout << "Book not borrowed or does not exist.\n";
        }
    }
};

int main() {
    Library cityLibrary;
    cityLibrary.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", 1));
    cityLibrary.addBook(Book("To Kill a Mockingbird", "Harper Lee", 2));
    cityLibrary.addBook(Book("1984", "George Orwell", 3));
    cityLibrary.displayBooks();
    cityLibrary.borrowBook(2);
    cityLibrary.displayBooks();
    cityLibrary.returnBook(2);
    cityLibrary.displayBooks();
    return 0;
}

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

template <typename T>
void inputBooks(T*& books, int& size);

template <typename T>
void displayBooks(const T* books, int size);

template <typename T>
string getCategory(const T& book);

template <typename T>
bool isBarcodeUnique(const T* books, int count, const string& barcode);


int main() {
    struct Book {
        string barcode;
        string title;
        int yearPublished;
        int rating;
    };

    Book* library = nullptr;
    int numBooks = 0;

    inputBooks(library, numBooks);
    displayBooks(library, numBooks);

    delete[] library;
    library = nullptr;

    return 0;
}


template <typename T>
string getCategory(const T& book) {
    switch (book.rating) {
        case 5: return "Excellent";
        case 4: return "Very Good";
        case 3: return "Good";
        case 2: return "Fair";
        case 1: return "Poor";
        case 0: return "No Rating";
        default: return "Invalid";
    }
}


template <typename T>
bool isBarcodeUnique(const T* books, int count, const string& barcode) {
    for (int i = 0; i < count; ++i) {
        if (books[i].barcode == barcode) {
            return false;
        }
    }
    return true;
}


template <typename T>
void inputBooks(T*& books, int& size) {
    cout << "Enter number of books: ";
    while (!(cin >> size) || size < 1) {
        cout << "Invalid! Enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore();

    books = new T[size];

    for (int i = 0; i < size; ++i) {
        cout << "\n--- Book " << (i + 1) << " ---\n";

        bool duplicate;
        do {
            cout << "Enter Barcode: ";
            getline(cin, books[i].barcode);
            duplicate = !isBarcodeUnique(books, i, books[i].barcode);
            if (duplicate) cout << "Barcode exists! Enter another.\n";
        } while (duplicate);

        cout << "Enter Title: ";
        getline(cin, books[i].title);

        cout << "Enter Year Published (1000-2026): ";
        while (!(cin >> books[i].yearPublished) || books[i].yearPublished < 1000 || books[i].yearPublished > 2026) {
            cout << "Invalid! Enter 1000-2026: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore();

        cout << "Enter Rating (0-5): ";
        while (!(cin >> books[i].rating) || books[i].rating < 0 || books[i].rating > 5) {
            cout << "Invalid! Enter 0-5: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore();
    }
}


template <typename T>
void displayBooks(const T* books, int size) {
    cout << "\n\n=== Book Rating Results ===\n";
    cout << setfill('-') << setw(75) << "-" << setfill(' ') << "\n";
    cout << left << setw(18) << "Barcode"
         << setw(32) << "Title"
         << setw(10) << "Year"
         << setw(10) << "Rating"
         << "Category\n";
    cout << setfill('-') << setw(75) << "-" << setfill(' ') << "\n";

    for (int i = 0; i < size; ++i) {
        cout << left << setw(18) << books[i].barcode
             << setw(32) << books[i].title
             << setw(10) << books[i].yearPublished
             << setw(10) << books[i].rating
             << getCategory(books[i]) << "\n";
    }
    cout << setfill('-') << setw(75) << "-" << setfill(' ') << "\n";
}

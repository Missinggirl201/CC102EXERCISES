#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits> 

using namespace std;

struct Book {
    string br;  
    string t;   
    int y;      
    int r;      
};

string category(int r) { 
    switch(r) {
        case 5: return "Excellent";
        case 4: return "Very Good";
        case 3: return "Good";
        case 2: return "Fair";
        case 1: return "Poor";
        case 0: return "No Rating";
        default: return "Invalid";
    }
}

bool isBarcodeUnique(const vector<Book>& books, const string& br) {
    for(const auto& book : books) {
        if(book.br == br) {
            return false;
        }
    }
    return true;
}

int main() {
    char ch;  
    do {
        int num;  
        cout << "Enter number of books: ";
        while(!(cin >> num) || num < 1) {
            cout << "Invalid! Enter a positive integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore();

        vector<Book> books;
        books.reserve(num);

        for(int i = 0; i < num; ++i) {
            Book n;  
            cout << "\nBook " << (i + 1) << ":\n";

            bool duplicate;
            do {
                cout << "Enter Barcode: ";
                getline(cin, n.br);
                duplicate = !isBarcodeUnique(books, n.br);
                if(duplicate) {
                    cout << "Barcode already exists! Enter another.\n";
                }
            } while(duplicate);

            cout << "Enter Title: ";
            getline(cin, n.t);

            
            cout << "Enter Year Published: ";
            while(!(cin >> n.y) || n.y < 1000 || n.y > 2026) {
                cout << "Invalid! Enter a valid year (1000-2026): ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore();

            do {
                cout << "Enter Rating (0-5): ";
                while(!(cin >> n.r)) { 
                    cout << "Invalid! Enter a number (0-5): ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.ignore();
                if(n.r < 0 || n.r > 5) {  
                    cout << "Invalid rating! Must be 0-5.\n";
                }
            } while(n.r < 0 || n.r > 5);  

            books.push_back(n);
        }

        // Consistent table formatting
        cout << "\n\nBook Rating Results:\n";
        cout << setfill('-') << setw(70) << "-" << setfill(' ') << "\n";
        cout << left 
             << setw(15) << "Barcode" 
             << setw(30) << "Title" 
             << setw(8) << "Year" 
             << setw(8) << "Rating" 
             << "Category\n";
        cout << setfill('-') << setw(70) << "-" << setfill(' ') << "\n";
        
        for(const auto& book : books) {
            cout << left 
                 << setw(15) << book.br 
                 << setw(30) << book.t 
                 << setw(8) << book.y 
                 << setw(8) << book.r  
                 << category(book.r) << "\n"; 
        }
        cout << setfill('-') << setw(70) << "-" << setfill(' ') << "\n";

        cout << "\nDo you want to run the program again? (Y/N): ";
        while(!(cin >> ch) || (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n')) {
            cout << "Invalid! Enter Y or N: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore();

    } while(ch == 'Y' || ch == 'y');

    cout << "Program terminated. Thank you!\n";
    return 0;
}

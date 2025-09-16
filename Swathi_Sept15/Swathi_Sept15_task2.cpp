#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


enum Genre { FICTION, NONFICTION, SCIENCE, HISTORY, TECHNOLOGY };


string genreToString(Genre g) {
    switch (g) {
        case FICTION: return "Fiction";
        case NONFICTION: return "Non-Fiction";
        case SCIENCE: return "Science";
        case HISTORY: return "History";
        case TECHNOLOGY: return "Technology";
        default: return "Unknown";
    }
}


class Book {
private:
    int bookID;
    float rating;
    double price;
    char availabilityStatus;  
    bool isReferenceOnly;
    string title;
    Genre genre;

public:

    Book()
        : bookID(0), rating(0.0), price(0.0), availabilityStatus('A'),
          isReferenceOnly(false), title("Untitled"), genre(FICTION) {}

    
    Book(int id, float r, double p, char status, bool ref, string t, Genre g)
        : bookID(id), rating(r), price(p), availabilityStatus(status),
          isReferenceOnly(ref), title(t), genre(g) {}
    ~Book() {
        cout << "Book object with ID " << bookID << " destroyed." << endl;
    }

   
    int getBookID() const { return bookID; }
    float getRating() const { return rating; }
    double getPrice() const { return price; }
    char getAvailabilityStatus() const { return availabilityStatus; }
    bool getIsReferenceOnly() const { return isReferenceOnly; }
    string getTitle() const { return title; }
    Genre getGenre() const { return genre; }

   
    void setBookID(int id) { bookID = id; }
    void setRating(float r) { rating = r; }
    void setPrice(double p) { price = p; }
    void setAvailabilityStatus(char status) { availabilityStatus = status; }
    void setIsReferenceOnly(bool ref) { isReferenceOnly = ref; }
    void setTitle(const string& t) { title = t; }
    void setGenre(Genre g) { genre = g; }

    void updateAvailability(bool isBorrowed) {
        availabilityStatus = isBorrowed ? 'B' : 'A';
    }

    void displayDetails() const {
        cout << "Book ID: " << bookID << endl;
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
        cout << "Rating: " << rating << endl;
        cout << "Status: " << (availabilityStatus == 'A' ? "Available" : "Borrowed") << endl;
        cout << "Reference Only: " << (isReferenceOnly ? "Yes" : "No") << endl;
        cout << "Genre: " << genreToString(genre) << endl;
        cout << "-----------------------------" << endl;
    }
};


void markAsReference(Book &book) {
    book.setIsReferenceOnly(true);
    cout << "Book \"" << book.getTitle() << "\" marked as Reference Only." << endl;
}

bool isAffordable(const Book &book, const double budget) {
    return book.getPrice() <= budget;
}

void printFormattedBookList(const Book books[], const int size) {
    cout << left << setw(6) << "ID"
         << setw(20) << "Title"
         << setw(10) << "Price"
         << setw(8) << "Rating"
         << setw(10) << "Status"
         << setw(12) << "Reference"
         << setw(15) << "Genre" << endl;
    cout << string(80, '-') << endl;

    for (int i = 0; i < size; i++) {
        cout << left << setw(6) << books[i].getBookID()
             << setw(20) << books[i].getTitle()
             << setw(10) << books[i].getPrice()
             << setw(8) << books[i].getRating()
             << setw(10) << (books[i].getAvailabilityStatus() == 'A' ? "Available" : "Borrowed")
             << setw(12) << (books[i].getIsReferenceOnly() ? "Yes" : "No")
             << setw(15) << genreToString(books[i].getGenre())
             << endl;
    }
    cout << "---------------------------------------------------------------" << endl;
}

int main() {
    // Sample data
    Book book1(101, 4.5, 299.99, 'A', false, "C++ Primer", TECHNOLOGY);
    Book book2(102, 3.8, 150.00, 'B', true, "Design Patterns", SCIENCE);
    Book book3; // default constructor
    Book books[3] = { book1, book2, book3 };

    int choice;
    do {
        cout << "\nLibrary Menu:\n";
        cout << "1. Add/Update Book Details\n";
        cout << "2. Mark Book as Reference Only\n";
        cout << "3. Check if Book is Affordable\n";
        cout << "4. Update Availability\n";
        cout << "5. Display Book Details\n";
        cout << "6. Display All Books (Formatted List)\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int index, id, genreSel;
            float rating;
            double price;
            char status;
            bool ref;
            string title;

            cout << "Enter book index (0-2): ";
            cin >> index;
            if (index < 0 || index >= 3) { cout << "Invalid index!\n"; continue; }

            cout << "Enter ID: "; cin >> id;
            cout << "Enter Rating (0.0 - 5.0): "; cin >> rating;
            if (rating < 0.0 || rating > 5.0) { cout << "Invalid rating!\n"; continue; }
            cout << "Enter Price (>0): "; cin >> price;
            if (price <= 0) { cout << "Invalid price!\n"; continue; }
            cout << "Enter Availability (A/B): "; cin >> status;
            cout << "Is Reference Only (0/1): "; cin >> ref;
            cin.ignore();
            cout << "Enter Title: "; getline(cin, title);
            if (title.empty()) { cout << "Title cannot be empty!\n"; continue; }
            cout << "Enter Genre (0-FICTION,1-NONFICTION,2-SCIENCE,3-HISTORY,4-TECHNOLOGY): ";
            cin >> genreSel;

            books[index] = Book(id, rating, price, status, ref, title, (Genre)genreSel);

        } else if (choice == 2) {
            int index;
            cout << "Enter book index (0-2): "; cin >> index;
            if (index >= 0 && index < 3) markAsReference(books[index]);

        } else if (choice == 3) {
            int index; double budget;
            cout << "Enter book index (0-2): "; cin >> index;
            cout << "Enter budget: "; cin >> budget;
            if (index >= 0 && index < 3) {
                cout << (isAffordable(books[index], budget) ? "Affordable\n" : "Not Affordable\n");
            }

        } else if (choice == 4) {
            int index; bool isBorrowed;
            cout << "Enter book index (0-2): "; cin >> index;
            cout << "Is borrowed? (1 = Yes, 0 = No): "; cin >> isBorrowed;
            if (index >= 0 && index < 3) books[index].updateAvailability(isBorrowed);

        } else if (choice == 5) {
            int index;
            cout << "Enter book index (0-2): "; cin >> index;
            if (index >= 0 && index < 3) books[index].displayDetails();

        } else if (choice == 6) {
            printFormattedBookList(books, 3);
        }

    } while (choice != 7);

    return 0;
}

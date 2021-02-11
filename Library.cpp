#include<string>
#include "cli.h"
#include "FileInteraction.h"

using namespace std;
struct Date {
    int year;
    int month;
    int day;

    string ToString() {
        string result;
        result = to_string(day) + "." + to_string(month) + "." + to_string(year);
        return result;
    }
};

int main() {
    map<string, Book> listOfBooks;
    map<string, Reader> listOfReaders;

    map<string, Reader>::iterator iter_1;
    map<string, Book>::iterator iter_2;
   
    int menu;
    string temp;
  
    string key;
    ImportFromFileB(listOfBooks);
    ImportFromFileR(listOfReaders);

    cout << "\n\n\t+++Library +++\n\n";
    do {
        cout << "--------------------------------------------\n";
        cout << "\t--- Menu ---\n\n";
        cout << "To show the list of books [1]" << endl;
        cout << "To show the list of issued books [2]" << endl;
        cout << "To show the list of readers [3]" << endl;
        cout << "To add a book to the list [4]" << endl;
        cout << "To add a reader to the list [5]" << endl;
        cout << "To search for a book [6]" << endl;
        cout << "To search for a reader [7]" << endl;
        cout << "Change book's status (issued/not issued)[8]" << endl;
        cout << "To exit press [0]" << endl;
        cout << "--------------------------------------------\n";
        cout << endl << "We can do it easy way, or we can do it hard way. The choice is yours. - ";
        cin >> menu;

        system("cls");
        cout << "\n\n\t+++Library +++\n\n";
        switch (menu) {
        case 1:
            cout << "--------------------------------------------\n";
            cout << "--- The list of books ---\n";
            cout << "--------------------------------------------\n";
            ShowTheListOfBooks(listOfBooks);
            break;

        case 2:
            cout << "--------------------------------------------\n";
            cout << "--- The list of issued books ---\n";
            cout << "--------------------------------------------\n";
            ShowTheListOfIssuedBooks(listOfBooks);
            break;

        case 3:
            cout << "--------------------------------------------\n";
            cout << "--- The list of readers ---\n";
            cout << "--------------------------------------------\n";
            ShowTheListOfReaders(listOfReaders);
            break;

        case 4:
            cout << "--------------------------------------------\n";
            cout << "--- Add new book ---" << endl;
            cout << "--------------------------------------------\n";
            InputBook(listOfBooks);
            break;

        case 5:
            cout << "--------------------------------------------\n";
            cout << "--- Add new reader ---" << endl;
            cout << "--------------------------------------------\n";
            InputReader(listOfReaders);
            break;

        case 6:
            cout << "--------------------------------------------" << endl;
            cout << "--- Search for a book ---\n";
            cout << "--------------------------------------------\n";
            cout << "\nEnter the title of a book - "; 
            cin.ignore(256, '\n');
            getline(cin, key);
            SearchForABook(listOfBooks, key);
            break;

        case 7:
            cout << "--------------------------------------------" << endl;
            cout << "--- Search for a reader ---\n";
            cout << "--------------------------------------------\n";
            cout << "\nEnter the name of a reader - "; 
            cin.ignore(256, '\n');
            getline(cin, key);
            SearchForAReader(listOfReaders, key);
            break;

        case 8:
            cout << "--------------------------------------------" << endl;
            cout << "--- Change book's status ---\n";
            cout << "--------------------------------------------\n";
            cout << "\nEnter the title of a book - "; 
            cin.ignore(256, '\n');
            getline(cin, key);
            iter_2 = listOfBooks.find(key);
            iter_2->second.ChangeStatus();
            if (iter_2->second.status) {
                cout << "status changed to: Issued.\n";
            }
            else {
                cout << "status changed to: Not issued.\n";
            }
            break;
        default:
            cout << "Wrong option. Please, enter again\n";
            break;
        }
    } while (menu != 0);

    ExportToFileB(listOfBooks);
    ExportToFileR(listOfReaders);
}
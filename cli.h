#pragma once

#include <iostream>
#include <vector>
#include <map>
#include<string>
#include<fstream>
#include "Books.h"
#include "Readers.h"

void InputReader(map<string, Reader>& readerList) {
    Reader reader;
    string temp;
    cin.ignore(256, '\n');

    cout << "--------------------------------------------" << endl;
    cout << "+++ Enter the data of a reader +++" << endl;
    cout << "Enter the firstname of a reader - ";
    getline(cin, reader.firstname);
    cout << "Enter the lastname of a reader - ";
    getline(cin, reader.lastname);
    cout << "Enter the date of birth (01.01.1995) - ";
    getline(cin, reader.lastname);

    cout << "Recording is successful" << endl;
    cout << "--------------------------------------------" << endl;
}

void ShowOneReader(pair<string, Reader> reader) {
    cout << "Name: " << reader.second.firstname << ";\n";
    cout << "Lastname: " << reader.second.lastname << ";\n";
    cout << "Date of birth: " << reader.second.dateOfBirth << ";\n";
    cout << "--------------------------------------------\n\n";
}

void ShowTheListOfReaders(map<string, Reader> listOfReaders) {
    cout << "--------------------------------------------\n";
    cout << "--- The list of readers ---\n";
    cout << "--------------------------------------------\n";
    for (pair<string, Reader> el : listOfReaders) {
        ShowOneReader(el);
    }
}

void SearchForAReader(map<string, Reader> listOfReaders, string key) {
    auto iterator = listOfReaders.find(key);
    cout << "--------------------------------------------" << endl;
    cout << "----Search for a reader---\n";
    cout << "--------------------------------------------\n";

    if (iterator != listOfReaders.end()) {
        ShowOneReader(make_pair(iterator->first, iterator->second));
    }
    else {
        cout << "--------------------------------------------\n";
        cout << "There is no such reader. Please, try again.\n";
        cout << "--------------------------------------------\n\n";
    }
}

void InputBook(map<string, Book>& libra) {
    Book book;
    string temp;
    cin.ignore(256, '\n');

    cout << "+++ Add new book +++" << endl;
    cout << "Enter the title of a book - ";
    getline(cin, book.title);
    cout << "Enter the name of a author - ";
    getline(cin, book.author);
    cout << "Enter the status of a book - ";
    getline(cin, temp);
    if (temp == "Issued") {
        book.status = true;
    }
    else {
        book.status = false;
    }

    libra.insert(make_pair(book.title, book));
    cout << "Recording is successful" << endl;
    cout << "--------------------------------------------\n\n";
}

void ShowOneBook(pair<string, Book> book) {
    cout << "key - " << book.first << endl;
    cout << "Title of a book: " << book.second.title << ";\n";
    cout << "\nName of an author: " << book.second.author << ";\n";
    cout << "\nStatus of a book: ";
    if (book.second.status) {
        cout << "Issued;\n";
    }
    else {
        cout << "Not issued;\n";
    }
    cout << "--------------------------------------------\n\n";
}

void ShowTheListOfIssuedBooks(map<string, Book> listOfBooks) {
    for (pair<string, Book> el : listOfBooks) {
        if (el.second.status) {
            ShowOneBook(el);
        }
    }
}

void ShowTheListOfBooks(map<string, Book> listOfBooks) {
    cout << "--------------------------------------------\n";
    cout << "--- The list of books ---\n";
    cout << "--------------------------------------------\n";
    for (pair<string, Book> el : listOfBooks) {
        ShowOneBook(el);
    }
}

void SearchForABook(map<string, Book> listOfBooks, string key) {
    auto iterator = listOfBooks.find(key);

    cout << "--------------------------------------------" << endl;
    cout << "----Search for a book---\n";
    cout << "--------------------------------------------\n";
    if (iterator != listOfBooks.end()) {
        ShowOneBook(make_pair(iterator->first, iterator->second));
        cout << "--------------------------------------------" << endl;
    }
    else {
        cout << "--------------------------------------------" << endl;
        cout << "There is no such book. Please, try again." << endl;
        cout << "--------------------------------------------" << endl;
    }
}
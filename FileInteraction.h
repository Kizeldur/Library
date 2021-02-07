#pragma once

#include <iostream>
#include <vector>
#include <map>
#include<string>
#include<fstream>

void ReadFromFileB(map<string, Book>& books, ifstream& file) {
    Book book;
    string key;
    string temp;

    while (!file.eof()) {
        getline(file, book.title, ';');
        getline(file, book.author, ';');
        getline(file, temp);
        if (temp == "Issued") {
            book.status = true;
        }
        else {
            book.status = false;
        }

        key = book.title;
        books.insert(make_pair(key, book));
    }
}

void ImportFromFileB(map<string, Book>& listOfReaders) {
    ifstream file;
    string address;

    cout << "Reading from file B.csv" << endl;

    file.open("B.csv");

    if (file.is_open() && file.peek() == -1) {
        cout << "File is empty. Please, try again" << endl;
    }
    else if (file.is_open() && file.peek() != -1) {
        ReadFromFileB(listOfReaders, file);
        cout << "Adding book list from file is successful" << endl;
    }
    else {
        cout << "There is no such file. Please try again" << endl;
    }
    file.close();
}

void WriteToFileB(map<string, Book> books, ofstream& file) {
    for (auto iter : books)
    {
        file << iter.second.title << ";";
        file << iter.second.author << ";";
        file << iter.second.status << endl;
    }
}

void ExportToFileB(map<string, Book> readers) {
    ofstream file;
    cout << "Writing to file B.csv" << endl;
    file.open("B.csv", ios_base::trunc);
    if (file.is_open()) {
        WriteToFileB(readers, file);
        cout << "Recording is successful" << endl;
    }
    else {
        cout << "There is no such file. Please try again" << endl;
    }
    file.close();
    cout << "Writing is successeful" << endl;
}

void ReadFromFileR(map<string, Reader>& readers, ifstream& file) {
    Reader reader;
    string key;
    string someShit;

    while (!file.eof()) {
        getline(file, reader.firstname, ';');
        getline(file, reader.lastname, ';');
        getline(file, reader.dateOfBirth);
        
        key = reader.lastname;
        readers.insert(make_pair(key, reader));
    }
}

void ImportFromFileR(map<string, Reader>& readers) {
    ifstream file;

    cout << "Reading from file R.csv" << endl;
    file.open("R.csv");

    if (file.is_open() && file.peek() == -1) {
        cout << "File is empty. Please, try again" << endl;
    }
    else if (file.is_open() && file.peek() != -1) {
        ReadFromFileR(readers, file);
        cout << "Adding readers list from file is successful" << endl;
    }
    else {
        cout << "There is no such file. Please try again\n";
    }
    file.close();
}

void WriteToFileR(map<string, Reader> readers, ofstream& file) {
    for (auto iter : readers)
    {
        file << iter.second.firstname << ";";
        file << iter.second.lastname << ";";
        file << iter.second.dateOfBirth;
    }
}

void ExportToFileR(map<string, Reader> readers) {
    ofstream file;
    cout << "Writing to file R.csv" << endl;
    file.open("R.csv", ios_base::trunc);

    if (file.is_open()) {
        WriteToFileR(readers, file);
        cout << "Recording is successful" << endl;
    }
    else {
        cout << "There is no such file. Please try again" << endl;
    }
    file.close();
}


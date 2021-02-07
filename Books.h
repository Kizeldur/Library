#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <string>
#include <fstream>

using namespace std;

struct Book {
    string author;
    string title;
    bool status;
   
    string StatusToString() {
        if (status) {
            return "Issued";
        }
        else {
            return "Not issued";
        }
    }

    void ChangeStatus() {
        status = !status;
    }
};



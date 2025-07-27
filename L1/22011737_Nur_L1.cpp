/*
ID : 22011737
Name : Nur Aina Nabila
Group : G3
Lab: Lab 1
*/

#include <iostream>
using namespace std;

int main() {

    struct Student {
        int id;
        string name;
        int contact;
        string email;
    };

    int size = 5;
    Student student[size];
    for (int i = 0; i < size; i++) {
        cout << "\nStudent #" << i + 1;
        cout << "\nEnter ID: "; cin >> student[i].id;
        cout << "Enter name: "; cin >> student[i].name;
        cout << "Enter email: "; cin >> student[i].email;
        cout << "Enter contact: "; cin >> student[i].contact;
    }
    
    cout << "\n-------------------";
    cout << "\nStudent Database:\n";
    cout << "-------------------\n";

    for (int i = 0; i < 5; i++) {
        cout << "Student " << i + 1;
        cout << "\nID: " << student[i].id;
        cout << "\nName: " << student[i].name;
        cout << "\nEmail: " << student[i].email;
        cout << "\nContant: " << student[i].contact;
        cout << "\n-------------------\n";
    }

}
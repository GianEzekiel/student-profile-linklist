#include <iostream>
#include <string>

using namespace std;

int maxSize;

class Node {
public:
    string name;
    string srCode;
    string sub1;
    string sub2;
    string sub3;
    Node* next;
};

Node* head = NULL;

void addStudent(string name, string srCode, string sub1, string sub2, string sub3) {
    Node* newStudent = new Node();
    newStudent->name = name;
    newStudent->srCode = srCode;
    newStudent->sub1 = sub1;
    newStudent->sub2 = sub2;
    newStudent->sub3 = sub3;
    newStudent->next = NULL;

    cout << "Adding student: " << name << endl;

    if (head == NULL || (head->name >= newStudent->name)) {
        newStudent->next = head;
        head = newStudent;
    }
    else {
        Node* current = head;
        while (current->next != NULL && current->next->name < newStudent->name) {
            current = current->next;
        }
        newStudent->next = current->next;
        current->next = newStudent;
    }

    cout << "\nRecord Inserted Successfully\n";
}

void showInformationSheet() {
    Node* p = head;
    if (p == NULL) {
        cout << "No Records Available\n";
    }
    else {
        while (p != NULL) {
            cout << "Name: " << p->name << endl;
            cout << "SR Code: " << p->srCode << endl;
            cout << "Subjects: " << p->sub1 << ", " << p->sub2 << ", " << p->sub3 << endl;
            cout << endl;

            p = p->next;
        }
    }
}

void searchFunc(string name) {
    if (!head) {
        cout << "No Records Available\n";
        return;
    }
    else {
        Node* p = head;
        while (p) {
            if (p->name == name) {
                cout << "\nName: " << p->name << endl;
                cout << "SR Code: " << p->srCode << endl;
                cout << "Subjects: " << p->sub1 << ", " << p->sub2 << ", " << p->sub3 << endl;
                cout << endl;
                return;
            }
            p = p->next;
        }

        cout << "No Record Found for Name: " << name << endl;
    }
}

void deleteStudent(string name) {
    if (!head) {
        cout << "No Records Available\n";
        return;
    }
    else {
        Node* current = head;
        Node* previous = nullptr;

        // Handle the case where the node to be deleted is the head node
        if (current != nullptr && current->name == name) {
            head = current->next;
            delete current;
            cout << "Deleted student: " << name << endl;
            return;
        }

        while (current != nullptr && current->name != name) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "No Record Found for Name: " << name << endl;
            return;
        }

        // Unlink the node from the linked list
        previous->next = current->next;
        delete current;
        cout << "Deleted student: " << name << endl;
    }
}

int main() {
    string name;
    string srCode;
    string sub1;
    string sub2;
    string sub3;
    int choice;
    char choice1;
    bool isContinue = true;

    while (isContinue) {
        bool isContinue1 = true;

        system("cls");
        cout << "\t\t\tStudent Profile Information\n";
        cout << "\t\t[1] Insert Student Information\n";
        cout << "\t\t[2] Information Sheet\n";
        cout << "\t\t[3] Search\n";
        cout << "\t\t[4] Delete\n";
        cout << "\t\t[5] Exit Program\n";
        cout << "\t\tChoice: ";
        cin >> choice;
        cout << endl << endl;

        switch (choice) {
        case 1:
            system("cls");
            while (isContinue1) {
                system("cls");
                cout << "\tEnter Student Information ";
                cin.ignore(); // Ignore the newline character after reading maxSize
                cout << endl;
                cout << "-------------------------------------";

                // Name
                while (true) {
                    cout << "\nEnter Name: ";
                    getline(cin, name);
                    if (name.empty()) {
                        cout << "Error: Empty string entered." << endl;
                        continue;
                    }
                    break;
                }

                // SR Code
                while (true) {
                    cout << "Enter SR Code: ";
                    getline(cin, srCode);
                    if (srCode.empty()) {
                        cout << "Error: Empty string entered." << endl;
                        continue;
                    }
                    break;
                }

                // Subject 1
                while (true) {
                    cout << "Enter First Subject: ";
                    getline(cin, sub1);
                    if (sub1.empty()) {
                        cout << "Error: Empty string entered." << endl;
                        continue;
                    }
                    break;
                }

                // Subject 2
                while (true) {
                    cout << "Enter Second Subject: ";
                    getline(cin, sub2);
                    if (sub2.empty()) {
                        cout << "Error: Empty string entered." << endl;
                        continue;
                    }
                    break;
                }

                // Subject 3
                while (true) {
                    cout << "Enter Third Subject: ";
                    getline(cin, sub3);
                    if (sub3.empty()) {
                        cout << "Error: Empty string entered." << endl;
                        continue;
                    }
                    break;
                }

                addStudent(name, srCode, sub1, sub2, sub3);

                cout << "\nDo you want to insert another profile? [Y/N]: ";
                cin >> choice1;
                if (choice1 == 'n' || choice1 == 'N') {
                    isContinue1 = false;
                }
            }
            break;
        case 2:
            system("cls");
            showInformationSheet();
            break;
        case 3:
            system("cls");
            cin.ignore(); // Ignore the newline character before reading the name
            cout << "Enter Name to Search: ";
            getline(cin, name);
            searchFunc(name);
            break;
        case 4:
            system("cls");
            cin.ignore(); // Ignore the newline character before reading the name
            cout << "Enter Name to Delete: ";
            getline(cin, name);
            deleteStudent(name);
            break;
        case 5:
            isContinue = false;
            break;
        default:
            continue;
        }

        cout << "\nPress Enter to Continue...";
        cin.ignore();
        cin.get();
    }

    // Free the memory for the nodes
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}

#include <iostream>

struct Patient
{
    std::string name;
    int age;
    std::string condition;
    Patient *next;
};
void displayMenu(int &n);
void addPatient(Patient **headptr);
void displayPatients(Patient *headptr);
void searchPatient(Patient *headptr);
void deletePatient(Patient *headptr);
void freeMemory(Patient *headptr);

int main()
{
    Patient *headpointer = nullptr;

    int numberOfPatients, menuOption;
    system("cls");
    std::cout << "Welcome To The Patient Record Managements System.\nPress Enter To Proceed...";
    std::cin.get();
    system("cls");
    do
    {
        displayMenu(menuOption);
        switch (menuOption)

        {
        case 1:
            addPatient(&headpointer);
            break;
        case 2:
            displayPatients(headpointer);
            break;
        case 3:
            searchPatient(headpointer);
            break;
        case 4:
            deletePatient(headpointer);
            break;
        case 5:
            freeMemory(headpointer);
            break;

        default:
            system("cls");
            std::cout << "Invalid Input\nExiting System...\n";
            return 0;
            break;
        }

    } while (menuOption > 0 && menuOption <= 5);

    return 0;
}
void displayMenu(int &n)
{
    std::cout << "Options\n\n1. Add Patient\n2. Display All Patients\n3. Search Patient by Name\n4. Delete Patient by Name\n5. Exit\nOption:";
    std::cin >> n;
}
void addPatient(Patient **headptr)
{
    system("cls");
    Patient *newPatient = new Patient();
    std::cout << "Adding Patient...\n";
    std::cin.ignore();
    std::cout << "Name      : ";
    getline(std::cin, newPatient->name);
    std::cout << "Age       : ";
    std::cin >> newPatient->age;
    std::cin.ignore();
    std::cout << "Condition : ";
    getline(std::cin, newPatient->condition);

    newPatient->next = nullptr;
    if (*headptr == nullptr)
    {
        *headptr = newPatient;
    }
    else
    {
        Patient *current = *headptr;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newPatient;
    }

    std::cout << "You've Successfully Added A Patient\nPress Enter To Return To Menu...";
    std::cin.get();
    system("cls");
};
void displayPatients(Patient *headptr)
{
    std::cout << "Displaying Patients";
};
void searchPatient(Patient *headptr)
{
    std::cout << "Condition:";
};
void deletePatient(Patient *headptr)
{
    std::cout << "Dleteting Patient";
};
void freeMemory(Patient *headptr)
{
    std::cout << "Freeing MEMORY";
};
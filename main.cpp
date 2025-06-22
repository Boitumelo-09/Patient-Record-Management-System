#include <iostream>

struct Patient
{
    std::string name;
    int age;
    std::string condition;
    Patient *next;
};
void displayMenu(int &n);
int countPatients(Patient *headptr);
void addPatient(Patient **headptr);
void displayPatients(Patient *headptr);
void searchPatient(Patient *headptr);
void deletePatient(Patient **headptr);
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
            system("cls");
            std::cout << "Number Of Patients: " << countPatients(headpointer);

            addPatient(&headpointer);
            break;
        case 2:
            displayPatients(headpointer);
            break;
        case 3:
            searchPatient(headpointer);
            break;
        case 4:
            deletePatient(&headpointer);
            break;
        case 5:
            freeMemory(headpointer);
            return 0;
            break;

        default:
            system("cls");
            std::cout << "Invalid Input\nExiting System...\n";
            return 0;
            break;
        }

    } while (menuOption >= 1 && menuOption <= 5);

    return 0;
}
void displayMenu(int &n)
{
    std::cout << "Options\n\n1. Add Patient\n2. Display All Patients\n3. Search Patient by Name\n4. Delete Patient by Name\n5. Exit\nOption:";
    std::cin >> n;
}
void addPatient(Patient **headptr)
{

    Patient *newPatient = new Patient();
    std::cout << "\n\nAdding Patient...\n";
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
int countPatients(Patient *headptr)
{
    int counter = 0;
    Patient *current1 = headptr;
    while (current1 != nullptr)
    {
        counter++;
        current1 = current1->next;
    }
    return counter;

    int count = 0;
    Patient *current = headptr;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}
void displayPatients(Patient *headptr)
{
    int tracker = 0;
    if (headptr == nullptr)
    {
        system("cls");
        std::cin.ignore();
        std::cout << "There Are No Saved Patients.\nEnter To Return To Menu...";
        std::cin.get();
        system("cls");
    }
    else
    {
        system("cls");
        while (headptr != nullptr)
        {
            std::cout << "Patient No: " << tracker + 1 << '\n';
            std::cout << "Name      : " << headptr->name << '\n';
            std::cout << "Age       : " << headptr->age << '\n';
            std::cout << "Condition : " << headptr->condition << '\n';
            tracker++;
            headptr = headptr->next;
            std::cout << "...................................................\n\n";
        }
        std::cin.ignore();
        std::cout << "Press Enter To Return To Main Menu...";
        std::cin.get();
        system("cls");
    }
};
void searchPatient(Patient *headptr)
{
    if (headptr == nullptr)
    {
        system("cls");
        std::cin.ignore();
        std::cout << "There Are No Saved Patients.\nEnter To Return To Menu...";
        std::cin.get();
        system("cls");
        return;
    }
    bool found = false;
    system("cls");
    std::string searchKey;
    Patient *CurrentPatient = headptr;
    system("cls");
    std::cout << "Searching For Patient....\n\nSearch: ";
    std::cin.ignore();
    getline(std::cin, searchKey);
    for (; CurrentPatient != nullptr; CurrentPatient = CurrentPatient->next)
    {
        if (searchKey == CurrentPatient->name)
        {
            found = true;

            std::cout << "\nPatient Found. Details:";
            std::cout << "\nName      :" << CurrentPatient->name;
            std::cout << "\nAge       :" << CurrentPatient->age;
            std::cout << "\nCondition :" << CurrentPatient->condition;
            std::cout << "\n\nEnter To Return To Menu...";
            std::cin.get();
            system("cls");
            return;
        }
    }
    if (!found)
    {
        std::cout << "Patient Not Found";
        std::cout << "\n\nEnter To Return To Menu...";
        std::cin.get();
        system("cls");
    }
}
void deletePatient(Patient **headptr)
{
    system("cls");
    std::cin.ignore();
    std::string deleteKey;
    std::cout << "Enter Name Of Patient To Delete: ";
    getline(std::cin, deleteKey);

    Patient *current = *headptr;
    Patient *previous = nullptr;

    while (current != nullptr && current->name != deleteKey)
    {
        previous = current;
        current = current->next;
    }

    if (current == nullptr)
    {
        std::cout << "Patient Not Found.\nPress Enter To Return To Menu...";
        std::cin.get();
        system("cls");
        return;
    }

    if (previous == nullptr) // deleting head
    {
        *headptr = current->next;
    }
    else
    {
        previous->next = current->next;
    }

    delete current;

    std::cout << "Patient Deleted Successfully.\nPress Enter To Return To Menu...";
    std::cin.get();
    system("cls");
}
void freeMemory(Patient *headptr)
{
    system("cls");
    std::cin.ignore();
    while (headptr != nullptr)
    {
        Patient *temporaryNode = headptr;
        headptr = headptr->next;
        delete temporaryNode;
    }

    std::cout << "Freeing Memory...\n\nPress Enter To Exit System...";
    std::cin.get();
    system("cls");
    std::cout << "Thank You For Visiting.\nClosing System...";
    return;
};
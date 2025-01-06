#ifndef BANKMANGEMENTSYSTEM_H_INCLUDED
#define BANKMANGEMENTSYSTEM_H_INCLUDED

#include <iostream>
#include "clsHolderAccount.h"
#include <fstream>
#include <string>
#include <iomanip>
#include "clsBranches.h"
#include <cstdlib>
#include <algorithm>
using namespace std;

void AddHolder();
void RemoveHolder(const string& AccountID);

class clsBankMangementSystem
{
private:

    clsHolderAccount* Head;
    string DataFile;
    clsBranchesMangement Branches;
public:
    //Constactor
    clsBankMangementSystem()
    {
        Head = NULL;

        clsBranch branch1("101", "Maadi", "Cairo");

        clsBranch branch2("102", "6October", "Giza");

        clsBranch branch3("103", "Benha", "Qaluobia");
        clsBranch branch4("104", "Tanta", "Garbia");


        Branches.AddBranch(branch1);
        Branches.AddBranch(branch2);
        Branches.AddBranch(branch3);
        Branches.AddBranch(branch4);



        Menu();



    }

    void Menu()
    {
        int choice = 1;
        bool IsFirstTime = true;
        while (choice != 0)
        {

            if (!IsFirstTime)
            {
                cout << "\n\nDo you want to make another operation (Y/N) : ";
                string c; cin >> c;
                if (c == "N" || c == "n" || c == "No" || c == "NO" || c == "no" || c == "nO")
                {
                    //IsFirstTime = true;
                    exit(0);
                }
            }
            system("cls");
                cout << setw(37) << left << "" << "============================\n";
                cout << setw(37) << left << "" << "\t\tMain Menu\n";
                cout << setw(37) << left << "" << "============================\n";
                cout << setw(37) << left << "" << "\t[1] Add New Holder.\n";
                cout << setw(37) << left << "" << "\t[2] Remove Holder.\n";
                cout << setw(37) << left << "" << "\t[3] Display Holder Data.\n";
                cout << setw(37) << left << "" << "\t[4] Search For Holder.\n";
                cout << setw(37) << left << "" << "\t[5] Update Holder Information.\n";
                cout << setw(37) << left << "" << "\t[6] Branches Operations.\n";
                cout << setw(37) << left << "" << "\t[0] Exit The Program.\n\n";
                cout << setw(37) << left << "" << "\tEnter opration [1-6]: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                system("cls");
                cout << setw(37) << left << "" << "============================\n";
                cout << setw(37) << left << "" << "\tAdd New Holder Screen\n";
                cout << setw(37) << left << "" << "============================\n";
                IsFirstTime = false;
                AddHolder();


            }break;
            case 2:
            {
                system("cls");
                cout << setw(37) << left << "" << "============================\n";
                cout << setw(37) << left << "" << "\tRemove Holder Screen\n";
                cout << setw(37) << left << "" << "============================\n";
                cout << "\nEnter the ID of The Holder : ";
                string ID; cin >> ID;
                RemoveHolder(ID);
                IsFirstTime = false;

            }break;
            case 3:
            {
                system("cls");
                cout << setw(37) << left << "" << "===================================\n";
                cout << setw(37) << left << "" << "\tDisplay Holder Data Screen\n";
                cout << setw(37) << left << "" << "===================================\n";
                cout << "\nEnter the ID of The Holder : ";
                string ID; cin >> ID;

                _PrintHolderCard(ID);
                IsFirstTime = false;
            }break;

            case 4:
            {
                system("cls");
                cout << setw(37) << left << "" << "==============================\n";
                cout << setw(37) << left << "" << "\tSearch For Holder Screen\n";
                cout << setw(37) << left << "" << "==============================\n\n";
                cout << setw(37) << left << "" << "\t[1] Search by Name.\n";
                cout << setw(37) << left << "" << "\t[2] Search by ID.\n";
                cout << setw(37) << left << "" << "\t[3] Back forword.\n\n";
                cout << setw(37) << left << "" << "\tEnter Opration [1-3]: ";
                int answer; cin >> answer;

                if (answer == 1)
                {
                    cout <<endl<< setw(37) << left << "" << "\tEnter The Name : ";
                    string Name; cin >> Name;
                    SerchHolderByName(IsFirstTime,Name);
                   // IsFirstTime = false;

                }
                else if (answer == 2)
                {
                    cout << setw(37) << left << "" << "\tEnter The ID  : ";

                    string ID; cin >> ID;
                    if (IsIdNumberIsUnique(ID))
                    {
                        cout << "\nThe ID you searching for does not exist";
                        return;
                    }
                    clsHolderAccount* Current = FindAccount(ID);
                    SerchHolderByName(IsFirstTime,Current->_Name);
                    //IsFirstTime = false;
                }
            }break;
            case 5:
            {
                system("cls");
                cout << setw(37) << left << "" << "=======================================\n";
                cout << setw(37) << left << "" << "\tUpdate Holder Information Screen\n";
                cout << setw(37) << left << "" << "=======================================\n\n";
                cout << setw(37) << left << "" << "\tEnter the ID of The Holder : ";
                string ID; cin >> ID;
                UpdateHolderInfo(IsFirstTime,ID);
//                IsFirstTime = false;

            }break;
            case 6:
            {
                system("cls");
                cout << setw(37) << left << "" << "==============================\n";
                cout << setw(37) << left << "" << "\tBranches Operations Screen\n";
                cout << setw(37) << left << "" << "==============================\n\n";
                cout << setw(37) << left << "" << "\t[1] Add Branch.\n";
                cout << setw(37) << left << "" << "\t[2] Remove Branch by ID.\n";
                cout << setw(37) << left << "" << "\t[3] Display Branch Data.\n";
                cout << setw(37) << left << "" << "\t[4] Search for Branch by ID.\n";
                cout << setw(37) << left << "" << "\t[5] Display Holders according to Top Balance.\n\n";
                cout << setw(37) << left << "" << "\tEnter Opration [1-5]: ";
                int answer; cin >> answer;
                if (answer == 1)
                {
                    string ID, Name, Location;
                    cout << "\nEnter Branch Name : "; cin >> Name;
                    cout << "\nEnter Branch ID : "; cin >> ID;
                    cout << "\nEnter Branch Location : "; cin >> Location;
                    clsBranch NewBranch(ID, Name, Location);
                    Branches.AddBranch(NewBranch);
                    IsFirstTime = false;

                }
                else if (answer == 2)
                {

                    string ID;
                    cout << "\n Enter Branch ID : "; cin >> ID;

                    if (!Branches.FindBranchByID(ID))
                    {
                        cout << "\nThere is no such Branch with this ID";
                        IsFirstTime = false;
                        return;
                    }
                    Branches.RemoveBranchByID(ID);

                    cout << "\nBranch Deleted Sucessfully !";

                    IsFirstTime = false;

                }
                else if (answer == 3)
                {
                    Branches.DisplayAllBranchesIDsAndNames();
                    string ID;
                    cout <<"\n\n" << setw(37) << left << "" << "\tEnter Branch ID- : "; cin >> ID;
                    clsBranch* branch = Branches.FindBranchByID(ID);

                    if (branch != NULL)
                    {
                        //branch->DisplayBranchInfo();
                        IsFirstTime = false;
                        system("cls");
                        cout << endl;
                        cout << "\t| " << left << setw(15) << "Branch ID: " << branch->_BranchID <<endl;
                        cout << "\t| " << left << setw(15) <<"Branch Name: " << branch->_BranchName<<endl;
                        cout << "\t| " << left << setw(15) << "Branch Location:" << branch->_BranchLocation<<endl;
                        cout << "\t| " << left << setw(15) << "Accounts in Branch:\n\n\n";

                        cout << "\n\t___________________________________________________________________________";
                        cout << "______________________________________________________________________________\n" << endl;

                        cout << "\t| " << left << setw(15) << "Name";
                        cout << "| " << left << setw(20) << "ID";
                        cout << "| " << left << setw(12) << "Address";
                        cout << "| " << left << setw(20) << "Email";
                        cout << "| " << left << setw(10) << "P.Number";
                        cout << "| " << left << setw(20) << "Balance";
                        cout << "| " << left << setw(12) << "PINCode";
                        cout << "| " << left << setw(15) << "Branch" ;

                        cout << "\n\t___________________________________________________________________________";
                        cout << "______________________________________________________________________________\n" << endl;
                        DisplayHoldersData(ID);
                       cout << "\n\t___________________________________________________________________________";
                       cout << "______________________________________________________________________________\n" << endl;




                    }
                    else
                    {
                        cout << "No branch found with ID: " << ID << endl;
                    }

                }
                else if (answer == 4)
                {
                    string ID;
                    cout << "\nEnter Branch ID : "; cin >> ID;
                    clsBranch* branch = Branches.FindBranchsByID(ID);
                    if (branch != NULL)
                    {
                        cout << "\nThe Branch is Exist !";
                        branch->DisplayBranchInfo();
                    }
                    else
                    {
                        cout << "\nThere is no Branch with such ID";
                        //return; -> dont use it it will end the program

                    }

                }
                else if(answer == 5)
                {
                    string ID;
                    cout <<"\n\n" << setw(37) << left << "" << "\tEnter Branch ID- : "; cin >> ID;

                    clsBranch* branch = Branches.FindBranchsByID(ID);
                    if (branch)
                    {
                        cout << "\nThe Branch is Exist !";
                        DisplayHoldersByBalance(ID);

                    }
                    else
                    {
                        cout << "\nThere is no Branch with such ID";
                        //return; -> dont use it it will end the program

                    }

                }

                IsFirstTime = false;

            }break;
            case 0:
            {
                exit(0);
            }break;
            }

        }

    }


    bool IsIdNumberIsUnique(const string& AccountID)
    {
        clsHolderAccount* Current = Head;

        if (Current == NULL)
        {
            return true;
        }

        while (Current != NULL)
        {
            if (Current->_AccountID == AccountID)
                return false;

            Current = Current->Next;
        }

        return true;

    }

    void AddHolder()
    {

        clsHolderAccount* NewAccount = new clsHolderAccount();

        cout << "\nEnter Branch ID ";
        Branches.DisplayAllBranchesIDsAndNames();


        cin.ignore(1, '\n');
        cin >> NewAccount->_Branch._ID;
        clsBranch* branch = Branches.FindBranchByID(NewAccount->_Branch._ID);
        if (!branch)
        {
            cout << "\nThere is no such Branch with this ID";
            delete NewAccount;
            return;
        }

        cin.ignore(1, '\n');
        cout<<'\n';
        cout << setw(37) << left << "" << "\tEnter Account ID : ";

        getline(cin, NewAccount->_AccountID);
        branch->AddAccount(NewAccount->_AccountID); // if its found branch
        NewAccount->Next = NULL;





        if (IsIdNumberIsUnique(NewAccount->_AccountID))
        {
           cout << setw(37) << left << "" <<"\tAccount Name     : ";

            // cin.ignore(1,'\n');
            getline(cin, NewAccount->_Name);
           cout << setw(37) << left << "" <<"\tAccount Address  : ";

            //cin.ignore(1,'\n');
            getline(cin, NewAccount->_Address);


            cout << setw(37) << left << "" <<"\tAccount Email    : ";
            getline(cin, NewAccount->_Email);


            cout << setw(37) << left << "" <<"\tAccount Phone    : ";
            getline(cin, NewAccount->_PhoneNumber);


            cout << setw(37) << left << "" <<"\tAccount Balance  : ";
            cin >> NewAccount->_AccountBalance;

           cout << setw(37) << left << "" <<"\tAccount PIN Code : ";
            cin.ignore(1, '\n');
            getline(cin, NewAccount->_PINCode);

            if (Head == NULL)
            {
                Head = NewAccount;
            }
            else
            {
                clsHolderAccount* Current = Head;
                while (Current->Next != NULL)
                {
                    Current = Current->Next;
                }
                Current->Next = NewAccount;
            }
            cout<<'\n';
            cout << setw(37) << left << "" <<"\t============================\n";
            cout << setw(37) << left << "" <<"\tAccount Added Successfully!\n";
            cout << setw(37) << left << "" <<"\t============================\n";


        }
        else
        {
            cout << "\nAccount Already Exists. Please try another ID.";
            delete NewAccount;
        }

    }

    void RemoveHolder(const string& AccountID)
    {

        if (!IsIdNumberIsUnique(AccountID))
        {


            clsHolderAccount* CurrentDelPtr = Head, * Previous = Head;
            //Empty
            if (Head == NULL)
            {
                cout << "\nThere is no Holders in the Data Base";
                return;
            }
            //Delete First
            if (CurrentDelPtr->_AccountID == AccountID)
            {
                Head = CurrentDelPtr->Next;
                delete CurrentDelPtr;
                cout << "\nAccount Removed Successfully!";
                return;
            }
            //Serch for Node we want to delete
            while (CurrentDelPtr != NULL && CurrentDelPtr->_AccountID != AccountID)
            {
                Previous = CurrentDelPtr;
                CurrentDelPtr = CurrentDelPtr->Next;

            }

            if (CurrentDelPtr == NULL)
            {
                cout << "\nThis Account doesn't exist.";
                return;
            }

            //link prev by the next of the current we want to delete
            Previous->Next = CurrentDelPtr->Next;
            delete CurrentDelPtr;
            cout << "\nAccount Removed Successfully!";


        }
        else { cout << "\nThis Account dosen't Exist "; }

    }
    clsHolderAccount* FindAccount(const string& AccountID)
    {
        clsHolderAccount* Current = Head;
        while (Current != NULL)
        {
            if (Current->_AccountID == AccountID)
            {
                return Current;
            }
            Current = Current->Next;
        }
        return NULL;

    }


    void SerchHolderByName(bool &IsFirstTime,const string& AccountName)
    {

        clsHolderAccount* Current = Head;

        while (Current != NULL)
        {
            if (Current->_Name == AccountName)
            {
                system("cls");
                cout << "\nAccount of ID  " << Current->_AccountID << " is  found !!\n\n";

                cout << setw(37) << left << "" << "==============================\n";
                cout << setw(37) << left << "" << "\tSearch For Holder Screen\n";
                cout << setw(37) << left << "" << "==============================\n\n";
                cout <<"\n\n" << setw(37) << left << "" << "--[Account Operations]-- \n\n";
                cout << setw(37) << left << "" << "\t[1] Display Data Account.\n";
                cout << setw(37) << left << "" << "\t[2] Remove Account.\n";
                cout << setw(37) << left << "" << "\t[3] Set New PIN Code.\n";
                cout << setw(37) << left << "" << "\t[0] Back To Menu.\n\n";
                cout << setw(37) << left << "" << "\tEnter Opration [1-3]: ";
                int Choice; cin >> Choice;
                switch (Choice)
                {
                case 1:
                {
                    _PrintHolderCard(Current->_AccountID);
                    IsFirstTime = false;
                    return;

                }break;
                case 2:
                {
                    RemoveHolder(Current->_AccountID);
                    IsFirstTime = false;
                    return;

                }break;
                case 3:
                {

                    string NewPinCode;
                    cout << setw(37) << left << "" << "\tEnter the new PIN Code : ";
                    cin >> NewPinCode;
                    Current->_PINCode = NewPinCode;
                    cout << "\nPIN code has been sucessfully updated";
                    IsFirstTime = false;
                    return;


                }break;

                case 0:
                    IsFirstTime = true;
                    return;

                }break;

            }
            Current = Current->Next;
        }

        cout << "\nThere is no account with such name";


    }
    void UpdateHolderInfo(bool &IsFirstTime,const string& AccountID)
    {


        clsHolderAccount* Current = FindAccount(AccountID);
        if (Current == NULL)
        {
            cout << "\nThis Holder Information does not exist";
            return;
        }

        int Choice = 1;
        while (Choice != 0)
        {
            system("cls");
            cout << setw(37) << left << "" << "=======================================\n";
            cout << setw(37) << left << "" << "\tUpdate Holder Information Screen\n";
            cout << setw(37) << left << "" << "=======================================\n\n";
            cout << setw(37) << left << "" << "\t[1] Update Phone.\n";
            cout << setw(37) << left << "" << "\t[2] Update Email.\n";
            cout << setw(37) << left << "" << "\t[3] Update Address.\n";
            cout << setw(37) << left << "" << "\t[4] Update PIN Code.\n";
            cout << setw(37) << left << "" << "\t[0] Back Forword.\n\n";
            cout << setw(37) << left << "" << "\tEnter Opration [1-4]: ";
            cin >> Choice;
            switch (Choice)
            {
            case 1:
            {
                string Phone;
                cout << "\nEneter the new Phone Number : ";
                cin >> Phone;
                Current->_PhoneNumber = Phone;
                cout << "\nPhone Number has been Updated";
                IsFirstTime = false;

                return;
            }break;
            case 2:
            {
                string Email;
                cout << "\nEneter the new Email : ";
                cin >> Email;
                Current->_Email = Email;
                cout << "\nEmail has been Updated";
                IsFirstTime = false;
                return;

            }break;

            case 3:
            {
                string Address;
                cout << "\nEneter the new Address : ";
                cin >> Address;
                Current->_Address = Address;
                cout << "\nAddress has been Updated";
                IsFirstTime = false;

            }break;
            case 4:
            {
                string PinCode;
                cout << "\nEneter the new PIN Code : ";
                cin >> PinCode;
                Current->_PINCode = PinCode;
                cout <<"\PIN Code has been Updated";
                IsFirstTime = false;
                return;

            }break;
            case 0:
            {
                return;
            }break;
            }

        }

    }

    void DisplayHoldersData(const string &BranchID)
    {
        bool IsFound = false;
        clsHolderAccount* Current = Head;
        while (Current != NULL)
        {
            if (Current->_Branch._ID == BranchID)
            {
                IsFound = true;
                cout << "\t| " << setw(15) << left << Current->_Name;
                cout << "| " << setw(20) << left << Current->_AccountID;
                cout << "| " << setw(12) << left << Current->_Address;
                cout << "| " << setw(20) << left << Current->_Email;
                cout << "| " << setw(10) << left << Current->_PhoneNumber;
                cout << "| " << setw(20) << left << Current->_AccountBalance;
                cout << "| " << setw(12) << left << Current->_PINCode;
                clsBranch* FoundBranch = Branches.FindBranchByID(Current->_Branch._ID);
                cout << "| " << setw(15) << left << FoundBranch->_BranchName;

            cout << endl;
            }
            Current = Current->Next;

        }
        if (!IsFound)
        {
            cout <<endl<< setw(50) << left  <<" "<<  "\t\tNo accounts lineked with this Branch" << endl;
        }

    }


    void _PrintHolderCard(const string& AccountID)
    {
        clsHolderAccount* Current = FindAccount(AccountID);
        if (Current == NULL)
        {
            cout << "\nThis ID does not Exist";
        }
        else
        {
            cout << "\Holder Card:";
            cout << "\n_________________________________\n";
            cout << "\n  Name             : " << Current->_Name;
            cout << "\n  AccountID        : " << Current->_AccountID;
            cout << "\n  Address          : " << Current->_Address;
            cout << "\n  Email            : " << Current->_Email;
            cout << "\n  PhoneNumber      : " << Current->_PhoneNumber;
            cout << "\n  AccountBalance   : " << Current->_AccountBalance;
            cout << "\n  PINCode          : " << Current->_PINCode;
             clsBranch* FoundBranch = Branches.FindBranchByID(Current->_Branch._ID);
            // if we delete the branch then try to display data for a client
            cout << "\n  BranchName       : " << (FoundBranch==NULL ? "###" : FoundBranch->_BranchName) << endl;
            cout << "\n_________________________________\n";
        }
    }

    void DisplayHoldersByBalance(const string& BranchID)
    {
        vector<clsHolderAccount*> holdersInBranch;
        clsHolderAccount* Current = Head;

        // allocate
        while (Current != NULL)
        {
            if (Current->_Branch._ID == BranchID)
            {
                holdersInBranch.push_back(Current);
            }
            Current = Current->Next;
        }

        if (holdersInBranch.empty())
        {
            cout << "\nNo accounts linked with this branch." << endl;
            return;
        }
        //sort with cmp function
        sort(holdersInBranch.begin(), holdersInBranch.end(), [](clsHolderAccount* a, clsHolderAccount* b)
        {
            return a->_AccountBalance > b->_AccountBalance;
        });

        cout << "\nAccounts in Branch " << BranchID << " sorted by Balance:" << endl;
        cout << "\n\t| " << setw(15) << left << "Name"
             << "| " << setw(20) << left << "Account ID"
             << "| " << setw(12) << left << "Address"
             << "| " << setw(20) << left << "Email"
             << "| " << setw(10) << left << "Phone"
             << "| " << setw(20) << left << "Balance"
             << "| " << setw(12) << left << "PINCode"
             << "| " << setw(15) << left << "Branch" << endl;
            cout << "\n\t___________________________________________________________________________";
            cout << "______________________________________________________________________________\n" << endl;

        for (clsHolderAccount* holder : holdersInBranch)
        {
            clsBranch* FoundBranch = Branches.FindBranchByID(holder->_Branch._ID);
            cout << "\t| " << setw(15) << left << holder->_Name
                 << "| " << setw(20) << left << holder->_AccountID
                 << "| " << setw(12) << left << holder->_Address
                 << "| " << setw(20) << left << holder->_Email
                 << "| " << setw(10) << left << holder->_PhoneNumber
                 << "| " << setw(20) << left << holder->_AccountBalance
                 << "| " << setw(12) << left << holder->_PINCode
                 << "| " << setw(15) << left << (FoundBranch ? FoundBranch->_BranchName : "Unknown Branch") << endl;
        }
           cout << "\n\t___________________________________________________________________________";
           cout << "______________________________________________________________________________\n" << endl;

}



};
#endif // BANKMANGEMENTSYSTEM_H_INCLUDED





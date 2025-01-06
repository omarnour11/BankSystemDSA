#ifndef CLSBRANCH_H_INCLUDED
#define CLSBRANCH_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "ClsBankManageSystem.h"
using namespace std;
void DisplayHolderData(const string& AccountID);

class clsBranch
{
public:
    string _BranchID;
    string _BranchName;
    string _BranchLocation;
    vector<string> _AccountIDs;


    clsBranch(string id, string name, string location)
    {
        _BranchID = id;
        _BranchName = name;
        _BranchLocation = location;
    }

    // Getters


    // Add an Account to the Branch
    void AddAccount(string AccountID)
    {
        _AccountIDs.push_back(AccountID);
    }

    // Display Branch Information
    void DisplayBranchInfo() const
    {
         cout<<"\n\n  ______________________\n";
        cout<< "\n  Branch ID      : " << _BranchID
            << "\n  Branch Name    : " << _BranchName
            << "\n  Branch Location: " << _BranchLocation;
        cout<<"\n  ______________________\n";

    }
};

class clsBranchesMangement
{
public:
    vector<clsBranch> vecBranches;

    void AddBranch(clsBranch branch)
    {
        vecBranches.push_back(branch);
    }
    void RemoveBranchByID(string BranchID)
    {
        for (int i = 0; i < vecBranches.size(); i++)
        {
            if (vecBranches[i]._BranchID == BranchID)
            {
                vecBranches.erase(vecBranches.begin() + i);
                return ;
            }
        }
        cout << "Branch with ID " << BranchID << " not found.\n";
    }

    clsBranch* FindBranchByID(string BranchID)
    {
        for (int i = 0; i < vecBranches.size(); i++)
        {
            if (vecBranches[i]._BranchID == BranchID)
            {
                return &vecBranches[i];
            }
        }
        return nullptr;
    }
    clsBranch* FindBranchsByID(string BranchID)
    {
        for (clsBranch &B: vecBranches) {
            if (B._BranchID== BranchID)
            {
                return &B;
            }

        }
        return NULL;
    }
    void DisplayAllBranches()
    {
        if (vecBranches.size() == 0)
        {
            cout << "No branches available." << endl;
        }
        else
        {
            for (int i = 0; i < vecBranches.size(); i++)
            {
                vecBranches[i].DisplayBranchInfo();
                cout << "----------------------------" << endl;
            }
        }
    }
    void DisplayAllBranchesIDsAndNames()
    {
        if (vecBranches.empty())
        {
            cout << "No branches available." << endl;
        }
        else
        {
            cout << " [ ";
            for (int i = 0; i < vecBranches.size()-1; i++)
            {
                cout << vecBranches[i]._BranchName << ":" << vecBranches[i]._BranchID << " | ";
            }
                cout << vecBranches[vecBranches.size()-1]._BranchName << ":" << vecBranches[vecBranches.size()-1]._BranchID;
            cout << " ] : ";

        }
    }

    void DisplayBranchByID(string BranchID)
    {
        clsBranch* branch = FindBranchByID(BranchID);
        if (branch != nullptr)
        {
            branch->DisplayBranchInfo();
        }
        else
        {
            cout << "Branch with ID " << BranchID << " not found." << endl;
        }
    }




};

#endif // CLSBRANCH_H_INCLUDED

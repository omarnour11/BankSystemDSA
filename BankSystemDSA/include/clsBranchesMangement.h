#ifndef CLSBRANCHESMANGEMENT_H
#define CLSBRANCHESMANGEMENT_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "ClsBankManageSystem.h"

class clsBranchesMangement
{
private:
    vector<clsBranch> _Branches;
    string DataFile = "BranchesInfo.txt";
public:
    clsBranchesMangement() {}
    virtual ~clsBranchesMangement() {}


        // Method to add a branch
    void AddBranch(clsBranch branch)
    {
        _Branches.push_back(branch);
        //SaveDataToFileText(_Branches);
    }
    // Method to remove a branch by ID
    bool RemoveBranchByID(string BranchID)
    {
        for (int i = 0; i < _Branches.size(); i++)
        {
            if (_Branches[i]._BranchID == BranchID)
            {
                _Branches.erase(_Branches.begin() + i);
                return true;
            }
        }
        return false;
    }

    // Method to find a branch by ID
    clsBranch* FindBranchByID(string BranchID)
    {
        for (int i = 0; i < _Branches.size(); i++)
        {
            if (_Branches[i]._BranchID == BranchID)
            {
                return &_Branches[i];
            }
        }
        return nullptr;
    }
    clsBranch* FindBranchsByID(string BranchID)
    {
        for (clsBranch &B: _Branches) {
            if (B._BranchID== BranchID)
            {
                return &B;
            }

        }
    }
    // Method to display all branches
    void DisplayAllBranches()
    {
        if (_Branches.size() == 0)
        {
            cout << "No branches available." << endl;
        }
        else
        {
            for (int i = 0; i < _Branches.size(); i++)
            {
                _Branches[i].DisplayBranchInfo();
                cout << "----------------------------" << endl;
            }
        }
    }
    void DisplayAllBranchesIDsAndNames()
    {
        if (_Branches.empty())
        {
            cout << "No branches available." << endl;
        }
        else
        {
            cout << " [ ";
            for (int i = 0; i < _Branches.size()-1; i++)
            {
                cout << _Branches[i]._BranchName << ":" << _Branches[i]._BranchID << " | ";
            }
                cout << _Branches[_Branches.size()-1]._BranchName << ":" << _Branches[_Branches.size()-1]._BranchID;
            cout << " ] : ";

        }
    }

    // Method to display a branch by ID
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


    void SaveDataToFileText(vector<clsBranch> Branches)
    {
        ofstream outputFile(DataFile, ios::out);

        if (!outputFile) {
            cout << "Error: Could not open file for writing!" << endl;
            return;
        }
       // vector<clsBranch> _Branches;

        // Write data for each account
        for (clsBranch& B: Branches)
        {



            outputFile << B._BranchID << "~"
                << B._BranchName << "~"
                << B._BranchLocation << endl;

        }

        outputFile.close();
        cout << "\nData saved to " << DataFile << " successfully!" << endl;
    }
    vector <string>split(string s1, string delim) {

        vector <string> vstring;
        short pos = 0;
        string word;
        //use find() function to get the position of the edlimiters;
        while ((pos = s1.find(delim)) != std::string::npos)
        {
            word = s1.substr(0, pos);//store the word
            //if (word != "")
            //{
            vstring.push_back(word);
            //}
            s1.erase(0, pos + delim.length());
        }
        if (s1 != "")
        {
            vstring.push_back(s1);
        }
        return vstring;
    }
    clsBranch ConvertLineToObject(string Line) {
        vector<string>vBranch;
        vBranch = split(Line, "~");
        return clsBranch(vBranch[0], vBranch[1], vBranch[2]);
    }
    //vector<clsBranch> LoadBranchesFromFile()
    //{
    //    vector<clsBranch>vBranches;
    //    fstream MyFile;
    //    MyFile.open(DataFile, ios::in);
    //    if (MyFile.is_open())
    //    {
    //        string Line;
    //
    //        while (getline(MyFile,Line))
    //        {
    //          clsBranch Branch = ConvertLineToObject(Line);
    //          vBranches.push_back(Branch);
    //        }
    //        MyFile.close();
    //        return vBranches;
    //    }
    //}





};

#endif // CLSBRANCHESMANGEMENT_H

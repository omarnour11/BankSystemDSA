#ifndef PRINTSCREENFILES_H
#define PRINTSCREENFILES_H
#include <iostream>
#include "clsHolderAccount.h"
#include <fstream>
#include <string>
#include <iomanip>
#include "clsBranches.h"
#include "PrintScreenFiles.h"
#include "ClsBankManageSystem.h"

void PrintMainMenuScreen()
{
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
}



#endif // PRINTSCREENFILES_H

//
// Created by Yumeng Zhang on 5/4/23.
//

#include "template.h"

void use_template(){

    CMyFirstTemplateClass <int> mHoldInteger;   // Template instantiation
    mHoldInteger.SetVariable(5);
    cout << "The value stored is: " << mHoldInteger.GetValue () << endl;

    CMyFirstTemplateClass <char*> mHoldString;
//    mHoldInteger.SetVariable("Sample string");
//    std::cout << "The value stored is: " << mHoldInteger.GetValue ();
    char* str = new char[14];
    strcpy(str, "Sample string");
    mHoldString.SetVariable(str);
    cout << "The value stored is: " << mHoldString.GetValue() << endl;
    delete[] str;

    CMyFirstTemplateClass <string> mHoldString2;
    string str2 = "Bruce!!!";
    mHoldString2.SetVariable(str2);
    cout << "The value stored is: " << mHoldString2.GetValue() << endl;


    int nInteger1 = 25;
    int nInteger2 = 40;
    int nMaxValue = GetMax <int> (nInteger1, nInteger2);
    cout << nMaxValue << endl;

    double dDouble1 = 1.1;
    double dDouble2 = 1.001;
    double dMaxValue = GetMax <double> (dDouble1, dDouble2);
    cout << dMaxValue << endl;

}
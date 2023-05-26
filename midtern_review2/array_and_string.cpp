//
// Created by Yumeng Zhang on 5/2/23.
//

#include "array_and_string.h"

void array_string(){

    enum WeekDays { Sun, Mon, Tue, Wed, Thu, Fri, Sat, DaysInWeek };
    int ArrayWeek[DaysInWeek] = { 10, 20, 30, 40, 50, 60, 70 };

    cout << "The value at Tuesday is: " << ArrayWeek[Tue] << endl;
    char Greeting[] = "Hello World";

    cout << Greeting << endl;

    char buffer[80] = {'\0'};
    cout << "Enter the string: ";
    cin.get(buffer, 79);
    cout << "Here’s the buffer: " << buffer << endl;

    char String1[] = "No man is an island";
    char String2[80] = {'\0'};

    strcpy(String2,String1);

    const int MaxLength = 80;
    strncpy(String2, String1, MaxLength);  // safer than strcpy

    cout << "String2: " << String2 << endl;

    string str1 ("This is a C++ string! ");

    int nArrayLength = 50;
    const char* pszString = new char [nArrayLength];  // dynamic allocation of data

    pszString = "In the Frozen";

    string strFromConst (pszString);
    cout << strFromConst << endl;

    string strPartialCopy (strFromConst, 6);   // " Frozen"
    cout << strPartialCopy << endl;

    string strPartialCopy2 (pszString, 6);       // "In the"
    cout << strPartialCopy2 << endl;

    const char* pszConstString = "Hello World!"; // To be copied

    // To create a copy, first allocate memory for one
    char * pszCopy = new char [strlen (pszConstString) + 1];
    strcpy (pszCopy, pszConstString);  // The copy step

    cout << pszCopy << endl;

    // deallocate memory after using pszCopy
    delete [] pszCopy;


    string strSTLString ("Summertime");

    // Access the contents of the string using array syntax
    cout << "Displaying characters using array-syntax: " << endl;
    for (size_t nCharCounter = 0; nCharCounter < strSTLString.length(); ++nCharCounter){
        cout << strSTLString[nCharCounter] << endl;
    }
    cout << endl;

    // Access the contents of a string using iterators
    cout << "Displaying characters using iterators: " << endl;
    int nCharOffset = 0;
    string::const_iterator iCharacterLocator;
    for(iCharacterLocator = strSTLString.begin(); iCharacterLocator != strSTLString.end(); ++iCharacterLocator){
        cout << *iCharacterLocator << endl;  // attention
    }

}

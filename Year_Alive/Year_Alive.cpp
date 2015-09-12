/* Problem 1:
Description : Given a list of people with their birth and end years (all between 1900 and 2000), find the year with the most number of people alive.
Code        : Solve using a language of your choice and dataset of your own creation.
Submission  : Please upload your code, dataset, and example of the program’s output to Bit Bucket or Github. Please include any graphs or charts created by your program.

Language -> C++,  IDE -> Microsoft Visual Studio Community 2015 RC vs 14.0.22823.1
Inputs -> Read from file "input.txt" via command prompt. The first line in the input file is the number of persons in the list. The next values are the birth year and the death years of different persons.
This means the file follows the sequence "Number of Persons" "Birth Year" "Death Year" "Birth Year" "Death Year" .... so on
*/

#include "stdafx.h"
#include <iostream>
#include "Alive.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    unsigned int n;                          // number of persons in the list
    cin >> n;

    Person *p = new Person[n];

    for (int i = 0; i < n; i++)
    {
        cin >> p[i].birth_year;             // Birth year of person[i]
        cin >> p[i].death_year;             // Death year of person[i]
    }

    int max = findYearWithMaxAlive(n,p);
    if (max != 0)
    {
        cout << "Year With Maximum number of alive people = " << max << "\n";
    }
    else
    {
        cout << "No common year with alive people"<< "\n";
    }

    delete[] p;
    return 0;
}


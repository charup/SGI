#include "stdafx.h"
#include <unordered_map>
#include "Alive.h"

using namespace std;

// Global variable declaration
int min_birth_year = 1900;                      // Given
int max_death_year = 2000;                      // Given

int findYearWithMaxAlive(unsigned int n, Person *listOfPersons)
{
    unsigned int size_list = n;

    static unordered_map<int, unsigned int> peopleAliveInYear;
    
    //initialize the unordered map
    for (int i = min_birth_year; i <= max_death_year; i++)
    {
        peopleAliveInYear.insert(make_pair(i,0));
    }
    
    //calculate the number of people alive in each year
    int key;
    
    for (unsigned int i = 0; i < size_list; i++)
    {
        for (key = listOfPersons[i].birth_year; key <= listOfPersons[i].death_year; key++)
        {
            peopleAliveInYear[key] += 1;
        }
    }

    //find the year with max people alive
    int yearWithMaxPeopleAlive = 0;
    unsigned int maxAliveInYear = 0;
    int yearsWithSameAliveNo = 0;
    
    for (key = min_birth_year; key <= max_death_year; key++)
    {
        if (peopleAliveInYear[key] > maxAliveInYear)
        {
            maxAliveInYear = peopleAliveInYear[key];
            yearWithMaxPeopleAlive = key;
            yearsWithSameAliveNo = 1;
        }
        else if (peopleAliveInYear[key] == maxAliveInYear && maxAliveInYear != 0)
            yearsWithSameAliveNo++;            
    }
    return yearWithMaxPeopleAlive;
}

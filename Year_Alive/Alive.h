#pragma once

struct Person
{
    int birth_year;
    int death_year;
};

int findYearWithMaxAlive(unsigned int n, Person *p);     // function to find the year with maximum number of people alive 

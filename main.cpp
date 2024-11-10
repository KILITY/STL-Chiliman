#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    vector<string> doctors, problems, problems_specialty;
    ifstream inFile("/Users/killity/Vss projects/STL COURSE/STL/input.txt");

    int no_problems, no_doctors;
    string name, speciality;
    inFile >> no_problems;
    for (int i = 0; i < no_problems; i++)
    {
        inFile >> name;
        inFile >> speciality;
        problems.push_back(name);
        problems_specialty.push_back(speciality);
    }

    inFile >> no_doctors;

    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> name;
        inFile >> speciality;
        doctors.push_back(speciality);
    }

    for (int i = 0; i < no_problems; i++)
    {
        int nr = 0;
        for (int j = 0; j < no_doctors; j++)
            if (problems_specialty[i] == doctors[j] && nr == 0)
            {
                cout << problems[i] << " acceptat"<<endl;
                nr++;
                break;
            }
        if (nr == 0)
            cout<< problems[i] << " respins"<<endl;
    }

    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
    ifstream inFile("/Users/killity/Vss projects/STL Course -Mine/STL - Fork/STL-Chiliman-1/input4_bonus.txt");

    int no_problems, no_doctors;

    vector<string> doctor, doctor_specialty, problems_solved, pacient_problem, pacient_problem_specialty;
    vector<int> doctor_available_hours, pacient_needed_hours, nr_problems;

    string name, specialty;
    int hours;

    inFile >> no_problems;

    for (int i = 0; i < no_problems; i++)
    {
        inFile >> name;
        inFile >> specialty;
        inFile >> hours;

        pacient_problem.push_back(name);
        pacient_problem_specialty.push_back(specialty);
        pacient_needed_hours.push_back(hours);
    }

    inFile >> no_doctors;

    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> name;
        inFile >> specialty;

        doctor.push_back(name);
        doctor_specialty.push_back(specialty);
        doctor_available_hours.push_back(8); // am citit toate datele si le-am organizat in 6 vectori, 3 pt pacienti 3 pt doctori

        nr_problems.push_back(0); // Initialize nr_problems to 0 for each doctor
        problems_solved.push_back(""); // Initialize problems_solved as an empty string for each doctor
    }

    for (int i = 0; i < no_problems; i++) // pentru fiecare pacient vreau sa ma uit daca are un doctor cu aceea specializare
    {
        auto it = find(doctor_specialty.begin(), doctor_specialty.end(), pacient_problem_specialty[i]);

        bool we_found = false;

        while (it != doctor_specialty.end() && we_found == false) // cat tim
        {

            int index = it - doctor_specialty.begin();
            if (doctor_available_hours[index] >= pacient_needed_hours[i]) // doctorul a verificat si are destule ore sa-l trateze
            {
                doctor_available_hours[index] -= pacient_needed_hours[i]; // l-am programat pe pacient
                nr_problems[index]++;                                     // scorul doctorului a crescut
                problems_solved[index].append(pacient_problem[i]);        // updatez arhiva spitalul
                problems_solved[index].append(" ");
                we_found = true;
            }
            it = find(it + 1, doctor_specialty.end(), pacient_problem_specialty[i]); // cautam din nou
        }
    }

    for (int i = 0; i < no_doctors; i++)
    {
        cout << doctor[i] << " " << nr_problems[i] << " ";
        cout << problems_solved[i] << " ";
        cout << endl;
    }

    return 0;
}

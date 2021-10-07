#include <iostream>
#include <vector>
#include "std_lib_facilities.h"

int main()
{
    double x = 1;                       //Változók deklarálása
    double mini=9999;
    double maxi=1;
    string unit;

    const int cm_per_m = 100;
    const double cm_per_in = 2.54;      //Átváltások
    const int in_per_ft = 12;

    vector<double> lengths;

    double total_length_meter = 0;      //Változók deklarálása

    cout << "Please declare any number of lengths, each followed by a measurement (cm, m, ft, in)!\n"
    << "Once you've entered all the lengths you wanted, type any non-numeric character, followed by an Enter to end the loop.\n\n";

    while(cin >> x >> unit){                      //Ha nem számot adnak meg hossznak, kilép a loopból

        if (x >=0){                               //Csak akkor törődöm vele, ha a hossz nem negatív!


            if (unit != "m" && unit != "cm" && unit != "ft" && unit != "in") cout << "Invalid unit!\n";

                else {cout << "Length added\n";

                if (x <= mini)              //Ha x kisebb az eddigi minimumnál, õ az új minimum
                mini = x;
                if (x >= maxi)              //Ha x nagyobb az eddigi maximumnál, õ az új maximum
                maxi = x;
                }

            if (unit == "m")
                {total_length_meter += x;      //Ha méterben adtuk meg, egyszerûen hozzáadjuk a szumhoz
                lengths.push_back(x);}         //..valamint simán betesszük a vektorba

                else if (unit == "cm")
                    {x = x/cm_per_m;                 //*Ha nem méterben adtuk meg, átváltjuk
                    total_length_meter += x;
                    lengths.push_back(x);}           //**valamint az immár átváltott x-et betesszük a vektorba

                    else if (unit == "in")
                        {x = x*cm_per_in/cm_per_m;                    //*
                        total_length_meter += x;
                        lengths.push_back(x);}                        //**

                        else if (unit == "ft")
                            {x = x*in_per_ft*cm_per_in/cm_per_m;      //*
                            total_length_meter += x;
                            lengths.push_back(x);}                    //**

            }
                else cout << "Lengths cannot be negative!\n";
    }


    cout << "Total length in meters: " << total_length_meter << " m\n"
    << "The largest value entered: " << maxi << "\n"
    << "The smallest value entered: " << mini << "\n";


    sort(lengths);
    cout << "\nEvery value converted to meters, and sorted:\n";
    for (int i=0; i < lengths.size(); ++i)
        cout << lengths[i] << "\n";

    return 0;
}

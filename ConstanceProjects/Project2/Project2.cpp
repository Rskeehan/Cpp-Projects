#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <vector>

using namespace std;

int main() 
{
    //declare initial constants
    const double aPremium = 10, bPremium = 25, cPremium = 50, 
        aDeductible = 200, bDeductible = 200, cDeductible = 0, 
        aCopay = .4, bCopay = .4, cCopay = 0, prescriptionUnitCost = 50; 
    
    //declare initial variables
    double selectPrem, selectDeductable, selectCopay;
    char redo = 'Y';

    //create outer loop for overall estimation program change
    while (redo == 'Y' || redo == 'y')
    {
        //display each plan's details
        std::cout
        << "Plan A" << endl
        << " Monthly Premium: $" << aPremium << endl
        << " Deductible $" << aDeductible << endl
        << " Copay " << aCopay*100 << "%" <<endl
        << "Plan B" << endl
        << " Monthly Premium: $" << bPremium << endl
        << " Deductible $" << bDeductible << endl
        << " Copay " << bCopay*100 << "%" <<endl
        << "Plan C" << endl
        << " Monthly Premium: $" << cPremium << endl
        << " Deductible $" << cDeductible << endl
        << " Copay " << cCopay*100 << "%" <<endl;

        //declare and init input sanitization variable
        bool goodInput = 0;
        char plan;
        //loop plan selection while goodInput is false
        while (!goodInput)
        {
            std::cout << endl << "Please select a plan (enter A, B, or C): ";
            std::cin >> plan;

            //assign selected plan values from constants
            switch (plan)
            {
            case 'A': case 'a':
                goodInput = !goodInput; // set to good input
                selectPrem       = aPremium;
                selectDeductable = aDeductible;
                selectCopay      = aCopay;
                break;

            case 'B': case 'b':
                goodInput = !goodInput;
                selectPrem       = bPremium;
                selectDeductable = bDeductible;
                selectCopay      = bCopay;
                break;

            case 'C': case 'c':
                goodInput = !goodInput;
                selectPrem       = cPremium;
                selectDeductable = cDeductible;
                selectCopay      = cCopay;
                break;

            default:
                std::cout << endl << "Sorry, " << plan << " is not a valid answer.";
                break;            
            }
        } // end plan select input verification loop

        //get estimated prescriptions, and check input
        int estPrescriptions;
        goodInput = !goodInput; //set to 0 again for next check

        //get valid number of prescription inputs
        while (!goodInput)
        {
            std::cout << "Please enter the estimated number of prescriptions (0 to 96): ";
            std::cin >> estPrescriptions;

            if (estPrescriptions >= 0 && estPrescriptions <= 96)
            {
                goodInput = !goodInput; // set true
            }
            else
            {
                std::cout << endl << "Sorry, " << estPrescriptions << " is not a valid number of prescriptions. Please try again."<< endl;
            }
        } // end prescription number input validation

        //Declare necesary variables for calculating annual cost of plan
        double cost, annualPremium, overDeductible, prescriptionAnnualCost;

        //calculate cost
        annualPremium          = selectPrem * 12;
        prescriptionAnnualCost = estPrescriptions * prescriptionUnitCost;
        overDeductible         = prescriptionAnnualCost - selectDeductable;
        cost = annualPremium + selectDeductable + overDeductible * selectCopay;

        //Output estimate
        std::cout << "Plan " << plan << " cost for " << estPrescriptions << " prescriptions is $" << cost << endl;

        //prompt for another go-around
        std::cout << "Would you like another plan cost estimate? (y/n): ";
        std::cin >> redo;
    }

    return EXIT_SUCCESS;
}
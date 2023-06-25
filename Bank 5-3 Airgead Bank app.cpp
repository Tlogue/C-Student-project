// Bank 5-3 Airgead Bank app.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <iomanip>

// Function to print the details of the balance at the end of each year
void printDetails(int yearIndex, double balance, double interestEarnedThisYear) {
    std::cout << "Year " << yearIndex << ": Balance $" << std::fixed << std::setprecision(2) << balance
        << " | Interest Earned $" << interestEarnedThisYear << std::endl;
}

// Function to calculate the balance without making a monthly deposit
double calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears) {
    double balance = initialInvestment;  // Initialize the balance with the initial investment
    double interestEarned;  // Variable to store the interest earned in each year

    // Loop for number of years to calculate the balance
    for (int year = 1; year <= numberOfYears; year++) {
        // Calculate the interest earned by multiplying the balance by the interest rate divided by 100 and divided by 12
        interestEarned = balance * (interestRate / 100) / 12;
        // Increase the balance by the interest earned
        balance += interestEarned;
        // Call the printDetails function to print the details of the balance and interest earned in each year
        printDetails(year, balance, interestEarned);
    }

    // Return the final balance after number of years
    return balance;
}

double balanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears) {
    double balance = initialInvestment;
    double monthlyInterestRate = ((interestRate / 100) / 12);

    for (int year = 1; year <= numberOfYears; year++) {
        double interestEarnedThisYear = 0.0;
        double interestEarnedThisMonth = balance * monthlyInterestRate;
        for (int month = 1; month <= 12; month++) {
            interestEarnedThisYear += interestEarnedThisMonth;
            balance += interestEarnedThisMonth;
            if (month == 12) {
                balance += monthlyDeposit;
            }
        }
        printDetails(year, balance, interestEarnedThisYear);
    }
    return balance;
}

int main() {
    double initialInvestment, interestRate;  // Variables to store the initial investment and interest rate
    int numberOfYears;  // Variable to store the number of years
    double monthlyDeposit;

    std::cout << "Initial Investment Amount: $";
    std::cin >> initialInvestment;

    std::cout << "Monthly Deposit: $";
    std::cin >> monthlyDeposit;

    // Read the interest rate from the user
    std::cout << "Annual Interest: %";
    std::cin >> interestRate;

    // Read the number of years from the user
    std::cout << "Number of Years: ";
    std::cin >> numberOfYears;

    // Call the calculateBalanceWithoutMonthlyDeposit function to get the final balance after number of years
    double finalBalance = calculateBalanceWithoutMonthlyDeposit(initialInvestment, interestRate, numberOfYears);

    // Print the final balance after number of years
    std::cout << "\nReport Without Monthly Deposit: \n";
    std::cout << "Final Balance: $" << std::fixed << std::setprecision(2) << finalBalance << std::endl;
    std::cout << "\n";

    // Call the balanceWithMonthlyDeposit function to get the final balance after number of years
    finalBalance = balanceWithMonthlyDeposit(initialInvestment, monthlyDeposit, interestRate, numberOfYears);

    // Print the final balance after number of years
    std::cout << "Report With Monthly Deposit: \n";
    std::cout << "Final Balance: $" << std::fixed << std::setprecision(2) << finalBalance << std::endl;

    return 0;
}
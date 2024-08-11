#include <iostream>
#include <string>
#include <map>

using namespace std;

// Function to perform the Luhn algorithm to validate the card number
bool luhnCheck(const string& cardNumber) {
    int sum = 0;
    bool alternate = false;

    for (int i = cardNumber.length() - 1; i >= 0; --i) {
        int n = cardNumber[i] - '0';

        if (alternate) {
            n *= 2;
            if (n > 9) n -= 9;
        }

        sum += n;
        alternate = !alternate;
    }

    return (sum % 10 == 0);
}

// Function to check if the card number has a valid length and prefix
bool validateCardNumber(const string& cardNumber) {
    map<string, pair<int, int>> cardTypes = {
        {"4", {13, 16}},        // Visa: 13 or 16 digits
        {"51", {16, 16}},       // MasterCard: 16 digits
        {"52", {16, 16}},
        {"53", {16, 16}},
        {"54", {16, 16}},
        {"55", {16, 16}},
        {"34", {15, 15}},       // American Express: 15 digits
        {"37", {15, 15}},
        {"6011", {16, 16}},     // Discover: 16 digits
        {"65", {16, 16}}
    };

    for (const auto& pair : cardTypes) {
        if (cardNumber.substr(0, pair.first.length()) == pair.first) {
            int length = cardNumber.length();
            if (length >= pair.second.first && length <= pair.second.second) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    string cardNumber;
    cout << "Enter a credit card number: ";
    cin >> cardNumber;

    bool valid = luhnCheck(cardNumber) && validateCardNumber(cardNumber);

    if (valid) {
        cout << "The credit card number is valid.\n";
    }
    else {
        cout << "The credit card number is invalid.\n";
    }

    return 0;
}


//


// Copyright (c) 2022 Aidan Lalonde-Novales All rights reserved

// Created by Aidan Lalonde-Novales
// Created on 2022-04-25
// This program is a number guessing game that has while/break components.

#include <iostream>
#include <string>
#include <random>


int main() {
    // this function checks if a guess is correct, prompts the
    // the user to try again if it isn't, and counts tries.
    int answer;
    int counter = 1;
    int guess;
    std::string guessString;

    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 9);  // [0, 9]
    answer = idist(rgen);

    // input
    std::cout << "Guess a number between 0 to 9: ";
    std::cin >> guessString;

    // process & output
    while (true) {
        try {
            guess = std::stoi(guessString);
            if (guess == answer) {
                break;
            } else if (guess > answer) {
                std::cout << "\nThat number is too high!" << std::endl;
            } else if (guess < answer) {
                std::cout << "\nThat number is too low!" << std::endl;
            } else {
                std::cout << "\nSomething went wrong." << std::endl;
            }
        } catch (std::invalid_argument) {
        std::cout << "\nSorry, that is not a valid integer." << std::endl;
        }

        std::cout << "Try Again: ";
        std::cin >> guessString;
        counter++;
    }

    // End of game output
    std::cout << "\nYou guessed Correctly! It took " << counter
    << " tries." << std::endl;
    std::cout << "\nDone." << std::endl;
}

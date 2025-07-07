//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <random>
#include <chrono>
#include <thread>
//#include <cmath>
//#include <algorithm>


using namespace std;

string playerName = "";
int limit = 1;
int guess = 0;

auto lastCondition = [](int guess, int randomNumber)->string {
    if (guess < randomNumber)
        return "cold)";
    else
        return "hot)";
};

void welcomeBar() {
    system("clear");
    cout << "Welcome to Guess-the-number, " << playerName << '!' << '\n';
    cout << "===========================\n";
}

int main() {
    // Create a random number engine (e.g., Mersenne Twister)
    // Seed with a truly random source if available (std::random_device)
    // or with a time-based seed for different sequences each run.
    std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
    // system("clear");
    cout << "Hello there, whats your name?\n";
    cout << "Enter name: ";
    cin >> playerName;

    welcomeBar();
    cout << "Please enter a limit for your gameplay (from 1 to 1,000,000,000): "; 
    cin >> limit;
    // Define a distribution (e.g., uniform integer distribution)
    std::uniform_int_distribution<> distrib(1, limit);
    // Generate a random number
    int randomNumber = distrib(gen);
    
    welcomeBar();
    while (guess != randomNumber) {
        welcomeBar();
        
        cout << "Number is between 0 and " << limit << '\n';
        if (guess != 0) 
            cout << "Your last guess: " << guess << " (" << lastCondition(guess, randomNumber) << '\n';

        cout << "Enter your guess: ";
        cout << "===========================\n";
        cin >> guess;

        if (guess > randomNumber)   
            cout << "\rDang that's hot!\n";
        else if (guess < randomNumber)
            cout << "\rWow that's cold!\n";
        cout << "===========================\n";

        this_thread::sleep_for(chrono::seconds(1));
    }   
    return 0;
}
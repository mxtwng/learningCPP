#include <iostream>
#include <string>
#include <cstdlib>
#include <random>
#include <chrono>
#include <thread>
//#include <cmath>
//#include <algorithm>
using namespace std;


class Games {

    string playerName = "";
    int limit = 1;
    int guess = 0;
    
    function<int,int> lastCondition = [](int guess, int randomNumber)->string {
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
    
    void numberGuessingGame() {
        // Create a random number engine (e.g., Mersenne Twister)
        // Seed with a truly random source if available (std::random_device)
        // or with a time-based seed for different sequences each run.
        std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
    
        system("clear");
        cout << "Hello there, whats your name?\n";
        do {
            cout << "Enter name: ";
        }
        while(!getline(cin, playerName));
    
        welcomeBar();
        cout << "Please enter a limit for your gameplay (from 1 to 1,000,000,000): ";
        while (true) {
            cin >> limit;
            if (cin.fail() && cin.fail() && (limit > 1000000000 || limit < 1)) {
                cout << "\033[F";               // Move cursor up
                cout << "\033[2K";              // Clear entire line
                cout << "Please enter an integer that is in the range from 1 to 1,000,000,000: ";
                cin.clear();
                cin.ignore(10000000001,'\n');
            } else 
                break;
        }
        // Define a distribution (e.g., uniform integer distribution)
        std::uniform_int_distribution<> distrib(1, limit);
        // Generate a random number
        int randomNumber = distrib(gen);
        
        while (guess != randomNumber) {
            welcomeBar();
            
            cout << "The secret number is in the range from 1 to " << limit << '\n';
            if (guess != 0) 
                cout << "Your last guess: " << guess << " (" << lastCondition(guess, randomNumber) << '\n';
    
            cout << "Enter your guess: ";
            cin >> guess;
    
            if (cin.fail()) {
                cout << "\n Please enter an integer!";
                cin.clear();    
                cin.ignore(100000000, '\n');
                this_thread::sleep_for(chrono::seconds(1));
                continue;
            }
    
            if (guess > randomNumber)   
                cout << "Dang that's hot!";
            else if (guess < randomNumber)
                cout << "Wow that's cold!";
            cout << '\n';
    
            this_thread::sleep_for(chrono::seconds(1));
        }
        welcomeBar();
        cout << "Congrats you got it! \n";
        cout << "The secret number was " << randomNumber;
    }
};

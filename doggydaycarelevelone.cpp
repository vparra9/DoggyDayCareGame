#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class LevelZero {
private:
    string name;
    string dayCareName;
    int balance;
    int service;
    int points;
    int day;

public:
    // Constructor
    LevelZero(int initialBalance) : balance(initialBalance), points(0), day(0), service(0) {
        cout << "Balance: " << balance << endl;
        cout << "\nPoints: " << points << endl;
        cout << "\nDay " << day << endl;
    }

    // Method to get current points
    int getPoints() const {
        return points;
    }

    // Player name
    string getName() const {
        return name;
    }

    void setName(const string& newName) {
        name = newName;
    }

    // Daycare name
    string getDayCareName() const {
        return dayCareName;
    }

    void setDayCareName(const string& newDayCareName) {
        dayCareName = newDayCareName;
    }

    // Service
    int getService() {
        return service;
    }

    void setService(int& newService) {
        // Loop until a valid service number (1, 2, or 3) is entered
        while (true) {
            if (newService == 1) {
                cout << "\nYou chose grooming services." << endl;
                // Assign the selected service and break the loop
                service = newService;
                break;
            }
            else if (newService == 2) {
                cout << "\nYou chose walking services." << endl;
                // Assign the selected service and break the loop
                service = newService;
                break;
            }
            else if (newService == 3) {
                cout << "\nYou chose training services." << endl;
                // Assign the selected service and break the loop
                service = newService;
                break;
            }
            else {
                // Handle invalid input
                cout << "\nInvalid selection. Enter a number 1-3: ";
                // Prompt user for a new input
                cin >> newService;
            }
        }
    }

    // Add points
    void addPoints(int pointsToAdd) {
        points += pointsToAdd;
        cout << "\nDEBUG POINTS ADDED: " << points << endl;
    }
};

class LevelOne : public LevelZero {
public:
    LevelOne(int initialBalance) : LevelZero(initialBalance) {}

    // Task 1
    void interactionOne() {
        int choice;

        do {
            cout << "\n(Choose how to interact! Enter the corresponding number.)" << endl;
            cout << "\n1. You avoid eye contact and say nothing." << endl;
            cout << "\n2. You give a nice warm welcome." << endl;

            cin >> choice;

            switch (choice) {
            case 1:
                cout << "\nThe girl walks in and you say nothing. It is clear she feels uncomfortable." << endl;
                break;
            case 2:
                cout << "\nYou welcome the girl with a big smile. She immediately lightens up." << endl;
                addPoints(10);
                break;
            default:
                cout << "\nInvalid choice. Please enter 1 or 2." << endl;
                break;
            }
        } while (choice != 1 && choice != 2); // Repeat until valid choice
    }

    int interactionTwo(int& choice) {
        do {
            cout << "\n1. You decide to take a look at her resume." << endl;
            cout << "\n2. You decide to toss her resume out." << endl;

            cin >> choice;

            switch (choice) {
            case 1:
                cout << "\nYou take a look at her resume..." << endl;
                cout << "\nAna Green..." << endl;
                cout << "\nPrevious jobs: Babysitting..." << endl;
                cout << "\nHas experience with dogs, patient, and determined.." << endl;
                addPoints(10);
                break;
            case 2:
                cout << "\nYou throw away her resume and don't think twice about it." << endl;
                break;
            default:
                cout << "\nInvalid choice. Please enter 1 or 2." << endl;
            }
        } while (choice != 1 && choice != 2); // Repeat until valid choice

        return choice;
    }

    int interactionThree(int& choice) {
        do {
            cout << "\n1. You decide to take a nap." << endl;
            cout << "\n2. You decide to create a social media account to promote your business." << endl;

            cin >> choice;

            switch (choice) {
            case 1:
                cout << "\nYou don't think any customers will be coming in since it's the first day.." << endl;
                cout << "\nAnd the lack of sleep from last night is seriously starting to catch up.." << endl;
                cout << "\nZzzZZZzzzZZZZZzzz" << endl;
                break;
            case 2:
                cout << "\nYou decide to browse the internet for which social platform would be best to promote your business on." << endl;
                addPoints(10);
                break;
            default:
                cout << "\nInvalid choice. Please enter 1 or 2." << endl;
            }
        } while (choice != 1 && choice != 2); // Repeat until valid choice

        return choice;
    }

    int interactionFour(int& choice) {
        do {
            cout << "\n1. You decide to play with Buddy.. hopefully you can burn some of his energy out." << endl;
            cout << "\n2. You leave Buddy alone to roam.." << endl;

            cin >> choice;

            switch (choice) {
            case 1:
                cout << "\nYou look through the new toys you bought for your daycare." << endl;
                cout << "\nYou notice one in particular catches Buddy's eyes... a squeaky toy in the shape of a hot dog." << endl;
                cout << "\nYou throw the toy for Buddy and he brings it back to you each time. After 40 minutes of playing with him, he starts to seem more tired." << endl;
                addPoints(10);
                break;
            case 2:
                cout << "\nYou put Buddy in the playpen and leave him to be. He starts to whimper and bark obnoxiously." << endl;
                break;
            default:
                cout << "\nInvalid choice. Please enter 1 or 2." << endl;
            }
        } while (choice != 1 && choice != 2);

        return choice;
    }
};

int main() {
    string tempName;         // Temporary variable for name
    string tempDayCareName;  // Temp variable for daycare name
    int tempService;         // Temp variable for service selection
    int initialBalance = 20000;
    int choiceTwo;           // Interaction 2
    int choiceThree;         // Interaction 3
    int choiceFour;          // Interaction 4
    LevelOne person(initialBalance);

    cout << "Welcome to Doggy Day Care! Before we get started, we need to get some information." << endl;

    // Get player name
    cout << "\nEnter your name: " << endl;
    getline(cin, tempName);
    person.setName(tempName); // Sets name
    cout << "\nCheck if name works DEBUG: " << person.getName() << endl;

    // Get daycare name
    cout << "\nEnter the name of your daycare: " << endl;
    getline(cin, tempDayCareName);
    person.setDayCareName(tempDayCareName);
    cout << "\nCheck if daycare name works DEBUG: " << person.getDayCareName() << endl;

    // Jobs included
    cout << "\nHere is a list of services you can provide. It will take away from your balance. And every 5 days you will be charged." << endl;
    cout << "\nSERVICES" << endl;
    cout << "1. Grooming Services --- $450" << endl;
    cout << "\n2. Walking Services --- $100" << endl;
    cout << "\n3. Training Services --- $500" << endl;

    cout << "\nEnter a number 1-3 (You can only select one service)" << endl;
    cin >> tempService;
    person.setService(tempService);
    cout << "\nChecking if worked DEBUG SERVICE: " << person.getService() << endl;

    cout << "\nLEVEL 1 .... starting" << endl;
    cout << "\nYou walk into " << person.getDayCareName() << " and begin to set up for the day." << endl;
    // FIXME add function for random generator
    cout << "\nYou hear the doorbell ring and see a young girl walk in" << endl;
    person.interactionOne();

    cout << "\nYoung girl: Hi! My name is Ana. I am looking for a job and I saw that you recently opened." << endl;
    cout << "\nShe hands you her resume." << endl;
    cout << "\nYou finish up your conversation with her and she leaves." << endl;
    cout << "\nDo you take a look at her resume?" << endl;
    person.interactionTwo(choiceTwo);
    cout << "\nDEBUG to make sure choice two works: " << choiceTwo << endl;

    if (choiceTwo == 1) {
        int yesOrNo;
        cout << "\nWould you like to hire Ana?" << endl;
        cout << "\nEnter 1 for yes, any other character for no." << endl;
        cin >> yesOrNo;
        if (yesOrNo == 1) {
            cout << "\nYou decide to give Ana a call back. She will come in to start in 5 days." << endl;
            person.addPoints(10);
        }
        else {
            cout << "\nYou decide to not hire Ana." << endl;
        }
    }
    else {
        cout << "\nYou decide to not hire Ana." << endl;
    }

    cout << "\nYou are now 3 hours in, no other customers have come in." << endl;
    cout << "\nYou're feeling a little sleepy.. should you take a nap or create a social media account for " << person.getDayCareName() << endl;
    person.interactionThree(choiceThree);
    cout << choiceThree << "\nDEBUG FOR 3" << endl;
    cout << choiceTwo << " debug to make sure choice two is valid still" << endl;

    if (choiceThree == 1) {
        cout << "\nA customer walks in! You are startled. But quickly greet the customer" << endl;
    }
    else {
        cout << "\nA customer walks in! Suddenly, you do not feel tired anymore and greet the customer." << endl;
        person.addPoints(5);
    }

    cout << "\nCustomer1: Hello! My name is Nia. I am looking around for a place to leave my dog." << endl;
    cout << "\nNia: I work long hours.. and my dog -- Buddy, tends to get lonely throughout the day." << endl;

    if (choiceThree == 1) {
        cout << "\nYou yawn as she goes on about her dog. She gives you a weird look. Maybe you shouldn't have napped after all." << endl;
    }

    cout << "\nAfter a long conversation.. or what seemed to be long, Nia seems so excited that she decides to leave Buddy there now!" << endl;
    person.addPoints(5);
    cout << "\nNia leaves." << endl;
    cout << "\nNow it is just you and Buddy. Buddy is a golden retriever. 1 year old. With lots of energy." << endl;
    person.interactionFour(choiceFour);

    cout << "\nA few hours pass by.." << endl;
    cout << "\nNia comes to pick up Buddy." << endl;
    if (choiceFour == 1) {
        cout << "\nNia notices how tired Buddy is." << endl;
        cout << "\nWow! I will definitely be recommending this place to my friends. You've got Buddy tired out, and that's a rare thing." << endl;
        person.addPoints(5);
    }
    else {
        cout << "\nNia notices that Buddy has lots of energy." << endl;
        cout << "\nShe is clearly irritated." << endl;
    }

    cout << "\nThe day has come to an end. You had one customer today." << endl;

    // Print the total points collected for Level 1, Day 1
    cout << "Total points collected for Level 1, Day 1: " << person.getPoints() << endl;

    return 0;
}

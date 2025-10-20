#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;

int main() {
    int numStates, numSymbols;

    cout << "Enter number of states: ";
    cin >> numStates;

    cout << "Enter number of symbols: ";
    cin >> numSymbols;

    vector<char> symbols(numSymbols);
    cout << "Enter symbols (e.g. a b): ";
    for (int i = 0; i < numSymbols; i++)
        cin >> symbols[i];

    vector<map<char, int>> transitions(numStates);
    cout << "\nEnter transition table:\n";
    cout << "(Format: for each state, enter next state for each symbol)\n";
    for (int s = 0; s < numStates; s++) {
        cout << "From state " << s << ":\n";
        for (char sym : symbols) {
            int next;
            cout << "  On '" << sym << "' go to: ";
            cin >> next;
            transitions[s][sym] = next;
        }
    }

    int startState;
    cout << "\nEnter start state: ";
    cin >> startState;

    int numFinal;
    cout << "Enter number of final states: ";
    cin >> numFinal;

    set<int> finalStates;
    cout << "Enter final states: ";
    for (int i = 0; i < numFinal; i++) {
        int f;
        cin >> f;
        finalStates.insert(f);
    }

    while (true) {
        string input;
        cout << "\nEnter input string (or type 'exit' to quit): ";
        cin >> input;

        if (input == "exit")
            break;

        int currentState = startState;
        bool invalid = false;

        for (char ch : input) {
            if (transitions[currentState].find(ch) == transitions[currentState].end()) {
                cout << "Invalid symbol '" << ch << "' encountered.\n";
                cout << "String Rejected.\n";
                invalid = true;
                break;
            }
            currentState = transitions[currentState][ch];
        }

        if (invalid)
            continue;

        if (finalStates.count(currentState))
            cout << "String Accepted! (ended in state " << currentState << ")\n";
        else
            cout << "String Rejected! (ended in state " << currentState << ")\n";

        cout << "Final State reached: " << currentState << endl;
    }

    cout << "\nProgram ended.\n";
    return 0;
}


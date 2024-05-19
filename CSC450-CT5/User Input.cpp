#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

// This is a function to append user input to a file
void appendToFile(const string& filename, const string& input) {
    ofstream outFile(filename, ios::app);
    if (!outFile.is_open()) {
        cerr << "Issue: Cannot open file for writing." << endl;
        return;
    }
    outFile << input << endl;
    outFile.close();
}

// Function to reverse all characters in a file
void reverseFile(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    if (!inFile.is_open()) {
        cerr << "Issue: Cannot open input file." << endl;
        return;
    }
    
    // It reads the content of input file into a string
    string content((istreambuf_iterator<char>(inFile)), (istreambuf_iterator<char>()));
    inFile.close();
    
    // This will reverse the content
    reverse(content.begin(), content.end());
    
    // This will write the reversed content to the output file
    ofstream outFile(outputFile);
    if (!outFile.is_open()) {
        cerr << "Issue: Cannot open output file." << endl;
        return;
    }
    outFile << content;
    outFile.close();
}

int main() {
    // Prompt the user for input
    string input;
    cout << "Enter text to add to CSC450_CT5_mod5.txt (Enter 'quit' to stop appending file.):\n";

    // Get input from the user
    while (true) {
        getline(cin, input);
        
        // Allow user to choose when they are done appending
        if (input == "quit") {
            break;
        }
        
        // Append input to the file
        appendToFile("CSC450_CT5_mod5.txt", input);
    }

    cout << "Input has been added to CSC450_CT5_mod5.txt\n";
    
    // This will reverse all characters in the input file and store in the new file
    reverseFile("CSC450_CT5_mod5.txt", "CSC450-mod5-reverse.txt");
    
    cout << "Characters in CSC450_CT5_mod5.txt have been reversed and stored in new file CSC450-mod5-reverse.txt\n";

    return 0;
}
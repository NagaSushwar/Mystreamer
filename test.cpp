#include <iostream>
#include <map>
#include <string>

// Define a symbol table using a map
using namespace std;
map<string, pair<string, int>> symbolTable;

// Variable to keep track of the next available address
int nextAddress = 1000;

// Function to print the symbol table
void printSymbolTable() {
    cout << "Symbol Table:\n";
    cout << "----------------------------------\n";
    cout << "Variable Name\tData Type\tAddress\n";
    for (const auto& entry : symbolTable) {
        cout << entry.first << "\t\t" << entry.second.first << "\t\t" << entry.second.second << endl;
    }
}

// Function to process the declaration statements and update the symbol table
void processDeclaration(const string& statement) {
    // Split the statement into tokens
    string delimiter = " ";
    size_t pos = 0;
    string token;
    string variableName;
    string variableType;

    // Get the variable name and type from the statement
    while ((pos = statement.find(delimiter)) != string::npos) {
        token = statement.substr(0, pos);
        if (variableType.empty()) {
            variableType = token;
        } else {
            variableName = token;
        }
        statement.erase(0, pos + delimiter.length());
    }

    // Update the symbol table
    symbolTable[variableName] = make_pair(variableType, nextAddress);
    nextAddress += sizeof(variableType); // Assuming each variable takes the size of its data type
}

int main() {
    // Example declaration statements
    string declaration1 = "int pos = inital*rate/60";
    string declaration2 = "float pi";
    string declaration3 = "char letter";

    // Process the declaration statements
    processDeclaration(declaration1);
    processDeclaration(declaration2);
    processDeclaration(declaration3);

    // Print the symbol table
    printSymbolTable();

    return 0;
}

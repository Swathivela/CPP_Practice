#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Simpletron constants
const int MEMORY_SIZE = 100;

// Operation codes
const int READ       = 10;
const int WRITE      = 11;
const int LOAD       = 20;
const int STORE      = 21;
const int ADD        = 30;
const int SUBTRACT   = 31;
const int DIVIDE     = 32;
const int MULTIPLY   = 33;
const int BRANCH     = 40;
const int BRANCHNEG  = 41;
const int BRANCHZERO = 42;
const int HALT       = 43;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " program.sml\n";
        return 1;
    }

    // Load SML program from file
    vector<int> memory(MEMORY_SIZE, 0);
    ifstream infile(argv[1]);
    if (!infile) {
        cerr << "Error: Could not open " << argv[1] << endl;
        return 1;
    }

    int instruction, location = 0;
    while (infile >> instruction && location < MEMORY_SIZE) {
        memory[location++] = instruction;
    }
    infile.close();

    int accumulator = 0;
    int instructionCounter = 0;
    bool running = true;

    cout << "=== Simpletron Execution Begins ===\n";

    while (running && instructionCounter < MEMORY_SIZE) {
        int instructionRegister = memory[instructionCounter];
        int operationCode = instructionRegister / 100;
        int operand = instructionRegister % 100;

        switch (operationCode) {
            case READ:
                cout << "Enter a number: ";
                cin >> memory[operand];
                instructionCounter++;
                break;

            case WRITE:
                cout << "Output: " << memory[operand] << endl;
                instructionCounter++;
                break;

            case LOAD:
                accumulator = memory[operand];
                instructionCounter++;
                break;

            case STORE:
                memory[operand] = accumulator;
                instructionCounter++;
                break;

            case ADD:
                accumulator += memory[operand];
                instructionCounter++;
                break;

            case SUBTRACT:
                accumulator -= memory[operand];
                instructionCounter++;
                break;

            case DIVIDE:
                if (memory[operand] == 0) {
                    cerr << "Error: Division by zero\n";
                    running = false;
                } else {
                    accumulator /= memory[operand];
                    instructionCounter++;
                }
                break;

            case MULTIPLY:
                accumulator *= memory[operand];
                instructionCounter++;
                break;

            case BRANCH:
                instructionCounter = operand;
                break;

            case BRANCHNEG:
                if (accumulator < 0)
                    instructionCounter = operand;
                else
                    instructionCounter++;
                break;

            case BRANCHZERO:
                if (accumulator == 0)
                    instructionCounter = operand;
                else
                    instructionCounter++;
                break;

            case HALT:
                cout << "=== Simpletron execution terminated ===\n";
                running = false;
                break;

            default:
                cerr << "Error: Invalid opcode " << operationCode 
                     << " at location " << instructionCounter << endl;
                running = false;
                break;
        }
    }

    return 0;
}

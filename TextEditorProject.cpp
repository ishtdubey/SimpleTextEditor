#include <iostream>
#include <fstream>
#include <string>

void createFile();
void readFile();
void writeFile();

int main() {
    int choice;
    while (true) {
        std::cout << "\nSimple Text Editor";
        std::cout << "\n1. Create New File";
        std::cout << "\n2. Read File";
        std::cout << "\n3. Write to File";
        std::cout << "\n4. Exit";
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore newline left in buffer

        switch (choice) {
            case 1: createFile(); break;
            case 2: readFile(); break;
            case 3: writeFile(); break;
            case 4: return 0;
            default: std::cout << "Invalid choice. Try again.\n";
        }
    }
}
void createFile() {
    std::string filename;
    std::cout << "Enter filename: ";
    std::getline(std::cin, filename);
    
    std::ofstream file(filename);
    if (file) {
        std::cout << "File created successfully.\n";
        file.close();
    } else {
        std::cout << "Error creating file!\n";
    }
}

void readFile() {
    std::string filename, line;
    std::cout << "Enter filename to read: ";
    std::getline(std::cin, filename);
    
    std::ifstream file(filename);
    if (!file) {
        std::cout << "File not found!\n";
        return;
    }

    std::cout << "File Content:\n";
    while (getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}

void writeFile() {
    std::string filename, text;
    std::cout << "Enter filename to write: ";
    std::getline(std::cin, filename);
    
    std::ofstream file(filename, std::ios::app); // Append mode
    if (!file) {
        std::cout << "Error opening file!\n";
        return;
    }

    std::cout << "Enter text (Type 'EXIT' to stop):\n";
    while (true) {
        std::getline(std::cin, text);
        if (text == "EXIT") break;
        file << text << std::endl;
    }

    file.close();
    std::cout << "Text saved successfully.\n";
}

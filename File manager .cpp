
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

void listFiles(const std::string& path) {
    for (const auto& entry : fs::directory_iterator(path))
        std::cout << entry.path().filename() << "\n";
}

void createDirectory(const std::string& path, const std::string& dirName) {
    fs::create_directory(path + "/" + dirName);
}

void copyFile(const std::string& sourcePath, const std::string& destinationPath) {
    fs::copy_file(sourcePath, destinationPath, fs::copy_options::overwrite_existing);
}

void moveFile(const std::string& sourcePath, const std::string& destinationPath) {
    fs::rename(sourcePath, destinationPath);
}

int main() {
    std::string currentPath = fs::current_path().string();
    std::string userInput;

    while (true) {
        std::cout << "Current Directory: " << currentPath << "\n";
        std::cout << "1. List files\n2. Create directory\n3. Copy file\n4. Move file\n5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> userInput;

        if (userInput == "1") {
            listFiles(currentPath);
        } else if (userInput == "2") {
            std::string dirName;
            std::cout << "Enter directory name: ";
            std::cin >> dirName;
            createDirectory(currentPath, dirName);
        } else if (userInput == "3") {
            std::string sourceFile, destinationFile;
            std::cout << "Enter source file path: ";
            std::cin >> sourceFile;
            std::cout << "Enter destination file path: ";
            std::cin >> destinationFile;
            copyFile(sourceFile, destinationFile);
        } else if (userInput == "4") {
            std::string sourceFile, destinationFile;
            std::cout << "Enter source file path: ";
            std::cin >> sourceFile;
            std::cout << "Enter destination file path: ";
            std::cin >> destinationFile;
            moveFile(sourceFile, destinationFile);
        } else if (userInput == "5") {
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
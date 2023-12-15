#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void writeCSV(const std::string& filename, const std::vector<std::vector<std::string>>& data) {
    std::ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
        return;
    }

    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            outputFile << row[i];
            if (i < row.size() - 1) {
                outputFile << ","; // Add comma between values
            }
        }
        outputFile << "\n"; // Add newline at the end of each row
    }
    outputFile.close();
}
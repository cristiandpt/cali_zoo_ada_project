#include <cstdlib>
#include <iostream>

void generate_report() {
    // Replace "your_shell_command" with the actual command you want to execute
    const char* command = "julia julia_report.jl > report.csv";

    // Execute the shell command
    int result = system(command);

    // Check the result of the command execution
    if (result == 0) {
        // Success
        std::cout << "Command executed successfully." << std::endl;
    } else {
        // Failure
        std::cerr << "Error: Command execution failed." << std::endl;
    }
}
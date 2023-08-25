#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <sstream>
#include <cstring>
#include <dirent.h>

std::string get_solidity_version(const std::string& sol_file_path) {
    std::ifstream file(sol_file_path);
    if (file.is_open()) {
        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string content = buffer.str();

        std::regex version_regex(R"(pragma solidity\s+^(\d+\.\d+\.\d+);)");
        std::smatch version_match;
        if (std::regex_search(content, version_match, version_regex)) {
            return version_match[1];
        } else {
            std::cout << "Error: Solidity version not found in " << sol_file_path << std::endl;
        }
    } else {
        std::cout << "Error opening file: " << sol_file_path << std::endl;
    }

    return "";
}

std::string compile_sol_file(const std::string& sol_file_path, const std::string& solidity_version) {
    std::string cmd = "solc-" + solidity_version + " --combined-json bin,opcodes " + sol_file_path;
    std::array<char, 128> buffer;
    std::string result;

    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) {
        std::cout << "Error executing command: " << cmd << std::endl;
        return "";
    }

    while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
        result += buffer.data();
    }

    pclose(pipe);
    return result;
}

bool has_extension(const std::string& filename, const std::string& extension) {
    return filename.length() >= extension.length() && filename.compare(filename.length() - extension.length(), extension.length(), extension) == 0;
}

void compile_directory(const std::string& directory_path) {
    DIR* dir;
    dirent* entry;
    dir = opendir(directory_path.c_str());

    if (dir != nullptr) {
        while ((entry = readdir(dir)) != nullptr) {
            std::string filename = entry->d_name;
            if (filename != "." && filename != "..") {
                std::string full_path = directory_path + "\\" + filename;

                if (entry->d_type == DT_REG && has_extension(filename, ".sol")) {
                    std::cout << "Compiling " << full_path << "..." << std::endl;

                    // Get the Solidity version from the .sol file
                    std::string solidity_version = get_solidity_version(full_path);
                    if (solidity_version.empty()) {
                        continue;
                    }

                    // Create output directory if it doesn't exist
                    std::string output_directory = directory_path + "\\output";
                    mkdir(output_directory.c_str());

                    // Compile the contract and save bytecode and opcode to separate files
                    std::string output = compile_sol_file(full_path, solidity_version);
                    if (!output.empty()) {
                        std::ofstream bytecode_file(output_directory + "\\" + filename.substr(0, filename.find_last_of(".")) + "_bytecode.txt");
                        bytecode_file << output;
                        bytecode_file.close();
                    }

                    std::cout << "Compilation of " << full_path << " complete!" << std::endl;
                } else if (entry->d_type == DT_DIR) {
                    std::string subdirectory = entry->d_name;
                    if (subdirectory != "." && subdirectory != "..") {
                        std::string subdirectory_path = directory_path + "\\" + subdirectory;
                        compile_directory(subdirectory_path);
                    }
                }
            }
        }

        closedir(dir);
    }
}

int main() {
    // Replace 'path/to/sol/files' with the directory containing your .sol files
    std::cout<<"chliye suru krte hai\n";
    std::string sol_files_directory = "C:\\Users\\ajaym\\Documents\\new_visual";
    std::cout<<"started\n";
    compile_directory(sol_files_directory);
    std::cout<<"ended\n";
    return 0;
}

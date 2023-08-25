import os
import subprocess
import re

def get_solidity_version(sol_file_path):
    # Read the .sol file and extract the Solidity version from the pragma statement
    with open(sol_file_path, "r") as f:
        content = f.read()
        solidity_version_match = re.search(r"pragma solidity\s+^(\d+\.\d+\.\d+);", content)
        if not solidity_version_match:
            print(solidity_version_match)
            print(f"Error: Solidity version not found in {sol_file_path}")
            return None

        solidity_version = solidity_version_match.group(1)
        return solidity_version

def compile_sol_file(sol_file_path, solidity_version):
    # Compile the .sol file using solc with the appropriate version
    try:
        result = subprocess.run(["solc-" + solidity_version, f"--combined-json=bin,opcodes", sol_file_path], capture_output=True, text=True, check=True)
        output = result.stdout
        return output
    except subprocess.CalledProcessError as e:
        print(f"Error compiling {sol_file_path}: {e}")
        return None

def main():
    # Replace 'path/to/sol/files' with the directory containing your .sol files
    sol_files_directory = "C:\\Users\\ajaym\\Documents\\new_visual"

    # Traverse through all the .sol files in the directory
    for root, dirs, files in os.walk(sol_files_directory):
        for file in files:
            if file.endswith(".sol"):
                sol_file_path = os.path.join(root, file)
                print(f"Compiling {sol_file_path}...")

                # Get the Solidity version from the .sol file
                solidity_version = get_solidity_version(sol_file_path)
                if not solidity_version:
                    continue

                # Create output directory if it doesn't exist
                output_directory = os.path.join(root, "output")
                os.makedirs(output_directory, exist_ok=True)

                # Compile the contract and save bytecode and opcode to separate files
                output = compile_sol_file(sol_file_path, solidity_version)
                if output:
                    with open(os.path.join(output_directory, f"{file.split('.')[0]}_bytecode.txt"), "w") as f:
                        f.write(output)

                print(f"Compilation of {sol_file_path} complete!")

if __name__ == "__main__":
    main()

import solcx

solc_version = "0.6.12"

# Compile the Solidity file
contract = solcx.compile_files("my_contract.sol", solc_version=solc_version)
list=solcx.get_installed_solc_versions()
print(list)
# Print the output
print(contract)
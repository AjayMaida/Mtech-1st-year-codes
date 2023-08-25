import os
import requests
import zipfile

def get_available_versions():
    url = "https://api.github.com/repos/ethereum/solidity/releases"
    response = requests.get(url)
    
    if response.status_code == 200:
        releases = response.json()
        return [release["tag_name"].lstrip("v") for release in releases]
    else:
        print("Failed to fetch available versions from GitHub")
        return []

def download_solc(version, target_dir):
    url = f"https://github.com/ethereum/solidity/releases/download/v{version}/solc-static-windows.zip"
    response = requests.get(url)

    if response.status_code == 200:
        os.makedirs(target_dir, exist_ok=True)
        target_zip_file = os.path.join(target_dir, f"solc-{version}.zip")

        with open(target_zip_file, "wb") as f:
            f.write(response.content)

        with zipfile.ZipFile(target_zip_file, "r") as zip_ref:
            zip_ref.extractall(target_dir)

        os.remove(target_zip_file)
        print(f"Solidity compiler version {version} downloaded and extracted to {target_dir}")
    else:
        print(f"Failed to download Solidity compiler version {version}")

if __name__ == "__main__":
    # Get the list of available versions of solc
    available_versions = get_available_versions()

    # Specify the target directory where the compilers will be saved
    target_directory = "C:\\Users\\ajaym\\Documents\\new_visual"

    # Download all available versions of solc
    for version in available_versions:
        download_solc(version, target_directory)

import torch

# Check for available GPUs
if torch.cuda.is_available():
    device = torch.cuda.get_device_name()
    print(f"GPU: {device}")
else:
    print("No GPU available, using CPU.")

# Check the number of available CPU threads
num_threads = torch.get_num_threads()
print(f"Number of CPU threads: {num_threads}")

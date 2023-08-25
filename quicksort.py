def quickSort(arr, low, high):
    if low >= high:
        return

    pivot = arr[high]
    i = low
    j = low

    while i < high:
        if arr[i] <= pivot:
            swap(arr[i], arr[j])
            j += 1
        i += 1

    if j < high:
        swap(arr[high], arr[j])

    quickSort(arr, low, j - 1)
    quickSort(arr, j + 1, high)

def swap(a, b):
    temp = a
    a = b
    b = temp

def main():
    arr = [10, 7, 8, 9, 1, 5]
    n = len(arr)

    quickSort(arr, 0, n - 1)

    print("Sorted array: ", arr)

if __name__ == "__main__":
    main()

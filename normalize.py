def normalize():
    smallest = min(data)
    diff = max(data) - smallest

    if diff == 0:
        print("Invalid: Cannot normalize constant list")
        return

    for i in range(len(data)):
        data[i] = (data[i] - smallest) / diff

    print("Normalized Dataset:")
    print(data)

if __name__ == "__main__":
    n = int(input("Input the number of values to be normalized:  "))

    data = []
    for i in range(n):
        # I wanted to add getting the min and max here but ehh
        data.append(float(input(f"Value {i+1}:  ")))

    print("List of dataset to be normalized:")
    print(data)

    normalize()
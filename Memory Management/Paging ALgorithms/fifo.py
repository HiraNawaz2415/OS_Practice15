# FIFO Page Replacement Algorithm

# Input
reference_string = list(map(int, input("Enter reference string (space-separated): ").split()))
frames = int(input("Enter number of frames: "))

# FIFO Algorithm
def simulate_fifo(reference, frames):
    memory = []
    faults = 0
    for page in reference:
        if page not in memory:
            faults += 1
            if len(memory) == frames:
                memory.pop(0)
            memory.append(page)
        print(f"FIFO | Page: {page} | Memory: {memory}")
    print(f"\nTotal FIFO Page Faults: {faults}")

simulate_fifo(reference_string, frames)

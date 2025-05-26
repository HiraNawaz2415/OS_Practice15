# MFU Page Replacement Algorithm

reference_string = list(map(int, input("Enter reference string (space-separated): ").split()))
frames = int(input("Enter number of frames: "))

from collections import defaultdict

def simulate_mfu(reference, frames):
    memory = []
    frequency = defaultdict(int)
    faults = 0

    for page in reference:
        frequency[page] += 1
        if page not in memory:
            faults += 1
            if len(memory) == frames:
                # Find page in memory with highest frequency
                most_used = max(memory, key=lambda p: frequency[p])
                memory.remove(most_used)
            memory.append(page)
        print(f"MFU  | Page: {page} | Memory: {memory}")
    
    print(f"\nTotal MFU Page Faults: {faults}")

simulate_mfu(reference_string, frames)

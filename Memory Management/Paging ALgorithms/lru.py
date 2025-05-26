# LRU Page Replacement Algorithm

# Input
reference_string = list(map(int, input("Enter reference string (space-separated): ").split()))
frames = int(input("Enter number of frames: "))

# LRU Algorithm
def simulate_lru(reference, frames):
    memory = []
    recent = []
    faults = 0
    for page in reference:
        if page not in memory:
            faults += 1
            if len(memory) == frames:
                lru = recent.pop(0)
                memory.remove(lru)
            memory.append(page)
        else:
            recent.remove(page)
        recent.append(page)
        print(f"LRU  | Page: {page} | Memory: {memory}")
    print(f"\nTotal LRU Page Faults: {faults}")

simulate_lru(reference_string, frames)

# MRU Page Replacement Algorithm

reference_string = list(map(int, input("Enter reference string (space-separated): ").split()))
frames = int(input("Enter number of frames: "))

def simulate_mru(reference, frames):
    memory = []
    recent_stack = []
    faults = 0

    for page in reference:
        if page not in memory:
            faults += 1
            if len(memory) == frames:
                mru = recent_stack[-1]  # Last used
                memory.remove(mru)
                recent_stack.remove(mru)
            memory.append(page)
        else:
            recent_stack.remove(page)
        recent_stack.append(page)
        print(f"MRU  | Page: {page} | Memory: {memory}")
    
    print(f"\nTotal MRU Page Faults: {faults}")

simulate_mru(reference_string, frames)

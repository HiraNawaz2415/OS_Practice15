# Optimal Page Replacement Algorithm

# Input
reference_string = list(map(int, input("Enter reference string (space-separated): ").split()))
frames = int(input("Enter number of frames: "))

# Optimal Algorithm
def simulate_optimal(reference, frames):
    memory = []
    faults = 0
    for i in range(len(reference)):
        page = reference[i]
        if page not in memory:
            faults += 1
            if len(memory) == frames:
                future = reference[i+1:]
                indexes = []
                for m in memory:
                    if m in future:
                        indexes.append(future.index(m))
                    else:
                        indexes.append(float('inf'))
                victim = memory[indexes.index(max(indexes))]
                memory.remove(victim)
            memory.append(page)
        print(f"OPT  | Page: {page} | Memory: {memory}")
    print(f"\nTotal OPT Page Faults: {faults}")

simulate_optimal(reference_string, frames)

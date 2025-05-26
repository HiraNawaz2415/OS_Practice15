#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;

    cout << "Enter number of memory blocks: ";
    cin >> m;
    vector<int> blockSize(m);

    cout << "Enter sizes of blocks:\n";
    for (int i = 0; i < m; i++) {
        cin >> blockSize[i];
    }

    cout << "Enter number of processes: ";
    cin >> n;
    vector<int> processSize(n);

    cout << "Enter sizes of processes:\n";
    for (int i = 0; i < n; i++) {
        cin >> processSize[i];
    }

    vector<int> allocation(n, -1);
    vector<bool> blockAllocated(m, false);

    // Worst Fit Allocation
    for (int i = 0; i < n; i++) {
        int worstIdx = -1;
        for (int j = 0; j < m; j++) {
            if (!blockAllocated[j] && blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx]) {
                    worstIdx = j;
                }
            }
        }
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockAllocated[worstIdx] = true;
        }
    }

    cout << "\nWorst Fit Allocation:\n";
    cout << "Process No.\tProcess Size\tBlock No.\tWastage\n";

    int totalWastage = 0;
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1) {
            int wastage = blockSize[allocation[i]] - processSize[i];
            totalWastage += wastage;
            cout << i + 1 << "\t\t" << processSize[i] << "\t\t" << allocation[i] + 1 << "\t\t" << wastage << "\n";
        } else {
            cout << i + 1 << "\t\t" << processSize[i] << "\t\t" << "Not Allocated" << "\t" << "-" << "\n";
        }
    }

    cout << "\nTotal wastage memory: " << totalWastage << "\n";

    return 0;
}

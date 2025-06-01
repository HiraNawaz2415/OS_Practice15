#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    unsigned int logicalAddressSpaceSize;  // in bytes
    unsigned int physicalMemorySize;       // in bytes
    unsigned int pageSize;                  // in bytes

    cout << "Enter Logical Address Space Size (in bytes): ";
    cin >> logicalAddressSpaceSize;

    cout << "Enter Physical Memory Size (in bytes): ";
    cin >> physicalMemorySize;

    cout << "Enter Page/Frame Size (in bytes): ";
    cin >> pageSize;

    unsigned int numberOfPages = logicalAddressSpaceSize / pageSize;
    unsigned int numberOfFrames = physicalMemorySize / pageSize;

    cout << "\nNumber of Pages = " << numberOfPages << endl;
    cout << "Number of Frames = " << numberOfFrames << endl;

    // Create page table: For simplicity, map page i to frame i % numberOfFrames
    vector<int> pageTable(numberOfPages);
    for (unsigned int i = 0; i < numberOfPages; i++) {
        pageTable[i] = i % numberOfFrames;
    }

    cout << "\nPage Table (Page -> Frame):\n";
    for (unsigned int i = 0; i < numberOfPages; i++) {
        cout << "Page " << i << " -> Frame " << pageTable[i] << endl;
    }

    // Input a logical address to translate
    unsigned int logicalAddress;
    cout << "\nEnter logical address (0 to " << logicalAddressSpaceSize - 1 << "): ";
    cin >> logicalAddress;

    if (logicalAddress >= logicalAddressSpaceSize) {
        cout << "Error: Logical address out of range.\n";
        return 1;
    }

    // Calculate page number and offset
    unsigned int pageNumber = logicalAddress / pageSize;
    unsigned int offset = logicalAddress % pageSize;

    cout << "Logical Address " << logicalAddress << " consists of:\n";
    cout << "Page Number = " << pageNumber << endl;
    cout << "Offset = " << offset << endl;

    // Get frame number from page table
    unsigned int frameNumber = pageTable[pageNumber];

    // Calculate physical address
    unsigned int physicalAddress = frameNumber * pageSize + offset;

    cout << "Physical Address = " << physicalAddress << endl;

    return 0;
}

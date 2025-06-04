# What is Process Synchronization?
When multiple processes are running at the same time and they share data or resoruces, they can interfere with each other if not controlled.
Process Synchronization is the technique to coordinate these processes so that:

   - No data is lost
   - No inconsistency occurs
   - Processes cooperate without conflict

- Process Synchronization means managing the order and timing of multiple processes that access shared resources (like memory, files, or variables), so that data remains correct and consistent.

- In simple words, it makes sure that when multiple processes are working together, they don’t get in each other’s way.



---
**Example:**

Imagine two people (processes) updating a shared Google Doc (shared data).
If both type at the same time in the same area, the document can get corrupted or confused.
Similarly, in OS, processes may:

- Share files

- Update the same memory/data

- Access printers, databases, etc.

If not synchronized, this leads to Race Conditions

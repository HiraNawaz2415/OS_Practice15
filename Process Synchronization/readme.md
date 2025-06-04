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

---
## Why Process Synchronization is Needed?
**Shared Resources:** When multiple processes access shared resources (e.g., memory, files, variables), synchronization prevents conflicts.

**Data Consistency:** Ensures that data is not corrupted due to simultaneous access by multiple processes.

**Race Conditions:** Avoids situations where the output depends on the unpredictable timing of processes.

---
## **What is a Race Condition?**

A race condition occurs when:

  - Multiple processes read/write shared data
  - The final result depends on who finishes first

**Example:**

Let’s say x = 10

Process A: x = x + 1 → (reads 10, adds 1 → x = 11)

Process B: x = x * 2 → (reads 10, multiplies by 2 → x = 20)

If both do it at the same time without sync, result might be:

x = 22 ❌ (wrong)
x = 20 ✅

x = 11 ✅

Which is unpredictable and dangerous.

---

## **Critical Section Problem**
A critical section is a part of the program where the process accesses shared resources. Only one process should be allowed in its critical section at a time.

- A solution to the critical section problem must satisfy:

**Mutual Exclusion:** Only one process can enter the critical section at a time.

**Progress:** If no process is in the critical section, one of the waiting processes should enter.

**Bounded Waiting:** There should be a limit on how long a process waits to enter the critical section.

---
# **Synchronization Techniques**

## **1. Software-based Solutions**
  - Peterson’s Algorithm (used for two processes)
  - Dekker’s Algorithm

## **2. Hardware-based Solutions**
 - Test-and-Set Instruction
 - Compare-and-Swap Instruction
 - Disabling Interrupts (not recommended for multiprocessor systems)

## **3. Synchronization Tools (provided by OS)**

### **Semaphores:**
   - Integer variable used to signal between processes.
   - wait() and signal() operations control access.

**Types:** Binary Semaphore (mutex), Counting Semaphore.

### **Mutex (Mutual Exclusion Object):**

   - A locking mechanism to ensure mutual exclusion.

### **Monitors:**

   - High-level synchronization construct with shared variables, condition variables, and functions to safely access them.

### **Condition Variables:**

   - Used with monitors for signaling between processes when a condition becomes true.

---





# **Virtual memory**
- Virtual memory is a memory management technique used by operating systems that gives an illusion of a large, continuous main memory to programs, even if the actual physical memory (RAM) is limited.

- It allows the system to execute processes that may not be completely loaded into RAM, by using disk space (usually called a swap file or page file) as an extension of RAM.
---
## **Why Virtual Memory is Important**

| Benefit                     | Description                                                   |
| --------------------------- | ------------------------------------------------------------- |
| **Runs Large Applications** | Supports processes larger than physical RAM.                  |
| **Efficient Multitasking**  | Enables more processes to run at the same time.               |
| **Memory Isolation**        | Keeps one process from accessing another's memory.            |
| **Simplified Programming**  | Programmers don’t need to worry about physical memory limits. |

---
## **How Virtual Memory Works (Step-by-Step)**
- Address Translation:
 - CPU generates a virtual address.
 - The OS uses the page table to translate it into a physical address.

- Page Replacement:
 - If a page needed by a process is not in RAM, it causes a page fault.
 - The OS brings the page from secondary storage (disk) into RAM.
 - If RAM is full, the OS swaps out a less-used page to disk (using algorithms like LRU, FIFO).

- Swapping:
 - Data is moved between RAM and disk as needed.

---
## **Conceptual Diagram
+-----------------------+
|     Virtual Memory    |
|-----------------------|
| Page 0 → Frame 5      |
| Page 1 → On Disk      | ← Page Fault triggers loading
| Page 2 → Frame 3      |
+-----------------------+
        ↓
+-----------------------+
|     Physical Memory   |
|-----------------------|
| Frame 3: Page 2       |
| Frame 5: Page 0       |
| Frame 7: Page 4       |
+-----------------------+

---

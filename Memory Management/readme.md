# **Memory Management Techniques in Operating Systems**
Memory management is the process by which an operating system controls and coordinates computer memory, assigning blocks to various programs to optimize overall system performance.
# 🔰 **Types of Memory Management Techniques**

| Category                      | Techniques                                                                       |
| ----------------------------- | -------------------------------------------------------------------------------- |
| **Contiguous Allocation**     | - Single Contiguous Allocation<br>- Fixed Partitioning<br>- Dynamic Partitioning |
| **Non-Contiguous Allocation** | - Paging<br>- Segmentation<br>- Segmentation with Paging                         |
| **Virtual Memory Techniques** | - Demand Paging<br>- Thrashing Control<br>- Page Replacement Algorithms          |

---
## **1.Single Contiguous Allocation**
- Description: One process loaded in memory at a time (usually the OS and one user process).

- Used In: Early OS like MS-DOS.

- Drawback: Wasteful — no multitasking.

  ---
## **2. Fixed Partitioning**
- Memory is divided into fixed-size partitions.

- Each partition holds exactly one process.

- Problem: Internal fragmentation (wasted memory inside a partition).
- Example:
Memory: 16 MB
Partitions: 4MB, 4MB, 4MB, 4MB
If process needs 2MB → 2MB wasted


  ---
  

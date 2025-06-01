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
## **3. Paging (Non-Contiguous Allocation)**
- Memory is divided into fixed-size pages (logical) and frames (physical).

- Pages of processes are loaded into any free frame.

- Solves both internal and external fragmentation issues.
- Advantage: Easy to manage, supports virtual memory.

- Disadvantage: Overhead due to maintaining page tables.

  ---
## **4. Segmentation**
- Divides memory logically based on functions (code, data, stack).

- Each segment has a different length and is stored in non-contiguous memory.
- Advantage: Better logical structure.

- Disadvantage: Can suffer from external fragmentation.

---
## **5. Segmentation with Paging**
- Combines segmentation and paging to use the advantages of both.

- Each segment is divided into pages, which are then mapped to memory.

- Used in modern OS like Windows and Linux.

---
## **6. Virtual Memory**
- Allows execution of processes that don’t fit entirely in RAM.

- Uses disk space (swap) as temporary RAM.

- Implemented using Demand Paging.

---
## Key Concept to rememeber

| Term                       | Description                                   |
| -------------------------- | --------------------------------------------- |
| **Internal Fragmentation** | Wasted space inside allocated memory block.   |
| **External Fragmentation** | Wasted space between allocated memory blocks. |
| **Compaction**             | Rearranging memory to remove fragmentation.   |
| **Swapping**               | Moving entire processes in/out of RAM.        |

---

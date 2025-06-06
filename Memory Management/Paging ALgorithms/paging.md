# **Definition of Paging**
- Paging is a memory management scheme used in operating systems that eliminates the need for contiguous allocation of physical memory. It allows the physical address space of a process to be non-contiguous, helping avoid fragmentation and improving efficiency.

## **Why Paging is Needed**
- Efficient Memory Use: Prevents external fragmentation.

- Simplifies Memory Allocation: Allocates memory in fixed-size blocks.

- Supports Virtual Memory: Allows execution of processes larger than physical memory.
---

# key concept of paging

| Term                 | Description                                                     |
| -------------------- | --------------------------------------------------------------- |
| **Page**             | A fixed-size block of **logical memory** (e.g., 4 KB).          |
| **Frame**            | A fixed-size block of **physical memory**, same size as a page. |
| **Page Table**       | A data structure that stores the mapping of pages to frames.    |
| **Logical Address**  | The address generated by the CPU (used by programs).            |
| **Physical Address** | The actual address in RAM (used by the hardware).               |

---

## **How Paging Works (Step-by-Step)**
- Divide Memory:

  - Logical memory → Divided into pages.
  - Physical memory → Divided into frames of the same size.

- Page Table Setup:

   - Each process has a page table that maps each page to a corresponding frame.

- Address Translation:

    - The logical address consists of:

      - Page Number (p) – Index in the page table.
      - Offset (d) – Location within the page.
      - The OS looks up the frame number (f) in the page table.

- The physical address is:

Physical Address=(Frame Number×Frame Size)+Offset
---
Logical Address (p, d)
       ↓
   Page Table
       ↓
Frame Number (f)
       ↓
Physical Address = f * frame size + d

---
## **Types of Paging Systems**
- **Simple Paging:** Each process has one page table.

- **Hierarchical Paging:** Page tables are themselves paged.

- **Inverted Paging:** One page table for all processes; indexed by frame.

- **Demand Paging:** Pages are loaded into memory only when needed (used in virtual memory).

---
## **Translation Lookaside Buffer (TLB)**
- A special cache used to reduce the time taken for virtual-to-physical address translation.

- Stores recent page-to-frame mappings.

- **TLB Hit:** Fast access.

- **TLB Miss:** Access page table in main memory (slower).

---
## **Example**
- Assume:

- Logical address = 1023

- Page size = 256 bytes

- Frame size = 256 bytes

- Page number = 1023 / 256 = 3
- Offset = 1023 % 256 = 255

- If Page 3 is mapped to Frame 5, then:
 - Physical Address=5×256+255=1535

---
## **Advantages of Paging**
- No External Fragmentation: Memory is efficiently utilized.

- Simple Allocation: Fixed-size frames/pages make memory management easier.

- Enables Virtual Memory: Pages can be stored on disk when not in RAM.

- Process Isolation: Protects memory of different processes.

## **Disadvantages of Paging**
- Internal Fragmentation: Last page might not be fully used.

- Overhead of Page Tables: Large processes need large page tables.

- Slower Access: Address translation requires extra steps.

- TLB Misses: If page-table entries aren't cached in TLB (Translation Lookaside Buffer), it takes more time.

---



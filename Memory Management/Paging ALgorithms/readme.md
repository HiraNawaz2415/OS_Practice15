# **What is a Page in Operating Systems?**

- A page is a small, fixed-size block of data from a program that is stored in virtual memory.

- Think of a book:
- **A book = your program.**

- A page in the book = a part of the program (code or data).

- Only a few pages can be open (in memory) at a time.

## **Why Do We Use Pages?**
- Modern computers use Virtual Memory, which allows a program to use more memory than physically available (RAM).

- But we can't load the whole program into RAM at once, so:

- The program is divided into pages (usually 4 KB in size).

- Only the needed pages are brought into physical memory (RAM).

## **How It Works:**
- The CPU requests data or instructions.

- If the page is already in RAM → ✅ used directly.

- If not → ❌ Page Fault happens → OS loads the required page from disk into RAM.

**Example:**
- Your app has 100 pages.

- RAM can only hold 3 pages at a time.

- When the app needs a page not currently in memory:

- A Page Replacement Algorithm decides which page to remove.

- The new page is loaded in.

  | Term                 | Meaning                                                                           
| -------------------- | --------------------------------------------------------------------------------- |
| **Page**             | A fixed-size block of memory/data used in virtual memory.                         |
| **Frame**            | A slot in physical memory (RAM) where a page can be loaded.                       |
| **Page Fault**       | Happens when a page is not in memory and must be loaded from disk.                |
| **Page Replacement** | Choosing which page to remove when RAM is full and a new page needs to be loaded. |

---

# **What is Page Replacement?**
- In a computer system, when processes run, they need memory. But memory (RAM) is limited. So, when memory becomes full and a new page (piece of data) is needed, the system has to decide which old page to remove to make space.

- That's where Page Replacement Algorithms come in.

  ---

## **1.FIFO – First-In First-Out**
**Concept:**
- Just like a queue in real life, the first page loaded into memory is the first to be removed, regardless of whether it's still being used or not.

**How it Works:**
- Keep track of the order pages entered memory.

- When memory is full and a new page comes in:

- Remove the page that was added earliest (the front of the queue).

## **2.LRU – Least Recently Used**
**Concept:**
- Remove the page that has not been used for the longest time.

**How it Works:**
- Track when each page was last used.

**On a page fault:**

- Remove the page that was least recently accessed.

**Real Life Analogy:**
- Think of books on your table: if you haven’t touched a book for hours, you're more likely to remove it than one you're actively reading.

## **3.Optimal Page Replacement**
**Concept:**
- Replace the page that will not be used for the longest time in the future.

**How it Works:**
- Looks ahead in the reference string.

- Replaces the page that won’t be needed for the longest time.

**Example:**
- Used mostly in theoretical studies because real systems can't predict the future.

## **4.MRU – Most Recently Used**
**Concept:**
- Opposite of LRU. MRU removes the page that was just used most recently.

**Why?**
- Useful in systems where recently used data is less likely to be used again soon, like certain database workloads.

**Example:**
- Imagine you just opened a file, but now you're done with it and want to focus on others — so you remove the one you just used.

## **5.MFU – Most Frequently Used**
**Concept:**
- Remove the page that has been used the most frequently.

**Why?**
- The idea is: pages that have been accessed many times may have done their job already and might not be needed again.

**Real World Analogy:**
- If you've used one tool 50 times already, and others only once or twice — maybe you won't need that tool again right now.

## ** Comparison Table**

| Algorithm | Removes Which Page?         | Good For                                   |
| --------- | --------------------------- | ------------------------------------------ |
| FIFO      | Oldest (first-in)           | Simple systems, easy to implement          |
| LRU       | Least recently accessed     | Realistic memory use patterns              |
| Optimal   | Furthest-used in future     | Theoretical best (not usable in real-time) |
| MRU       | Most recently accessed      | Cases where recent use means "done"        |
| MFU       | Most frequently used so far | Assumes most-used may not be needed again  |

---

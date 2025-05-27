# **Memory Allocation algorithms**
Best Fit, Worst Fit, and Next Fit memory allocation algorithms used in Operating Systems for managing free memory blocks when processes request memory:
## Memory Allocation Context
When a process needs memory, the OS finds a suitable free block (hole) from the list of available memory. Different algorithms decide which free block to allocate.
## **1. Best Fit**
**How it works:**
  - Find the smallest free block that is large enough to satisfy the request.

**Pros:**
  - Minimizes wasted memory inside allocated blocks (less fragmentation).

**Cons:**
  - Searching for the smallest block may be slower. Can create many small leftover holes.

## **2. Worst Fit**
**How it works:**
  - Find the largest free block and allocate memory from it.

**Pros:**
  - Leaves big leftover hole after allocation which might be useful for future requests.

**Cons:**
  - Can leave very large leftover holes unused and cause fragmentation.

## **3. Next Fit**
**How it works:**
  - Similar to First Fit, but instead of always starting from the beginning, it starts searching from where it left off last time.

**Pros:**
  - Can be faster than Best Fit because it doesn’t search entire memory each time.

**Cons:**
 - May skip small suitable holes before the current pointer.

## ** First Fit**

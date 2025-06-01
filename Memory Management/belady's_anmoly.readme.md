 ## **Belady’s Anomaly in Operating Systems**
Belady’s Anomaly is a counterintuitive phenomenon in page replacement algorithms where increasing the number of page frames results in more page faults.

In simple terms: More memory ≠ Better performance (under certain conditions).

---
- Normally, we expect that giving a process more frames (i.e., more memory space) should reduce page faults, because there is more room to store needed pages.

- But with Belady’s Anomaly, some algorithms behave oppositely: they cause more page faults as memory increases.
  ---
## **Occurs In:**
- FIFO (First-In-First-Out) page replacement algorithm.

- Not observed in Optimal or LRU (Least Recently Used) algorithms.

---
## **Why does it happen?**
In FIFO:

- The oldest page is removed, regardless of future use.

- Sometimes removing an old but frequently reused page can cause extra faults later.

- With more frames, FIFO may store pages that won’t be used soon, evicting useful ones too early.

---
## **How to Avoid It?**
- Use stack-based algorithms (which don’t show Belady’s anomaly):

- LRU (Least Recently Used)

- Optimal Page Replacement

- These follow the inclusion property, ensuring that more memory never leads to more faults.

---




# 🌟 **What is CPU Scheduling?**
- When multiple programs (or tasks) want to use the CPU, the operating system needs to decide which one gets to run first. This decision-making is called CPU Scheduling.

- Think of it like a queue at a doctor's clinic — the receptionist (OS) decides who goes in next. That’s where CPU scheduling algorithms come in.
---
# 🔁 **Types of CPU Scheduling Algorithms**

## **1. FCFS – First Come First Serve**
**Idea:** The one who arrives first gets the CPU first.

- Like standing in a line for a bus — first in line, first on the bus.

- Simple to understand.

- Can be slow for short tasks stuck behind long ones (called the convoy effect).

## **2. SJF – Shortest Job First (non-preemptive)**
**Idea:** The CPU picks the task that will finish the quickest.

- Like choosing to answer the easiest exam question first.

- Fast overall performance.

- Hard to know how long a job will take in advance.

- Risk of starvation (long tasks may keep waiting).
  
## **3. SJF – Shortest Job First (preemptive)**

- Always chooses the process with the least time left.

- If a new process comes with a shorter time, it interrupts the current one.

- Needs to know or estimate the burst time (how long each task will take).

- Can cause starvation — long tasks may keep getting delayed if short ones keep arriving.

- Imagine you're doing homework that takes 1 hour, but your teacher suddenly gives you a 10-minute task. You pause your long task and do the short one first. That’s preemptive SJF!

## **4. Priority Scheduling**

**Idea:** Each task is given a priority, and the CPU picks the one with the highest priority.

- Like in hospitals — emergency patients get treated before regular checkups.

- Important tasks get done quickly.

- Low-priority tasks might never get CPU time (again, starvation).

## **5.Round Robin (RR)**

**Idea:** Each task gets a fixed amount of CPU time (called a time slice or quantum) and then goes to the back of the line.

- Like kids taking turns playing a video game.

- Good for fairness and interactive systems.

- May have more context switching (overhead) if time slice is too small.

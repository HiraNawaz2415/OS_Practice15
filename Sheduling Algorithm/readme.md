# 🌟 **What is CPU Scheduling?**
- When multiple programs (or tasks) want to use the CPU, the operating system needs to decide which one gets to run first. This decision-making is called CPU Scheduling.

- Think of it like a queue at a doctor's clinic — the receptionist (OS) decides who goes in next. That’s where CPU scheduling algorithms come in.
---
# 🔑 **Important Terms in CPU Scheduling**

## **1. Burst Time (BT)**
- The time a process needs the CPU to complete its job.

**Example:** If a task needs 5 seconds of CPU time, its burst time is 5.

## **2. Arrival Time (AT)**
- The time when a process enters the ready queue (asks to be scheduled).

**Example:** If a task comes at time 2 seconds, then AT = 2.

## **3. Waiting Time (WT)**
- The time a process waits in the ready queue before getting the CPU.

**Formula:**
 - **Waiting Time = Turnaround Time - Burst Time**
## **4. Turnaround Time (TAT)**
- Total time taken from the moment a process arrives until it is completed.

**Formula:**
- **Turnaround Time = Completion Time - Arrival Time**
## **5. Completion Time (CT)**
- The time at which the process finishes execution.

## **6. Response Time**
- The time from when a process arrives to when it first gets the CPU.

- In non-preemptive scheduling, response time = waiting time.

- In preemptive scheduling, it's usually less than or equal to waiting time.

## **7. Priority**
- A number given to a process to show how important it is.

- Lower number = higher priority (commonly used).

## ** Summary TABLE

| Term            | Meaning                               | Formula / Note                    |
| --------------- | ------------------------------------- | --------------------------------- |
| Burst Time      | CPU time required to finish a task    | Given directly                    |
| Arrival Time    | Time when process enters the system   | Given directly                    |
| Completion Time | Time when process finishes            | Calculated after scheduling       |
| Turnaround Time | Time from arrival to completion       | `CT - AT`                         |
| Waiting Time    | Time spent waiting in the ready queue | `TAT - BT`                        |
| Response Time   | Time from arrival to first execution  | `Start Time - AT`                 |
| Priority        | Indicates importance of a task        | Lower = higher priority (usually) |



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

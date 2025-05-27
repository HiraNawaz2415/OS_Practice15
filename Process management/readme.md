# **What is a Process?**
- A process is simply a program in execution.
- When you run a program (like a calculator, browser, or code editor), the operating system turns it into a process. This process isn't just the code — it also includes:

- Program code (what it has to do)

-  Current activity (like which instruction is running)

-  Memory (variables, data, etc.)

-  CPU registers (used for processing)

- Open files and resources
---
**Example:**
- If you open MS Word, it becomes a process.

- If you open it twice, each one becomes a separate process, each with its own memory and data, even though they run the same program.
  
---
## Key Points

| Feature            | Description                                                        |
| ------------------ | ------------------------------------------------------------------ |
| Program            | Just a file with code (passive)                                    |
| Process            | Program in execution (active)                                      |
| Multiple Processes | You can run the same program multiple times as different processes |
| Independent        | Each process has its own memory and resources                      |

---
# 🚶‍♂️ **Process Lifecycle (States)**

- A process life cycle describes the various stages a process goes through from creation to termination.

- Each process does not run continuously — it switches between different states depending on what it's doing (e.g., waiting for input, running on the CPU, or being stopped).

## 📊**Process States**
Here are the main states in the process life cycle:

## **1. New**
-  The process is being created.

- OS sets up resources like memory, process ID, etc.
- Process is remain in secondary memory.

## **2. Ready**
- The process is ready to run and waiting for the CPU.

- It's in the ready queue, waiting for its turn.
- Long term sheduler brought the process from secondary memory to main memory (RAM) or in ready queue.

## **3. Running**
- The process is currently using the CPU and executing instructions.

- Only one process can be in this state at a time on a single-core CPU.

## **4. Waiting (or Blocked)**
- The process is waiting for some event like:

- User input

- File I/O (read/write)

- It cannot continue until the event finishes.

## **5. Terminated (or Exit)**
- The process has completed its task or has been killed (terminated).

- OS frees up the resources used by the process.

## **Bonus State: Suspended (Optional)**
- The OS may pause a process (temporarily remove it from memory) to improve performance or free memory.

- It can be resumed later.

---
      +-------+ 
      | New   |
      +---+---+
          |
          v
     +----+-----+        +-----------+
     |  Ready   |<------>|  Waiting  |
     +----+-----+        +-----------+
          |
          v
      +---+----+
      | Running|
      +---+----+
          |
     +----+-----+
     | Terminated|
     +-----------+
---

# **What is Process Scheduling?**
- Process scheduling is the method the Operating System (OS) uses to decide which process (program in execution) runs next on the CPU.

- Since many processes can be in memory at once but only one process can use the CPU at a time, the OS uses a scheduler to decide which process should run next, for how long, and when.

👉 The goal is to make the system fast, fair, and efficient.

---

# **Types of Schedulers**
The OS uses three main types of schedulers:

## **1. Long-Term Scheduler (Job Scheduler)**
 - **What it does:** Decides which processes are allowed into the system for execution.

 - **When it runs:** Before the process enters the ready queue.

 - **Purpose:** Controls the degree of multiprogramming (number of processes in memory).
 - **Example:** Out of 10 submitted jobs, it picks 5 to be loaded into RAM.
 -  Think of it as the gatekeeper that chooses which jobs can enter the system.

## **2. Short-Term Scheduler (CPU Scheduler)**
 - **What it does:** Selects one process from the ready queue to run on the CPU.

 - **When it runs:** Very frequently (every few milliseconds).

 - **Purpose:** Maximizes CPU usage and system responsiveness.

 - **Example:** Chooses between processes ready to run based on scheduling algorithms (e.g., FCFS, SJF, Round Robin).
 - This is the main scheduler that actually decides "who runs next."

## **3. Medium-Term Scheduler**
- **What it does:** Temporarily removes (swaps out) processes from RAM to free memory.

- **When it runs:** When RAM is full or overloaded.

- **Purpose:** Reduces memory load and improves performance.

- **Example:** Moves a paused background process to disk to make room for an active one.
- Think of it as a traffic controller that keeps memory from getting too crowded.

#### Summary Table

| Scheduler Type        | Role                            | Runs When                   | Main Job                                 |
| --------------------- | ------------------------------- | --------------------------- | ---------------------------------------- |
| Long-Term Scheduler   | Chooses which jobs enter RAM    | Before entering ready queue | Controls how many jobs are in memory     |
| Short-Term Scheduler  | Chooses which process gets CPU  | Frequently (ms-level)       | Runs scheduling algorithms like FCFS, RR |
| Medium-Term Scheduler | Swaps out processes temporarily | When memory is overloaded   | Frees up RAM by suspending processes     |

---

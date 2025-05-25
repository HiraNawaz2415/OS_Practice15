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
#🚶‍♂️ **Process Lifecycle (States)**

- A process life cycle describes the various stages a process goes through from creation to termination.

- Each process does not run continuously — it switches between different states depending on what it's doing (e.g., waiting for input, running on the CPU, or being stopped).

## 📊**Process States**
Here are the main states in the process life cycle:

## **1. New**
-  The process is being created.

- OS sets up resources like memory, process ID, etc.

## **2. Ready**
- The process is ready to run and waiting for the CPU.

- It's in the ready queue, waiting for its turn.

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

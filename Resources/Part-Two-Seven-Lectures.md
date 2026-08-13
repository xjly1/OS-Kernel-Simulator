# Lecture 1 - OS: Linux OS:
    Why Do We Need Scheduling?
        The Objective of Multiprogramming:
            1. Running a process at all times.
            2. Maximizing CPU utilization.
    
    The concept:Instead of the processor remaining idle while waiting for an I/O input operation, we give it another operation to execute.

    Process Lifecycle (CPU-I/O Burst Cycle):
        1. CPU Burst:
            The time a process spends calculating and executing tasks within the processor.
        
        2. I/O Burst:
            The time a process spends waiting for input and output.
        
        * Most processes are characterized by a large number of short processor bursts.
        * A few processes take a very long time to complete.
    
    Shortest-Job-First (SJF) Scheduling:
        * Associate with each process the length of its next CPU burst:
            * Use these lengths to schedule the process with the shortest time

        * SJF is optimal – gives minimum average waiting time for a given set of processes
            * The difficulty is knowing the length of the next CPU request
            * Could ask the user
        
        EX1 - calculate average wait time for process table bellow:
            Processes:
                P1:
                    CPU Burst Time = 6
                P2:
                    CPU Burst Time = 2
                P3:
                    CPU Burst Time = 8
                P4:
                    CPU Burst Time = 3
            
            Wait time = start time – arrival time

            * All operations arrived at the same time (arrival time = 0)

            Step 1 - Sort Processes by Burst Time:
                Processes:
                    P2:
                        CPU Burst Time = 2
                    P4:
                        CPU Burst Time = 3
                    P1:
                        CPU Burst Time = 6
                    P3:
                        CPU Burst Time = 8
            
            Step 2 - Gantt Chart:
                Time = 0---2 (P2) 2---5(P4) 5---11(P1) 11---19(P3)
            
            Step 3 - Waiting Time Calculation:
                Processes:
                    P2:
                        Waiting Time = 0
                    P4:
                        Waiting Time = 2
                    P1:
                        Waiting Time = 5
                    P4:
                        Waiting Time = 11
                
                Average Waiting Time = (0 + 2 + 5 + 11) / 4 = 4.5
        
        EX2 - calculate average wait time for process table bellow:
            Processes:
                P1:
                    Arrival Time = 0
                    CPU Burst Time = 7
                P2:
                    Arrival Time = 2
                    CPU Burst Time = 4
                P3:
                    Arrival Time = 4
                    CPU Burst Time = 1
                P4:
                    Arrival Time = 5
                    CPU Burst Time = 4
            
            Step 1: At Time = 0
                * ONLY (P1), so it is implemented directly (there is no other option).
            
            Step 2: At Time = 7
                * Check the Operations that have reached so far
                    P2 (Arrival = 2, Burst = 4)
                    P3 (Arrival = 4, Burst = 1)
                    P4 (Arrival = 5, Burst = 4)
                
                * We choose the shortest
                    1-
                        Burst Time ⟶ P3
                        Time 7 → 8
                    2-
                        P2(4),P4 (4)
                        Same execution time ⟶ We break the tie using FCFS
                        → P2 arrived before P4
                        Time 8 → 12 : P2
                        Time 12 → 16 : P4
            
            Step 3 - Gantt Chart:
                Time = 0---7 (P1) 7---8(P3) 8---12(P2) 12---16(P4)
            
            Step 4 - Waiting Time Calculation:
                Processes:
                    P1:
                        Start Time = 0
                        Arrival = 0
                        Waiting time = 0
                    P2:
                        Start Time = 7
                        Arrival = 4
                        Waiting time = 3
                    P3:
                        Start Time = 8
                        Arrival = 2
                        Waiting time = 6
                    P4:
                        Start Time = 12
                        Arrival = 5
                        Waiting time = 7
                
                Average Waiting Time = 0 + 3 + 6 + 7 /4 = 4
    
    Shortest-remaining-time-first:
        * SRTF is the preemptive version of Shortest Job First (SJF).
        * The CPU is always allocated to the process with the smallest remaining execution time.
        * If a new process arrives with a remaining time less than the currently running process, the CPU is preempted immediately.
        * The currently executing process continues only if it still has the shortest remaining time.
        * Execution proceeds until:
            * the process finishes,
            * a shorter remaining-time process arrives.
        
        Example of Shortest Remaining Time First (SRTF):
            Processes:
                P1:
                    Arrival Time = 0
                    CPU Burst Time = 8
                P2:
                    Arrival Time = 1
                    CPU Burst Time = 4
                P3:
                    Arrival Time = 2
                    CPU Burst Time = 2
                P4:
                    Arrival Time = 3
                    CPU Burst Time = 1
            
            Explaination:
                1-
                    Time = 0
                    Available: P1 (8)
                    CPU executes P1
                
                2-
                    Time = 1
                    New process arrives: P2 (4)
                    Remaining times:
                        P1 = 7
                        P2 = 4 (shorter)
                        Preemption occurs → P2 executes

            Gantt Chart:
                Time = 0---1 (P1) 1---2(P2) 2---4(P3) 4---5(P4) 5---8(P2) 8---15(P1)
            
            Explaination:
                3-
                    Time = 2
                    New process arrives: P3 (2)
                    Remaining times:
                        P1 = 7
                        P2 = 3
                        P3 = 2
                    
                    CPU switches to P3
                
                4-
                    Time = 4
                    P3 finishes
                    Remaining shortest: P4 (1)
                
                5-
                    Then P4 runs → finishes
                    Then P2 runs → finishes
                    Finally P1 runs → finishes
            
            Waiting Time Calculation:
                Processes:
                    P1:
                        Waiting Time = 7
                    P2:
                        Waiting Time = 3
                    P3:
                        Waiting Time = 0
                    P4:
                        Waiting Time = 1
                
                Average Waiting Time=(7+3+0+1)/4=2.75
    
    Priority Scheduling:
        * Each process is assigned a priority number (integer).
        * The CPU is allocated to the process with the highest priority (smallest number = highest priority).
    
    Relation to SJF:
        * Shortest Job First (SJF) is a special case of priority scheduling.
        * Priority is the inverse of the predicted CPU burst time.
    
    Types:
        1-Preemptive Priority Scheduling
        2-Non-Preemptive Priority Scheduling
    
    Main Problem:
        * Starvation:
            Low-priority processes may never get CPU time.

    Solution:
        * Aging:
            Gradually increase the priority of a process the longer it waits.
    
    Example of Priority Scheduling (Algorithm used: Non-Preemptive Priority Scheduling):
        Processes:
            P1:
                Arrival Time = 0
                Burst Time = 6
                Priority = 3
            P2:
                Arrival Time = 0
                Burst Time = 4
                Priority = 1
            P3:
                Arrival Time = 0
                Burst Time = 5
                Priority = 2
            P4:
                Arrival Time = 0
                Burst Time = 3
                Priority = 4
        
        Step 1 - Sort by Priority:
            | Highest Priority P2(1)
            |                  P3(2)
            |                  P1(3)
            | Lowest Priority  P4(4)

            Note: In case of equal priority, we use FCFS.
        
        Step 2 - Gantt Chart:
            Time = 0---4 (P2) 4---9(P3) 9---15(P1) 15---18(P4)
        
        Step 3 - Waiting Time Calculation:
            Processes:
                P2:
                    Waiting Time = 0
                P3:
                    Waiting Time = 4
                P1:
                    Waiting Time = 9
                P4:
                    Waiting Time = 15
            
            Average Waiting Time = (0 + 4 + 9 + 15) /4 = 7

# Lecture 2 - Round Robin (RR):
    RR:
        * Round Robin (RR) is a preemptive CPU scheduling algorithm.
        * Each process receives a fixed time slice (Time Quantum).
        * The CPU rotates among processes in a circular order.
        * Main goal: Fairness and responsiveness.
    
    Objectives:
        1. Give all processes equal CPU opportunity.
        2. Prevent CPU monopolization.
        3. Improve response time in time-sharing systems.
    
    Why is it Called “Round Robin”?
        1. The CPU moves from one process to another in a fixed circular order.
        2. After executing the last process, the scheduler returns to the first process again.
        3. This rotation continues until all processes finish execution.
        4. The main goal is fairness among processes.
    
    How It Works? (Steps)
        1. Processes arrive and enter the Ready Queue.
        2. CPU assigns a Time Quantum (q).
        3. Process executes for q time.
        4. If unfinished → move to end of queue.
        5. Repeat until all processes finish.
    
    Time Quantum:
        1. Small unit of CPU time.
        2. Usually 10 – 100 ms.
        3. After quantum expires → preemption occurs.
        4. Timer interrupt selects next process.
    
    Round Robin Example - Gantt Chart:
        * q = 5
    
        Time = 0---5 (P1) 5---10(P2) 10---15(P3) 15---20(P3) 20---25(P4)

        * Large q ➜ behaves like FIFO scheduling.
        * Small q ➜ many context switches →high overhead.
        * Best performance when q balances fairness vs Overhead

    Advantages of Round Robin Scheduling:
        1. Fair scheduling for all processes (Equal CPU sharing).
        2. Prevents CPU starvation because every process gets a time slice.
        3. Good response time → very suitable for interactive and time-sharing systems.
        4. Simple and easy to implement using a circular queue.
        5. Simple and widely used in modern OSs.

        “Each process runs for a short turn, then waits while others get their turn — until all processes finish.”
    
    Example:
        * Turnaround Time = Completion Time - Arrival Time
        * Waiting Time = Turnaround Time - Burst Time

        Processes:
            P1:
                Arrival Time = 0
                Burst Time = 4
                Completion Time = 8
                Turnaround Time = 8 - 0 = 8
                Waiting Time = 8 - 4 = 4
            P2:
                Arrival Time = 0
                Burst Time = 5
                Completion Time = 12
                Turnaround Time = 12 - 0 = 12
                Waiting Time = 12 - 5 = 7
            P3:
                Arrival Time = 0
                Burst Time = 3
                Completion Time = 11
                Turnaround Time = 11 - 0 = 11
                Waiting Time = 11 - 3 = 8
        
        Average Turn around time = (8 + 12 + 11)/3 = 31/3 = 10.33 ms
        Average waiting time = (4 + 7 + 8)/3 = 19/3 = 6.33 ms
    
    * Typically, higher average turnaround than SJF, but better response
    * q should be large compared to context switch time
    * q usually 10ms to 100ms, context switch < 10 usec

    Explaination:
        1. Time 0-2 (P1 Executes):
            * P1 starts execution as it arrives at 0 ms.
            * Runs for 2 ms; remaining burst time = 5 - 2 = 3 ms.
            * Ready Queue: [P1].
        
        2. Time 2-4 (P1 Executes Again):
            * P1 continues execution since no other process has arrived yet.
            * Runs for 2 ms; remaining burst time = 3 - 2 = 1 ms.
            * P2 arrive at 4 ms.
            * Ready Queue: [P2, P1].
        
        3. Time 4-6 (P2 Executes):
            * P2 starts execution as it arrives at 4 ms.
            * Runs for 2 ms; remaining burst time = 2 - 2 = 0 ms.
            * P3 arrive at 5ms
            * Ready Queue: [P1, P3].
        
        4. Time 6-7 (P1 Executes):
            * P1 starts execution.
            * Runs for 1 ms; remaining burst time = 1 - 1 = 0 ms.
            * Ready Queue: [P3].
        
        5. Time 7-9 (P3 Executes):
            * P3 starts execution.
            * Remaining burst time = 4 - 2 = 2 ms.
            * Ready Queue: [P3].
        
        6. Time 9-11 (P3 Executes Again):
            * P3 resumes execution and runs for 2 ms and complete its execution
            * Remaining burst time = 2 - 2 = 0 ms.
            * Ready Queue: [].
    
    Time Quantum and Context Switch Time:
        Effect of Time Quantum Size:
            * Very small quantum → many context
            * switches → high overhead.
        
        Example:
            * Process = 10 time units
            * q = 12 —B finishes in I quantum
            * q = 6 —Y 2 quanta -y 1 switch
            * q = 1 -Y 9 switches

            q = 12 -> Chantt Chart:
                Time = 0---P---10
            
            q = 6 -> Chantt Chart:
                Time = 0---P---5--CS(6)--7---P---10
            
            q = 1 -> Chantt Chart:
                Time = 0--P--CS--P--CS(6)--P--CS--10
            
            q = 1 -> Chantt Chart:
                Time = 0---1---6---10
    
        Context Switch Overhead:
            * CPU saves current process state and loads another process.
            * If context-switch time ≈ 10% of quantum, then about 10% of CPU time is wasted on switching.
            * Modern systems:
                * Time quantum ≈ 10–100 ms
                * Context switch time < 10 μs (very small compared to q).
        
        Impact on Turnaround Time:
            * Average turnaround time improves when most processes finish within one quantum.
            * Example:
                * Three processes (10 units each):
                    * q = 1 → Average TAT ≈ 29
                    * q = 10 → Average TAT ≈ 20
                
            * Smaller quantum ⇒ more switches ⇒ larger turnaround time.
        
        Choosing the Best Quantum (Important Rule):
            * Quantum should be:
                * Large compared to context-switch time
                * Not too large (otherwise RR becomes FCFS)
            
            * Rule of thumb: 80% of CPU bursts should be shorter than the time quantum.
            * Small q → Better response time but more overhead.
            * Large q → Less overhead but poorer fairness.
    
    Multilevel Queue Scheduling:
        * Processes are divided into separate queues based on priority or type.
        * Each queue has its own scheduling algorithm.
        * The CPU always selects from the highest-priority non-empty queue.
        
        How It Works?
            * Static priority is assigned to every process.
            * A process remains in the same queue during execution.
            * If multiple processes exist in one queue → scheduling inside the queue (e.g., Round Robin).
        
        Types of Queues (Example):
            1.Real-time processes — highest priority
            2.System processes
            3.Interactive processes
            4.Batch processes — lowest priority
            Not: Higher queues can preempt lower ones.
        
        Scheduling Inside Queues:
            * Foreground (interactive) → often Round Robin (RR)
            * Background (batch) → often FCFS
            
            Two common approaches:
                * Fixed-priority preemptive
                    * Higher queue always runs first.

                * Time slicing between queues
                    Example: Foreground 80% CPU, Background 20%.

                * Multilevel Queue ≠Multilevel Feedback Queue Here, processes do NOT move between queues.
                * Useful when process classes have different response needs
    
    Multilevel Feedback Queue Scheduling (MLFQ):
        * Advanced CPU scheduling algorithm.
        * Processes can move between queues depending on behavior.
        * Designed to separate:
            * Interactive / I-O bound processes
            * CPU-bound long processes
        
        How Processes Move in Multi-Level Feedback Queue (MLFQ)?
            * New process enters highest-priority queue (Q0).
            * If it uses too much CPU time → moved to lower queue.
            * Short jobs stay in high priority.
            * Long jobs gradually move downward.
            
            Note: Favor short and interactive processes.
        
        Movement Between Queues:
            * Demotion:
                * If process exceeds its time quantum → move to lower priority.
            
            * Promotion (Aging):
                * If process waits too long → move to higher queue.
            
            * Prevents starvation.
        
        Example Configuration:
            Queues ordered by priority:
                * Queue 0 → RR, quantum = 8 ms
                * Queue 1 → RR, quantum = 16 ms
                * Queue 2 → FCFS
            
            Execution rule:
                * CPU always serves highest non-empty queue.
                * Arrival in higher queue preempts lower queues.
        
        How Execution Happens?
            1. Process enters Q0.
            2. If finishes within 8 ms → done.
            3. If not → moved to Q1.
            4. If still unfinished after 16 ms → moved to Q2 (FCFS).
            
            Note: Short CPU bursts get fastest response.
        
        Parameters that Define MLFQ:
            * Number of queues.
            * Scheduling algorithm in each queue.
            * Promotion rule.
            * Demotion rule.
            * Initial queue placement.
        
        Advantages:
            * Adaptive scheduling (behavior-based).
            * Excellent response time for interactive jobs.
            * Reduces starvation using aging.
        
        Disadvantages:
            * Complex to design and tune.
            * Requires careful selection of quantum values.
            * Harder to analyze mathematically.
        
        Important Exam Note:
            * Multilevel Queue: process stays in same queue.
            * Multilevel Feedback Queue: process moves between queues

# Lecture 3 - Oprating system:
    Process and Thread Resource Structure:
        Dedicated Resources:
            Each thread has its own private resources that are not shared:

            Per Thread:
                - Stack
                - Registers
                - Program Counter

            > Each thread maintains its own independent execution state.

        Shared Resources:
            These resources are shared among all threads within the same process:
                - Code (Program Code)
                - Heap (Dynamic Memory)
                - Files (Open Files)
        
        Overall Structure:
            Process Contains:
                - Code
                - Heap
                - Files
            
            Each Thread Contains:
                - Its own Stack
                - Its own Registers
                - Its own Program Counter
        
        Relationship Between Threads and Resources:
            * All threads:
                - Execute the same Code
                - Share Heap and Files

            * Each thread:
                - Has its own Stack
                - Has its own Registers
                - Has its own Program Counter
    
    Thread Scheduling Architecture:
        1. Thread:
            The basic unit of execution in a system.
        
        2. Scheduling Types:
            * PCS (Process-Contention Scope) Scheduling:
                - Occurs in User Space
            
            * SCS (System-Contention Scope) Scheduling:
                - Occurs in Kernel Space
        
        3. User Space:
            User-Level Threads (ULT):
                - Managed at the user level.
                - Controlled by a Thread Library.
                - Do not interact directly with the kernel.
            
            Components:
                - Thread Library
                - Threads
        
        4. Kernel Space:
            Kernel-Level Threads (KLT):
                - Managed by the OS kernel.
                - Scheduled by the OS Scheduler.
            
            Components:
                - Kernel-Level Threads
                - OS Scheduler
        
        5. Mapping (ULT ↔ KLT):
            Types of mapping:
                - 1 : 1
                    - Each user thread maps to one kernel thread.

                - M : 1
                    - Multiple user threads map to a single kernel thread.

                - M : M
                    - Multiple user threads map to multiple kernel threads.
        
        6. Important Note:
            Modern OSs schedule threads, not processes.
    
    User vs Kernel Threads:
        User-Level Threads:
            * Managed by thread library.
            * Kernel is unaware of them.
            * Fast but need mapping to run on CPU.
        
        Process-Contention Scope (PCS):
            * Scheduling competition inside one process.
            * Thread library selects which user thread runs.
            * Often based on programmer-set priority.
        
        Kernel-Level Threads:
            * Managed by OS.
            * Scheduled directly on CPU
        
        System-Contention Scope (SCS):
            * Kernel schedules kernel threads on CPUs.
            * Competition among all threads in system.
            * Managed by OS scheduler.
    
    Thread Mapping & LWP:
        User threads -> LWP -> Kernel Threads -> CPU
        LWP acts as a bridge.
        Used in Many-to-Many model.
    
    Multiple-Processor Scheduling:
        CPU scheduling more complex when multiple CPUs are available
            * Homogeneous processors within a multiprocessor
            * Asymmetric multiprocessing – only one processor accesses the system data structures, alleviating the need for data sharing
            * Symmetric multiprocessing (SMP) – each processor is self scheduling, all processes in common ready queue, or each has its own private queue of ready processes
                * Currently, most common
            
            Processor affinity – process has affinity for processor on which it is currently running
                * soft affinity
                * hard affinity
                * Variations including processor sets
    
    Multiple-Processor Scheduling – Load Balancing:
        * If SMP, need to keep all CPUs loaded for efficiency
        * Load balancing attempts to keep workload evenly distributed
        * Push migration – periodic task checks load on each processor, and if found pushes task from overloaded CPU to other CPUs
        * Pull migration – idle processors pulls waiting task from busy processor
    
    Multicore Processors:
        * Recent trend to place multiple processor cores on same physical chip
        * Faster and consumes less power
        * Multiple threads per core also growing
            * Takes advantage of memory stall to make progress on another
    
    Multithreaded Multicore System:
        * Modern processors include multiple computing cores. pihc elgnis a no
        * Each core may support multiple hardware threads.(TMS / gnidaerhtitluM pihC)
        * Every hardware thread maintains its architectural state and appears to the OS as a logical CPU.
    
    Levels of Scheduling:
        1. OS Level: selects software threads to run on logical CPUs.
        2. Hardware Level: the core decides which hardware thread executes at a given time.

    Advantages:
        1. Processors often experience memory stalls due to cache misses or slow memory access.
        2. When one hardware thread stalls, the core switches to another thread to improve CPU utilization and throughput.
    
    Real-Time CPU Scheduling:
        * Can present obvious challenges
        * Soft real-time systems – no guarantee as to when critical real-time process will be scheduled
        * Hard real-time systems –task must be serviced by its deadline
        * Two types of latencies affect performance:
            1. Interrupt latency – time from arrival of interrupt to start of routine that services interrupt
            2. Dispatch latency – time for schedule to take current process off CPU and switch to another
        
        * Conflict phase of dispatch latency:
            1. Preemption of any process running in kernel mode
            2. Release by low-priority process of resources needed by high-priority processes
    
    Priority-based Scheduling:
        * For real-time scheduling, scheduler must support preemptive, priority-based scheduling
            * But only guarantees soft real-time
        
        * For hard real-time must also provide ability to meet deadlines
        * Processes have new characteristics: periodic ones require CPU at constant intervals
            * Has processing time t, deadline d, period p
            * 0 ≤ t ≤ d ≤ p
            * Rate of periodic task is 1/p
        
    Algorithm Evaluation:
        How to select CPU-scheduling algorithm for an OS?
            Determine criteria, then evaluate algorithms
            Deterministic modeling
            Type of analytic evaluation
            Takes a particular predetermined workload and defines the performance of each algorithm for that workload Consider 5 processes arriving at time 0:

            Processes:
                p1:
                    Burst Time = 10
                p2:
                    Burst Time = 29
                p3:
                    Burst Time = 3
                p4:
                    Burst Time = 7
                p5:
                    Burst Time = 12
            
            Find minimum average waiting time.

            * For each algorithm, calculate minimum average waiting time
            * Simple and fast, but requires exact numbers for input, applies only to those inputs

            FCFS is 28ms:
                0---10(p1) 10---39(p2) 39---42(p3) 42---49(p4) 49---61(p5)
            
            Non_ preemptive SFJ is 13ms:
                0---3(p3) 3---10(p4) 10---20(p1) 20---32(p5) 32---61(p2)
            
            RR is 23ms:
                0---10(p1) 10---20(p2) 20---23(p3) 23---30(p4) 30---40(p5) 40---50(p2) 50---52(p5) 52---61(p2)
    
    Context Switch Overhead:
        * CPU saves current process state and loads another process.
        * If context-switch time ≈ 10% of quantum, then about 10% of CPU time is wasted on switching.
        * Modern systems:
            * Time quantum ≈ 10–100 ms
            * Context switch time < 10 μs (very small compared to q).
    
    Impact on Turnaround Time:
        * Average turnaround time improves when most processes finish within one quantum.
        * Example:
            * Three processes (10 units each):
                * q = 1 → Average TAT ≈ 29
                * q = 10 → Average TAT ≈ 20

        * Smaller quantum ⇒ more switches ⇒ larger turnaround time.
    
    Choosing the Best Quantum (Important Rule):
        * Quantum should be:
            * Large compared to context-switch time
            * Not too large (otherwise RR becomes FCFS)
        
        * Rule of thumb: 80% of CPU bursts should be shorter than the time quantum.
        * Small q → Better response time but more overhead.
        * Large q → Less overhead but poorer fairness.
    
    Multilevel Queue Scheduling:
        * Processes are divided into separate queues based on priority or type.
        * Each queue has its own scheduling algorithm.
        * The CPU always selects from the highest-priority non-empty queue.

        How It Works?
            * Static priority is assigned to every process.
            * A process remains in the same queue during execution.
            * If multiple processes exist in one queue → scheduling inside the queue (e.g., Round Robin).
    
    Types of Queues (Example):
        1.Real-time processes — highest priority
        2.System processes
        3.Interactive processes
        4.Batch processes — lowest priority

        Not:Higher queues can preempt lower ones.
    
    Scheduling Inside Queues:
        * Foreground (interactive) → often Round Robin (RR)
        * Background (batch) → often FCFS
        
        Two common approaches:
            * Fixed-priority preemptive
                * Higher queue always runs first.

            * Time slicing between queues
                Example: Foreground 80% CPU, Background 20%.
            
            * Multilevel Queue ≠Multilevel Feedback Queue Here, processes do NOT move.seueuq neewteb
            * Useful when process classes have different response needs
    
    Multilevel Feedback Queue Scheduling (MLFQ):
        * Advanced CPU scheduling algorithm.
        * Processes can move between queues depending on behavior.
        * Designed to separate:
            * Interactive / I-O bound processes
            * CPU-bound long processes
        
        How Processes Move in Multi-Level Feedback Queue (MLFQ)?
            * New process enters highest-priority queue (Q0).
            * If it uses too much CPU time → moved to lower queue.
            * Short jobs stay in high priority.
            * Long jobs gradually move downward.
            
            Note: Favor short and interactive processes.

            Movement Between Queues:
                * Demotion:
                    * If process exceeds its time quantum → move to lower priority.
                
                * Promotion (Aging):
                    * If process waits too long → move to higher queue.
                
                * Prevents starvation.
        
        Example Configuration:
            Queues ordered by priority:
                Queue 0 → RR, quantum = 8 ms
                Queue 1 → RR, quantum = 16 ms
                Queue 2 → FCFS
            
            Execution rule:
                CPU always serves highest nonempty queue.
                Arrival in higher queue preempts lower queues.
        
        How Execution Happens?
            1. Process enters Q0.
            2. If finishes within 8 ms → done.
            3. If not → moved to Q1.
            4. If still unfinished after 16 ms → moved to Q2 (FCFS).

            Note:Short CPU bursts get fastest response.
        
        Parameters that Define MLFQ:
            * Number of queues.
            * Scheduling algorithm in each queue.
            * Promotion rule.
            * Demotion rule.
            * Initial queue placement.
        
        Advantages:
            * Adaptive scheduling (behavior-based).
            * Excellent response time for interactive jobs.
            * Reduces starvation using aging.
        
        Disadvantages:
            * Complex to design and tune.
            * Requires careful selection of quantum values.
            * Harder to analyze mathematically.
        
        Important Exam Note:
            * Multilevel Queue: process stays in same queue.
            * Multilevel Feedback Queue: process moves between queues.

# Lecture 4 - Synchronization Tools:
    Race Condition:
        * Occurs when multiple threads/processes access shared data simultaneously
        * At least one access is a write operation
        * Final result depends on execution timing
        * Leads to unpredictable or incorrect behavior

        * Processes P0 and P1 create child processes using fork()
        * Kernel variable next_available_pid stores the next available process ID
        * Both processes access this shared kernel variable
        * Without synchronization, both may read the same value
        * Result: Two different processes may receive the same PID
        * PID must be unique
        * Process table integrity depends on it
        * Kernel data structures are shared resources
        * This is a kernel-level race condition
        * Solve it by:
            * Spinlock
            * Mutex
            * Atomic operation
        
        * Only one process can modify it at a time
        * Race Condition in Kernel is catastrophic
    
    Critical Section Problem:
        * Consider a system of n processes {P0, P1, … , Pn−1}
        * Each process has a critical section segment of code
        * In critical section, process may:
            * Change shared variables
            * Update a table
            * Write to a file
        
        * If one process is in its critical section → no other process can be in its critical section

        General structure of process Pi:
            while (true) {
                Entry Section
                Critical Section
                Exit Section
                Remainder Section
            }
        
        Requirements for solution to critical-section problem

        1. Mutual Exclusion - If process Pi is executing in its critical section, then no other processes can be executing in their critical sections
        
        2. Progress - If no process is executing in its critical section and there exist some processes that wish to enter their critical section, then the selection of the process that will enter the critical section next cannot be postponed indefinitely
        
        3. Bounded Waiting - A bound must exist on the number of times that other processes are allowed to enter their critical sections after a process has made a request to enter its critical section and before that request is granted
            * Assume that each process executes at a nonzero speed
            * No assumption concerning relative speed of the n processes
        
    Interrupt-based Solution:
        * Entry section: disable interrupts
        * Exit section: enable interrupts
        * Will this solve the problem?
            * What if the critical section is code that runs for an hour?
            * Can some processes starve – never enter their critical section.
            * What if there are two CPUs?
        
        Software Solution 1:
            * Two process solution
            * Assume that the load and store machine-language instructions are atomic; that is, cannot be interrupted
            * The two processes share one variable:
                * int turn;
            
            * The variable turn indicates whose turn it is to enter the critical section
            * initially, the value of turn is set to i

            Algorithm for Process Pi:
                while (true){
                    while (turn = = j);
                    /* critical section */
                    turn = j;
                    /* remainder section */
                }
            
        Correctness of the Software Solution:
            * Mutual exclusion is preserved Pi enters critical section only if:
                turn = i
                and turn cannot be both 0 and 1 at the same time
            
            * What about the Progress requirement?
            * What about the Bounded-waiting requirement?
    
    Peterson’s Solution:
        * Two process solution
        * Assume that the load and store machine-language instructions are atomic; that is, cannot be interrupted
        * The two processes share two variables:
            * int turn;
            * boolean flag[2]
        
        * The variable turn indicates whose turn it is to enter the critical section
        * The flag array is used to indicate if a process is ready to enter the critical section.
            flag[i] = true implies that process Pi is ready!
        
        Algorithm for Process Pi:
            while (true){
                flag[i] = true;
                turn = j;
                while (flag[j] && turn = = j);
                
                /* critical section */
                flag[i] = false;
                /* remainder section */
            }
        
        Correctness of Peterson’s Solution:
            Provable that the three CS requirement are met:
                1. Mutual exclusion is preserved
                    Pi enters CS only if:
                        either flag[j] = false or turn = i
                        
                2. Progress requirement is satisfied
                3. Bounded-waiting requirement is met
    
    Peterson’s Solution and Modern Architecture:
        * Although useful for demonstrating an algorithm, Peterson’s Solution is not guaranteed to work on modern architectures.
            * To improve performance, processors and/or compilers may reorder operations that have no dependencies
        
        * Understanding why it will not work is useful for better understanding race conditions.
        * For single-threaded this is ok as the result will always be the same.
        * For multithreaded the reordering may produce inconsistent or unexpected results!
    
    Modern Architecture Example:
        * Two threads share the data:
            boolean flag = false;
            int x = 0;
        
        * Thread 1 performs
            while (!flag);
            print x

        * Thread 2 performs
            x = 100;
            flag = true
        
        * What is the expected output?
        *  However, since the variables flag and x are independent of each other, the instructions:
            flag = true;
            x = 100;
            for Thread 2 may be reordered
        
        * If this occurs, the output may be 0!
        * Because writes to x may not be visible to other cores immediately
        * Weak memory ordering allows reordering unless memory barriers are used
    
    Peterson’s Solution Revisited:
        * The effects of instruction reordering in Peterson’s Solution
        * This allows both processes to be in their critical section at the same time!
        * To ensure that Peterson’s solution will work correctly on modern computer architecture

    Memory Barrier:
        * Memory model are the memory guarantees a computer architecture makes to application programs.
        * Memory models may be either:
            * Strongly ordered – where a memory modification of one processor is immediately visible to all other processors.
            * Weakly ordered – where a memory modification of one processor may not be immediately visible to all other processors.
        
        * A memory barrier is an instruction that forces any change in memory to be propagated (made visible) to all other processors

        Memory Barrier Instructions:
            * When a memory barrier instruction is performed, the system ensures that all loads and stores are completed before any subsequent load or store operations are performed.
            
            * Therefore, even if instructions were reordered, the memory barrier ensures that the store operations are completed in memory and visible to other processors before future load or store operations are performed.
        
        Memory Barrier Example:
            * We could add a memory barrier to the following instructions to ensure Thread 1 outputs 100:
                * Thread 1 now performs
                    while (!flag){
                        memory_barrier();
                    }
                    print x
                
                *  Thread 2 now performs
                    x = 100;
                    memory_barrier();
                    flag = true
                
                * For Thread 1 we are guaranteed that that the value of flag is loaded before the value of x.
                * For Thread 2 we ensure that the assignment to x occurs before the assignment flag.

# Lecture 5 - Synchronization Hardware:
    Many systems provide hardware support to implement synchronization
    In early systems (Uniprocessor systems) the OS solved the problem by:
        Disabling interrupts:
            * When interrupts are disabled → the running code cannot be preempted
            * However this solution has problems in modern systems

            Limitations of Disabling Interrupts:
                * Works only on single processor systems
                * Not scalable for multiprocessor systems

                Problems:
                    * Very inefficient
                    * Only the kernel can use it
                    * If used frequently → system performance degrades
                
                Therefore modern systems rely on : Hardware synchronization primitives
    
    Types of Hardware Support:
        1. Hardware Instructions:
            Special CPU instructions that perform operations atomically
            Examples:
                Test-and-Set (TAS)
                Compare-and-Swap (CAS)
        
        2. Atomic Variables:
            Variables that support atomic read–modify–write operations
            Examples:
                atomic_int
                atomic_flag

                These ensure that concurrent updates are safe between threads.
        
        3. Memory Barriers (Memory Fences):
            Special instructions that prevent instruction reordering and ensure that:
                Memory updates become visible to other processors in the correct order.
            
            They are necessary because modern processors use:
                Weak memory ordering
            
    Hardware Instructions:
        Processors provide special instructions that can:
            * Test the value of a variable
            * Modify the variable
            * Swap values between variables
        
        All these operations occur atomically.
        Important examples:
            Test-and-Set (TAS), Compare-and-Swap (CAS)
        
        Test-and-Set Instruction:
            boolean test_and_set(boolean *target) {
                boolean rv = *target;
                *target = true;
                return rv;
            }

            Properties:
                * Executed atomically
                * Returns the original value
                * Sets the variable to true
            
            Mutual Exclusion using Test-and-Set:
                Shared variable: boolean lock = false;

                Algorithm:
                    do {
                        while (test_and_set(&lock)); // busy wait
                        /* critical section */
                        lock = false;
                        /* remainder section */
                    }
                    while (true);
    
        Compare-and-Swap Instruction (CAS):
            int compare_and_swap(int *value, int expected, int new_value) {
                int temp = *value;
                if (*value == expected)
                *value = new_value;
                return temp;
            }

            Properties:
                * Executed atomically
                * Compares value with expected value
                * Swaps value only if comparison succeeds
            
            Mutual Exclusion using CAS:
                Shared variable: int lock = 0;

                Algorithm:
                    while (true){
                        while(compare_and_swap(&lock,0,1) != 0); // busy wait
                        /* critical section */
                        lock = 0;
                        /* remainder section */
                    }
            
            Bounded Waiting with CAS:
                Problem:
                    CAS does not guarantee bounded waiting
                
                Solution:
                    Use an additional waiting array
                
                Algorithm ensures:
                    * Mutual Exclusion
                    * Progress
                    * Bounded Waiting
                
                while (true) {
                    waiting[i] = true;
                    key = 1;
                    while (waiting[i] && key == 1)
                        key = compare_and_swap(&lock,0,1);
                        waiting[i] = false;
                        /* critical section */
                        j = (i + 1) % n;
                        while ((j != i) && !waiting[j])
                            j = (j + 1) % n;
                            if (j == i)
                                lock = 0;
                            else
                                waiting[j] = false;
                            /* remainder section */
                        }
        
        Atomic Variables:
            * In concurrent systems, multiple processes may access shared data simultaneously.
            * To prevent incorrect results, the system must ensure that certain operations execute atomically.
            * An atomic operation is an operation that executes completely without interruption.
            
            Modern processors provide atomic variables allow safe updates to shared data atomic instructions that serve as building blocks for synchronization mechanisms.
                
    Hardware Support for Synchronization:
        * Modern processors provide atomic instructions that serve as building blocks for synchronization mechanisms.
        * One important instruction is:
            Compare-and-Swap (CAS)
        
        CAS is commonly used to implement:
            * Locks
            * Semaphores
            * Atomic variables
        These instructions ensure that memory updates occur safely.

        The increment() function can be implemented as follows:
            void increment(atomic_int *v) {
                int temp;
                
                do {
                    temp = *v;
                }
                
                while (temp != (compare_and_swap(v,temp,temp+1|)));
            }
    
    Mutex Locks:
        * Previous solutions to the Critical Section Problem such as Peterson’s Algorithm or other software approaches are often:
            * Complex
            * Difficult to implement correctly
            * Not practical for application programmers

        * Therefore, OS designers provide synchronization tools that simplify this problem.
        * One of the simplest and most widely used tools is the Mutex Lock.
        
        What is a Mutex Lock?
            A Mutex (Mutual Exclusion) Lock is a synchronization mechanism used to ensure that: Only one process or thread can access a critical section at a time.

            A mutex lock is typically implemented as a Boolean variable:
                lock = true → lock is available
                lock = false → lock is busy
            
            When a thread acquires the lock, no other thread can enter the critical section until the lock is released.
        
        Protecting a Critical Section:
            To safely access shared data, a thread must:
                1. Acquire the lock
                2. Execute the critical section
                3. Release the lock
        
        Algorithm:
            while (true) {
                acquire lock
                critical section
                release lock
                remainder section
            }
        
        Explanation:
            * acquire(lock) → enter protected area
            * critical section → access shared resource
            * release(lock) → allow others to enter
            * remainder section → normal execution
    
    Busy Waiting and Spinlocks:
        One drawback of simple mutex locks is busy waiting.
        When a thread cannot acquire the lock, it repeatedly checks the lock:
            while(lock == busy)
        
        This called: Spinlock
        Because the thread spins in a loop waiting for the lock to become available.
        
        Problem:
            Busy waiting can:
                * Waste CPU cycles
                * Reduce system efficiency
    
    Advantages of Mutex Locks:
        * Simple synchronization mechanism
        * Easy for programmers to understand
        * Supported by most programming languages
        * Efficient when lock waiting time is short
        * Commonly used in:
            * Multithreaded programs
            * OSs
            * Concurrent applications
    
    Disadvantages of Mutex Locks:
        * Busy waiting wastes CPU time
        * Not suitable for long waiting periods
        * Can cause deadlock if not used carefully
        * Example of deadlock:
            * Thread A holds Lock1 and waits for Lock2 Thread B holds Lock2 and waits for Lock1 Both threads wait forever.

# Lecture 6 - Semaphore in OSs:
    * Definition: A synchronization tool that provides more sophisticated ways for processes to synchronize their activities compared to Mutex locks.
    * The Variable: A Semaphore S is an integer variable.
    * Atomic Operations: It can only be accessed via two indivisible (atomic) operations:
        * wait(): Originally called P() (from Dutch Proberen, to test).
        * signal(): Originally called V() (from Dutch Verhogen, to increment).
    
    * Classic Definition:
        * wait(S){ while (S <= 0); S--;}(The while loop is known as Busy Waiting).
        * signal(S) { S++; }
    
    Types of Semaphore:
        * Counting Semaphore:
            * The integer value can range over an unrestricted domain.
            * Used to manage a resource with multiple instances (e.g., a pool of 5 printers).
        
        * Binary Semaphore:
            * The integer value ranges only between 0 and 1.
            * Functionally the same as a Mutex lock.
        
        * Versatility: You can implement a Counting Semaphore using Binary Semaphores.
    
    Solving Synchronization Problems with Semaphore’s algorithm:
        1.Critical Section (CS) Problem:
            1. Create a semaphore mutex initialized to 1.
            2.wait(mutex); → Critical Section → signal(mutex);
        
        2.Order of Execution (Sequence Control):
            1. Requirement: Statement S1 in Process P1 must happen before S2 in P2.
            2. Create a semaphore synch initialized to 0.
            3. P1: S1; signal(synch);
            4. P2: wait(synch); S2; (P2 will block until P1 signals).
        
        wait(S)
            {
                while (S <= 0) ; //
                busy wait
                S--;
            }
        signal(S)

        * Definition of the signal()
            operation
                signal(S) { S++; }
        
    The Implementation( Busy Waiting vs. Efficiency):
        * The Core Rule: No two processes can execute wait() and signal() on the same semaphore at the same time.
        * Busy Waiting (Spinlock):
            * While a process is in its critical section, any other process trying to enter must loop continuously in the call to wait().
            * Downside: Wastes CPU cycles.
            * Upside: Useful if the critical section is very short (no context switch needed)
    
    Implementation with No Busy Waiting:
        To avoid wasting CPU, semaphores are implemented with a Waiting Queue.
        
        * Structure: Each semaphore has an integer value and a list (queue) of processes.
        * Two Key System Calls:
            * block(): Places the process on the waiting queue and suspends it.
            * wakeup(): Removes a process from the waiting queue and moves it to the Ready Queue.
        
        * Waiting queue
            typedef struct {
                int value;
                struct process *list;
                }
            semaphore;
        
        wait(semaphore *S) {
            S->value--;
            if (S->value < 0) {
                add this process to S->list;
                block();
            }
        } 

        signal(semaphore *S) {
                S->value++;
                if (S->value <= 0) {
                    remove a process P from S->list; wakeup(P);
                }
            }
        
    Consequences of Incorrect Semaphore Usage:
        1. Reverse Order
            signal(mutex) → ... → wait(mutex)
            
            * Consequences:
                1. Mutual Exclusion Violation
                2. Race Conditions
                3. Data Corruption
        
        2. Fatal Repetition
            wait(mutex) → ... → wait(mutex)

            * Consequences:
                1. Deadlock
                2. Process Freeze
        
        3. Omission (Missing Operations)
            * Missing wait(mutex): signal(mutex) only
            
            Consequences:
                1. No Protection of Critical Section
                2. Mutual Exclusion Failure
            
        These – and others – are examples of what can occur when semaphores and other synchronization tools are used incorrectly.

    Why Monitors?
        * Human Error: Semaphores are effective but rely entirely on the programmer's discipline.
            A single mistake can lead to catastrophic timing errors.
        
        * Hard-to-Detect Bugs: Timing errors often occur only under specific execution sequences that are difficult to reproduce or debug.

        Common Programming Errors:
            1. Interchanging Operations: Calling signal(mutex) before wait(mutex) violates mutual exclusion.
            2. Replacing Operations: Calling wait(mutex) twice causes a permanent block (Deadlock).
            3. Omissions: Forgetting wait() or signal() results in either corrupted data or a frozen process.
    
    Monitors:
        * A high-level abstraction that provides a convenient and effective mechanism for process synchronization
        * Only one process may be active within the monitor at a time
        * Pseudocode syntax of
            * Abstract Data Type (ADT): A monitor encapsulates shared data with a set of functions that operate on that data.
            * Automatic Mutual Exclusion: Only one process at a time can be active within the monitor.
        
        * The Benefit: The programmer no longer needs to code synchronization constraints (like wait and signal for the mutex) explicitly; the monitor handles it
        * Encapsulation:
            * Shared variables are private to the monitor.
            * Only functions defined inside the monitor can access these variables.
        
        Monitors move the responsibility of synchronization from the programmer's logic to the programming language structure, making the system significantly more reliable and easier to maintain.
    
    Monitor Syntax:
        monitor monitor_name {
            /* shared variable declarations */
            function P1 (...) {
                /* operation logic - protected automatically */
            }

            function P2 (...) {
                /* operation logic - protected automatically */
            }

            initialization_code (...) {
                /* sets the initial state of variables */
            }
        }

    Advanced Synchronization Mechanism:
        Standard monitors are not enough for complex schemes where a process needs to wait for a specific condition.

        * The Solution: condition variables.
        * Declaration: condition x, y;
        * Operations:
            * x.wait(): The process calling this is suspended until another process calls signal().
                While suspended, it releases the monitor so others can enter.
            
            * x.signal(): Resumes exactly one suspended process. If no process is waiting, the operation has no effect (unlike semaphores where the value increases).
    
    Execution Flow with Condition Variables:
        * Process P.rotinom eht sretne
        * P sllac ti os ,deecorp tonnac ti srevocsid x.wait()
        * P.eerf won si rotinom ehT .x htiw detaicossa "eueuq gnitiaw" a ot devom si
        * Process Q.krow smrofrep dna rotinom eht sretne
        * Q sllac x.signal() pu sekaw hcihw ,P.
        * P.rotinom eht ot ssecca evisulcxe niager nac ti ecno noitucexe semuser

        Semaphore:
            Feature:
                Level: Low-level (Primitive)
                Management: Manual (Programmer must be careful)
                Mutual Exclusion: Explicitly coded
                Waiting Logic: Based on integer values (S)
                Safety: High risk of Deadlocks/Race conditions
        
        Monitor:
            Feature:
                Level: High-level (Language Construct)
                Management: Automatic (Handled by compiler/OS)
                Mutual Exclusion: Built-in / Implicit
                Waiting Logic: Based on condition variables
                Safety: Much safer and more robust

# Lecture 7 - Deadlock in OSs:
    * A situation where a set of threads are waiting for resources held by each other, causing them to stay in a permanent waiting state.
    * Deadlock problems are becoming more complex due to the increased demand for concurrency and parallelism on multicore systems.

    System Model - Resources:
        * Resource Distribution: A system has a finite number of resources (CPU cycles, files, I/O devices).
        * Resource Types & Instances:
    
    Resource Types & Instances:
        * Resources are categorized into Types (e.g., CPU, Network).
        * Each type consists of Identical Instances (e.g., a system with 4 CPUs has 4 instances of the CPU resource type).
    
    * Synchronization Tools: Mutex locks and semaphores are the most common sources of deadlock in modern systems.
    * Lock Specificity: Typically, each lock protects a specific data structure (like a queue or list), so each instance belongs to its own resource class.

    Solving Synchronization Problems with Semaphore’s algorithm:
        Resource Utilization Sequence:
            Under normal operation, a thread must follow this strict sequence:
                1. Request: The thread requests the resource. If held by another thread, the requester must wait.
                2. Use: The thread operates on the resource (e.g., accesses the critical section).
                3. Release: The thread releases the resource for others.
            
        OS Management: * System calls: request()/release(), open()/close(), wait()/signal().
        System Table: Tracks if resources are free or allocated and to which thread.
    
    Deadlock in Multithreaded Applications:
        * The Problem: Deadlocks often occur when developers use locking tools (designed to avoid race conditions) improperly.
        * Common Causes: Resource acquisition and release cycles involving logical resources (mutexes, semaphores, files) or IPC facilities.
        * Example: Dining-Philosophers Problem:
            * Resources = Chopsticks.
            * If every philosopher grabs the left chopstick simultaneously, no one can grab the right one.
            * Result: All threads are blocked waiting for each other.
    
    Conditions for Deadlock:
        Deadlock can arise only if the following four conditions hold simultaneously in a system:
            1. Mutual Exclusion: Only one thread at a time can use a resource (non-sharable mode).
            2. Hold and Wait: A thread holding at least one resource is waiting to acquire additional resources held by other threads.
            3. No Preemption: Resources cannot be taken away; they are only released voluntarily by the thread after completing its task.
            4. Circular Wait: A set of waiting threads {T0,T1,...,Tn} exists such that T0 waits for T1, T1 for T2, and Tn waits for T0.
        
    METHODS FOR HANDLING DEADLOCKS:
        Operating systems and applications can address the deadlock problem in one of three fundamental ways:
            1. Ignoring Deadlocks:
                The Approach: Ignore the problem altogether; pretend deadlocks never occur in the system.
                
                Implementation:
                    The most common solution, used by most operating systems, including Linux and Windows.
                    It is then up to kernel and application developers to handle deadlocks using other methods.
                
                Key Consideration: Expense is a significant factor. Ignoring the possibility of deadlocks is cheaper than other approaches. Deadlocks are infrequent (eg., once per month) in many systems, making this a pragmatic choice. Manual recovery for other failures (like livelock) is crucial.
            
            2-Deadlock Avoidance:
                Requires that the system has some additional a priori information available
                
                * Simplest and most useful model requires that each thread declare the maximum number of resources of each type that it may need
                * The deadlock-avoidance algorithm dynamically examines the resource-allocation state to ensure that there can never be a circular-wait condition
                * Resource-allocation state is defined by the number of available and allocated resources, and the maximum demands of the processes

                * Requires advance knowledge of resource needs
                * System checks before allocation:
                    * Available
                    * Allocation
                    * Need
            
    Safe State vs Unsafe State:
        A system is in a safe state if there exists a sequence <T1, T2, …, Tn> such that each thread can complete. 
        Each thread can obtain required resources from:
            * Available resources
            * Resources released by previous threads
            * Safe ⇒ No Deadlock
            * Unsafe ⇒ Deadlock may occur
    
    Safe vs Unsafe vs Deadlock:
        * Safe State → system can avoid deadlock
        * Unsafe State → possible deadlock
        * Deadlock State → system is stuck
    
    Banker’s Algorithm:
        * Used for multiple resource instances
        * Each thread declares maximum need
        * System ensures safe state before allocation
    
        Data Structures:
            * Available[m]
            * Max[n][m]
            * Allocation[n][m]
            * Need[n][m]
            * Need = Max –Allocation
        
        Safety Algorithm
            1.Work = Available
            2.Find process with Need ≤ Work
            3.Add Allocation to Work
            4.Repeat until all finish
        
        Banker’s Algorithm Example?
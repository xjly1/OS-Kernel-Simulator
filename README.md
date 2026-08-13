# OS Kernel Simulator

A C++ project exploring the implementation and simulation of core operating system kernel concepts from scratch.

The original goal of this project was to build an operating system, or get as close to a real operating system as possible through simulation, while understanding how its internal components work and interact with each other.

## Project Overview

This project is an ongoing and unfinished exploration of operating system concepts and kernel-level mechanisms.

The `OS-Simulator` directory contains the main implementation and experimentation with different operating system components, including:

- CPU and processor management
- Process Control Blocks (PCB)
- Process management
- Thread management
- CPU scheduling
- Memory Management Unit (MMU)
- Resource management
- Synchronization mechanisms
- Mutexes
- Semaphores
- Spinlocks
- Atomic operations
- Inter-Process Communication (IPC)
- Shared memory
- Message passing
- System calls
- Context switching
- Multicore scheduling
- Deadlock handling
- I/O management

### Scheduling Algorithms

The project also contains implementations and experiments involving several CPU scheduling algorithms:

- First-Come, First-Served (FCFS)
- Shortest Job First (SJF)
- Shortest Remaining Time First (SRTF)
- Round Robin (RR)
- Priority Scheduling
- Multilevel Queue
- Multilevel Feedback Queue (MLFQ)

## Project Structure

```text
.
├── OS-Simulator/
├── OS-Codes
├── Resources/
│   ├── Part-One-Nine-Lectures.md
│   └── Part-Two-Seven-Lectures.md
└── ...
```

## Technologies

- C++
- Rust — used for experimental work outside the main implementation
- Operating Systems concepts
- Concurrency and synchronization
- CPU scheduling

## Project Status

**Unfinished / In Development**

This project is not intended to represent a complete or production-ready operating system.

It is an educational project and an ongoing attempt to understand and reproduce operating system and kernel mechanisms through implementation and simulation.

Some components are incomplete, experimental, or require further integration.

## Purpose

The main purpose of this project is to move beyond learning operating system concepts theoretically and attempt to implement them in code.

Instead of treating the operating system as a black box, this project explores how components such as processes, threads, scheduling, memory management, synchronization, IPC, and system calls can be represented and implemented.

## Resources

The `Resources/` directory contains the lecture materials that were used as the primary educational reference for building this project.

The project was developed based on Operating Systems lectures provided by my university instructor, including additional material and topics discussed during the lectures beyond the standard course syllabus.

These materials were used as the main theoretical foundation for understanding the concepts implemented and explored throughout the project.

The lecture materials are included in this repository with permission from their original author.

## Note

This repository represents an unfinished stage of my attempt to understand and build an operating system from the ground up.

It is primarily a record of experimentation, learning, implementation, and exploration of operating system internals.
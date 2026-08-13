# Lecture 1 - Introduction to Operating Systems(OS):
	Operating System – Overview:
		1-Introduction to OS:
            An (OS) is an interface between a computer user and computer hardware.
            An OS is a software which performs all the basic tasks like file management, memory management, process management, handling input and output, and controlling peripheral devices such as disk drives and printers.
            Some popular OS include Linux, Windows, OS X, VMS, OS/400, AIX, z/OS, etc.

            1.1 OS Definitions:
                An OS is a program that acts as an intermediary between a user of a computer and the computer hardware.
                In the 1950's one might have defined OS as the software that control the hardware.
                An OS is a program that acts as an interface between the user and the computer hardware and controls the execution of all kinds of programs.
                Today we can define an OS as a set of programs implemented in either software or firmware, that make the hardware useable.
                The OS is primary resources manager, where the main resource it manage is computer HAY ( in the form of processor, storage, I/O devices, communication devices), and data.

            1.2 Computer System Components:
                An OS is an important part of almost every computer system. A Computer System can be divided roughly into four components:
                    1. The Hardware (CPU, memory, I/O devices).
                    2. Operating system (OS).
                    3. Application programs (Assembler, data base compiler text. editor).
                    4. The users (people, machines, other computers).
            
            1.3 OS Goals:
                1. The primary goal of an OS is to make OS convenient to use.
                2. A secondary goal is to use the computer H/W in an efficient manner.
            
            1.4 The OS Functions and services:
                1.4.1 OS Functions:
                    Following are some of important functions of an OS:
                        1. Memory Management
                        2. Processor Management
                        3. Device Management
                        4. File Management
                        5. Security
                        6. Control over system performance
                        7. Job accounting
                        8. Error detecting aids
                        9. Coordination between other software and users
                
                    1. Memory management:
                        Memory management refers to management of Primary Memory or Main Memory. Main memory is a large array of words or bytes where each word or byte has its own address.
                        Main memory provides a fast storage that can be accessed directly by the CPU. For a program to be executed, it must in the main memory. An OS does the following activities for memory management −
                            * Keeps tracks of primary memory, what part of it are in use by whom, what part are not in use.
                            * In multiprogramming, the OS decides which process will get memory when and how much.
                            * Allocates the memory when a process requests it to do so.
                            * De-allocates the memory when a process no longer needs it or has been terminated.
                    
                    2. Processor Management:
                        In multiprogramming environment, the OS decides which process gets the processor when and for how much time. This function is called process scheduling.
                        An OS does the following activities for processor management:
                            1. Keeps tracks of processor and status of process. The program responsible for this task
                            is known as traffic controller.
                            2. Allocates the processor (CPU) to a process.
                            3. De-allocates processor when a process is no longer required.
                    
                    3.Device Management:
                        An OS manages device communication via their respective drivers.
                        It does the following activities for device management −
                            1. Keeps tracks of all devices. Program responsible for this task is known as the I/O controller.
                            2. Decides which process gets the device when and for how much time.
                            3. Allocates the device in the efficient way.
                            4. De-allocates devices.
                    
                    4. File Management:
                        A file system is normally organized into directories for easy navigation and usage.
                        These directories may contain files and other directions.
                        An OS does the following activities for file management −
                            1. Keeps track of information, location, uses, status etc. The collective facilities are often known as file system.
                            2. Decides who gets the resources.
                            3. Allocates the resources.
                            4. De-allocates the resources.
                    
                    Other Important Activities:
                        1. Security − By means of password and similar other techniques, it prevents unauthorized access to programs and data.
                        2. Control over system performance − Recording delays between request for a service and response from the system.
                        3. Job accounting − Keeping track of time and resources used by various jobs and users.
                        4. Error detecting aids − Production of dumps, traces, error messages, and other debugging and error detecting aids.
                        5. Coordination between other softwares and users − Coordination and assignment of compilers, interpreters, assemblers and other software to the various users of the computer systems.
                    
                    Resource Management:
                        In case of multi-user or multi-tasking environment, resources such as main memory, CPU cycles and files storage are to be allocated to each user or job.
                        Following are the major activities of an OS with respect to resource management:
                            * The OS manages all kinds of resources using schedulers.
                            * CPU scheduling algorithms are used for better utilization of CPU.
                    
            Operating System:
                An OS provides services to both the users and to the programs.
                It provides programs an environment to execute.
                It provides users the services to execute the programs in a convenient manner.
                Following are a few common services provided by an OS:
                    1. Program execution
                    2. I/O operations
                    3. File System manipulation
                    4. Communication
                    5. Error Detection
                    6. Resource Allocation
                    7. Protection

# Lecture 2 - History of OSs & Different OSs:
    OS development history:
        OS have developed over the last 50 years through a number of distinct phases or generations to the decades:-
            * Early history (The 1940's and 1950's) In this lime the earliest Electronic digital computers had no OS.
            * Machines of that period were Primitive.
            * The programs were often entered one Bit at a time on rows of mechanical switches.
            * Eventually machine language programs were entered on punched cards, and assembly languages were developed to speed the programming process.
            * The 1' OS implemented in the early 1950's, this system ran one job at a time and smoothed the transition between jobs to get maximum utilization of the computer system.
            * This type of OS called single-stream Batch processing system, because program and data were submitted in groups or batches.
        
        OS 1960:
            * They were also batch processing system, but they were able to take advantage of computers resources by running several jobs at once.
            * The OS designer developed the concept of multiprogramming, and software engineering field was appeared.
        
        OS 1970:
            * They were multimode time — sharing system that supported batch processing, time-sharing, and real-time application.
            * They were in its first development stage.
            * Communication between C/S became widely used.
            * Communication in local area net works (LAN) was made practical and economical by Ethernet standard.
        
        OS 1980:
            * The 1980's was a decade of the workstation.
            * Microprocessor technology it became possible to build desktop computers as powerful as the mainframe of the 1970's.
            * Individuals could have their own computers for performing their work and they could use communication facilities for transmitting data between systems.
            * Computing was distributed to the sites which it was needed rather than bringing the data to be processed to some central-scale computer installation.
            * Application software packages are available such as:-
                1. Spread sheet programs.
                2. Word processors.
                3. Data base packages.
                4. Graphics packages.
                5. Transfer information between computers in computers in computer network (E-mail, Remate DB access application....etc) were widely used.
                6. The client/server model became wide spread : Clients are network users that need various services performed; servers and network components that perform these services.
        
        0.S 1990:
            * In the 1990's we enter the area of true distribute computing in which computations will be divided into sub-computation that can be executed on other processors in multiprocessor computer network.
            * Networks will be dynamically configured, they will continue operating even as new devices and S/W are added or removed by using registration procedure.
        
        0S 2000:
            * Middleware:
                * Links two separate applications: Often over a network and between incompatible machines
                * Particularly important for Web services: Simplifies communication across multiple architectures
            
            * Web services:
                * Encompass set of related standards
                * Ready-to-use pieces of software on the Internet
                * Enable any two applications to communicate and exchange data
    
    Types of OS:
        1. Batch OS:
            This type of OS does not interact with the computer directly. There is an operator which takes similar jobs having the same requirement and groups them into batches. It is the responsibility of the operator to sort jobs with similar needs.

            Advantage:
                * Multiple users can share the batch systems.
                * The idle time for the batch system is very less.
                * It is easy to manage large work repeatedly in batch systems.
            
            Disadvantage:
                * The computer operators should be well known with batch systems.
                * It is very difficult to guess or know the time required for any job to complete
                * Batch systems are hard to debug.
                * It is sometimes costly.
                * The other jobs will have to wait for an unknown time if any job fails.
        
        2. Time-sharing OS:
            Time-sharing is a technique which enables many people, located at various terminals, to use a particular computer system at the same time.
            Time-sharing or multitasking is a logical extension of multiprogramming. Processor's time which is shared among multiple users simultaneously is termed as time-sharing.
            The main difference between Multiprogrammed Batch Systems and Time-Sharing Systems is that in case of Multiprogrammed batch systems, the objective is to maximize processor use, whereas in Time-Sharing Systems, the objective is to minimize response time.
            Each user receives CPU time when using the system. These systems are known as Multitasking Systems.
            The tasks may belong to a single user or multiple users. The time allocated to each task is called a quantum. After this time interval expires, the (OS) switches to the next task.
            The OS uses CPU scheduling and multiprogramming to provide each user with a small portion of a time. Computer systems that were designed primarily as batch systems have been modified to time-sharing systems.

            Advantages:
                * Reduces CPU idle time.
                * Fairness: Each task gets an equal opportunity to run, preventing any single task from monopolizing the CPU.
                * Cost-Effectiveness: It allows multiple users to share a single, powerful computer, which is cheaper than providing a separate computer for each user.
                * Faster Response Time: Users don't have to wait for a long time to get results, as the system responds to their requests quickly and interactively.
                * Reduced Software Duplication: Multiple users can access and run the same software from a central location, reducing the need for individual copies.
            
            Disadvantages:
                * Reliability problem.
                * One must have to take care of the security and integrity of user programs and data.
                * Data communication problem.
                * High Overhead: Time-sharing systems have a higher overhead than other (OS)s due to the need for scheduling, context switching, and other overheads that come with supporting multiple users.
        
        3. Real Time OS:
            A real-time system is defined as a data processing system in which the time interval required to process and respond to inputs is so small that it controls the environment.
            The time taken by the system to respond to an input and display of required updated information is termed as the response time.
            So in this method, the response time is very less as compared to online processing.
            Real-time systems are used when there are rigid time requirements on the operation of a processor or the flow of data and real-time systems can be used as a control device in a dedicated application. A real-time OS must have well-defined, fixed time constraints, otherwise the system will fail.
            For example, Scientific experiments, medical imaging systems, industrial control systems, weapon systems, robots, air traffic control systems, etc.
            
            There are two types of real-time OSs:
                A- Hard real-time systems:
                    Hard real-time systems guarantee that critical tasks complete on time. In hard real-time systems, secondary storage is limited or missing and the data is stored in ROM. In these systems, virtual memory is almost never found.
                B- Soft real-time systems: 
                    Soft real-time systems are less restrictive.
                    A critical real-time task gets priority over other tasks and retains the priority until it completes.
                    Soft real-time systems have limited utility than hard real-time systems.
                    For example, multimedia, virtual reality, Advanced Scientific Projects like undersea exploration and planetary rovers, etc.
            
            Advantages of RTOS(Real Time OS):
                * Maximum Consumption: Maximum utilization of devices and systems, thus more output from all the resources.
                * Task Shifting: The time assigned for shifting tasks in these systems is very less.
                    For example, in older systems, it takes about 10 microseconds in shifting from one task to another, and in the latest systems, it takes 3 microseconds.
                * Focus on Application: Focus on running applications and less importance on applications that are in the queue.
            
            Disadvantages of RTOS:
                * Limited Tasks: Very few tasks run at the same time and their concentration is very less on a few applications to avoid errors.
                * Use heavy system resources: Sometimes the system resources are not so good and they are expensive as well.
                * Complex Algorithms: The algorithms are very complex and difficult for the designer to write on.
                * Device driver and interrupt signals: It needs specific device drivers and interrupts signal to respond earliest to interrupts.
                * Thread Priority: It is not good to set thread priority as these systems are very less prone to switching tasks.
        
        4.Multi-Programming System:
            can be simply illustrated as more than one program is present in the main memory and any one of them can be kept in execution.
            This is basically used for better execution of resources.
        
        5.Multi-Processing System:
            Is a type of OS in which more than one CPU is used for the execution of resources.
            It betters the throughput of the System.
        
        6.Multi-Tasking OS:
            Multitasking OS is simply a multiprogramming OS with having facility of a Round-Robin Scheduling Algorithm. It can run multiple programs simultaneously.
    
        7.Distributed OS:
            Distributed OS are a recent advancement in the world of computer technology and are gaining widespread and rapid acceptance all over the world.
            In these systems, various autonomous and interconnected computers communicate with each other over a shared network.
            Each independent system has its own memory unit and CPU, but they work together to form a single, coherent system.
        
        8.Network OS:
        These systems run on a server and provide the capability to manage data,users groups security,applications and other networking functions.
        These types of OS allow shared access to files printers security applications and other networking functions over a small private network.

# Lecture 3 - Layered OS:
    OS Structure:
        1. Simple Structure:
            * MS-DOS :written to provide the most functionally in the least space
            * Not divided into modules
            * Its interface and levels of functionally are not well separated

            Systems started as small, simple, and limited systems and then grew beyond their original scope.
            MS-DOS is an example of such a system. It was originally designed and implemented by a few people who had no idea that it would become so popular.
            It was written to provide the most functionality in the least space, so it was not carefully divided into modules.
            In MS-DOS, the interfaces and levels of functionality are notwell separated.
            For instance, application programs are able to access the basic I/O routines to write directly to the display and disk drives.
            Such freedom leaves MS-DOS vulnerable to errant (or malicious) programs, causing entire system crashes when user programs fail.
            Of course, MS-DOS was also limited by the hardware of its era. Because the Intel 8088 for which it was written provides no dual mode and no hardware protection, the designers of MS-DOS had no choice but to leave the base hardware accessible.
            Another example of limited structuring is the original UNIX OS. Like MS-DOS, UNIX initially was limited by hardware functionality.
            It consists of two separable parts: the kernel and the system programs. The kernel ROM BIOS device drivers application.
            is further separated into a series of interfaces and device drivers, which have been added and expanded over the years as UNIX has evolved.
            We can view the traditional UNIX OS as being layered to some extent, Everything below the system-call interface and above the physical hardware is the kernel.
            The kernel provides the file system, CPU scheduling, memory management, and other OS functions through system calls.
            Taken in sum, that is an enormous amount of functionality to be combined into one level.
            This monolithic structure was difficult to implement and maintain.
            It had a distinct performance advantage, however: there is very little overhead in the system call interface or in communication within the kernel.
            We still see evidence of this simple, monolithic structure in the UNIX, Linux, and Windows OS.
        
        2. Layered Structure:
            * The OS is divided into number of layers (levels), each built on top of lower layers.
            * The bottom layer (layer 0), is the hardware, the highest (layer n) is the user interface.
            * Each layer is implemented only with operations provided by lower-level layers.

            Layered Approach:
                An OS layer is an implementation of an abstract object made up of data and the operations that can manipulate those data.
                A typical OS layer—say, layer M—consists of data structures and a set of routines that can be invoked by higher-level layers.
                Layer M, in turn, can invoke operations on lower-level layers.
                A system can be made modular in many ways. One method is the layered approach, in which the OS is broken into a number of layers (levels).
                The bottom layer (layer 0) is the hardware; the highest (layer N) is the user interface.

            Layer structure of OS:
                Layer 5: User programs
                Layer 4: Buffering for input and output devices
                Layer 3: Operator-console device driver
                Layer 2: Memory Management
                Layer 1: CPU scheduling
                Layer 0: Hardware
            
            Challenges of layered OS structure:
                1. Because a layer can use only lower-level layers, careful planning is necessary.
                2. the CPU scheduler may have information about all the active processes than can fit in memory, this information need to be swapped in and out of memory, therefore, requiring the backing store driver routine to be below the CPU scheduler.
                3. It is less efficient than other types, its system call that takes longer than does one on a nonlayered system.
        
        3. Microkernels: 
            The microkernel approach is used develop modularized kernel that called Mach OS It removes all nonessential components from the kernel by implementing them as system and user-level programs.
            * microkernel provide s communication between the client program and the services that are also running in user space through messages.
            * the performance of microkernels suffers from overhead. due to increased system-function

            Benefits:
                * Easier to extend a microkernel
                * Easier to port the OS to new architectures
                * More reliable (less code is running in kernel mode)
                * More secure
            
            Detriments:
            * Performance overhead of user space to kernel space communication

            The main function of the microkernel is to provide communication between the client program and the various services that are also running in user space.
            Communication is provided through message passing, if the client program wishes to access a file, it must interact with the file server.
            The client program and service never interact directly. Rather, they communicate indirectly by exchanging messages with the microkernel.
            Tru64 UNIX (formerly Digital UNIX) provides a UNIX interface to the user, but it is implemented with a Mach kernel.
            The Mach kernel maps UNIX system calls into messages to the appropriate user-level services.
            The Mac OS X kernel (also known as Darwin) is also partly based on the Mach microkernel.
            Another example is QNX, a real-time OS for embedded systems.
            The QNX Neutrino microkernel provides services for message passing and process scheduling.
            It also handles low-level network communication and hardware interrupts.
            All other services in QNX are provided by standard processes that run outside the kernel in user mode.
            Unfortunately, the performance of microkernels can suffer due to increased system-function overhead.
            Consider the history of Windows NT.
            The first release had a layered microkernel organization.
            This version’s performance was low compared with that of Windows 95.
            Windows NT 4.0 partially corrected the performance problem by moving layers from user space to kernel space and integrating them more closely.
            By the time Windows XP was designed, Windows architecture had become more monolithic than microkernel.

        4. Modules:
            the kernel has a set of core components and links in additional services via modules, either at boot time or during run time.
            loadable kernel modules modern OS implementations such as:
                - Solaris,
                - Linux,
                - MacOS X,
                - Windows.
            
            Many modern OSs implement loadable kernel modules:
                * Uses object-oriented approach
                * Each core component is separate
                * Each talks to the others over known interfaces
                * Each is loadable as needed within the kernel
            
            Overall, similar to layers but with more flexible
                * Linux, Solaris, etc
            
            Solaris structure:
                core Solaris kernel:
                    * device and bus drivers
                    * scheduling classes
                    * file systems
                    * loadable system calls
                    * executable formats
                    * STREAMS modules
                    * miscellaneous modules
    
    Hybrid OS:
        Most modern OSs are actually not one pure model:
            * Hybrid combines multiple approaches to address performance, security, usability needs
            * Linux and Solaris kernels in kernel address space, so monolithic, plus modular for dynamic loading of functionality
            * Windows mostly monolithic, plus microkernel for different subsystem personalities
        
        Apple Mac OS X hybrid, layered, Aqua UI plus Cocoa programming environment
        * Below is kernel consisting of Mach microkernel and BSD Unix parts, plus I/O kit and dynamically loadable modules (called kernel extensions)
    
    IOS OS:
        Apple mobile OS for iPhone, iPad:
            * Structured on Mac OS X, added functionality
            * Does not run OS X applications natively
        
        Also runs on different CPU architecture (ARM vs. Intel):
            1. Cocoa Touch Objective-C API for developing apps
            2. Media services layer for graphics, audio, video
            3. Core services provides cloud computing, databases
            4. Core OS, based on Mac OS X 
    
    Android OS:
        Developed by Open Handset Alliance (mostly Google):
            * Open Source
        
        Similar stack to IOS
        Based on Linux kernel but modified:
            * Provides process, memory, device-driver management
            * Adds power management
    
        Runtime environment includes core set of libraries and Dalvik virtual machine:
            * Apps developed in Java plus Android API Java class files compiled to Java bytecode then translated to executable than runs in Dalvik VM
        
        Libraries include frameworks for web browser (webkit), database (SQLite), multimedia, smaller libc

# Lecture 4 - Introduction to OS Services:
    OS - Services:
        OS provide an environment for execution of programs and services to programs and users.
        One set of OS services provides functions that are helpful to the user:
            * User interface:
                Almost all OSs have a user interface (UI).
                Varies between Command-Line (CLI), Graphics User Interface (GUI), Batch
            
            * Program execution: The system must be able to load a program into memory and to run that program, end execution, either normally or abnormally (indicating error)
            * I/O operations: A running program may require I/O, which may involve a file or an I/O device.
        
        One set of OS services provides functions that are helpful to the user (Cont.):
            * File-system manipulation:
                The file system is of particular interest.
                Programs need to read and write files and directories, create and delete them, search them, list file Information, permission management.
            
            * Communications: Processes may exchange information, on the same computer or between computers over a network:
                * Communications may be via shared memory or through message passing (packets moved by the OS)
            
            * Error detection: OS needs to be constantly aware of possible errors:
                * May occur in the CPU and memory hardware, in I/O devices, in user program.
                * For each type of error, OS should take the appropriate action to ensure correct and consistent computing.
                * Debugging facilities can greatly enhance the user’s and programmer’s abilities to efficiently use the system.
        
        Another set of OS functions exists for ensuring the efficient operation of the system itself via resource sharing:
            * Resource allocation: When multiple users or multiple jobs running concurrently, resources must be allocated to each of them:
                * Many types of resources - CPU cycles, main memory, file storage, I/O devices.
            
            * Accounting: To keep track of which users use how much and what kinds of computer resources.
            * Protection and security: The owners of information stored in a multiuser or networked computer system may want to control use of that information, concurrent processes should not interfere with each other:
                * Protection involves ensuring that all access to system resources is controlled.
                * Security of the system from outsiders requires user authentication, extends to defending external I/O devices from invalid access attempts.
        
    User OS Interface - CLI:
        CLI or command interpreter allows direct command entry
            * Sometimes implemented in kernel, sometimes by systems program
            * Sometimes multiple flavors implemented – shells
            * Primarily fetches a command from user and executes it
            * Sometimes commands built-in, sometimes just names of programs
                * If the latter, adding new features doesn’t require shell modification
    
    User OS Interface - GUI:
        User-friendly desktop metaphor interface:
            * Usually mouse, keyboard, and monitor
            * Icons represent files, programs, actions, etc
            * Various mouse buttons over objects in the interface cause various actions (provide information, options, execute function, open directory (known as a folder))
            * Invented at Xerox PARC
        
        Many systems now include both CLI and GUI interfaces:
            * Microsoft Windows is GUI with CLI “command” shell
            * Apple Mac OS X is “Aqua” GUI interface with UNIX kernel underneath and shells available
            * Unix and Linux have CLI with optional GUI interfaces (CDE, KDE, GNOME)

    Touchscreen Interfaces:
        * Touchscreen devices require new interfaces:
            * Mouse not possible or not desired
            * Actions and selection based on gestures
            * Virtual keyboard for text entry
        
        *Voice commands.
    
    System Programs:
        System programs provide a convenient environment for program development and execution.
        They can be divided into:
            * File manipulation
            * Status information sometimes stored in a File modification
            * Programming language support
            * Program loading and execution
            * Communications
            * Background services
            * Application programs
        
        Most users’ view of the operation system is defined by system programs, not the actual system calls.
        Provide a convenient environment for program development and execution:
            * Some of them are simply user interfaces to system calls; others are considerably more complex
        
        1. File management: Create, delete, copy, rename, print, dump, list, and generally manipulate files and directories.
        2. Status information:
            * Some ask the system for info - date, time, amount of available memory, disk space, number of users
            * Others provide detailed performance, logging, and debugging information
            * Typically, these programs format and print the output to the terminal or other output devices
            * Some systems implement a registry - used to store and retrieve configuration information
        
        3. File modification:
            * Text editors to create and modify files(note pad,world pad,vi,vim)
            * Special commands to search contents of files or perform transformations of the text
        
        Programming-language support: Compilers, assemblers, debuggers and interpreters sometimes provided

        4. Program loading and execution:
            Absolute loaders, relocatable loaders, linkage editors, and overlay-loaders, debugging systems for higher-level and machine language(direct link library)
        
        5. Communications:
            Provide the mechanism for creating virtual connections among processes, users, and computer systems
            * Allow users to send messages to one another’s screens, browse web pages, send electronic-mail messages, log in remotely, transfer files from one machine to another
        
        6. Background Services:
            * Launch at boot time:
                * Some for system startup, then terminate
                * Some from system boot to shutdown
            * Provide facilities like disk checking, process scheduling, error logging, printing
            * Run in user context not kernel context
            * Known as services, subsystems, daemons
        
        7. Application programs:
            * Don’t pertain to system
            * Run by users
            * Not typically considered part of OS
            * Launched by command line, mouse click, finger poke
    
    OS Design and Implementation:
        * Design and Implementation of OS not “solvable”, but some approaches have proven successful
        * Internal structure of different OSs can vary widely
        * Start the design by defining goals and specifications
        * Affected by choice of hardware, type of system
        * User goals and System goals:
            * User goals: OS should be convenient to use, easy to learn, reliable, safe, and fast
            * System goals: OS should be easy to design, implement, and maintain, as well as flexible, reliable, error-free, and efficient
        
        * Important principle to separate:
            * Policy: What will be done?
            * Mechanism: How to do it?
        
        * Mechanisms determine how to do something, policies decide what will be done
        * The separation of policy from mechanism is a very important principle, it allows maximum flexibility if policy decisions are to be changed later (example: timer)
        * Specifying and designing an OS is highly creative task of software engineering
    
    Implementation:
        * Much variation:
            * Early OSes in assembly language
            * Then system programming languages like Algol, PL/1
            * Now C, C++
        
        * Actually usually a mix of languages:
            * Lowest levels in assembly
            * Main body in C
            * Systems programs in C, C++, scripting languages like PERL, Python, shell scripts
        
        * More high-level language easier to port to other hardware:
            * But slower
        
        * Emulation can allow an OS to run on non-native hardware

# Lecture 5 - System Calls & Interrupts in OS:
    System Calls:
        * Programming interface to the services provided by the OS
        * Typically written in a high-level language (C or C++)
        * Mostly accessed by programs via a high-level Application Programming Interface (API) rather than direct system call use
        * Three most common APIs are Win32 API for Windows, POSIX API for POSIX based systems (including virtually all versions of UNIX, Linux, and Mac OS X), and Java API for the Java virtual machine (JVM)

        Note: That the system-call names used throughout this text are generic

        * System call sequence to copy the contents of one file to another file:
            source file -------------------------------> destination file
                          Example System Call Sequence
                         Acquire input file name
                          Write prompt to screen
                          Accept input
                         Acquire output file name
                          Write prompt to screen
                          Accept input
                         Open the input file
                          if file doesn't exist, abort
                         Create output file
                          if file exists, abort
                         Loop
                          Read from input file
                          Write to output file
                         Until read fails
                         Close output file
                         Write completion message to screen
                         Terminate normally

        Example of Standard API:
            As an example of a standard API, consider the read() function that is available in UNIX and Linux systems.
            The API for this function is obtained from the man page by invoking the command:
                man read
            
            on the command line. A description of this API appears below:
                #include <unistd.h>
                    ssize_t read (int fd, void *buf, size_t count)
                ---------------------------------------------------------
                ssize_t: return value
                read: function name
                (int fd, void *buf, size_t count): parameters
            
            A program that uses the read function must include the unistd.h header
            file, as this file defines the ssize-t and size-t data types (among other things).
            Ihe parameters passed to read() are as follows:
                * int fd: the file descriptor to be read
                * void *buf: a buffer where the data will be read into
                * size-t count: the maximum number of bytes to be read into the buffer
            
            On a successful read, the number of bytes read is returned. A return value Of 0 indicates end of file. If an error occurs, read() returns —1.
        
        System Call Implementation:
            * Typically, a number associated with each system call:
                * System-call interface maintains a table indexed according to these numbers
            
            * The system call interface invokes the intended system call in OS kernel and returns status of the system call and any return values
            * The caller need know nothing about how the system call is implemented:
                * Just needs to obey API and understand what OS will do as a result call
                * Most details of OS interface hidden from programmer by API:
                    * Managed by run-time support library (set of functions built into libraries included with compiler)
        
        System Call Parameter Passing:
            * Often, more information is required than simply identity of desired system call:
                * Exact type and amount of information vary according to OS and call
            
            * Three general methods used to pass parameters to the OS:
                * Simplest: pass the parameters in registers:
                    * In some cases, may be more parameters than registers

                * Parameters stored in a block, or table, in memory, and address of block passed as a parameter in a register:
                    * This approach taken by Linux and Solaris
                
                * Parameters placed, or pushed, onto the stack by the program and popped off the stack by the OS
                * Block and stack methods do not limit the number or length of parameters being passed
        
        Types of System Calls:
            * Process control:
                * create process, terminate process
                * end, abort
                * load, execute
                * get process attributes, set process attributes
                * wait for time
                * wait event, signal event
                * allocate and free memory
                * Dump memory if error
                * Debugger for determining bugs, single step execution
                * Locks for managing access to shared data between processes
            
            * File management:
                * create file, delete file
                * open, close file
                * read, write, reposition
                * get and set file attributes
            
            * Device management:
                * request device, release device
                * read, write, reposition
                * get device attributes, set device attributes
                * logically attach or detach devices
            
            * Information maintenance:
                * get time or date, set time or date
                * get system data, set system data
                * get and set process, file, or device attributes
            
            * Communications:
                * create, delete communication connection
                * send, receive messages if message passing model to host name or process name:
                    * From client to server
                
                * Shared-memory model create and gain access to memory regions
                * transfer status information
                * attach and detach remote devices
            
            * Protection:
                * Control access to resources
                * Get and set permissions
                * Allow and deny user access
            
        Examples of Windows and Unix System Calls:
            * Process Control:
                * Windows:
                    * CreateProcess ()
                    * ExitProcess()
                    * WaitForSingIeObject ()
                
                * Unix:
                    * fork()
                    * exit ()
                    * wait ()
            
            * File Manipulation:
                * Windows:
                    * CreateFi1e()
                    * ReadFi1e()
                    * WriteFi1e()
                    * CloseHand1e()
                
                * Unix:
                    * open ()
                    * read ()
                    * write ()
                    * close()
            
            * Device Manipulation:
                * Windows:
                    * SetCons01eMode()
                    * ReadCons01e ()
                    * WriteConsole()
                
                *Unix:
                    * ioctl()
                    * read()
                    * write()
            
            * Information Maintenance:
                * Windows:
                    * GetCurrentProcessID()
                    * SetTimer()
                    * Sleep()
                
                *Unix:
                    * getpid()
                    * alarm ()
                    * sleep ()
            
            * Communication:
                * Windows:
                    * CreatePipe ()
                    * CreateFile Mapping ()
                    * MapViewOfFile()
                
                * Unix: 
                    * pipe ()
                    * shmget ()
                    * mmap ()
            
            * Protection:
                * Windows:
                    * SetFi1eSecurity()
                    * Init1ia1izeSecurityDescriptor()
                    * Set Securi tyDescriptorGroup ()
                
                * Unix:
                    * chmod ()
                    * umask ()
                    * chown ()
        
        Example: MS-DOS:
            * Single-tasking
            * Shell invoked when system booted
            * Simple method to run program:
                * No process created
            
            * Single memory space
            * Loads program into memory, overwriting all but the kernel
            * Program exit -> shell reloaded
        
        Example: FreeBSD:
            * Unix variant
            * Multitasking
            * User login -> invoke user’s choice of shell
            * Shell executes fork() system call to create process:
                * Executes exec() to load program into process
                * Shell waits for process to terminate or continues with user commands
            
            * Process exits with:
                * code = 0 – no error
                * code > 0 – error code
    
    Interrupts:
        * Interrupt transfers control to the interrupt service routine generally, through the interrupt vector, which contains the addresses of all the service routines
        * Interrupt architecture must save the address of the interrupted instruction
        * A trap or exception is a software-generated interrupt caused either by an error or a user request
        * An OS is interrupt driven

        Interrupt Handling:
            * The OS preserves the state of the CPU by storing registers and the program counter
            * Determines which type of interrupt has occurred:
                * polling
                * vectored interrupt system
            
            *Separate segments of code determine what action should be taken for each type of interrupt
        
        I/O Structure:
            * After I/O starts, control returns to user program only upon I/O completion:
                * Wait instruction idles the CPU until the next interrupt
                * Wait loop (contention for memory access)
                * At most one I/O request is outstanding at a time, no simultaneous I/O processing
            
            * After I/O starts, control returns to user program without waiting for I/O completion:
                * System call – request to the OS to allow user to wait for I/O completion
                * Device-status table contains entry for each I/O device indicating its type, address, and state
                * OS indexes into I/O device table to determine device status and to modify table entry to include interrupt

    The basic unit of computer storage is the bit. A bit can contain one of two values, O and 1.
    All other storage in a computer is based on collections of bits.
    Given enough bits, it is amazing how many things a computer can represent:
        numbers, letters, images, movies, sounds, documents, and programs,
    to name a few.
    A byte is 8 bits, and on most computers it is the smallest convenient chunk of storage.
    For example, most computers don't have an instruction to move a bit but do have one to move a byte.
    A less common term is word, which is a given computer architecture's native unit of data.
    A word is made up of one or more bytes. For example, a computer that has 64-bit registers and 64-bit memory addressing typically has 64-bit (8-byte) words.
    A computer executes many operations in its native word size rather than a byte at a time.
    Computer storage, along with most computer throughput, is generally measured and manipulated in bytes and collections of bytes.

    A kilobyte, or KB, is 1,024 bytes
    a megabyte, or MB, is 1,0242 bytes
    a gigabyte, or GB, is 1,0243 bytes
    a terabyte, or T B, is 1,0244 bytes
    a petabyte, or PB, is 1,0245 bytes

    Computer manufacturers often round off these numbers and say that a megabyte is I million bytes and a gigabyte is I billion bytes. Networking measurements are an exception to this general rule; they are given in bits (because networks move data a bit at a time).

    Storage Structure:
        * Main memory: only large storage media that the CPU can access directly
            * Random access
            * Typically volatile
        
        * Secondary storage: extension of main memory that provides large nonvolatile storage capacity
        * Hard disks: rigid metal or glass platters covered with magnetic recording material
        * Disk surface is logically divided into tracks, which are subdivided into sectors
        * The disk controller determines the logical interaction between the device and the computer
        * Solid-state disks: faster than hard disks, nonvolatile:
            * Various technologies
            * Becoming more popular

# Lecture 6 - Process Management in OS:
    An OS executes a variety of programs:
        *  Batch system-jobs
        * Time-shared systems-user programs or tasks
    
    Textbook uses the terms job and process almost interchangeably
    Process: a program in execution; process execution must progress in sequential fashion
    Multiple parts:
        * The program code, also called text section
        * Current activity including program counter, processor registers
        * Stack containing temporary data
        * Function parameters, return addresses, local variables
        * Data section containing global variables
        * Heap containing memory dynamically allocated during run time
    
    Program is passive entity stored on disk (executable file), process is active
        * Program becomes process when executable file loaded into memory
    
    Execution of program started via GUI mouse clicks, command line entry of its name, etc
    One program can be several processes:
        * Consider multiple users executing the same program
    
    Process State:
        As a process executes, it changes state:
            * new: The process is being created
            * running: Instructions are being executed
            * waiting: The process is waiting for some event to occur
            * ready: The process is waiting to be assigned to a processor
            * terminated: The process has finished execution
        
    Process Control Block (PCB):
        Information associated with each process (also called task control block)

        * Process state: running, waiting, etc.
        * Program counter: location of instruction to next execute
        * CPU registers: contents of all process-centric registers
        * CPU scheduling information: priorities, scheduling queue pointers
        * Memory-management information: memory allocated to the process
        * Accounting information: CPU used, clock time elapsed since start, time limits
        * I/O status information: I/O devices allocated to process, list of open files
    
    Threads:
        * So far, process has a single thread of execution
        * Consider having multiple program counters per process:
            * Multiple locations can execute at once:
                * Multiple threads of control -> threads
        
        * Must then have storage for thread details, multiple program counters in PCB
    
    Process Representation in Linux:
        Represented by the C structure task_struct
        pid t_pid; /* process identifier */
        long state; /* state of the process */
        unsigned int time_slice /* scheduling information */
        struct task_struct *parent; /* this process’s parent */
        struct list_head children; /* this process’s children */
        struct files_struct *files; /* list of open files */
        struct mm_struct *mm; /* address space of this process */

    Process Scheduling:
        * Maximize CPU use, quickly switch processes onto CPU for time sharing
        * Process scheduler selects among available processes for next execution on CPU
        * Maintains scheduling queues of processes
            * Job queue: set of all processes in the system
            * Ready queue: set of all processes residing in main memory, ready and waiting to execute
            * Device queues: set of processes waiting for an I/O device
            * Processes migrate among the various queues
    
    Schedulers:
        Short-term scheduler (or CPU scheduler): selects which process should be executed next and allocates CPU:
            * Sometimes the only scheduler in a system
            * Short-term scheduler is invoked frequently (milliseconds) -> (must be fast)
        
        Long-term scheduler (or job scheduler): selects which processes should be brought into the ready queue:
            * Long-term scheduler is invoked infrequently (seconds, minutes) -> (may be slow)
            * The long-term scheduler controls the degree of multiprogramming
        
        Processes can be described as either:
            * I/O-bound process: spends more time doing I/O than computations, many short CPU bursts
            * CPU-bound process: spends more time doing computations; few very long CPU bursts
        
        Long-term scheduler strives for good process mix
        Medium-term scheduler can be added if degree of multiple programming needs to decrease:
            * Remove process from memory, store on disk, bring back in from disk to continue execution: swapping
    
    Multitasking in Mobile Systems:
        Some mobile systems (early version of iOS) allow only one process to run, others suspended.
        Due to screen real estate, user interface limits iOS provides for a
            * Single foreground process- controlled via user interface
            * Multiple background processes: in memory, running, but not on the display, and with limits
            * Limits include single, short task, receiving notification of events, specific long-running tasks like audio playback
        
        Android runs foreground and background, with fewer limits:
            * Background process uses a service to perform tasks
            * Service can keep running even if background process is suspended
            * Service has no user interface, small memory use

# Lecture 7 - Process Context Switching:
    Context Switch:
        When CPU switches to another process, the system must save the state of the old process and load the saved state for the new process via a context switch.
        Context of a process represented in the PCB.
        Context-switch time is overhead; the system does no useful work while switching:
            * The more complex the OS and the PCB -> the longer the context switch
        
        Time dependent on hardware support:
            * Some hardware provides multiple sets of registers per CPU -> multiple contexts loaded at once
    
    Operations on Processes:
        System must provide mechanisms for:
            * process creation,
            * process termination,
            * and so on as detailed next
        
    Process Creation:
        Parent process create children processes, which, in turn create other processes, forming a tree of processes.
        Generally, process identified and managed via a process identifier (pid).
        Resource sharing options:
            * Parent and children share all resources
            * Children share subset of parent’s resources
            * Parent and child share no resources
        
        Execution options:
            * Parent and children execute concurrently
            * Parent waits until children terminate
        
        Address space:
            * Child duplicate of parent
            * Child has a program loaded into it
        
        UNIX examples:
            * fork() system call creates new process
            * exec() system call used after a fork() to replace the process’ memory space with a new program
    
    C Program Forking Separate Process:
        #include <sys/types.h>
        #include <Stdio.h>
        #include <unistd.h>

        int main(){
            pid_t pid;

            /*fork a child process*/
            pid = fork();

            if (pid < 0) { /* error occurred */
                fprintf(stderr. "Fork Faild");
                return 1;
            }

            else if (pid == 0) { /* child process */
                execlp ("/bin/ls", "ls", NULL);
            }

            else { /* parent process */
                /* parent will wait for the child to complete */
                wait(NULL);
                printf("Child Complete");
            }

            return 0;
        }
    
    Process Termination:
        Process executes last statement and then asks the OS to delete it using the exit() system call.
            * Returns status data from child to parent (via wait())
            * Process' resources are deallocated by OS
        
        Parent may terminate the execution of children processes using the abort() system call.
        Some reasons for doing so:
            * Child has exceeded allocated resources
            * Task assigned to child is no longer required
            * The parent is exiting and the OSs does not allow a child to continue if its parent terminates
        
        Some OSs do not allow child to exists if its parent has terminated. If a process terminates, then all its children must also be terminated.
            * cascading termination. All children, grandchildren, etc. are terminated.
            * The termination is initiated by the OS
        
        The parent process may wait for termination of a child process by using the wait() system call.
        The call returns status information and the pid of the terminated process
            pid = wait(&status);
        
        If no parent waiting (did not invoke wait()) process is a zombie.
        If parent terminated without invoking wait , process is an orphan.
    
    Multiprocess Architecture - Chrome Browser:
        Many web browsers ran as single process (some still do)
            * If one web site causes trouble, entire browser can hang or crash
        
        Google Chrome Browser is multiprocess with 3 different types of processes:
            * Browser process manages user interface, disk and network I/O
            * Renderer process renders web pages, deals with HTML, Javascript. A new renderer created for each website opened:
                * Runs in sandbox restricting disk and network I/O, minimizing effect of security exploits
            
            * Plug-in process for each type of plug-in
    
    Interprocess Communication:
        * Processes within a system may be independent or cooperating
        * Cooperating process can affect or be affected by other processes, including sharing data
        * Reasons for cooperating processes:
            * Information sharing
            * Computation speedup
            * Modularity
            * Convenience
        
        * Cooperating processes need interprocess communication (IPC)
        * Two models of IPC:
            * Shared memory
            * Message passing
    
    Cooperating Processes:
        * Independent process cannot affect or be affected by the execution of another process
        * Cooperating process can affect or be affected by the execution of another process
        * Advantages of process cooperation:
            * Information sharing
            * Computation speed-up
            * Modularity
            * Convenience
    
    Interprocess Communication - Shared Memory:
        * An area of memory shared among the processes that wish to communicate
        * The communication is under the control of the users processes not the OS.
        * Major issues is to provide mechanism that will allow the user processes to synchronize their actions when they access shared memory.
    
    Interprocess Communication - Message Passing:
        * Mechanism for processes to communicate and to synchronize their actions
        * Message system: processes communicate with each other without resorting to shared variables
        * IPC facility provides two operations:
            * send(message)
            * receive(message)
        
        * The message size is either fixed or variable
    
    Message Passing:
        * If processes P and Q wish to communicate, they need to:
            * Establish a communication link between them
            * Exchange messages via send/receive
        
        * Implementation issues:
            * How are links established?
            * Can a link be associated with more than two processes?
            * How many links can there be between every pair of communicating processes?
            * What is the capacity of a link?
            * Is the size of a message that the link can accommodate fixed or variable?
            * Is a link unidirectional or bi-directional?
        
        * Implementation of communication link:
            * Physical:
                * Shared memory
                * Hardware bus
                * Network

            * Logical:
                * Direct or indirect
                * Synchronous or asynchronous
                * Automatic or explicit buffering

# Lecture 8 - Threads:
    What is a Thread?
        A thread is a basic unit of CPU utilization; or a thread is a flow of control within a process.
        A multithreaded process contains several different flows of control within the same address space; it is called lightweight process.
        Each thread comprises a thread ID, a program counter, a register set, and a stack.
        It shares with other threads belonging to the same process its code section, data section, and other OS resources, such as open files and signals.
    
    For example:
        a word processor may have a thread for displaying graphics, another thread for responding to keystrokes from the user,
        and a third thread for performing spelling and grammar checking in the background.
    
    Motivation:
        * Most modern applications are multithreaded
        * Threads run within application
        * Multiple tasks with the application can be implemented by separate threads:
            * Update display
            * Fetch data
            * Spell checking
            * Answer a network request
        
        * Process creation is heavy-weight while thread creation is light-weight
        * Can simplify code, increase efficiency
        * Kernels are generally multithreaded
    
    Benefits:
        * Responsiveness: may allow continued execution if part of process is blocked, especially important for user interfaces
        * Resource Sharing: threads share resources of process, easier than shared memory or message passing
        * Economy: cheaper than process creation, thread switching lower overhead than context switching
        * Scalability: process can take advantage of multiprocessor architectures
        * Multicore or multiprocessor systems putting pressure on programmers, challenges include:
            * Dividing activities
            * Balance
            * Data splitting
            * Data dependency
            * Testing and debugging
        
        * Parallelism implies a system can perform more than one task simultaneously
        * Concurrency supports more than one task making progress:
            * Single processor / core, scheduler providing concurrency

        * Types of parallelism:
            * Data parallelism: distributes subsets of the same data across multiple cores, same operation on each
            * Task parallelism: distributing threads across cores, each thread performing unique operation
        
        * As # of threads grows, so does architectural support for threading:
            * CPUs have cores as well as hardware threads
            * Consider Oracle SPARC T4 with 8 cores, and 8 hardware threads per core
    
    Process Synchronization:
        * Processes can execute concurrently:
            * May be interrupted at any time, partially completing execution

        * Concurrent access to shared data may result in data inconsistency
        * Maintaining data consistency requires mechanisms to ensure the orderly execution of cooperating processes
        * Illustration of the problem:
            Suppose that we wanted to provide a solution to the consumer-producer problem that fills
            all the buffers.
            We can do so by having an integer counter that keeps track of the number of full buffers. Initially, counter is set to 0.
            It is incremented by the producer after it produces a new buffer and is decremented by the consumer after it consumes a buffer.
    
    Critical Section Problem:
        * Consider system of n processes {P0, P1, ...Pn-1}
        * Each process has critical section segment of code:
            * Process may be changing common variables, updating table, writing file, etc.
            * When one process in critical section, no other may be in its critical section
        
        * Critical section problem is to design protocol to solve this
        * Each process must ask permission to enter critical section in entry section, may follow critical section with exit section, then remainder section
    
    Solution to Critical-Section Problem:
        1. Mutual Exclusion: If process Pi is executing in its critical section, then no other processes can be executing in their critical sections
        2. Progress: If no process is executing in its critical section and there exist some processes that wish to enter their critical section, then the selection of the processes that will enter the critical section next cannot be postponed indefinitely
        3. Bounded Waiting: A bound must exist on the number of times that other processes are allowed to enter their critical sections after a process has made a request to enter its critical section and before that request is granted:
            * Assume that each process executes at a nonzero speed
            * No assumption concerning relative speed of the n processes
    
    Critical-Section Handling in OS:
        Two approaches depending on if kernel is preemptive or non- preemptive:
            * Preemptive: allows preemption of process when running in kernel mode
            * Non-preemptive: runs until exits kernel mode, blocks, or voluntarily yields CPU
                * Essentially free of race conditions in kernel mode
    
    Peterson's Solution:
        * Good algorithmic description of solving the problem
        * Two process solution
        * Assume that the load and store machine-language instructions are atomic; that is, cannot be interrupted
        * The two processes share two variables:
            * int turn;
            *Boolean flag[2]
        
        * The variable turn indicates whose turn it is to enter the critical section
        * The flag array is used to indicate if a process is ready to enter the critical section.
        flag[i] = true implies that process Pi is ready!

# Lecture 9 - Semaphore:
    Semaphore: Synchronization tool that provides more sophisticated ways (than Mutex locks) for process to synchronize their activities.

    * Semaphore S - integer variable
    * Can only be accessed via two indivisible (atomic) operations
        * wait() and signal()
            * Originally called P() and V()
    
    * Counting semaphore: integer value can range over an unrestricted domain
    * Binary semaphore: integer value can range only between 0 and 1
        * Same as a mutex lock
    
    * Can solve various synchronization problems

    Semaphore Implementation:
        * Must guarantee that no two processes can execute the wait() and signal() on the same semaphore at the same time
        * Thus, the implementation becomes the critical section problem where the wait and signal code are placed in the critical section
            * Could now have busy waiting in critical section implementation
                * But implementation code is short
                * Little busy waiting if critical section rarely occupied
        
        * Note that applications may spend lots of time in critical sections and therefore this is not a good solution
    
    Semaphore Implementation with no Busy waiting:
        * With each semaphore there is an associated waiting queue
        * Each entry in a waiting queue has two data items:
            * value (of type integer)
            * pointer to next record in the list

        * Two operations:
            * block: place the process invoking the operation on the appropriate waiting queue
            * wakeup: remove one of processes in the waiting queue and place it in the ready queue
    
    Classical Problems of Synchronization:
        * Classical problems used to test newly-proposed synchronization schemes
            * Bounded-Buffer Problem
            * Readers and Writers Problem
            * Dining-Philosophers Problem
    
    Bounded-Buffer Problem:
        * n buffers, each can hold one item
        * Semaphore mutex initialized to the value 1
        * Semaphore full initialized to the value 0
        * Semaphore empty initialized to the value n

        The structure of the producer process:
            do {
                ...
                /* produce an item in next_produced */

                ...

                wait(empty);
                wait(mutex);

                ...
                /* add next produced to the buffer */

                ...

                signal(mutex);
                signal(full);
            }

            While (true);
        
        The structure of the consumer process:
            do {
                wait(full);
                wait(mutex);

                ...

                /* remove an item in next consumed */

                ....
            }

            while (true);
    
    Readers-Writers Problem:
        * A data set is shared among a number of concurrent processes
            * Readers - only read the data set; they do not perform any updates
            * Writers - can both read and write

        * Problem - allow multiple readers to read at the same time
            * Only one single writer can access the shared data at the same time
        
        * Several variations of how readers and writers are considered - all involve some form of priorities
        * Shared Data:
            * Data set
            * Semaphore rw_mutex initialized to 1
            * Semaphore mutex initialized to 1
            * Integer read_count initialized to 0

        * The structure of a writer process:
            do {
                wait(rw_mutex);
                
                ...

                /* waiting is preformed */

                ...

                signal (rw_mutex);
            }

            while (true);
        
        * The structure of a reader process:
            do {
                wait(mutex);
                read_count++;

                if(read_count == 1){
                    wait (rw_mutex);
                }

                signal(mutex);

                ...

                /* reading is preformed */

                ...

                wait(mutex);
                read_count--;

                if(read_count == 0){
                    signal(rw_mutex);
                }

                signal(mutex);
            }

            while (true);
    
    Readers-Writers Problem Variations:
        * First variation - no reader kept waiting unless writer has permission to use shared object
        * Second variation - once writer is ready, it performs the write ASAP
        * Both may have starvation leading to even more variations
        * Problem is solved on some systems by kernel providing reader-writer locks
    
    Dining-Philosophers Problem:
        * Philosophers spend their lives alternating thinking and eating
        * Don't interact with their neighbors, occasionally try to pick up 2 chopsticks (one at a time) to eat from bowl
            * Need both to eat, then release both when done
        
        * In the case of 5 philosophers
            * Shared data:
                * Bowl of rice (data set)
                * Semaphore chopstick [5] initialized to 1
        
        * The structure of Philosopher:
            do {
                wait (chopstick[i]) ;
                wait (chopStick[ (i + 1) 5]);

                //eat

                signal (chopstick [i]);
                signal (chopstick [ (i + 1) % 5]);

                //think 
            }

            while (True);

            * What is the problem with this algorithm?
        
        * Deadlock handling:
            * Allow at most 4 philosophers to be sitting simultaneously at the table.
            * Allow a philosopher to pick up the forks only if both are available (picking must be done in a critical section).
            * Use an asymmetric solution -- an odd-numbered philosopher picks up first the left chopstick and then the right chopstick.
                Evennumbered philosopher picks up first the right chopstick and then the left chopstick.
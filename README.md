# ShellForge X 🛡️⚙️

**AI-Powered Interactive Unix Shell with Real-Time Visualization of Operating System Concepts**

ShellForge X is a functional, custom-built Unix shell written from scratch in C for Ubuntu Linux/WSL. Designed as a comprehensive 12-week Operating Systems (OSSP) course project, it natively utilizes POSIX system calls to execute commands. 

Unlike standard shells, ShellForge X will feature an **AI Assistance Layer** to explain system mechanics and a **Real-Time Visualization Dashboard** to expose core OS concepts (process management, memory, pipes, concurrency) that are usually hidden from the user.

---

## 👥 Team (G-3)
* **Satvik Pachipulusu** — 2510030227
* **Ramesh Siddardh** — 2510030303
* **Padmavathi** — 2510030085

---

## 💡 Project Philosophy
**A shell is not magic; it is a C program that communicates with the kernel.** 
Current OS education forces students to choose between raw, text-based programming with poor visibility, or modern AI tools that hide how the operating system actually works. 

ShellForge X bridges this gap. 
* **The Core:** The C/POSIX shell is the actual OS project. 
* **The AI Layer:** Natural language interpretation and command explanations.
* **The Visualization Layer:** Live telemetry of the Abstract Syntax Tree (AST), process trees, and memory states.

*Note: The AI and UI layers are educational enhancements and strictly do not replace the core C/POSIX execution environment.*

---

## 🏗️ Architecture & Tech Stack

### Core System (Current Focus)
* **Language:** C17
* **APIs:** POSIX (`fork()`, `execvp()`, `waitpid()`, `pipe()`, `dup2()`, pthreads)
* **Build/Debug:** GCC, Make, GDB, Valgrind

### Telemetry & Visualization (Upcoming)
* **Frontend:** React, Tailwind CSS, React Flow, Chart.js
* **Backend Bridge:** Python, FastAPI, WebSockets
* **AI:** LLM API integration

---

## 🚀 Build & Run Instructions

**Prerequisites:** Ubuntu Linux or WSL with `gcc` and `make` installed.

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/SATVIK-PACHIPULUSU/shellforgex.git](https://github.com/SATVIK-PACHIPULUSU/shellforgex.git)
   cd shellforgex









   shellforge-x/
├── include/           # Header files (.h)
│   ├── shell.h        # REPL and main loop
│   ├── parser.h       # Tokenizer and AST definitions
│   ├── process.h      # fork, exec, wait logic
│   ├── builtin.h      # cd, pwd, exit, etc.
│   └── history.h      # Command history
├── src/               # Source files (.c)
│   ├── main.c         # Entry point
│   ├── shell.c        # Core shell loop
│   ├── parser.c       # Input parsing logic
│   ├── process.c      # Process execution
│   ├── builtin.c      # Built-in implementations
│   └── history.c      # History management
├── assets/            # UI/UX assets
├── docs/              # Project documentation and architecture diagrams
├── tests/             # Unit and integration tests
├── Makefile           # Build instructions
└── README.md          # You are here





2-Week Development Roadmap
Weeks 1-4: Foundation & Execution
[x] Week 1 (REPL): Infinite read-evaluate loop, custom ShellForge> terminal prompt, raw string input capture, and the make build system.

[ ] Week 2 (Memory): Dynamic memory allocation (malloc, free) to replace fixed buffers, ensuring the shell safely handles arbitrarily long inputs without overflowing.

[x] Week 3 (Parsing): String tokenizer (delimiter parsing) and the initial Abstract Syntax Tree (AST) structures to break complex input into isolated executable arguments.

[x] Week 4 (Processes): Process cloning via fork(), binary execution via execvp(), and synchronization via waitpid() to run single external commands.

Weeks 5-8: Advanced Control & Plumbing
[ ] Week 5 (Built-ins): Environment PATH resolution (searching for binaries) and implementation of core shell built-in commands (cd, pwd, history, exit).

[ ] Week 6 (Signals): Asynchronous signal handling to safely capture Ctrl+C (SIGINT) and Ctrl+Z (SIGTSTP) without crashing the shell, plus a background child reaper (SIGCHLD).

[ ] Week 7 (Pipes): Inter-process communication via pipe() and file descriptor manipulation (dup2) to chain multiple independent commands together (e.g., ls | grep .c).

[ ] Week 8 (Virtual Memory): A custom memstat built-in command to track heap allocations, coupled with complete Valgrind memory-leak testing and validation.

Weeks 9-12: I/O, Concurrency & Polish
[ ] Week 9 (Redirection): Standard input, output, and error redirection operators (>, <, 2>) mapping active processes to physical text files.

[ ] Week 10 (Mutex): Posix threads (pthreads) and mutex locks to create a threaded background job monitor that prevents data races.

[ ] Week 11 (Deadlocks): Complete job control interface (jobs, fg, bg, kill) and an intentional deadlock demonstration mechanism.

[ ] Week 12 (Polish): The React/WebSocket telemetry bridge for the visualization dashboard, and the LLM API integration for natural language OS concept explanations.

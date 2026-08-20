
# ShellForge X

**AI-Powered Interactive Unix Shell with Real-Time Visualization of Operating System Concepts**

ShellForge X is a functional, custom-built Unix shell written from scratch in C for Ubuntu Linux/WSL. Designed as a comprehensive 12-week Operating Systems (OSSP) course project, it natively utilizes POSIX system calls to execute commands. 

Unlike standard shells, ShellForge X will feature an **AI Assistance Layer** to explain system mechanics and a **Real-Time Visualization Dashboard** to expose core OS concepts (process management, memory, pipes, concurrency) that are usually hidden from the user.

---

##  Team (G-3)
* **Satvik Pachipulusu** — 2510030227
* **Ramesh Siddardh** — 2510030303
* **Padmavathi** — 2510030085

---

##  Project Philosophy
**A shell is not magic; it is a C program that communicates with the kernel.** 
Current OS education forces students to choose between raw, text-based programming with poor visibility, or modern AI tools that hide how the operating system actually works. 

ShellForge X bridges this gap. 
* **The Core:** The C/POSIX shell is the actual OS project. 
* **The AI Layer:** Natural language interpretation and command explanations.
* **The Visualization Layer:** Live telemetry of the Abstract Syntax Tree (AST), process trees, and memory states.



---

##  Architecture & Tech Stack

### Core System (Current Focus)
* **Language:** C17
* **APIs:** POSIX (`fork()`, `execvp()`, `waitpid()`, `pipe()`, `dup2()`, pthreads)
* **Build/Debug:** GCC, Make, GDB, Valgrind

### Telemetry & Visualization (Upcoming)
* **Frontend:** React, Tailwind CSS, React Flow, Chart.js
* **Backend Bridge:** Python, FastAPI, WebSockets
* **AI:** LLM API integration

---

##  Build & Run Instructions

**Prerequisites:** Ubuntu Linux or WSL with `gcc` and `make` installed.

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/SATVIK-PACHIPULUSU/shellforgex.git](https://github.com/SATVIK-PACHIPULUSU/shellforgex.git)
   cd shellforgex

# 42 Common Core

My project map for **École 42 Lausanne**: from a first C library to Unix programming, graphics, C++, and HTTP servers.

This repository is the navigation hub. Projects live in their own repositories and are connected here as Git submodules, keeping each project’s history and README available independently.

## Explore the projects

The folders use zero-based Common Core ranks. The map follows the C/C++ curriculum represented by my project path; campus subjects and curriculum versions may differ. “Included” describes available source, not an official grade or completion record.

| Rank | Project | Focus |
| --- | --- | --- |
| 00 | [Libft](Lvl00/libft) | C library and memory/string utilities |
| 01 | [ft_printf](Lvl01/ft_printf) | Variadic functions and formatted output |
| 01 | [Get Next Line](Lvl01/get_next_line) | File descriptors and buffered reading |
| 02 | [Push Swap](Lvl02/push_swap) | Algorithms and constrained stack sorting |
| 02 | [Minitalk](Lvl02/minitalk) | Unix signal-based communication |
| 02 | [So Long](Lvl02/so_long) | 2D graphics and map validation |
| 03 | [Minishell](Lvl03/minishell) | Processes, pipelines, and shell parsing |
| 03 | [Philosophers](Lvl03/philosophers) | Threads, mutexes, and shared state |
| 04 | [miniRT](Lvl04/miniRT) | Ray tracing and 3D geometry |
| 04 | [C++ Modules · 00–09](Lvl04/CPP) | C++ modules 00–04; the same repository also contains 05–09 |
| 05 | [Webserv](Lvl05/webserv) | HTTP, sockets, multiplexing, and CGI |

**C++ continues in Rank 05:** modules [05](https://github.com/Rspinelli93/CPP-Piscine/tree/main/CPP05), [06](https://github.com/Rspinelli93/CPP-Piscine/tree/main/CPP06), [07](https://github.com/Rspinelli93/CPP-Piscine/tree/main/CPP07), [08](https://github.com/Rspinelli93/CPP-Piscine/tree/main/CPP08), and [09](https://github.com/Rspinelli93/CPP-Piscine/tree/main/CPP09) share the repository linked at `Lvl04/CPP`. They are not duplicated as a second submodule.

## How this matches the Common Core

The graph contains alternative project branches. My included path uses **Minitalk** for process communication, **So Long** for the first graphics project, **miniRT** for the later graphics project, and **Webserv** for the networking project. Their alternative branches are not additional requirements claimed by this repository.

| Stage | Other milestones in the reference path | Source in this hub |
| --- | --- | --- |
| Rank 01 | Born2beroot | Not included |
| Rank 04 | NetPractice | Not included |
| Rank 05 | Inception | Not included |
| Rank 06 | ft_transcendence | Not included |
| Exams | Exam ranks 02–06 | Practice files for ranks 02–05; no official exam results recorded |

The reference graph also contains specializations outside the Common Core. Those are separate from this hub. Its highlighted projects belong to the reference screenshot; they are not used as evidence of my own grades or completed projects.

## Clone everything

```bash
git clone --recurse-submodules https://github.com/Rspinelli93/42-Common-Core.git
cd 42-Common-Core
```

If you already cloned the hub:

```bash
git submodule sync --recursive
git submodule update --init --recursive
```

Initialize just one project:

```bash
git submodule update --init Lvl03/minishell
```

Each submodule is pinned to a specific commit. Updating this hub does not silently switch every project to its latest branch tip. After pulling a new hub commit, run `git submodule update --init --recursive` to check out its recorded versions. Build projects inside their own directories; there is no single root build target.

## Practice material

- [Exam training](Exam_Training/) groups independent exercises for exam ranks 02–05.
- [Earlier Get Next Line work](Practice/get_next_line_legacy/) preserves a separate implementation and its fixtures. The main Rank 01 project is the `Lvl01/get_next_line` submodule.
- [Training-C](https://github.com/Rspinelli93/Training-C) contains additional pointer, allocation, structure, and linked-list exercises.

## Repository layout

```text
Lvl00/          Libft
Lvl01/          ft_printf, get_next_line
Lvl02/          push_swap, minitalk, so_long
Lvl03/          minishell, philosophers
Lvl04/          miniRT, shared C++ module repository
Lvl05/          webserv, guide to C++ modules 05–09
Exam_Training/  Exam practice, separate from submitted projects
Practice/       Earlier implementations and supporting exercises
```

## Collaboration

The individual READMEs identify shared work, including Minishell with xiribar and miniRT/Webserv with glucken. The [Webserv portfolio copy](https://github.com/Rspinelli93/webserv) preserves the history of [G-Lck/webserv](https://github.com/G-Lck/webserv).

Use these projects to understand the approaches, compare implementations, and build your own solutions.

[My GitHub profile](https://github.com/Rspinelli93) · [All projects](https://github.com/Rspinelli93/Rspinelli93/blob/main/PROJECTS.md)

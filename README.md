<h1 align="center">
  Console ToDo App in C++
  <br>
</h1>

<h4 align="center">
A minimalist C++ console-based ToDo application—add, view, complete, and remove tasks while valiantly trying not to forget the milk (again).
</h4>

<p align="center">
  <a href="#-installation">Installation</a> •
  <a href="#-usage">Usage</a> •
  <a href="#-classes">Classes</a> •
  <a href="#-documentation">Documentation</a> •
  <a href="#-contributing">Contributing</a> •
  <a href="#-license">License</a> •
  <a href="#-acknowledgments">Acknowledgments</a> •
  <a href="#-disclaimer">Disclaimer</a>
</p>

---

## 💻 Installation

Requires a **C++17** (or higher) compiler.

1. **Clone** this repository:
   ```bash
   git clone https://github.com/andreaaazo/ToDoCPP.git
   cd ToDoC++
   ```
2. **Compile** and **run** (example using g++ on Linux/macOS):
   ```bash
   ./make-file.sh
   ```
   or
   ```bash
   g++ -I include \
    src/main.cpp src/Task.cpp src/TaskManager.cpp src/ToDoApp.cpp src/ConsoleUI.cpp \
    -o ToDoC++
   ```
3. **Windows** users can similarly compile with Visual Studio or MinGW, as long as you link the above files together.  
   *We promise we haven't intentionally left any cross-platform booby traps (the heaviest trap here is forgetting semicolons).*

---

## 🚀 Usage

Once compiled, run the program:
```bash
./ToDoC++.exe
```
You’ll see a simple menu:
```
1. Add task
2. View task
3. Complete task
4. Delete task
5. Exit
```

1. **Add task**: Prompted for a name and description—no more scribbling tasks on random sticky notes.  
2. **View task**: Lists all your tasks, reminding you of everything you promised you'd do yesterday.  
3. **Complete task**: Marks a task as done, granting that sweet, sweet feeling of productivity.  
4. **Delete task**: Removes a task from the list forever—like that 2016 resolution you’d rather forget.  
5. **Exit**: Closes the program. Attempts not to guilt-trip you about undone tasks.

> If you accidentally complete the “Make coffee” task first thing in the morning, you’re basically unstoppable for the day—unless you start reading memes instead.

---

## 🏗 Classes

### `Task`
- **Purpose:**  
  Represents a single to-do item with a name, description, and completion status.
- **Key Methods:**  
  - `markAsCompleted()` to check tasks off your never-ending list.  
  - `isCompleted()` to confirm whether you can lounge guilt-free.

### `TaskManager`
- **Purpose:**  
  Manages a collection of `Task` objects.
- **Key Methods:**  
  - `addTask(name, description)`: Because your memory is short.  
  - `completeTask(index)`: Because your will is strong.  
  - `removeTask(index)`: Because sometimes tasks deserve to be “lost” forever.

### `ConsoleUI`
- **Purpose:**  
  Handles all user interaction via the console. Think: *“Press 1 for new regrets.”*
- **Key Methods:**  
  - `showMenu()`, `getUserChoice()`: Steering the user’s fate.  
  - `displayTasks(...)`: Spams your terminal with your tasks (and a pinch of existential dread).

### `ToDoApp`
- **Purpose:**  
  Orchestrates the entire show. Creates and binds the `ConsoleUI` with the `TaskManager`.
- **Key Method:**  
  - `run()`: The main application loop—like a well-trained hamster wheel.

---

## 📄 Documentation

**Location:**  
Feel free to generate further docs using your favorite Doxygen configuration or rummage through the `.h` and `.cpp` files to discover the joys of function prototypes and witty comments.

**Developer Protip:**  
Be sure to read `ToDoApp.cpp` and `ConsoleUI.cpp` for the main flow. If you’re allergic to reading code, you can always do `doxygen Doxyfile` (if you set it up) and swirl through the generated HTML docs with that fancy new web browser of yours.

---

## 🤝 Contributing

We welcome PRs, issues, or daydreams about adding a cutting-edge artificial intelligence that automatically completes tasks for you. (Wait, that might be going too far—**we do not want a self-aware to-do list**.)

1. **Fork** this repository.  
2. **Create** a new feature branch.  
3. **Commit** your changes (sprinkle in tests if possible).  
4. **Open** a pull request. We’ll do the rest—like giving you a virtual high-five.

---

## 📄 License

This project is distributed under the [MIT License]("https://github.com/andreaaazo/ToDoCPP/blob/master/LICENSE.txt").  
You’re free to use, modify, and distribute this code—just like free samples at the grocery store. But please, don’t hog it all for yourself.

---

## 🙏 Acknowledgments

- **C++ Community**: For endless discussions on templates and segfaults that gave us nightmares and knowledge in equal measure.  
- **Coffee**: For fueling us through tasks that never ended, especially that one time we wrote code at 3 AM.  
- **Your Future Self**: For eventually remembering to do laundry.

> “Template metaprogramming is just a fancy way of saying, *I want to type curly braces for the next 3 hours.*”
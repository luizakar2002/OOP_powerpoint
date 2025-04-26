# PowerPoint Clone - C++ & Qt Implementation

## Overview

This project is a **PowerPoint-like presentation tool** built from scratch in **C++** using **Qt** for the GUI layer.  
It was designed with a strong focus on **SOLID principles**, making use of multiple **design patterns** (Command, Composite, Factory Method) to ensure **modularity** and **extensibility**.

---

## Structure

### 1. Commands

Implements the **Command design pattern**.  
Each user action (e.g., adding a slide, adding an item, displaying, showing help, quitting) is encapsulated as a distinct command class:

- `Command` (abstract base class)
- `AddItemCommand`
- `AddSlideCommand`
- `DisplayCommand`
- `HelpCommand`
- `QuitCommand`
- *(and more)*

Each command overrides the `execute()` method to perform its action independently.  
This decouples command invocation from execution logic, making features like **undo/redo** easily extendable.

---

### 2. Document Model

Implements a **Composite-like structure** for presentations:

- **Document** → contains multiple **Slides**
- **Slide** → contains multiple **Items**
- **Item** → represents a drawable object, each defined by:
  - A **BoundingBox** (two corner points)
  - An **ItemType** (e.g., rectangle, text, image)

This model allows complex slide hierarchies while treating individual and grouped elements uniformly.

---

### 3. Parser

Handles **user input parsing** and **command object creation**:

- **CommandCreator**: Creates specific `Command` instances.
- **CommandRegistry**: Maps user input strings to corresponding `CommandCreator`s.

This cleanly separates **input interpretation** from **application logic**, making new commands easy to add.

---

### 4. Qt GUI Layer

Built using **Qt Widgets**, the GUI is cleanly separated from the business logic:

- The **View** layer focuses solely on presentation and user interactions.
- The **Logic** layer is fully testable independently of the UI.



## Demo

![](https://github.com/luizakar2002/OOP_powerpoint/blob/main/media/Screenshot%20from%202024-01-12%2002-43-37.png)

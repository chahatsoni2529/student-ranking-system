# Student Performance Tracker & Ranking System

A robust, console-based C++ application designed to process student academic data, calculate percentages, handle edge-case exceptions, and dynamically rank top performers. This project serves as a practical demonstration of core Object-Oriented Programming (OOP) principles.

---

## 🚀 Project Requirements & Features

The application seamlessly executes the following four operations based on structural constraints and test cases:

1. **Student Basic Information:** Captures fundamental data fields (Roll Number, Name, University) using a structured class framework.
2. **Academic Evaluation via Constructors:** Evaluates marks across 5 subjects, automatically calculating the total, average, and percentage using parameterized constructors.
3. **Exception Handling for Zero Marks:** Detects if a student scores `0` across all 5 subjects. When triggered, the software isolates the exception immediately, prevents calculation anomalies, and safely adjusts execution.
4. **Top 5 Ranking Engine:** Uses a sorting algorithm to dynamically order all records and display the Top 5 performing students in the class.

---

## 🛠️ OOP Architecture & Concepts Used

This solution leverages specific advanced pillars of C++ to satisfy all system constraints:

* **Classes & Objects:** Used to encapsulate data fields and behaviors into modular, reusable components (`Student` and `Result`).
* **Inheritance (Single):** The derived class `Result` publicly inherits from the base class `Student`, cleanly separating fundamental personal identity details from academic metrics.
* **Parameterized Constructors & Member Initializer Lists:** Instantiates the base class directly from the derived constructor, ensuring safe data passing and automatic initialization of variables.
* **Inline Functions:** Implicitly embeds minor utility and getter methods (like `getPercentage()`) to reduce function-call overhead and optimize runtime performance.
* **Dynamic Memory Management:** Uses pointers (`Result**`) to allocate an array of objects dynamically based on runtime user input, ending with manual memory cleanup to prevent memory leaks.

---

## 📂 System Class Diagram

The project structure relies on a clean hierarchical relationship between the components:

```text
       ┌────────────────────────┐
       │        Student         │  ◄─── (Base Class)
       ├────────────────────────┤
       │ # rollNo: int          │
       │ # name: string         │
       │ # university: string   │
       ├────────────────────────┤
       │ + displayBasicInfo()   │
       └────────────────────────┘
                   ▲
                   │  (Public Inheritance)
                   │
       ┌────────────────────────┐
       │         Result         │  ◄─── (Derived Class)
       ├────────────────────────┤
       │ - marks[5]: int        │
       │ - total: float         │
       │ - average: float       │
       │ - percentage: float    │
       ├────────────────────────┤
       │ + Result(...)          │
       │ + getPercentage()      │
       │ + displayResult()      │
       └────────────────────────┘

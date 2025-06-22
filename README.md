# 🏥 Patient Record Management System — C++

[![Made with C++](https://img.shields.io/badge/Made%20with-C%2B%2B-blue)](https://en.cppreference.com)
[![Status](https://img.shields.io/badge/Status-Active-brightgreen)]()
[![License](https://img.shields.io/badge/License-MIT-lightgrey)]()

This is a simple **Command-Line Interface (CLI)** project that manages patient records using a **Singly Linked List** in C++. Each record includes a patient’s name, age, and medical condition. You can add, view, search, and delete patients — all dynamically in memory.

---

## 🔗 Features

- ✅ Add new patients (dynamically linked)
- 📋 Display all patient records neatly
- 🔍 Search patients by full name
- ❌ Delete a patient by name (handles head, middle, tail)
- 💡 Count number of current patients
- 🧹 Free up memory on exit

---

## 🧱 Data Structure Used

```cpp
struct Patient {
    std::string name;
    int age;
    std::string condition;
    Patient* next;
};
```

> This structure forms the building block of the **linked list**.

---

## 🖥️ Menu Options

```
1. Add Patient
2. Display All Patients
3. Search Patient by Name
4. Delete Patient by Name
5. Exit
```

---

## 🚀 How It Works

- The program starts with an empty list (`head = nullptr`).
- Each new patient is dynamically allocated with `new`.
- All operations work directly on the linked list using pointers.
- The delete function adjusts pointers correctly to unlink a patient.
- The memory is cleared node-by-node on exit.

---

## 📌 Notes

- The system is **in-memory only** (no files).
- You must search/delete using **exact name matches**.
- Designed to help you practice pointers and linked list operations in C++.

---

## 🎓 What You’ll Learn

- Pointer-to-pointer usage (`Patient** headptr`)
- Traversing linked lists
- Dynamic memory management
- Input/output handling for structured data
- Clean CLI interaction using `std::cin` and `getline()`

---

## 💡 Future Improvements

- 🔄 Edit/update patient records
- 💾 Save/load to file with `fstream`
- 🔢 Sort patients by age or name
- ↔️ Convert to doubly linked list for two-way traversal

---

## 📂 Getting Started

### Prerequisites
- C++ Compiler (g++, clang++, MSVC)
- Terminal or Command Prompt

### Compilation Example
```bash
g++ -o patient_app patient.cpp
./patient_app
```

---

## ⚖️ License

This project is licensed under the **MIT License** — see the [LICENSE](LICENSE) file for details.

---

## 🤝 Contributing

Pull requests are welcome. If you'd like to improve the UI, optimize search, or implement file storage — go for it!

---

## 🙌 Credits

Made with 🔥 by a beast in C++ who understands dynamic memory and handles pointers like a boss.

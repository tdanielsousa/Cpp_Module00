# CPP Module 00

The first module of the 42 C++ series: an introduction to C++ and object-oriented programming.

It covers namespaces, `std::iostream`, classes, member functions, `static` members, initialization lists and the basics of the orthodox canonical form, all compiled with `-Wall -Wextra -Werror -std=c++98`.

> Note: This module is graded with the C++98 standard, so none of the modern features (`auto`, `nullptr`, range-based loops, and so on) are used.
---

<div align="center">
    <br>
    <a href="https://github.com/tdanielsousa/42_School/blob/main/Subjects/cpp00.pdf" target="_blank">
        <img src="https://img.shields.io/badge/View%20Subject-PDF-red?style=for-the-badge&logo=adobe-acrobat-reader&logoColor=white" alt="Subject PDF" height="40">
    </a>
    <p><i>Click on the button above to see the subject's pdf.</i></p>

</div>

---

##  Module Architecture & Concepts

Each exercise lives in its own folder with its own `Makefile`, and builds on the previous one, going from simple string handling to a full class-based program.

### Technical Specifications
* **Language:** C++98.
* **Compiler:** `c++` with `-Wall -Wextra -Werror -std=c++98`.
* **I/O:** `std::cout`, `std::cin` and `std::getline` (no `printf` or `scanf`).
* **Namespaces:** `std::` and the use of `using namespace` restrictions of the subject.
* **Memory:** No dynamic allocation needed, and no leaks.

---

##  Exercises

### ex00: Megaphone
A small program that prints its arguments in uppercase. With no arguments, it prints `* LOUD AND UNBEARABLE FEEDBACK NOISE *`.

* **Concepts:** Basic `iostream` output, `std::string`, character conversion.

### ex01: My Awesome PhoneBook
A tiny interactive phonebook that stores up to **8 contacts**, replacing the oldest one when it is full.

* **`Contact` class:** Holds the first name, last name, nickname, phone number and darkest secret.
* **`PhoneBook` class:** Stores the contacts and handles the commands.
* **Commands:**
   * `ADD`: Prompts for each field and saves a new contact (empty fields are rejected).
   * `SEARCH`: Displays the saved contacts as a 4-column table (index, first name, last name, nickname), each column 10 characters wide, right-aligned and truncated with a `.` when too long. Then asks for an index to show the full contact.
   * `EXIT`: Quits the program, and the contacts are lost.
* **Concepts:** Classes, member functions, encapsulation (`private` / `public`), fixed-size arrays, input handling.

### ex02: The Job Of Your Dreams
Recreates a lost source file for an `Account` class from its header (`Account.hpp`), so that the output matches the provided log file.

* **`Account.cpp`:** Implements deposits, withdrawals, checks and the account status display.
* **Static members:** Track the total number of accounts, total amount, deposits and withdrawals across all instances.
* **Timestamps:** The log lines start with a timestamp, so only the output after the timestamp is expected to match the original log.
* **Concepts:** `static` attributes and methods, initialization lists, constructors and destructors.

---

## Installation & Run Steps

### 1. System Prerequisites
Make sure you have a C++ compiler and `make` installed. On Debian/Ubuntu:

    sudo apt-get install make clang

### 2. Compile an Exercise
Go into the folder of the exercise and run `make`:

    cd ex01
    make

### 3. Run It
Each exercise generates its own executable:

    ./megaphone "shhhhh... I think the students are asleep..."
    ./phonebook
    ./account

---

## Testing

For **ex02** you can use my Python tester, which compares the program output with the expected log while ignoring the timestamps:

* **[tester_ex2.py](https://github.com/tdanielsousa/Cpp_Module00/blob/main/tester_ex2.py)**

Run it from the repository root after compiling ex02:

    python3 tester_ex2.py

Ex00 and ex01 are best checked by hand, following the examples in the subject.

---

## References

* **[C++ reference](https://en.cppreference.com/)**
* **[cplusplus.com tutorial](https://cplusplus.com/doc/tutorial/)**
* **[Learn C++](https://www.learncpp.com/)**

---

## AI Usage Declaration

AI tools were used to assist with:

* **Documentation Support:** Structuring and writing this README file.

---

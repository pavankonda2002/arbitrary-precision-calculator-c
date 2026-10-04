# Arbitrary Precision Calculator in C

## 📌 Project Overview

The **Arbitrary Precision Calculator (APC)** is a C-based calculator designed to perform arithmetic operations on very large numbers that cannot be handled by standard C data types such as `int`, `long`, or `long long`.

The project implements large-number arithmetic using **doubly linked lists**, where each digit of the number is stored as a node.

## 🚀 Features

- Addition of large numbers
- Subtraction of large numbers
- Multiplication of large numbers
- Division of large numbers
- Handles numbers beyond the range of standard integer data types
- Uses dynamic memory allocation
- Uses doubly linked list data structures
- Modular and function-based implementation

## 🧮 Operations

The calculator supports:

| Operation | Symbol |
|-----------|--------|
| Addition | `+` |
| Subtraction | `-` |
| Multiplication | `*` |
| Division | `/` |

## 🛠️ Technologies Used

- **Language:** C
- **Data Structure:** Doubly Linked List
- **Compiler:** GCC
- **Build Tool:** Makefile
- **Environment:** Linux / WSL

## 📂 Project Structure

```text
APC Project (DS)
│
├── addition.c
├── subtraction.c
├── multiplication.c
├── division.c
├── dll_utils.c
├── apc.h
├── main.c
├── makefile
├── .gitignore
└── README.md
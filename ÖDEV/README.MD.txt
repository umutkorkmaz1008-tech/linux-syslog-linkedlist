# Linux Syslog Linked List

## Description
This project demonstrates how Linux system log files (syslog) can be read, stored, and displayed using a **singly linked list** in C programming. The purpose is to understand syslog structure and how linked list data structures can be applied to manage dynamic log entries efficiently.

## Features
- Reads a syslog file (`sample_syslog.txt`) line by line
- Stores each log entry in a **singly linked list**
- Prints all log entries to the console
- Handles file not found errors gracefully

## Linked List Choice
A **singly linked list** was chosen because:
- Syslog entries are read sequentially from top to bottom
- Insertion is always at the end of the list
- Memory allocation is dynamic and efficient for unknown log sizes

## Files
- `main.c` → Contains the C program to read syslog and store in linked list
- `sample_syslog.txt` → Example syslog file with sample entries
- `README.md` → Project description and instructions

## How to Run
1. Make sure `main.c` and `sample_syslog.txt` are in the same directory.
2. Open terminal/Dev-C++ and compile:

```bash
gcc main.c -o syslog
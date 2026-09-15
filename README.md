# Simple Line Editor in C

## Introduction

The Simple Line Editor in C is a command-line text editor developed as part of the Portfolio Building – Studio Course 3rd Semester Coding Competition. A line editor works with text one line at a time through commands entered in the terminal. This project allows the user to create, view, modify, search, count, and save a small text document without using a graphical user interface. The editor stores the document lines in memory and performs operations based on line numbers.

## Objective

The objective of this project is to design and implement a simple working line editor using the C programming language. The project demonstrates basic C programming concepts such as arrays, strings, functions, loops, conditional statements, command processing, and file handling. The project was designed on paper before coding, and the final program was tested through the terminal.

## Data Structure

The project uses a two-dimensional character array to store the lines of the document. The data structure used is `char lines[MAX_LINES][MAX_LEN]`. Each row of the array represents one line of text, while each column stores a character in that line. This approach was selected because it is simple, easy to understand, and suitable for a small text editor. When a line is inserted, existing lines are shifted downward, and when a line is deleted, the lines below it are shifted upward.

## Features Implemented

The editor implements the main line editing operations required for the project. The Insert Line feature adds a new line at a specified line number and shifts existing lines downward. The Delete Line feature removes a selected line and shifts the remaining lines upward. The Display Document feature displays all current lines with their line numbers. The Save feature writes the in-memory document to a text file named `document.txt`. In addition to these features, bonus features have also been implemented. The Search feature searches for a given word and reports the line number where it is found. The Count feature displays the total number of lines and words in the document.

## Commands

The editor provides simple commands that can be entered in the terminal. The `insert <line>` command inserts a new line at the specified position. For example, `insert 1` inserts a new line at line number 1. The `delete <line>` command deletes the specified line, such as `delete 2`. The `display` command displays all lines in the document with their line numbers. The `search <word>` command searches for a word in the document, for example `search Hello`. The `count` command displays the number of lines and words. The `save` command saves the current document into `document.txt`. The `help` command displays all available commands and their usage. The `exit` command closes the line editor.

## Team Members

This project was developed as a team activity. Manjunath N worked on the document storage using a two-dimensional character array and implemented the line insertion and deletion operations. Member 2 worked on displaying the document, searching for words, and counting lines and words. Member 3 worked on saving the document, command processing, newline handling, and the help interface.

## Compilation

To compile the program using GCC, open the terminal in the project directory and run the following command:

`gcc main.c -o line-editor`

The program should compile without errors.

## Running the Program

After successful compilation, run the editor from the terminal using:

`./line-editor`

On Windows, the generated executable can be run using:

`line-editor.exe`

After starting the program, the available commands are displayed and the user can enter commands to operate on the document.

## Example

A simple example of using the editor is to insert two lines using `insert 1` and `insert 2`, and then use the `display` command to view the document. The user can use `search Hello` to search for the word Hello and use `count` to display the number of lines and words. Finally, the `save` command saves the document as `document.txt`.

## Error Handling

The editor performs basic validation to handle invalid operations. It checks whether the document is full before inserting a line and checks whether the entered line number is valid. It also handles operations on an empty document and displays an appropriate message instead of crashing. Invalid commands are also handled by displaying a message asking the user to type `help`.

## Project Files

The main source code is stored in `main.c`. The help documentation is stored in `HELP.md` or `help.txt`, and the project documentation is provided in `README.md`. The saved document is stored as `document.txt` after using the save command.

## Conclusion

The Simple Line Editor in C demonstrates how a small text editor can be designed and implemented using basic C programming concepts. The project provides line insertion, deletion, display, saving, searching, and counting functionality through simple terminal commands. The project also demonstrates teamwork, code organization, testing, documentation, and GitHub-based collaboration.
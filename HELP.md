# M3 Line Editor - Help

## About

M3 Line Editor is a simple command-line text editor written in C.

It stores text lines in memory and allows the user to insert,
delete, display, search, count words, and save the document.

## Commands

### 1. insert <line>

Inserts a new line at the given line number.

Existing lines are shifted down.

**Syntax:**
insert <line>

**Example:**
insert 1
Text: Hello World

### 2. delete <line>

Deletes the line at the given line number.

The lines below it are shifted up.

**Syntax:**
delete <line>

**Example:**
delete 2

### 3. display

Displays all lines in the document with their line numbers.

**Syntax:**
display

**Example:**
display

### 4. search <word>

Searches for a word in the document and displays
the line number where it is found.

**Syntax:**
search <word>

**Example:**
search Hello

### 5. count

Displays the total number of lines and words in the document.

**Syntax:**
count

**Example:**
count

### 6. save

Saves the current document into a text file named
`document.txt`.

**Syntax:**
save

**Example:**
save

### 7. help

Displays the list of available commands.

**Syntax:**
help

**Example:**
help

### 8. exit

Exits the Line Editor program.

**Syntax:**
exit

**Example:**
exit

## Example Session

```text
> insert 1
Text: Hello World
Line inserted successfully.

> insert 2
Text: C Programming
Line inserted successfully.

> display

----- DOCUMENT -----
1. Hello World
2. C Programming
--------------------

> search Hello
Found "Hello" at line 1

> count
Lines: 2
Words: 4

> save
Document saved as document.txt

> exit
Goodbye!
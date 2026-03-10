# MP3 Tag Reader and Editor (C)

## Overview

This project is a command-line based MP3 Tag Reader and Editor implemented in the C programming language. The main purpose of this project is to understand how metadata is stored inside MP3 files and how it can be accessed using low-level file handling techniques.

MP3 files store information such as song title, artist name, album name, year, genre, and composer using a tagging format called ID3v2.3. This project reads those tags directly from the binary structure of an MP3 file and displays them in a readable format. It also demonstrates how these tags can be updated through command-line arguments.

The program is written in a modular way, separating responsibilities across different source files for better readability and maintainability.

---

## Objectives

* To understand the internal structure of MP3 metadata.
* To implement file handling using the C programming language.
* To read ID3v2.3 frames from an MP3 file.
* To display important metadata fields such as title, artist, album, year, genre, and composer.
* To simulate editing of MP3 metadata using command-line arguments.
* To practice modular programming using multiple source files.

---

## Features

* Reads metadata directly from MP3 files using ID3v2.3 frames.
* Displays common tags including:

  * Title (TIT2)
  * Artist (TPE1)
  * Album (TALB)
  * Year (TYER)
  * Genre (TCON)
  * Composer (TCOM)
* Handles missing metadata by displaying "Not Present".
* Supports command-line arguments for editing tags.
* Provides help and version information commands.
* Uses modular program design with separate source and header files.
* Safe editing approach using simulated updates and backup notification.

---

## Technologies Used

* Programming Language: C
* Compiler: GCC
* Development Environment: Visual Studio Code
* Operating System: Linux / Ubuntu

Standard libraries used:

* `stdio.h`
* `stdlib.h`
* `string.h`

---

## Project Structure

```
MP3_Tag_Reader
│
├── main.c
├── view.c
├── view.h
├── edit.c
├── edit.h
│
├── samplefiles
│   └── sample.mp3
│
└── README.md
```

### File Description

**main.c**

Handles command-line arguments and decides whether the program should read tags or simulate editing.

**view.c / view.h**

Responsible for opening the MP3 file, reading the ID3v2.3 header, identifying frames, and displaying tag information.

**edit.c / edit.h**

Handles simulated editing operations and shows which tags would be updated.

**samplefiles/sample.mp3**

Test MP3 file used to demonstrate the program.

---

## ID3v2.3 Tag Frames Used

The program reads the following metadata frames:

| Frame ID | Description |
| -------- | ----------- |
| TIT2     | Title       |
| TPE1     | Artist      |
| TALB     | Album       |
| TYER     | Year        |
| TCON     | Genre       |
| TCOM     | Composer    |

Each frame consists of:

* Frame ID (4 bytes)
* Frame Size (4 bytes)
* Flags (2 bytes)
* Frame Data (text information)

---

## Compilation

To compile the program, run the following command in the terminal:

```
gcc main.c view.c edit.c -o mp3tag
```

This will create an executable file named `mp3tag`.

---

## Running the Program

### View MP3 Metadata

```
./mp3tag samplefiles/sample.mp3
```

Example Output:

```
----- ID3v2.3 TAG INFO -----
TIT2 : Shape of You
TPE1 : Ed Sheeran
TALB : Divide
TYER : 2017
TCON : Pop
TCOM : Not Present
----------------------------
```

---

### Edit Title Tag

```
./mp3tag -t "Perfect" samplefiles/sample.mp3
```

Example Output:

```
Opening samplefiles/sample.mp3 to update ID3v2.3 tags...
Creating backup before edit...
Tags to update:
  TIT2 (Title) -> Perfect
Changes applied (simulation complete).
```

---

### Show Help

```
./mp3tag -h
```

Displays usage instructions and supported options.

---

### Show Version

```
./mp3tag -v
```

Displays the program version.

---

## Key Concepts Implemented

* Binary file handling in C
* MP3 metadata structure
* ID3v2.3 frame parsing
* Command-line argument processing
* Modular programming
* File pointer operations (`fopen`, `fread`, `fseek`, `fclose`)

---

## Learning Outcomes

Through this project I gained practical experience with:

* Low-level file handling in C
* Understanding multimedia file structures
* Working with binary data
* Parsing structured metadata
* Designing modular programs

This project also helped strengthen my debugging and problem-solving skills when dealing with non-text file formats.

---

## Future Scope

There are several possible improvements that could be implemented in future versions:

* Support for ID3v2.4 tags
* Actual in-place modification of metadata frames
* Support for additional metadata such as lyrics or album artwork
* Graphical user interface (GUI) for easier interaction
* Batch editing for multiple MP3 files

---

## Conclusion

This project demonstrates how metadata stored inside MP3 files can be accessed and interpreted using the C programming language. By analyzing the structure of ID3v2.3 frames and reading them through binary file operations, the program is able to display important information about an audio file. Working on this project provided valuable insight into file structures and improved my understanding of system level programming concepts.

---

## Author

Jayesh Jagtap

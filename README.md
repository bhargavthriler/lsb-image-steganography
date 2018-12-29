# lsb-image-steganography
===========

A simple steganography application based on LSB Image Steganography

## Getting Started

Pull the repository. Delete the shared library file (.so) and executable file (.out or .exe). First execute 'make' command in /Functions directory and then execute 'make' command in /Main directory. An executable  file (.out or .exe) and a shared object (.so) will be generated in /Main and /Functions directory respectively. Execute the .out(.exe) file from /Main to run the application

### Prerequisites

OS       - Linux (might work on Windows with Linux subshell)
Compiler - gcc (preferred)

### Installing

Nothing to install just ensure that you have gcc compiler (haven't tried other compilers)

### Using the application

**Execution**
```
./main.out <-e or -d> <source bmp image> <secret text file> <new bmp image>
```

```
```

## Built With

* vim - text editor
* OS  - ubuntu 18.04

## Author

* **Bhargav Das**

## Acknowledments

* Emertxe Information Technologies Pvt Ltd - for providing idea of this project

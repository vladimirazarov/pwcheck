# pwcheck

A simple command-line utility written in C to check if passwords meet specified security rules.

## Description

This program reads passwords from standard input, one per line, and checks them against a set of rules defined by a security level and a parameter provided as command-line arguments. Passwords that meet the criteria are printed to standard output. Optionally, it can also print statistics about all processed passwords.

## Build Instructions

To compile the project, ensure you have `gcc` installed and run the following command in the project root directory:

```bash
make
```

This will create an executable named `pwcheck`.

To remove the compiled executable and any intermediate object files, run:

```bash
make clean
```

## Usage

The program is run from the command line as follows:

```bash
./pwcheck LEVEL PARAM [--stats] < passwords.txt
```

**Arguments:**

*   `LEVEL`: An integer between 1 and 4 (inclusive) specifying the security level. Higher levels enforce stricter rules.
    *   Level 1: Password must contain at least one uppercase and one lowercase letter.
    *   Level 2: Password must contain characters from at least `PARAM` character groups (lowercase, uppercase, digits, special symbols). Rules from Level 1 must also be met.
    *   Level 3: Password must not contain a sequence of the same character repeated `PARAM` or more times. Rules from Levels 1 & 2 must also be met.
    *   Level 4: Password must not contain two identical substrings of length `PARAM` or more. Rules from Levels 1, 2 & 3 must also be met.
*   `PARAM`: A positive integer used as a parameter for rules defined in Levels 2, 3, and 4.
*   `--stats` (Optional): If provided as the third argument, the program will print statistics (number of unique characters, minimum length, average length) about all processed passwords (including those that failed the checks) to standard output after printing the valid passwords.

**Input:**

The program reads passwords from standard input. Each password should be on a new line and contain only ASCII characters (up to 100 characters long).

## Example

Given a file named `passwords.txt` with the following content:

```
1234567890
Password
Heslo123
Mojevelmidlouhehesloscislem0
IZP2021:fit@vut.cz
```

To check these passwords against Level 2 rules with a parameter of 3, and also display statistics:

```bash
./pwcheck 2 3 --stats < passwords.txt
```

**Expected Output:**

```
Heslo123
Mojevelmidlouhehesloscislem0
IZP2021:fit@vut.cz
Statistika:
Ruznych znaku: 36
Minimalni delka: 8
Prumerna delka: 14.4
```

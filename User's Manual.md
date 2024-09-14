## What does this program do?
This program extracts names from "names.txt" and creates randomly generated passwords which then puts them into a new file named "rawdata.txt". 
Then, it reads names and passwords in the "rawdata.txt", encrypts those passwords specifically for those user, then creates and writes those users and encrypted password into "encrypteddata".
Then, the program automatically stores those passwords into a hashtable where it can provide those encrypted passwords with the corresponding usernames.

## What is database.hpp files?
These files handles data transfer, encryption, hashing data, and storing.

## What does the hashtable.hpp files do?
It takes data, hashes the data, giving it a key for faster search complexity. It also stores said data.

## What does the password-encrypteion.hpp do?
It takes in passwords from "rawdata.txt" and encrypts passwords using a Secret Cipher.

## What are the command prompts to run this program?
Creates Executable files
```bash
make
```

Creates and executes main.cpp
```bash
make runmain
```

Creates and executes /test/test.cpp for personal testing purposes
```bash
make runtest
```

Clean directory
```bash
make clean
```

## Thank you.
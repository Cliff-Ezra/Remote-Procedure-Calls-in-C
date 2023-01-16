# Use RPCGen to create a client and server process that communicate using Remote Procedure Calls

## Challenge

Using RPCGen tool for C and C++, create client and server processes that communicate using Remote Procedure Calls. Create three remote procedures that perform anything you wish. But those procedures must accept and return parameters as follows:

- Procedure 1, accepts an integer and returns an integer 
- Procedure 2, accepts an integer and string and returns a floating point
- Procedure 3, accepts an integer and returns a string

## Solution

### Installation

- First install rpcbind (sudo apt-get install rpcbind)
- Then run rpcinfo (This shows whether the rpcbind is running or not)
- Create the .x file and create a structure defining the different arguments

### Creating the .x file (Define the RPC program)

- Create a file with .x extension
- Specify the name of the program
- Specify the version number
- Define the program structure (The 3 procedures)

### Generate C code for the RPC program

- Run the command: rpcgen -a -C add.x
- The '-a' flag generates the client and server code
- The '-C' flag generates the code in C
- The 'add.x' is the name of the .x file (input file)
- The output files will be named based on the input file name, for example "add_clnt.c" and "add_svc.c" for the client and server side code, respectively.

### Running the make file to compile the code

- Run the command: make
- The make command will compile the code and create the executables
- The Makefile contains instructions for the compiler on how to build the program

# Minitalk

## Description
**Minitalk** is a project where I built a small data exchange program using UNIX signals. The project involves creating a client and server that communicate with each other exclusively through signals, making it a unique and challenging exploration of process communication.

In this project, I learned how to handle UNIX signals like `SIGUSR1` and `SIGUSR2`, and I applied concepts related to signal handling, process IDs, and efficient data transmission.

## Features
- A server that prints its process ID (PID) upon launch.
- A client that sends a string to the server using the server’s PID.
- The server receives and prints the string sent by the client.
- Supports continuous communication between the client and server, allowing multiple clients to send messages in a row without restarting the server.
- Communication is done exclusively through the UNIX signals `SIGUSR1` and `SIGUSR2`.

### Example Usage
1. Start the server:
   ```bash
   ./server
   ```
   This will display the server's PID, which will be used by the client.

2. Send a message from the client to the server:
   ```bash
   ./client <server-pid> "Your message here"
   ```

   The server will print the received message.

## Bonus Features
I also implemented the following bonuses:
- The server acknowledges each message by sending a signal back to the client.
- Unicode character support for more complex messages.

## Installation
1. Clone my repository:
   ```bash
   git clone git@github.com:Rui-Pedro-Pires/Minitalk.git
   ```
2. Navigate to the project directory:
   ```bash
   cd Minitalk
   ```
3. Compile the project with the provided `Makefile`:
   ```bash
   make
   ```

## Requirements
- C programming language.
- Basic understanding of UNIX signals.

## External Functions
The project uses the following external functions:
- `write`, `signal`, `sigaction`, `kill`, `getpid`, `malloc`, `free`, `pause`, `usleep`, `exit`.

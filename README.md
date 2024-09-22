# Minitalk

## Project Overview

The **Minitalk** project is a simple communication program that allows data exchange between a client and a server using **UNIX signals**. The client sends a string to the server, and the server receives and displays the string. This project helped me explore low-level system functions such as signal handling in UNIX, particularly using `SIGUSR1` and `SIGUSR2`.

## How It Works

- The **server** starts first and prints its **Process ID (PID)**.
- The **client** takes the server's PID and a string as arguments, then sends the string to the server.
- The communication is done using only UNIX signals (`SIGUSR1` and `SIGUSR2`).
- The server receives the signals, reconstructs the string, and prints it.

### Features:
- The server can handle multiple clients sequentially without needing to restart.
- Strings are sent one character at a time via signals, and the server displays the string almost instantly.

## Files

- **client.c**: Code for the client that sends the string to the server.
- **server.c**: Code for the server that receives and prints the string.
- **Makefile**: Compiles the client and server programs.

## Mandatory Part

- The client sends the string to the server using UNIX signals.
- The server receives and displays the string without delays.
- The server handles multiple client messages without restarting.
- Only `SIGUSR1` and `SIGUSR2` are used for communication.

### Functions Allowed:
- `write`, `ft_printf`, `signal`, `sigaction`, `kill`, `getpid`, `malloc`, `free`, `pause`, `usleep`, `exit`.

## Bonus Features
- The server sends a signal back to the client to **acknowledge** receipt of the message.
- **Unicode character support** for sending and receiving non-ASCII characters.

## Compilation

To compile the project, run:
```bash
make
```

This will generate two executables: `client` and `server`.

## How to Run

1. **Start the server**:
   ```bash
   ./server
   ```
   The server will print its PID (e.g., `PID: 12345`).

2. **Run the client** with the server’s PID and a string to send:
   ```bash
   ./client 12345 "Hello, world!"
   ```

3. The server will display the received message:
   ```
   Hello, world!
   ```

## Conclusion

This project was a deep dive into signal handling in UNIX. The challenge was to manage the communication using only two signals while ensuring correct string transmission and fast response times.

--- 

This README is streamlined for clarity while still documenting your project and its main components effectively.
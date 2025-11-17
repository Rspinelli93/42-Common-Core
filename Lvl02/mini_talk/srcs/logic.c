/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rspinell <rspinellir13@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:22:02 by rspinell          #+#    #+#             */
/*   Updated: 2025/11/17 14:33:20 by rspinell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
! TESTER
https://github.com/ThibaudM13/minitalk-Tester

! MINI TALK EXPLANATION 

- SERVER SIDE  

$ Step 1 — Server: Setup and Signal Handling  

* Server starts first and prints its PID. The client needs this PID to 
*   send signals.  
* Sets up handlers for SIGUSR1 and SIGUSR2. When a signal arrives, 
*   the OS pauses normal execution and calls the handler.  
* Handler must be fast and simple. It only stores the bit, updates the current 
*   character buffer, and resets counters after 8 bits.  
* Common mistakes: not printing PID, handler too slow, client sending signals 
*   too early, or mismatched signal meaning.  
* The handler can read the client PID for acknowledgments.  

- CLIENT SIDE  

$ Step 2 — Client: Sending a Message Bit by Bit  

* Needs server PID, the message, and agreement on signals 
*   (SIGUSR1 = 0, SIGUSR2 = 1).  
* Converts each character into binary (8 bits).  
* Sends each bit as a signal to the server, waiting briefly or 
*   for acknowledgment before the next bit.  
* Sends null byte (‘\0’) at the end to indicate message completion.  

- SERVER SIDE RECEIVING  

$ Step 3 — Server: Receiving and Rebuilding  

* Each signal wakes the server and calls the handler, which stores the bit.  
* After 8 bits, a byte is formed, converted to ASCII, 
*   printed, and counters reset.  
* Static variables keep track of the current byte and
*   bit position between signals.  
* Receiving a null byte indicates the message has ended.  
* Optionally, server can send acknowledgment after each bit or character.  

$ Step 4 — How Bits Become Characters  

* Each bit has a weight in a byte: 7=128, 6=64, 5=32, 4=16, 3=8, 2=4, 1=2, 0=1.  
* Server sums the weights for all 8 bits to get the ASCII code.  
* After printing, counters reset and server waits for the next byte.  

- END OF MESSAGE  

$ Step 5 — Detecting the End  

* Client sends null byte (‘\0’) after the last character.  
* Server rebuilds the byte and recognizes it as the end.  
* Server prints a newline or message and resets for the next communication.  
* Optionally sends acknowledgment to let client exit safely.  

- ACKNOWLEDGMENTS  

$ Step 6 — Client ↔ Server Handshake  

* Without synchronization, signals can be lost.  
* Handshake: client sends a bit → server processes and sends ACK → client waits 
*   for ACK before sending the next bit.  
* Ensures reliability and keeps processes synchronized.  

- CLEANUP AND RESET  

$ Step 7 — After the Message Ends  

* Server: null byte received → prints newline, resets state,
*   and waits for next client.  
* Client: waits for final acknowledgment (if used) and exits; without ACK, 
*   it exits after sending null byte.  
* Cleanup prevents leftover data, hangs, or missed signals.  

- OVERALL FLOW  

* Start server → print PID.  
* Start client → provide PID and message.  
* Client converts message to bits and sends signals.  
* Server receives, rebuilds characters, prints text.  
* Client sends null terminator → server detects end.  
* Optional acknowledgments keep communication reliable.  
* Both sides reset and are ready for the next message.  

MiniTalk demonstrates process communication using UNIX signals — low-level,
bit-by-bit message transfer with synchronization and acknowledgment.
*/

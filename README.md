# Lab 04: Embedded Communications and the USART

Authors : Kyle G. Gayliyev <br>
Date: 21-February-2024<br>
Course: ECE 6780 - Embedded System Design, ECE Department, The University of Utah<br>
GitHub IDs: ggayliye <br>
Repo: https://github.com/ggayliye/Lab4_ECE6780EmbeddedSys_SR24 <br>
Date: By 1-March-2024 (Time of when submission is due/will be ready to be evaluated)<br>
Copyright: ECE 6780, Kyle G. Gayliyev - This work may not be copied for use in Academic Coursework.

## Overview of the Lab 04

Lab 4 is consisted of 3 Parts:<br>

* Part 1: Preparing to use the USART.
* Part 2: Blocking Reception.
* Part 3: Interrupt-Based Reception.



### Part 1: Preparing to use the USART
Instructions:<br>

The STM32F072 has four USART peripherals available; you will need to select one of these to use. 
We suggest using USART3, which has had the best success for students: the connections for USART1 
and USART2 use pins that are unavailable on this board (see Discovery Board Manual Section 4.14 
for Extension connectors to view these pins). Each USART has a small selection of GPIO pins that 
can be used as its transmit (TX) and receive (RX) signals. Because the split connections on the 
end of the Adafruit USB-USART cable are fairly short, you will want to choose USART output/input 
pins that are relatively near a GND pin.<br>

1. Using the chip datasheet, locate pins that connect to TX/RX signals on USART peripherals.
2. Choose a set of RX/TX pins that are near enough to a GND connection such that the USBUSART
cable’s wire ends can reach.
3. Connect the USB-UART transmit (TX) line to the STM32F0’s receive (RX) pin. Likewise,
connect the STM32F0’s transmit (TX) pin to the USB-UART receive (RX) line.
4. Set the selected pins into alternate function mode and program the correct alternate function
number into the GPIO AFR registers.
5. Note the USART that the selected pins connect to, this is the peripheral you will be using in
the lab exercises.

### Part 2: Blocking Reception.
Instructions:<br>

For this exercise you will use the infinite while loop in the main function to read single-character
commands typed at the serial terminal on the PC. Your goal is to develop an application that toggles
the correct LED whenever the character matching the first letter of the color is pressed. For example, 
typing an ‘r’ into the terminal would toggle the red LED.<br>

1. Check and wait on the USART status flag that indicates the receive (read) register is not empty.
* You can use an empty while loop which exits once the flag is set or simply check each
iteration of the main infinite loop.
* It may be helpful to carefully read the bit descriptions in the register map.
2. Test the received data and toggle the appropriate LED
* The receive register can be read like an ordinary variable. However, the data isn’t
		guaranteed to remain in the register after it has been read once.
* Unless you use a switch statement you may want to save the value into a local variable
		and test against that.
3. Whenever a key is pressed that doesn’t match an LED color, print an error message to the
console.
4. You will probably want to comment or remove any old transmit code and delay statements
from the infinite loop.
* The possible reception rate at 115200 Baud is faster than the minimum delay the HAL
library functions are designed to provide.
* It is possible to lose received data while waiting for a blocking transmit to complete.
Where we are only receiving single bytes it is unlikely to cause problems.

### Part 3: Interrupt-Based Reception.
Instructions:<br>
1. Your command parser must now accept two character commands.
* The first character is a letter matching the one of the LED colors.
* The second character is a number between 0 and 2.
		<pre>	   – ‘0’ turns off the LED </pre>
		<pre>		– ‘1’ turns on the LED  </pre>
		<pre>		– ‘2’ toggles the LED   </pre>
2. Print a command prompt such as “CMD?” when waiting for user input.
3. Entering an unknown character prints an error message and restarts back to the beginning.
4. On a successful command, print a message about which command was recognized.


<pre><ins>Future extensions</ins> :  There will be no future additions to this project. </pre>

# Partnership

We're partnered in the lab with students of two, but each student is required to complete
their work individually.

<ins> Progress Notes: </ins> <br>

<ins>1st Week Notes:</ins> <br>

On Wed, 21st of February-2024, these tasks are completed:
- Created the "Lab4_ECE6780EmbeddedSys_SR24" GitHub repo.
- Created the "lab04" project using STM32CubeMX Software


## Testing
No Unit Test files are created as the nature of the project. Manual testing 
are performed in each step to ensure code improvements. Check "Testing Instructions"
section below.

# Time Expenditures:
<pre>Lab04: Predicted Hours: 12h		Actual Hours:	h		 </pre>

The actual hours recorded on top reflect the time spent for the assignment including the time 
spent in labs. It excludes time spent reading and understanding the lab assignment instructions 
at the beginning of the lab (pre-lab work).

# Comments to Evaluators:

Compared to the other labs, I am uploading
the full project files in this repo. Therfore,
you may not need some of the information below to
prepaire this project to run. However, I'm still
including those parts below.


<em>To able to fully test the main.c, other files and tools are required.<br>
For example, I created the project using the STM32CubeMX software first. Then <br>
clicked "Code Generation" button from the top menu after adjusting necessary <br>
settings. The instructions on how to adjust the settings will be given below. Then, <br>
the software automatically opens the Keil uVision5 softwhere where we code main.c.<br>
The main.c will be located under the "Application/User/Core" folder on the left menu of 
the Keil uVision5 softwhere.</em><br>

The main.c includes the 1st and 2nd part of the assignment. One of the assignments<br>
must be commented out. To test the commented out part, you'll need to uncomment that <br>
section and comment out the already uncommented section. Follow the comments<br>
out the sections in the main.c file.

## Testing Instructions:
After reading the discussion above, let's adjust the settings of
STM32CubeMX and Keil uVision5 softwares. <br><br>
STM32CubeMX:<br>

Select STM32F0 in the Series filter.<br>
* Select STM32F0x2 in the Lines filter
* Select LQFP64 in the Package filter <br>
At this point, there should only be a few choices available, select STM32F072RBTx and press the OK
button.<br>
Come to Project ->Menu->Settings.<br>
Name the new project. Select a directory where STMCube can create subfolders to store project files.<br>
Change the Toolchain/IDE dropdown menu to MDK-ARM V5.<br>
On the Project tab, move to the Code Generator tab at the top of the window.<br>
STMCube may take a while to copy the files to the directory specified in the settings. Afterward,
you may be asked if you want to open the project folder or project file itself. Click "project file".<br>
Now you should be in the "Keil uVision5" program as it's opened automatically.<br><br>

Keil uVision5:<br>

Click "Flash" -> "Configure flash tools" from the top menu.<br>
Click "Target" from the top menu. Find "Arm complier" menu and select 
"use default compiler version..".


One the setting is done, replace the main.c file in the "Application/User/Core" folder <br>
with my main.c file you downloaded.<br>
From the top menu, "Project"->"Build Target".<br>
Plug in your STM32F072 Discovery Microcontroller to your computer. <br>
Click "Flash" -> "Download" from the top menu. Test it on your STM32F072 Discovery Microcontroller.

Thank you for evaluating this project and providing feedback. <br>

Have a wonderful day!

# Consulted Peers:
N/A

# Caution/Warnings

* "Ensure that both the Discovery board and USB-UART cable are unpowered when connecting
them to each other. If one device is connected to the PC and the other is not, the transmit line on
the powered device will feed voltage into the unpowered device through its input pin."


# Examples of Good Software Practice (GSP)
<pre><ins>DRY</ins> :</pre>
DRY is an abbreviation of "Don't repeat yourself". It's a principle of Software Engineering that
has the goal of reducing repetition and redundancy in the coding. Using abstractions and normalization
are advised over redundancy <a href="https://en.wikipedia.org/wiki/Don%27t_repeat_yourself">[2]</a>.

<pre><ins>Separation of Concerns</ins> :</pre>
This concept is similar to the "divide and conquer" principle where you divide
a big software project into small projects to complete. A software design technique that focuses on separating 
and freeing functionalities of a program is called Modular programming. Making each of the divided small 
projects independent and addressing a separate concern, it'll make it easy to reduce, detect 
and fix the errors. <a href="https://en.wikipedia.org/wiki/Separation_of_concerns">[3]</a>

<pre><ins>Good Code Typing Practices</ins> :</pre>
Good coding practices can be listed as: Naming variables with a relevant name, commenting 
in between code lines with a brief explanation if the code is not self-explanatory, creating 
helper methods that can be used multiple times and by other sections.


<pre><ins>Testing Strategies</ins> :</pre>
Unit Testing can be summarized in 3 types of techniques:<br>

1. <ins>Black Box Testing : </ins> In this testing, input, user interface, and output parts are covered.
2. <ins>White Box Testing : </ins> In this testing, functionality, design structure, and code models are covered.
3. <ins>Gray Box Testing : </ins> In this testing, analysis of code performance, relevant test cases,
methods, and functions are covered.<a href="https://www.geeksforgeeks.org/unit-testing-software-testing/">[4]</a>


# References:
1. Canvas Page Class Materials.(For example, lecture slides, additional resources and pdf files). <br>
2. https://en.wikipedia.org/wiki/Don%27t_repeat_yourself<br>
3. https://en.wikipedia.org/wiki/Separation_of_concerns<br>
4. https://www.geeksforgeeks.org/unit-testing-software-testing/<br>







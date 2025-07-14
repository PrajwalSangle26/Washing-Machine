# Washing Machine Project

This project simulates the functioning of a basic washing machine using embedded C in MPLAB X IDE (v6.25). The system uses a digital keypad for user input and manages multiple washing states like washing, rinsing, and spinning through timers and interrupts.

## 🛠️ Tools Used

- **MPLAB X IDE v6.25**
- **XC8 Compiler**
- **PIC Microcontroller (target-dependent)**
- **PicsimLab (optional for simulation)**

---

## 📷 Pojects Screenshot
![Power on](https://raw.githubusercontent.com/PrajwalSangle26/Washing-Machine/main/assets/Pic1.png) ![Cloth Types](https://raw.githubusercontent.com/PrajwalSangle26/Washing-Machine/main/assets/Pic3.png) ![Start-Stop](https://raw.githubusercontent.com/PrajwalSangle26/Washing-Machine/main/assets/Pic6.png) ![Finish](https://raw.githubusercontent.com/PrajwalSangle26/Washing-Machine/main/assets/Pic7.png)

## 📁 Project Structure

You said:


these are the project files of a washing machine project which I made on MPLab. Give a README/ .md file for this

ChatGPT said:
Here's a sample README.md file for your Washing Machine Project created using MPLAB X IDE. It includes project overview, structure, and build instructions.

markdown
Copy
Edit
# Washing Machine Project

This project simulates the functioning of a basic washing machine using embedded C in MPLAB X IDE (v6.25). The system uses a digital keypad for user input and manages multiple washing states like washing, rinsing, and spinning through timers and interrupts.

## 🛠️ Tools Used

- **MPLAB X IDE v6.25**
- **XC8 Compiler**
- **PIC Microcontroller (target-dependent)**
- **PicsimLab (optional for simulation)**

---

## 📁 Project Structure

Washing_machine/ \
├── build/ \
├── dist/ \
├── nbproject/ \
├── Makefile \
├── README.md \
├── dcd.c \
├── dcd.h \
├── digital_keypad.c \
├── isr.c \
├── main.c \
├── main.h \
├── timers.c \
├── timers.h \
├── washing_machine_function_def.c \
├── washing_machine_header.h 


### 📄 Key Source Files

| File Name                         | Description |
|----------------------------------|-------------|
| `main.c`                         | Entry point of the program |
| `digital_keypad.c`               | Handles keypad inputs |
| `timers.c` / `timers.h`          | Timer configurations and handlers |
| `isr.c`                          | Interrupt Service Routines |
| `washing_machine_function_def.c` | Main logic for wash cycle execution |
| `dcd.c` / `dcd.h`                | Display control driver |
| `washing_machine_header.h`       | Header for common definitions |

---

## ⚙️ Features

- Digital keypad interface for user input
- Timed washing, rinsing, and spinning stages
- Interrupt-based control for real-time operations
- Modular code for easy debugging and extension

---

## 🧪 How to Build and Run

1. Open `Washing_machine` project in **MPLAB X IDE**
2. Ensure the proper microcontroller and XC8 compiler are selected.
3. Build the project using the **hammer** icon or `Ctrl + F11`
4. Load the hex file to PicsimLab or burn it to the microcontroller.

---

## 📝 Author

Prajwal Sangle  
B.E. Student | SSGMCE, Shegaon

---

## 📌 Notes

- Make sure to configure oscillator and fuse settings in MPLAB properly.
- Use PicsimLab to simulate the washing machine for verification before hardware implementation.


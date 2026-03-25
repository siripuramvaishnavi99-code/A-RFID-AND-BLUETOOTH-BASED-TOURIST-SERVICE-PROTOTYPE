# RFID Bluetooth Tourist Service System

## 📌 Overview

This project is an **RFID-based access control system** integrated with **Bluetooth communication** and an **LCD display** using Arduino. It is designed for applications like tourist services, entry validation systems, or smart ticketing.

The system reads RFID card data via serial communication and validates it against predefined IDs. Based on the result, it provides visual and audio feedback using LEDs and a buzzer.

---

## ⚙️ Features

* 📡 RFID card detection via Serial input
* 📲 Bluetooth communication support
* 📺 16x2 LCD display output
* ✅ Valid / ❌ Invalid card detection
* 🔴🟢 LED indication
* 🔊 Buzzer alert for invalid access
* 🔄 Real-time data processing

---

## 🧰 Hardware Requirements

* Arduino Uno (or compatible board)
* RFID Reader Module
* Bluetooth Module (e.g., HC-05)
* 16x2 LCD Display
* LEDs (Red & Green)
* Buzzer
* Resistors & connecting wires
* Power supply

---

## 🔌 Pin Configuration

| Component | Arduino Pin |
| --------- | ----------- |
| LCD RS    | 6           |
| LCD EN    | 7           |
| LCD D4–D7 | 5, 4, 3, 2  |
| Red LED   | 8           |
| Green LED | 9           |
| Buzzer    | 13          |

---

## 🚀 How It Works

1. The system waits for RFID card input via Serial.
2. Each RFID tag sends a **12-character unique ID**.
3. The system compares the received ID with predefined values:

   * `"55007FB5D24D"` → ✅ Valid Entry
   * `"55007B49C6A1"` → ❌ Invalid Entry
4. Based on validation:

   * LCD displays the result
   * LEDs indicate status
   * Buzzer activates for invalid entry

---

## 💻 Software Requirements

* Arduino IDE
* LiquidCrystal Library (included by default)

---

## 📂 Code Structure

* `setup()` → Initializes LCD, Serial, and pins
* `loop()` → Continuously checks for RFID input
* `serialEvent()` → Handles incoming serial data
* `beep()` → Controls buzzer alert
* Utility functions:

  * `convertl()` → Display numeric data on LCD
  * `converts()` → Send numeric data via Serial

---

## 🔧 Customization

* Add more RFID tags:

```cpp
if(inputString == "YOUR_RFID_TAG")
{
  lcd.print("Valid Entry");
}
```

* Change delay, buzzer timing, or LED behavior as needed.

---

## ⚠️ Notes

* Ensure RFID reader sends **exactly 12 characters** per scan.
* Serial baud rate is set to **9600**.
* Avoid using `Serial.flush()` unnecessarily (can be optimized).

---

## 📸 Future Improvements

* Database integration for dynamic RFID validation
* Mobile app interface via Bluetooth
* Logging system for entry records
* IoT/cloud integration

---

## 👨‍💻 Author

Developed as an embedded systems project using Arduino.

---

## 📜 License

This project is open-source and free to use for educational and personal purposes.

---


# GPS Logger with TinyGPS++ and SoftwareSerial

This Arduino sketch reads GPS data from a NEO-M8N GPS module using the `TinyGPSPlus` and `SoftwareSerial` libraries. It logs location, altitude, speed, satellite count, and UTC date/time to the Serial Monitor.

## 📦 Requirements

* **Arduino Board** (e.g., Uno, Nano)
* **NEO-M8N GPS Module**
* **Libraries:**

  * [TinyGPSPlus]
  * `SoftwareSerial` (included with Arduino IDE)

## 🛠️ Wiring

| GPS Module Pin | Arduino Pin |
| -------------- | ----------- |
| TX             | D4          |
| RX             | D3          |
| VCC            | 5V          |
| GND            | GND         |

> ⚠️ Note: Connect **GPS TX to Arduino RX (D4)** and **GPS RX to Arduino TX (D3)** via `SoftwareSerial`.


## 📄 License

This project is open-source and provided as-is, with no warranties.

---

Let me know if you'd like to include images, schematics, or turn this into a GitHub-friendly format with sections like badges or setup instructions!

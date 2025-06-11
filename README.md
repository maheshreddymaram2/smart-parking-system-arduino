# Smart Parking System using Arduino

This project demonstrates a **Smart Parking System** using Arduino Uno and ultrasonic sensors. It simulates a parking area with three slots and includes gate control, LED indicators, and an LCD display for user-friendly parking status updates.

## 🚗 Features

- Detects vehicle presence using **3 ultrasonic sensors**.
- Controls **entry and exit gates** using **2 servo motors**.
- Displays slot status (`Full` / `Empty`) on **I2C 16x2 LCD**.
- LED indicators:
  - 🔴 Red = Slot occupied
  - 🟢 Green = Slot available
- LCD scrolling messages for vehicle readiness.

---

## 🛠️ Components Used

| Component             | Quantity |
|-----------------------|----------|
| Arduino Uno R3        | 1        |
| Ultrasonic Sensor (HC-SR04) | 3        |
| Green LEDs            | 3        |
| Red LEDs              | 3        |
| Resistors (220Ω)      | 6        |
| Breadboard (Small)    | 1        |
| Servo Motor           | 2        |
| I2C LCD Display       | 1        |
| Power Supply          | 1        |

---

## 🔌 How It Works

1. Each **slot has an ultrasonic sensor** to detect if a car is parked.
2. If distance > 10cm, slot is **Empty**:
   - Green LED ON
   - Entry gate opens
   - LCD: `Slot X Empty`, `Car X coming`
3. If distance ≤ 10cm, slot is **Full**:
   - Red LED ON
   - Exit gate opens
   - LCD: `Slot X Full`, `Car X Ready to Leave` (scrolls message)

---

## 📸 Screenshots

You can find simulation visuals inside the `screenshots/` folder:
- `components.png`: Circuit layout in Tinkercad
- `lcd_startup.png`: "Smart Parking" message at power on
- `slot_full.png`: Car parked view
- `slot_empty.png`: Empty slot with green LED

---

## 📁 Code

The Arduino sketch is in:  
[`smart_parking_system.ino`](./smart_parking_system.ino)

```cpp
// Sample function
long getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

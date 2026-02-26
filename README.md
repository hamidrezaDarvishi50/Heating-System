# Multi-Room Heating Control System (Embedded Systems Project)

This project was developed for the **Embedded Systems** course.
It models and controls the temperature of a four-room environment using a dynamic system, thermostat controller, and safety gateway architecture.

The system is designed and simulated using MATLAB Simulink following a model-based design approach.

## 🎯 Project Objective

To model and control the temperature of four interconnected rooms using limited heating resources (steam units) while maintaining thermal stability and safety constraints.

Each room's temperature is influenced by:
- External temperature
- Neighboring rooms
- Heating power
- Control decisions

## 🧠 System Model

The temperature dynamics of each room are defined by:

ẋᵢ = cᵢhᵢ + bᵢ(u − xᵢ) + Σ aᵢⱼ(xⱼ − xᵢ)

Where:
- xᵢ → room temperature
- u → external temperature
- hᵢ → heater state (0 or 1)
- A → room interaction matrix
- b, c → system parameters

## 🔧 System Components

### 1️⃣ Room Heating Subsystem
- Implements thermal dynamics of 4 rooms
- Uses parameterized matrices (A, b, c)
- Supports external temperature input

### 2️⃣ Thermostat Controller (Stateflow)
- Controls heater activation per room
- Maintains temperature thresholds
- Limits active heaters to two rooms
- Handles heater relocation logic

### 3️⃣ Safety Gateway
- Validates control commands before execution
- Prevents unsafe heater activation

### 4️⃣ System Integration & Simulation
- Full system modeled in Simulink
- Temperature and control signals monitored
- Heater allocation visualized

## 🧪 Verification & Testing

- Requirement-based design
- Black-box and white-box testing
- Simulation-based validation
- Coverage analysis using Simulink Test

## 🛠 Tools & Technologies

- MATLAB
- Simulink
- Stateflow
- Simulink Requirements
- System Composer
- Embedded Coder
- Simulink Test

## 📊 Simulation Goal

Maintain room temperatures within the desired range (15°C – 20°C) under system constraints.

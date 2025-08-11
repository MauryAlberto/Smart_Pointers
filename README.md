# Smart Pointer Implementations in C++

This project contains **minimal, educational implementations** of two common C++ smart pointers:

- `UniquePtr` — a simple version of `std::unique_ptr`
- `SharedPtr` — a simple version of `std::shared_ptr`

The goal of this project is to **understand how smart pointers work internally** by implementing them from scratch as C++ class templates.

---

## Project Structure

```
Unique_Ptr/
│── main.cpp          # Contains the UniquePtr class and example usage
│── CMakeLists.txt    # Build instructions for UniquePtr project

Shared_Ptr/
│── main.cpp          # Contains the SharedPtr class and example usage
│── CMakeLists.txt    # Build instructions for SharedPtr project
README.md
```

---

## Concepts Covered

### **UniquePtr**
- Single ownership of a dynamically allocated object.
- Move semantics for ownership transfer (`std::move`).
- No copy constructor or copy assignment allowed.
- Access operators (`*` and `->`), `get()`, `release()`, `reset()`.

### **SharedPtr**
- Multiple ownership via **reference counting**.
- Copy constructor and copy assignment share ownership.
- Destructor decrements reference count and frees memory when count reaches zero.
- `use_count()` to see how many owners share the same pointer.

---

## Building the Projects

### **UniquePtr**
```bash
cd Unique_Ptr
mkdir build && cd build
cmake ..
cmake --build .
./unique_ptr_demo
```

### **SharedPtr**
```bash
cd Shared_Ptr
mkdir build && cd build
cmake ..
cmake --build .
./shared_ptr_demo
```

---

## Example Output

**UniquePtr Example**
```
up1 is null
up2 value: 42
```

**SharedPtr Example**
```
sp1 count: 3
sp2 value: 100
```

---

# ADT
Abstract Data Type repo

**Ring buffer**

1. There are 2 indexes (**Head & Tail**, or **Write & Read**). They used to define the rigth 
place to put and get comming data.

2. **Head** index is used to track incomming data. Once new data put to the buffer, **Head** advanced.

3. **Tail** index is used to track outcomming data. Once the data retrieved from the buffer, **Tail** advanced.

4. Every time the index (Head or Tail) advanced (+ 1) it should be compared with the length og the buffer, in
order to wrap around (not to overflow the buffer).

**Example:** index = (index + 1) % BUFFER_SZ

5. Once the **Head** reaches the end of the buffer, it should be set to the start point ([0]) and it should 
advance the **Tail** (to overwrite the oldest data) or just discard the new data.

6. Each function **push()** and **pop()** should be start with verifying the state of the buffer (**full and is_empty**).

7. The **empty** condition is considered when **Head == Tail**.

8. The **full** condition is considered when **((Head + 1) % BUFFER_SZ) == Tail**.
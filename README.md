# Map Template Class

Created a Map Template Class for Uni and was kinda proud of it even though it might be kinda rudimetary and/or incomplete.
If the key is a number, it's ordered based on the key.
It's resized automatically.

## Fields:
Struct called Pair that contains a key a value and an index inside the map that is used to memorize the map data
map size
map capacity

## I will use *Map<int, const char*> m* as an example

## Methods:
### Set 
```cpp
m.Set(key, value);
```
- Takes in a ***key and a value***
  - If the key doesn't exist inside the map, a new data element is created and inserted inside the map
  - If the key exists, it replaces the old value with the new one
### Get
```cpp
const char* a = null;
m.Get(key, a);
```
- Takes in a ***key and a value address***
  - If the key doesn't exist, it returns FALSE
  - If the key exists, it passes the value associated to it's key to the given address and returns TRUE
### Count
```cpp
int size = m.Count();
``` 
- Returns the number of elements inside the Map
### Clear
```cpp
m.Clear();
```
- Empties out the Map
### Delete
- Takes in a ***key***
  - If the key doesn't exist, it returns FALSE
  - If the key exists, it deletes the element with the given key and returns TRUE
### Overloaded [] operator
- Allows the user to do stuff like
    ```cpp
        Map<int, const char*> m;
        m[10] = "first";
    ```
### Includes
```cpp
  // m2 is the same as m
  cout << "m2.Includes(m) = " << boolalpha << m2.Includes(m) << endl;
```
- Takes in another ***Map Object***
  - If ***ALL*** of the keys inside m are included inside m2 (regardless of order), returns TRUE
  - Otherwise, returns FALSE
  
### Copy and Move constructors
- Self explanatory

### You can use a for each with
  ```cpp
    Map <int, const char*> m;
    for(auto [key, value, index] : m){
      . . . . . .
    }
  ```

## Use examples inside main.cpp


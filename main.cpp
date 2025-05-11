#include <iostream>
#include "map.h"

using namespace std;

int main()
{
    // // Creating the object and asigning values to keys
    // Map<int, const char *> m;
    // m[10] = "C++";
    // m[20] = "test";
    // m.Set(30, "Poo");
    // // Printing using iterator
    // for (auto [key, value, index]: m)
    // {
    //     printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    // }
    //
    // cout << "============================\n";
    //
    // // Replacing values
    // m[20] = "result";
    //
    // for (auto [key, value, index]: m)
    // {
    //     printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    // }
    //
    // cout << "============================\n";
    //
    // // Using the Set method to both replace and create a new element inside the Map
    // m.Set(10, "Rust");
    // m.Set(40, "Python");
    //
    // for (auto [key, value, index]: m)
    // {
    //     printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    // }
    //
    // cout << "============================\n";
    //
    // // Check if a given key exists, if it does, get it's value
    // const char *value = "null";
    //
    // cout << "Key exists in map : " << boolalpha << m.Get(10, value) << '\n';
    // cout << value << '\n';
    //
    // cout << "============================\n";
    //
    // // Delete keys from the Map
    // m.Delete(10);
    // m.Delete(40);
    // for (auto [key, value, index]: m)
    // {
    //     printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    // }
    //
    // cout << "============================\n";
    //
    // // Clear the Map
    // m.Clear();
    // for (auto [key, value, index]: m)
    // {
    //     printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    // }
    // cout << "============================\n";
    //
    // // Check if one map contains the KEYS of another, not the values
    // Map<int, const char *> m2;
    //
    // m[10] = "C++";
    // m[20] = "test";
    // m[30] = "Poo";
    //
    // m2[10] = "C++";
    // m2[30] = "test";
    //
    // cout << "m2.Includes(m) = " << boolalpha << m2.Includes(m) << endl;
    // cout << "m.Includes(m2) = " << boolalpha << m.Includes(m2) << endl;
    //
    // cout << "============================\n";
    //
    // // Copying the map
    // m = m2;
    //
    // for (auto [key, value, index]: m)
    // {
    //     printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    // }

    Map<const char *, int> m;
    m.Set("C++", 10);
    m.Set("test", 30);
    m.Set("Poo", 20);

    for (auto [key, value, index]: m)
    {
        printf("Index:%d, Key=%s, Value=%d\n", index, key, value);
    }

    return 0;
}

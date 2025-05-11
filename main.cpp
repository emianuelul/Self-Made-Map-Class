#include <bits/stdc++.h>
#include "map.h"

using namespace std;

int main()
{
    Map<int, const char *> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto [key, value, index]: m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    cout << "============================\n";

    m[20] = "result";

    for (auto [key, value, index]: m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    cout << "============================\n";

    m.Set(10, "Rust");
    m.Set(40, "Python");

    for (auto [key, value, index]: m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    cout << "============================\n";

    const char *value;

    cout << "Key exists in map : " << boolalpha << m.Get(10, value) << '\n';
    cout << value << '\n';

    cout << "============================\n";

    m.Delete(10);
    m.Delete(40);
    for (auto [key, value, index]: m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    cout << "============================\n";

    m.Clear();
    for (auto [key, value, index]: m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    cout << "============================\n";

    Map<int, const char *> m2;

    m[10] = "C++";
    m[20] = "test";

    cout << "m2.Includes(m) = " << boolalpha << m2.Includes(m) << endl;
    cout << "m.Includes(m2) = " << boolalpha << m.Includes(m2) << endl;

    return 0;
}

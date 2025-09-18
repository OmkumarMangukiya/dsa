## Difference between reserve and direct size in vector
- In vector we can allocate space in two ways

1. ```cpp
	vector<int> v;
	v.reserve(10);
	```
2. ```cpp
   vector<int> v(10);  

   ```
   - Using reserve the capacity becomes 10 but the size still would be 0, in short the vector won't be initialized and we can `push_back()` safely without reallocation up to 10 elements.
   - Using the constructor the vector's size becomes 10 with Default-Initialized Elements (if non value is given it's by default initialized by 0)







[⬅️ Back to Main Page](../README.md)
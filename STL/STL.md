# #BinarySearch
#### `upper_bound` and `lower_bound`

- `lower_bound`->Finds first element `>= val`
```cpp
auto it = lower_bound(v.begin(), v.end(), val);
if (it != v.end() && *it == val) {
    // Value is present
}
```
- upper_bound -> Finds first element `> val`
```cpp
auto ub = upper_bound(v.begin(), v.end(), val);
if(it != v.end && *it >= val){
	// Value > is present
}
```

# #Index

- When have a iterator of a data structure we can directly get the index using `distance`
```cpp
count = distance(it, v.end());
```
- Alternatively we can also do (but this is not universal so it won't work for data structure like set but will work for vector , array , deque)
```cpp
count = v.end() - it;
```
Problem: Given a set of element return the power set of that set.
Solution:
- All three Solution have O(N * 2^N)

### Recursive 
```cpp
void findSubsets(int index, vector<int>& numbers, vector<int>& currentSubset, vector<vector<int>>& powerSet) {
    if (index >= numbers.size()) {
        powerSet.push_back(currentSubset);
        return;
    }

    findSubsets(index + 1, numbers, currentSubset, powerSet);

    currentSubset.push_back(numbers[index]);
    findSubsets(index + 1, numbers, currentSubset, powerSet);
    currentSubset.pop_back();
}

vector<vector<int>> generatePowerSetRecursive(vector<int>& numbers) {
    vector<vector<int>> powerSet;
    vector<int> currentSubset;
    findSubsets(0, numbers, currentSubset, powerSet);
    return powerSet;
}
```

### Bit Masking 
```cpp
<vector<int>> generatePowerSetBitMasking(vector<int>& numbers) {
    vector<vector<int>> powerSet;
    int totalElements = numbers.size();
    int numberOfSubsets = 1 << totalElements;

    for (int mask = 0; mask < numberOfSubsets; ++mask) {
        vector<int> currentSubset;
        for (int i = 0; i < totalElements; ++i) {
            if ((mask >> i) & 1) {
                currentSubset.push_back(numbers[i]);
            }
        }
        powerSet.push_back(currentSubset);
    }

    return powerSet;
}
```

### Cascading
```cpp
vector<vector<int>> generatePowerSetCascading(vector<int>& numbers) {
    vector<vector<int>> powerSet;
    powerSet.push_back({});

    for (int currentNumber : numbers) {
        int existingSubsetsCount = powerSet.size();
        for (int i = 0; i < existingSubsetsCount; ++i) {
            vector<int> newSubset = powerSet[i];
            newSubset.push_back(currentNumber);
            powerSet.push_back(newSubset);
        }
    }

    return powerSet;
}
```
**How it works:** You start with a list containing just the empty set. Then, for each number in your input set, you iterate through all the subsets you've already found, create a new subset by adding the current number to each of them, and add these new subsets to your list.

**Example with `[1, 2, 3]`:**

1. **Start:** `powerSet = [ [] ]`
2. **Process `1`:** Create new subsets by adding `1` to existing ones. New subset is `[1]`. Now, `powerSet = [ [], [1] ]`.
3. **Process `2`:** Create new subsets by adding `2` to existing ones (`[]` and `[1]`). New subsets are `[2]` and `[1, 2]`. Now, `powerSet = [ [], [1], [2], [1, 2] ]`.
4. **Process `3`:** Add `3` to all existing subsets. New ones are `[3], [1, 3], [2, 3], [1, 2, 3]`. Add them to the list.
5. **Final:** `powerSet = [ [], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3] ]`
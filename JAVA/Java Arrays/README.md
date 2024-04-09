# Java Arrays
### Declaration
##### `<data_type> [] <name_arr>;` (1): array -> null
##### `<data_type> <name_arr> [];` (2): array -> null

- (1): declare multiple arrays at once
```
    public class Main {
    public static void main(String[] args) {
        String[] cars = {"Volvo", "BMW", "Ford", "Mazda"}, mass = {"1", "2", "3"};
        System.out.println(cars.length);//output: 4
        System.out.println(mass.length);//output: 3
    }
}
```

- (2): declaring an array
```
    public class Main {
    public static void main(String[] args) {
        int cars, mass [];
        // carts is not array
        // mass is array
    }
    }
```

### Memory Allocation Process
##### `String cars = new String[<number>];`
##### `String cars[] = { "a", "b", "c" };`

### Access Elements 
- `Array.length`
Start 0 to array.length
```
    // The array's values were altered.
    for(int i=0; i<cars.length; i++) {
        arr[i] = 1;
    }
    
    // The array's values were not altered.
    for(int e : arr) {
        e = 1;
    }
```
###### **Note**: 
- For-each Loops are not appropriate when you want to modify the array.

### Method
1. Arrays.sort(---);
- Arrays sort(arr): Sorts the complete array in ascending order. 
- Arrays sort(arr, start, end): Sorts the specified range of array in ascending order.
```
    int[] arr = {3, 1, 2};
    Arrays.sort(arr); // arr sẽ trở thành {1, 2, 3}

```

2. Arrays.binarySearch(arr, value): tìm kiếm value trong arr 
**Note**: array sorted
```
    int index = Arrays.binarySearch(arr, 2); // index = 1
```

3. Arrays.equals(arr1, arr2): Check if both arrays are equal or not
```
    int[] arr1 = {1, 2, 3};
    int[] arr2 = {1, 2, 3};
    boolean isEqual = Arrays.equals(arr1, arr2); // true
```

4. Arrays.fill(originalArray, fillValue): Assigns this fill value to each index of this arrays
```
    int[] arr = new int[5];
    Arrays.fill(arr, 10); // arr sẽ trở thành {10, 10, 10, 10, 10}
```

5. Arrays.toString(originalArray): Convert Array to String
```
    int[] arr = {1, 2, 3};
    String str = Arrays.toString(arr); // str = "[1, 2, 3]"
```

6. Arrays.copyOf(arr, newLength): Used to copy an array or part of an array.
```
    int[] arr = {1, 2, 3};
    int[] copiedArray = Arrays.copyOf(arr, arr.length); // copiedArray sẽ trở thành {1, 2, 3}
```

7. Arrays.copyOfRange(arr, fromIndex, endIndex): Used to copy from `fromIndex` to `endIndex`.
```
    int[] arr = {1, 2, 3, 4, 5};
    int[] copiedArray = Arrays.copyOfRange(arr, 1, 3); // copiedArray sẽ trở thành {2, 3}

```

8. Arrays.asList(arr): Return list elements
```
    String[] arr = {"a", "b", "c"};
    List<String> list = Arrays.asList(arr); // list = ["a", "b", "c"]

```

9. Arrays.hash(arr): Return hash code
```
    int[] arr = {1, 2, 3};
    int hashCode = Arrays.hashCode(arr); // hashCode = 30817 (ví dụ)
```

10. Arrays.deepEquals(arr1, arr2): Used to compare two multidimensional arrays to check if they are equal.
```
    int[][] arr1 = {{1, 2}, {3, 4}};
    int[][] arr2 = {{1, 2}, {3, 4}};
    boolean isEqual = Arrays.deepEquals(arr1, arr2); // true
```

11. Arrays.deepHashCode(arr): Return hash code for multidimensional arrays
```
    int[][] arr = {{1, 2}, {3, 4}};
    int hashCode = Arrays.deepHashCode(arr); // hashCode = 12345678 (ví dụ)
```

12. ....
# JAVA STRING

##### A `String` variable contains a collection of characters surrounded by double quotes(dấu "");

1. Declaration 
##### `String <name>;`
##### `String <name> = "string";`

2. `Length()`: return length of string
```
    String str = "Hello";
    int length = str.length(); // length sẽ là 5
```

3. `charAt(index)`: return value at index
```
    char ch = str.charAt(0); // ch sẽ là 'H'
```

4. `subString(start)/subString(start, end)`: return substring
```
    String sub1 = str.substring(1); // sub1 sẽ là "ello"
    String sub2 = str.substring(1, 3); // sub2 sẽ là "el"
```

5. `indexOf("character")/indexOf("character", start)`: return index of the character in the string
```
    int index1 = str.indexOf("l"); // index1 sẽ là 2
    int index2 = str.indexOf("l", 3); // index2 sẽ là 3
```

6. `toLowerCase()/toUpperCase`: return lowercase string/uppercase string
```
    String lower = str.toLowerCase(); // lower sẽ là "hello"
    String upper = str.toUpperCase(); // upper sẽ là "HELLO"
```

7. `trim()`: remove whitespace at head and end in the String
```
    String str = "  Hello  ";
    String trimmed = str.trim(); // trimmed sẽ là "Hello"
```

8. `replace(charX, charY)`: replace charY by charX
```
    String replaced1 = str.replace('l', 'x'); // replaced1 sẽ là "Hexxo"
    String replaced2 = str.replace("ll", "xx"); // replaced2 sẽ là "Hexxo"
```

9. `isEmpty()`: return true/false
```
    boolean empty = str.isEmpty(); // false
```

10. `split(regex, limit)`: split string to array base regex
```
    String str = "apple,banana,orange";
    String[] parts = str.split(","); // Tách chuỗi thành các phần con, sử dụng dấu phẩy làm dấu phân cách
```

11. `contains()`: check string contain substring
```
    boolean contains = str.contains("el"); // true
```

12. `equals(str)/equalsIgnoreCase(str)`: compare 2 string return true/false
```
    boolean equal = str.equals("Hello"); // true
    boolean equalIgnoreCase = str.equalsIgnoreCase("hello"); // true
```

13. `compareTo(str)`: compare 2 string return number
```
    int comparison = str.compareTo("Hi"); // 1
```
- return 0: equal
- return > 0: str greater than strOther
- return < 0: str less than strOther

14. `concat(str)`: concat 2 string
```
    String concatenated = str.concat(", World!"); // "Hello, World!"
```

15. `valurOf()`: convert other datatype to string.
```
    String fromInt = String.valueOf(42); // "42"
    String fromDouble = String.valueOf(3.14); // "3.14"
```


...

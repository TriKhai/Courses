# I. THỪA KẾ
### 1. Định nghĩa
- Một lớp thừa hưởng tất cả các thành phần của một lớp khác
- Chỉ truy cập được public và protected 

### 2. Khai báo
```
    <P.vi> class A {
        <>
    }
```

# II. ĐA HÌNH
### 1. Định nghĩa
- Một thành phần có ý nghĩa hay xử lí khác trong một lớp khác . Bằng việc nạp chồng/ nạp đè
- Tham chiếu cha có thể tham chiếu đến các đối tượng con. Kh truy cập được các thành phần của con trừ nạp đè
- Tham chiếu con không thẻ tham chiếu đến đối tượng cha. Truy cập được public, protected, default(nếu cùng gói).

# III. TRỪU TƯỢNG
### 1. Định nghĩa
- Là việc **mô hình hóa bài toán thành các đối tượng**.

### 2. Lớp trừu tượng (Abstract Class)
- Là lớp tổng quát để tạo các lớp con và tham chiếu nhưng không dùng để tạo ra các đối tượng.
- Khai báo
```
    <P.vi> abstract class A {
        // các thành phần lớp A
        // Phương thức trừu tượng
        <P.vi> abstract <Kiểu> <Tên P.thuc trừu tuọng> ();

    }

```

- Chú ý: Phương thức trừu tượng chỉ khai báo. Việc định nghĩa sẽ viết trong lớp con cháu.
```
    <P.vi> class C extends A {
        <P.vi> abstract <Kiểu> <Tên P.thuc trừu tuọng> () {
            // code ....
            // Định nghĩa phương thức lớp cha A
        }
    }
```

### 3. Giao diện
- Y như lớp trừu tượng nhưng có thể implement nhiều lớp...(cài đặt đa thừa kế).
- Các lớp -> trừu tượng quan hệ cha con
- Giao diện -> trừu tượng các chức năng không có quan hệ cha con.

```
    <P.vi> interface <Tên lớp> {
        // Các khai báo phương thức chung...(chỉ khai báo)
    }

    <Pvi> class A implements Inf1, Inf2, ... {
        //...
        // Định nghĩa phương thức của giao diện Inf1, Inf2
    }

```
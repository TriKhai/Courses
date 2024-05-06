# I PHƯƠNG THỨC (METHOD)
### 1. Đĩnh nghĩa
- Thành phần xử lí các thuộc tính

### 2. Khai báo
```
    <Phạm vi> class A {
        <Phạm vi> <Kiểu dữ liệu> <Tên phương thức> (Đối số) {
            // LỆNH
            // RETURN (có thể có)
        }
    }
```

# II. TÁI ĐỊNH NGHĨA
### 1. Đĩnh nghĩa
- Định nghĩa nhiều hàm cùng tên.
- Khác đối số hoặc vị trí các đối số

### 2. Khai báo
```
    <Phạm vi> class A {
        <Phạm vi> <Kiểu> f() {...}
        <Phạm vi> <Kiểu> f(đối số..) {...}
    }

```

# III. PHƯƠNG THỨC XÂY DỰNG SAO CHÉP
### 1. Định nghĩa
- Là phương thức xây dựng được gọi tự động để tạo ra một đối tượng sao chép từ đối tượng khác.

### 2. Khai báo
```
    <Phạm vi> class A {
        <Phạm vi> A (A a) {
            // Sao chép đầy đủ thuộc tính của đối tượng
        }
    }
```

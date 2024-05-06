# I. LỚP (Class)
### 1. Định nghĩa
- Lớp: **Tổng quát hóa** các đối tượng có cùng thuộc tính, phương thức.
- Thuộc tính: Thành phần dữ liệu dùng để lưu trữ trạng thái cho đối tượng.(Biến lưu trữ)
- Phương thức: Thành phần xử lí dùng để cập nhật, truy xuất, xử lí thao tác,... các thuộc tính.(Hàm xử lí)

### 2. Cú pháp
```
    <Phạm vi> class <Tên Lớp> {
        // Thuộc tính
        <Phạm vi> <Kiểu> <Tên thuộc tính>
        ....

        // Phương thức
        <Phạm vi> <Kiểu> <Tên phương thức> (Đối số) {
            //...
        }
        ....

    }

```

### 3. Lưu ý
- Tên lớp: Danh từ, Hoa chữ đầu.
- Kiểu: Cơ bản và tham chiếu
- Tên thuộc tính: quy tắc tên biến (tính từ)
- Tên phương thức: quy tắc tên hàm (động từ)
- Phạm vi truy cập: Java có 4 cái(defaule/public/private/protected)

# II. ĐỐI TƯỢNG (OBJECT)
### 1. Định nghĩa
- Đối tượng: **Cụ thể hóa** một lớp bằng việc gán giá trị cụ thể cho thuộc tính.

### 2. Cú pháp
```
    // Khai báo
    <Tên lớp> <Tên đối tượng>

    // Cấp phát bộ nhớ
    <Tên đối tượng> = new <Tên lớp> (Đối số)

    // Truy xuất các thành phần của 1 lớp/đối tượng
    <Tên đối tượng>.<Tên thành phần>(đối só)
```

# III. PHƯƠNG THỨC XÂY DỰNG (CONSTRUCTOR) 
### 1. Đĩnh nghĩa
- Được gọi tự động mỗi khi tạo ra đối tượng
- Têm trùng với tên lớp
- Có thể chứa đối số
- Không có kiểu trả về
- Có bao nhiêu constructor thì có bấy nhiêu cách tạo đối tượng.

### 2. Khai báo
```
    <Phạm vi> class A {
        ....
        <Phạm vi> A (Đối số) {
            // Cấp phát bộ nhớ cho các thuộc tính
            // Gán giá trị ban đầu cho các thuộc tính
        }
    }

```





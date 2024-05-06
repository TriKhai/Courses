# OOP: OBJECT ORIENTED PROGRAMING
- Lập trình hướng đối tượng là **phương pháp lập trình** dựa trên việc **mô hình hóa** một vấn đề thành các **đối tượng**. Sau đó **ánh xạ các đối tượng** vào chương trình thông qua một chương trình.
- Trực quan hóa.
- Module hóa. (gôm nhóm)
- Bảo mật.

# So ánh LTHDT (OOP) với LT hướng thủ tục (POP: Procedure Oriented Programing)
### POP
- Nhìn vào chức năng.
- Dựa trên giải thuật.
- CT = Giải thuật + CTDL
### OOP
- Nhìn vào đối tượng.
- CT = Tập các đối tượng + Sự tương tác các đối tượng.

# II. CÁC KHÁI NIỆM LIÊN QUAN
### 1. Lóp (CLASS)
- Sự **tổng quát hóa** nhiều đối tượng có cùng đặc trưng hay thành phần(Bao gồm thuộc tính và phương thức).
- Một lớp có thể xem như **một kiểu DL**.

### 2. Đối tượng (OBJECT)
- Sự **cụ thể hóa** (thể hiện) của một lớp. Bởi việc gán các giá trị cụ thể trên các thuộc tính cùng lớp.
- Một đối tượng có thể xem như **một biến**.

### 3. Thuộc tính (ATTRIBUTE / DATA / PROPERTY)
- Thuộc tính được xem như là một **thành phần dữ liệu**. Được sử dụng để **lưu trữ trạng thái** của một đối tượng tại một thời điểm.

### 4. Phương thức (METHOD / **FUNCTION** / OPERATION)
- Được xem như các **thành phần xử lí** trên các thuộc tính được sử dụng để cập nhật hay truy xuất các thuộc tính của lớp hay đối tượng.

### 5. Phạm vi truy cập (ACCESS MODIFIER)
##### Xác định đường truy xuất đến các thành phần của một lớp hay đối tượng.
- **private** (-): Truy bên trong cùng *lớp*.
- **protected** (#): Truy bên trong cùng *lớp, con cháu, cùng gói*.
- **public** (+): Truy không giới hạn.
- **default** (.): Có trong java khi khai báo không có access modifier, truy xuất bên trong cùng gói, cùng lớp.

### 6. Thông điệp và truyền thông điệp (MESSAGE & MESSAGE PASSING)
- Tương tác giữa các đối tượng
- Thông điệp: là báo cho đó tượng đó biết phải làm gì.
- Truyền thông điệp: Khi đối tượng nhận được thông điệp đối tượng đó sẽ kích hoạt phương thức tương ứng.
```
    //VD: Student svien1;
          svien1.run();
    // Thông điệp là run()
    // Truyền thông điệp là dấu .
```

# III. Tính chất (CHARACTERISTICS)
### 1. Tính bao gói (Encapsolation)
##### Thể hiện ở hai khía cạnh
- Bao gói không cho tác động trực tiếp chỉ thao tác qua chức năng.
- Gom nhóm các thuộc tính và phương thức vào trong một đối tượng.
- Phạm vi truy cập (public/private/protected)

### 2. Tính đa hình (Polymorphism)
##### Một thành phần sẽ có được ý nghĩa hoặc xử lí khác nhau trong môi trường (cùng lớp, cùng gói,...) khác nhau. Có 2 cách để thực hiện: 
- Nạp chồng / Tái định nghĩa (OVERLOADING): Định nghĩa nhiều **hàm cùng tên** nhưng **khác đối số** trong cùng lớp hoặc trong lớp con cháu
- Nạp đè (OVERRIDING): Cho phép định nghĩa nhiều **hàm trùng tên, trùng đối số** nhưng **trong lớp cha con**.
- Lưu ý: Lớp cha không thể truy cập được các thành phần của lớp con, ngoại trừ thành phần bị nạp đè./ Lớp con có thể truy cập thành phần được bảo vệ và chung của lớp cha
- Nạp chồng là tái định nghĩa.
- Nạp đè là định nghĩa lại hàm đè lên hàm củ luôn.

### 3. Tính thừa kế (INHERITANCE)
- Một lớp con B được thừa kế từ lớp cha A nếu nó thừa hưởng được các thành phần của lớp cha A. Tuy nhiên lớp con chỉ truy cập được thành phần được **bảo vệ và chung** của lớp cha. 
- Thừa hưởng (all), Truy cập(bảo vệ và chung).
- Java chỉ hổ trợ thừa hưởng dạng public.

### 4. Trừu tượng hóa (Abstraction)
- Là việc **mô hình hóa bài toán thành các đối tượng**. Quá trình xác định đối tượng, thuộc tính, phương thức và quan hệ giữa các đối tượng đucợ hội là quá trình trừu tượng hóa
- `abstract/interface`

## [o]. So sánh sự khác nhau giữa abstract và interface.
##### Giống nhau:
- Sử dụng để đạt tính trừu tượng
- Sử dụng trong kế thừa
- Chứa cả method và trường dữ liệu
- Không thể tạo đối tượng cụ thể với keyword new.

##### Khác nhau
- 




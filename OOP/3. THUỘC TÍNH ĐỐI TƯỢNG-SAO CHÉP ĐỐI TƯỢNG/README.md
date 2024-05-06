# I. THUỘC TÍNH
### 1. Định nghĩa
- Thành phần dữ liệu để lưu trữ trạng thái của lớp đối tượng

### 2. Khai báo
```
    <Pham vi> <Kiểu> <Tên thuộc tính>;
    ...

```

# II. THUỘC TÍNH ĐỐI TƯỢNG
### 1. Khai báo
```
    <P.Vi> class A {...}
    <P.Vi> class B {
        <P.Vi> A a;// thuộc tính đối tượng
        ...
    }

    // A và B có quan hệ thành phần/bao gồm
```

### 2. Tính bao gói
- Cùng gói thì A truy cập được all trừ private
- Khác gói thì A chỉ truy cập được public

# III. SAO CHÉP ĐỐI TƯỢNG
### 1. Sao chép Sâu
- Sao chép đầy đủ từng thuộc tính 2 đối tượng
- VD: 
```
    ...
    Public DThang(DThang dt) {
        d1 = new Diem(dt.d1);
        d2 = new Diem(dt.d2);
    }
    ...

```

### 2. Sao chép Cạn
- Thực hiện gán bằng
- VD: 
```
    ...
    Public DThang(DThang dt) {
        d1 = dt.d1;
        d2 = dt.d2;
    }
    ...

```
### 3. Sao chép Tham Chiếu
- Thực hiện gán bằng cho 2 đối tượng


### Thứ tự vẽ trong tập @@
- SCTHamChieu -> Sao chép cạn -> Sao chép cạn-clone() -> Sao chép sâu

# IV. THUỘC TÍNH TĨNH
### 1. Định nghĩa
- Thuộc tính tĩnh là thuộc tính được dùng chung cho tất cả các đối tượng của cùng lớp.
- Dùng trong lập trình song song
- Các CPU đều có cùng giá trị

### 2. Khai báo
```
    <P.vi> class A {
        <P.vi> static <Kiểu> <Tên thuộc tính> = <Gía trị>;
        ...
    }
```
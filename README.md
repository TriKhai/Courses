# CHAPPTER 1: INTRODUCTION

## I. Cấu trúc của một hệ thống máy tính:
#### Có 4 thành phần trong hệ thống máy tính:
- Phần cứng (hardware): cung cấp tài nguyên CPU, I/O,...
- Hệ điều hành (Operating System): Quản lí tài nguyên phần cứng (**OS là phần mềm**).
- Các chương trình(Ctrinh hệ thống và Ctrinh Ứng dụng): Sử dụng tài nguyên hệ thống.
- Đối tượng người dùng: nhu cầu tính toán làm việc với ctrinh máy tính.
![alt text](./img/componentsCS.png)

#### Hệ điều hành ?
- Hệ thống máy tính gồm phần cứng và phần mềm: OS Là phần mềm.
- Nằm phía bên trên phần cứng.
- Nằm dưới các ctrinh hệ thống.

#### User interface program: chia 2 loại
- **GUI**: Giao diện đồ họa. (Graph user interface).
- **CLI**: Giao diện dòng lệnh. (Command line interface).

#### Định nghĩa hệ điều hành
- Bộ cấp phát tài nguyên (Quản lí cả khgian và thgian...tiến trinh nào dùng vùng nhớ nào tại tgian nào).
- Chương trình điều khiển (Quản lí điều khiển toàn bộ hệ thống ... cho phép thì ctrinh mới làm đc nhé -> Ngăn chặn lỗi xãy ra).
- Máy tính mở rộng (Che phủ những tính toán phứt tạp bên dưới hệ thống)


#### Kernel ?
- Kernel là ctrinh chạy toàn phần trong hệ thống từ khi mở máy.

#### USER MODE(tất cả gì trong hệ thống máy đều chạy ở user mode)/ KERNEL MODE(chế độ nhân lõi chỉ duy nhất hệ điều hành chạy)
- Khi ra lệnh ta ở UM 
- Để truy xuất thao tác với phần cứng chuyển qua Kernel Mode
- Để kết quả từ phần cứng đến người dùng chuyển qua User Mode

#### Các cách Transition usermode/kernelmode
- interrupt(phần cứng): nếu hardware request OS services(tất cả gì sài trên máy đều là dịch vụ của OS).
- trap(chương trình): Ctrinh người dùng yêu cầu OS.
- exception: ngoại lệ lỗi đồ đó.

#### Computer Starup
- Bootstrap program: (ngòi lửa)
- Khi ấn nút nguồn -> Bootstrap kích hoạt (định vị kernel hđh đang nằm đâu) -> nạp kernel vào memory -> starup kernel hđh
- Khi kernel của hệ điều hành vận hàng -> Nhường quyền đkhiển cho HĐH.

- Tất cả dữ liệu, tài nguyên lưu bất kì đâu trên máy muốn sử dụng thì phải được nạp vao memory.
- OS kernel luôn nằm trong memory nhé.

#### Storage-Device Hierarchy
- Tốc độ giảm dần , Dung lượng tăng dần:
- **Registers**
- **cache**
- **main memory**
- **disk** (electronic disk -> magnetic disk -> optical disk).
- **magnetic tapes**

#### CSA (Computer System Architecture - kiến trúc hệ thống máy tính)
- Đơn xử lí
- Đa xử lí: (Ưu điểm: )

#### Hệ thống đa xử lí
- AMP(Bất đối xứng): có processer làm boos quản lí(ƯĐ: phân chia công việc; NĐ: boss hỏng -> tới công chuyện)
- SMP(Đối xứng): Phân chia kh đồng đều dẫn đến 1 hệ thống nhàn rỗi hay quá tải
#### Multicore hay Multichip hiệu quả hơn?
- Multicore oke hơn: 2 người 1 phòng oke hơn 1 người 1 phòng

#### Hệ thống cụm: Yêu cầu kết nối mạng
- Cụm đối xứng
- Cụm bất đối đối xứng: kh có boos nhưng có 1 máy tính ở chế độ **hot-standby**(Luôn sẳn sàng thay thế khi có máy bị fail - giống kiểu dự bị).

#### Cấu trúc OS
- Hệ thống bó
- Hệ thống đa chương(chương trình)
- Hệ thống Timesharing

- Các thành phần: Process management/Memory management/File and Storage/Networking

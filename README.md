# CHƯƠNG 1: ĐỘ PHỨT TẠP THUẬT TOÁN
## 1. Sắp xếp độ phứt tạp
#### Định nghĩa Algorithmic Complexity: 


#### So sánh:
- Hằng: O(1)
- Logaric: O(logn) 
- Tuyến tính: O(n)
- Loga tuyến tính: O(nlogn)
- Đa thức: O(n^c)
- Mũ: O(C^a)
- Lũy thừa: O(n!)

## 2. Chương trình không có đệ quy (QTC, QTN)
- Tính độ phút tạp dựa trên code

## 3. Chương trinhg có đệ quy(Truy hồi/Tổng quát)
- Thành lập phtrinh và tính độ phứt tạp


# CHƯƠNG 2: SẮP XẾP
## 1. Ý tưởng các thuật toán sắp xếp đơn giản O(n^2)
### Selection Sort:
- Ý tưởng:
##### Chọn phần tử nhỏ nhất trong n phần tử ban đầu, đưa phần tử này về vị trí đúng là vị trí đầu tiên của mảng hiện hành. Sau đó không quan tấm đến nó nữa, xem mảng hiện hành chỉ còn n-1 phần tử của mảng ban đầu. Bắt đầu từ vị trí thứ 2, lặp lại quá trình trên cho mảng hiện hành đến khi chỉ còn 1 phần tử.
##### Do mảng ban đầu có n phần tử, vậy tóm tắt ý tưởng thuật toán là thực hiện n-1 lượt việc đưa phần tử nhỏ nhất trong mảng hiện hành về vị trí đúng ở đầu mảng.
- Giải thuật: 
##### **B1:** Chọn phần tử có khóa nhỏ nhất trong n phần tử từ a[0] đến a[n-1] và hoán vị nó với phần tử a[0].
##### **B2:** Chọn phần tử có khóa nhỏ nhất trong n-1 phần tử từ a[1] đến a[n-1] và hoán vị nó với a[1]. 
##### **Tổng quat bước i:** chọn phần tử có kháo nhỏ nhất trong n-i phần tử từ a[i] đến a[n-1] và hoán vị nó với a[i];
##### **Bn-1:** Mảng đã được sắp xếp.
- Minh họa:
#### Sắp Xếp giảm dần dãy: 5 6 2 2 10 12 9 10 9 3
|    | a0 | a1 | a2 | a3 | a4 | a5 | a6 | a7 | a8 | a9 |
|----|----|----|----|----|----|----|----|----|----|----|
| BĐ |  5 |  6 |  2 |  2 | 10 | 12 |  9 | 10 |  9 |  3 |
| B1 | **2**  |    |    |    |    |    |    |    |    |    |
| B2 |    |    |    |    |    |    |    |    |    |    |
| B3 |    |    |    |    |    |    |    |    |    |    |
| B4 |    |    |    |    |    |    |    |    |    |    |
| B5 |    |    |    |    |    |    |    |    |    |    |
| B6 |    |    |    |    |    |    |    |    |    |    |
| B7 |    |    |    |    |    |    |    |    |    |    |
| B8 |    |    |    |    |    |    |    |    |    |    |
| B9 |    |    |    |    |    |    |    |    |    |    |
| KQ |    |    |    |    |    |    |    |    |    |    |

# CHAPTER 3:


# CHAPTER 4:

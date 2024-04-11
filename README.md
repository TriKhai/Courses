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
## 1. Các thuật toán sắp xếp đơn giản O(n^2)
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
| B1 |  **2** |  6 |  **5** |  2 | 10 | 12 |  9 | 10 |  9 |  3 |
| B2 |    |  **2** |  5 |  **6** | 10 | 12 |  9 | 10 |  9 |  3 |
| B3 |    |    |  **3** |  6 | 10 | 12 |  9 | 10 |  9 |  **5** |
| B4 |    |    |    |  **5** | 10 | 12 |  9 | 10 |  9 |  **6** |
| B5 |    |    |    |    |  **6** | 12 |  9 | 10 |  9 | **10** |
| B6 |    |    |    |    |    |  **9** | **12** | 10 |  9 | 10 |
| B7 |    |    |    |    |    |    |  **9** | 10 | **12** | 10 |
| B8 |    |    |    |    |    |    |    | **10** | 12 | 10 |
| B9 |    |    |    |    |    |    |    |    | **10** | **12** |
| KQ |  **2** |  **2** |  **3** |  **5** |  **6** |  **9** |  **9** | **10** | **10** | **12** |

#### Ngoài lề: Không phụ thuộc tình trạng của mảng ban đầu O(n^2).

###
### Insertion Sort:
- Ý tưởng: 
##### Bắt chước xếp các quân bài của những người chơi bài. Muốn sắp xếp một bộ bài theo tuần tự, người chơi bài rút lần lượt từ quân bài thứ 2, so với các quân đứng ở trước nó để chèn vào vị trí thích hợp.
#### Xét mảng gồm k phần tử đầu. Với i=1, mảng gồm một phần tử đã được sắp. Giả sử trong mảng i-1 phần tử đầu đã được sắp, để sắp xếp một phần tử ta tìm vị trí thích hợp của nó trong mảng. Vị trí thích hợp đó là đứng trước phần tử lớn hơn nó và sau phần tử nhỏ hơn hoặc bằng nó.

- Giải thuật:
##### **B1:** Xen phần tử a[1] vào danh sách đã có thứ tự a[0] sao cho a[0], a[1] là danh sách có thứ tự.
##### **B2:** Xen phần tử a[2] vào danh sách đã có thứ tự a[0], a[1] sao cho a[0], a[1], a[2] là danh sách có thứ tự.
##### **Tổng quat bước i:** Xen phần tử a[i] vào danh sách đã có thứ tự a[0], a[1], a[2], ..., a[i-1] sao cho a[0], a[1], a[2], ..., a[i-1], a[i] là danh sách có thứ tự.
##### **Bn-1:** Mảng đã được sắp xếp.

- Minh họa
#### Sắp Xếp giảm dần dãy: 5 6 2 2 10 12 9 10 9 3
|    | a0 | a1 | a2 | a3 | a4 | a5 | a6 | a7 | a8 | a9 |
|----|----|----|----|----|----|----|----|----|----|----|
| BĐ |  5 |  6 |  2 |  2 | 10 | 12 |  9 | 10 |  9 |  3 |
| B1 |  5 |  **6** |    |    |    |    |    |    |    |    |
| B2 |  **2** |  5 |  6 |    |    |    |    |    |    |    |
| B3 |  2 |  **2** |  5 |  6 |    |    |    |    |    |    |
| B4 |  2 |  2 |  5 |  6 | **10** |    |    |    |    |    |
| B5 |  2 |  2 |  5 |  6 | 10 | **12** |    |    |    |    |
| B6 |  2 |  2 |  5 |  6 |  **9** | 10 | 12 |    |    |    |
| B7 |  2 |  2 |  5 |  6 |  9 | 10 | **10** | 12 |    |    |
| B8 |  2 |  2 |  5 |  6 |  9 |  **9** | 10 | 10 | 12 |    |
| B9 |  2 |  2 |  **3** |  5 |  6 |  9 |  9 | 10 | 10 | 12 |
| KQ |  **2** |  **2** |  **3** |  **5** |  **6** |  **9** |  **9** | **10** | **10** | **12** |
#### Ngoài lề: Phụ thuộc tình trạng của mảng ban đầu (Tại while có thể O(1)).
###
### Buble Sort:
- Ý tưởng: 
##### Xuất phát từ cuối (or đầu) mảng, đổi chổ các cặp phần tử kế cận để đưa phần tử nhỏ(lớn) hơn trong cặp phần tử đó về vị trí đứng đầu(cuối) mảng hiện hành. Sau đó sẽ không xét đến nó ở vị trí tiếp theo, do vậy ở lần xử lý thứ i sẽ có vị trí đầu mảng là i. Lặp lại xử lý trên cho đến khi không còn cặp phần tử nào để xét. 

- Giải thuật:
##### **B1:** Xét a[j] (j giảm từ n-1 đến 1), so sanh khóa của a[j] với khóa của a[j-1]. Nếu a[j] < a[j-1] thì đổi a[j] và a[j-1]. Sau bước này thì a[0] có khóa nhỏ nhất.
##### **B2:** Xét a[j] (j giảm từ n-1 đến 2), so sanh khóa của a[j] với khóa của a[j-1]. Nếu a[j] < a[j-1] thì đổi a[j] và a[j-1]. Sau bước này thì a[1] có khóa nhỏ thứ 2.
##### ....
##### **Bn-1:** Mảng đã được sắp xếp.
- Minh hoạ: 
#### Sắp Xếp giảm dần dãy: 5 6 2 2 10 12 9 10 9 3
|    | a0 | a1 | a2 | a3 | a4 | a5 | a6 | a7 | a8 | a9 |
|----|----|----|----|----|----|----|----|----|----|----|
| BĐ |  5 |  6 |  2 |  2 | 10 | 12 |  9 | 10 |  9 |  3 |
| B1 |  **2** |  5 |  6 |  2 |  3 | 10 | 12 |  9 | 10 |  9 |
| B2 |    |  **2** |  5 |  6 |  3 |  9 | 10 | 12 |  9 | 10 |
| B3 |    |    |  **3** |  5 |  6 |  9 |  9 | 10 | 12 | 10 |
| B4 |    |    |    |  **5** |  6 |  9 |  9 | 10 | 10 | 12 |
| B5 |    |    |    |    |  **6** |  9 |  9 | 10 | 10 | 12 |
| B6 |    |    |    |    |    |  **9** |  9 | 10 | 10 | 12 |
| B7 |    |    |    |    |    |    |  **9** | 10 | 10 | 12 |
| B8 |    |    |    |    |    |    |    | **10** | 10 | 12 |
| B9 |    |    |    |    |    |    |    |    | **10** | 12 |
| KQ |  **2** |  **2** |  **3** |  **5** |  **6** |  **9** |  **9** | **10** | **10** | **12** |
#### Ngoài lề: Không phụ thuộc tình trạng của mảng ban đầu O(n^2).

# CHAPTER 3:


# CHAPTER 4:

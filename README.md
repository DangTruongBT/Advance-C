# C nâng cao 🔥
## LESSON 1: COMPILER AND MARCO
### Quá trình biên dịch
Quy trình biên dịch là quá trình chuyển đổi ngôn ngữ bậc cao (NNBC) (C/C++, Pascal, Java,...) sang ngôn ngữ máy, để máy tính có thể hiểu và thực thi.
### Quá trình biên dịch gồm 4 giai đoạn
 >  - Giai đoàn tiền xử lý (Pre-processor)
 >  - Giai đoạn dịch NNBC sang Asembly (Compiler)
 >  - Giai đoạn dịch asembly sang ngôn ngữ máy (Asember)
 >  - Giai đoạn liên kết (Linker)
![Compiler_Marco (2)](https://github.com/DangTruongBT/advance-C/assets/103482832/62ae7186-a6a5-463e-8698-bd0b6aafef55)

#### *Pre-processor (Giai đoạn tiền xử lý):*
 - 1 Project được tạo ra từ nhiều file: `a.h, b.h, a.c, b.c` và file `main.c` sau quá trình tiền xử lý sẽ gọp tất cả các file thành 1 file duy nhất là file `main.i`.
 - Trong quá trình này sẽ chèn Header vào, triển khai Macro và xóa commment.
 - Lệnh trong CMD là: `gcc -E main.c -o main.i`.
   ![Screenshot 2024-03-08 101451](https://github.com/DangTruongBT/advance-C/assets/103482832/3682f5e3-5279-4215-aeda-d7f6543e23e6)
#### **3 việc xảy ra trong quá trình tiền xử lý**
 - `include` file header, có nghĩa là nội dung file sẽ được chèn vào vị trí mà mình chỉ định.
 - Xóa bỏ ghi chú (không ảnh hưởng đến dung lượng bộ nhớ và tốc độ xử lý chương trình)
 - Triển khai macro:
     - `Marco` là từ dùng để chỉ những thông tin được xử lý ở quá trình tiền xử lý (Pre-processor). Chia làm 3 nhóm chính:
         - `#include`
         - `#define`, `#undef`
         - `#if`, `#elif`, `#ifdef`, `#ifndef`
     - `#define`
         - Macro được định nghĩa bằng cách sử dụng chỉ thị tiền xử lý #define.
         - Nơi nào có tên Macro sẽ được thay thế bằng nội dung của macro đó.
         - Giảm lặp lại mã ,dễ bảo trì.
         - Ví dụ 1:
           ```c
           #include <stdio.h>

           // Định nghĩa hằng số Pi sử dụng #define
           #define PI 3.14
           int main() {
           // Sử dụng hằng số Pi trong chương trình
           double radius = 5.0;
           double area = PI * radius * radius;

           printf("Radius: %.2f\n", radius);
           printf("Area of the circle: %.2f\n", area);

           return 0;
           }

         - Ví dụ 2:
           ```c
           #include <stdio.h>

           // Định nghĩa macro để tìm số lớn hơn giữa hai số
           #define MAX(x, y) ((x) > (y) ? (x) : (y))

           int main() {
           int a = 10, b = 20;
    
           // Sử dụng macro để tìm số lớn hơn giữa a và b
           int maxNumber = MAX(a, b);

           printf("The bigger number between %d and %d is: %d\n", a, b, maxNumber);

           return 0;
           }
    - `#undef`
       - Chỉ thị `#undef` dùng để hủy định nghĩa của một macro đã được định nghĩa trước đó bằng `#define`




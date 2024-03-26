# C nâng cao 🔥
<details><summary>LESSON 1: COMPILER AND MARCO</summary>
<p>
 
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
       - Nếu hai hoặc nhiều tệp tiêu đề có cùng tên macro, chúng có thể xung đột với nhau. Việc sử dụng các chỉ thị này giúp ngăn chặn các xung đột này.
       - Ví dụ:
         ```c
          #include <stdio.h>
          #include "nhietdo.c"
          #include "doam.c"
          // trong 2 file đều có macro lần lượt là:
          //#define cam_bien 10(nhietdo.c)
          //#define cam_bien 20(doam.c)

          int main(){
 	        #undef cam_bien
 	        #define cam_bien 40
         return 0;
         }
   - `#if`: Sử dụng để bắt đầu 1 điều kiện xử lý.Nếu đúng thì các dòng lệnh sau `#if` sẽ được biên dịch , sai sẽ bỏ qua đến khi gặp `#endif`.
   - `#elif`: Để thêm 1 ĐK mới khi #if hoặc `#elif` sai.
   - `#else`: Dùng khi không có ĐK nào đúng
   - `#ifdef`: Dùng để kiểm tra 1 macro định nghĩa hay chưa.Nếu định nghĩa rồi thì mã sau ifdef sẽ được biên dịch.
   - `#ifndef`: Dùng để kiểm tra 1 macro định nghĩa hay chưa.Nếu chưa định nghĩa thì mã sau `#ifndef` sẽ được biên dịch.Thường dùng để kiểm tra macro đó đã dc định nghĩa trong file nào chưa, kết thúc thì `#endif`
#### Mục đích tránh định nghĩa nhiều lần và xung đột
  - Ví dụ:
    ```c
    #ifndef __ABC_H
    #define __ABC_H

    int a = 10;

    #endif
 - Một số toán tử trong Marco:
   - Ví dụ
   
   ```c
   #include <stdio.h>

   #define STRINGIZE(x) #x
   #define DATA 40

   int main() {

    // Sử dụng toán tử #
    printf("The value is: %s\n", STRINGIZE(DATA));

    return 0;
   }
 - Variadic Marco: Là một dạng macro cho phép nhận một số lượng biến tham số có thể thay đổi.
    - Ví dụ

   ```c
   #include <stdio.h>

 	#define print_menu_item(...) \
 		do { \
 			const char *items[] = {__VA_ARGS__}; \
 			int n = sizeof(items) / sizeof(items[0]); \
 			for (int i = 0; i < n; i++) { \
 				print_menu_item(i + 1, items[i]); \
 			} \
 		} while (0)

 	#define case_option(number, function) \
 		case number: \
 			function(); \
 			break;

 	#define handle_option(option, ...) \
 		switch (option) { \
 			__VA_ARGS__ \
 			default: \
 				printf("Invalid option!\n"); \
 		}

 	void print_menu_item(int number, const char *item) {
 			printf("%d. %s\n", number, item);
 		}

 	void feature1() { printf("Feature 1 selected\n"); }
 	void feature2() { printf("Feature 2 selected\n"); }
 	void feature3() { printf("Feature 3 selected\n"); }
 	void feature4() { printf("Feature 4 selected\n"); }

 	int main() {
 		print_menu_item("Option 1", "Option 2", "Option 3", "Option 4", "Exit");

 		int option;
 		scanf("%d", &option);

 		handle_option(option,
 					case_option(1, feature1)
 					case_option(2, feature2)
 					case_option(3, feature3)
 					case_option(4, feature4)
 		)

 		return 0;
- Compiler (Giai đoạn dịch NNBC sang ngôn ngữ Assembly):
   - Quá trình này compiler sẽ biên dịch từ file `.i `sang file ngôn ngữ assembly là file `.s`
   - Dùng lệnh `gcc -S main.i -o main.s`
- Assembler (Giai đoạn dịch ngôn ngữ Assembly sang ngôn ngữ máy): compiler sẽ Biên dịch ngôn ngữ Assembly sang ngôn ngữ máy (0 và 1). Và tạo ra tệp tin Object `.o`
   - Dùng lệnh `gcc -c main.s -o main.o` để tạo ra file `.o`
- Linker (Giải đoạn liên kết):
   - 1 hoặc nhiều file.o sẽ được compiler liên kết lại 1 File `.exe`.
   - File này để hệ điều hành chạy
   - Dùng lệnh gcc  `main.o -o filename` để tạo ra tệp thực thi .



</p>
</details>

<details><summary>LESSON 9: JSON</summary>
<p>

</p>
</details>




<details><summary>LESSON 10: LINKER LIST</summary>
<p>
 
## LESSON 10: LINKER LIST

### Danh sách liên kết là gì?
Danh sách liên kết (Linker List): là một cấu trúc dữ liệu được sử dụng để lưu trữ các phần tử tương tự như mảng nhưng cớ nhiều điểm khác biệt

Có các loại danh sách liên kết:
   - Danh sách liên kết đơn
   - Danh sách liên kết đôi
   - Danh sách liên kết vòng
###  Tính chất

  - Danh sách liên kết có thể mở rộng và thu hẹp một cách linh hoạt
  - Phần tử cuối cùng trong DSLK trỏ vào `NULL` (con trỏ `NULL`)
  - Đây kà kiểu cấu trúc dữ liệu kiểu cấp phát động có nghĩa là còn bộ nhớ thì còn cấp phát được, cấp phát đến khi nào hết bộ nhớ thì thôi
         - Vùng nhớ cấp phát : `Heap`
  - Không lãng phí bộ nhớ nhưng cần thêm bộ nhớ để lưu phần con trỏ.
    
![Screenshot 2024-03-26 144050](https://github.com/DangTruongBT/advance-C/assets/103482832/339e04a6-e5d0-4a7d-a212-bc29dab43f6f)

Để quản lí danh sách liên kết cần 1 con trỏ Head

Ví dụ:

Phần link của node 1 sẽ lưu địa chỉ node 2 là 6, tương tự với các node tiếp theo cho đến node cuối cùng link địa chỉ `NULL`
 
>     - Phần data lưu giá trị node

>     - Phần link lưu địa chỉ của node kế tiếp.

#### Ưu điểm

  - Có thể mở rộng với độ phức tạp
  - Dễ mở rộng và thu hẹp kích thước
  - Có thể cấp phát số lượng lớn các node tùy vào bộ nhớ
      
#### Nhược điểm

- Khó khăn trong việc truy cập 1 phần tử ở vị trí bất kì (0(n))
- Khó khăn trong việc cài đặt
- Tốn thêm bộ nhớ cho phần tham chiếu bổ sung

### Cấu trúc một node của DSLK
 ```c 
    
              struct node {
              int data;
              struct node* next; //link
          };
```
**Giải thích ý nghĩa của cấu trúc node**

Node ở dây có phần tử dữ liệu là một số nguyên lưu ở data, ngoài ra nó còn có 1 phần con trỏ trỏ tới chính struct node. Phần này chính là địa chỉ của node tiếp theo của nó trong DSLK.

Như vậy mỗi node sẽ có dữ liệu của nó và có địa chỉ của node tiếp sau nó. Đối với con trỏ cuối cùng trong DSLK thì phần địa chỉ này sẽ là con trỏ `NULL`


*Mỗi node trong DSLK đều đưuọc cấp phát động*
#### a. Tạo một node mới 
```c
    struct node {
              int data;
              struct node* next; //link
          };
   node *Makenode(int value){
    node *newNode = (node*)malloc(sizeof(node));
    newNode -> data = value;
    newNode -> next = NULL;
   return newNode;
```
#### b. Kiểm tra danh sách có rõng hay không
```c
  bool empty(node **array)
     {
      	if( (*array) == NULL)
         	{
		          return true;
         	}
      	else
	        {
		         return false;
	        }
    }
```

#### c. Thêm một node vào đầu danh sách
```c
void push_front(node **array, int value)
{
	 node* temp;
    temp = Makenode(value); 
    if (*array == NULL)  
    {

        *array = temp;
    }
    else
    {
    	temp->next = *array;
    	*array = temp;
	   }
    
}
```
#### d. Thêm một node vào cuối danh sách
```c
void push_back(node** array, int value)
{
    node* temp;
    temp = Makenode(value); // khoi tao node
                              // temp = 0xa1

    
    if (*array == NULL)   // if array doesn't have any node yet
    {

        *array = temp;
    }
    else                // if array has some node
    {
        node* p = *array;          // use p instead of array because we are using pointer, use array will change the structure of linkedlist
        while (p->next != NULL) // which mean the current node is not the last node
        {
            p = p->next;    // check next node until it a last node

        }

        p->next = temp;     // change it next member point to address of new node have just create
    }
}
```
#### e. Xóa node đầu danh sách
```c
     void pop_front(node **array)
       {
          	if(*head == NULL) return;
	          node *temp = *array;
          	*array = (*array)->next;
          	free(temp);
       }

```

#### f. Xóa node cuối danh sách
```c
   void pop_back(node **array){
    if(*array == NULL) return; // DSLK rong
    if((*array)->next == NULL){
        free(*array);
        (*array) = NULL;
    }
    else{
        node *tmp = (*array);
        //Duyet den node thu 2 tu cuoi ve : tmp
        while(tmp->next->next != NULL){
            tmp = tmp->next;
        }
        //Luu lai node cuoi de giai phong
        node *delNode = tmp->next;
        //Cho node tmp => NULL
        tmp->next = NULL;
        //Giai phong node cuoi
        delete delNode;
    }
}

```

#### g. Lấy kích thước của danh sách
```c
int size(node *array)
{
    int count = 0;
	while(array != NULL)
	{
		count++;
		array = array->next;
	}
	printf("\n so phan tu trong danh sach %d", count);
        return count;
}

```
#### h. Thêm 1 node vào vị trí bất kì của danh sách
```c

```
</p>
</details>

<details><summary>LESSON 11: STACK AND QUEUE</summary>
<p>
	
# STACK AND QUEUE

## 1. STACK

 ###   Stack là gì?

   Một ngăn xếp là một cấu trúc dữ liệu trừu tượng (Abstract Data Type – viết tắt là ADT), hầu như được sử dụng trong hầu hết mọi ngôn ngữ lập trình. Đặt tên là ngăn xếp bởi vì nó hoạt động như một ngăn xếp trong đời sống thực, ví dụ như một cỗ bài hay một chồng đĩa, …

  Trong đời sống thực, ngăn xếp chỉ cho phép các hoạt động tại vị trí trên cùng của ngăn xếp. Ví dụ, chúng ta chỉ có thể đặt hoặc thêm một lá bài hay một cái đĩa vào trên cùng của ngăn xếp. Do đó, cấu trúc dữ liệu trừu tượng ngăn xếp chỉ cho phép các thao tác dữ liệu tại vị trí trên cùng. Tại bất cứ thời điểm nào, chúng ta chỉ có thể truy cập phần tử trên cùng của ngăn xếp.

  Đặc điểm này làm cho ngăn xếp trở thành cấu trúc dữ liệu dạng `LIFO`. `LIFO` là viết tắt của `Last-In-First-Out`. Ở đây, phần tử được đặt vào (được chèn, được thêm vào) cuối cùng sẽ được truy cập đầu tiên. Trong thuật ngữ ngăn xếp, hoạt động chèn được gọi là hoạt động `PUSH` và hoạt động xóa được gọi là hoạt động `POP`.
  
  ![Screenshot 2024-03-26 225502](https://github.com/DangTruongBT/advance-C/assets/103482832/81a46976-880c-4714-8aa3-339ec22b8cc0)

Một ngăn xếp có thể được triển khai theo phương thức của Mảng (Array), Cấu trúc (Struct), Con trỏ (Pointer) và Danh sách liên kết (Linked List). Ngăn xếp có thể là ở dạng kích cỡ cố định hoặc ngăn xếp có thể thay đổi kích cỡ.

Bên dưới sẽ sẽ triển khai ngăn xếp bằng danh sách liên kết:

 ###  Các hoạt động cơ bản trên cấu trúc dữ liệu ngăn xếp

  - Push(): Đẩy 1 phần tử dữ liệu vào trong ngăn xếp

  - Pop(): Lấy 1 phần tử dữ liệu ra khỏi ngăn xếp

  - Top(): Lấy 1 phần tử trên cùng của ngăng xếp.

  - Is_Full(): Kiểm tra xem ngăn xếp đã đầy chưa

  - Is_Empty(): Kiểm tra xem ngăn xếp có trống hay không.
#### Định nghĩa 1 Stack

```c
typedef struct Stack {
    int* items; // mảng chứa các giá trị trong ngăn xếp
    int size;   // kích thước của mảng đó
    int top;   // giá trị của phần tử trên cùng
} Stack;
```
#### Hoạt động khởi tạo 1 ngăn xếp
```c
void initialize( Stack *stack, int size) {
    stack->items = (int*) malloc(sizeof(int) * size); //cấp phát động 1 mảng chứa các giá trị
    stack->size = size; // truyền vào kích thước mong muốn
    stack->top = -1; // gắn giá trị trên cùng bằng -1
}
```

#### Hoạt động Is_Full() trong cấu trúc dữ liệu ngăn xếp

```c
int Is_Full( Stack stack) {
    return stack.top == stack.size - 1;
}
```

#### Hoạt động Is_Empty() trong cấu trúc dữ liệu ngăn xếp

```c
int Is_Empty( Stack stack) {
    return stack.top == -1;
}
```

#### Hoạt động Push() trong cấu trúc dữ liệu ngăn xếp

```c
void Push( Stack *stack, int value) {
    if (!is_full(*stack)) {
        stack->items[++stack->top] = value;
    } else {
        printf("Stack overflow\n");
    }
}
```

</p>
</details>








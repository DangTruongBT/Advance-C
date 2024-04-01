# Bài Tập Lớn: Quản Lý Thông Tin Cư Dân Chung Cư

### Mục tiêu

Phát triển một chương trình bằng C để quản lý thông tin cư dân trong chung cư, bao gồm các chức năng cơ bản: thêm, xóa, chỉnh sửa và tìm kiếm thông tin cư dân. Chương trình này sẽ giúp quản lý cư dân một cách hiệu quả và chính xác, đảm bảo dữ liệu được cập nhật và truy xuất một cách nhanh chóng.

### Cấu Trúc Dữ Liệu

 - Member

    ```c
    Mô tả: Cấu trúc để lưu trữ thông tin cơ bản của cư dân.

    Trường thông tin: UID của RFID, số phòng, tên, biển số xe
    ```

    Ví dụ Code

   ```c
    typedef struct {
       char uid[20]; // UID của RFID
       char roomNumber[10]; // Số Phòng
       char name[50]; // Tên
       char licensePlate[20]; // Biển Số Xe
      } Member;

   
   ```

   MemberNode
   
   ```c
   Mô tả: Node trong linked list chứa thông tin Member.

   Trường thông tin: Dữ liệu Member, con trỏ đến MemberNode tiếp theo.
   ```

   Ví dụ Code

   ```c
   // Định nghĩa cấu trúc MemberNode
      typedef struct MemberNode {
          Member data;
          struct MemberNode* next;
      } MemberNode;
   ```

   
   

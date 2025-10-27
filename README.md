# **CHƯƠNG 1: C CƠ BẢN**
<details>
	<summary><strong>BÀI 1: BIẾN, KIỂU DỮ LIỆU</strong></summary>

## **BÀI 1: BIẾN, KIỂU DỮ LIỆU**

### **I. KIỂU DỮ LIỆU CƠ BẢN**

#### **1.1.Kiểu số nguyên (Integral Types)**

* **Mô tả:** Lưu trữ các số nguyên (không có phần thập phân).

* **Các kiểu:** 

  ◦ `short int:` Thường 2 byte, phạm vi: -32,768 đến 32,767 (cho kiểu có dấu).

  ◦ `int:` Thường 4 byte, phạm vi: -2,147,483,648 đến 2,147,483,647.

  ◦ `long int:` Thường 4 hoặc 8 byte, tùy hệ thống.

  ◦ `long long int:` Thường 8 byte, phạm vi: -2^63 đến 2^63-1.

* **Modifier:** 

  ◦ `signed`: Mặc định, lưu cả số âm và dương.

  ◦ `unsigned`: Chỉ lưu số không âm, tăng gấp đôi phạm vi dương (ví dụ: unsigned int: 0 đến 4,294,967,295).

  ◦ `size_t`: Kiểu không dấu, thường dùng để biểu diễn kích thước hoặc chỉ số (ví dụ: kích thước mảng, số byte). Kích thước phụ thuộc hệ thống (4 byte trên 32-bit, 8 byte trên 64-bit).

* **Phạm vi giá trị:** 

| Kiểu Dữ Liệu          | Kích thước (byte) | Phạm vi giá trị                                 |
|----------------------|------------------|-----------------------------------------------|
| signed char          | 1                | -128 đến 127                                 |
| unsigned char        | 1                | 0 đến 255                                    |
| short / short int    | 2                | -32,768 đến 32,767                           |
| unsigned short       | 2                | 0 đến 65,535                                 |
| int                  | 4                | -2,147,483,648 đến 2,147,483,647             |
| unsigned int         | 4                | 0 đến 4,294,967,295                          |
| long                 | 4 hoặc 8         | -2,147,483,648 đến 2,147,483,647 (32-bit)    |
| unsigned long        | 4 hoặc 8         | 0 đến 4,294,967,295 (32-bit)                 |
| long long            | 8                | -9,223,372,036,854,775,808 đến 9,223,372,036,854,775,807 |
| unsigned long long   | 8                | 0 đến 18,446,744,073,709,551,615             |

* **VD:** 

        #include <stdio.h>

        int main() {
            int age = 25;
            unsigned int count = 100;
            long long int bigNumber = 1234567890123LL; // LL để chỉ định kiểu long long
            size_t size = 1024; // Kiểu size_t cho kích thước
            printf("Age: %d\n", age);
            printf("Count: %u\n", count);
            printf("Big Number: %lld\n", bigNumber);
            printf("Size: %zu\n", size);
            return 0;
        }

#### **1.2.Kiểu số thực (Floating-Point Types)** 

* **Mô tả:** Lưu trữ số thực có phần thập phân.

* **Các kiểu:**

  ◦ `float:` Thường 4 byte, độ chính xác ~6-7 chữ số thập phân.

  ◦ `double:`Thường 8 byte, độ chính xác ~15-16 chữ số thập phân.

  ◦ `long double:` Kích thước và độ chính xác phụ thuộc vào hệ thống (thường ≥ double).

* **VD:** 

        float temperature = 36.6f; // f để chỉ định float
        double pi = 3.14159265359;
        long double bigNum = 1.23456789e308L; // L để chỉ định long double

#### **1.3.Kiểu ký tự (Character Type)** 

* **Mô tả:** Lưu trữ một ký tự đơn (ví dụ: 'A', '1', '@').

* **Các kiểu:**

  ◦ `char:` Lưu một ký tự (1 byte, thường mã ASCII), phạm vi -128 đến 127 hoặc 0 đến 255 (unsigned).


* **VD:** 

        char grade = 'A'; // Lưu ký tự ASCII
        unsigned char byte = 65; // Lưu giá trị số, tương ứng 'A'


#### **1.4.Kiểu logic (Boolean Type)**

* **Mô tả:** Lưu trữ giá trị logic `true` hoặc `false` , được định nghĩa trong thư viện `<stdbool.h>`.

* **Kích thước:** Thường 1 byte.
 
*  **VD:** 
  
        #include <stdio.h>
        #include <stdbool.h> // C99

        int main() {
            bool isStudent = true;
            bool isActive = false;
            printf("Is Student: %d\n", isStudent); // 1 cho true
            printf("Is Active: %d\n", isActive); // 0 cho false
            return 0;
        }

#### **1.5.Kiểu void**

* **Mô tả:** Không chứa giá trị, thường dùng cho hàm không trả về hoặc con trỏ tổng quát.

*  **VD:** 
  
        #include <stdio.h>

        void printMessage() {
            printf("Hello, World!\n");
        }

        int main() {
            printMessage();
            return 0;
        }

#### **1.6.Kiểu cố định (C99)**

* Được định nghĩa trong thư viện `<stdint.h>`

  ◦ `int8_t, int16_t, int32_t, int64_t:` Số nguyên có kích thước cố định.

  ◦ `uint8_t, uint16_t, uint32_t, uint64_t:` Số nguyên không dấu có kích thước cố định.

*  **VD:** 
  
        #include <stdio.h>
        #include <stdint.h> // C99

        int main() {
            int32_t fixedInt = 12345;
            uint64_t largeUnsigned = 9876543210ULL;
            printf("Fixed Int: %d\n", fixedInt);
            printf("Large Unsigned: %llu\n", largeUnsigned);
            return 0;
        }
    
#### **1.7. Lưu ý**

* **Kích thước kiểu dữ liệu:**

  ◦ Phụ thuộc vào kiến trúc hệ thống (32-bit hoặc 64-bit) và trình biên dịch

  ◦ Dùng `sizeof(type)` để kiểm tra

        #include <stdio.h>

        int main() {
            printf("Size of int: %zu bytes\n", sizeof(int));
            return 0;
        }

*  **Chọn kiểu phù hợp:** 
  
  ◦ Sử dụng `double` thay vì `float` cho các phép tính yêu cầu độ chính xác cao.

  ◦ Sử dụng `unsigned` khi chỉ cần lưu số không âm để tối ưu phạm vi.

  ◦ `char` có thể được dùng như số nguyên nhỏ (ví dụ: char x = 65; tương ứng với ký tự 'A').

*  **Giới hạn kiểu dữ liệu:** 
  
  ◦ Sử dụng `<limits>` để kiểm tra giới hạn của các kiểu số nguyên và `<float.h>` cho các kiểu số thực.

        #include <stdio.h>
        #include <limits.h>
        #include <float.h>

        int main() {
            printf("Max int: %d\n", INT_MAX);
            printf("Max double: %e\n", DBL_MAX);
            return 0;
        }


### **II.KHAI BÁO VÀ KHỞI TẠO BIẾN** 

#### **2.1.Lý thuyết**

* Biến là tên gọi cho một vùng bộ nhớ dùng để lưu trữ dữ liệu

* Biến phải được khai báo với kiểu dữ liệu trước khi sử dụng.

#### **2.2.Khai báo biến**

* Đặt tên và kiểu dữ liệu, nhưng không nhất thiết phải khởi tạo giá trị ban đầu.

* **Cú pháp:** `<kiểu_dữ_liệu> <tên_biến>;`

* **VD:** 

        int age;
        double salary;
        char grade;

#### **2.3.Khởi tạo biến**

* Các cách khởi tạo:

  ◦ Khởi tạo trực tiếp

        int age = 25;

  ◦ Khởi tạo nhiều biến

        int a, b = 5; // Chỉ b được khởi tạo
        int x = 1, y = 2, z = 3; // Khởi tạo nhiều biến cùng lúc

* VD:

        #include <stdio.h>

        int main() {
            int age = 25;
            double salary = 1000.5;
            char grade = 'A';
            printf("Age: %d, Salary: %.2f, Grade: %c\n", age, salary, grade);
            return 0;
        }


#### **2.4.Quy tắc đặt tên biến**

* Bắt đầu bằng chữ cái hoặc dấu gạch dưới `(_)`.

* Chỉ chứa chữ cái, số, hoặc dấu gạch dưới.

* Phân biệt chữ hoa và thường (`age` khác với `Age`).

* Tránh sử dụng từ khóa của C (như `int`, `if`, `return`).

* **VD hợp lệ:** `myVar`, `_count`, `studentName1`

* **VD không hợp lệ:** `2var`, `my-var`, `int`

#### **2.5.Lưu ý**

* **Biến không khởi tạo:** 

  ◦ Có thể chứa giá trị rác (undefined behavior)

  ◦ Luôn khởi tạo biến trước khi sử dụng

        #include <stdio.h>

        int main() {
            int x; // Giá trị rác
            int y = 0; // Khởi tạo an toàn
            printf("y: %d\n", y);
            // printf("x: %d\n", x); // Có thể gây lỗi
            return 0;
        }

* **Tối ưu hóa:** 

  ◦ Chọn kiểu dữ liệu phù hợp với nhu cầu để tiết kiệm bộ nhớ (ví dụ: dùng `short` thay vì `int` cho số nhỏ).

* **Khối lệnh:** 

        #include <stdio.h>

        int main() {
            {
                int temp = 10; // Chỉ tồn tại trong khối này
                printf("Temp: %d\n", temp);
            }
            // temp không còn tồn tại
            return 0;
        }

### **III. HẰNG SỐ** 

#### **3.1.Lý thuyết**

* Hằng số là các giá trị không thể thay đổi sau khi được khai báo, đảm bảo tính bất biến của dữ liệu.

#### **3.2.Hằng số với const**

* **Mô tả:** Định nghĩa hằng số tại thời điểm biên dịch, không thể thay đổi giá trị sau khi khởi tạo.

* **Cú pháp:** 

        const <kiểu_dữ_liệu> <tên_hằng> = <giá_trị>;

* **VD:** 

        #include <stdio.h>

        int main() {
            const int MAX_USERS = 100;
            const double PI = 3.14159265359;
            // MAX_USERS = 200; // Lỗi: không thể thay đổi
            printf("Max Users: %d\n", MAX_USERS);
            printf("PI: %.5f\n", PI);
            return 0;
        }

#### **3.3.Hằng số với #define**

* **Mô tả:** Định nghĩa hằng số bằng macro, thay thế trực tiếp trước khi biên dịch.

* **Cú pháp:** 

        #define <TÊN_HẰNG> <giá_trị>

* **VD:** 

        #include <stdio.h>
        #define MAX_SIZE 50

        int main() {
            printf("Max Size: %d\n", MAX_SIZE);
            return 0;
        }

#### **3.4.Lưu ý**

* **Quy ước đặt tên:** Hằng số thường được đặt tên bằng chữ in hoa (ví dụ: `MAX_USERS`, `PI`).

* **Ưu tiên const :** `const` đảm bảo an toàn kiểu dữ liệu, còn `#define` có thể gây lỗi nếu không cẩn thận (do thay thế văn bản trực tiếp).

* **Ứng dụng:** Hằng số giúp mã nguồn dễ bảo trì và tránh lỗi khi giá trị cố định được sử dụng nhiều lần.


### **IV.PHẠM VI BIẾN (SCOPE)**

#### **4.1.Biến cục bộ (Local Scope)**

  * **Mô tả:** Biến được khai báo trong một khối lệnh `{}` hoặc hàm, chỉ tồn tại trong phạm vi đó.

  * **VD:** 

        #include <stdio.h>

        void function() {
            int localVar = 10; // Biến cục bộ
            printf("Local Var: %d\n", localVar);
        } // localVar bị hủy khi thoát khỏi hàm

        int main() {
            function();
            return 0;
        }

#### **4.2.Biến toàn cục (Global Scope)**

  * **Mô tả:** Biến được khai báo ngoài mọi hàm, tồn tại suốt thời gian chương trình chạy.

  * **VD:** 

        #include <stdio.h>

        int globalVar = 100; // Biến toàn cục

        void function() {
            printf("Global Var: %d\n", globalVar); // Có thể truy cập từ bất kỳ đâu
        }

        int main() {
            function();
            return 0;
        }

#### **4.3.Biến tĩnh (Static Variables)**

  * **Mô tả:** Biến `static` giữ giá trị giữa các lần gọi hàm hoặc tồn tại suốt chương trình (nếu ở phạm vi global).

  * **Cú pháp:** 

        static <kiểu_dữ_liệu> <tên_biến>;

  * **VD:** 

        #include <stdio.h>

        void counter() {
            static int count = 0; // Biến tĩnh
            count++;
            printf("Count: %d\n", count);
        }

        int main() {
            counter(); // Count: 1
            counter(); // Count: 2
            return 0;
        }

#### **4.4.Shadowing**

  * **Mô tả:** Biến cục bộ trong khối lệnh hoặc hàm có cùng tên với biến ở phạm vi ngoài sẽ "che" (shadow) biến ngoài.

  * **VD:** 

        #include <stdio.h>

        int main() {
            int x = 10;
            {
                int x = 20; // Shadowing
                printf("Inner x: %d\n", x); // In: 20
            }
            printf("Outer x: %d\n", x); // In: 10
            return 0;
        }

#### **4.5. Lưu ý**

  * **Tránh lạm dụng biến toàn cục:** Dễ gây lỗi do khó theo dõi và xung đột tên.

  * **Sử dụng khối lệnh {}** để giới hạn phạm vi biến, giảm nguy cơ lỗi.

  * **Biến tĩnh:** Hữu ích cho việc đếm số lần gọi hàm hoặc lưu trạng thái.  


### **V.NHẬP/XUẤT DỮ LIỆU (INPUT/OUTPUT)**

* C sử dụng thư viện `<stdio.h>` để thực hiện các thao tác nhập/xuất dữ liệu.

#### **5.1.Xuất dữ liệu với printf**

  * **Mô tả:** Hàm `printf` dùng để hiển thị dữ liệu ra màn hình.

  * **Cú pháp:** 

        printf("<chuỗi_định_dạng>", <giá_trị>);

  * **Các ký hiệu định dạng phổ biến:** 

| Ký hiệu | Ý nghĩa               | Ví dụ                          |
|---------|----------------------|--------------------------------|
| `%d`    | Số nguyên (int)       | `printf("%d", 10);`           |
| `%u`    | Số nguyên không dấu   | `printf("%u", 10);`           |
| `%f`    | Số thực (float)       | `printf("%f", 3.14);`         |
| `%lf`   | Số thực (double)      | `printf("%lf", 3.14);`        |
| `%c`    | Ký tự                 | `printf("%c", 'A');`          |
| `%s`    | Chuỗi ký tự           | `printf("%s", "Hello");`      |
| `%p`    | Con trỏ (địa chỉ)     | `printf("%p", &var);`         |

  * **Điều khiển định dạng:** 

    ◦ `%.nf`: Đặt số chữ số thập phân (n là số).

    ◦ `%nd`: Đặt độ rộng trường hiển thị.

        #include <stdio.h>

        int main() {
            int age = 25;
            double salary = 1000.5;
            char grade = 'A';
            char name[] = "John";
            printf("Age: %d\n", age);
            printf("Salary: %.2f\n", salary); // In 2 chữ số thập phân
            printf("Grade: %c\n", grade);
            printf("Name: %s\n", name);
            printf("Right-aligned: %10d\n", age); // Căn phải, độ rộng 10
            return 0;
        }

#### **5.2.Nhập dữ liệu với scanf**

  * **Mô tả:** Hàm `scanf` dùng để nhập dữ liệu từ bàn phím

  * **Cú pháp:** 

        scanf("<chuỗi_định_dạng>", &<biến>);

  * **Ví dụ:** 

        #include <stdio.h>

        int main() {
            int age;
            double salary;
            char grade;
            printf("Enter your age: ");
            scanf("%d", &age);
            printf("Enter your salary: ");
            scanf("%lf", &salary);
            printf("Enter your grade: ");
            scanf(" %c", &grade); // Khoảng trắng để bỏ ký tự trắng
            printf("Age: %d, Salary: %.2f, Grade: %c\n", age, salary, grade);
            return 0;
        }

#### **5.3.Nhập chuỗi với fgets**

  * **Mô tả:** Nhập cả dòng, bao gồm dấu cách, sử dụng `fgets` từ `<stdio.h>` (an toàn hơn `gets`, vì `gets` không kiểm soát kích thước bộ đệm).

  * **Cú pháp:** `char *fgets(char *str, int n, FILE *stream);`

  * **VD:** 

        #include <stdio.h>

        int main() {
            char name[50];
            printf("Enter your name: ");
            fgets(name, sizeof(name), stdin);
            printf("Hello, %s", name);
            return 0;
        }

#### **5.4.Lưu ý**

  * **Định dạng scanf:** 

    ◦ Thêm khoảng trắng trước `%c` để bỏ qua ký tự trắng (như Enter).

    ◦ `%s` chỉ đọc chuỗi không chứa khoảng trắng. Để đọc chuỗi có khoảng trắng, sử dụng `fgets`

  * **Định dạng printf:** 

    ◦ Sử dụng đúng ký hiệu định dạng để tránh lỗi.

    ◦ Với `double`, sử dụng `%lf` trong `scanf` và `%f` hoặc `%.nf` trong `printf`.


 
 </details>

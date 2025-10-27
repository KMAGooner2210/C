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

<details>
	<summary><strong>BÀI 2: TOÁN TỬ VÀ BIỂU THỨC</strong></summary>

## **BÀI 2: TOÁN TỬ VÀ BIỂU THỨC**

### **I. TOÁN TỬ**

#### **1.1.Lý thuyết**

* Toán tử là các ký hiệu được sử dụng để thực hiện các phép toán trên các biến hoặc giá trị.

* C cung cấp nhiều loại toán tử, bao gồm số học, quan hệ, logic, bit, gán, điều kiện, sizeof và dấu phẩy.

#### **1.2.Toán tử số học (Arithmetic Operators)**

* **Mô tả:** Thực hiện các phép toán số học cơ bản trên các giá trị số nguyên hoặc số thực.

* **Các toán tử:**

| Toán Tử | Ý Nghĩa               | Ví Dụ            | Kết Quả            |
|---------|----------------------|------------------|-------------------|
| `+`     | Cộng                 | `5 + 3`          | `8`               |
| `-`     | Trừ                  | `5 - 3`          | `2`               |
| `*`     | Nhân                 | `5 * 3`          | `15`              |
| `/`     | Chia                 | `5 / 2`          | `2` (số nguyên)   |
| `%`     | Chia lấy dư      | `5 % 2`          | `1`               |
| `++`    | Tăng 1 (increment)   | `x++` hoặc `++x` | `x = x + 1`       |
| `--`    | Giảm 1 (decrement)   | `x--` hoặc `--x` | `x = x - 1`       |

* **Lưu ý:**

  ◦ Phép chia `/` giữa hai số nguyên cho kết quả số nguyên (phần thập phân bị bỏ).

  ◦ Phép chia `%` chỉ áp dụng cho các kiểu số nguyên.

  ◦ Toán tử `++` và `--` có hai dạng:

        Tiền tố (++x, --x): Tăng/giảm giá trị trước, sau đó sử dụng giá trị mới.

        Hậu tố (x++, x--): Sử dụng giá trị hiện tại, sau đó tăng/giảm

* **VD:**

        #include <stdio.h>

        int main() {
            int a = 5, b = 3;
            printf("Cộng: %d\n", a + b); // 8
            printf("Trừ: %d\n", a - b); // 2
            printf("Nhân: %d\n", a * b); // 15
            printf("Chia: %d\n", a / b); // 1
            printf("Chia lấy dư: %d\n", a % b); // 2
            printf("Tiền tố ++a: %d\n", ++a); // 6
            printf("Hậu tố b++: %d\n", b++); // 3
            printf("b sau khi tăng: %d\n", b); // 4
            return 0;
        }

#### **1.3.Toán tử quan hệ (Relational Operators)**

* **Mô tả:** So sánh hai giá trị và trả về giá trị logic (`1` cho `đúng`, `0` cho `sai`).

* **Các toán tử:**

| Toán Tử | Ý Nghĩa               | Ví Dụ            | Kết Quả            |
|---------|----------------------|------------------|-------------------|
| `==`     | Bằng                 | `5 == 3`          | `0`               |
| `!=`     | Không bằng                  | `5 != 3`          | `1`               |
| `>`     | Lớn hơn                 | `5 > 3`          | `1`              |
| `<`     | Nhỏ hơn                | `5 < 3`          | `0`  |
| `>=`     | Lớn hơn hoặc bằng      | `5 >= 3`          | `1`               |
| `<=`    | Nhỏ hơn hoặc bằng   | `5 <= 3` | `0`       |


* **VD:** 

        #include <stdio.h>

        int main() {
            int a = 5, b = 3;
            printf("a == b: %d\n", a == b); // 0
            printf("a != b: %d\n", a != b); // 1
            printf("a > b: %d\n", a > b); // 1
            printf("a < b: %d\n", a < b); // 0
            printf("a >= b: %d\n", a >= b); // 1
            printf("a <= b: %d\n", a <= b); // 0
            return 0;
        }

#### **1.4.Toán tử logic (Logical Operators)** 

* **Mô tả:** Thực hiện các phép toán logic trên các giá trị logic (true hoặc false, thường là 1 hoặc 0 trong C).

* **Các toán tử:**

| Toán Tử | Ý Nghĩa               | Ví Dụ            | Kết Quả            |
|---------|----------------------|------------------|-------------------|
| `&&`     | AND                 | `(5 > 3) && (3 > 1)`          | `1`               |
| `!`     | NOT (phủ định)              | `!(5 > 3)`          | `0`               |
| `\|\|`     | OR (hoặc)               | `(5 > 3) \|\| (3 < 1)`          | `1`              |

* **Lưu ý:**

  ◦ Trong C, bất kỳ giá trị khác 0 được coi là `true`, còn 0 là `false`.

  ◦ `&&` và `||` sử dụng đánh giá ngắn mạch (short-circuit evaluation):

        Với &&, nếu biểu thức bên trái là false, biểu thức bên phải không được đánh giá.

        Với ||, nếu biểu thức bên trái là true, biểu thức bên phải không được đánh giá.


* **VD:** 

        #include <stdio.h>

        int main() {
            int a = 5, b = 3, c = 0;
            printf("(a > b) && (b > c): %d\n", (a > b) && (b > c)); // 1
            printf("(a > b) || (b < c): %d\n", (a > b) || (b < c)); // 1
            printf("!(a > b): %d\n", !(a > b)); // 0
            return 0;
        }

#### **1.5.Toán tử Bit (Bitwise Operators)** 

* **Mô tả:** Thực hiện các phép toán trên từng bit của giá trị số nguyên.

* **Các toán tử:**

| Toán Tử | Ý Nghĩa               | Ví Dụ            | Kết Quả (Binary)        | Kết Quả (Decimal) |
|---------|----------------------|------------------|------------------------|------------------|
| `&`     | AND bit              | `5 & 3`          | `0001`                 | `1`              |
| `\|`    | OR bit               | `5 \| 3`         | `0111`                 | `7`              |
| `^`     | XOR bit              | `5 ^ 3`          | `0110`                 | `6`              |
| `~`     | NOT bit (phủ định)   | `~5`             | `...1010`              | Phụ thuộc hệ thống |
| `<<`    | Dịch trái            | `5 << 1`         | `1010`                 | `10`             |
| `>>`    | Dịch phải            | `5 >> 1`         | `0010`                 | `2`              |

* **Lưu ý:**

  ◦ `&, | , ^` thực hiện phép toán trên từng cặp bit tương ứng.

  ◦ `~` đảo ngược tất cả các bit (0 thành 1, 1 thành 0).

  ◦ `<<` dịch các bit sang trái, thêm 0 vào bên phải (tương đương nhân 2).

  ◦ `>>` dịch các bit sang phải, giữ dấu cho kiểu signed (thêm bit dấu vào bên trái).

* **VD:** 

        #include <stdio.h>

        int main() {
            int a = 5; // 0101
            int b = 3; // 0011
            printf("a & b: %d\n", a & b); // 0001 (1)
            printf("a | b: %d\n", a | b); // 0111 (7)
            printf("a ^ b: %d\n", a ^ b); // 0110 (6)
            printf("~a: %d\n", ~a); // ~0101 = ...1010
            printf("a << 1: %d\n", a << 1); // 1010 (10)
            printf("a >> 1: %d\n", a >> 1); // 0010 (2)
            return 0;
        }


#### **1.6.Toán tử gán (Assignment Operators)**

* **Mô tả:** Gán giá trị cho biến hoặc thực hiện phép toán kết hợp với gán.

* **Các toán tử:** 

| Toán Tử | Ý Nghĩa               | Ví Dụ          | Tương Đương       |
|---------|----------------------|----------------|------------------|
| `=`     | Gán giá trị          | `x = 5`        | `x = 5`          |
| `+=`    | Cộng và gán          | `x += 3`       | `x = x + 3`      |
| `-=`    | Trừ và gán           | `x -= 3`       | `x = x - 3`      |
| `*=`    | Nhân và gán          | `x *= 3`       | `x = x * 3`      |
| `/=`    | Chia và gán          | `x /= 3`       | `x = x / 3`      |
| `%=`    | Chia lấy nguyên và gán | `x %= 3`     | `x = x % 3`      |
| `&=`    | AND bit và gán       | `x &= 3`       | `x = x & 3`      |
| `\|=`   | OR bit và gán        | `x \|= 3`      | `x = x \| 3`     |
| `^=`    | XOR bit và gán       | `x ^= 3`       | `x = x ^ 3`      |
| `<<=`   | Dịch trái và gán     | `x <<= 1`      | `x = x << 1`     |
| `>>=`   | Dịch phải và gán     | `x >>= 1`      | `x = x >> 1`     |

*  **VD:** 
  
        #include <stdio.h>

        int main() {
            int x = 10;
            x += 5; // x = x + 5
            printf("x += 5: %d\n", x); // 15
            x *= 2; // x = x * 2
            printf("x *= 2: %d\n", x); // 30
            x &= 3; // x = x & 3
            printf("x &= 3: %d\n", x); // 2
            return 0;
        }

#### **1.7.Toán tử điều kiện Conditional Operator - Toán Tử 3 Ngôi)**

* **Mô tả:** Toán tử điều kiện `(?:)` là toán tử ba ngôi duy nhất trong C, thực hiện lựa chọn dựa trên điều kiện và trả về một trong hai giá trị.

* **Cú pháp:** `biểu_thức_điều_kiện ? giá_trị_nếu_đúng : giá_trị_nếu_sai;`

* **Lưu ý:** 

  ◦ Nếu `biểu_thức_điều_kiện` là `true` (khác 0), trả về `giá_trị_nếu_đúng`.

  ◦ Nếu `biểu_thức_điều_kiện` là `false` (0), trả về `giá_trị_nếu_sai`.

  ◦ Toán tử này thường được sử dụng để thay thế các câu lệnh `if-else` đơn giản.

*  **VD:** 
  
        #include <stdio.h>

        int main() {
            int a = 10, b = 5;
            int max = (a > b) ? a : b; // Nếu a > b, trả về a, ngược lại trả về b
            printf("Max of %d and %d is: %d\n", a, b, max); // 10

            int x = 0;
            printf("x is %s\n", x ? "non-zero" : "zero"); // zero
            return 0;
        }

#### **1.8.Toán tử Sizeof**

* **Mô tả:** Toán tử `sizeof` trả về kích thước (tính bằng byte) của một kiểu dữ liệu hoặc biến.

* **Cú pháp:** 

        sizeof(biến);
        sizeof(kiểu_dữ_liệu);

* **Lưu ý:** 

  ◦ Kết quả của `sizeof` có kiểu `size_t` (được định nghĩa trong `<stddef.h>` hoặc `<stdio.h>`).

  ◦ Thường được sử dụng để xác định kích thước bộ nhớ của biến, mảng, hoặc kiểu dữ liệu.

  ◦ Kích thước phụ thuộc vào hệ thống (32-bit hoặc 64-bit) và trình biên dịch.

*  **VD:** 
  
        #include <stdio.h>

        int main() {
            int x = 42;
            double d = 3.14;
            printf("Size of x: %zu bytes\n", sizeof(x)); // 4
            printf("Size of double: %zu bytes\n", sizeof(double)); // 8
            printf("Size of int: %zu bytes\n", sizeof(int)); // 4
            return 0;
        }

    
#### **1.9. Toán tử dấu phẩy (Comma Operator)**

* **Mô tả:**

  ◦ Toán tử dấu phẩy `(,)` cho phép thực hiện nhiều biểu thức trong một câu lệnh, trả về giá trị của biểu thức cuối cùng.

*  **Cú pháp:** 
  
        biểu_thức_1, biểu_thức_2, ..., biểu_thức_n;

*  **Lưu ý:** 

  ◦ Các biểu thức được đánh giá từ trái sang phải.

  ◦ Giá trị của toàn bộ biểu thức dấu phẩy là giá trị của biểu thức cuối cùng.

  ◦ Thường được sử dụng trong vòng lặp hoặc để gộp nhiều thao tác.

*  **VD:** 
  
        #include <stdio.h>

        int main() {
            int x = 10, y;
            y = (x++, x + 5); // x tăng lên 11, y nhận giá trị x + 5
            printf("x: %d, y: %d\n", x, y); // x: 11, y: 16

            // Dùng trong vòng lặp
            for (int i = 0, j = 10; i < 5; i++, j--) {
                printf("i: %d, j: %d\n", i, j);
            }
            return 0;
        }


### **II.BIỂU THỨC** 

#### **2.1.Lý thuyết**

* Biểu thức là sự kết hợp của các toán tử, biến, hằng số và giá trị để tạo ra một kết quả.

* Trong C, biểu thức có thể bao gồm các phép toán số học, quan hệ, logic, bit, gán, điều kiện, sizeof hoặc dấu phẩy.

#### **2.2.Ưu tiên toán tử (Operator Precedence)**

* **Mô tả:** Quy định thứ tự thực hiện các toán tử trong một biểu thức. Toán tử có độ ưu tiên cao được thực hiện trước.

* **Bảng ưu tiên toán tử (từ cao đến thấp):**

| Độ Ưu Tiên | Toán Tử                      | Ý Nghĩa                              |
|------------|------------------------------|--------------------------------------|
| 1          | `()`                         | Dấu ngoặc (thay đổi thứ tự)          |
| 2          | `++`, `--`, `!`, `~`, `(type)`, `sizeof` | Tăng, giảm, phủ định, type cast, sizeof |
| 3          | `*`, `/`, `%`                | Nhân, chia, chia lấy nguyên          |
| 4          | `+`, `-`                     | Cộng, trừ                            |
| 5          | `<<`, `>>`                   | Dịch bit trái, phải                  |
| 6          | `<`, `<=`, `>`, `>=`         | Quan hệ                              |
| 7          | `==`, `!=`                   | Bằng, không bằng                     |
| 8          | `&`                          | AND bit                              |
| 9          | `^`                          | XOR bit                              |
| 10         | `\|`                         | OR bit                               |
| 11         | `&&`                         | AND logic                            |
| 12         | `\|\|`                       | OR logic                             |
| 13         | `?:`                         | Toán tử điều kiện (3 ngôi)           |
| 14         | `=`, `+=`, `-=`, `*=`, `/=` etc. | Gán và gán kết hợp                |
| 15         | `,`                          | Dấu phẩy                            |

* **Lưu ý:** 

  ◦ Các toán tử cùng mức ưu tiên được thực hiện từ trái sang phải (trừ toán tử gán và dấu phẩy, từ phải sang trái).

  ◦ Sử dụng dấu ngoặc `()` để thay đổi thứ tự ưu tiên.

* **VD:** 

        #include <stdio.h>

        int main() {
            int x = 5 + 3 * 2; // * ưu tiên hơn +
            printf("x = 5 + 3 * 2: %d\n", x); // 11
            int y = (5 + 3) * 2; // () thay đổi thứ tự
            printf("y = (5 + 3) * 2: %d\n", y); // 16
            return 0;
        }

#### **2.3.Type Casting**

* **Mô tả:** Ép kiểu (type casting) là quá trình chuyển đổi một giá trị từ kiểu dữ liệu này sang kiểu dữ liệu khác.

* **Cú pháp:** `(kiểu_dữ_liệu) biểu_thức;`

* **Các loại ép kiểu:** 

  ◦ Ép kiểu ngầm (Implicit Casting): Tự động thực hiện bởi trình biên dịch khi các kiểu tương thích.

        Gán int cho double hoặc char cho int.

  ◦ Ép kiểu tường minh (Explicit Casting): Sử dụng toán tử (type) để chỉ định kiểu rõ ràng.


* VD:

        #include <stdio.h>

        int main() {
            double d = 3.14;
            int i = (int)d; // Ép kiểu tường minh
            printf("Double to int: %d\n", i); // 3

            int a = 5, b = 2;
            double result = (double)a / b; // Ép kiểu để giữ phần thập phân
            printf("Division with casting: %.2f\n", result); // 2.50

            char c = 'A';
            int ascii = c; // Ép kiểu ngầm
            printf("Char to int: %d\n", ascii); // 65
            return 0;
        }

* **Lưu ý:** 

  ◦ Ép kiểu từ kiểu lớn hơn (như `double`) sang kiểu nhỏ hơn (như `int`) có thể mất dữ liệu.

  ◦ Ép kiểu ngầm chỉ xảy ra khi không có nguy cơ mất dữ liệu đáng kể.


### **III. BIT MANIPULATION (THAO TÁC BIT)** 

#### **3.1.Lý thuyết**

* Thao tác bit cho phép làm việc trực tiếp trên các bit của giá trị số nguyên, thường được sử dụng để tối ưu hóa hoặc xử lý dữ liệu cấp thấp.

#### **3.2.Xoay bit (Bit Rotation)**

* **Mô tả:** Xoay bit không có toán tử trực tiếp trong C, nhưng có thể thực hiện bằng cách kết hợp dịch bit (`<<`, `>>`) và toán tử OR (`|`).


* **VD:Xoay trái 1 bit** 

        #include <stdio.h>

        unsigned int rotateLeft(unsigned int num, int n) {
            return (num << n) | (num >> (32 - n)); // Giả sử 32-bit
        }

        int main() {
            unsigned int x = 0x00000005; // 0000...0101
            unsigned int result = rotateLeft(x, 1); // Xoay trái 1 bit: 0000...1010
            printf("Rotate left: %u\n", result); // 10
            return 0;
        }

#### **3.3.Dịch Bit (Bit Shifting)**

* **Mô tả:** Dịch các bit sang trái (`<<`) hoặc phải (`>>`), thêm các bit 0 hoặc bit dấu (cho kiểu signed).

* **VD:** 

        #include <stdio.h>

        int main() {
            int a = 5; // 0101
            printf("a << 1: %d\n", a << 1); // 1010 (10)
            printf("a >> 1: %d\n", a >> 1); // 0010 (2)
            return 0;
        }

#### **3.4.Kiểm tra Bit**

* **Mô tả:** Kiểm tra trạng thái của một bit cụ thể (0 hoặc 1) bằng toán tử AND bit (`&`).

* **Cú pháp:** 

  ◦ Kiểm tra bit thứ `n`: `value & (1 << n)`

  ◦ Đặt bit thứ `n` thành 1: `value |= (1 << n)`

  ◦ Xóa bit thứ `n` (đặt thành 0): `value &= ~(1 << n)`

  ◦ Đảo bit thứ `n`: `value ^= (1 << n)`

* **VD:**

        #include <stdio.h>

        int main() {
            int value = 5; // 0101
            int bitPosition = 2; // Kiểm tra bit thứ 2 (tính từ 0)
            if (value & (1 << bitPosition)) {
                printf("Bit %d is 1\n", bitPosition);
            } else {
                printf("Bit %d is 0\n", bitPosition); // Bit 2 là 1
            }

            // Đặt bit thứ 1 thành 1
            value |= (1 << 1); // 0101 -> 0111 (7)
            printf("After setting bit 1: %d\n", value);

            // Xóa bit thứ 2
            value &= ~(1 << 2); // 0111 -> 0011 (3)
            printf("After clearing bit 2: %d\n", value);

            // Đảo bit thứ 0
            value ^= (1 << 0); // 0011 -> 0010 (2)
            printf("After toggling bit 0: %d\n", value);
            return 0;
        }



 </details>

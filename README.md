# **C_PROGRAMMING**
<details>
	<summary><strong>CHƯƠNG 1: BIẾN, KIỂU DỮ LIỆU & TOÁN TỬ</strong></summary>

## **CHƯƠNG 1: BIẾN, KIỂU DỮ LIỆU & TOÁN TỬ**

### **I. KIỂU DỮ LIỆU CƠ BẢN**

#### **1.1.Kiểu số nguyên (Integral Types)**

##### **1.1.1.Mô tả**

* Lưu trữ các số nguyên không có phần thập phân, có thể có dấu (signed) hoặc không dấu (unsigned).

##### **1.1.2.Kiểu cơ bản**


* **char:** 1 byte

  ◦ signed char: -128 đến 127

  ◦ unsigned char: 0 đến 255
            
    
        char c = 'A';           // 1 byte, giá trị ASCII
        signed char sc = -100;  // -128 đến 127
        unsigned char uc = 255; // 0 đến 255

        printf("%c %d %u\n", c, sc, uc);
      
    
* **short:** 2 bytes

  ◦ short int: -32,768 đến 32,767

  ◦ unsigned short: 0 đến 65,535

    
        short s = -30000;           // -32768 đến 32767
        unsigned short us = 60000;  // 0 đến 65535

        printf("%hd %hu\n", s, us);
    


* **int:** 4 bytes

  ◦ int: -2,147,483,648 đến 2,147,483,647

  ◦ unsigned int: 0 đến 4,294,967,295

    
        int i = -2000000000;
        unsigned int ui = 4000000000U;  // thêm U để tránh cảnh báo

        printf("%d %u\n", i, ui);
    


* **long:** 4 hoặc 8 bytes (phụ thuộc hệ thống)

  ◦ long int: -2,147,483,648 đến 2,147,483,647 (32-bit)

  ◦ unsigned long: 0 đến 4,294,967,295 (32-bit)

    
        long l = -2000000000L;           // thêm L
        unsigned long ul = 4000000000UL; // thêm UL

        printf("%ld %lu\n", l, ul);
    


* **long long:** 8 bytes (C99)

  ◦ long long int: -9,223,372,036,854,775,808 đến 9,223,372,036,854,775,807

  ◦ unsigned long long: 0 đến 18,446,744,073,709,551,615

    
        long long ll = -9000000000000000000LL;
        unsigned long long ull = 18000000000000000000ULL;

        printf("%lld %llu\n", ll, ull);
    


##### **1.1.3.Modifiers**

* **signed:**

  ◦ Mặc định cho hầu hết kiểu số nguyên

  ◦ Lưu cả số âm và dương

  ◦ Bit cao nhất (MSB) làm bit dấu (0: dương, 1: âm)

* **unsigned:**

  ◦ Chỉ lưu số không âm

  ◦ Tăng gấp đôi phạm vi số dương so với signed

  ◦ ất cả bit đều dùng cho giá trị

* **size_t:**

  ◦ Kiểu không dấu để biểu diễn kích thước

  ◦ Thường dùng cho: kích thước mảng, số phần tử, số byte

  ◦ Kích thước: 4 byte (32-bit) hoặc 8 byte (64-bit)


    
        char arr[] = "Xin chào";
        size_t size = sizeof(arr);     // kích thước mảng (byte)
        size_t len = strlen(arr);      // độ dài chuỗi

        printf("Size: %zu, Length: %zu\n", size, len);
    

##### **1.1.4.Phạm vi giá trị**

* **Bảng Tổng hợp Phạm vi Giá trị**

| Kiểu Dữ Liệu         | Kích thước     | Phạm vi giá trị                                      |
|----------------------|----------------|------------------------------------------------------|
| `signed char`        | 1 byte         | -128 đến 127                                         |
| `unsigned char`      | 1 byte         | 0 đến 255                                            |
| `short`              | 2 bytes        | -32,768 đến 32,767                                   |
| `unsigned short`     | 2 bytes        | 0 đến 65,535                                         |
| `int`                | 4 bytes        | -2,147,483,648 đến 2,147,483,647                     |
| `unsigned int`       | 4 bytes        | 0 đến 4,294,967,295                                  |
| `long`               | 4/8 bytes      | -2³¹ đến 2³¹-1 *(32-bit)*<br>-2⁶³ đến 2⁶³-1 *(64-bit)* |
| `unsigned long`      | 4/8 bytes      | 0 đến 2³²-1 *(32-bit)*<br>0 đến 2⁶⁴-1 *(64-bit)*      |
| `long long`          | 8 bytes        | -2⁶³ đến 2⁶³-1                                       |
| `unsigned long long` | 8 bytes        | 0 đến 2⁶⁴-1



#### **1.2.Kiểu số thực (Floating-Point Types)** 

#### **1.2.1.Mô tả** 

* Lưu trữ số thực có phần thập phân, biểu diễn theo chuẩn IEEE 754.

#### **1.2.2.Phân loại** 

* **float:** 

  ◦ Kích thước: 4 bytes (32 bits)

  ◦ Độ chính xác: ~6-7 chữ số thập phân

  ◦ Phạm vi: ±3.4×10³⁸

  ◦ Cấu trúc: 1 bit dấu, 8 bit exponent, 23 bit fraction

        float temp = 36.6f;  // hậu tố 'f' bắt buộc
        printf("float: %.2f\n", temp);

* **double:**

  ◦ Kích thước: 8 bytes (64 bits)

  ◦ Độ chính xác: ~15-16 chữ số thập phân

  ◦ Phạm vi: ±1.7×10³⁰⁸

  ◦ Cấu trúc: 1 bit dấu, 11 bit exponent, 52 bit fraction

        double pi = 3.14159265359;  // không cần hậu tố
        printf("double: %.12f\n", pi);

* **long double:** 

  ◦ Kích thước: thường 10, 12 hoặc 16 bytes

  ◦ Độ chính xác: ≥ double (phụ thuộc implementation)

  ◦ Phạm vi: rất lớn, phụ thuộc hệ thống

* **VD:** 

        long double e = 2.71828182845904523536L;  // hậu tố 'L'
        printf("long double: %.18Lf\n", e);

#### **1.2.3.Hậu tố chỉ định kiểu** 

* f hoặc F: float (36.6f)

* không hậu tố: double (3.14159)

* l hoặc L: long double (1.234L)

#### **1.3.Kiểu ký tự (Character Type)** 

##### **1.3.1.Mô tả** 

* Lưu trữ một ký tự đơn theo bảng mã ASCII hoặc các bảng mã ký tự khác.

##### **1.3.2.Đặc điểm**

* **char:** 

  ◦ Kích thước: 1 byte (8 bits)

  ◦ Mặc định: signed hoặc unsigned (phụ thuộc compiler)

  ◦ Phạm vi:

        signed char: -128 đến 127

        unsigned char: 0 đến 255

    ```
    #include <stdio.h>
    #include <limits.h>

    int main() {
        printf("Kich thuoc char: %zu byte\n", sizeof(char));
        printf("signed char : %d to %d\n", SCHAR_MIN, SCHAR_MAX);
        printf("unsigned char: 0 to %u\n", UCHAR_MAX);
        return 0;
    }

    Kich thuoc char: 1 byte
    signed char : -128 to 127
    unsigned char: 0 to 255
    ```

##### **1.3.3.Sử dụng**

* Lưu ký tự:

  ◦ Đặt trong dấu nháy đơn: 'A', '1', '@'

    ```
    char c1 = 'A';
    char c2 = '1';
    char c3 = '@';

    printf("Ky tu: %c, %c, %c\n", c1, c2, c3);

    Ky tu: A, 1, @
    ```

  ◦ Lưu mã ASCII của ký tự

    ```
    char ch = 'A';
    printf("Ma ASCII cua '%c' la: %d\n", ch, ch);

    Ma ASCII cua 'A' la: 65
    ```

* Lưu giá trị số:

  ◦ Có thể dùng như số nguyên 1 byte

  ◦ unsigned char: 0-255, signed char: -128-127

    ```
    signed char sc = -100;
    unsigned char uc = 200;

    printf("signed char  : %d\n", sc);
    printf("unsigned char: %u\n", uc);

    signed char  : -100
    unsigned char: 200
    ```

##### **1.3.4.Ký tự đặc biệt (Escape Sequences)**

* \n: newline

        printf("Dong 1\nDong 2\n");
        Dong 1
        Dong 2

* \t: tab

        printf("Ten\tTuoi\n");
        printf("An\t20\n");

        Ten     Tuoi
        An      20

* \': single quote

        printf("Ky tu: \'%c\'\n", 'A');

        Ky tu: 'A'

* \": double quote

        printf("Noi: \"Hello World!\"\n");

        Noi: "Hello World!"

* \\: backslash

        printf("Duong dan: C:\\\\folder\\\\file.txt\n");

        Duong dan: C:\folder\file.txt

* \0: null character

        char str[] = {'H', 'i', '\0', '!'};
        printf("Chuoi: %s\n", str);

        Chuoi: Hi

#### **1.4.Kiểu logic (Boolean Type)**

##### **1.4.1.Mô tả** 

* Lưu trữ giá trị logic `true` hoặc `false` , được định nghĩa trong thư viện `<stdbool.h>`.


##### **1.4.2.Lịch sử phát triển** 

* **Trước C99:**
 
  ◦ Dùng int: 0 (false), khác 0 (true)

  ◦ #define TRUE 1, #define FALSE 0

        #include <stdio.h>

        #define TRUE  1
        #define FALSE 0

        int main() {
            int is_valid = TRUE;
            int is_error = FALSE;

            if (is_valid) {
                printf("Trang thai: Hop le\n");
            }
            return 0;
        }

* **Từ C99:**
 
  ◦ _Bool: kiểu boolean nguyên thủy

        #include <stdio.h>

        int main() {
            _Bool flag = 1;  // 0 = false, khác 0 = true → tự động thành 1

            printf("_Bool flag = %d\n", flag); //_Bool flag = 1
            return 0;
        }

  ◦ bool, true, false: macro trong <stdbool.h>

        #include <stdio.h>
        #include <stdbool.h>  // Cần include

        int main() {
            bool active = true;
            bool stopped = false;

            printf("active = %d, stopped = %d\n", active, stopped); //active = 1, stopped = 0

            return 0;
        }


##### **1.4.3.Đặc điểm** 

* **_Bool:**
 
  ◦ Chỉ lưu 0 (false) hoặc 1 (true)

        _Bool b1 = 0;
        _Bool b2 = 100;     // tự động ép về 1
        _Bool b3 = -5;      // tự động ép về 1

        printf("b1 = %d, b2 = %d, b3 = %d\n", b1, b2, b3);//b1 = 0, b2 = 1, b3 = 1

  ◦ Kích thước: thường 1 byte

  ◦ Bất kỳ giá trị khác 0 đều chuyển thành 1

        #include <stdio.h>

        int main() {
            printf("Kich thuoc _Bool: %zu byte\n", sizeof(_Bool)); //Kich thuoc _Bool: 1 byte
            return 0;
        }



* **stdbool.h:**
 
  ◦ Định nghĩa: bool, true, false

  ◦ Tương thích ngược với code cũ

        #include <stdio.h>
        #include <stdbool.h>

        #define OLD_TRUE  1
        #define OLD_FALSE 0

        int main() {
            int old_style = OLD_TRUE;
            bool new_style = true;

            printf("old_style = %d, new_style = %d\n", old_style, new_style);//old_style = 1, new_style = 1
            return 0;
        }

#### **1.5.Kiểu void**

##### **1.5.1.Mô tả** 

* Không chứa giá trị, thường dùng cho hàm không trả về hoặc con trỏ tổng quát.

        // void: không có giá trị, không thể khai báo biến
        // void v;  // LỖI biên dịch!

##### **1.5.2.Sử dụng chính** 

* Hàm không trả về giá trị:
  
        #include <stdio.h>

        void say_hello() {
            printf("Xin chao!\n");  
            return;  // có thể bỏ qua
        }

        int main() {
            say_hello();  //Xin chao!
            return 0;
        }

* Con trỏ tổng quát (void*):
  
  ◦ Có thể trỏ đến bất kỳ kiểu dữ liệu nào

  ◦ Cần ép kiểu khi truy cập giá trị

        #include <stdio.h>

        int main() {
            int x = 100;
            float y = 3.14f;

            void* ptr;

            ptr = &x;  // trỏ đến int
            printf("Gia tri int: %d\n", *(int*)ptr);  //Gia tri int: 100

            ptr = &y;  // trỏ đến float
            printf("Gia tri float: %.2f\n", *(float*)ptr);  //Gia tri float: 3.14

            return 0;
        }

* Tham số hàm không có đối số:
  
  ◦ Có thể trỏ đến bất kỳ kiểu dữ liệu nào

  ◦ Cần ép kiểu khi truy cập giá trị

        #include <stdio.h>

        // Hàm không nhận tham số nào
        int get_status(void) {
            return 1;  // 1 = OK
        }

        int main() {
            if (get_status()) {
                printf("He thong hoat dong tot.\n");
            }
            return 0;
        }

        He thong hoat dong tot.

#### **1.6.Kiểu cố định (C99)**

##### **1.6.1.Mô tả**

* Cung cấp các kiểu số nguyên với kích thước cố định, không phụ thuộc platform.

##### **1.6.2.Lý do sử dụng**

* Portable code: kích thước nhất quán trên mọi platform

* Rõ ràng: biết chính xác kích thước kiểu dữ liệu

* Dùng trong embedded systems, network programming


##### **1.6.3.Các kiểu chính**

* **Số nguyên có dấu:**

  ◦ int8_t: chính xác 8 bits

        int8_t temp = -100;
        printf("int8_t: %d (size: %zu)\n", temp, sizeof(temp)); //int8_t: -100 (size: 1)

  ◦ int16_t: chính xác 16 bits

        int16_t value = -30000;
        printf("int16_t: %hd (size: %zu)\n", value, sizeof(value)); //int16_t: -30000 (size: 2)

  ◦ int32_t: chính xác 32 bits

        int32_t count = -2000000000;
        printf("int32_t: %d (size: %zu)\n", count, sizeof(count)); //int32_t: -2000000000 (size: 4)

  ◦ int64_t: chính xác 64 bits cố định.

        int64_t big = -9000000000000000000LL;
        printf("int64_t: %lld (size: %zu)\n", big, sizeof(big)); //int64_t: -9000000000000000000 (size: 8)

*  **Số nguyên không dấu:** 
  
    ◦ uint8_t: chính xác 8 bits

        uint8_t byte = 255;
        printf("uint8_t: %u (size: %zu)\n", byte, sizeof(byte)); //uint8_t: 255 (size: 1)

    ◦ uint16_t: chính xác 16 bits

        uint16_t port = 8080;
        printf("uint16_t: %u (size: %zu)\n", port, sizeof(port));  //uint16_t: 8080 (size: 2)

    ◦ uint32_t: chính xác 32 bits

        uint32_t ip = 3232235777U;  // 192.168.1.1
        printf("uint32_t: %u (size: %zu)\n", ip, sizeof(ip));  //uint32_t: 3232235777 (size: 4)

    ◦ uint64_t: chính xác 64 bits

        uint64_t id = 18446744073709551615ULL;
        printf("uint64_t: %llu (size: %zu)\n", id, sizeof(id)); //uint64_t: 18446744073709551615 (size: 8)

*  **Kiểu nhanh (fast):** 
  
    ◦ int_fast8_t, uint_fast8_t: nhanh nhất ít nhất 8 bits

    ◦ Tối ưu 

        int_fast8_t  fast_s = -50;
        uint_fast8_t fast_u = 200;

        printf("int_fast8_t : %d (size: %zu)\n", fast_s, sizeof(fast_s));
        printf("uint_fast8_t: %u (size: %zu)\n", fast_u, sizeof(fast_u));

        int_fast8_t : -50 (size: 4)   ← thường là int (nhanh hơn char)
        uint_fast8_t: 200 (size: 4)

*  **Kiểu nhỏ nhất (least):** 
  
    ◦ int_least8_t, uint_least8_t: nhỏ nhất ít nhất 8 bits

    ◦ Tối ưu cho memory usage

        int_least8_t  least_s = -120;
        uint_least8_t least_u = 250;

        printf("int_least8_t : %d (size: %zu)\n", least_s, sizeof(least_s));
        printf("uint_least8_t: %u (size: %zu)\n", least_u, sizeof(least_u));

        int_least8_t : -120 (size: 1)
        uint_least8_t: 250 (size: 1)

##### **1.6.4.Hậu tố chỉ định kiểu**

* **U: unsigned (100U)**

* **L: long (100L)**

* **LL: long long (100LL)**

* **ULL: unsigned long long (100ULL)**


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

#### **1.8. Giới hạn kiểu dữ liệu**

##### **1.8.1.<limits.h>**

* Sử dụng `<limits.h>` để kiểm tra giới hạn của các kiểu số nguyên 

* **Bảng các macro quan trọng**

| Macro         | Mô tả                                      | Giá trị điển hình (64-bit)              |
|---------------|--------------------------------------------|-----------------------------------------|
| `CHAR_BIT`    | Số bit trong 1 byte                        | `8`                                     |
| `SCHAR_MIN`   | Nhỏ nhất `signed char`                     | `-128`                                  |
| `SCHAR_MAX`   | Lớn nhất `signed char`                     | `127`                                   |
| `UCHAR_MAX`   | Lớn nhất `unsigned char`                   | `255`                                   |
| `CHAR_MIN`    | Nhỏ nhất `char` (phụ thuộc signed/unsigned)| `-128` hoặc `0`                         |
| `CHAR_MAX`    | Lớn nhất `char`                            | `127` hoặc `255`                        |
| `SHRT_MIN`    | Nhỏ nhất `short`                           | `-32768`                                |
| `SHRT_MAX`    | Lớn nhất `short`                           | `32767`                                 |
| `USHRT_MAX`   | Lớn nhất `unsigned short`                  | `65535`                                 |
| `INT_MIN`     | Nhỏ nhất `int`                             | `-2147483648`                           |
| `INT_MAX`     | Lớn nhất `int`                             | `2147483647`                            |
| `UINT_MAX`    | Lớn nhất `unsigned int`                    | `4294967295`                            |
| `LONG_MIN`    | Nhỏ nhất `long`                            | `-9223372036854775808` *(64-bit)*       |
| `LONG_MAX`    | Lớn nhất `long`                            | `9223372036854775807`                   |
| `ULONG_MAX`   | Lớn nhất `unsigned long`                   | `18446744073709551615`                  |
| `LLONG_MIN`   | Nhỏ nhất `long long`                       | `-9223372036854775808`                  |
| `LLONG_MAX`   | Lớn nhất `long long`                       | `9223372036854775807`                   |
| `ULLONG_MAX`  | Lớn nhất `unsigned long long`              | `18446744073709551615`                  |

##### **1.8.2.<float.h>**

* Sử dụng `<float.h>` để kiểm tra giới hạn của số thực

* **Bảng các macro quan trọng**

| Macro             | Mô tả                                              | Giá trị điển hình (IEEE 754)             |
|-------------------|----------------------------------------------------|------------------------------------------|
| `FLT_RADIX`       | Cơ số hệ thống (thập phân của mantissa)            | `2`                                      |
| `FLT_MANT_DIG`    | Số bit trong phần mantissa của `float`             | `24`                                     |
| `DBL_MANT_DIG`    | Số bit trong phần mantissa của `double`            | `53`                                     |
| `LDBL_MANT_DIG`   | Số bit trong phần mantissa của `long double`       | `64` *(80-bit x86)* hoặc `113` *(128-bit)* |
| `FLT_DIG`         | Số chữ số thập phân chính xác của `float`          | `6`                                      |
| `DBL_DIG`         | Số chữ số thập phân chính xác của `double`         | `15`                                     |
| `LDBL_DIG`        | Số chữ số thập phân chính xác của `long double`    | `18` *(80-bit)*                          |
| `FLT_MIN_EXP`     | Exponent nhỏ nhất (trước khi chuẩn hóa) `float`    | `-125`                                   |
| `DBL_MIN_EXP`     | Exponent nhỏ nhất `double`                         | `-1021`                                  |
| `FLT_MAX_EXP`     | Exponent lớn nhất `float`                          | `128`                                    |
| `DBL_MAX_EXP`     | Exponent lớn nhất `double`                         | `1024`                                   |
| `FLT_MIN`         | Giá trị dương nhỏ nhất `float` (chuẩn hóa)         | `1.17549e-38`                            |
| `FLT_MAX`         | Giá trị lớn nhất `float`                           | `3.40282e+38`                            |
| `DBL_MIN`         | Giá trị dương nhỏ nhất `double`                    | `2.22507e-308`                           |
| `DBL_MAX`         | Giá trị lớn nhất `double`                          | `1.79769e+308`                           |
| `LDBL_MIN`        | Giá trị dương nhỏ nhất `long double`               | `3.36210e-4932` *(80-bit)*               |
| `LDBL_MAX`        | Giá trị lớn nhất `long double`                     | `1.18973e+4932` *(80-bit)*               |
| `FLT_EPSILON`     | `ε` nhỏ nhất sao cho `1.0f + ε ≠ 1.0f`              | `1.19209290e-07`                         |
| `DBL_EPSILON`     | `ε` nhỏ nhất sao cho `1.0 + ε ≠ 1.0`                | `2.2204460492503131e-16`                 |


### **II.KHAI BÁO VÀ KHỞI TẠO BIẾN** 

#### **2.1.Quy tắc đặt tên biến**

##### **2.1.1.Quy tắc cơ bản**

* Bắt đầu bằng chữ cái (a-z, A-Z) hoặc dấu gạch dưới _

        int age = 25;        // Hợp lệ
        int _count = 10;     // Hợp lệ
        // int 1st = 1;      // LỖI: không bắt đầu bằng chữ/số

* Chỉ chứa chữ cái, số (0-9), hoặc dấu gạch dưới _

        int user_id = 100;
        int totalScore = 95;
        // int my-var = 5;   // LỖI: có dấu gạch ngang
        // int @rate = 2;    // LỖI: ký tự đặc biệt

* Phân biệt chữ hoa và thường (age ≠ Age ≠ AGE)

        int Age = 30;
        int age = 20;
        int AGE = 40;

        printf("%d %d %d\n", Age, age, AGE);  // In: 30 20 40

* Độ dài: Không giới hạn, nhưng nên từ 3-30 ký tự

        int n = 5;                    // Tốt: ngắn gọn
        int studentCount = 120;       // Tốt: rõ nghĩa
        // int a = 1;                 // Tránh: không rõ nghĩa
        // int thisIsAVeryVeryVeryLongVariableNameThatNoOneWantsToRead = 10; // Tránh

* Tránh từ khóa của C (int, if, return, while, for...)

        int return_value = 0;     // Hợp lệ (không phải từ khóa khi dùng làm tên)
        int for_loop = 1;         // Hợp lệ
        // int int = 5;           // LỖI: trùng từ khóa
        // int while = 3;         // LỖI

##### **2.1.2.Các chuẩn đặt tên phổ biến**

* snake_case (thường dùng trong C):

        int student_age;
        float average_score;
        char first_name[50];
        const int MAX_BUFFER_SIZE = 1024;

* camelCase (phổ biến trong C++/Java):

        int studentAge;
        float averageScore;
        char firstName[50];
        const int maxBufferSize = 1024;

* PascalCase (cho kiểu dữ liệu, struct):

        typedef struct StudentInfo {
            char name[50];
            int age;
        } StudentInfo;

        enum ColorType {
            RED,
            GREEN,
            BLUE
        };

* UPPER_CASE (cho hằng số, macro):

        #define MAX_STUDENTS 100
        const double PI = 3.14159;
        const int MAX_BUFFER = 1024;

##### **2.1.3.Quy ước đặt tên theo ngữ cảnh**

* Biến cục bộ:

        int i, j, k;          // Chỉ số vòng lặp
        int n, cnt;           // Số lượng, bộ đếm
        float x, y, z;        // Tọa độ, giá trị tạm

* Biến toàn cục:

        int g_total_students;     // Tiền tố 'g_' cho global
        float g_average_score;
        static int s_instance_count; // Tiền tố 's_' cho static

* Con trỏ (tiền tố 'p_' hoặc hậu tố '_ptr'):

        int *p_data;
        char *name_ptr;
        FILE *file_pointer;

#### **2.2.Phạm vi biến (Variable Scope)**

##### **2.2.1.Biến cục bộ (Local Variables)**

* Đặc điểm:

  ◦ Khai báo bên trong hàm hoặc khối code {}

  ◦ Chỉ tồn tại và truy cập được trong khối đó

  ◦ Tự động hủy khi ra khỏi khối

  ◦ Không tự động khởi tạo (chứa giá trị rác)

        #include <stdio.h>

        void example_function() {
            int local_var = 10;           // Biến cục bộ của hàm
            printf("Local var: %d\n", local_var);
            
            {
                int block_var = 20;       // Biến cục bộ của khối
                printf("Block var: %d\n", block_var);
                printf("Local var in block: %d\n", local_var); // ✅ Truy cập được
            }
            
            // printf("Block var: %d\n", block_var); // ❌ LỖI: Không truy cập được
        }

        int main() {
            example_function();
            // printf("Local var: %d\n", local_var); // ❌ LỖI: Không truy cập được
            return 0;
        }


##### **2.2.2.Biến toàn cục (Global Variables)**

* Đặc điểm:

  ◦ Khai báo bên ngoài tất cả hàm

  ◦ Truy cập được từ mọi hàm trong file

  ◦ Tồn tại suốt chương trình

  ◦ Tự động khởi tạo về 0

        #include <stdio.h>

        // Biến toàn cục
        int global_counter = 0;           
        const double PI = 3.14159;
        char global_buffer[100];

        void increment_counter() {
            global_counter++;             // ✅ Truy cập được
            printf("Counter in function: %d\n", global_counter);
        }

        void process_data() {
            global_counter += 10;         // ✅ Truy cập được
            printf("Counter in another function: %d\n", global_counter);
        }

        int main() {
            printf("Initial counter: %d\n", global_counter);
            increment_counter();
            process_data();
            printf("Final counter: %d\n", global_counter);
            return 0;
        }

##### **2.2.3.Variable Shadowing**

        #include <stdio.h>

        int global_var = 100;             // Biến toàn cục

        void shadow_example() {
            int global_var = 50;          // ❌ Che lấp biến toàn cục
            printf("Local var: %d\n", global_var); // 50
            
            {
                int global_var = 25;      // Che lấp biến cục bộ
                printf("Block var: %d\n", global_var); // 25
            }
            
            printf("Local var again: %d\n", global_var); // 50
        }

        // Truy cập biến toàn cục bị che lấp
        void access_global() {
            extern int global_var;        // Khai báo extern để truy cập global
            printf("Global var: %d\n", global_var); // 100
        }

        int main() {
            shadow_example();
            access_global();
            return 0;
        }


#### **2.3.Storage Classes**

##### **2.3.1.Tổng quan**

* Storage Class xác định phạm vi (scope), thời gian sống (lifetime) và vị trí lưu trữ (storage location) của biến

* **Các loại Storage Classes:**

  ◦ auto - Tự động (mặc định)

  ◦ register - Thanh ghi

  ◦ static - Tĩnh

  ◦ extern - Ngoại

##### **2.3.2.auto**

* **Cú pháp:**

        auto data_type variable_name;
        // hoặc (thường dùng)
        data_type variable_name;

        VD:
        auto int x = 10;        // Rõ ràng
        int y = 20;             // Tương đương (auto mặc định)

* **Đặc điểm:**

  ◦ Mặc định cho tất cả biến cục bộ

        #include <stdio.h>

        void test() {
            auto int local = 100;   // auto = mặc định
            int local2 = 200;       // giống nhau
            printf("local = %d, local2 = %d\n", local, local2);
        }

  ◦ Phạm vi: Cục bộ (trong hàm/khối)

        #include <stdio.h>

        int main() {
            {
                auto int inside = 99;
                printf("Inside block: %d\n", inside);
            }
            // printf("%d", inside);  // LỖI: ngoài phạm vi
            return 0;
        }

        Inside block: 99

  ◦ Thời gian sống: Từ khi vào khối đến khi ra khối

        #include <stdio.h>

        void counter() {
            auto int count = 0;  // Tạo mới mỗi lần gọi
            count++;
            printf("Count: %d\n", count);
        }

        int main() {
            counter();  // Count: 1
            counter();  // Count: 1 (không giữ giá trị)
            counter();  // Count: 1
            return 0;
        }

        Count: 1
        Count: 1
        Count: 1

  ◦ Vị trí lưu trữ: Bộ nhớ stack

        #include <stdio.h>

        int main() {
            auto int a = 50;
            printf("Dia chi a: %p\n", (void*)&a);  // Địa chỉ trên stack
            return 0;
        }

        Dia chi a: 0x7fff5fbff6ac

  ◦ Khởi tạo: Không tự động (chứa giá trị rác)

        #include <stdio.h>

        void demo() {
            auto int x;           // Không khởi tạo → rác
            printf("Gia tri rac: %d\n", x);  // Kết quả không xác định!
        }

        int main() {
            demo();
            return 0;
        }

* **Lưu ý:**

  ◦ Từ khóa auto thường được bỏ qua

  ◦ Biến được tạo khi vào khối, hủy khi ra khối

  ◦ Mỗi lần gọi hàm sẽ tạo biến mới

        #include <stdio.h>

        int* get_auto_address() {
            auto int temp = 999;
            return &temp;  // NGUY HIỂM: trả về địa chỉ biến đã hủy!
        }

        int main() {
            int* ptr = get_auto_address();
            printf("*ptr = %d\n", *ptr);  // Hành vi không xác định!
            return 0;
        }



##### **2.3.3.register**

* **Cú pháp:**

        register data_type variable_name;

        VD:

        register int i = 0;
        register float counter = 0.0f;

* **Đặc điểm:**

  ◦ Phạm vi: Cục bộ (trong hàm/khối)

        #include <stdio.h>

        void loop() {
            register int i;  // Chỉ tồn tại trong hàm
            for (i = 0; i < 3; i++) {
                printf("i = %d\n", i);
            }
        }

  ◦ Thời gian sống: Từ khi vào khối đến khi ra khối

        #include <stdio.h>

        void test() {
            register int count = 100;
            count++;
            printf("count = %d\n", count);  // 101
        }

        int main() {
            test();  // 101
            test();  // 101 → tạo mới mỗi lần
            return 0;
        }


        count = 101
        count = 101

  ◦ Vị trí lưu trữ: Thanh ghi CPU (nếu có thể)

        #include <stdio.h>

        void fast_loop() {
            register int i;
            register int sum = 0;
            for (i = 0; i < 1000000; i++) {
                sum += i;  // Biến lặp → gợi ý lưu vào thanh ghi
            }
            printf("sum = %d\n", sum);
        }

  ◦ Khởi tạo: Không tự động

        register int x;       // Chứa giá trị rác!
        x = 10;               // Phải gán trước khi dùng
        printf("x = %d\n", x);

* **Lưu ý:**

  ◦ Là gợi ý cho compiler, không phải mệnh lệnh

  ◦ Không thể lấy địa chỉ (không dùng được với &)

        #include <stdio.h>

        int main() {
            register int value = 42;
            // printf("Address: %p\n", &value);  // LỖI BIÊN DỊCH!
            printf("value = %d\n", value);
            return 0;
        }

  ◦ Tốt cho biến được truy cập thường xuyên

        #include <stdio.h>

        int fibonacci(int n) {
            if (n <= 1) return n;
            
            register int a = 0, b = 1, temp;  // a, b truy cập liên tục
            for (register int i = 2; i <= n; i++) {
                temp = a + b;
                a = b;
                b = temp;
            }
            return b;
        }

  ◦ Compiler có thể bỏ qua gợi ý nếu không có thanh ghi trống

        // Nếu không đủ thanh ghi → compiler lưu vào stack như auto
        register int too_many_vars[100];  // Quá lớn → không thể vào thanh ghi

  ◦ Kích thước biến phải nhỏ hơn hoặc bằng kích thước thanh ghi

        register char c;      // OK: 1 byte
        register int i;       // OK: 4/8 bytes
        // register double d; // Có thể bị bỏ qua (8 bytes)


##### **2.3.4.Local static**

* **Cú pháp:**

        static data_type variable_name;


        VD:
        static int counter = 0;
        static float total = 0.0f;

* **Đặc điểm:**

  ◦ Phạm vi: Cục bộ (trong hàm/khối)

        #include <stdio.h>

        void demo() {
            static int local_static = 100;  // Chỉ thấy trong hàm
            printf("local_static = %d\n", local_static);
        }

        int main() {
            demo();  // OK
            // printf("%d", local_static);  // LỖI: ngoài phạm vi
            return 0;
        }

  ◦ Thời gian sống: Từ khi vào khối đến khi ra khối

        #include <stdio.h>

        void count_calls() {
            static int count = 0;  // Tồn tại suốt chương trình
            count++;
            printf("Ham da goi: %d lan\n", count);
        }

        int main() {
            count_calls();  // 1
            count_calls();  // 2
            count_calls();  // 3
            return 0;
        }


        Ham da goi: 1 lan
        Ham da goi: 2 lan
        Ham da goi: 3 lan

  ◦ Vị trí lưu trữ: Data segment

        #include <stdio.h>

        void show_address() {
            static int value = 999;
            printf("Dia chi static: %p\n", (void*)&value);
        }

        int main() {
            show_address();
            show_address();  // Cùng địa chỉ
            return 0;
        }


        Dia chi static: 0x404000
        Dia chi static: 0x404000

  ◦ Khởi tạo: Tự động = 0 (một lần duy nhất)

        #include <stdio.h>

        void test_init() {
            static int x;           // Tự động = 0
            static int y = 50;      // Chỉ gán 1 lần
            printf("x = %d, y = %d\n", x, y);
            x++;
            y++;
        }

        int main() {
            test_init();  // x = 0, y = 50
            test_init();  // x = 1, y = 51 → x tăng, y vẫn tăng
            return 0;
        }

        x = 0, y = 50
        x = 1, y = 51

* **Lưu ý:**

  ◦ Giữ giá trị giữa các lần gọi hàm

        #include <stdio.h>

        int get_next_id() {
            static int id = 1000;  // Giữ giá trị
            return ++id;
        }

        int main() {
            printf("ID: %d\n", get_next_id());  // 1001
            printf("ID: %d\n", get_next_id());  // 1002
            printf("ID: %d\n", get_next_id());  // 1003
            return 0;
        }

        ID: 1001
        ID: 1002
        ID: 1003

  ◦ Chỉ được khởi tạo một lần duy nhất

        #include <stdio.h>

        int init_once() {
            static int initialized = 0;
            if (initialized == 0) {
                printf("Khoi tao lan dau!\n");
                initialized = 1;
            } else {
                printf("Da khoi tao truoc do.\n");
            }
            return initialized;
        }

        int main() {
            init_once();  // Khởi tạo lần đầu!
            init_once();  // Đã khởi tạo trước đó.
            return 0;
        }

        Khoi tao lan dau!
        Da khoi tao truoc do.

  ◦ Tồn tại suốt chương trình nhưng chỉ visible trong hàm

        #include <stdio.h>

        void secret() {
            static int password = 123456;
            printf("Mat khau bi mat: %d\n", password);
        }

        int main() {
            secret();  // OK
            // password = 0;  // LỖI: không thấy được
            return 0;
        }

##### **2.3.5.Global Static**

* **Cú pháp:**

        static data_type variable_name;

        VD:
        static int file_counter = 0;        // Biến toàn cục static
        static void helper_function();     // Hàm static

* **Đặc điểm:**

  ◦ Phạm vi: File (chỉ visible trong file hiện tại)

        // file: module.c
        static int secret_data = 999;  // Chỉ dùng trong file này

        void public_func() {
            printf("Secret: %d\n", secret_data);
        }  

        secret_data không thể truy cập từ file khác.

  ◦ Thời gian sống: Toàn bộ chương trình

        // module.c
        static int init_count = 0;

        void track_init() {
            init_count++;
            printf("Khoi tao lan %d\n", init_count);
        }


  ◦ Vị trí lưu trữ: Bộ nhớ data segment

        // module.c
        static long long big_value = 1234567890123LL;

        void show_address() {
            printf("Dia chi static global: %p\n", (void*)&big_value);
        }


        Dia chi static global: 0x404010 → data segment

  ◦ Khởi tạo: Tự động = 0 

        // module.c
        static int x;        // Tự động = 0
        static float y;      // Tự động = 0.0f

        void test() {
            printf("x = %d, y = %.1f\n", x, y);  // 0, 0.0
        }

* **Lưu ý:**

  ◦ Ngăn không cho các file khác truy cập biến/hàm

        //file module.c
        static int private_var = 100;  // Không thể truy cập từ ngoài

        int get_private() {
            return private_var;
        }

        void set_private(int v) {
            private_var = v;
        }

        //file main.c
        #include <stdio.h>

        extern int get_private();
        extern void set_private(int);

        int main() {
            printf("Gia tri: %d\n", get_private());  // OK: 100
            set_private(500);
            printf("Sau thay doi: %d\n", get_private());  // 500
            // private_var = 10;  // LỖI: không thấy được!
            return 0;
        }

  ◦ Dùng cho biến/hàm "private" của file

        //file utils.c

        static void internal_log(const char* msg) {
            printf("[LOG] %s\n", msg);
        }

        void public_api() {
            internal_log("API duoc goi");  // OK
        }

        //file main.c
        
        extern void public_api();

        int main() {
            public_api();  // OK
            // internal_log("test");  // LỖI: không thấy hàm!
            return 0;
        }

        Kết quả: [LOG] API duoc goi

  ◦ Tồn tại suốt chương trình nhưng chỉ visible trong hàm

        #include <stdio.h>

        void secret() {
            static int password = 123456;
            printf("Mat khau bi mat: %d\n", password);
        }

        int main() {
            secret();  // OK
            // password = 0;  // LỖI: không thấy được
            return 0;
        }

##### **2.3.6.extern**

* **Cú pháp:**

        extern data_type variable_name;

        VD:
        extern int global_counter;
        extern void init_system();

* **Đặc điểm:**

  ◦ Phạm vi: Toàn cục (nhiều file)

        // file1.c
        extern int shared_value;  // Có thể dùng ở nhiều file

  ◦ Thời gian sống: Toàn bộ chương trình

        // Biến extern tồn tại từ lúc chương trình chạy đến khi kết thúc


  ◦ Vị trí lưu trữ: Bộ nhớ data segment

        // Cùng vùng nhớ với biến toàn cục static


  ◦ Khởi tạo: Phải được định nghĩa ở file khác

* **Lưu ý:**

  ◦ Chỉ là khai báo, không phải định nghĩa

        // file: utils.h
        extern int config_mode;     // KHAI BÁO (không tạo biến)

  ◦ Dùng để chia sẻ biến/hàm giữa các file



        //file shared.c

        int request_count = 0;  // Định nghĩa

        //file api.c
        
        extern int request_count;

        void handle_request() {
            request_count++;
        }

        //file main.c
        
        #include <stdio.h>
        extern int request_count;
        extern void handle_request();

        int main() {
            handle_request();
            handle_request();
            printf("So request: %d\n", request_count);  // 2
            return 0;
        }       

  ◦ Biến phải được định nghĩa (cấp phát bộ nhớ) ở một file

        //file config.c

        #include "utils.h"

        int config_mode = 1;  // ĐỊNH NGHĨA: cấp phát bộ nhớ

        //file main.c– Dùng extern để truy cập

        #include <stdio.h>
        #include "utils.h"

        extern int config_mode;  // KHAI BÁO: dùng biến đã định nghĩa ở nơi khác

        int main() {
            printf("Che do: %d\n", config_mode);
            config_mode = 2;
            printf("Da thay doi: %d\n", config_mode);
            return 0;
        }

        Che do: 1
        Da thay doi: 2

* **Lỗi phổ biến:**

  ◦ Chỉ khai báo, không định nghĩa

        // main.c
        extern int missing_var;
        printf("%d", missing_var);  // Lỗi linker: undefined reference

  ◦ Định nghĩa nhiều lần

        // file1.c
        int value = 10;

        // file2.c
        int value = 20;  // Lỗi linker: multiple definition

* **Cách thực hiện đúng:**

        //file globals.h

        #ifndef GLOBALS_H
        #define GLOBALS_H

        extern int app_version;
        extern float pi_value;

        #endif

        //file globals.c

        #include "globals.h"

        int app_version = 100;
        float pi_value = 3.14159f;

        //file main.c

        #include <stdio.h>
        #include "globals.h"

        int main() {
            printf("Phien ban: %d\n", app_version);
            printf("Pi: %.5f\n", pi_value);
            return 0;
        }

### **III. TYPE QUALIFIERS** 

#### **3.1.Lý thuyết**

##### **3.1.1.Định nghĩa**

* Type Qualifiers là các từ khóa bổ sung thông tin cho compiler về cách xử lý biến, giúp tối ưu hóa, đảm bảo tính đúng đắn và an toàn của chương trình.

##### **3.1.2.Phân loại**

* **const** - Hằng số: Ngăn thay đổi giá trị

* **volatile** - Biến động: Ngăn tối ưu hóa không mong muốn

* **restrict** - Con trỏ độc quyền: Cho phép tối ưu hóa mạnh

* **_Atomic** - Nguyên tử: Đảm bảo atomic operations

#### **3.2.const Qualifier**

##### **3.2.1.Lý thuyết**

* **Định nghĩa:** const chỉ định rằng biến không thể thay đổi giá trị sau khi khởi tạo.

* **Mục đích:** 

  ◦ Đảm bảo tính bất biến

  ◦ Ngăn thay đổi giá trị vô tình

  ◦ Cho phép compiler tối ưu hóa

  ◦ Làm code rõ ràng, dễ bảo trì

* **Cú pháp:** 

        const data_type variable_name = value;
        data_type const variable_name = value; // Tương đương

##### **3.2.2.Các cách sử dụng const**

* **const với biến cơ bản:** 

        #include <stdio.h>

        int main() {
            // Biến const cơ bản
            const int MAX_SIZE = 100;
            const double PI = 3.14159265359;
            const char NEWLINE = '\n';
            
            printf("Max size: %d\n", MAX_SIZE);
            printf("PI: %.10f\n", PI);
            printf("Newline: %c", NEWLINE);
            
            // ❌ KHÔNG thể thay đổi
            // MAX_SIZE = 200;      // Lỗi: assignment of read-only variable
            // PI = 3.14;           // Lỗi: assignment of read-only variable
            
            return 0;
        }


* **const với con trỏ:** 

        #include <stdio.h>

        int main() {
            int x = 10;
            int y = 20;
            
            // 1. Con trỏ đến hằng số
            const int *ptr1 = &x;
            printf("Value: %d\n", *ptr1);  // ✅ Đọc được
            // *ptr1 = 30;                 // ❌ Lỗi: không thay đổi được giá trị
            ptr1 = &y;                     // ✅ Có thể thay đổi con trỏ
            printf("New value: %d\n", *ptr1);
            
            // 2. Con trỏ hằng
            int *const ptr2 = &x;
            printf("Value: %d\n", *ptr2);  // ✅ Đọc được
            *ptr2 = 30;                    // ✅ Có thể thay đổi giá trị
            printf("Updated value: %d\n", *ptr2);
            // ptr2 = &y;                  // ❌ Lỗi: không thay đổi được con trỏ
            
            // 3. Con trỏ hằng đến hằng số
            const int *const ptr3 = &x;
            printf("Value: %d\n", *ptr3);  // ✅ Đọc được
            // *ptr3 = 40;                 // ❌ Lỗi: không thay đổi giá trị
            // ptr3 = &y;                  // ❌ Lỗi: không thay đổi con trỏ
            
            return 0;
        }

* **const với mảng:** 

        #include <stdio.h>

        int main() {
            // Mảng hằng số
            const int DAYS_IN_WEEK = 7;
            const char DAY_NAMES[][10] = {
                "Sunday", "Monday", "Tuesday", "Wednesday",
                "Thursday", "Friday", "Saturday"
            };
            
            const int PRIME_NUMBERS[] = {2, 3, 5, 7, 11, 13, 17, 19};
            const int PRIME_COUNT = sizeof(PRIME_NUMBERS) / sizeof(PRIME_NUMBERS[0]);
            
            printf("Days in week: %d\n", DAYS_IN_WEEK);
            
            for(int i = 0; i < DAYS_IN_WEEK; i++) {
                printf("Day %d: %s\n", i + 1, DAY_NAMES[i]);
            }
            
            printf("First %d prime numbers: ", PRIME_COUNT);
            for(int i = 0; i < PRIME_COUNT; i++) {
                printf("%d ", PRIME_NUMBERS[i]);
            }
            printf("\n");
            
            // ❌ KHÔNG thể thay đổi
            // DAY_NAMES[0] = "SUN";      // Lỗi
            // PRIME_NUMBERS[0] = 1;      // Lỗi
            
            return 0;
        }


* **const với struct:** 

        #include <stdio.h>

        struct Point {
            int x;
            int y;
        };

        struct Circle {
            const double radius;
            const struct Point center;
        };

        void print_circle(const struct Circle *c) {
            printf("Circle - Radius: %.2f, Center: (%d, %d)\n", 
                c->radius, c->center.x, c->center.y);
            // c->radius = 5.0;  // ❌ Lỗi: không thể thay đổi
        }

        int main() {
            // Struct với thành viên const
            const struct Circle my_circle = {3.5, {10, 20}};
            print_circle(&my_circle);
            
            // Struct const
            const struct Point origin = {0, 0};
            printf("Origin: (%d, %d)\n", origin.x, origin.y);
            // origin.x = 1;  // ❌ Lỗi: không thể thay đổi
            
            return 0;
        }


* **const với tham số hàm:** 

        #include <stdio.h>
        #include <string.h>

        // Tham số const - đảm bảo không thay đổi giá trị
        void print_array(const int arr[], int size) {
            printf("Array elements: ");
            for(int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
                // arr[i] = 0;  // ❌ Lỗi: không thể thay đổi
            }
            printf("\n");
        }

        // Con trỏ const với chuỗi
        int count_uppercase(const char *str) {
            int count = 0;
            while(*str) {
                if(*str >= 'A' && *str <= 'Z') {
                    count++;
                }
                str++;
            }
            // *str = 'X';  // ❌ Lỗi: không thể thay đổi
            return count;
        }

        // Trả về con trỏ const
        const char* get_error_message(int error_code) {
            static const char* messages[] = {
                "Success",
                "Invalid input",
                "Out of memory",
                "File not found"
            };
            
            if(error_code >= 0 && error_code < 4) {
                return messages[error_code];
            }
            return "Unknown error";
        }

        int main() {
            int numbers[] = {1, 2, 3, 4, 5};
            const int SIZE = 5;
            
            print_array(numbers, SIZE);
            
            const char *text = "Hello World";
            printf("Uppercase letters: %d\n", count_uppercase(text));
            
            printf("Error 2: %s\n", get_error_message(2));
            
            return 0;
        }

#### **3.3.volatile Qualifier**

##### **3.3.1.Lý thuyết**

* **Định nghĩa:** volatile chỉ định rằng biến có thể thay đổi giá trị bất ngờ, ngoài tầm kiểm soát của chương trình.

* **Mục đích:** 

  ◦ Ngăn compiler tối ưu hóa không mong muốn

  ◦ Đảm bảo truy cập bộ nhớ thực tế mỗi lần đọc/ghi

  ◦ Dùng cho memory-mapped I/O, biến chia sẻ, interrupt handlers

* **Cú pháp:** 

        volatile data_type variable_name;

##### **3.3.2.Các tình huống sử dụng volatile**

* **Memory-mapped I/O:** 

        #include <stdio.h>

        // Giả sử đây là thanh ghi phần cứng
        #define STATUS_REGISTER (*(volatile unsigned int*)0x1000)
        #define DATA_REGISTER (*(volatile unsigned int*)0x1004)

        void wait_for_data_ready() {
            // Compiler không thể tối ưu vòng lặp này
            // vì STATUS_REGISTER có thể thay đổi bởi phần cứng
            while((STATUS_REGISTER & 0x01) == 0) {
                // Chờ cho đến khi bit 0 được set
            }
        }

        unsigned int read_data() {
            wait_for_data_ready();
            return DATA_REGISTER;
        }

        int main() {
            printf("Reading data from hardware...\n");
            unsigned int data = read_data();
            printf("Data received: 0x%08X\n", data);
            return 0;
        }


* **Biến chia sẻ với interrupt handler:** 

        #include <stdio.h>
        #include <signal.h>
        #include <unistd.h>

        // Biến volatile - có thể thay đổi bởi signal handler
        volatile sig_atomic_t interrupt_flag = 0;

        void interrupt_handler(int sig) {
            interrupt_flag = 1;  // Được gọi bất ngờ
        }

        int main() {
            // Đăng ký signal handler
            signal(SIGINT, interrupt_handler);
            
            printf("Press Ctrl+C to trigger interrupt...\n");
            
            // Không có volatile, compiler có thể tối ưu thành while(0)
            while(!interrupt_flag) {
                // Chờ interrupt
                usleep(100000); // 100ms
            }
            
            printf("Interrupt received! Cleaning up...\n");
            return 0;
        }

* **multi-threading:** 

        #include <stdio.h>
        #include <pthread.h>
        #include <unistd.h>

        // Biến chia sẻ giữa các thread
        volatile int shared_counter = 0;

        void* worker_thread(void* arg) {
            for(int i = 0; i < 1000; i++) {
                // Đọc giá trị mới nhất từ bộ nhớ
                int current = shared_counter;
                
                // Giả lập công việc
                usleep(1000);
                
                // Ghi giá trị mới
                shared_counter = current + 1;
            }
            return NULL;
        }

        int main() {
            pthread_t thread1, thread2;
            
            printf("Starting multi-threaded counter...\n");
            printf("Initial counter: %d\n", shared_counter);
            
            pthread_create(&thread1, NULL, worker_thread, NULL);
            pthread_create(&thread2, NULL, worker_thread, NULL);
            
            pthread_join(thread1, NULL);
            pthread_join(thread2, NULL);
            
            printf("Final counter: %d\n", shared_counter);
            printf("Expected: 2000, Got: %d\n", shared_counter);
            
            return 0;
        }


* **So sánh volatile vs non-volatile:** 

        #include <stdio.h>

        void without_volatile() {
            int counter = 0;
            
            // Compiler có thể tối ưu thành vòng lặp vô hạn
            // vì counter không thay đổi trong thân vòng lặp
            while(counter == 0) {
                // Không làm gì
            }
            printf("Without volatile: Loop exited\n");
        }

        void with_volatile() {
            volatile int counter = 0;
            
            // Compiler PHẢI đọc counter từ bộ nhớ mỗi lần
            while(counter == 0) {
                // Không làm gì
            }
            printf("With volatile: Loop exited\n");
        }

        int main() {
            printf("Demonstrating volatile optimization prevention\n");
            
            // without_volatile();  // Có thể bị tối ưu thành vòng lặp vô hạn
            // with_volatile();     // Luôn hoạt động đúng
            
            return 0;
        }


#### **3.4.restrict Qualifier**

##### **3.4.1.Lý thuyết**

* **Định nghĩa:** restrict là một lời hứa với compiler rằng con trỏ là cách duy nhất để truy cập vùng nhớ đó trong phạm vi hiện tại.

* **Mục đích:** 

  ◦ Cho phép compiler tối ưu hóa mạnh hơn

  ◦ Tránh hiện tượng pointer aliasing

  ◦ Cải thiện hiệu năng với các phép toán trên mảng

* **Cú pháp:** 

        data_type *restrict pointer_name;

##### **3.4.2.Đặc điểm**

* **restrict là gì?** 

        void add(int *restrict a, int *restrict b, int n) {
            for (int i = 0; i < n; i++) {
                a[i] = a[i] + b[i];
            }
        }

        a và b không trỏ cùng vùng nhớ
        → Compiler tối ưu nhanh hơn (không phải kiểm tra aliasing)


* **Dùng đúng – Không aliasing:** 

        int x[5] = {1, 2, 3, 4, 5};
        int y[5] = {10, 20, 30, 40, 50};

        add(x, y, 5);  // OK: x và y khác nhau → restrict đúng

* **Dùng sai – Có aliasing (Lỗi logic!):** 

        int arr[5] = {1, 2, 3, 4, 5};

        add(arr, arr, 5);  // SAI: a và b cùng trỏ arr → vi phạm restrict!


* **restrict vs non-restrict:** 

        // Phiên bản an toàn (không restrict)
        void add_safe(int *a, int *b, int n) {
            for (int i = 0; i < n; i++) a[i] += b[i];
        }

        // Phiên bản tối ưu (có restrict)
        void add_fast(int *restrict a, int *restrict b, int n) {
            for (int i = 0; i < n; i++) a[i] += b[i];
        }

        add_fast nhanh hơn nếu chắc chắn a ≠ b

* **const + restrict:** 

        void scale(const float *restrict src, float *restrict dest, float k, int n) {
            for (int i = 0; i < n; i++) {
                dest[i] = src[i] * k;
            }
        }

        src không đổi, dest không trùng src → tối ưu + an toàn.


#### **3.5._Atomic Qualifier (C11)**

##### **3.5.1.Lý thuyết**

* **Định nghĩa:** _Atomic đảm bảo các thao tác trên biến được thực hiện một cách nguyên tử (atomic) - không thể bị gián đoạn.

* **Mục đích:** 

  ◦ Đảm bảo thread-safety trong lập trình đa luồng

  ◦ Ngăn race conditions

  ◦ Cung cấp các thao tác atomic không cần khóa (lock-free)

* **Cú pháp:** 

        _Atomic data_type variable_name;
        _Atomic(data_type) variable_name;

        VD:

        #include <stdatomic.h>

        _Atomic int counter = 0;           // Cách 1
        _Atomic(int) flag = 1;             // Cách 2

##### **3.5.2.Đặc điểm*

* **Tăng/giảm nguyên tử – An toàn đa luồng:** 

        #include <stdatomic.h>
        #include <stdio.h>

        _Atomic int count = 0;

        void worker() {
            for (int i = 0; i < 100000; i++) {
                count++;  // Nguyên tử: không bị race condition
            }
        }

* **Không _Atomic → Race condition:** 

  ◦ Race Condition:Hai hoặc nhiều luồng cùng truy cập một biến chung, ít nhất một luồng ghi, và kết quả phụ thuộc vào thứ tự chạy – không kiểm soát được.

        int count = 0;

        void thread1() { count++; }  // Đọc → +1 → Ghi
        void thread2() { count++; }  // Cùng lúc

        Mong đợi: count = 2
        Thực tế có thể: count = 1 → mất dữ liệu!

  ◦ VD:
        int count = 0;  // KHÔNG atomic

        void bad_worker() {
            for (int i = 0; i < 100000; i++) {
                count++;  // NGUY HIỂM: có thể mất dữ liệu!
            }
        }

* **Dùng atomic_load / atomic_store** 

        #include <stdatomic.h>
        #include <stdio.h>

        _Atomic int status = 0;

        void set_ready() {
            atomic_store(&status, 1);  // Ghi nguyên tử
        }

        int is_ready() {
            return atomic_load(&status);  // Đọc nguyên tử
        }

### **IV.TOÁN TỬ VÀ BIỂU THỨC**

#### **4.1.Lý thuyết**

##### **4.1.1.Định nghĩa**

  * **Toán tử (Operator):** Ký hiệu thực hiện phép toán trên các toán hạng

  * **Toán hạng (Operand):** Giá trị hoặc biến được thao tác

  * **Biểu thức (Expression):** Kết hợp toán tử và toán hạng tạo ra giá trị

##### **4.1.2.Phân loại toán tử*

  * **Số học** - Arithmetic operators

  * **Quan hệ** - Relational operators

  * **Logic** - Logical operators

  * **Bitwise** - Bitwise operators

  * **Gán** - Assignment operators

  * **Điều kiện** - Conditional operator

  * **Đặc biệt** - Special operators

#### **4.2.Toán tử số học (Arithmetic Operators)**

##### **4.2.1.Mô tả:** 

* Thực hiện các phép toán số học cơ bản trên các giá trị số nguyên hoặc số thực.

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

##### **4.2.2.Lưu ý:**

* Phép chia `/` giữa hai số nguyên cho kết quả số nguyên (phần thập phân bị bỏ).

* Phép chia `%` chỉ áp dụng cho các kiểu số nguyên.

* Toán tử `++` và `--` có hai dạng:

  ◦ Tiền tố (++x, --x): Tăng/giảm giá trị trước, sau đó sử dụng giá trị mới.

  ◦ Hậu tố (x++, x--): Sử dụng giá trị hiện tại, sau đó tăng/giảm

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

#### **4.3.Toán tử quan hệ (Relational Operators)**

##### **4.3.1.Mô tả** 

* So sánh hai giá trị và trả về giá trị logic (`1` cho `đúng`, `0` cho `sai`).

##### **4.3.2.Các toán tử**

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

#### **4.4.Toán tử logic (Logical Operators)** 

##### **4.4.1.Mô tả** 

* Thực hiện các phép toán logic trên các giá trị logic (true hoặc false, thường là 1 hoặc 0 trong C).

##### **4.4.2.Các toán tử**

| Toán Tử | Ý Nghĩa               | Ví Dụ            | Kết Quả            |
|---------|----------------------|------------------|-------------------|
| `&&`     | AND                 | `(5 > 3) && (3 > 1)`          | `1`               |
| `!`     | NOT (phủ định)              | `!(5 > 3)`          | `0`               |
| `\|\|`     | OR (hoặc)               | `(5 > 3) \|\| (3 < 1)`          | `1`              |

##### **4.4.3.Lưu ý:**

* Trong C, bất kỳ giá trị khác 0 được coi là `true`, còn 0 là `false`.

* `&&` và `||` sử dụng đánh giá ngắn mạch (short-circuit evaluation):

  ◦ Với &&, nếu biểu thức bên trái là false, biểu thức bên phải không được đánh giá.

  ◦ Với ||, nếu biểu thức bên trái là true, biểu thức bên phải không được đánh giá.


* **VD:** 

        #include <stdio.h>

        int main() {
            int a = 5, b = 3, c = 0;
            printf("(a > b) && (b > c): %d\n", (a > b) && (b > c)); // 1
            printf("(a > b) || (b < c): %d\n", (a > b) || (b < c)); // 1
            printf("!(a > b): %d\n", !(a > b)); // 0
            return 0;
        }

#### **4.5.Toán tử Bit (Bitwise Operators)** 

##### **4.5.1.Mô tả** 

* Thực hiện các phép toán trên từng bit của giá trị số nguyên.

##### **4.5.2.Các toán tử**

| Toán Tử | Ý Nghĩa               | Ví Dụ            | Kết Quả (Binary)        | Kết Quả (Decimal) |
|---------|----------------------|------------------|------------------------|------------------|
| `&`     | AND bit              | `5 & 3`          | `0001`                 | `1`              |
| `\|`    | OR bit               | `5 \| 3`         | `0111`                 | `7`              |
| `^`     | XOR bit              | `5 ^ 3`          | `0110`                 | `6`              |
| `~`     | NOT bit (phủ định)   | `~5`             | `...1010`              | Phụ thuộc hệ thống |
| `<<`    | Dịch trái            | `5 << 1`         | `1010`                 | `10`             |
| `>>`    | Dịch phải            | `5 >> 1`         | `0010`                 | `2`              |

##### **4.5.3.Lưu ý:**

*  `&, | , ^` thực hiện phép toán trên từng cặp bit tương ứng.

*  `~` đảo ngược tất cả các bit (0 thành 1, 1 thành 0).

*  `<<` dịch các bit sang trái, thêm 0 vào bên phải (tương đương nhân 2).

*  `>>` dịch các bit sang phải, giữ dấu cho kiểu signed (thêm bit dấu vào bên trái).

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


#### **4.6.Toán tử gán (Assignment Operators)**

##### **4.6.1.Mô tả** 

* Gán giá trị cho biến hoặc thực hiện phép toán kết hợp với gán.

##### **4.6.2.Các toán tử:** 

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

#### **4.7.Toán tử điều kiện Conditional Operator - Toán Tử 3 Ngôi)**

##### **4.7.1.Mô tả**

* Toán tử điều kiện `(?:)` là toán tử ba ngôi duy nhất trong C, thực hiện lựa chọn dựa trên điều kiện và trả về một trong hai giá trị.

##### **4.7.2.Cú pháp**

    `biểu_thức_điều_kiện ? giá_trị_nếu_đúng : giá_trị_nếu_sai;`

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

#### **4.8.Toán tử Sizeof**

##### **4.8.1.Mô tả:** 

* Toán tử `sizeof` trả về kích thước (tính bằng byte) của một kiểu dữ liệu hoặc biến.

##### **4.8.2.Cú pháp:** 

        sizeof(biến);
        sizeof(kiểu_dữ_liệu);

##### **4.8.3.Lưu ý:** 

* Kết quả của `sizeof` có kiểu `size_t` (được định nghĩa trong `<stddef.h>` hoặc `<stdio.h>`).

* Thường được sử dụng để xác định kích thước bộ nhớ của biến, mảng, hoặc kiểu dữ liệu.

* Kích thước phụ thuộc vào hệ thống (32-bit hoặc 64-bit) và trình biên dịch.

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

    
#### **4.9.Toán tử dấu phẩy (Comma Operator)**

##### **4.9.1.Mô tả**

* Toán tử dấu phẩy `(,)` cho phép thực hiện nhiều biểu thức trong một câu lệnh, trả về giá trị của biểu thức cuối cùng.

##### **4.9.2.Cú pháp**
  
        biểu_thức_1, biểu_thức_2, ..., biểu_thức_n;

##### **4.9.3.Lưu ý**

* Các biểu thức được đánh giá từ trái sang phải.

* Giá trị của toàn bộ biểu thức dấu phẩy là giá trị của biểu thức cuối cùng.

* Thường được sử dụng trong vòng lặp hoặc để gộp nhiều thao tác.

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


#### **4.10.Ưu tiên toán tử (Operator Precedence)**

#### **4.10.1.Mô tả**

* Quy định thứ tự thực hiện các toán tử trong một biểu thức. Toán tử có độ ưu tiên cao được thực hiện trước.

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

### **V.ÉP KIỂU (TYPE CASTING)**

#### **5.1.Lý thuyết**

##### **5.1.1.Định nghĩa**

  * Ép kiểu là quá trình chuyển đổi giá trị từ kiểu dữ liệu này sang kiểu dữ liệu khác.

##### **5.1.2.Phân loại**

  * **Ép kiểu tự động (Implicit Casting)** - Compiler tự động thực hiện

  * **Ép kiểu tường minh (Explicit Casting)** - Lập trình viên chỉ định

##### **5.1.3.Nguyên tắc chuyển đổi**

  * **Mở rộng (Widening):** Chuyển từ kiểu nhỏ → kiểu lớn (an toàn)

  * **Thu hẹp (Narrowing):** Chuyển từ kiểu lớn → kiểu nhỏ (có thể mất mát)

#### **5.2.Ép kiểu tự động (Implicit Casting)**

##### **5.2.1.Khi nào xảy ra**

  * Trong các phép toán hỗn hợp kiểu

  * Khi gán giá trị cho biến có kiểu khác

  * Trong truyền tham số hàm

##### **5.2.2.Quy tắc chuyển đổi (theo thứ tự ưu tiên)**

  * char, short → int → unsigned int → long → unsigned long → long long → float → double → long double

        #include <stdio.h>

        int main() {
            // Chuyển char → int (mở rộng)
            char c = 'A';
            int i = c;  // Tự động chuyển
            printf("char '%c' → int %d\n", c, i);
            
            // Chuyển int → float (mở rộng)
            int count = 10;
            float ratio = count;  // 10 → 10.0f
            printf("int %d → float %.1f\n", count, ratio);
            
            // Trong phép toán hỗn hợp
            int a = 5;
            double b = 2.5;
            double result = a + b;  // 5 → 5.0, rồi + 2.5
            printf("%d + %.1f = %.1f\n", a, b, result);
            
            // Chuyển float → int (thu hẹp - có cảnh báo)
            float pi = 3.14f;
            int approx = pi;  // 3.14 → 3 (mất phần thập phân)
            printf("float %.2f → int %d\n", pi, approx);
            
            return 0;
        }

#### **5.3.Ép kiểu tường minh (Explicit Casting)**

##### **5.3.1.Cú pháp:**

        (target_type)expression


        VD: Ép kiểu số nguyên → số thực

        int a = 10, b = 3;
        float result = (float)a / b;  // → 3.33333
        printf("%.5f\n", result);


##### **5.3.2.Khi nào sử dụng**

* Chuyển đổi thu hẹp (có thể mất mát)

* Chuyển giữa các kiểu không tương thích

* Làm rõ ý định cho compiler và người đọc code

* Tránh cảnh báo compiler

##### **5.3.3.Đặc điểm**

* Lập trình viên chủ động chỉ định

* Có thể gây mất mát dữ liệu

* Cần cẩn thận khi sử dụng

        VD: Ép kiểu số thực → số nguyên (cắt phần thập phân)
        
        double x = 9.78;
        int y = (int)x;  // → 9
        printf("%d\n", y);

        VD: Ép kiểu con trỏ (pointer casting)
        
        int arr[] = {1, 2, 3};
        void* ptr = arr;               // OK: int* → void*
        int* back = (int*)ptr;         // Ép lại: void* → int*
        printf("%d\n", back[0]);       // → 1

        VD: Ép kiểu giữa các kiểu số nguyên
        
        long long big = 1234567890123LL;
        int small = (int)big;  // → Cắt bớt (tràn số!)
        printf("%d\n", small); // Kết quả không xác định

        VD: Ép kiểu với const
        
        const char* str = "Hello";
        char* mutable = (char*)str;  // Bỏ const (nguy hiểm!)
        mutable[0] = 'h';            // OK nhưng undefined behavior

        VD: Ép kiểu trong hàm
        
        #include <stdio.h>
        double divide(int a, int b) {
            return (double)a / b;  // Ép a hoặc b → chia thực
        }

        int main() {
            printf("%.2f\n", divide(5, 2));  // → 2.50
            return 0;
        }

</details> 
<details>
	<summary><strong>CHƯƠNG 2: NHẬP XUẤT CƠ BẢN</strong></summary>

## **CHƯƠNG 2: NHẬP XUẤT CƠ BẢN**

### **I. FORMATTED OUTPUT**

#### **1.1.Giới thiệu hàm printf()**

##### **1.1.1.Mô tả**

* `printf()` là hàm dùng để xuất dữ liệu có định dạng ra thiết bị xuất chuẩn (thường là màn hình).

##### **1.1.2.Cú pháp**

        #include <stdio.h>

        int printf(const char *format, ...);
                   
* **Tham số:**

  ◦ `format:` Chuỗi định dạng chứa văn bản tĩnh và các **format specifiers** (mã định dạng như `%d`, `%f`).

  ◦ `...:` Các đối số tương ứng với format specifiers (có thể là int, float, char, v.v.).

##### **1.1.3.Giá trị trả về**

* Số ký tự được in ra (nếu thành công), hoặc số âm nếu có lỗi (ví dụ: buffer đầy).
                   
* **Lưu ý:**

  ◦ Phải include `<stdio.h>` để sử dụng.

  ◦ `printf()` tự động thêm null terminator cho chuỗi.

    
#### **1.2.Format Specifiers**

##### **1.2.1.Định nghĩa**

* Format specifiers là các mã đặc biệt bắt đầu bằng `%` để chỉ định cách hiển thị dữ liệu. 

##### **1.2.2.Bảng specifier**

| Specifier | Kiểu dữ liệu | Ví dụ | Kết quả dự kiến |
|------------|---------------|--------|-----------------|
| %d / %i | int | printf("%d", 25); | 25 |
| %u | unsigned int | printf("%u", 300); | 300 |
| %f | float, double | printf("%f", 3.14); | 3.140000 |
| %c | char | printf("%c", 'A'); | A |
| %s | char* (chuỗi) | printf("%s", "Hello"); | Hello |
| %p | Con trỏ | printf("%p", &x); | 0x7ffd42a... |
| %x / %X | int (hệ thập lục phân) | printf("%x", 255); | ff |
| %o | int (hệ bát phân) | printf("%o", 64); | 100 |
| %e / %E | Số thực dạng khoa học | printf("%e", 1000.0); | 1.000000e+03 |
| %g / %G | Số thực (tự chọn) | printf("%g", 3.14); | 3.14 |
| %% | Ký tự % | printf("%%"); | % |
                   
* **VD:**

        #include <stdio.h>

        int main() {
            int age = 25;
            float height = 1.75f;
            char grade = 'A';
            char name[] = "John";
            int *ptr = &age;
            
            printf("Tuổi: %d, Chiều cao: %.2f\n", age, height);      // Tuổi: 25, Chiều cao: 1.75
            printf("Điểm: %c, Tên: %s\n", grade, name);              // Điểm: A, Tên: John
            printf("Địa chỉ biến age: %p\n", (void*)ptr);            // Địa chỉ biến age: 0x7ffd...
            printf("Số 255 trong hex: 0x%X\n", 255);                 // Số 255 trong hex: 0xFF
            printf("Ký tự phần trăm: %%\n");                          // Ký tự phần trăm: %
            
            return 0;
        }

        Tuổi: 25, Chiều cao: 1.75
        Điểm: A, Tên: John
        Địa chỉ biến age: 0x7ffd42a...
        Số 255 trong hex: 0xFF
        Ký tự phần trăm: %


#### **1.3.Flags (Cờ định dạng)**

##### **1.3.1.Định nghĩa**

* Flags là các ký tự đặc biệt sau `%` để tùy chỉnh hiển thị (căn chỉnh, dấu, padding). Chúng được đặt ngay sau `%` và trước specifier.

##### **1.3.2.Bảng Flags**

| **Flag** | **Ý nghĩa** | **Ví dụ** | **Kết quả dự kiến** |
|------------|---------------|--------|-----------------|
| `-` | Căn trái trong trường in ra | `printf("%-10s", "Hi");` | `Hi        ` |
| `+` | Luôn hiển thị dấu `+` hoặc `-` | `printf("%+d", 25);` | `+25` |
| (space) | Thêm khoảng trắng trước số dương | `printf("% d", 25);` | ` 25` |
| `0` | Padding bằng số `0` (thay vì khoảng trắng) | `printf("%05d", 25);` | `00025` |
| `#` | Format thay thế (prefix với 0x, 0, 0X, ...) | `printf("%#x", 255);` | `0xff` |
| `#` | Với `%o`, thêm tiền tố `0` | `printf("%#o", 64);` | `0100` |
| `#` | Với `%f`, luôn có dấu `.` dù không có phần thập phân | `printf("%#.0f", 3.0);` | `3.` |

* **VD:**

        #include <stdio.h>

        int main() {
        int number = 123;
        float pi = 3.14159;
        char str[] = "Hello";
        
        // Width với số nguyên
        printf("Width 8: |%8d|\n", number);                      // Width 8: |    123|
        printf("Width 2: |%2d|\n", number);                      // Width 2: |123| (vượt quá vẫn hiển thị đủ)
        
        // Width với chuỗi
        printf("String width 10: |%10s|\n", str);                // String width 10: |     Hello|
        printf("String width 3: |%3s|\n", str);                  // String width 3: |Hello| (vượt quá vẫn hiển thị đủ)
        
        // Precision với số thực
        printf("Precision 2: %.2f\n", pi);                       // Precision 2: 3.14
        printf("Precision 0: %.0f\n", pi);                       // Precision 0: 3
        printf("Precision 5: %.5f\n", pi);                       // Precision 5: 3.14159
        
        // Precision với chuỗi
        printf("String precision 3: %.3s\n", str);               // String precision 3: Hel
        printf("String precision 10: %.10s\n", str);             // String precision 10: Hello (không cắt nếu ngắn)
        
        // Kết hợp width và precision
        printf("Combined: |%8.2f|\n", pi);                       // Combined: |   3.14|
        printf("Combined: |%-8.2f|\n", pi);                      // Combined: |3.14    |
        
        // Precision với số nguyên (padding 0)
        printf("Int precision: %.5d\n", 25);                     // Int precision: 00025
        
        return 0;
        }


#### **1.4.Width và Precision**

##### **1.4.1.Định nghĩa**

* **Width:** Độ rộng tối thiểu của trường (số ký tự). Nếu dữ liệu ngắn hơn, sẽ padding bằng space (căn phải mặc định).

* **Precision:** Độ chính xác, thường là số chữ số thập phân cho `%f`, hoặc độ dài tối đa cho `%s`

##### **1.4.2.Cú pháp tổng quát**

* `%[flags][width][.precision]specifier`


| **Flag** | **Ý nghĩa** | **Ví dụ** | **Kết quả dự kiến** |
|-----------|-------------|------------|----------------------|
| `-` | Căn trái trong trường in ra | `printf("%-10s", "Hi");` | `Hi        ` |
| `+` | Luôn hiển thị dấu `+` hoặc `-` | `printf("%+d", 25);` | `+25` |
| (space) | Thêm khoảng trắng trước số dương | `printf("% d", 25);` | ` 25` |
| `0` | Padding bằng số `0` (thay vì khoảng trắng) | `printf("%05d", 25);` | `00025` |
| `#` | Format thay thế (prefix với 0x, 0, 0X, ...) | `printf("%#x", 255);` | `0xff` |
| `#` | Với `%o`, thêm tiền tố `0` | `printf("%#o", 64);` | `0100` |
| `#` | Với `%f`, luôn có dấu `.` dù không có phần thập phân | `printf("%#.0f", 3.0);` | `3.` |



#### **1.5.Các Specifiers đặc biệt**

##### **1.5.1.Định nghĩa**

* Cho kiểu dữ liệu cố định (`stdint.h`): Sử dụng macro từ `<inttypes.h>` như `PRId32`, `PRIu64`.

##### **1.5.2.VD**

        #include <stdio.h>
        #include <stdint.h>
        #include <inttypes.h>

        int main(void) {
            int32_t a = -12345;
            uint64_t b = 9876543210ULL;

            printf("Số int32_t: %" PRId32 "\n", a);     // PRId32 → in số có dấu 32-bit
            printf("Số uint64_t: %" PRIu64 "\n", b);    // PRIu64 → in số không dấu 64-bit

            return 0;
        }

        Số int32_t: -12345
        Số uint64_t: 9876543210


#### **1.6.Các ký tự đặc biệt**

##### **1.6.1.Định nghĩa**

* Escape sequences bắt đầu bằng \ để chèn ký tự đặc biệt vào chuỗi.

##### **1.6.2.Bảng các ký tự đặc biệt**

| Escape Sequence | Ý nghĩa           | Ví dụ                                 |
|------------------|------------------|----------------------------------------|
| `\n`             | New line (xuống dòng mới) | `printf("Dòng 1\nDòng 2");` |
| `\t`             | Tab (khoảng cách ngang)   | `printf("Cột1\tCột2");`      |
| `\\`             | Backslash (`\`)           | `printf("C:\\Users");`       |
| `\"`             | Double quote (`"`)        | `printf("\"Hello\"");`       |
| `\'`             | Single quote (`'`)        | `printf("\'A\'");`           |
| `\b`             | Backspace (xóa ký tự trước) | `printf("Xóa\b");`         |
| `\r`             | Carriage return (đưa con trỏ về đầu dòng) | `printf("Loading...\rDone!");` |
| `\a`             | Alert (phát tiếng beep)   | `printf("\aCảnh báo!");`     |

* **VD:progress bar đơn giản**

        #include <stdio.h>

        int main() {
            printf("Dòng 1\nDòng 2\n");
            printf("Tab:\tCột 1\tCột 2\n");
            printf("Đường dẫn: C:\\Users\\Name\\File.txt\n");
            printf("Trích dẫn: \"Hello, World!\"\n");
            printf("Tiếng bíp: \a\n");
            
            // Progress bar với \r và fflush(stdout)
            printf("Loading: [----------]\r");
            fflush(stdout);
            printf("Loading: [###-------]\r");
            fflush(stdout);
            printf("Loading: [##########]\n");  // Kết thúc bằng \n
            
            return 0;
        }

        Dòng 1
        Dòng 2
        Tab:	Cột 1	Cột 2
        Đường dẫn: C:\Users\Name\File.txt
        Trích dẫn: "Hello, World!"
        Tiếng bíp: 

        Loading: [##########]

### **II. FORMATTED INPUT**

#### **2.1.Giới thiệu hàm scanf()**

##### **2.1.1.Định nghĩa**

* `scanf()` là hàm nhập dữ liệu có định dạng từ thiết bị nhập chuẩn (thường là bàn phím).

##### **2.1.2.Cú pháp**

        #include <stdio.h>
        int scanf(const char *format, ...);
                   
* **Tham số:**

  ◦ `format:` Chuỗi định dạng chứa format specifiers

  ◦ `...:` Con trỏ đến các biến sẽ nhận giá trị nhập

* **Giá trị trả về:**

  ◦ Số biến được nhập thành công (> 0).

  ◦ 0: Không có biến nào được nhập (đầu vào không khớp).

  ◦ EOF: Lỗi hoặc end-of-file (Ctrl+D trên Unix, Ctrl+Z trên Windows).

* **Lưu ý:**

  ◦ Phải dùng `&` trước biến (trừ mảng char như `%s`).

  ◦ `scanf()` dừng khi gặp whitespace không khớp hoặc end-of-input.

#### **2.2.Width Specification**

##### **2.2.1.Định nghĩa**

* Width giới hạn số ký tự tối đa nhập vào để tránh tràn buffer (đặc biệt với `%s`).

##### **2.2.2.Cú pháp**

* `%[width]specifier (ví dụ: %19s giới hạn 19 ký tự).`

* **VD:**

        #include <stdio.h>

        int main() {
            char first_name[20];
            char last_name[20];
            
            // Giới hạn 19 ký tự cho first_name (chừa chỗ '\0')
            printf("Nhập họ (tối đa 19 ký tự): ");
            scanf("%19s", first_name);
            
            printf("Nhập tên (tối đa 19 ký tự): ");
            scanf("%19s", last_name);
            
            printf("Họ và tên: %s %s\n", first_name, last_name);
            
            // Giới hạn 4 chữ số cho số nguyên
            int number;
            printf("Nhập số (tối đa 4 chữ số): ");
            scanf("%4d", &number);
            printf("Số đã nhập: %d\n", number);
            
            return 0;
        }


#### **2.3.Scan Sets**

##### **2.3.1.Định nghĩa**

* Scan sets cho phép kiểm soát ký tự được chấp nhận (`%[set]` hoặc `%[^set]`).

  ◦ **Scan Set cơ bản:** `%[set]` - Chỉ nhận ký tự trong `set` (ví dụ: `%[a-zA-Z]` chỉ chữ cái).

  ◦ **Negated Scan Set:** `%[^set]` - Nhận tất cả trừ ký tự trong `set` (ví dụ: %[^\n] nhập đến newline).

* **VD1:**

        #include <stdio.h>

        int main() {
            char str1[50], str2[50];

            // Scan Set cơ bản - chỉ nhận chữ cái (a–z, A–Z)
            printf("Nhập chữ cái: ");
            scanf("%[a-zA-Z]", str1);
            printf("Kết quả: %s\n", str1);

            // Negated Scan Set - nhận tất cả trừ ký tự newline
            printf("Nhập chuỗi (dừng khi xuống dòng): ");
            scanf(" %[^\n]", str2);
            printf("Kết quả: %s\n", str2);

            return 0;
        }

  ◦ 1.Input người dùng (%[a-zA-Z]): `Hello123 (Enter)` -> Output chương trình: `Hello`

  ◦ 2.Input người dùng: (%[^\n]): `Xin chào` -> Output chương trình: `Xin chào`


* **VD2:**

        #include <stdio.h>

        int main() {
            char input[100];
            
            // Chữ cái và space
            printf("Nhập họ tên (chỉ chữ cái và space): ");
            scanf("%[a-zA-Z ]", input);
            printf("Họ tên: %s\n", input);
            
            // Email (a-z, 0-9, @, .)
            printf("Nhập email: ");
            scanf("%[a-zA-Z0-9@.]", input);
            printf("Email: %s\n", input);
            
            // Số điện thoại (0-9, -, +)
            printf("Nhập số điện thoại: ");
            scanf("%[0-9-+]", input);
            printf("SĐT: %s\n", input);
            
            return 0;
        }



#### **2.5.Xử lý buffer**

##### **2.5.1.Vấn đề**

* Newline (\n) còn sót trong buffer sau `%d` hoặc `%s`, gây `%c` đọc sai.

* **VD:**

        #include <stdio.h>

        int main() {
            int age;
            char grade;
            
            printf("Nhập tuổi: ");
            scanf("%d", &age);  // Nhập 25<Enter> → buffer còn '\n'
            
            printf("Nhập xếp loại: ");
            scanf("%c", &grade);  // Đọc '\n' thay vì ký tự mới
            
            printf("Tuổi: %d, Xếp loại: '%c'\n", age, grade);
            
            return 0;
        }

##### **2.5.2.Giải pháp**

* **Clear buffer**

* **VD:**

        #include <stdio.h>

        void clear_input_buffer() {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        int main() {
            int age;
            char grade;
            char name[50];
            
            printf("Nhập tuổi: ");
            scanf("%d", &age);
            clear_input_buffer();
            
            printf("Nhập xếp loại: ");
            scanf("%c", &grade);
            clear_input_buffer();
            
            printf("Nhập tên: ");
            scanf("%49[^\n]", name);  // Nhập đến newline
            
            printf("Tuổi: %d, Xếp loại: '%c', Tên: %s\n", age, grade, name);
            
            return 0;
        }

### **III. CHARACTER I/O**

#### **3.1.Giới thiệu**

##### **3.1.1.Định nghĩa**

* Các hàm nhập/xuất ký tự đơn, làm việc trực tiếp với từng ký tự thay vì chuỗi định dạng.

##### **3.1.2.Ưu điểm**

* Đơn giản, hiệu quả cho xử lý ký tự: Không cần format specifiers, nhanh cho xử lý ký tự lớn.

* Không cần định dạng: Trực tiếp đọc/ghi byte, tránh overhead.

* Làm việc được với mọi luồng (stream): Hỗ trợ stdin/stdout, file, hoặc stream tùy chỉnh.

* Kiểm soát chi tiết từng ký tự

#### **3.2.getchar() và putchar()**

##### **3.2.1.getchar() - Nhập ký tự từ stdin**

* **Cú pháp:**

        #include <stdio.h>
        int getchar(void);


* **Đặc điểm:**

  ◦ Nhận 1 ký tự từ luồng nhập chuẩn (stdin)

  ◦ Trả về `int` thay vì `char` để có thể trả về `EOF`

  ◦ Chờ đến khi có ký tự nhập

        #include <stdio.h>

        int main() {
            int ch; // dùng int để chứa cả ký tự và EOF

            printf("Nhập 1 ký tự: ");
            ch = getchar(); // đọc 1 ký tự từ stdin

            printf("Bạn vừa nhập: %c\n", ch);
            return 0;
        }


        //Nhập 1 ký tự: A
        //Bạn vừa nhập: A

##### **3.2.2.putchar() - Xuất ký tự ra stdout**

* **Cú pháp:**

        #include <stdio.h>
        int putchar(int c);

        VD:putchar('A');

* **Tham số:**

  ◦ c: Ký tự cần xuất dưới dạng int (chỉ 8 bit thấp được sử dụng)

        Xuất ra luồng xuất chuẩn (stdout); trả về ký tự đã xuất hoặc EOF nếu lỗi (ví dụ: stdout bị đóng).

* **Đặc điểm:**

  ◦ Xuất 1 ký tự ra luồng xuất chuẩn (stdout)

  ◦ Nhận tham số `int` nhưng chỉ xuất 8 bit thấp

  ◦ Trả về ký tự đã xuất, hoặc `EOF` nếu lỗi

        #include <stdio.h>

        int main() {
            char ch;

            printf("Nhập 1 ký tự: ");
            ch = getchar();  // nhập ký tự từ bàn phím

            printf("Ký tự bạn vừa nhập là: ");
            putchar(ch);     // xuất ký tự ra màn hình
            putchar('\n');   // in thêm dòng mới

            return 0;
        }



        //Nhập 1 ký tự: !
        //Ký tự bạn vừa nhập là: !


#### **3.3.getc() và putc()**

##### **3.3.1.getc() - Nhập ký tự từ stream**

* **Cú pháp:**

        #include <stdio.h>
        int getc(FILE *stream);

        VD:
        FILE *f = fopen("demo.txt", "r");
        putchar(getc(f));

* **Tham số:**

  ◦ stream: Con trỏ đến FILE (stdin, file đã mở, hoặc stream khác)

        Tương tự getchar() nhưng linh hoạt với stream; có thể là macro (nhanh hơn hàm)
        Trả về ký tự hoặc EOF.

* **Đặc điểm:**

  ◦ Tương tự getchar() nhưng làm việc với stream bất kỳ

  ◦ Có thể là macro hoặc hàm

  ◦ Thường dùng với stdin, file, hoặc stream khác

        #include <stdio.h>

        int main() {
            FILE *f = fopen("demo.txt", "r");
            int ch;

            if (f == NULL) {
                printf("Không thể mở file!\n");
                return 1;
            }

            printf("Nội dung file:\n");
            while ((ch = getc(f)) != EOF) {
                putchar(ch);
            }

            fclose(f);
            return 0;
        }



        //Giả sử file demo.txt chứa:

        Hello KMA!

        //Output:
        Nội dung file:
        Hello KMA!


##### **3.3.2.putc() - Xuất ký tự ra stream**

* **Cú pháp:**

        #include <stdio.h>
        int putc(int c, FILE *stream);


        VD: putc(c, stdout);

* **Tham số:**

  ◦ c: Ký tự dưới dạng int (8 bit thấp).

  ◦ stream: Con trỏ đến FILE (stdout, file đã mở).

        Tương tự putchar() nhưng cho stream tùy chỉnh; có thể là macro

        Trả về ký tự đã xuất hoặc EOF nếu lỗi.

* **Đặc điểm:**

  ◦ Tương tự `putchar()` nhưng làm việc với stream bất kỳ

  ◦ Có thể là macro hoặc hàm

        #include <stdio.h>

        int main() {
            int c;
            
            printf("Nhập văn bản (Enter để kết thúc):\n");
            
            // Sử dụng getc với stdin
            while ((c = getc(stdin)) != '\n' && c != EOF) {
                putc(c, stdout);  // Sử dụng putc với stdout
            }
            
            putc('\n', stdout);
            return 0;
        }


#### **3.4.ungetc() - Đẩy ký tự trở lại buffer**

##### **3.4.1.Cú pháp**

        #include <stdio.h>
        int ungetc(int c, FILE *stream);

        VD:
        ungetc(c, stdin);


##### **3.4.2.Tham số**

* c: Ký tự cần đẩy trở lại dưới dạng int (8 bit thấp).

* stream: Con trỏ đến FILE (stdin, file, v.v.)

        Trả về c nếu thành công, EOF nếu lỗi.

        Chỉ đảm bảo 1 ký tự (implementation-defined cho nhiều hơn)

        Không thay đổi vị trí file nếu thất bại.

##### **3.4.3.Đặc điểm:**

  ◦ Tương tự getchar() nhưng làm việc với stream bất kỳ

  ◦ Có thể là macro hoặc hàm

  ◦ Thường dùng với stdin, file, hoặc stream khác

        #include <stdio.h>

        int main() {
            FILE *f = fopen("demo.txt", "r");
            int ch;

            if (f == NULL) {
                printf("Không thể mở file!\n");
                return 1;
            }

            printf("Nội dung file:\n");
            while ((ch = getc(f)) != EOF) {
                putchar(ch);
            }

            fclose(f);
            return 0;
        }


### **IV. STRING I/O**

#### **4.1.Giới thiệu**

##### **4.1.1.Định nghĩa**

* Các hàm nhập/xuất làm việc trực tiếp với chuỗi ký tự (string buffers) thay vì luồng (streams).

##### **4.1.2.Ưu điểm**

* An toàn hơn so với hàm cũ

* Kiểm soát được kích thước buffer

* Làm việc trực tiếp với bộ nhớ

* Lý tưởng cho parsing và formatting

#### **4.2.fgets() và puts()**

##### **4.2.1.fgets() - Nhập chuỗi an toàn**

* **Cú pháp:**

        #include <stdio.h>
        char *fgets(char *str, int size, FILE *stream);

        VD:
        char buf[20];
        fgets(buf, sizeof(buf), stdin);

* **Tham số:**

  ◦ str: Con trỏ đến buffer char để lưu chuỗi (phải đủ lớn).

  ◦ size: Kích thước tối đa của buffer (đọc tối đa size-1 ký tự, chừa chỗ cho \0).

  ◦ stream: Luồng nguồn (stdin mặc định cho bàn phím).

        Đặc điểm: Dừng khi gặp newline (\n), EOF, hoặc đạt size-1. 
        Tự thêm \0. Trả về str nếu thành công, NULL nếu lỗi/EOF.

* **Đặc điểm:**

  ◦ Đọc tối đa `size-1` ký tự từ stream

  ◦ Tự động thêm \0 vào cuối

  ◦ Dừng khi gặp newline hoặc EOF

  ◦ Trả về `str` nếu thành công, `NULL` nếu lỗi

        #include <stdio.h>

        int main() {
            char buf[20];

            printf("Nhập một dòng (tối đa 19 ký tự): ");
            if (fgets(buf, sizeof(buf), stdin) != NULL) {
                printf("Bạn vừa nhập: %s", buf);
            } else {
                printf("Đọc chuỗi thất bại hoặc gặp EOF.\n");
            }

            return 0;
        }


        //Input: Hello C Programming!
        //Output: Bạn vừa nhập: Hello C Programming!

##### **4.2.2.puts() - Xuất chuỗi**

* **Cú pháp:**

        #include <stdio.h>
        int puts(const char *str);

        VD:
        puts("Hello, World!");

* **Tham số:**

  ◦ str: Con trỏ đến chuỗi null-terminated (const để không thay đổi).

        Xuất đến \0, tự thêm \n ở cuối 

        Trả về giá trị không âm nếu thành công, EOF nếu lỗi

        Không xuất \n nếu đã có trong str.

* **Đặc điểm:**

  ◦ Xuất chuỗi ra stdout

  ◦ Tự động thêm newline

  ◦ Trả về EOF nếu lỗi, giá trị không âm nếu thành công

        #include <stdio.h>

        int main() {
            char name[100];
            
            printf("Nhập tên của bạn: ");
            
            // Sử dụng fgets thay vì gets (an toàn hơn)
            if (fgets(name, sizeof(name), stdin) != NULL) {
                printf("Xin chào, ");
                puts(name);  // puts tự động thêm newline
            } else {
                printf("Lỗi khi nhập tên!\n");
            }
            
            return 0;
        }


            // Nhập tên của bạn: Tùng
            // Xin chào, Tùng

#### **4.3.sprintf() và sscanf()**

##### **4.3.1.sprintf() - Format vào string buffer**

* **Cú pháp:**

        #include <stdio.h>
        int sprintf(char *str, const char *format, ...);

        VD:
        char buf[50]; 
        sprintf(buf, "Tuổi: %d", 30);

* **Tham số:**

  ◦ `str`: Buffer để ghi chuỗi (phải đủ lớn, không kiểm soát size → rủi ro overflow).

  ◦ `format`: Chuỗi định dạng (như %d, %s).

  ◦ `...`: Đối số tương ứng (int, float, v.v.).

        Đặc điểm: Ghi đến \0, trả về số ký tự ghi (không tính \0).

        Cảnh báo: Không an toàn; dùng snprintf() thay thế.

* **Đặc điểm:**

  ◦ Đọc tối đa `size-1` ký tự từ stream

  ◦ Tự động thêm \0 vào cuối

  ◦ Dừng khi gặp newline hoặc EOF

  ◦ Trả về `str` nếu thành công, `NULL` nếu lỗi

        #include <stdio.h>

        int main() {
            char buf[20];

            printf("Nhập một dòng (tối đa 19 ký tự): ");
            if (fgets(buf, sizeof(buf), stdin) != NULL) {
                printf("Bạn vừa nhập: %s", buf);
            } else {
                printf("Đọc chuỗi thất bại hoặc gặp EOF.\n");
            }

            return 0;
        }


        //Input: Hello C Programming!
        //Output: Bạn vừa nhập: Hello C Programming!

##### **4.3.2.sscanf() - Đọc từ string buffer**

* **Cú pháp:**

        #include <stdio.h>
        int sscanf(const char *str, const char *format, ...);

        VD:
        int age;
        sscanf("25", "%d", &age);

* **Tham số:**

  ◦ `str`: Chuỗi nguồn để đọc (const).

  ◦ `format`: Chuỗi định dạng (như %d, %s).

  ◦ `...`: Con trỏ đến biến nhận giá trị (&var cho scalar, mảng cho string)

        Trả về số biến đọc thành công 
        Dừng khi không khớp format.

* **Đặc điểm:**

  ◦ Tương tự scanf() nhưng đọc từ string buffer

  ◦ Trả về số biến được đọc thành công

        #include <stdio.h>

        int main() {
            char str[] = "25 3.14 hello";  // Chuỗi nguồn
            int num;
            float f;
            char word[10];
            
            // sscanf: Đọc từ str theo format "%d %f %s"
            int ret = sscanf(str, "%d %f %s", &num, &f, word);
            
            // In kết quả
            printf("Số biến đọc thành công: %d\n", ret);
            printf("num = %d\n", num);
            printf("f = %.2f\n", f);
            printf("word = %s\n", word);
            
            return 0;
        }


        Số biến đọc thành công: 3
        num = 25
        f = 3.14
        word = hello

### **V. ERROR HANDLING VỚI I/O**

#### **5.1.Giới thiệu**

##### **5.1.1.Tầm quan trọng**

* Xử lý lỗi (error handling) là kỹ thuật phát hiện, báo cáo và khắc phục các vấn đề xảy ra trong quá trình nhập/xuất dữ liệu (I/O), như đọc/ghi file, nhập từ bàn phím, hoặc kết nối mạng.

* Trong C, I/O có thể thất bại do nhiều lý do: file không tồn tại, hết bộ nhớ, quyền truy cập bị từ chối, hoặc lỗi hệ thống (hardware/network)

##### **5.1.2.Lợi ích chính**

* Phát hiện và xử lý kịp thời: Tránh chương trình tiếp tục chạy với dữ liệu sai lệch.

* Ngăn chặn undefined behavior: C chuẩn yêu cầu kiểm tra return value của hàm I/O (như fopen() trả NULL nếu lỗi).

* Debug dễ dàng hơn: Log lỗi chi tiết giúp trace vấn đề nhanh chóng.

##### **5.1.3.Nguyên tắc**

* Luôn kiểm tra `return value` của hàm I/O (thành công: giá trị dương; lỗi: -1, NULL, hoặc 0).

* Sử dụng `errno` để lấy mã lỗi hệ thống.

* Kết hợp với `perror()` hoặc `strerror() `để in mô tả lỗi.

* Dọn dẹp tài nguyên (fclose, free) trước khi thoát để tránh leak.


#### **5.2.Sử dụng errno từ <errno.h>**

##### **5.2.1.Lý thuyết**

* `errno` là biến toàn cục (global) lưu mã lỗi số nguyên từ lần gọi hàm thất bại gần nhất.

*  Nó được set bởi các hàm thư viện chuẩn (như `fopen()`, `malloc()`) khi lỗi xảy ra.

*  Không phải lúc nào cũng set (chỉ khi lỗi), và có thể bị ghi đè bởi hàm khác.

##### **5.2.2.Các mã lỗi phổ biến**

| Mã lỗi | Tên hằng số | Ý nghĩa phổ biến trong I/O | Ví dụ tình huống |
|--------|-------------|----------------------------|-----------------|
| 2      | ENOENT      | No such file or directory | File không tồn tại (fopen) |
| 13     | EACCES      | Permission denied         | Không có quyền đọc/ghi file |
| 22     | EINVAL      | Invalid argument          | Tham số sai (ví dụ: mode không hợp lệ) |
| 12     | ENOMEM      | Out of memory             | Hết RAM khi alloc buffer lớn |
| 5      | EIO         | Input/output error        | Lỗi đĩa cứng, network timeout |
| 11     | EAGAIN      | Resource temporarily unavailable | Non-blocking I/O bị chặn |
| 9      | EBADF       | Bad file descriptor       | FILE* không hợp lệ (đóng rồi) |
| 4      | EINTR       | Interrupted system call   | Signal gián đoạn (Ctrl+C) |
| 28     | ENOSPC      | No space left on device   | Hết dung lượng đĩa khi ghi file |

* **Lưu ý:** Mã số có thể khác tùy OS (Linux vs Windows). Dùng hằng số (ENOENT) thay vì số cứng để portable.


        #include <stdio.h>
        #include <errno.h>
        #include <string.h>

        int main() {
            FILE *file;
            
            // Cố mở file không tồn tại
            file = fopen("file_khong_ton_tai.txt", "r");
            
            if (file == NULL) {
                printf("Lỗi khi mở file!\n");
                printf("Mã lỗi: %d (%s)\n", errno, strerror(errno));  // strerror() mô tả
                
                // Kiểm tra cụ thể
                if (errno == ENOENT) {
                    printf("File không tồn tại! Hãy kiểm tra đường dẫn.\n");
                } else if (errno == EACCES) {
                    printf("Không có quyền truy cập! Kiểm tra quyền file.\n");
                } else {
                    printf("Lỗi khác: %s\n", strerror(errno));
                }
                
                // Reset errno cho lần gọi sau
                errno = 0;
            } else {
                printf("Mở file thành công!\n");
                fclose(file);
            }
            
            return 0;
        }


        Lỗi khi mở file!
        Mã lỗi: 2 (No such file or directory)
        File không tồn tại! Hãy kiểm tra đường dẫn.

#### **5.3.perror() và strerror()**

##### **5.3.1.perror()**

* **Định nghĩa:**

  ◦ perror(): In thông báo lỗi chuẩn hóa ra stderr.

* **Cú pháp:**

        #include <stdio.h>
        void perror(const char *s);  // Không trả về giá trị

        VD:perror("Thông báo lỗi");

* **Tham số:**

  ◦ s: Chuỗi mô tả ngữ cảnh (ví dụ: "fopen failed"). 
  
        Nếu NULL, chỉ in mô tả errno.

        In format: s: mô tả lỗi từ errno\n.

        Tự động dùng errno hiện tại; không thay đổi errno.

        #include <stdio.h>
        #include <errno.h>

        int main() {
            FILE *f = fopen("nofile.txt", "r");  // file không tồn tại
            if (!f) {
                perror("Mở file thất bại");  // in lỗi ra stderr
            }
            return 0;
        }

        Mở file thất bại: No such file or directory



##### **5.3.2.strerror()**

* **Định nghĩa:**

  ◦ strerror(): Trả về chuỗi mô tả lỗi

* **Cú pháp:**

        #include <string.h>
        char *strerror(int errnum);

        VD:strerror(ENOENT);

* **Tham số:**

  ◦ errnum: Mã lỗi (thường là errno).
  
        Trả về con trỏ đến chuỗi tĩnh (không free);

        không thay đổi errno

        #include <stdio.h>
        #include <string.h>
        #include <errno.h>

        int main() {
            int err = ENOENT;  // file không tồn tại
            printf("Lỗi: %s\n", strerror(err));
            return 0;
        }

        Lỗi: No such file or directory

#### **5.4.Kiểm tra Return Value của Hàm I/O**

##### **5.4.1.Nguyên tắc chung**

* **Luôn kiểm tra:**

  ◦ Mỗi hàm I/O trả về indicator lỗi (NULL cho fopen, -1 cho read/write, 0 cho fread/fwrite nếu không đầy đủ).

* **Xử lý ngay:**

  ◦ Dọn dẹp (fclose, free) và thoát/log lỗi.

* **Kết hợp errno:**

  ◦ Sau khi kiểm tra return, dùng errno/perror để chi tiết.

* **Kiểm tra ferror/feof:**

  ◦ Sau fread/fwrite, dùng ferror(stream) (lỗi) hoặc feof(stream) (hết file).

        #include <stdio.h>
        #include <errno.h>
        #include <string.h>
        #include <stdlib.h>

        #define CHECK_NULL(ptr, msg) \
            do { \
                if ((ptr) == NULL) { \
                    fprintf(stderr, "Lỗi: %s (errno: %d - %s)\n", \
                        (msg), errno, strerror(errno)); \
                    exit(EXIT_FAILURE); \
                } \
            } while(0)

        #define CHECK_IO(result, expected, msg) \
            do { \
                if ((result) != (expected)) { \
                    fprintf(stderr, "Lỗi: %s (kết quả: %zd, mong đợi: %zd; errno: %d - %s)\n", \
                        (msg), (result), (expected), errno, strerror(errno)); \
                    exit(EXIT_FAILURE); \
                } \
            } while(0)

        void safe_file_operations() {
            FILE *source, *destination;
            char buffer[1024];
            size_t bytes_read, bytes_written;
            
            // Mở file (giả sử source.txt tồn tại)
            source = fopen("source.txt", "rb");
            CHECK_NULL(source, "Không thể mở file nguồn");
            
            destination = fopen("destination.txt", "wb");
            CHECK_NULL(destination, "Không thể tạo file đích");
            
            // Sao chép
            while ((bytes_read = fread(buffer, 1, sizeof(buffer), source)) > 0) {
                bytes_written = fwrite(buffer, 1, bytes_read, destination);
                CHECK_IO(bytes_written, bytes_read, "Ghi file thất bại");
            }
            
            // Kiểm tra lỗi đọc
            if (ferror(source)) {
                fprintf(stderr, "Lỗi đọc file nguồn: %s\n", strerror(errno));
                fclose(source);
                fclose(destination);
                exit(EXIT_FAILURE);
            }
            
            if (feof(source)) {
                printf("Đã đọc hết file nguồn.\n");
            }
            
            printf("Sao chép file thành công!\n");
            
            if (fclose(source) != 0 || fclose(destination) != 0) {
                fprintf(stderr, "Lỗi đóng file: %s\n", strerror(errno));
            }
        }

        int main() {
            safe_file_operations();
            return 0;
        }

        Đã đọc hết file nguồn.
        Sao chép file thành công!

</details> 
<details>
	<summary><strong>CHƯƠNG 3: CẤU TRÚC ĐIỀU KHIỂN</strong></summary>

## **CHƯƠNG 3: CẤU TRÚC ĐIỀU KHIỂN**

### **I. CÂU LỆNH ĐIỀU KIỆN IF-ELSE**

#### **1.1.Giới thiệu if-else**

##### **1.1.1.Định nghĩa**

* Câu lệnh điều kiện if-else là cấu trúc điều khiển cơ bản cho phép chương trình thực thi các khối lệnh khác nhau dựa trên việc kiểm tra một hoặc nhiều điều kiện logic.

##### **1.1.2.Mục đích**

* Thực hiện các hành động khác nhau tùy theo điều kiện

* Kiểm soát luồng thực thi của chương trình

* Xử lý các tình huống đặc biệt và lỗi

* Tạo ra các nhánh logic trong chương trình
                   
#### **1.2.Các dạng if-else**

##### **1.2.1. IF đơn giản**

* **Cú pháp:** 

        if (điều_kiện) {
            // Khối lệnh thực thi nếu điều_kiện đúng (true)
        }

* **Đặc điểm:**

  ◦ Chỉ thực thi khối lệnh khi điều kiện đúng

  ◦ Nếu điều kiện sai, bỏ qua khối lệnh


        #include <stdio.h>

        int main() {
            int tuoi;
            
            printf("Nhập tuổi của bạn: ");
            scanf("%d", &tuoi);
            
            // Kiểm tra điều kiện đơn giản
            if (tuoi >= 18) {
                printf("Bạn đã đủ tuổi trưởng thành.\n");
            }
            
            printf("Chương trình kết thúc.\n");
            return 0;
        }

##### **1.2.2. IF-ELSE**

* **Cú pháp:** 

        if (điều_kiện) {
            // Khối lệnh thực thi nếu điều_kiện đúng
        } else {
            // Khối lệnh thực thi nếu điều_kiện sai
        }

* **Đặc điểm:**

  ◦ Luôn có một trong hai khối lệnh được thực thi

  ◦ Bao phủ mọi trường hợp có thể xảy ra


        #include <stdio.h>

        int main() {
            int so;
            
            printf("Nhập một số nguyên: ");
            scanf("%d", &so);
            
            if (so % 2 == 0) {
                printf("%d là số chẵn.\n", so);
            } else {
                printf("%d là số lẻ.\n", so);
            }
            
            return 0;
        }

##### **1.2.3. IF-ELSE IF-ELSE**

* **Cú pháp:** 

        if (điều_kiện_1) {
            // Khối lệnh thực thi nếu điều_kiện_1 đúng
        } else if (điều_kiện_2) {
            // Khối lệnh thực thi nếu điều_kiện_2 đúng
        } else if (điều_kiện_3) {
            // Khối lệnh thực thi nếu điều_kiện_3 đúng
        } else {
            // Khối lệnh thực thi nếu tất cả điều kiện sai
        }

* **Đặc điểm:**

  ◦ Kiểm tra tuần tự các điều kiện từ trên xuống

  ◦ Chỉ thực thi khối lệnh đầu tiên có điều kiện đúng

  ◦ Có thể có nhiều mệnh đề else if

        #include <stdio.h>

        int main() {
            float diem;
            
            printf("Nhập điểm (0-10): ");
            scanf("%f", &diem);
            
            if (diem >= 9.0) {
                printf("Xếp loại: Xuất sắc\n");
            } else if (diem >= 8.0) {
                printf("Xếp loại: Giỏi\n");
            } else if (diem >= 7.0) {
                printf("Xếp loại: Khá\n");
            } else if (diem >= 5.5) {
                printf("Xếp loại: Trung bình\n");
            } else if (diem >= 4.0) {
                printf("Xếp loại: Yếu\n");
            } else {
                printf("Xếp loại: Kém\n");
            }
            
            return 0;
        }


#### **1.3.Short-circuit Evaluation**

##### **1.3.1.Khái niệm**

* **Short-circuit evaluation** là cơ chế trong đó trình biên dịch dừng đánh giá biểu thức logic ngay khi kết quả cuối cùng đã được xác định.

##### **1.3.2.Nguyên tắc hoạt động**

* **Với toán tử AND (&&):** Nếu vế trái sai, không cần kiểm tra vế phải

* **Với toán tử OR (||):** Nếu vế trái đúng, không cần kiểm tra vế phải

        #include <stdio.h>

        int main() {
            int x = 10;
            int *p1 = &x, *p2 = NULL;

            // Short-circuit với AND
            if (p1 && *p1 > 5) printf("p1 hợp lệ và > 5\n");
            if (p2 && *p2 > 5) printf("Không in vì p2 NULL\n");
            else printf("p2 không hợp lệ - an toàn\n");

            // Short-circuit với OR
            int a = 1, b = 0;
            if (a == 1 || b == 1) printf("a bằng 1, không kiểm tra b\n");

            return 0;
        }

#### **1.4.Nested if statements**

##### **1.4.1.Khái niệm**

* **Nested if** là cấu trúc if-else lồng bên trong nhau, cho phép kiểm tra các điều kiện phức tạp theo nhiều cấp độ.

##### **1.4.2.Cú pháp**

        if (điều_kiện_ngoài) {
            // Khối lệnh ngoài
            if (điều_kiện_trong) {
                // Khối lệnh trong
            } else {
                // Khối lệnh else trong
            }
        } else {
            // Khối lệnh else ngoài
        }

* **VD:**

        #include <stdio.h>

        int main() {
            int x = 10, y = 5;

            if (x > 0) {
                if (y > 0)
                    printf("Cả x và y đều dương\n");
                else
                    printf("x dương, y không dương\n");
            } else {
                printf("x không dương\n");
            }

            return 0;
        }
       

### **II. SWITCH-CASE**

#### **2.1.Tổng quan**

##### **2.1.1.Định nghĩa**

* Switch-case là cấu trúc điều khiển cho phép lựa chọn một trong nhiều khối lệnh để thực thi dựa trên giá trị của một biểu thức.

##### **2.1.2.Đặc điểm**

* Chỉ làm việc với kiểu dữ liệu nguyên (int, char, enum)

* Hiệu quả hơn if-else khi có nhiều trường hợp

* Sử dụng break để ngăn fall-through

##### **2.1.3.Cú pháp**

        switch (biểu_thức) {
            case giá_trị_1:
                // Khối lệnh 1
                break;
            case giá_trị_2:
                // Khối lệnh 2
                break;
            // ...
            default:
                // Khối lệnh mặc định
        }

* **VD:**

        #include <stdio.h>

        int main() {
            int day;
            printf("Nhập số thứ tự ngày (1-7): ");
            scanf("%d", &day);
            
            switch (day) {
                case 1:
                    printf("Chủ Nhật\n");
                    break;
                case 2:
                    printf("Thứ Hai\n");
                    break;
                case 3:
                    printf("Thứ Ba\n");
                    break;
                case 4:
                    printf("Thứ Tư\n");
                    break;
                case 5:
                    printf("Thứ Năm\n");
                    break;
                case 6:
                    printf("Thứ Sáu\n");
                    break;
                case 7:
                    printf("Thứ Bảy\n");
                    break;
                default:
                    printf("Số không hợp lệ!\n");
            }
            return 0;
            }

#### **2.2.Break và Fall-through Behavior**

##### **2.2.1.Khái niệma**

* **Break:** Là lệnh dừng (exit) ngay lập tức khỏi khối switch. 

  ◦ Khi gặp break, chương trình sẽ nhảy ra khỏi toàn bộ cấu trúc switch và tiếp tục thực thi lệnh tiếp theo bên ngoài (thường là sau khối switch).

  ◦ Ngăn chặn việc thực thi các case tiếp theo một cách không mong muốn

* **Fall-through:** Là hành vi fall through khi không có break ở cuối một case 

  ◦ Code sẽ tiếp tục thực thi các lệnh của case tiếp theo, và cứ thế cho đến khi gặp break đầu tiên hoặc kết thúc toàn bộ switch.

  ◦ Cho phép nhóm nhiều case có hành vi tương tự mà không cần lặp code.

  ◦ Dễ gây nhầm lẫn và lỗi bảo trì, vì code có thể chạy nhiều khối lệnh không dự đoán

##### **2.2.2.Lưu ý**

* `switch` trong C không kiểm tra điều kiện cho các case sau; nó chỉ khớp giá trị ban đầu và thực thi tuyến tính từ case khớp đến break đầu tiên.

* `default` cũng có thể fall-through nếu không có break, nhưng thường nên đặt break cho nó.

* `Fall-through` chỉ xảy ra xuống dưới (không nhảy lên), và chỉ trong cùng một khối switch.

##### **2.2.3.VD**

* **Với break (ngăn fall-through):**

        #include <stdio.h>

        int main() {
            int grade = 2;
            
            switch (grade) {
                case 1:
                    printf("Xuất sắc\n");
                    break;
                case 2:
                    printf("Giỏi\n");
                    break;  // Dừng tại đây
                case 3:
                    printf("Khá\n");
                    break;
                default:
                    printf("Trung bình\n");
            }
            // Kết quả: "Giỏi"
            
            return 0;
        }

* **Không có break (fall-through):**

        #include <stdio.h>

        int main() {
            int month;
            printf("Nhập tháng (1-12): ");
            scanf("%d", &month);
            
            switch (month) {
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                    printf("Tháng có 31 ngày\n");
                    break;
                case 4: case 6: case 9: case 11:
                    printf("Tháng có 30 ngày\n");
                    break;
                case 2:
                    printf("Tháng có 28 hoặc 29 ngày\n");
                    break;
                default:
                    printf("Tháng không hợp lệ\n");
            }
            
            return 0;
        }


### **III. TOÁN TỬ ĐIỀU KIỆN**

#### **3.1.Giới thiệu**

##### **3.1.1.Định nghĩa**

* Toán tử điều kiện (ternary operator) là toán tử ba ngôi cho phép viết câu lệnh điều kiện ngắn gọn trong một dòng.

##### **3.1.2.Cú pháp**

        biểu_thức_điều_kiện ? biểu_thức_1 : biểu_thức_2

* **biểu_thức_điều_kiện:** Phải trả về giá trị bool (non-zero = true).

* **biểu_thức_1:** Thực thi nếu điều kiện đúng (true).

* **biểu_thức_2:** Thực thi nếu điều kiện sai (false).

        #include <stdio.h>

        int main() {
            int number;
            printf("Nhập một số: ");
            scanf("%d", &number);
            
            printf("Số %d là số %s\n", 
                number, 
                (number % 2 == 0) ? "chẵn" : "lẻ");
            
            printf("Số %d là %s\n",
                number,
                (number > 0) ? "dương" : (number < 0) ? "âm" : "bằng 0");
            
            return 0;
        }

#### **3.2.Nested ternary operators**

##### **3.2.1.Khái niệm**

* **Nested ternary** là việc lồng ghép nhiều toán tử ternary bên trong nhau, tương tự if-else if-else chain.

##### **3.2.2.Cách hoạt động**

* Mỗi ternary là một biểu thức độc lập, nhưng nested làm chúng phụ thuộc.

* Ưu tiên: Dùng ngoặc để rõ ràng, tránh ambiguity (ví dụ: `(cond1 ? expr1 : cond2) ? expr2 : expr3)`.

        #include <stdio.h>

        int main() {
            int score;
            printf("Nhập điểm (0-100): ");
            scanf("%d", &score);
            
            // Nested ternary: Right-associative, kiểm tra từ trên xuống
            char *grade = (score >= 90) ? "A" :
                        (score >= 80) ? "B" :
                        (score >= 70) ? "C" :
                        (score >= 60) ? "D" : "F";
            
            printf("Điểm %d -> Xếp loại %s\n", score, grade);
            
            return 0;
        }


##### **3.2.3.Ứng dụng trong macro**

* Ternary rất phù hợp cho macro vì macro là text replacement (preprocessor), không có scope hay type checking.

* Nó cho phép tạo hàm-like macro ngắn gọn mà không cần function thực (tiết kiệm stack)

* Tuy nhiên, cần ngoặc đơn đầy đủ để tránh side effects

* Vấn đề side effects:

  ◦ `#define MAX(a,b) a > b ? a : b` → `MAX(i++, j++)` có thể ++ hai lần.

  ◦ Giải pháp: `#define MAX(a,b) ((a)>(b)?(a):(b))` – evaluate mỗi arg chỉ một lần.

        #include <stdio.h>

        #define MAX(a, b) ((a) > (b) ? (a) : (b))
        #define MIN(a, b) ((a) < (b) ? (a) : (b))
        #define ABS(x) ((x) >= 0 ? (x) : -(x))

        int main() {
            int x = -10, y = 20;
            
            printf("Max(%d, %d) = %d\n", x, y, MAX(x, y));
            printf("Min(%d, %d) = %d\n", x, y, MIN(x, y));
            printf("Abs(%d) = %d\n", x, ABS(x));
            printf("Abs(%d) = %d\n", y, ABS(y));
            
            return 0;
        }


</details> 
<details>
	<summary><strong>CHƯƠNG 4: VÒNG LẶP</strong></summary>

## **CHƯƠNG 4: VÒNG LẶP**

### **I. VÒNG LẶP FOR**

#### **1.1.Giới thiệu**

##### **1.1.1.Định nghĩa**

* Vòng lặp for là một cấu trúc điều khiển lặp trong ngôn ngữ C, được thiết kế để thực thi một khối lệnh lặp lại một số lần xác định trước, thường dựa trên một biến đếm (counter variable)

* Nó là loại vòng lặp **entry-controlled** (kiểm soát trước khi vào), nơi toàn bộ logic lặp (khởi tạo, kiểm tra điều kiện, cập nhật) được đặt gọn gàng trong một dòng cú pháp duy nhất.

##### **1.1.2.Mục đích**

* Thực thi lặp với số lần cố định hoặc dựa trên điều kiện đếm tăng/giảm dần.

* Xử lý mảng, chuỗi, hoặc các cấu trúc dữ liệu tuyến tính.

* Tối ưu hóa code bằng cách tích hợp khởi tạo, kiểm tra, và cập nhật trong một cấu trúc.


##### **1.1.3.Cách hoạt động tổng quát**

* **1.Khởi tạo (initialization):** Thực thi một lần trước khi kiểm tra điều kiện (ví dụ: i = 0).

* **2.Kiểm tra điều kiện (condition):** Đánh giá trước mỗi lần lặp; nếu false, thoát vòng.

* **3.Thực thi khối lệnh (body):** Chạy code bên trong nếu điều kiện true.

* **4.Cập nhật (update/increment):** Thực thi sau mỗi lần lặp (ví dụ: i++).

* **5.Lặp lại từ bước 2** 

##### **1.1.4.Cú pháp**

        for (khởi_tạo; điều_kiện; cập_nhật) {
            // Khối lệnh được lặp
        }

* **Khởi_tạo:** Biểu thức gán hoặc khai báo biến (có thể nhiều, phân cách bằng dấu phẩy).

* **Điều_kiện:** Biểu thức bool (non-zero = true); mặc định true nếu rỗng.

* **Cập_nhật:** Biểu thức tăng/giảm (có thể phức tạp như i += 2, j--).

* Các phần có thể rỗng (ví dụ: `for (;;)` cho vô hạn).

* Scope: Biến khởi tạo (C99+) chỉ tồn tại trong vòng lặp.

        #include <stdio.h>

        int main() {
            // In các số từ 1 đến 10
            for (int i = 1; i <= 10; i++) {
                printf("%d ", i);
            }
            printf("\n");
            
            return 0;
        }

#### **1.2.Multiple Initialization**

##### **1.2.1.Khái niệm**

* Từ C99, vòng lặp for hỗ trợ khởi tạo và cập nhật nhiều biến trong cùng một phần (phân cách bằng dấu phẩy).

* Điều kiện có thể dùng toán tử logic cho nhiều biến.

##### **1.2.2.VD**

        #include <stdio.h>

        int main() {
            // Multiple initialization
            for (int i = 0, j = 10; i <= 10 && j >= 0; i++, j--) {
                printf("i = %d, j = %d\n", i, j);
            }
            
            // Vòng lặp với nhiều biến phức tạp
            for (int i = 0, count = 0, sum = 0; i < 5; i++, count++) {
                sum += i;
                printf("Lần %d: i=%d, count=%d, sum=%d\n", i+1, i, count, sum);
            }
            
            return 0;
        }

#### **1.3.Vòng lặp vô hạn**

##### **1.3.1.Khái niệm**

* Khi điều kiện luôn true (rỗng hoặc hằng true), vòng lặp chạy mãi trừ khi dùng `break`.

* Thường dùng cho event loops (server, game) hoặc simulation.

##### **1.3.2.VD**

        #include <stdio.h>

        int main() {
            int count = 0;
            
            // Vòng lặp vô hạn với break condition
            for (;;) {
                printf("Lần lặp thứ %d\n", ++count);
                
                if (count >= 5) {
                    printf("Đã đủ 5 lần, thoát vòng lặp.\n");
                    break;
                }
            }
            
            // Ứng dụng: Server listening
            int request_count = 0;
            for (;;) {
                printf("Đang chờ request... (Request số %d)\n", ++request_count);
                
                // Giả lập xử lý request
                if (request_count >= 3) {
                    printf("Server dừng sau 3 request.\n");
                    break;
                }
            }
            
            return 0;
        }


#### **1.4.Optimization Considerations**

##### **1.4.1.Khái niệm**

* Tối ưu vòng lặp nhằm giảm thời gian chạy, đặc biệt với dữ liệu lớn.

* Các kỹ thuật bao gồm loop-invariant hoisting (chuyển tính toán ra ngoài), unrolling (mở rộng vòng lặp), và tránh function calls trong điều kiện.

##### **1.4.2.Lý thuyết tối ưu**

* **Loop-invariant:** Tính toán không đổi (như strlen) chỉ gọi một lần.

        #include <stdio.h>
        #include <string.h>

        int main() {
            char str[] = "Hello";
            int len = strlen(str); // loop-invariant: tính strlen 1 lần

            for (int i = 0; i < len; i++) {
                printf("%c ", str[i]);
            }
            return 0;
        }


* **Loop unrolling:** Giảm số lần kiểm tra điều kiện bằng cách lặp nhiều bước (compiler tự động, hoặc thủ công).

        #include <stdio.h>

        int main() {
            int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            int sum = 0;
            
            // Cách thông thường
            for (int i = 0; i < 10; i++) {
                sum += array[i];
            }
            printf("Tổng (thông thường): %d\n", sum);
            
            // Loop unrolling - giảm số lần lặp
            sum = 0;
            for (int i = 0; i < 10; i += 2) {
                sum += array[i];
                if (i + 1 < 10) {  // Tránh truy cập ngoài phạm vi
                    sum += array[i + 1];
                }
            }
            printf("Tổng (unrolled): %d\n", sum);
            
            return 0;
        }

### **II. VÒNG LẶP WHILE**

#### **2.1.Giới thiệu**

##### **2.1.1.Định nghĩa**

* Vòng lặp while là cấu trúc lặp pre-test (kiểm tra điều kiện trước khi thực thi khối lệnh)

* Phù hợp khi số lần lặp không xác định trước hoặc phụ thuộc vào điều kiện động (như input người dùng hoặc dữ liệu file).

##### **2.1.2.Mục đích**

* Lặp dựa trên điều kiện thay đổi (ví dụ: đọc file đến EOF).

* Input validation hoặc simulation (game loop).


##### **2.1.3.Cách hoạt động tổng quát**

* **1.Kiểm tra điều kiện (true/false).**

* **2.Nếu true, thực thi khối lệnh.** 

* **3.Cập nhật (thủ công, thường trong body).** 

* **4.Lặp lại từ bước 1.** 


##### **2.1.4.Cú pháp**

        while (điều_kiện) {
            // Khối lệnh được lặp
        }

* **điều_kiện:** iều kiện là biểu thức bool; body phải có code cập nhật để tránh vô hạn. Thường dùng với biến flag hoặc counter.

        #include <stdio.h>

        int main() {
            int count = 1;
            
            // In các số từ 1 đến 5
            while (count <= 5) {
                printf("Số thứ %d\n", count);
                count++;
            }
            
            return 0;
        }

#### **2.2.Pre-test Loop Characteristic**

##### **2.2.1.Khái niệm**

* Pre-test Loop Characteristic là zero-iteration loop có thể (không chạy nếu điều kiện false ban đầu).

* Điều này khác với do-while (luôn chạy ít nhất một lần).

##### **2.2.2.VD**

        #include <stdio.h>

        int main() {
            int number;
            
            // Pre-test: có thể không chạy lần nào
            printf("Nhập số âm để bắt đầu: ");
            scanf("%d", &number);
            
            while (number < 0) {
                printf("Số bạn nhập: %d (số âm)\n", number);
                printf("Nhập số tiếp theo (số dương để dừng): ");
                scanf("%d", &number);
            }
            
            printf("Đã thoát vòng lặp với số: %d\n", number);
            
            return 0;
        }

        Nhập số âm để bắt đầu: -5
        Số bạn nhập: -5 (số âm)
        Nhập số tiếp theo (số dương để dừng): -2
        Số bạn nhập: -2 (số âm)
        Nhập số tiếp theo (số dương để dừng): 3
        Đã thoát vòng lặp với số: 3

### **III. VÒNG LẶP DO-WHILE**

#### **3.1.Giới thiệu**

##### **3.1.1.Định nghĩa**

* Vòng lặp do-while là cấu trúc post-test (thực thi khối lệnh trước, kiểm tra điều kiện sau), đảm bảo ít nhất một lần thực thi dù điều kiện false.

##### **3.1.2.Cách hoạt động tổng quát**

* **1.Thực thi khối lệnh.**

* **2.Kiểm tra điều kiện.** 

* **3.Nếu true, lặp lại từ 1; nếu false, thoát.**

* **Lưu ý:** Dấu chấm phẩy ; sau while bắt buộc. 


##### **3.1.3.Cú pháp**

        do {
            // Khối lệnh được lặp
        } while (điều_kiện);

#### **3.2.Ứng dụng**

##### **3.2.1.Hệ thống menu đơn giản**

        #include <stdio.h>

        int main() {
            int choice;
            
            do {
                printf("\n=== HỆ THỐNG QUẢN LÝ SINH VIÊN ===\n");
                printf("1. Thêm sinh viên\n");
                printf("2. Xóa sinh viên\n");
                printf("3. Hiển thị danh sách\n");
                printf("4. Tìm kiếm sinh viên\n");
                printf("0. Thoát\n");
                printf("Chọn chức năng: ");
                scanf("%d", &choice);
                
                switch (choice) {
                    case 1:
                        printf("Đang thêm sinh viên...\n");
                        break;
                    case 2:
                        printf("Đang xóa sinh viên...\n");
                        break;
                    case 3:
                        printf("Đang hiển thị danh sách...\n");
                        break;
                    case 4:
                        printf("Đang tìm kiếm sinh viên...\n");
                        break;
                    case 0:
                        printf("Thoát chương trình.\n");
                        break;
                    default:
                        printf("Lựa chọn không hợp lệ!\n");
                }
            } while (choice != 0);
            
            return 0;
        }


##### **3.2.2.Chơi trò đoán số**

        #include <stdio.h>
        #include <stdlib.h>
        #include <time.h>

        int main() {
            srand(time(0));
            int secret = rand() % 10 + 1;
            int guess;
            do {
                printf("Đoán số (1-10): ");
                scanf("%d", &guess);
                if(guess < secret) printf("Nhỏ quá!\n");
                else if(guess > secret) printf("Lớn quá!\n");
            } while(guess != secret);

            printf("Chính xác! Số là %d\n", secret);
            return 0;
        }

### **IV. ĐIỀU KHIỂN VÒNG LẶP**

#### **4.1.Break Statement**

##### **4.1.1.Tác dụng**

* `break` chấm dứt vòng lặp gần nhất (hoặc switch), chuyển đến lệnh sau vòng.

* Hữu ích cho early termination (tìm kiếm, error handling).

* **Scope:** Chỉ ảnh hưởng vòng lặp/switch chứa nó; không thoát nested loops trừ khi flag.

##### **4.1.2.VD**

        #include <stdio.h>

        int main() {
            // Tìm số đầu tiên chia hết cho 7
            for (int i = 1; i <= 100; i++) {
                if (i % 7 == 0) {
                    printf("Số đầu tiên chia hết cho 7 là: %d\n", i);
                    break;  // Thoát vòng lặp ngay
                }
            }
            
            // Tìm kiếm trong mảng
            int numbers[] = {2, 4, 6, 8, 10, 12};
            int target = 8;
            int found = 0;
            
            for (int i = 0; i < 6; i++) {
                if (numbers[i] == target) {
                    printf("Tìm thấy %d tại vị trí %d\n", target, i);
                    found = 1;
                    break;
                }
            }
            
            if (!found) {
                printf("Không tìm thấy %d trong mảng\n", target);
            }
            
            return 0;
        }

#### **4.2.Continue Statement**

##### **4.2.1.Tác dụng**

* `continue` bỏ qua phần còn lại của body hiện tại, nhảy đến update/điều kiện cho lần lặp sau.

* Hữu ích để skip cases (filter data).

* **Scope:** Chỉ vòng lặp gần nhất.

##### **4.2.2.VD**

        #include <stdio.h>

        int main() {
            // In các số lẻ từ 1 đến 10
            printf("Các số lẻ từ 1 đến 10: ");
            for (int i = 1; i <= 10; i++) {
                if (i % 2 == 0) {
                    continue;  // Bỏ qua số chẵn
                }
                printf("%d ", i);
            }
            printf("\n");
            
            // Xử lý dữ liệu, bỏ qua giá trị không hợp lệ
            int data[] = {5, -2, 8, -1, 10, 0, 7};
            int sum = 0;
            int count = 0;
            
            for (int i = 0; i < 7; i++) {
                if (data[i] <= 0) {
                    continue;  // Bỏ qua số không dương
                }
                sum += data[i];
                count++;
            }
            
            printf("Tổng các số dương: %d\n", sum);
            printf("Số lượng số dương: %d\n", count);
            if (count > 0) {
                printf("Trung bình: %.2f\n", (double)sum / count);
            }
            
            return 0;
        }

#### **4.3.Goto Statement**

##### **4.3.1.Khái niệm**

* `goto` nhảy đến label (được định nghĩa bằng `label:`), cho phép control flow tùy ý.

* Tránh dùng vì spaghetti code (khó theo dõi). Chỉ dùng cho error handling (cleanup) hoặc state machines phức tạp.

* Ưu tiên `break/continue/flags`.

##### **4.3.2.Cú pháp**

        // Định nghĩa label
        label_name:

        // Sử dụng goto
        goto label_name;

* **VD:**

        #include <stdio.h>

        int main() {
            int i, j;
            
            // Ví dụ sử dụng goto để thoát khỏi nhiều vòng lặp lồng nhau
            for (i = 0; i < 5; i++) {
                for (j = 0; j < 5; j++) {
                    printf("(%d, %d) ", i, j);
                    
                    if (i == 2 && j == 2) {
                        printf("\nTìm thấy điểm (2,2), thoát vòng lặp.\n");
                        goto end_loops;  // Nhảy đến label
                    }
                }
                printf("\n");
            }
            
        end_loops:
            printf("Đã thoát vòng lặp tại (%d, %d)\n", i, j);
            
            return 0;
        }


### **V.VÒNG LẶP LỒNG NHAU**

#### **5.1.Giới thiệu**

##### **5.1.1.Khái niệm**

* Vòng lặp lồng nhau (nested loops) là khi body của vòng ngoài chứa một hoặc nhiều vòng trong, tạo không gian đa chiều (2D, 3D,...).

* Tổng số lần lặp = tích số lần mỗi vòng.


##### **5.1.2.Cú pháp**

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Khối lệnh
            }
        }

* **VD:**

        #include <stdio.h>

        int main() {
            int rows = 3, cols = 4;
            
            printf("Ma trận %dx%d:\n", rows, cols);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    printf("(%d,%d) ", i, j);
                }
                printf("\n");
            }
            
            return 0;
        }
        
</details> 

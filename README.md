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

	* `format:` Chuỗi định dạng chứa văn bản tĩnh và các **format specifiers** (mã định dạng như `%d`, `%f`).

	* `...:` Các đối số tương ứng với format specifiers (có thể là int, float, char, v.v.).


* **Cơ sở:**

	* `printf()` sử dụng cơ chế đổi số khả biến (variadic arguments) thông qua macro `va_list`, `va_start`, `va_arg`, `va_end` từ `<stdarg.h>`
 
 	* Điều này cho phép hàm nhận số lượng tham số không cố định

   	* Chuỗi `format` đóng vai trò ban đồ để hàm biết có bao nhiêu đối số và kiểu dữ liệu của từng đối số   

##### **1.1.3.Giá trị trả về**

* Số ký tự được in ra (nếu thành công), hoặc số âm nếu có lỗi (ví dụ: buffer đầy).
                   
* **Lưu ý:**

	* Phải include `<stdio.h>` để sử dụng.

	* `printf()` tự động thêm null terminator cho chuỗi.

    
#### **1.2.Format Specifiers**

##### **1.2.1.Định nghĩa**

* Format specifiers là các mã đặc biệt bắt đầu bằng `%` để chỉ định cách hiển thị dữ liệu.

* **Cú pháp:**

			%[flags][width][.precision][length modifier]specifier   

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
| %n | Ghi số ký tự đã in vào biến con  | printf("Hi%n", &count); | ghi 2 vào count |
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

* **Precision:** Với `%f` là số chữ số thập phân; với `%s` là độ dài tối đa chuỗi; với`%d` là số chữ số tối thiểu (padding 0).

##### **1.4.2.VD**

			#include <stdio.h>
			
			int main() {
			    int number = 123;
			    float pi = 3.14159;
			    char str[] = "Hello";
			
			    printf("Width 8:          |%8d|\n", number);      // |     123|
			    printf("Width 2:          |%2d|\n", number);       // |123| (vượt vẫn hiển thị đủ)
			    printf("String width 10:  |%10s|\n", str);         // |     Hello|
			    printf("Precision 2:      %.2f\n", pi);            // 3.14
			    printf("Precision 0:      %.0f\n", pi);            // 3
			    printf("String prec 3:    %.3s\n", str);           // Hel
			    printf("Combined:         |%8.2f|\n", pi);         // |    3.14|
			    printf("Left-align:       |%-8.2f|\n", pi);        // |3.14    |
			    printf("Int precision:    %.5d\n", 25);            // 00025
			
			    return 0;
			}


#### **1.5.Length Modifiers (Bổ ngữ kích thước)**

##### **1.5.1.Định nghĩa**

* Length modifiers chỉ định kích thước thực sự của kiểu dữ liệu được truyền vào.

* Thiếu modifier phù hợp có thể gây undefined behavior. 

##### **1.5.2. Bảng Length Modifiers**

| **Modifier** | **Ý nghĩa** | **Ví dụ** | 
|------------|---------------|--------|
| `h` | `short int` / `unsigned short` | `printf("%hd", (short)x);` |
| `l` | `long int/ unsigned ` | `printf("%ld", 1234567890L);` |
| `ll` | `long long int` | `printf("%lld", 9223372036854775807LL);` |
| `z` | `size_t` (Kết quả của `sizeof` | `printf("%zu", sizeof(int));` |
| `L` | `long double` | `printf("%Lf", 3.14L);` |

##### **1.5.3. VD**

			#include <stdio.h>
			#include <stddef.h>
			
			int main() {
			    short s = 32767;
			    long l = 1234567890L;
			    long long ll = 9223372036854775807LL;
			    size_t sz = sizeof(double);
			
			    printf("short:       %hd\n", s);    // 32767
			    printf("long:        %ld\n", l);    // 1234567890
			    printf("long long:   %lld\n", ll);  // 9223372036854775807
			    printf("size_t:      %zu\n", sz);   // 8 (thường là 8 byte)
			
			    return 0;
			}

#### **1.6.Các Specifiers đặc biệt**

##### **1.6.1.Định nghĩa**

* Khi dùng các kiểu từ `<stdint.h>` như `int32_t`, `uint64_t`, sử dụng macro từ `<inttypes.h>` để đảm bảo portable.

##### **1.6.2.VD**

			#include <stdio.h>
			#include <stdint.h>
			#include <inttypes.h>
			
			int main(void) {
			    int32_t a = -12345;
			    uint64_t b = 9876543210ULL;
			
			    printf("Số int32_t:  %" PRId32 "\n", a);   // -12345
			    printf("Số uint64_t: %" PRIu64 "\n", b);   // 9876543210
			
			    return 0;
			}


#### **1.7.Các ký tự đặc biệt**

##### **1.7.1.Định nghĩa**

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

	* `format:` Chuỗi định dạng chứa format specifiers

	* `...:` Con trỏ đến các biến sẽ nhận giá trị nhập

	* `scanf()` cần biết địa chỉ bộ nhớ để ghi giá trị vào biến, nên phải dùng toán tử `&` trước tên biến (trừ mảng `char` như `%s` vì tên mảng đã là địa chỉ)	

* **Giá trị trả về:**

	* Số biến được nhập thành công (> 0).

	* 0: Không có biến nào được nhập (đầu vào không khớp).

	* EOF: Lỗi hoặc end-of-file (Ctrl+D trên Unix, Ctrl+Z trên Windows).

	* Cách `scanf()` xử lý whitespace:
 
 		* Trong chuỗi format, ký tự khoảng trắng (space, tab, \n) khớp với không hoặc nhiều ký tự whitespace trong đầu vào
   
   		* `scanf()` tự động bỏ qua whitespace đầu dòng trước hầu hết các specifiers (trừ `%c, %[...], %n`).   

* **Lưu ý:**

	* Phải dùng `&` trước biến (trừ mảng char như `%s`).

	* `scanf()` dừng khi gặp whitespace không khớp hoặc end-of-input.

* **VD:**

			#include <stdio.h>
			
			int main() {
			    int a, b;
			    int result = scanf("%d %d", &a, &b);
			
			    if (result == 2) {
			        printf("Nhập thành công: %d và %d\n", a, b);
			    } else if (result == 1) {
			        printf("Chỉ nhập được 1 giá trị!\n");
			    } else if (result == EOF) {
			        printf("Lỗi hoặc end-of-file!\n");
			    } else {
			        printf("Không nhập được giá trị nào!\n");
			    }
			
			    return 0;
			}

#### **2.2.Width Specification**

##### **2.2.1.Định nghĩa**

* Width giới hạn số ký tự tối đa nhập vào, đặc biệt quan trọng với `%s` để tránh tràn buffer (buffer overflow).

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

	* **Scan Set cơ bản:** `%[set]` - Chỉ nhận ký tự trong `set` (ví dụ: `%[a-zA-Z]` chỉ chữ cái).

	* **Negated Scan Set:** `%[^set]` - Nhận tất cả trừ ký tự trong `set` (ví dụ: %[^\n] nhập đến newline).

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

	* 1.Input người dùng (%[a-zA-Z]): `Hello123 (Enter)` -> Output chương trình: `Hello`

	* 2.Input người dùng: (%[^\n]): `Xin chào` -> Output chương trình: `Xin chào`


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

#### **2.4.Input Suppression (Bỏ qua dữ liệu đầu vào)**

##### **2.4.1.Vấn đề**

* Cờ `*` đặt sau `%` khiến `scanf()` đọc nhưng không lưu giá trị vào biến

* Biến tương ứng không cần cung  

##### **2.4.2.VD:**

		#include <stdio.h>
		
		int main() {
		    int year, day;
		    char month[20];
		
		    // Input dạng: "2024 January 15"
		    // Bỏ qua tháng, chỉ lấy năm và ngày
		    printf("Nhập ngày (năm tháng ngày): ");
		    scanf("%d %*s %d", &year, &day);
		    printf("Năm: %d, Ngày: %d\n", year, day);
		
		    return 0;
		}
		// Input: 2024 January 15
		// Output: Năm: 2024, Ngày: 15



#### **2.5.Xử lý buffer**

##### **2.5.1.Vấn đề**

* Sau khi dùng `%d` hoặc `%s`, ký tự `\n` còn sót trong buffer khiến `%c` hoặc `fgets()` đọc sai.

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

##### **3.1.2.Cơ chế Buffered I/O và Unbuffered I/O**

* **Buffered I/O:**

	* **Stream:** `stdin`, `stdout`
 
 	* Dữ liệu được giữ trong buffer, gửi theo khối

  	* `stdout` thường là line-buffered (gửi khi gặp `\n`)  

* **Unbuffered I/O:**

	* **Stream:** ``
 
 	* Mỗi ký tự được gửi ngay lập tức, không chờ buffer đầy.

* **getchar() trả về int thay vì char:**

	* Vì `char` chỉ có thể chứa giá trị 0 - 255 (hoặc -128 - 127 nếu signed)
 
 	* Hằng số `EOF` thường là `-1`, nằm ngoài phạm vi `char`

  	* Nếu `getchar()` trả về `char`, sẽ không phân biệt được `EOF` với ký tự hợp lệ vì thế dùng `int` để giải quyết vấn đề này      

			// ❌ Sai - không phân biệt được EOF
			char ch = getchar();      // có thể bỏ sót EOF
			
			// ✅ Đúng - dùng int
			int ch = getchar();       // chứa được cả ký tự (0-255) lẫn EOF (-1)
			if (ch == EOF) { ... }

##### **3.1.3.Ưu điểm**

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

	* Nhận 1 ký tự từ luồng nhập chuẩn (stdin)

	* Trả về `int` thay vì `char` để có thể trả về `EOF`

	* Chờ đến khi có ký tự nhập

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

	* Xuất 1 ký tự ra luồng xuất chuẩn (stdout)

	* Nhận tham số `int` nhưng chỉ xuất 8 bit thấp

	* Trả về ký tự đã xuất, hoặc `EOF` nếu lỗi

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
  		int fgetc(FILE *stream);

        VD:
        FILE *f = fopen("demo.txt", "r");
        putchar(getc(f));

* **Tham số:**

	* stream: Con trỏ đến FILE (stdin, file đã mở, hoặc stream khác)

        Tương tự getchar() nhưng linh hoạt với stream; có thể là macro (nhanh hơn hàm)
        Trả về ký tự hoặc EOF.

* **Đặc điểm:**

	* Tương tự getchar() nhưng làm việc với stream bất kỳ

	* Có thể là macro hoặc hàm

	* Thường dùng với stdin, file, hoặc stream khác

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
		int fputc(int c, FILE *stream);


        VD: putc(c, stdout);

* **Tham số:**

	* c: Ký tự dưới dạng int (8 bit thấp).

	* stream: Con trỏ đến FILE (stdout, file đã mở).

		* Tương tự putchar() nhưng cho stream tùy chỉnh; có thể là macro

		* Trả về ký tự đã xuất hoặc EOF nếu lỗi.

* **Đặc điểm:**

	* Tương tự `putchar()` nhưng làm việc với stream bất kỳ

	* Có thể là macro hoặc hàm

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

* Đẩy ký tự c trở lại bộ đệm đầu vào để lần đọc tiếp theo sẽ nhận lại ký tự đó.

* Chỉ đảm bảo hoạt động với 1 ký tự tại một thời điểm.

* Trả về c nếu thành công, EOF nếu thất bại.   


##### **3.4.2.Tham số**

* c: Ký tự cần đẩy trở lại dưới dạng int (8 bit thấp).

* stream: Con trỏ đến FILE (stdin, file, v.v.)

        Trả về c nếu thành công, EOF nếu lỗi.

        Chỉ đảm bảo 1 ký tự (implementation-defined cho nhiều hơn)

        Không thay đổi vị trí file nếu thất bại.

##### **3.4.3.Đặc điểm:**

	* Tương tự getchar() nhưng làm việc với stream bất kỳ

	* Có thể là macro hoặc hàm

	* Thường dùng với stdin, file, hoặc stream khác

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

#### **4.2.fgets() , puts() và fputs()**

##### **4.2.1.fgets() - Nhập chuỗi an toàn**

* **Lý do loại bỏ gets():**

		// KHÔNG BAO GIỜ dùng gets() !
		char buf[10];
		gets(buf);  // Nếu nhập hơn 9 ký tự → BUFFER OVERFLOW!

	* `gets()` không kiểm tra kích thước buffer, ghi vượt quá vùng nhớ được cấp phát.
 
 	* Dẫn đến buffer overflow — lỗ hổng bảo mật nghiêm trọng, có thể bị khai thác để thực thi mã độc.

  	* Chuẩn C11 (ISO/IEC 9899:2011) đã xóa hoàn toàn gets()
 
  
* **Cú pháp:**

        #include <stdio.h>
        char *fgets(char *str, int size, FILE *stream);

        VD:
        char buf[20];
        fgets(buf, sizeof(buf), stdin);

* **Tham số:**

	* str: Con trỏ đến buffer char để lưu chuỗi (phải đủ lớn).

	* size: Kích thước tối đa của buffer (đọc tối đa size-1 ký tự, chừa chỗ cho \0).

	* stream: Luồng nguồn (stdin mặc định cho bàn phím).

        Đặc điểm: Dừng khi gặp newline (\n), EOF, hoặc đạt size-1. 
        Tự thêm \0. Trả về str nếu thành công, NULL nếu lỗi/EOF.

* **Đặc điểm:**

	* Đọc tối đa `size-1` ký tự từ stream

	* Tự động thêm \0 vào cuối

	* Dừng khi gặp newline hoặc EOF

	* Trả về `str` nếu thành công, `NULL` nếu lỗi

* **Kỹ thuật cắt bỏ `\n`** 

			#include <stdio.h>
			#include <string.h>
			
			int main() {
			    char buf[100];
			
			    printf("Nhập một dòng: ");
			    if (fgets(buf, sizeof(buf), stdin) != NULL) {
			        // Cắt bỏ '\n' mà fgets giữ lại
			        size_t len = strlen(buf);
			        if (len > 0 && buf[len - 1] == '\n') {
			            buf[len - 1] = '\0';
			        }
			        printf("Bạn vừa nhập: [%s]\n", buf);
			    }
			    return 0;
			}
			// Input: Hello World
			// Output: Bạn vừa nhập: [Hello World]   ← không có '\n' thừa

##### **4.2.2.puts() - Xuất chuỗi tự thêm `\n`**

* **Cú pháp:**

        #include <stdio.h>
        int puts(const char *str);

        VD:
        puts("Hello, World!");

	* Xuất chuỗi ra `stdout` và tự động thêm `\n` vào cuối.
 
 	* Trả về giá trị không âm nếu thành công, EOF nếu lỗi. 

* **Tham số:**

	* str: Con trỏ đến chuỗi null-terminated (const để không thay đổi).

		* Xuất đến \0, tự thêm \n ở cuối 

		* Trả về giá trị không âm nếu thành công, EOF nếu lỗi

		* Không xuất \n nếu đã có trong str.

* **VD:**

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

##### **4.2.3.fputs() - Xuất ra stream bất kỳ, không thêm `\n`**

* **Cú pháp:**

			#include <stdio.h>
			int fputs(const char *str, FILE *stream);


	* Xuất chuỗi ra stream chỉ định.
 
 	* Không tự thêm \n — phù hợp khi cần kiểm soát định dạng chính xác.

  	* Trả về giá trị không âm nếu thành công, EOF nếu lỗi. 

* **Tham số:**

	* str: Kiểu dữ liệu `const char*`
 
 		* Con trỏ trỏ đến chuỗi ký tự cần xuất. 

 		* Từ khóa const đảm bảo hàm sẽ không thay đổi nội dung chuỗi gốc.

 		* Chuỗi phải kết thúc bằng ký tự '\0'.

	* stream: Kiểu dữ liệu `FILE*`

 		* Con trỏ trỏ đến luồng đích — nơi chuỗi sẽ được ghi ra.

 		* Có thể là stdout (in ra màn hình), stderr (in ra lỗi), hoặc một con trỏ file được mở bằng fopen().
  
* **VD:**

			#include <stdio.h>
			
			int main() {
			    char name[] = "Nguyễn Văn A";
			
			    puts(name);               // In: "Nguyễn Văn A\n"
			    fputs(name, stdout);      // In: "Nguyễn Văn A" (không có \n)
			    fputs("\n", stdout);      // In \n riêng
			
			    // Xuất ra stderr
			    fputs("Đây là thông báo lỗi\n", stderr);
			
			    return 0;
			}


#### **4.3.sprintf() , snprintf() và sscanf()**

##### **4.3.1.sprintf() - Format vào string buffer**

* **Cú pháp:**

	        #include <stdio.h>
	        int sprintf(char *str, const char *format, ...);
	
	        VD:
	        char buf[50]; 
	        sprintf(buf, "Tuổi: %d", 30);

	* sprintf() không kiểm soát kích thước buffer, có nguy cơ buffer overflow.
	 
	* Dùng snprintf() thay thế. 

* **Tham số:**

	* `str`: Buffer để ghi chuỗi (phải đủ lớn, không kiểm soát size → rủi ro overflow).

	* `format`: Chuỗi định dạng (như %d, %s).

	* `...`: Đối số tương ứng (int, float, v.v.).

        Đặc điểm: Ghi đến \0, trả về số ký tự ghi (không tính \0).

        Cảnh báo: Không an toàn; dùng snprintf() thay thế.

* **Đặc điểm:**

	* Đọc tối đa `size-1` ký tự từ stream

	* Tự động thêm \0 vào cuối

	* Dừng khi gặp newline hoặc EOF

	* Trả về `str` nếu thành công, `NULL` nếu lỗi


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

##### **4.3.2.snprintf()**

* **Cú pháp:**

		#include <stdio.h>
		int snprintf(char *str, size_t size, const char *format, ...);

        VD:
        char buf[50]; 
        sprintf(buf, "Tuổi: %d", 30);

	* sprintf() không kiểm soát kích thước buffer, có nguy cơ buffer overflow.
 
 	* Dùng snprintf() thay thế. 

* **Tham số:**

	* `str`: Kiểu dữ liệu `char*`

 		* Con trỏ trỏ đến bộ đệm đích (mảng ký tự) nơi chuỗi kết quả sẽ được ghi vào.

 		* Phải đủ lớn để chứa tối đa size ký tự.

	* `size`: Kiểu dữ liệu `size_t`

 		* Kích thước tối đa của bộ đệm (tính bằng byte)

 		* Hàm sẽ ghi tối đa size - 1 ký tự định dạng, sau đó tự động thêm ký tự '\0' kết thúc chuỗi.

	* `format`: Kiểu dữ liệu `const char*`

 		* Chuỗi định dạng — chứa văn bản thông thường và các specifier (như %d, %s, %f...) giống hệt printf.

* **Đặc điểm:**

	* Nếu giá trị trả về nhỏ hơn size → toàn bộ chuỗi đã được ghi đầy đủ, không bị cắt cụt.
  
	* Nếu giá trị trả về lớn hơn hoặc bằng size → chuỗi bị cắt cụt (truncated), bộ đệm không đủ lớn.

	* Nếu trả về số âm → có lỗi xảy ra trong quá trình định dạng (lỗi encoding, specifier không hợp lệ...).
 
  
				#include <stdio.h>
				
				int main() {
				    char buf[50];
				    int age = 25;
				    float score = 9.5f;
				    char name[] = "An";
				
				    // snprintf - an toàn
				    int written = snprintf(buf, sizeof(buf), "Tên: %s, Tuổi: %d, Điểm: %.1f", name, age, score);
				    printf("Chuỗi: %s\n", buf);
				    printf("Số ký tự: %d\n", written);
				
				    // Kiểm tra có bị cắt không
				    if (written >= (int)sizeof(buf)) {
				        printf("Cảnh báo: chuỗi bị cắt!\n");
				    }
				
				    // Ứng dụng: tạo tên file động
				    char filename[100];
				    snprintf(filename, sizeof(filename), "report_%d.txt", 2024);
				    printf("Tên file: %s\n", filename);
				
				    return 0;
				}
  
##### **4.3.3.sscanf() - Đọc từ string buffer**

* **Cú pháp:**

	        #include <stdio.h>
	        int sscanf(const char *str, const char *format, ...);
	
	        VD:
	        int age;
	        sscanf("25", "%d", &age);

* **Tham số:**

	* `str`: Chuỗi nguồn để đọc (const).

	* `format`: Chuỗi định dạng (như %d, %s).

	* `...`: Con trỏ đến biến nhận giá trị (&var cho scalar, mảng cho string)

        Trả về số biến đọc thành công 
        Dừng khi không khớp format.

* **Đặc điểm:**

	* Tương tự scanf() nhưng đọc từ string buffer

	* Trả về số biến được đọc thành công


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

*  Chỉ được set khi có lỗi; không tự reset.

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

	* perror(): In thông báo lỗi chuẩn hóa ra stderr.

* **Cú pháp:**

        #include <stdio.h>
        void perror(const char *s);  // Không trả về giá trị

        VD:perror("Thông báo lỗi");

* **Tham số:**

	* s: Chuỗi mô tả ngữ cảnh (ví dụ: "fopen failed").
  
 		* Nếu NULL, chỉ in mô tả errno.

 		* In format: s: mô tả lỗi từ errno\n.

 		* Tự động dùng errno hiện tại; không thay đổi errno.


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

	* strerror(): Trả về chuỗi mô tả lỗi

* **Cú pháp:**

        #include <string.h>
        char *strerror(int errnum);

        VD:strerror(ENOENT);

* **Tham số:**

	* errnum: Mã lỗi (thường là errno).
  
 		* Trả về con trỏ đến chuỗi tĩnh (không free);

 		* không thay đổi errno


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

	* Mỗi hàm I/O trả về indicator lỗi (NULL cho fopen, -1 cho read/write, 0 cho fread/fwrite nếu không đầy đủ).

* **Xử lý ngay:**

	* Dọn dẹp (fclose, free) và thoát/log lỗi.

* **Kết hợp errno:**

	* Sau khi kiểm tra return, dùng errno/perror để chi tiết.

* **Kiểm tra ferror/feof:**

	* Sau fread/fwrite, dùng ferror(stream) (lỗi) hoặc feof(stream) (hết file).


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

##### **1.1.3.Cơ sở**

* Trong C không có kiểu bool riêng biệt, mọi biểu thức đều được đánh giá theo quy tắc:

	* True (Đúng): Giá trị khác 0 — bao gồm số nguyên, số thực, con trỏ khác NULL.

	* False (Sai): Giá trị bằng 0 — số nguyên 0, số thực 0.0, con trỏ NULL.


			#include <stdio.h>
			
			int main() {
			    int x = 5;
			    double d = 0.0;
			    int *p = NULL;
			
			    if (x)       printf("x khác 0 → True\n");      // In ra
			    if (d)       printf("d khác 0 → True\n");       // Không in (d = 0.0)
			    if (p)       printf("p khác NULL → True\n");    // Không in (p = NULL)
			    if (!p)      printf("p là NULL → True\n");      // In ra
			
			    return 0;
			}


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

#### **1.4.Danling Else**

##### **1.4.1.Khái niệm**

* "Dangling Else" xảy ra khi có nhiều if lồng nhau nhưng số lượng else ít hơn if, gây ra mơ hồ về việc else thuộc if nào.

##### **1.4.2.Nguyên tắc hoạt động**

* Lệnh else luôn được ghép cặp với lệnh if gần nhất chưa có else ở cùng cấp độ khối lệnh.

			#include <stdio.h>
			
			int main() {
			    int x = 10, y = 5;
			
			    // ❌ Trông như else thuộc if ngoài, nhưng KHÔNG PHẢI
			    if (x > 0)
			        if (y > 10)
			            printf("y > 10\n");
			    else                          // else này thuộc if (y > 10) !
			        printf("x <= 0\n");       // Sẽ in khi x > 0 VÀ y <= 10
			
			    // ✅ Dùng {} để xác định rõ ràng
			    if (x > 0) {
			        if (y > 10)
			            printf("y > 10\n");
			    } else {                      // else này rõ ràng thuộc if (x > 0)
			        printf("x <= 0\n");
			    }
			
			    return 0;
			}
  
#### **1.5.Nested if statements**

##### **1.5.1.Khái niệm**

* **Nested if** là cấu trúc if-else lồng bên trong nhau, cho phép kiểm tra các điều kiện phức tạp theo nhiều cấp độ.

##### **1.5.2.Cú pháp**

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


##### **2.1.4.Cơ chế điều hướng của switch**

* Khi switch thực thi, trình biên dịch chuyển quyền điều khiển trực tiếp đến nhãn case có giá trị khớp, sau đó thực thi tuyến tính (từ trên xuống) cho đến khi gặp break hoặc kết thúc switch.

* Switch không kiểm tra điều kiện lại cho các case phía dưới — nó chỉ "nhảy" đến điểm bắt đầu rồi chạy thẳng xuống. 

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

##### **2.2.4. Khối lệnh**

* Thực thi khi không có case nào khớp.

* Không bắt buộc phải nằm ở cuối — có thể đặt ở bất kỳ vị trí nào trong switch.

* Nên luôn có default để xử lý các giá trị ngoài dự kiến (catch-all).

		switch (option) {
		    default:                         // default ở đầu vẫn hợp lệ
		        printf("Lựa chọn không hợp lệ\n");
		        break;
		    case 1: printf("Option 1\n"); break;
		    case 2: printf("Option 2\n"); break;
		}

#### **2.3. Tối ưu hóa trình biên dịch — Jump Table vs Binary Search Tree**

* **if-else ladder → O(n):**

	* Trình biên dịch sinh ra chuỗi so sánh tuần tự.
 
 	* Với n nhánh, trường hợp xấu nhất cần n lần so sánh. 

* **switch → O(1) với Jump Table:**

	* Khi các giá trị case liên tục hoặc gần liên tục (ví dụ: 1, 2, 3, 4, 5), trình biên dịch tạo ra một bảng nhảy (Jump Table) — mảng địa chỉ các nhãn case
 
 	* Chương trình chỉ cần một phép tính địa chỉ để nhảy thẳng đến case đúng, bất kể có bao nhiêu case.

			Jump Table (ví dụ switch với case 1-5):
			Index:  [0]      [1]      [2]      [3]      [4]
			Addr:  &case1   &case2   &case3   &case4   &case5
			
			Thực thi: goto table[value - 1]  → O(1)

* **switch → O(log n) với Binary Search Tree:**

	* Khi các giá trị case thưa thớt (ví dụ: 1, 100, 1000, 9999), trình biên dịch có thể sinh ra cấu trúc tìm kiếm nhị phân ở mức assembly, đạt O(log n).

				// Ví dụ minh họa: compiler chọn Jump Table cho case liên tục
				switch (x) {       // x từ 1-5: Jump Table O(1)
				    case 1: ...; break;
				    case 2: ...; break;
				    case 3: ...; break;
				    case 4: ...; break;
				    case 5: ...; break;
				}
				
				// Compiler có thể chọn BST cho case thưa thớt
				switch (x) {       // x: 1, 100, 500, 1000, 9999: BST O(log n)
				    case 1:    ...; break;
				    case 100:  ...; break;
				    case 500:  ...; break;
				    case 1000: ...; break;
				    case 9999: ...; break;
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

##### **3.1.3.Ternary là Expression, không phải Statement**


* if-else là câu lệnh (statement) — không trả về giá trị, không dùng được trong biểu thức.

* Ternary là biểu thức (expression) — trả về một giá trị, dùng được ở bất kỳ nơi nào cần giá trị.


			// if-else là statement: không thể dùng như thế này
			// int x = if (a > b) a else b;   ← LỖI BIÊN DỊCH
			
			// ternary là expression: dùng được mọi nơi cần giá trị
			int x = (a > b) ? a : b;                    // Gán biến
			printf("%d\n", (a > b) ? a : b);            // Đối số hàm
			int arr[3] = {1, (x > 0) ? x : 0, 3};      // Khởi tạo mảng

##### **3.1.4.Quy tắc hợp nhất kiểu**

* Khi nhánh true và nhánh false có kiểu dữ liệu khác nhau, trình biên dịch tự động tìm kiểu chung (common type) để chứa cả hai kết quả — tương tự phép ép kiểu ngầm định.

* Nên đảm bảo cả hai nhánh cùng kiểu hoặc có thể ép kiểu tường minh để tránh kết quả ngoài ý muốn.


		#include <stdio.h>
		
		int main() {
		    int a = 5;
		
		    // Nhánh true: int (1), nhánh false: double (2.5)
		    // → Toàn bộ biểu thức có kiểu double
		    double result = (a > 3) ? 1 : 2.5;
		    printf("%.1f\n", result);   // 1.0  (không phải 1 nguyên)
		
		    // int và float → float
		    float f = (a > 0) ? a : 3.14f;
		    printf("%.2f\n", f);        // 5.00
		
		    // Cảnh báo: kiểu không tương thích
		    // (a > 0) ? "text" : 42;   ← Undefined behavior, tránh dùng
		
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

##### **1.1.5.Lexical Scope của biến trong for (C99)**


* Từ C99, có thể khai báo biến ngay trong phần khởi tạo của for

* Đây là phạm vi từ vựng hẹp (Strict Lexical Scope): biến bị hủy ngay khi vòng lặp kết thúc.


		#include <stdio.h>
		
		int main() {
		    // ✅ C99: khai báo trong for - biến i chỉ sống trong vòng lặp
		    for (int i = 0; i < 3; i++) {
		        printf("i = %d\n", i);
		    }
		    // printf("%d", i);  ← LỖI BIÊN DỊCH: i không tồn tại ở đây
		
		    // Khai báo ngoài for - biến i tồn tại sau vòng lặp
		    int j;
		    for (j = 0; j < 3; j++) {
		        printf("j = %d\n", j);
		    }
		    printf("j sau vòng lặp: %d\n", j);  // j = 3, hợp lệ
		
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

#### **1.3.Lược bỏ biểu thức**

##### **1.3.1.Tính tùy chọn của biểu thức**

			// Bỏ khởi tạo (biến đã khai báo trước)
			int i = 0;
			for (; i < 5; i++) { ... }
			
			// Bỏ cập nhật (cập nhật trong body)
			for (int i = 0; i < 5;) { i++; }
			
			// Bỏ tất cả → vòng lặp vô hạn
			for (;;) { ... }

##### **1.3.2.for(;;) và while(1)**

* `for(;;)` là idiom C chuẩn cho vòng lặp vô hạn — không có biểu thức điều kiện nào cần đánh giá.

*  Một số compiler sinh cảnh báo với while(1) (constant condition), trong khi for(;;) không bao giờ sinh cảnh báo.

*  Trình biên dịch tối ưu hóa for(;;) tốt hơn vì không cần kiểm tra điều kiện. 


			#include <stdio.h>
			
			int main() {
			    int count = 0;
			
			    // ✅ Idiom chuẩn mực - vòng lặp vô hạn
			    for (;;) {
			        printf("Lần lặp thứ %d\n", ++count);
			        if (count >= 5) {
			            printf("Đã đủ 5 lần, thoát.\n");
			            break;
			        }
			    }
			
			    // Ứng dụng: Server event loop
			    int request_count = 0;
			    for (;;) {
			        printf("Chờ request... (Request #%d)\n", ++request_count);
			        if (request_count >= 3) {
			            printf("Server dừng sau 3 request.\n");
			            break;
			        }
			    }
			
			    return 0;
			}
			
#### **1.4.Vòng lặp vô hạn**

##### **1.4.1.Khái niệm**

* Khi điều kiện luôn true (rỗng hoặc hằng true), vòng lặp chạy mãi trừ khi dùng `break`.

* Thường dùng cho event loops (server, game) hoặc simulation.

##### **1.4.2.VD**

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


#### **1.5.Optimization Considerations**

##### **1.5.1.Khái niệm**

* Tối ưu vòng lặp nhằm giảm thời gian chạy, đặc biệt với dữ liệu lớn.

* Các kỹ thuật bao gồm loop-invariant hoisting (chuyển tính toán ra ngoài), unrolling (mở rộng vòng lặp), và tránh function calls trong điều kiện.

##### **1.5.2.Lý thuyết tối ưu**

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

#### **2.3.Assignment Expression trong while**

##### **2.3.1.Kỹ thuật**

* Biểu thức gán (assignment expression) có thể dùng trực tiếp trong điều kiện while, tạo ra code ngắn gọn và hiệu quả.

* `while ((ch = getchar()) != EOF)` — đọc từng ký tự cho đến hết file. Đây là idiom phổ biến nhất trong xử lý stream C.

##### **2.3.2.VD**


		#include <stdio.h>
		
		int main() {
		    int ch;
		
		    // Pattern 1: Đọc từng ký tự đến EOF
		    printf("Nhập văn bản (Ctrl+D để kết thúc):\n");
		    while ((ch = getchar()) != EOF) {   // gán VÀ kiểm tra trong một bước
		        putchar(ch);
		    }
		
		    // Pattern 2: Đọc số đến khi nhập đúng
		    int n;
		    printf("Nhập số dương: ");
		    while (scanf("%d", &n) == 1 && n <= 0) {
		        printf("Phải là số dương! Nhập lại: ");
		    }
		    printf("Đã nhận: %d\n", n);
		
		    return 0;
		}
			
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

#### **3.4.do { ... } while(0) trong Macro**

##### **3.4.1.Vấn đề với macro đa lệnh**

* Khi macro chứa nhiều câu lệnh, có thể gây lỗi cú pháp khi dùng trong if-else không có {}:


			// ❌ Macro lỗi khi dùng với if không có {}
			#define SWAP(a, b) \
			    int tmp = a;   \
			    a = b;         \
			    b = tmp;
			
			// Khi gọi:
			if (x > y)
			    SWAP(x, y);    // Mở rộng thành 3 câu lệnh riêng biệt
			else               // ← LỖI: else không có if tương ứng (chỉ câu đầu thuộc if)
			    printf("...");

##### **3.4.2.Giải pháp — do { ... } while(0)**

		// ✅ Đóng gói an toàn bằng do-while(0)
		#define SWAP(a, b)      \
		    do {                \
		        int tmp = (a);  \
		        (a) = (b);      \
		        (b) = tmp;      \
		    } while (0)
		
		// Khi gọi:
		if (x > y)
		    SWAP(x, y);    // Mở rộng thành: do { ... } while(0);
		else               // ✅ else hợp lệ vì if chỉ có 1 câu lệnh (do-while)
		    printf("Không cần đổi\n");

* Toàn bộ macro trở thành một câu lệnh duy nhất (kết thúc bằng ;).

* Compiler không bao giờ thực sự lặp vì điều kiện 0 luôn false.

* Không ảnh hưởng hiệu năng — compiler tối ưu bỏ phần kiểm tra while(0).  


			#include <stdio.h>
			
			#define LOG_ERROR(msg)          \
			    do {                        \
			        fprintf(stderr, "ERROR: %s\n", msg); \
			        error_count++;          \
			    } while (0)
			
			#define SAFE_FREE(ptr)          \
			    do {                        \
			        if ((ptr) != NULL) {    \
			            free(ptr);          \
			            (ptr) = NULL;       \
			        }                       \
			    } while (0)
			
			int error_count = 0;
			
			int main() {
			    int x = 5, y = 3;
			
			    if (x > y)
			        LOG_ERROR("Giá trị không hợp lệ");  // ✅ An toàn với if không có {}
			    else
			        printf("Không có lỗi\n");
			
			    printf("Số lỗi: %d\n", error_count);
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

#### **5.2.Big O Notation**

##### **5.2.1.Khái niệm**

* Big O Notation mô tả tốc độ tăng của thời gian thực thi khi kích thước đầu vào (N) tăng.

* Số tầng lặp lồng nhau ảnh hưởng trực tiếp đến độ phức tạp.


		f(N) = O(g(N)) nếu tồn tại hằng số c > 0 và N₀ sao cho với mọi N ≥ N₀ thì f(N) ≤ c·g(N)

##### **5.2.2.Quy tắc tính Big O**

* **Quy tắc 1: - Bỏ hằng số:**

		5N  → O(N)
		100 → O(1)
		3N² → O(N²)

* **Quy tắc 2: - Bỏ số hạng bậc thấp:**

		N² + N + 1 → O(N²)
		N³ + N²    → O(N³)


* **Quy tắc 3: - Cộng (các bước tuần tự):**

		for (i = 0; i < N; i++) { ... }    // O(N)
		for (j = 0; j < N; j++) { ... }    // O(N)
		// Tổng: O(N) + O(N) = O(2N) = O(N)

* **Quy tắc 4: - Nhân (vòng lặp lồng nhau):**

		for (i = 0; i < N; i++) {          // O(N)
		    for (j = 0; j < N; j++) { ... } // O(N)
		}
		// Tổng: O(N) × O(N) = O(N²)
  
##### **5.2.3.Mối quan hệ giữa số tầng lặp và Big O**

* Số tâng lặp:

	* **1 Vồng:**
 
 		* **O(N) - Tuyến tính**
   
   		* VD: Tìm kiếm tuần tự, in mảng
 

 
	* **2 Vồng:**
 
 		* **O(N^2) - Bình phương**
   
   		* VD: Bubble Sort, Selection Sort

	* **3 Vồng:**
 
 		* **O(N^3) - Lập phương**
   
   		* VD: Nhân ma trận naïve


			#include <stdio.h>
			
			int main() {
			    int N = 4;
			
			    // O(N) - 1 vòng: N bước
			    printf("O(N) - %d bước:\n", N);
			    for (int i = 0; i < N; i++) {
			        printf("i=%d ", i);
			    }
			    printf("\n");
			
			    // O(N²) - 2 vòng: N×N = %d bước
			    printf("\nO(N²) - %d bước:\n", N * N);
			    for (int i = 0; i < N; i++) {
			        for (int j = 0; j < N; j++) {
			            printf("(%d,%d) ", i, j);
			        }
			    }
			    printf("\n");
			
			    // O(N³) - 3 vòng: N×N×N bước
			    printf("\nO(N³) - %d bước:\n", N * N * N);
			    int count = 0;
			    for (int i = 0; i < N; i++)
			        for (int j = 0; j < N; j++)
			            for (int k = 0; k < N; k++)
			                count++;
			    printf("Tổng số bước: %d\n", count);
			
			    return 0;
			}
	
</details> 

<details>

<summary><strong>CHƯƠNG 5: CON TRỎ CƠ BẢN</strong></summary>

## **CHƯƠNG 5: CON TRỎ CƠ BẢN**

### **I. TỔNG QUAN**

#### **1.1.Khái niệm**

##### **1.1.1.Định nghĩa**

* Con trỏ (pointer) là một biến đặc biệt dùng để lưu trữ địa chỉ bộ nhớ của một biến khác hoặc của vùng bộ nhớ nào đó

	* Biến thông thường lưu giá trị 
	
	* Con trỏ lưu địa chỉ (address) nơi giá trị đó được lưu giữ
	
* VD:

		int x = 2025;   // x là biến thường, chứa giá trị 2025
		
		-> Máy tính sẽ cấp phát một ô nhớ (thường 4 byte trên hệ 32-bit hoặc 8 byte trên hệ 64-bit) để lưu số 2025, và ô nhớ đó có một địa chỉ duy nhất (ví dụ: 0x7ffd5b2e4a1c). 

		int *ptr;		// ptr là con trỏ kiểu int
		ptr = &x; 	// ptr lưu địa chỉ của x
		
		-> Sau lệnh này, ptr không chứa số 2025, mà chứa địa chỉ của biến x 

##### **1.1.2.Vai trò**

* **Quản lý bộ nhớ động:**

	* Cấp phát và giải phóng bộ nhớ trong lúc chạy chương trình (`malloc`, `calloc`,`realloc`,`free`)
	
	* Tạo mảng động, linked list, tree, graph,...
	
* **Truyền tham chiếu (pass-by-reference)**

	* C chỉ hỗ trợ truyền tham trị (pass-by-value)
	
	* Muốn thay đổi giá trị của biến trong hàm, ta phải truyền địa chỉ của biến đó - dùng con trỏ
	
	 *  VD1: Hàm hoán đổi hai số mà không dùng con trỏ sẽ không hoạt động 	
	 
			void swap(int a, int b) {    // sai – chỉ đổi bản sao
			    int temp = a;
			    a = b;
			    b = temp;
			}

	 *  VD2: Dùng con trỏ đúng
	 
			void swap (int *a, int *b){
				int temp = *a;
				*a = *b;
				*b = temp;
			}
			
			// Gọi hàm 
			int x = 10, y = 20;
			swap(&x, &y);		// x = 20, y = 10
			
								
*   Truy cập mảng, chuỗi hiệu quả 




#### **1.2.Mô hình bộ nhớ tuyến tính**

##### **1.2.1.RAM như một mảng bytes khổng lồ**

* Dưới góc nhìn của C, bộ nhớ máy tính (RAM) là một mảng liên tiếp các ô nhớ (byte), mỗi ô có kích thước 1 byte. 

* Mỗi byte có một địa chỉ duy nhất — chỉ số định danh của ô nhớ đó trong không gian bộ nhớ ảo.


		Địa chỉ:  0x1000  0x1001  0x1002  0x1003  0x1004  ...
		          +------+------+------+------+------+
		Nội dung: |  25  |  00  |  00  |  00  |  ...  |
		          +------+------+------+------+------+
		           ↑
		           int x = 25 chiếm 4 byte liên tiếp (little-endian)

* Không gian địa chỉ ảo (Virtual Address Space):

	* Mỗi chương trình khi chạy được hệ điều hành cấp một không gian địa chỉ ảo riêng.
 
 	* Trên hệ thống 64-bit hiện đại, không gian này có thể lên đến 2⁶⁴ byte, dù RAM vật lý thực tế nhỏ hơn nhiều.
 
    
##### **1.2.2.Biểu diễn địa chỉ trong hệ thập lục phân**

* Địa chỉ bộ nhớ luôn được biểu diễn dưới dạng hexadecimal khi in bằng `%p`

		#include <stdio.h>

		int main() {
		    int a = 10;
		    printf("Gia tri cua a: %d\n", a);
		    printf("Dia chi cua a: %p\n", (void*)&a);
		    return 0;
		}
		// Output:
		Gia tri cua a: 10
		Dia chi cua a: 0x7ffd5b2e4a1c

* Để in địa chỉ an toàn, luôn ép kiểu về `void*` khi dùng `%p`

##### **1.2.3.Kiểu dữ liệu uintptr_t**

* Từ C99, uintptr_t trong <stdint.h> cung cấp kiểu số nguyên không dấu đủ lớn để chứa toàn bộ địa chỉ trên kiến trúc hiện tại.

		#include <stdio.h>
		#include <stdint.h>

		int main() {
		    int x = 2025;
		    uintptr_t addr = (uintptr_t)&x;
		    printf("Dia chi duoi dang so nguyen: 0x%lx\n", addr);
		    return 0;
		}

#### **1.3.Khai báo và khởi tạo**

##### **1.3.1.Cú pháp**

		kiểu_dữ_liệu *tên_con_trỏ;

* `kiểu_dữ_liệu` là kiểu của giá trị mà con trỏ trỏ tới (không phải kiểu của con trỏ)

*  Dấu `*` gắn liền với tên con trỏ, không gắn với kiểu 

		int *ptr;
		int* ptr;
		int * ptr

* VD:

		int *iptr;          // con trỏ tới int
		float *fptr;        // con trỏ tới float
		char *cptr;         // con trỏ tới char (thường dùng cho chuỗi)
		double *dptr;
		void *vptr;         // con trỏ tổng quát (sẽ học sau)

##### **1.3.2.Khởi tạo con trỏ với địa chỉ hợp lệ**

* Con trỏ không tự động trỏ đến đâu cả -> phải khởi tạo trước khi dùng 

	* Cách đúng: 

			int x = 100;
			int *ptr = &x;
			
			// hoặc 
			int *ptr;
			ptr = &x;

	* Cách sai:
	
			int *ptr;               // wild pointer – giá trị rác
			*ptr = 500;             // → undefined behavior (crash hoặc lỗi ngẫu nhiên)

#### **1.4.Toán tử con trỏ**

##### **1.4.1.Đặc điểm**

* **&:** Address-of  (Lấy địa chỉ)
 
	* Trích xuất địa chỉ bộ nhớ của một biến đã được cấp phát.
			
			&x


	* **Giới hạn cần lưu ý:**
 
	   	* Không thể lấy địa chỉ của biến khai báo register
	   	
		* Từ khóa register gợi ý compiler lưu biến trong thanh ghi CPU — thanh ghi không có địa chỉ bộ nhớ.
	 
	 	* Tuy nhiên, từ C11, register hầu như không còn hiệu lực thực tế vì compiler tự tối ưu hóa.  
	
* **`*`:** Dereference (giải tham chiếu)

	* Lấy giá trị tại địa chỉ mà con trỏ đang trỏ tới 
	
			*ptr 

##### **1.4.2.VD**

		#include <stdio.h>

		int main() {
		    int x = 2025;
		    int *ptr = &x;

		    printf("Gia tri cua x:          %d\n", x);
		    printf("Dia chi cua x:          %p\n", (void*)&x);
		    printf("Gia tri ma ptr luu:     %p\n", (void*)ptr);
		    printf("Gia tri tai dia chi ptr tro toi: %d\n", *ptr);

		    // Thay doi gia tri thong qua con tro
		    *ptr = 2026;
		    printf("\nSau khi doi:\n");
		    printf("Gia tri cua x bay gio:  %d\n", x);
		    printf("Gia tri qua *ptr:       %d\n", *ptr);

		    return 0;
		}

	// Output:

	Gia tri cua x:          2025
	Dia chi cua x:          0x7ffd5b2e4a1c
	Gia tri ma ptr luu:     0x7ffd5b2e4a1c
	Gia tri tai dia chi ptr tro toi: 2025

	Sau khi doi:
	Gia tri cua x bay gio:  2026
	Gia tri qua *ptr:       2026
	
	//
	-> ptr và &x có cùng giá trị (cùng địa chỉ)
	
	-> *ptr và x có cùng giá trị (cùng nội dung)

### **II. CON TRỎ VÀ KIỂU DỮ LIỆU**

#### **2.1.Con trỏ theo từng kiểu dữ liệu**

* Mỗi kiểu con trỏ (`int*`. `char*`, `double*`,...) được thiết kế để trỏ đến dữ liệu kiểu tương ứng

* VD khai báo:
	
		int    *iptr;     // trỏ đến int (thường 4 byte)
		char   *cptr;     // trỏ đến char (1 byte)
		double *dptr;     // trỏ đến double (thường 8 byte)
		float  *fptr;     // trỏ đến float (thường 4 byte)

* Sự phụ thuộc giữa kiểu con trỏ và kích thước bước nhảy bộ nhớ 

	* 	Khi thực hiện phép toán tăng/giảm con trỏ (`ptr++`, `ptr + n`)
	
		* Số byte dịch chuyển không phải là +1 byte
		
		* Mà là +sizeof(kiểu mà ptr trỏ tới) byte

* VD:

		#include <stdio.h>

		int main() {
		    int arr[5] = {10, 20, 30, 40, 50};
		    int *ip = arr;
		    char *cp = (char *)arr;     // ép kiểu để minh họa

		    printf("Dia chi ip ban dau:   %p\n", (void*)ip);
		    ip++;
		    printf("Sau ip++:             %p  (tang %zu byte)\n", (void*)ip, sizeof(int));

		    printf("\nDia chi cp ban dau:   %p\n", (void*)cp);
		    cp++;
		    printf("Sau cp++:             %p  (tang %zu byte)\n", (void*)cp, sizeof(char));

		    return 0;
		}

		// Output:
		Dia chi ip ban dau:   0x7ffd12345678
		Sau ip++:             0x7ffd1234567c  (tang 4 byte)

		Dia chi cp ban dau:   0x7ffd12345678
		Sau cp++:             0x7ffd12345679  (tang 1 byte)
		
#### **2.2.Con trỏ void**

* `void*` là con trỏ tổng 	quát (generic pointer) 

	* Có thể trỏ đến bất kỳ kiểu dữ liệu nào 
	
	* Không thể giải tham chiếu trực tiếp 

* Ứng dụng:

	* Tham số của các hàm cấp phát bộ nhớ: `malloc`, `calloc`, `realloc`
	
	* Tham số của các hàm sao chép bộ nhớ: `memcpy`, `memmove`, `memset`
	
	* Làm trung gian khi cần truyền con trỏ giữa các hàm có kiểu khác nhau
	
* VD:

		#include <stdio.h>
		#include <stdlib.h>
		int main(){
			int n = 1000;
			int *p = malloc(n * sizeof(int));
			
			if (p == NULL){
				printf("Cap phat that bai!\n");
				return 1;
			}
			
			// void* tự động ép kiểu về int* trong C
			// Có thể viết rõ ràng như sau:
			// int *p = (int *)malloc(n * sizeof(int));
			
			*p = 2025;
			printf("Gia tri: %d\n", *p);
			free(p);
			return 0;
		}

* **Ép kiểu khi giải tham chiếu:**

	* Để lấy giá trị từ `void*`, bắt buộc phải ép kiểu trước:
	
			void *vp; 
			int x = 999;
			vp = &x;
			printf("%d\n", *(int *)vp); // phải ép về int* rồi mới *

#### **2.3.Con trỏ NULL**

* `NULL` là một macro thường được định nghĩa là `(void*)0` hoặc `0`, biểu thị con trỏ không đến đâu cả (không hợp lệ)

		#include <stdio.h>

		int main() {
		    int *ptr = NULL;

		    if (ptr == NULL) {
		        printf("Con tro chua duoc khoi tao hop le.\n");
		    }

		    // *ptr = 10;   // NGUY HIỂM – dereference NULL → undefined behavior
		    return 0;
		}
	
* Quy tắc kiểm tra:

			if (ptr != NULL) {
			    *ptr = 500;
			    printf("%d\n", *ptr);
			} else {
			    printf("Loi: con tro la NULL!\n");
			}

* Sau khi `free(ptr)`, nên gán lại `ptr = NULL;` để tránh double free

#### **2.4.Con trỏ chưa khởi tạo (Wild Pointer)**

* `Wild pointer` là con trỏ chưa được khởi tạo hoặc được khởi tạo với giá trị rác

	* Nó sẽ trỏ đến một địa chỉ ngẫu nhiên trong bộ nhớ
	
* Nguyên nhân phổ biến:
		
		int *ptr;		 // không khởi tạo → wild pointer
		*ptr = 100;  // → undefined behavior (có thể crash, ghi đè dữ liệu khác)
	
* Hoặc:
  
		int *ptr = malloc(sizeof(int));
		free(ptr);
		*ptr = 200

* Gây ra:

	* Undefined behavior: Crash, dữ liệu sai, treo máy
	
	* Ghi đè lên vùng nhớ chương trình khác

* Phòng tránh:

	* Luôn khởi tạo khi khai báo
		
			int *ptr = NULL;           // an toàn nhất
			// hoặc
			int x = 0;
			int *ptr = &x;
	
	*  Sau `free(ptr)` -> gán lại NULL:
	
			free(ptr);
			ptr = NULL;

	* Kiểm tra `NULL` trước mọi thao tác giải tham chiếu
	
	* Sử dụng công cụ debug:
	
		* Valgrind
		* VS debugger

### **III. PHÉP TOÁN TRÊN CON TRỎ (POINTER ARITHMETIC)**

#### **3.1.Cơ sở**

* Mối liên hệ giữa con trỏ và mảng

	* Trong C, mảng hoạt động như một con trỏ hằng trỏ đến phần tử đầu tiên của mảng
	
			int arr[5] = {10, 20, 30, 40, 50};
			
			// Các biểu thức tương đương:
			arr        ≡  &arr[0]          // địa chỉ phần tử đầu
			arr + 1    ≡  &arr[1]          // địa chỉ phần tử thứ 2
			*(arr + 2) ≡  arr[2]           // giá trị phần tử thứ 3
			arr[i]     ≡  *(arr + i)       // cách truy cập tổng quát
		
* 	Cách tính địa chỉ phần tử tiếp theo

	* Khi bạn thực hiện ptr + n, C *tự động nhân n với sizeof(ptr) để tính số byte cần dịch chuyển.
	
	* Công thức:  
		
			địa chỉ mới = địa chỉ hiện tại + n × sizeof(kiểu mà ptr trỏ tới)
			
	* VD:  
		
			int* ptr -> ptr + 1 tăng 4 byte (hoặc 8 byte)
			char* ptr -> ptr + 1 tăng 1 byte
			double* ptr -> ptr + 1 tăng 8 byte

 

#### **3.2.Các phép toán tăng giảm**

* **ptr++**:

	* Tăng con trỏ lên 1 phần tử 
	
	* + sizeof(*ptr)byte
	
* **ptr--**:

	* Giảm con trỏ xuống 1 phần tử
	
	* -sizeof(*ptr)byte

* **ptr + n**:

	* Di chuyển tiến n phần tử 
	
	* VD: ptr + 3 -> + 3 × sizeof(*ptr) byte
	
* **ptr - n**:

	* Di chuyển lùi n phần tử
	
	* VD: ptr - 2 -> -2 × sizeof(*ptr) byte

* **Lưu ý:**

	*  Không được thực hiện `ptr + ptr`, `ptr * n`, `ptr / n`, `ptr % n` → lỗi biên dịch.

	*  Chỉ cộng/trừ với số nguyên (int, size_t, …).
	
* **VD:**

			#include <stdio.h>

			int main() {
			    int arr[5] = {10, 20, 30, 40, 50};
			    int *p = arr;               // p trỏ đến arr[0]

			    printf("Duyet bang chi so:\n");
			    for(int i = 0; i < 5; i++) {
			        printf("%d ", arr[i]);
			    }

			    printf("\n\nDuyet bang con tro:\n");
			    for(int i = 0; i < 5; i++) {
			        printf("%d ", *p);
			        p++;                    // hoặc p = p + 1;
			    }
			    printf("\n");

			    return 0;
			}	

#### **3.3.So sánh con trỏ**

* Các toán tử so sánh hợp lệ: `==`, `!=`,` <`, `>`, `<=`, `>=`

* Hai con trỏ phải trỏ vào cùng một đối tượng (thường là cùng một mảng hoặc cùng một khối bộ nhớ liên tục).
	
* So sánh với NULL luôn hợp lệ.

* **VD1:**

			int arr[10];
			int *p1 = &arr[2];
			int *p2 = &arr[7];

			if (p1 < p2) {          // hợp lệ → true
			    printf("p1 nam truoc p2 trong mang\n");
			}

			if (p1 == &arr[2]) {    // hợp lệ
			    // ...
			}								  

* **VD2:**

		int a, b;
		int *pa = &a;
		int *pb = &b;

		if (pa < pb) {          // KHÔNG ĐƯỢC – hai biến cục bộ không đảm bảo thứ tự
		    // undefined behavior
		}

#### **3.. Ưu tiên toán tử — `*ptr++ vs (*ptr)++`**

* **Biểu thức:**

	* **`*(ptr++)`**: Lấy giá trị tại ptr, sau đó tăng địa chỉ ptr
	
	* **`*(++ptr)`**: Trước tiên tăng ptr, rồi lấy giá trị tại địa chỉ mới
		
	* **`(*ptr)++`**: Lấy giá trị tại ptr, sau đó tăng giá trị tại địa chỉ đó
	
	* **`++(*ptr)`**: Trước tiên tăng giá trị tại địa chỉ, rồi trả về

* **Quy tắc ưu tiên:**

	* `++` và `* (unary)` có cùng độ ưu tiên, kết hợp từ phải sang trái.  

* **VD:**

			#include <stdio.h>
			
			int main() {
			    int arr[] = {10, 20, 30, 40};
			    int *p;
			    int val;
			
			    // --- *ptr++ : lấy giá trị rồi tăng con trỏ ---
			    p = arr;
			    val = *p++;              // val = arr[0] = 10, p trỏ sang arr[1]
			    printf("*ptr++:    val=%d, *p=%d\n", val, *p);   // 10, 20
			
			    // --- *(++ptr) : tăng con trỏ rồi lấy giá trị ---
			    p = arr;
			    val = *(++p);            // p trỏ sang arr[1] trước, val = arr[1] = 20
			    printf("*(++ptr):  val=%d, *p=%d\n", val, *p);   // 20, 20
			
			    // --- (*ptr)++ : tăng giá trị tại địa chỉ, con trỏ không đổi ---
			    p = arr;
			    val = (*p)++;            // val = arr[0] = 10, arr[0] trở thành 11
			    printf("(*ptr)++:  val=%d, arr[0]=%d, *p=%d\n", val, arr[0], *p);   // 10, 11, 11
			
			    // --- ++(*ptr) : tăng giá trị trước rồi lấy ---
			    p = arr;
			    val = ++(*p);            // arr[0] tăng thêm 1 (11 → 12), val = 12
			    printf("++(*ptr):  val=%d, arr[0]=%d\n", val, arr[0]);   // 12, 12
			
			    return 0;
			}
  
#### **3.4.Phép trừ hai con trỏ**

* Chỉ hợp lệ khi hai con trỏ trỏ vào cùng một mảng (hoặc cùng một khối bộ nhớ cấp phát liên tục).

* Số phần tử chênh lệch giữa hai vị trí (kiểu `ptrdiff_t` – thường là `long` hoặc `long long`).		

* Công thức:
	
		khoảng cách = ptr2 - ptr1;    // số phần tử ptr2 đứng sau ptr1
		
* Ví dụ:

		#include <stdio.h>

		int main() {
		    int arr[8] = {0};
		    int *p_start = &arr[1];
		    int *p_end   = &arr[6];

		    ptrdiff_t distance = p_end - p_start;

		    printf("Khoang cach: %td phan tu\n", distance);     // in ra: 5
		    printf("So byte: %td byte\n", (char*)p_end - (char*)p_start);  // thường 20 nếu int=4 byte

		    return 0;
		}

### **IV. TÍNH BẤT BIẾN VÀ CON TRỎ (CONST VÀ POINTER)**

#### **4.1.Con trỏ tới hằng số (Pointer to const)**

* Khai báo:

		const int *ptr;
		// hoặc tương đương
		int const *ptr;

* Giá trị tại địa chỉ mà ptr trỏ tới không thể thay đổi thông qua con trỏ này (*ptr = ... → lỗi biên dịch).

* Bản thân con trỏ (ptr) có thể thay đổi để trỏ sang địa chỉ khác.

* VD:

			#include <stdio.h>

			int main() {
			    int a = 10;
			    int b = 20;

			    const int *ptr = &a;

			    // *ptr = 100;          // LỖI biên dịch: không thể gán cho dữ liệu const

			    printf("Gia tri ban dau: %d\n", *ptr);   // 10

			    ptr = &b;               // HỢP LỆ: thay đổi địa chỉ con trỏ trỏ tới
			    printf("Gia tri sau khi doi: %d\n", *ptr);   // 20

			    // Nhưng vẫn không thể thay đổi giá trị qua ptr
			    // *ptr = 30;           // vẫn lỗi

			    // Có thể thay đổi giá trị gốc nếu dùng biến gốc
			    b = 30;
			    printf("Gia tri goc thay doi: %d\n", *ptr);  // 30

			    return 0;
			}

#### **4.2.Con trỏ hằng (Const pointer)**

* Khai báo:

		int * const ptr;

* Địa chỉ mà ptr lưu trữ không thể thay đổi sau khi khởi tạo (ptr = ... → lỗi biên dịch).

* Giá trị tại địa chỉ đó có thể thay đổi thông qua con trỏ (*ptr = ... → hợp lệ).

* VD:

		 #include <stdio.h>

		int main() {
		    int x = 100;
		    int y = 200;

		    int * const ptr = &x;     // phải khởi tạo ngay khi khai báo

		    *ptr = 150;               // HỢP LỆ
		    printf("x sau khi doi: %d\n", x);   // 150

		    // ptr = &y;              // LỖI biên dịch: không thể thay đổi địa chỉ

		    return 0;
		}		

#### **4.3.Con trỏ hằng tới hằng số (Const pointer to const)**

* Khai báo:

		const int * const ptr;
		// hoặc 
		int const * const ptr;

* Cả địa chỉ lẫn giá trị tại địa chỉ đó đều không thể thay đổi

* VD:

		#include <stdio.h>

		int main() {
		    int x = 2025;

		    const int * const ptr = &x;

		    printf("Gia tri: %d\n", *ptr);   // 2025

		    // *ptr = 2026;         // LỖI
		    // ptr = &y;            // LỖI (nếu có biến y khác)

		    // Nhưng vẫn có thể thay đổi giá trị gốc nếu truy cập trực tiếp
		    x = 2026;
		    printf("Gia tri sau khi doi goc: %d\n", *ptr);   // 2026

		    return 0;
		}

#### **4.4.Quy tắc đọc khai báo con trỏ có const**

*  Đọc từ phải sang trái, bắt đầu từ tên biến, rồi xoay vòng theo chiều kim đồng hồ (spiral rule).

* `const int * ptr`: ptr là con trỏ -> trỏ tới -> int const

* `int * const ptr`: ptr là const -> con trỏ -> trỏ tới int

*  `const int * const ptr`:  ptr là con trỏ → trỏ tới → const int

*  `const int * const * ptr`:  ptr là con trỏ → trỏ tới → (const pointer to const int)   

#### **4.5.Chú ý**

*  Khi thiết kế hàm, nên khai báo tham số con trỏ với const nếu hàm chỉ đọc dữ liệu, không cần ghi.

	* Khẳng định với compiler: hàm này chỉ có quyền read-only.
	
	* Bảo vệ dữ liệu gốc của người gọi khỏi bị thay đổi ngoài ý muốn.
 
 	* Cho phép truyền cả const và non-const vào hàm.  


			#include <stdio.h>
			
			// ✅ Đúng: chỉ đọc arr, dùng const
			void print_array(const int *arr, int size) {
			    for (int i = 0; i < size; i++)
			        printf("%d ", arr[i]);
			    printf("\n");
			    // arr[0] = 999;   // ❌ LỖI biên dịch — compiler bảo vệ dữ liệu
			}
			
			// ✅ Đúng: có ghi vào arr, không dùng const
			void fill_array(int *arr, int size, int value) {
			    for (int i = 0; i < size; i++)
			        arr[i] = value;
			}
			
			// ✅ Tham số chuỗi chỉ đọc
			size_t my_strlen(const char *s) {
			    size_t len = 0;
			    while (*s++) len++;
			    return len;
			}
			
			int main() {
			    int data[] = {1, 2, 3, 4, 5};
			    print_array(data, 5);
			    fill_array(data, 5, 0);
			    print_array(data, 5);
			    return 0;
			}

### **V. CÁC LỖI THƯỜNG GẶP**

#### **5.1.Error**

##### **5.1.1.Dereference con trỏ NULL**

* (Truy cập giá trị tại địa chỉ 0x0)

		int *ptr = NULL;
		*ptr = 100;             // → segmentation fault (thường gặp nhất)
		// Nguyên nhân: quên kiểm tra ptr != NULL trước khi dùng *ptr hoặc ptr->.

##### **5.1.2.Truy cập bộ nhớ ngoài phạm vi**

		int arr[5] = {1,2,3,4,5};
		int *p = arr;
		*(p + 10) = 999;        // ghi đè vùng nhớ ngoài mảng 

→ ghi đè lên biến khác, stack frame, return address.

##### **5.1.3.Dangling pointer**

* Con trỏ vẫn giữ địa chỉ cũ sau khi vùng nhớ đã bị giải phóng hoặc biến cục bộ đã ra khỏi phạm vi.

		int *getNumber() {
		    int x = 2025;
		    return &x;              // NGUY HIỂM – x là biến cục bộ
		}

		// hoặc
		int *ptr = malloc(sizeof(int));
		free(ptr);
		*ptr = 500;             // use-after-free → dangling pointer

##### **5.1.4.Double free / Invalid free**

		int *p = malloc(100);
		free(p);
		free(p);                // double free → UB, thường crash heap

##### **5.1.5.Sai kiểu ép con trỏ**

		int x = 0x12345678;
		float *pf = (float *)&x;   // vi phạm strict aliasing rule → UB

#### **5.2.Nguyên tắc thực hành**

##### **5.2.1.Luôn khởi tạo con trỏ ngay khi khai báo**

		int *p = NULL; hoặc int *p = &x;

##### **5.2.2.Kiểm tra NULL trước mọi thao tác giải tham chiếu và pointer arithmetic**

	if (p != NULL) { 
		*p = 10; 
	}

##### **5.2.3.Sau free(ptr) → gán lại ptr = NULL;**

		free(p); p = NULL;

##### **5.2.4.Không thực hiện pointer arithmetic ra ngoài giới hạn mảng**

		Dùng p < arr + SIZE thay vì p < &arr[SIZE]

##### **5.2.5.Khi truyền mảng/chuỗi vào hàm → dùng const nếu chỉ đọc**

		void print(const char *s);

##### **5.2.6.Không trả về địa chỉ của biến cục bộ từ hàm**

		Trả về giá trị hoặc cấp phát động

##### **5.2.7.Sử dụng size_t cho kích thước và chỉ số (không dùng int âm)**

		size_t len = end - start;

##### **5.2.8.Kiểm tra kết quả của malloc / calloc / realloc**

		if (!p) { 
		exit(1); 
		}

##### **5.2.9.Khi cần truy cập byte-level → dùng `unsigned char*` hoặc `uint8_t*`**

		unsigned char *bytes = (unsigned char*)&data;


			// Ví dụ tổng hợp nguyên tắc thực hành
			#include <stdio.h>
			#include <stdlib.h>
			
			int *create_array(int size) {
			    if (size <= 0) return NULL;              // validate input
			
			    int *arr = malloc(size * sizeof(int));
			    if (!arr) {                              // (8) kiểm tra malloc
			        perror("malloc failed");
			        return NULL;
			    }
			    return arr;
			}
			
			void process_array(const int *arr, int size) {  // (5) const — chỉ đọc
			    if (arr == NULL || size <= 0) return;        // (2) kiểm tra NULL
			    for (int i = 0; i < size; i++)
			        printf("%d ", arr[i]);
			    printf("\n");
			}
			
			int main() {
			    int *p = NULL;                           // (1) khởi tạo NULL
			
			    p = create_array(5);
			    if (!p) return 1;
			
			    for (int i = 0; i < 5; i++) p[i] = i * 10;
			    process_array(p, 5);
			
			    free(p);                                 // (3) free rồi gán NULL
			    p = NULL;
			
			    return 0;
			}
													 
</details>


<details>

<summary><strong>CHƯƠNG 6: HÀM VÀ PHẠM VI BIẾN</strong></summary>

## **CHƯƠNG 6: HÀM VÀ PHẠM VI BIẾN**

### **I. TỔNG QUAN**

#### **1.1.Khái niệm**

##### **1.1.1.Định nghĩa**

* Hàm (function) là một đơn vị chương trình độc lập bao gồm một tập hợp các lệnh thực hiện một nhiệm vụ cụ thể

* Mỗi hàm có tên riêng, có thể nhận đầu vào (tham số), xử lý dữ liệu và trả về kết quả (nếu có) 

	* Hàm giống như một black box:
	
		* Chỉ cần biết cách gọi nó (input/output), không cần quan tâm chi tiết bên trong
		
		* Mọi chương trình C đều phải có ít nhất một hàm: `main()` - điểm bắt đầu thực thi  
	

##### **1.1.2.Vai trò**

* Hàm giúp cấu trúc chương trình theo modular, thay vì viết tất cả code trong một hàm duy nhất (monolithic)

* Các vai trò chính: 

	* **Phân chia nhiệm vụ:** Mỗi hàm chịu trách nhiệm một chức năng nhỏ, dễ quản lý.
	
	* **Tái sử dụng code:** Gọi hàm nhiều lần mà không lặp code.

	* **Dễ debug và bảo trì:** Lỗi chỉ ảnh hưởng cục bộ, dễ sửa.
	
	* **Tích hợp thư viện:** Sử dụng hàm từ thư viện chuẩn (stdio.h, stdlib.h) hoặc tự viết.
	
* Nguyên tắc chia nhỏ chức năng (Modular Programming)

	* Modular Programming là cách tiếp cận chia chương trình thành các module (hàm hoặc file) nhỏ, độc lập
	
* Nguyên tắc: Single Responsibility Principle (SRP) – Mỗi hàm chỉ làm một việc duy nhất.
	
	 *  VD1: Không moduler
	 
			// Tất cả trong main – khó đọc
			int main() {
			    int a = 10, b = 20;
			    int sum = a + b;
			    printf("Tong: %d\n", sum);
			    // ... thêm code khác
			    return 0;
			}

	 *  VD2: Modular
	 
			int add(int a, int b);     // prototype

			int main() {
			    int sum = add(10, 20);  // gọi hàm độc lập
			    printf("Tong: %d\n", sum);
			    return 0;
			}

			int add(int a, int b) {     // hàm nhỏ, chỉ cộng
			    return a + b;
			}
			
								

#### **1.2.Cú pháp và khai báo**

##### **1.2.1.Khai báo nguyên mẫu (Function Prototype)**

*  Prototype (nguyên mẫu hàm) là khai báo ngắn gọn về hàm, cho compiler biết về kiểu trả về, tên hàm và tham số - trước khi định nghĩa đầy đủ

*  Cú pháp:
		
		kiểu_trả_về tên_hàm(danh_sách_tham_số);

*  VD:

		int add(int a, int b);
		void printHello(void);
		double tinhBinhPhuong(float x);

##### **1.2.2.Định nghĩa hàm (Function Definition)**

* Definition là phần triển khai đầy đủ của hàm, bao gồm thân hàm

* Cú pháp: 

		kiểu_trả_về tên_hàm(danh_sách_tham_số) {
		    // thân hàm: các lệnh
		    return giá_trị;  // nếu có kiểu trả về
		}

* VD:

		int add(int a, int b) {     // định nghĩa
		    int sum = a + b;        // thân hàm
		    return sum;             // trả về
		}

#### **1.3.Tham số và đối số**

* **Parameters (tham số hình thức):** 

	* Biến trong khai báo hàm (ví dụ: int a, int b trong add(int a, int b)).

*  **Arguments (đối số thực tế):** 

	* Giá trị thực tế truyền vào khi gọi hàm (ví dụ: add(10, 20); – 10 và 20 là arguments).

*  **Sự tương thích kiểu dữ liệu:** 

	* Arguments phải khớp kiểu parameters (compiler tự ép kiểu nếu có thể, ví dụ int → float, nhưng không ngược lại).

*  **Cơ chế truyền dữ liệu khi gọi hàm:** 

	* Mặc định là call by value (sao chép giá trị)

			int multiply(int x, int y);  // parameters: x, y

			int main() {
			    int result = multiply(5, 3);  // arguments: 5, 3
			    return 0;
			}

#### **1.4.Câu lệnh return**

* **Ý nghĩa và vai trò:** Kết thúc hàm và trả giá trị về nơi gọi (nếu hàm có kiểu trả về non-void).

* **Trả về giá trị:** return biểu_thức; – biểu thức phải khớp kiểu trả về.

* **Trả về sớm (early return):** Dùng để thoát hàm sớm nếu điều kiện thỏa mãn

			int checkEven(int num) {
			    if (num % 2 == 0) {
			        return 1;           // early return nếu chẵn
			    }
			    return 0;               // nếu lẻ
			}

* **Hàm không trả về giá trị (void):** Không cần return, hoặc chỉ return; để kết thúc sớm.

		void printMessage() {
		    printf("Xin chao!\n");
		    // không cần return
		}
			

### **II. CƠ CHẾ GỌI HÀM VÀ HOẠT ĐỘNG**

#### **2.1.Call by value - Truyền tham trị**

* C mặc định sử dụng **call by value** (truyền tham trị):

	* Khi gọi hàm, giá trị của đối số được sao chép vào tham số hình thức 
	
	* Tham số trong hàm là bản sao của đối số
	
	* Thay đổi giá trị tham số không ảnh hưởng đến biến gốc ở nơi gọi  

* VD :
	
			#include <stdio.h>

			void swap(int a, int b) {
			    int temp = a;
			    a = b;
			    b = temp;
			    printf("Trong ham swap: a = %d, b = %d\n", a, b);
			}

			int main() {
			    int x = 10, y = 20;
			    printf("Truoc khi goi: x = %d, y = %d\n", x, y);

			    swap(x, y);

			    printf("Sau khi goi: x = %d, y = %d\n", x, y);
			    return 0;
			}
			// Output:
			Truoc khi goi: x = 10, y = 20
			Trong ham swap: a = 20, b = 10
			Sau khi goi: x = 10, y = 20	
			
			-> Biến x và y không thay đổi, vì a và b chỉ là bản sao.	
	
#### **2.2.Call by reference - Truyền tham chiếu**

* C không có cơ chế call by reference thật sự như C++ (dùng `&`).

* Tuy nhiên, ta có thể mô phỏng bằng cách truyền địa chỉ (con trỏ) → gọi là call by reference qua pointer.
	
* Đặc điểm:

	* Truyền địa chỉ của biến gốc.
	
	* Thay đổi *tham_so → thay đổi trực tiếp giá trị tại địa chỉ → ảnh hưởng biến gốc.

* VD:

			#include <stdio.h>

			void swap(int *a, int *b) {
			    int temp = *a;
			    *a = *b;
			    *b = temp;
			    printf("Trong ham swap: *a = %d, *b = %d\n", *a, *b);
			}

			int main() {
			    int x = 10, y = 20;
			    printf("Truoc khi goi: x = %d, y = %d\n", x, y);

			    swap(&x, &y);           // truyền địa chỉ

			    printf("Sau khi goi: x = %d, y = %d\n", x, y);
			    return 0;
			}
			// Output:
			Truoc khi goi: x = 10, y = 20
			Trong ham swap: *a = 20, *b = 10
			Sau khi goi: x = 20, y = 10			


#### **2.3.Stack Frame**

* Call Stack (ngăn xếp gọi hàm) là vùng bộ nhớ đặc biệt (stack segment) dùng để quản lý các lần gọi hàm lồng nhau

* Mỗi lần gọi hàm -> hệ thống tạo một stack frame (khung ngăn xếp) mới

* Thành phần chính của một stack frame:

	* **Tham số** (arguments/parameters – sao chép hoặc địa chỉ)   

	* **Biến cục bộ** (local variables – automatic storage)
	
	* **Return address** (địa chỉ lệnh tiếp theo trong hàm gọi)

	* **Saved registers** (giá trị thanh ghi bị thay đổi, được lưu để khôi phục)
	
	* **Frame pointer (FP)** và **Stack pointer (SP)** - quản lý frame 

* Qúa trình thực thi:

	* Trước khi gọi hàm -> push các đối số lên stack  (theo thứ tự ngược trong một số kiến trúc).
	
	* Push return address
	
	* Tạo frame mới -> cấp phát không gian cho biến cục bộ 
	
	*  Thực thi thân hàm 
	
	*  Khi gặp return  → pop frame → khôi phục thanh ghi → nhảy về return address.

	* Frame bị hủy → biến cục bộ mất giá trị.

			Giả sử main() gọi funcA() → funcA() gọi funcB()

			Stack (địa chỉ cao → thấp):
			+---------------------+
			| main's frame        |  ← Frame Pointer (FP) của main
			| biến cục bộ main    |
			| return addr (hệ thống)|
			+---------------------+
			          ↓ push khi gọi funcA
			+---------------------+
			| funcA's frame       |  ← FP hiện tại
			| tham số của funcA   |
			| biến cục bộ funcA   |
			| return addr → main  |
			+---------------------+
			          ↓ push khi gọi funcB
			+---------------------+
			| funcB's frame       |  ← FP hiện tại
			| tham số của funcB   |
			| biến cục bộ funcB   |
			| return addr → funcA |
			+---------------------+
			          ↓ funcB return → pop frame
			          ↓ funcA return → pop frame
			          ↓ quay về main



### **III. PHẠM VI VÀ VÒNG ĐỜI**

#### **3.1.Scope và Storage Duration**

* **Scope (phạm vi):**

	* Vùng code mà tại đó tên biến có thể được sử dụng 

* **Lifetime (thời gian sống / storage duration):**

	* Khoảng thời gian biến tồn tại trong bộ nhớ (từ lúc được cấp phát đến khi bị hủy)
	
* **Các loại phạm vi:**

	* **Block scope (phạm vi khối)** – từ { đến }
	
	*  **Function scope** – chỉ áp dụng cho nhãn (label) của goto
		
	* **Function prototype scope** – tham số trong prototype
	
	*  **File scope (global scope)** – ngoài mọi hàm


#### **3.2.Local Variables**

* **Khai báo:** Trong thân hàm hoặc trong khối { } (block).

* **Phạm vi:** Chỉ trong khối chứa nó (block scope).
	
* **Lifetime:** Tồn tại chỉ khi khối đang thực thi (automatic storage duration).
	
* **Lưu trữ:** Trên stack (trong stack frame của hàm).
	
* **Khởi tạo mặc định:** Giá trị rác (garbage) nếu không khởi tạo.

* Biến cục bộ bị hủy tự động khi ra khỏi khối → giá trị mất.

* Mỗi lần gọi hàm → stack frame mới → biến cục bộ được cấp phát lại.
	
* **VD:**

		#include <stdio.h>

		void test() {
		    int x = 100;            // block scope, lifetime = suốt hàm test()
		    
		    {
		        int y = 200;        // block scope nhỏ hơn
		        printf("y = %d\n", y);
		    }
		    
		    // printf("%d", y);     // LỖI biên dịch: y ngoài scope
		    
		    printf("x = %d\n", x);  // hợp lệ
		}

		int main() {
		    test();
		    // printf("%d", x);     // LỖI: x không tồn tại ở main
		    return 0;
		}

#### **3.3.Global Variables**

* **Khai báo:** Ngoài mọi hàm (file scope).

* **Phạm vi:** Toàn bộ file (và các file khác nếu dùng extern).
	
* **Lifetime:** Suốt thời gian chương trình chạy (static storage duration).
	
* **Lưu trữ:** Trong vùng Data (nếu có khởi tạo) hoặc BSS (nếu không khởi tạo).
	
* **Khởi tạo mặc định:** 0 (zero-initialized) nếu không gán giá trị.


		#include <stdio.h>

		int globalVar = 500;        // global, file scope, lifetime = toàn chương trình

		void func() {
		    globalVar += 100;
		    printf("Trong func: globalVar = %d\n", globalVar);
		}

		int main() {
		    printf("Ban dau: globalVar = %d\n", globalVar);
		    func();
		    printf("Sau func: globalVar = %d\n", globalVar);
		    return 0;
		}
		
		// Output:
		Ban dau: globalVar = 500
		Trong func: globalVar = 600
		Sau func: globalVar = 600		

#### **3.4.Từ khóa extern**

* `extern` dùng để khai báo (không định nghĩa) một biến toàn cục đã được định nghĩa ở file khác

	* Cho phép chia sẻ biến giữa các file 

* Quy tắc:

	* Chỉ một file định nghĩa biến (có giá trị khởi tạo hoặc không)
	
	* Các file khác khai báo extern để sử dụng  	

	
* Ví dụ:

	* **globals.h** (header file - khai báo) 

			#ifndef GLOBALS_H
			#define GLOBALS_H

			extern int sharedCounter;   // khai báo, không định nghĩa

			#endif

	* **main.c** (định nghĩa biến)

			#include <stdio.h>
			#include "globals.h"

			int sharedCounter = 0;      // định nghĩa thực sự

			void increment();

			int main() {
			    printf("Ban dau: %d\n", sharedCounter);
			    increment();
			    printf("Sau: %d\n", sharedCounter);
			    return 0;
			}

	* **utils.c** (sử dụng extern)

			#include "globals.h"

			void increment() {
			    sharedCounter++;
			    printf("Trong utils: %d\n", sharedCounter);
			}

	* **Kết quả** khi biên dịch & chạy (gcc main.c utils.c -o program):


			Ban dau: 0
			Trong utils: 1
			Sau: 1		
			
### **IV. STATIC VARIABLE VÀ SCOPE**

#### **4.1.Static variable**

##### **4.1.1.Static Local Variable**

* **Khai báo:** `static` trước biến cục bộ trong hàm hoặc khối 

* **Đặc điểm:**

	* **Khởi tạo chỉ một lần duy nhất**  (khi chương trình bắt đầu hoặc lần đầu hàm được gọi).
	
	* **Giữ giá trị giữa các lần gọi hàm**  (không bị reset như biến cục bộ thông thường) 

	* **Vòng đời:** Suốt thời gian chương trình chạy
	
	* **Vị trí lưu trữ:** Vùng Data (nếu có khởi tạo) hoặc BSS (nếu không khởi tạo)

	* **Phạm vi:**  Vẫn chỉ trong hàm/khối (block scope) – không thể truy cập từ ngoài.

* VD:

			#include <stdio.h>

			void counter() {
			    static int count = 0;       // khởi tạo chỉ 1 lần
			    count++;
			    printf("Ham counter duoc goi lan thu: %d\n", count);
			}

			int main() {
			    counter();      // lần 1 → count = 1
			    counter();      // lần 2 → count = 2
			    counter();      // lần 3 → count = 3
			    
			    // count vẫn giữ giá trị 3 ở lần gọi tiếp theo
			    counter();      // lần 4 → count = 4
			    return 0;
			}
			
			// Output:
			Ham counter duoc goi lan thu: 1
			Ham counter duoc goi lan thu: 2
			Ham counter duoc goi lan thu: 3
			Ham counter duoc goi lan thu: 4			

#### **4.2.Static Global Variable**

* **Khai báo:** `static` trước biến khai báo ngoài mọi hàm

* **Đặc điểm:**

	* **Phạm vi (scope/linkage):**  Chỉ giới hạn trong file hiện tại (internal linkage).
	
	* Không thể truy cập từ file khác (ngay cả khi dùng extern).

	* **Vòng đời:** Suốt chương trình (static storage duration).
	
	* **Khởi tạo mặc định:** 0 nếu không gán.

	* **Lưu trữ:**  Vùng Data/BSS.

* VD:

	* **file1.c**

			#include <stdio.h>

			static int filePrivateVar = 100;    // chỉ dùng được trong file1.c

			void showPrivate() {
			    printf("Gia tri private: %d\n", filePrivateVar);
			}

			int main() {
			    showPrivate();
			    filePrivateVar += 50;
			    showPrivate();
			    return 0;
			}
			
	* **file2.c** 

			// extern int filePrivateVar;   // LỖI linker: undefined reference



### **V. INLINE FUNCTION VÀ STATIC INLINE FUNCTION**

#### **5.1.Inline Function**

##### **5.1.1.Khái niệm**

* Inline Function là hàm được khai báo với từ khóa `inline`

* Khi biên dịch, thay vì thực hiện một lời gọi hàm truyền thống (tạo stack frame, nhảy địa chỉ), trình biên dịch sẽ cố gắng thay thế trực tiếp đoạn code của thân hàm vào ngay tại vị trí hàm được gọi  

##### **5.1.2.Đặc điểm:**
	
* Khác với Macro (`#define`) của tiền xử lý, hàm inline được trình biên dịch kiểm tra kiểu dữ liệu của tham số và giá trị trả về một cách nghiêm ngặt
	
* Trình biên dịch có quyền từ chối inline nếu hàm quá phức tạp (chứa vòng lặp lớn, đệ quy, hoặc kích thước hàm quá dài)

* Nếu một hàm inline được gọi ở rất nhiều nơi, mã nguồn của nó sẽ bị sao chép ra bấy nhiêu lần, làm tăng dung lượng bộ nhớ chương trình

##### **5.1.3.Cú pháp:**

		inline kiểu_trả_về tên_hàm(danh_sách_tham_số){\
			//body
			return giá_trị
		}
	
* **VD:**	

			#include<stdio.h>
			inline int binhPhuong(int x){
				return x * x;
			}
			int main (){
				int a = 5;
				printf("Result: %d\n", binhPhuong(a));
				return 0;
			}

	* **Cách trình biên dịch xử lý ngầm:**
	
			int main(){
				int a = 5;
				printf("Result: %d\n", a * a);
				return 0;
			} 		

#### **5.2.Static Inline Function**

##### **5.2.1.Khái niệm**

* Nếu định nghĩa mooht hàm inline thông thường trong file `.h` , rồi `#include` file này vào nhiều file `.c` khác nhau để sử dụng, quá trình liên kết (Linker) sẽ báo lỗi **Multiple Definition (trùng lặp định nghĩa hàm)** do vi phạm quy tắc ODR


##### **5.2.2.Đặc điểm:**
	
* Static Inline Function là sự kết hợp giữa từ khóa `static` (giới hạn phạm vi) và `inline` (yêu cầu tối ưu nội tuyến) 
	
* Từ khóa `static` giới hạn phạm vi của hàm chỉ nằm trong file `.c` nào trực tiếp include nó

* Linker sẽ không nhìn thấy hàm này ở phạm vi toàn cục, tránh hoàn toàn lỗi trùng lặp định nghĩa 

* Nếu trình biên dịch quyết định không inline hóa hàm đó, nó sẽ tự động coi hàm đó như một hàm `static` bình thường của riêng file `.c` đó, không tạo ra các cảnh báo hay lỗi biên dịch

##### **5.2.3.Cú pháp**

		static inline kiểu_trả_về tên_hàm(danh_sách_tham_số){
			//body
			return giá_trị;
		}

##### **5.2.4.VD**

* **File `utils.h`:**

		#ifndef UTILS_H
		#define UTILS_H

		static inline int timMax(int a, int b){
			return (a > b) ? a : b;
		}

		#endif

* **File `process1.c`:**

		#include <stdio.h>
		#include "utils.h"
		void process1(){
			int m = timMax(10, 20);
			printf("Max 1: %d\n", m);
		}

* **File `process2.c`:**

		 #include <stdio.h>
		 #include "utils.h"
		 void process2(){
			 int n = timMax(100, 200);
			 printf("Max 2: %d\n", n);
		}

### **VI. HÀM ĐỆ QUY (RECURSION)**

#### **6.1. Khái niệm**

* Hàm đệ quy là hàm tự gọi lại chính nó một cách trực tiếp hoặc gián tiếp (thông qua một hàm khác) trong quá trình thực thi

* Phương pháp đệ quy chia một bài toán lớn thành các bài toán con nhỏ hơn, có cùng tính chất, cho đến khi bài toán con này đủ đơn giản để có thể giải quyết trực tiếp mà không cần phân rã thêm

* Các Stack Frame này sẽ xếp chồng lên nhau 

* Khi đạt tới điều kiện dừng, các hàm bắt đầu trả về giá trị (return), các Stack Frame lần lượt bị hủy (pop) theo cơ chế **LIFO** cho đến khi quay về lời gọi ban đầu  

#### **6.2. Cấu trúc**

* Một hàm đệ quy chuẩn luôn phải được cấu thành từ hai phần rõ rệt:

	* Là điều kiện tiên quyết để kết thúc quá trình đệ quy
	
	* Tại điểm dừng, hàm sẽ trả về một giá trị cụ thể ngay lập tức mà không thực hiện thêm bất kỳ lời gọi nào khác  

		* Nếu thiếu điểm dừng hoặc điểm dừng được thiết lập sai, hàm sẽ gọi chính nó vô hạn, dẫn đến việc cạn kiệt bộ nhớ Stack của hệ thống

* Là phần thân hàm thực hiện việc gọi lại chính nó, nhưng với tham số đã được thay đổi theo hướng tiến dần về phía điểm dừng

#### **6.3. Cú pháp**

			return_type recursive_function_name(parameter_list){
				//1. Base Case
				if(termination_condition){
					return base_value;
				}
				//2. Recursive Case
				return process_logic_with(recursive_function_name(modified_parameter));
			 }

#### **6.4. VD**

* Nếu n = 0 hoặc n = 1: n! = 1 (Điểm dừng)

* Nếu n > 1: n! = n x (n - 1)! (Bước đệ quy)

			#include<stdio.h>
			long long factorial(int n){
				if(n == 0 || n == 1){
					return 1;
				}

				return n * factorial(n - 1);
			}
			int main(){
				int num = 3;
				printf("Factorial cua %d la : %lld\n", num, factorial(num));
				return 0;
			}

* Cách hoạt động:

			factorial(3)
			= 3 * factorial(2)
			= 3 * (2 * factorial(1))
			= 3 * (2 * 1)
			= 6

* Quá trình gọi hàm:

		factorial(3)
		    ↓
		factorial(2)
		    ↓
		factorial(1)  ← Base Case, trả về 1
		    ↑
		2 × 1 = 2
		    ↑
		3 × 2 = 6
				

													 
</details>


<details>

<summary><strong>CHƯƠNG 7: BỘ TIỀN XỬ LÝ (C PREPROCESSOR)</strong></summary>

## **CHƯƠNG 7: BỘ TIỀN XỬ LÝ (C PREPROCESSOR)**

### **I. TỔNG QUAN**

#### **1.1.Định nghĩa**

* Bộ tiền xử lý (preprocessor) là giai đoạn đầu tiên trong quá trình biên dịch chương trình C.

* Nó xử lý các chỉ thị đặc biệt (bắt đầu bằng #) để biến đổi mã nguồn thành một dạng mở rộng, dễ biên dịch hơn.

#### **1.2.Vị trí**

* Quá trình biên dịch C bao gồm bốn giai đoạn chính (thường gọi là "compilation pipeline"). Preprocessor nằm ở vị trí đầu tiên:

	* Preprocessing (Tiền xử lý): 

		* Xử lý các chỉ thị # (như #include, #define, #if).
		
		* Thay thế macro, chèn file header, loại bỏ comment.

		* Kết quả: Tệp nguồn mở rộng (thường có đuôi .i) – vẫn là code C nhưng đã được biến đổi.
	
	* Compilation (Biên dịch):

		* Chuyển code C đã tiền xử lý thành assembly (mã máy thấp cấp, đuôi .s).
		
		* Kiểm tra cú pháp, kiểu dữ liệu, và tạo mã trung gian.

	* Assembly (Hợp ngữ):

		* Chuyển assembly thành object code (mã máy, đuôi .o hoặc .obj).

	* Linking (Liên kết):
	
		* Kết hợp các object file và thư viện thành file thực thi (executable, như .exe trên Windows).
	
#### **1.3.Sơ đồ**
	 
		Mã nguồn (.c / .h) → Preprocessor (#include, #define, #if) → Tệp mở rộng (.i)
		↓
		Compiler (check syntax, generate assembly) → Assembly code (.s)
		↓
		Assembler → Object code (.o)
		↓
		Linker (link libraries) → Executable (.exe / a.out)

* Để xem kết quả preprocessing, dùng lệnh: gcc -E source.c -o output.i (GCC)

* Kết quả sau tiền xử lý: tệp nguồn mở rộng (.i):

	*  Chèn toàn bộ nội dung header (như stdio.h → code thực sự của printf).
	
	*  Thay thế macro (như MAX(a,b) → ((a) > (b) ? (a) : (b))).
	
	*  Loại bỏ comment và xử lý conditional (#if → chỉ giữ code phù hợp).
	
	*  Compiler sẽ biên dịch tệp .i này, nên lỗi preprocessor thường xuất hiện gián tiếp ở giai đoạn compile.
			
								


			

### **II. CÁC CHỈ THỊ CƠ BẢN**

#### **2.1.Chỉ thị #include**

* Chèn toàn bộ nội dung của một tệp khác (thường là header file .h) vào vị trí chỉ thị #include tại thời điểm tiền xử lý.

	* Giúp tái sử dụng khai báo hàm, macro, kiểu dữ liệu mà không cần copy-paste code.
	
	* Tất cả thư viện chuẩn C (stdio.h, stdlib.h, string.h…) đều được chèn qua #include.
	
* Hai hình thức cú pháp:

		#include <tên_tệp>          // Dùng cho header hệ thống (system headers)
		#include "tên_tệp"          // Dùng cho header do người dùng viết (user headers)

* Cơ chế tìm kiếm header file :

	* Với `< >` (system headers):
	
		* 	Tìm trong các thư mục hệ thống chuẩn (ví dụ: /usr/include, /usr/local/include).
		
		*  Thường dùng cho thư viện chuẩn: #include

	* Với `" "` (user headers):
	
		* 	Tìm trước trong thư mục hiện tại (nơi chứa file .c).
		
		*  Sau đó tìm trong các thư mục hệ thống (tương tự < >).
		
		*  Thường dùng cho header tự viết: #include "myutils.h".

* Nếu một header được include nhiều lần (trực tiếp hoặc gián tiếp) → lỗi biên dịch "redefinition" (định nghĩa lại).

	*   Include Guard (truyền thống) là cách ngăn chặn:

				// myheader.h
				#ifndef MYHEADER_H          // Nếu MYHEADER_H chưa được định nghĩa
				#define MYHEADER_H          // Định nghĩa nó ngay lập tức

				// Nội dung header thật sự
				int add(int a, int b);

				#endif                      // Kết thúc guard

		*   Lần include đầu tiên: #ifndef đúng → định nghĩa và xử lý nội dung.
	
		*   Lần include sau: #ifndef sai → bỏ qua toàn bộ nội dung đến #endif.
	
#### **2.2.Chỉ thị #define**

* Định nghĩa macro – thay thế một định danh (identifier) bằng chuỗi văn bản khác trong toàn bộ code sau đó.

* Cú pháp:

			#define ĐỊNH_DANH replacement_text
	
* VD:

		#define PI          3.14159265359
		#define BUFFER_SIZE 1024
		#define MAX_USERS   100
		#define DEBUG_MODE  1		


#### **2.3.Chỉ thị #undef**

* Hủy bỏ (undefine) một macro đã được định nghĩa trước đó.

* Cú pháp:

		#undef ĐỊNH_DANH

* VD:


			#define DEBUG 1

			#ifdef DEBUG
			    printf("Debug mode ON\n");
			#endif

			#undef DEBUG           // hủy định nghĩa

			#ifdef DEBUG
			    // code này sẽ KHÔNG được compile
			#endif



### **III. Macro Hàm**

#### **3.1.Định nghĩa Macro Hàm**

* **Cú pháp:**

			#define TÊN_MACRO(tham_số1, tham_số2, ...) replacement_text

	* VD:

			#define MAX(a, b)       ((a) > (b) ? (a) : (b))
			#define SQUARE(x)       ((x) * (x))
			#define MIN(a, b)       ((a) < (b) ? (a) : (b))
			#define ABS(x)          ((x) >= 0 ? (x) : -(x))

* **Cơ chế thay thế văn bản:**

	* Preprocessor thay thế nguyên văn mà không hiểu ngữ nghĩa.
	
	*  Không kiểm tra kiểu dữ liệu → có thể dùng với int, float, double, thậm chí struct (nếu hợp lệ).
	
	*  Không tạo stack frame → không có overhead gọi hàm → nhanh hơn hàm thông thường.
	
	* VD:

			#define SWAP(a, b, type)    do { type temp = (a); (a) = (b); (b) = temp; } while(0)
			
			int p = 5, q = 10;
			SWAP(p, q, int);            // an toàn vì dùng do-while(0)
				
#### **3.2.Nguyên tắc**

* **Luôn bao tham số trong ngoặc đơn**

	* **Sai:**

			#define SQUARE(x)   x * x
			int result = SQUARE(3 + 2);     // thay thành 3 + 2 * 3 + 2 = 11 (sai!)

	*  **Đúng**

			#define SQUARE(x)   ((x) * (x))

* **Bao toàn bộ biểu thức trong ngoặc**

	* **Sai:**

			#define MAX(a, b)   (a) > (b) ? (a) : (b)
			int larger = MAX(x, y) + 5;     // có thể sai ưu tiên

	*  **Đúng**

			#define MAX(a, b)   (((a) > (b)) ? (a) : (b))
	
* **Tránh side effects trong tham số**

			int i = 5;
		int max_val = MAX(i++, 10);     // i++ được đánh giá 2 lần → undefined behavior
	
* **Dùng do-while(0) cho macro nhiều câu lệnh**

		#define PRINT_DEBUG(msg)    do { printf("DEBUG: %s\n", msg); } while(0)
			
### **IV. CONDITIONAL COMPILATION**

#### **4.1.Các chỉ thị điều kiện**

* Các chỉ thị chính dùng để kiểm soát biên dịch có điều kiện:

	* **#if biểu_thức**

	* **#ifdef ĐỊNH_DANH**  (tương đương `#if defined(ĐỊNH_DANH)`)
	
	* **#ifndef ĐỊNH_DANH**  (tương đương `#if !defined(ĐỊNH_DANH)`) 

	* **#else**

	* **#elif biểu_thức**  (else if)
	
	* **#endif**  (bắt buộc kết thúc mỗi khối điều kiện) 

* Cú pháp:

		#if điều_kiện
		    // code chỉ biên dịch nếu điều kiện đúng
		#elif điều_kiện_khác
		    // code thay thế
		#else
		    // code mặc định
		#endif

* VD:

		#define DEBUG 1

		#ifdef DEBUG
		    printf("Debug mode: Biến x = %d\n", x);
		#endif

* Ví dụ với #if / #elif / #else:

		#if __STDC_VERSION__ >= 201112L
		    // Code dùng tính năng C11 (ví dụ: _Generic, _Static_assert)
		    _Static_assert(sizeof(int) == 4, "int phải 4 byte");
		#elif __STDC_VERSION__ >= 199901L
		    // Code dùng C99
		    printf("Dùng C99\n");
		#else
		    // Code legacy (C89/ANSI C)
		    printf("Dùng chuẩn cũ\n");
		#endif

#### **4.2.Platform Detection**

* **_WIN32:** Windows (32/64-bit)

* **__linux__:** Linux

* **__APPLE__:** macOS / iOS

* **__GNUC__:** GCC compiler
	
* **__arm__ / __aarch64__:** ARM architecture

* **__x86_64__:** x86-64 (Intel/AMD 64-bit)
	
### **V. KỸ THUẬT XỬ LÝ**

#### **5.1.Token Pasting (##)**

* Token pasting (ghép token) dùng toán tử ## để nối hai token thành một định danh mới tại thời điểm tiền xử lý.

* **Cú pháp:** 

		#define CONCAT(a, b)    a##b

* **VD:**

		#define CONCAT(a, b)    a##b

		int CONCAT(var, 1) = 100;       // trở thành int var1 = 100;
		int CONCAT(test, Number) = 200; // trở thành int testNumber = 200;

#### **5.2.Stringizing (#)**

* Toán tử # chuyển tham số macro thành **chuỗi ký tự** (string literal).

**Cú pháp**:

* **Cú pháp:** 

		#define TO_STRING(x)    #x

* **VD:**

			#define TO_STRING(x)    #x

			printf("Gia tri PI: %s\n", TO_STRING(3.14159));     // in: Gia tri PI: 3.14159
			printf("Ten bien: %s\n", TO_STRING(myVar));         // in: Ten bien: myVar

#### **5.3.Variadic Macros**

* Từ C99, preprocessor hỗ trợ macro nhận số lượng tham số bất kỳ bằng ... và __VA_ARGS__.

* **Cú pháp:**

		#define TÊN_MACRO(fmt, ...)     replacement sử dụng __VA_ARGS__

* **VD:**

		#define LOG(fmt, ...)           printf(fmt "\n", ##__VA_ARGS__)
		LOG("Xin chao");                    // chỉ fmt
		LOG("Gia tri: %d", 42);             // 1 tham số bổ sung
		LOG("Ten: %s, tuoi: %d", "An", 25); // nhiều tham số		

#### **5.4.Chỉ thị #pragma**

* `#pragma` là chỉ thị phụ thuộc trình biên dịch, dùng để điều khiển hành vi compiler cụ thể.

* **Cú pháp:**

		#pragma directive [arguments]

* **Một số pragma phổ biến:**

	* **#pragma once:**	
	
		*  Ngăn include lặp (thay thế include guard truyền thống)		

	* **#pragma pack(push, n):**	
	
		*  Đặt alignment của struct = n byte (thường 1 để dữ liệu nhị phân)	

	* **#pragma pack(pop):**	
	
		*  Khôi phục alignment cũ

	* **#pragma warning(disable: n):**	
	
		*  Tắt cảnh báo cụ thể (ví dụ: 4996 cho deprecated)

	* **#pragma GCC diagnostic ignored "-Wunused-variable":**	
	
		*  Tắt warning GCC cụ thể

	* **#pragma message("text"):**	
	
		*  In thông báo tại thời điểm compile

* VD:

			#pragma pack(push, 1)      // alignment 1 byte – không padding

			struct PacketHeader {
			    uint16_t id;
			    uint32_t length;
			    uint8_t  type;
			};

			#pragma pack(pop)          // khôi phục alignment mặc định

### **VI. PREDEFINED MACROS**

#### **6.1.Định nghĩa**

* Macro tiền định (predefined macros) là các macro được trình biên dịch tự động định nghĩa trước khi bắt đầu tiền xử lý. Chúng cung cấp thông tin về:

	*  Vị trí mã nguồn
	
	*  Thời gian biên dịch
	
	*   Phiên bản chuẩn C 
	
	*   Tên hàm hiện tại
	
	*  Compiler và nền tảng
	


#### **6.2.Macro thông tin vị trí mã nguồn**

* `__FILE__:`

	*  Tên tệp nguồn hiện tại (bao gồm đường dẫn nếu compiler cung cấp)

* `__LINE__:`

	*  Số dòng hiện tại trong tệp nguồn

* `__func__:`

	*  Tên hàm hiện tại (từ C99, là identifier, không phải chuỗi)
	
* **VD:** 

			#include <stdio.h>

			#define LOG_ERROR(msg) \
			    fprintf(stderr, "[ERROR] %s:%d: %s(): %s\n", __FILE__, __LINE__, __func__, msg)

			int main() {
			    LOG_ERROR("Gia tri khong hop le");
			    return 0;
			}
			
			// Output:
			[ERROR] main.c:10: main(): Gia tri khong hop le

#### **6.3.Macro thời gian biên dịch**

* `__DATE__:`

	*  Ngày biên dịch (định dạng: "Mmm dd yyyy")

* `__TIME__:`

	*  Giờ biên dịch (định dạng: "hh:mm:ss")

* **VD:** 

		#include <stdio.h>

		int main() {
		    printf("Chuong trinh duoc build vao: %s %s\n", __DATE__, __TIME__);
		    return 0;
		}
		//Output:
		Chuong trinh duoc build vao: Mar  1 2026 17:26:45

### **VII. INCLUDE GUARD**

#### **7.1.Cơ chế hoạt động**

* Sử dụng `#ifndef` + `#define` + `#endif` để tạo một "lá chắn" (guard) dựa trên một định danh duy nhất.

*  Cú pháp chuẩn:
	
			// myheader.h
			#ifndef MYHEADER_H                  // Nếu MYHEADER_H chưa được định nghĩa
			#define MYHEADER_H                  // Định nghĩa nó ngay lập tức

			// Nội dung header thật sự
			#include <stdio.h>

			#define MAX_BUFFER 1024

			typedef struct {
			    int id;
			    char name[50];
			} Person;

			void printPerson(const Person *p);

			#endif /* MYHEADER_H */             // Kết thúc guard (có thể ghi chú tên để dễ đọc)		

#### **7.2.Thiết kế header file chuẩn**

* **Bảo vệ include lặp** → luôn có #pragma once hoặc include guard.

* Sắp xếp thứ tự include:

	* Header dự án trước
	
	* Header hệ thống sau
	
	* VD:

			#pragma once

			#include "mytypes.h"        // header dự án
			#include <stdio.h>          // hệ thống
			#include <stdlib.h>	  

* Dùng extern "C" cho tương thích C++.

* Không đặt định nghĩa (definition) trong header (trừ inline, static, macro).

	* Chỉ khai báo (declaration): prototype hàm, extern biến, typedef, struct khai báo.
	
	* Định nghĩa (implementation) → đặt trong .c file.

* Hạn chế #include không cần thiết

   												 
</details>


<details>
    <summary><strong>CHƯƠNG 8: MẢNG VÀ CHUỖI KÝ TỰ</strong></summary>

## **CHƯƠNG 8: MẢNG VÀ CHUỖI KÝ TỰ**

### **I.  Mảng một chiều**

#### **1.1. Bản chất và đặc điểm của mảng**

##### **1.1.1. Khái niệm**

* Mảng (array) là một tập hợp gồm nhiều phần tử có cùng kiểu dữ liệu, được cấp phát liên tiếp nhau trên bộ nhớ vật lý (contiguous memory).

##### **1.1.2. Đặc điểm**
	
* Tất cả các phần tử phải có cùng kiểu dữ liệu (int, float, char, …).

*  Các phần tử được lưu trữ ở các ô nhớ liên tiếp nhau về mặt vật lý.

*  Chỉ số (index) của mảng luôn bắt đầu từ 0.

*  Kích thước của mảng phải được xác định tại thời điểm biên dịch (trừ trường hợp VLA – sẽ trình bày sau).

##### **1.1.3. Địa chỉ phần tử**

* **Công thức:**
	
	* **Địa chỉ phần tử i** = **Địa chỉ cơ sở (Base address) + i × sizeof(kiểu dữ liệu)**
	
*  **Ví dụ:**

	*  Giả sử khai báo `int arr[5]`; và địa chỉ cơ sở của `arr` là `0x1000`, kích thước của int là 4 byte:
	
		*  `arr[0]` nằm tại `0x1000`
		
		* `arr[1]` nằm tại `0x1004`
		
		* `arr[2]` nằm tại `0x1008`  
	
	 	 		
#### **1.2. Khai báo và khởi tạo mảng một chiều**

* **Cú pháp khai báo mảng một chiều:**

			kiểu_dữ_liệu tên_mảng[kích_thước]; 

* **VD:**
	
		int numbers[10];           // Mảng 10 phần tử kiểu int
		float scores[50];          // Mảng 50 phần tử kiểu float
		char name[30];             // Mảng 30 ký tự

* **Khởi tạo mảng khi khai báo:**

	* Khởi tạo toàn bộ giá trị:

			int arr[5] = {10, 20, 30, 40, 50};
	
	* Khởi tạo một phần (các phần tử còn lại tự động được gán giá trị 0):

			int arr[5] = {10, 20};     // arr[0]=10, arr[1]=20, arr[2..4]=0
	
	* Khởi tạo tất cả phần tử bằng 0 (cách viết phổ biến):

			int arr[100] = {0};

* **Lưu ý:**

	*  Nếu không khởi tạo giá trị khi khai báo, các phần tử của mảng cục bộ (local array) sẽ chứa giá trị rác (undefined value).

#### **1.3. Chỉ định phần tử khởi tạo**

##### **1.3.1.Khái niệm**

* Chuẩn C99 giới thiệu tính năng Designated Initializers, cho phép khởi tạo các phần tử mảng theo chỉ số cụ thể, không nhất thiết phải theo thứ tự.

##### **1.3.2.Cú pháp**
	
		int arr[so_phan_tu] = {[chỉ_số] = giá_trị, ...};
	
* VD1:

		int numbers[10] = {
		    [0] = 5,
		    [3] = 42,
		    [9] = 100
		};
	
	* `numbers[0] = 5`
		
	* `numbers[3] = 42`
		
	* `numbers[9] = 100`
	
	*  Các phần tử còn lại được tự động khởi tạo bằng 0.     

* VD2:

		int arr[100] = {
		    [0 ... 9] = 1,      // GNU extension (range initializer)
		    [10 ... 49] = 2,
		    [50] = 999
		};

##### **1.3.3.Lưu ý**
	
* Chỉ số trong dấu ngoặc vuông phải là hằng số (constant expression).
		
* Tính năng range `[first ... last]` là mở rộng của GCC, không phải chuẩn C99 thuần túy.

#### **1.4. Tính toán kích thước mảng**

* Để xác định kích thước của mảng, ngôn ngữ C cung cấp toán tử `sizeof`.

	*  `sizeof(tên_mảng)` → trả về tổng kích thước (theo byte) của toàn bộ mảng.
	
	*  `sizeof(tên_mảng[0])` → trả về kích thước của một phần tử.

* **Công thức:**

		size_t n = sizeof(arr) / sizeof(arr[0]);
		
* **Ví dụ:**

		#include <stdio.h>

		int main(void)
		{
		    int arr[] = {10, 20, 30, 40, 50};
		    
		    printf("Kich thuoc toan bo mang: %zu bytes\n", sizeof(arr));
		    printf("Kich thuoc mot phan tu: %zu bytes\n", sizeof(arr[0]));
		    printf("So luong phan tu: %zu\n", sizeof(arr) / sizeof(arr[0]));
		    
		    return 0;
		}

	
#### **1.5. Buffer Overflow**

* Một trong những đặc điểm nguy hiểm nhất của mảng trong C là ngôn ngữ không tự động kiểm tra ranh giới mảng tại thời điểm biên dịch lẫn thực thi.

	* Truy cập hoặc ghi dữ liệu ngoài giới hạn mảng dẫn đến hành vi không xác định (Undefined Behavior).
	
	* Có thể gây ra:
	
		*  Ghi đè dữ liệu của các biến khác
		
		*  Làm sập chương trình (crash)
		 
* **VD:**

		#include <stdio.h>

		int main(void)
		{
		    int arr[5] = {1, 2, 3, 4, 5};
		    int x = 999;
		    
		    arr[10] = 888;        // Vượt biên nghiêm trọng!
		    
		    printf("Gia tri x = %d\n", x);   // Kết quả không thể dự đoán
		    
		    return 0;
		}

### **II.  Mảng đa chiều**

#### **2.1. Cấu trúc và cách khai báo**

* Mảng đa chiều trong C được xây dựng theo nguyên tắc “mảng của các mảng”

* **Cú pháp:**

		kiểu_dữ_liệu tên_mảng[số_hàng][số_cột];

* **Khai báo:**
	
		int matrix[3][4];        // Mảng 2 chiều: 3 hàng, 4 cột
		float scores[5][10];     // Mảng 2 chiều: 5 hàng, 10 cột
		int cube[2][3][4];       // Mảng 3 chiều
	
* **Khởi tạo mảng đa chiều khi khai báo:**
	
		int matrix[3][4] = {
		    {1,  2,  3,  4},
		    {5,  6,  7,  8},
		    {9, 10, 11, 12}
		};

* **Khởi tạo một phần (các phần tử còn lại tự động bằng 0):**
	
		int matrix[3][4] = {
		    {1, 2},           // Hàng 0
		    {5},              // Hàng 1
		    {9, 10, 11}       // Hàng 2
		};

* **Quy tắc:**

	*  Khi khởi tạo ngay lúc khai báo, chỉ được phép bỏ trống kích thước của chiều ngoài cùng (chiều thứ nhất).
	
	*  Các chiều còn lại bắt buộc phải ghi rõ kích thước.
	
	*  VD đúng: 
	
			int arr[][3] = {{1,2,3}, {4,5,6}, {7,8,9}};   // Hợp lệ

	*  VD sai: 
	
			int arr[3][] = ...;   // Sai – không được bỏ trống chiều trong
					
#### **2.2. Tổ chức bộ nhớ theo thứ tự Row-major Order**

* Trong ngôn ngữ C, mảng đa chiều được lưu trữ theo thứ tự ưu tiên hàng

* **Ý nghĩa:** 

	* Các phần tử thuộc cùng một hàng được lưu trữ liền kề nhau trong bộ nhớ.
	
	* Chỉ sau khi hết một hàng, chương trình mới chuyển sang lưu trữ hàng tiếp theo.

* **Minh họa:**

	* Với mảng `int matrix[3][4]` được khởi tạo như sau:

			int matrix[3][4] = {
			    {10, 20, 30, 40},
			    {50, 60, 70, 80},
			    {90, 100, 110, 120}
			};
	
	* Trong bộ nhớ vật lý, các phần tử được sắp xếp theo thứ tự tuyến tính như sau:

			matrix[0][0]  matrix[0][1]  matrix[0][2]  matrix[0][3]
			matrix[1][0]  matrix[1][1]  matrix[1][2]  matrix[1][3]
			matrix[2][0]  matrix[2][1]  matrix[2][2]  matrix[2][3] 

* **Ý nghĩa:**

	* Duyệt mảng theo hàng (row-by-row) sẽ tận dụng tối đa bộ nhớ đệm (CPU Cache Locality), giúp chương trình chạy nhanh hơn.
	
	* Duyệt theo cột (column-by-column) thường chậm hơn do kém tận dụng cache. 

* **VD:** 

		// Duyệt theo hàng - hiệu năng tốt
		for(int i = 0; i < 3; i++) {
		    for(int j = 0; j < 4; j++) {
		        printf("%d ", matrix[i][j]);
		    }
		    printf("\n");
		}
	
	
#### **2.3. Mảng có kích thước biến thiên**

* Từ chuẩn C99, ngôn ngữ C cho phép khai báo mảng với kích thước là một biến số (được xác định tại thời điểm chạy chương trình).

* **Cú pháp:**

		int n;
		scanf("%d", &n);
		int arr[n];           // VLA - kích thước được xác định lúc chạy
	

* **Đặc điểm:**

	*  Kích thước mảng được tính tại thời điểm thực thi (runtime), không phải lúc biên dịch.
	
	*  VLA chỉ có thể được khai báo trong phạm vi khối (block scope), thường là bên trong hàm.
	
	* VLA được cấp phát trên ngăn xếp (Stack), không phải trên Heap như `malloc()`. 
	
* **VD:**

		 #include <stdio.h>

		int main(void)
		{
		    int rows, cols;
		    printf("Nhap so hang va so cot: ");
		    scanf("%d %d", &rows, &cols);
		    
		    int matrix[rows][cols];   // VLA hai chiều
		    
		    // Gán giá trị
		    for(int i = 0; i < rows; i++) {
		        for(int j = 0; j < cols; j++) {
		            matrix[i][j] = i * cols + j + 1;
		        }
		    }
		    
		    // In ra màn hình
		    for(int i = 0; i < rows; i++) {
		        for(int j = 0; j < cols; j++) {
		            printf("%4d", matrix[i][j]);
		        }
		        printf("\n");
		    }
		    
		    return 0;
		}



### **III.  Phân rã mảng thành con trỏ (Array Decay)**

#### **3.1. Cơ chế**

* Trong hầu hết các biểu thức, tên của mảng sẽ tự động được chuyển đổi thành một con trỏ trỏ đến phần tử đầu tiên của mảng đó.

* Quá trình chuyển đổi này được gọi là Array Decay.

	* Phân rã xảy ra ngầm định (implicit conversion), không cần biết toán tử nào.
	
	* Khi phân rã, mảng mất hoàn toàn thông tin về kích thước (dimension) và kiểu mảng. 
	
	*  Việc truyền mảng vào hàm thực chất là truyền bản sao của con trỏ trỏ đến phần tử đầu tiên (`&arr[0]`).
	
* **Ví dụ:**

		 #include <stdio.h>

		void printSize(int arr[])   // Tham số thực chất là int*
		{
		    printf("Kich thuoc ben trong ham: %zu\n", sizeof(arr));  // Kết quả là kích thước của con trỏ (thường 8 bytes)
		}

		int main(void)
		{
		    int numbers[10] = {0};
		    
		    printf("Kich thuoc ben ngoai ham: %zu\n", sizeof(numbers));  // Kết quả là 40 bytes (10 * 4)
		    printSize(numbers);   // Mảng thoái hóa thành con trỏ khi truyền vào hàm
		    
		    return 0;
		}
	
#### **3.2. Các trường hợp ngoại lệ không phân rã**

* Khi tên mảng là toán hạng của toán tử `sizeof`.

* Khi tên mảng là toán hạng của toán tử lấy địa chỉ `&` (unary &).

*  Khi chuỗi hằng được sử dụng để khởi tạo mảng ký tự.

* **VD:**

		int arr[10];

		sizeof(arr);           // Không thoái hóa → trả về kích thước toàn bộ mảng (40 bytes)

		&arr;                  // Không thoái hóa → kiểu là "con trỏ trỏ đến mảng 10 phần tử int" (int (*)[10])

		int arr2[] = "Hello";  // Chuỗi hằng khởi tạo mảng → không thoái hóa

#### **3.3. Tương đương cú pháp giữa mảng và con trỏ**

* Do cơ chế phân rã, trình biên dịch hiểu một số biểu thức mảng và con trỏ là tương đương.

		arr[i]   ≡   *(arr + i)

	* `arr[i]` là cú pháp truy cập phần tử (array subscript).

	* `*(arr + i)` là phép toán con trỏ (pointer arithmetic).

* VD:

		int arr[5] = {10, 20, 30, 40, 50};
		int *ptr = arr;        // ptr thoái hóa từ arr

		printf("%d\n", arr[2]);     // In ra 30
		printf("%d\n", *(arr + 2)); // Tương đương, cũng in ra 30
		printf("%d\n", ptr[2]);     // Tương đương
		printf("%d\n", *(ptr + 2)); // Tương đương

* **Lưu ý:**
	
	* 	Mảng không thể gán giá trị mới cho tên mảng (`arr = ...` là sai).
	
	*   Con trỏ có thể thay đổi vị trí trỏ (`ptr = ptr + 1` là hợp lệ).

#### **3.4. Phân biệt mảng con trỏ và con trỏ trỏ đến mảng**

##### **3.4.1. Mảng con trỏ (Array of Pointers)**

* Là một mảng, trong đó mỗi phần tử là một con trỏ.

*  Cú pháp: `kiểu_dữ_liệu *tên_mảng[kích_thước]`;

* Thường dùng để tạo ma trận răng cưa (jagged array) hoặc quản lý nhiều chuỗi ký tự.

* VD:  

		char *names[3] = {
		    "Nguyen Van A",
		    "Tran Thi B",
		    "Le Van C"
		};

	* `names` là mảng chứa 3 con trỏ kiểu `char*`.
	
##### **3.4.2. Con trỏ trỏ đến mảng (Pointer to an Array)**

* Là một con trỏ, trỏ đến toàn bộ một mảng.

*  Cú pháp: `kiểu_dữ_liệu (*tên_con_trỏ)[kích_thước]`;

* Dùng khi cần giữ nguyên thông tin kích thước của mảng.

* VD:

		int matrix[3][4];
		int (*ptr)[4];     // Con trỏ trỏ đến mảng 4 phần tử int

		ptr = matrix;      // ptr trỏ đến hàng đầu tiên của matrix 

### **IV.  Chuỗi ký tự trong C**

#### **4.1. Khái niệm chuỗi ký tự kết thúc null**

* Chuỗi ký tự (string) trong C là một mảng ký tự một chiều được kết thúc bằng ký tự null (`'\0'`)

* Ký tự null có giá trị ASCII bằng 0 và đóng vai trò là sentinel value (giá trị đánh dấu kết thúc).

* **Đặc điểm:**
	
	* Chuỗi phải luôn kết thúc bằng  `'\0'`.
	
	*  Ký tự `'\0'` không được tính vào chiều dài logic của chuỗi.
	
	*  Tất cả các hàm thao tác chuỗi trong thư viện chuẩn (`<string.h>`) đều dựa vào ký tự `\0` để xác định điểm kết thúc chuỗi
	
* **Ví dụ:**

		char str[6] = {'H', 'e', 'l', 'l', 'o', '\0'};   // Cách viết rõ ràng
		// hoặc
		char str[] = "Hello";     // Cách viết phổ biến và ngắn gọn hơn
	
#### **4.2. Phân biệt chuỗi hằng và mảng ký tự**

##### **4.2.1. Chuỗi hằng (String Literal)**

* Được viết dưới dạng ngoặc kép: `"Hello World"`

* Được lưu trữ trong phân vùng bộ nhớ chỉ đọc (read-only section, thường là `.rodata`).

*  Kiểu dữ liệu: `const char[]` (từ C99 trở đi).

*  Không được phép sửa đổi nội dung. Việc cố tình sửa sẽ gây lỗi thời gian chạy (thường là Segmentation Fault).

		char *str = "Hello";     // str trỏ đến chuỗi hằng
		// str[0] = 'h';         // SAI – Undefined Behavior, có thể gây crash

##### **4.2.2. Mảng ký tự (Character Array)**

* Là mảng ký tự thông thường được khởi tạo từ chuỗi hằng.

* Nội dung chuỗi hằng được sao chép vào mảng nằm trên Stack (hoặc vùng dữ liệu nếu là biến toàn cục).

*  Có thể sửa đổi nội dung tự do.

*  VD:

		char str[] = "Hello";    // Mảng ký tự, có thể sửa đổi
		str[0] = 'h';            // Hợp lệ → chuỗi trở thành "hello"

##### **4.2.3. Chiều dài logic và dung lượng bộ nhớ của chuỗi**

* **Chiều dài logic (Logical Length):**

	*  Là số lượng ký tự in được (không tính ký tự `'\0'`).
	
	*  Được tính bằng hàm `strlen()` trong thư viện `<string.h>`

* **Dung lượng bộ nhớ (Storage Size):**

	*  Là kích thước thực tế của mảng ký tự, bao gồm cả ký tự `'\0'`.
	
	*  Phải luôn lớn hơn hoặc bằng chiều dài logic + 1 byte.

			#include <stdio.h>
			#include <string.h>

			int main(void)
			{
			    char str[20] = "Hello";     // Dung lượng bộ nhớ = 20 bytes
			    
			    printf("Chuoi: %s\n", str);
			    printf("Chieu dai logic (strlen): %zu\n", strlen(str));   // Kết quả: 5
			    printf("Dung luong bo nho (sizeof): %zu\n", sizeof(str)); // Kết quả: 20
			    
			    return 0;
			}

### **V.  Thư viện chuẩn thao tác chuỗi**

#### **5.1. Các hàm kiểm tra và tìm kiếm chuỗi**

* Nhóm hàm này dùng để lấy thông tin về chuỗi hoặc tìm vị trí của ký tự/chuỗi con.

* **Các hàm chính:**

	* `strlen(const char *str)`
	
		* Trả về chiều dài logic của chuỗi (không tính ký tự `'\0'`).  

	* `strchr(const char *str, int c)`
	
		* Tìm ký tự `c` đầu tiên xuất hiện trong chuỗi `str`.
		
		* Trả về con trỏ đến vị trí tìm thấy, hoặc `NULL` nếu không tìm thấy.
		
	* `strrchr(const char *str, int c)`
	
		* Tìm ký tự c cuối cùng xuất hiện trong chuỗi (tìm từ phải sang).
	
	*  `strstr(const char *haystack, const char *needle)`

		* Tìm chuỗi con `needle` bên trong chuỗi `haystack`.
		
		*  Trả về con trỏ đến vị trí bắt đầu của chuỗi con, hoặc `NULL` nếu không tìm thấy.
			
* **Ví dụ:**

			#include <stdio.h>
			#include <string.h>

			int main(void)
			{
			    char str[] = "Hello, World! Welcome to C programming.";
			    
			    printf("Chieu dai chuoi: %zu\n", strlen(str));
			    
			    char *pos1 = strchr(str, 'W');
			    if (pos1) 
			        printf("Tim thay 'W' tai vi tri: %ld\n", pos1 - str);
			    
			    char *pos2 = strstr(str, "Welcome");
			    if (pos2) 
			        printf("Tim thay \"Welcome\" tai vi tri: %ld\n", pos2 - str);
			    
			    return 0;
			}
	
#### **5.2. Các hàm sao chép và nối chuỗi**

* `strcpy(char *dest, const char *src)`

	*  Sao chép chuỗi nguồn `src` (kể cả `'\0'`) vào vùng đích `dest`.

* `strcat(char *dest, const char *src)`

	*  Nối chuỗi nguồn `src` vào cuối chuỗi đích `dest`.

* `strncpy(char *dest, const char *src, size_t n)`

	*  Sao chép tối đa `n` ký tự từ `src` sang `dest`.

* `strncat(char *dest, const char *src, size_t n))`

	*  Nối tối đa `n` ký tự từ `src` vào `dest`.

* **VD:**

			#include <stdio.h>
			#include <string.h>

			int main(void)
			{
			    char dest[20] = "Hello";
			    char src[] = " World";
			    
			    // Sử dụng hàm an toàn
			    strncat(dest, src, sizeof(dest) - strlen(dest) - 1);
			    
			    printf("Sau khi noi: %s\n", dest);
			    
			    return 0;
			}

#### **5.3. Các hàm so sánh chuỗi**

* **Các hàm chính:**

	* `strcmp(const char *str1, const char *str2)`: So sánh toàn bộ hai chuỗi.
	
		*   Trả về 0 nếu hai chuỗi giống nhau.
		
		*   Trả về số âm nếu `str1` nhỏ hơn `str2`.
		
		*   Trả về số dương nếu `str1` lớn hơn `str2`. 

	* `strncmp(const char *str1, const char *str2, size_t n)`: So sánh tối đa n ký tự đầu tiên của hai chuỗi.
	

		
* **VD:**

			#include <stdio.h>
			#include <string.h>

			int main(void)
			{
			    char s1[] = "Apple";
			    char s2[] = "Banana";
			    char s3[] = "Apple";
			    
			    printf("strcmp(s1, s3) = %d\n", strcmp(s1, s3));   // 0
			    printf("strcmp(s1, s2) = %d\n", strcmp(s1, s2));   // số âm
			    
			    if (strncmp("HelloWorld", "Hello", 5) == 0)
			        printf("5 ky tu dau tien giong nhau\n");
			    
			    return 0;
			}

#### **5.4. Tách chuỗi bằng hàm strtok (Tokenization)**

* Hàm `strtok` được sử dụng để chia tách một chuỗi thành các phần nhỏ hơn (gọi là token) dựa trên một hoặc nhiều ký tự phân cách (delimiters).

* Cú pháp:
	
		char *strtok(char *str, const char *delim);

* **Đặc điểm:**

	* Hàm `strtok` là hàm stateful (có nhớ trạng thái): nó sử dụng một biến tĩnh nội bộ để lưu vị trí cắt chuỗi ở lần gọi trước. 
	
	*  Lần gọi đầu tiên truyền vào chuỗi cần tách (`str`), các lần gọi sau truyền `NULL`.
	
	*  Hàm sẽ thay thế ký tự phân cách bằng ký tự `'\0'` trong chuỗi gốc.
	
	*  Sau khi tách xong, chuỗi gốc sẽ bị sửa đổi (không còn nguyên vẹn).
	

		
* **VD:**

			#include <stdio.h>
			#include <string.h>

			int main(void)
			{
			    char str[] = "Nguyen,Van,A;30;Ha Noi;Vietnam";
			    char *token;
			    
			    printf("Chuoi goc: %s\n\n", str);
			    
			    // Lần gọi đầu tiên
			    token = strtok(str, ",;");
			    
			    while (token != NULL) {
			        printf("Token: %s\n", token);
			        token = strtok(NULL, ",;");   // Các lần gọi sau
			    }
			    
			    return 0;
			}

* **Output:**

			Chuoi goc: Nguyen,Van,A;30;Ha Noi;Vietnam

			Token: Nguyen
			Token: Van
			Token: A
			Token: 30
			Token: Ha Noi
			Token: Vietnam							

### **VI.  Ký tự mở rộng và hỗ trợ Unicode**

#### **6.1. Hạn chế của bảng mã ASCII**

* ASCII sử dụng 1 byte (8 bit), chỉ biểu diễn được 256 ký tự.

* Không thể biểu diễn đầy đủ bảng chữ cái tiếng Việt (có dấu), chữ cái có dấu của các ngôn ngữ châu Âu, hay các ký tự Đông Á.

*  Không hỗ trợ emoji và các ký tự biểu tượng hiện đại.

#### **6.2. Ký tự rộng (Wide Characters) với wchar_t**

* Để khắc phục hạn chế của ASCII, chuẩn C giới thiệu kiểu dữ liệu wide character (`wchar_t`) và thư viện `<wchar.h>`

* **Đặc điểm:**
	
	* `wchar_t` thường chiếm 2 hoặc 4 byte tùy theo nền tảng và compiler

	* Hằng chuỗi rộng sử dụng tiền tố `L`.
	
	* Thư viện `<wchar.h>` cung cấp các hàm tương đương `<string.h>` nhưng dành cho ký tự rộng
		
* **VD:**

			#include <stdio.h>
			#include <wchar.h>

			int main(void)
			{
			    wchar_t str[] = L"Xin chào Việt Nam! Hello World! 你好";
			    
			    wprintf(L"Chuỗi rộng: %ls\n", str);
			    wprintf(L"Chiều dài: %zu\n", wcslen(str));
			    
			    return 0;
			}

#### **6.3. Hỗ trợ Unicode hiện đại trong chuẩn C11**

* Chuẩn C11 đã cải tiến đáng kể hỗ trợ Unicode bằng cách giới thiệu các kiểu dữ liệu mới và định dạng UTF-8.

* **Các kiểu dữ liệu mới:**
	
	* `char16_t` : Dùng cho UTF-16 (thường 2 byte).

	* `char32_t` : Dùng cho UTF-32 (thường 4 byte).
	
	* Thư viện hỗ trợ: `<uchar.h>`



### **VII. THAO TÁC AN TOÀN VÀ CÁC HÀM VÙNG NHỚ TRÊN MẢNG**

#### **7.1. Truyền mảng hai chiều vào hàm**

##### **7.1.1.Khái niệm**

* Khi truyền mảng một chiều `int arr[10]` vào hàm, nó phân rã thành con trỏ trỏ đến phần tử đầu tiên (`int *`)

* Đối với mảng hai chiều `int matrix[3][4]`, nó được hiểu là mảng gồm 3 phần tử, mỗi phần tử là một mảng 4 số nguyên
 

##### **7.1.2.Đặc điểm:**
	
* Đối với mảng hai chiều `int matrix[3][4]`, nó được hiểu là mảng gồm 3 phần tử, mỗi phần tử là một mảng 4 số nguyên
	
* Khi truyền matrix vào hàm, nó phân rã thành con trỏ đến mảng gồm 4 phần tử int, mang kiểu dữ liệu: `int (*)[4]`

	* Nó không phân rã thành con trỏ trỏ đến con trỏ (`int **`) 

* Để tính toán địa chỉ của phần tử matrix[i][j], trình biên dịch áp dụng công thức

	* **Địa chỉ = Địa chỉ cơ sở + (i x Số cột + j) x sizeof(kiểu_dữ_liệu)**
	
* Nếu không biết số cột, compiler không thể tính toán được bước nhảy để đi tới hàng thứ i   

##### **7.1.3.Cú pháp**

* Chiều đầu tiên (số hàng) có thể bỏ trống, nhưng chiều thứ hai (số cột) phải là một hằng số cụ thể

			#include<stdio.h>
			#define COLS 4

			void inMaTran(int arr[][COLS], int rows){
				for(int i = 0; i < rows; i++){
					for(int j = 0; j < COLS; j++){
						printf("%d", arr[i][j]);
					}
					printf("\n");
				}
			}
			int main(void){
				int matrix[3][COLS] = {
					{1, 2, 3, 4},
					{5, 6, 7, 8},
					{9, 10, 11, 12}
				};
				inMaTran(matrix, 3);
				return 0;
			}



#### **7.2.Các hàm thao tác trên vùng nhớ mảng (`<string.h>`)**

##### **7.2.1.memset()**

###### **7.2.1.1.Khái niệm**

* Các hàm này thao tác trực tiếp trên các byte bộ nhớ thô (`void *`), bỏ qua ràng buộc về kiểu dữ liệu nên tốc độ xử lý rất nhanh


###### **7.2.1.2.Cú pháp**

			void *memset(void *ptr, int value, size_t num);

			// ptr: Con trỏ trỏ đến khối bộ nhớ cần điền
			// value: giá trị cần điền 
			// num: số lương byte cần điền
			
	
* Lưu ý:

	* memset điền theo từng byte, nên không thể dùng nó để khởi tạo mảng số nguyên int với các giá trị khác ngoài 0 và -1 
	
	* VD1: 
	
		* Đặt giá trị là 1 sẽ khiên mỗi byte trong số 4 byte của kiểu int nhận giá trị 0x01, kết quả phần tử đó sẽ có giá trị 0x01010101 = 16843009
		
	* VD2: 

			#include <stdio.h>
			#include <string.h>
			int main(void){
				int arr[5] = {1, 2, 3, 4, 5};
				memset(arr, 0, sizeof(arr));
				for(int i = 0; i < 5; i++){
					printf("%d ", arr[i]);
				}
				return 0;
			} 
	
		* Đặt giá trị là 1 sẽ khiên mỗi byte trong số 4 byte của kiểu int nhận giá trị 0x01, kết quả phần tử đó sẽ có giá trị 0x01010101 = 16843009


##### **7.2.2.memcpy**

###### **7.2.2.1.Khái niệm**

* `memcpy()` là hàm dùng để sao chép một số byte xác định từ vùng nhớ sang vùng nhớ đích

* Hàm này giả định rằng hai vùng nhớ không chồng lấn lên nhau

* Nếu vùng nguồn và đích bị chồng lấn, kết quả sẽ là Undefined Behavior  

###### **7.2.2.2.Cú pháp**

			void *memcpy(void *destination, const void *source, size_t num);

			// destination: Địa chỉ vùng nhớ đích
			// source: Địa chỉ vùng nhớ nguồn 
			// num: Số byte cần sao chép

* VD:
			
	
			#include <stdio.h>
			#include <string.h>

			int main() {
			    int source[] = {1, 2, 3, 4, 5};
			    int destination[5];

			    memcpy(destination, source, 5 * sizeof(int));

			    printf("Mang destination: ");
			    for (int i = 0; i < 5; i++) {
			        printf("%d ", destination[i]);
			    }

			    return 0;
			}

			// Mang destination: 1 2 3 4 5


###### **7.2.2.3. Đặc điểm**

* Sao chép dữ liệu theo từng byte.

* Tốc độ thực thi nhanh.

* Không kiểm tra sự chồng lấn giữa hai vùng nhớ.

##### **7.2.3.memmove()**

###### **7.2.3.1.Khái niệm**

* `memmove()` dùng để sao chép dữ liệu từ vùng nhớ nguồn sang vùng nhớ đích giống như `memcpy()`, nhưng hỗ trợ an toàn khi **hai vùng nhớ bị chồng lấn lên nhau**.

###### **7.2.3.2.Cú pháp**

			void *memmove(void *destination, const void *source, size_t num);

			// destination: Địa chỉ vùng nhớ đích
			// source: Địa chỉ vùng nhớ nguồn 
			// num: Số byte cần sao chép

* VD:
			
	
		#include <stdio.h>
		#include <string.h>

		int main() {
		    int arr[5] = {1, 2, 3, 4, 5};

		    // Dịch các phần tử sang phải một vị trí
		    memmove(arr + 1, arr, 4 * sizeof(int));

		    for (int i = 0; i < 5; i++) {
		        printf("%d ", arr[i]);
		    }

		    return 0;
		}

		// 1 1 2 3 4


###### **7.2.3.3. Đặc điểm**

* Sao chép dữ liệu theo từng byte.

* An toàn khi hai vùng nhớ chồng lấn nhau.

* Thường dùng để dịch chuyển dữ liệu trong cùng một mảng.

### **VIII. KỸ THUẬT NÂNG CAO VỚI CHUỖI**

#### **8.1. fgets**

##### **8.1.1.Giới thiệu**

* **gets(str):**

	*  Đọc dữ liệu đến khi gặp ký tự xuống dòng (`'\n'`).
	
	*  Hàm này hoàn toàn không kiểm soát kích thước mảng nhận vào, cực kỳ dễ bị khai thác lỗi tràn bộ đệm (Buffer Overflow).

* **scanf("%s", str):**

	*  Dừng lại khi gặp bất kỳ ký tự khoảng trắng nào (phím cách, tab, xuống dòng).
	
	*  Ngoài ra cũng không giới hạn được độ dài nhập vào trừ khi viết tường minh scanf("%49s", str).
 

##### **8.1.2.Cú pháp**
	
		char *fgets(char *str, int num, FILE *stream);
	
* str: Con trỏ tới mảng ký tự nhận dữ liệu.

* num: Số ký tự tối đa được phép đọc (bao gồm cả ký tự kết thúc \0) nên fgets chỉ đọc tối đa num - 1 ký tự từ bàn phím.

* stream: Nguồn nhập dữ liệu

##### **8.1.3. Lưu ý**
	
*    Khi bạn nhập chuỗi từ bàn phím và nhấn Enter, fgets sẽ đọc luôn ký tự xuống dòng `'\n'` này và lưu vào mảng nếu còn đủ chỗ chứa, sau đó mới thêm ký tự `'\0'`.

*    Điều này khiến chuỗi bị xuống dòng ngoài ý muốn khi in ra và gây sai lệch khi so sánh chuỗi bằng strcmp.

*    Cách xử lý:

			#include <stdio.h>
			#include <string.h>

			int main(void) {
			    char name[20];
			    
			    printf("Nhập tên của bạn: ");
			    fgets(name, sizeof(name), stdin);
			    
			    // Loại bỏ ký tự '\n' nếu có
			    name[strcspn(name, "\n")] = '\0';
			    
			    printf("Xin chào: [%s]!\n", name); // Không bị xuống dòng trước dấu '!'
			    return 0;
			} 

#### **8.2. <ctype.h>**

##### **8.2.1.Giới thiệu**

* Thư viện này cung cấp các hàm tối ưu cao để phân tích và chuyển đổi các ký tự đơn lẻ.

##### **8.2.2. Đặc điểm**

* Các hàm này nhận vào một ký tự (dưới dạng int) và trả về giá trị khác 0 (true) nếu thỏa mãn điều kiện, ngược lại trả về 0 (false):

	*  `isalpha(c)` : Có phải chữ cái (a-z, A-Z) hay không

	*  `isdigit(c)` : Có phải chữ số (0-9) hay không

	*  `isalnum(c)` : Có phải chữ cái hoặc chữ số (isalpha hoặc isdigit)

	*  `islower(c)` : Có phải chữ cái viết thường hay không

	*  `isupper(c)` :Có phải chữ cái viết hoa hay không

	*  `isspace(c)` : Có phải khoảng trắng (dấu cách ' ', '\t', '\n', '\r') hay không
	
	*  `tolower(int c)` :Chuyển ký tự in hoa thành in thường. Nếu ký tự không phải là chữ hoa, giữ nguyên.

	*  `toupper(int c)` : Chuyển ký tự thường thành in hoa.
	
##### **8.2.3. VD**

		#include <stdio.h>
		#include <ctype.h>

		void chuanHoaTen(char str[]) {
		    int i = 0;
		    int vietHoaTiepTheo = 1; // Cờ đánh dấu cần viết hoa ký tự tiếp theo

		    while (str[i] != '\0') {
		        if (isspace(str[i])) {
		            vietHoaTiepTheo = 1;
		        } else {
		            if (vietHoaTiepTheo) {
		                str[i] = toupper(str[i]);
		                vietHoaTiepTheo = 0;
		            } else {
		                str[i] = tolower(str[i]);
		            }
		        }
		        i++;
		    }
		}

		int main(void) {
		    char name[] = "nGuYEn vAn a";
		    chuanHoaTen(name);
		    printf("Chuỗi chuẩn hóa: %s\n", name); // Output: Nguyen Van A
		    return 0;
		}
 

		

			 										
   </details> 
   

<details>
    <summary><strong>CHƯƠNG 9: KIỂU DỮ LIỆU TỰ ĐỊNH NGHĨA</strong></summary>

## **CHƯƠNG 9: KIỂU DỮ LIỆU TỰ ĐỊNH NGHĨA**

### **I.  Cấu trúc (Structure)**

#### **1.1. Bản chất và cú pháp định nghĩa cấu trúc**

##### **1.1.1. Khái niệm**

* Cấu trúc là kiểu dữ liệu phức hợp (composite data type) do người dùng định nghĩa

*  Nó cho phép đóng gói nhiều biến có kiểu dữ liệu khác nhau vào chung một khối dữ liệu dưới một tên chung.

##### **1.1.2. Đặc điểm**
	
* Cấu trúc là kiểu dữ liệu do người lập trình tự tạo ra.

*  Mỗi thành viên (member) bên trong cấu trúc có thể có kiểu dữ liệu khác nhau..

*  Chỉ số (index) của mảng luôn bắt đầu từ 0.

*  Việc khai báo cấu trúc chỉ tạo ra khuôn mẫu (template), không chiếm bộ nhớ.

##### **1.1.3. Cú pháp**

		struct Tên_Cấu_trúc {
		    kiểu_dữ_liệu thành_viên_1;
		    kiểu_dữ_liệu thành_viên_2;
		    // ... các thành viên khác
		};

* **VD:**

			// Định nghĩa khuôn mẫu cấu trúc
			struct Date {
			    int day;
			    int month;
			    int year;
			};

			struct Student {
			    char name[50];
			    int studentID;
			    float gpa;
			    struct Date birthDate;     // Thành viên là một cấu trúc khác
			};



#### **1.2. Truy xuất thành viên cấu trúc**

##### **1.2.1.Khái niệm**

* Để truy cập và thao tác với các thành viên bên trong một biến cấu trúc, C cung cấp hai toán tử chính:

	*  **Toán tử dấu chấm (.) – Dot operator:** 
	
		* Dùng khi làm việc trực tiếp với biến cấu trúc.
	
	*  **Toán tử mũi tên (->) – Arrow operator:** 
	
		* Dùng khi làm việc thông qua con trỏ trỏ đến cấu trúc. 

##### **1.2.2.VD**
	
		#include <stdio.h>

		struct Student {
		    char name[50];
		    int studentID;
		    float gpa;
		};

		int main(void)
		{
		    struct Student s1;
		    struct Student *ptr = &s1;

		    // Truy xuất bằng toán tử dấu chấm
		    s1.studentID = 2023001;
		    s1.gpa = 3.85;

		    // Truy xuất bằng toán tử mũi tên
		    ptr->gpa = 3.90;                    // Tương đương với (*ptr).gpa

		    printf("Ma so sinh vien: %d\n", s1.studentID);
		    printf("Diem GPA: %.2f\n", ptr->gpa);

		    return 0;
		}



#### **1.3. Khởi tạo và phép gán cấu trúc**

* Cấu trúc hỗ trợ nhiều cách khởi tạo và có thể được gán trực tiếp bằng toán tử `=`.

*  **Khởi tạo theo thứ tự thành viên:**
	
		struct Date d1 = {25, 12, 2024};
		struct Student s1 = {"Nguyen Van A", 2023001, 3.75, {15, 5, 2005}};

*  **Khởi tạo chỉ định (Designated Initializers – C99):**

	*  Cách này cho phép khởi tạo theo tên thành viên, không phụ thuộc thứ tự và chỉ khởi tạo một số thành viên.
	
			struct Student s2 = {
			    .name = "Tran Thi B",
			    .studentID = 2023002,
			    .gpa = 3.68
			    // birthDate sẽ tự động bằng 0
			};
		
* **Phép gán cấu trúc:**

	*  Trong C, hai biến cấu trúc cùng kiểu có thể gán trực tiếp cho nhau.
	
	*  Toán tử `=` sẽ sao chép toàn bộ nội dung (byte-by-byte). 

			struct Student s3;
			s3 = s1;        // Sao chép toàn bộ dữ liệu từ s1 sang s3
		
* **Ví dụ:**

		#include <stdio.h>
		#include <string.h>

		struct Student {
		    char name[50];
		    int studentID;
		    float gpa;
		};

		int main(void)
		{
		    struct Student s1 = {
		        .name = "Le Van C",
		        .studentID = 2023003,
		        .gpa = 3.92
		    };

		    struct Student s2;
		    s2 = s1;                         // Phép gán cấu trúc

		    printf("Sinh vien: %s\n", s2.name);
		    printf("Ma so: %d\n", s2.studentID);
		    printf("GPA: %.2f\n", s2.gpa);

		    return 0;
		}

* **Lưu ý:**

	*  Phép gán cấu trúc chỉ hoạt động khi hai cấu trúc cùng kiểu.
	
	*   Nếu cấu trúc chứa con trỏ, phép gán chỉ sao chép địa chỉ (shallow copy), không sao chép vùng nhớ mà con trỏ trỏ tới.

	

### **II.  Tổ chức cấu trúc nâng cao**

#### **2.1. Cấu trúc lồng nhau (Nested Structures)**

* **Cú pháp:**

		struct Cấu_trúc_con {
		    // các thành viên của cấu trúc con
		};

		struct Cấu_trúc_cha {
		    // các thành viên thông thường
		    struct Cấu_trúc_con tên_thành_viên;   // Cấu trúc lồng nhau
		};

* **VD:**

		struct Date {
		    int day;
		    int month;
		    int year;
		};

		struct Employee {
		    char name[50];
		    int employeeID;
		    struct Date birthDate;      // Cấu trúc Date được lồng vào
		    struct Date joinDate;       // Cấu trúc Date được lồng vào
		};

		int main(void)
		{
		    struct Employee emp = {
		        .name = "Nguyen Van An",
		        .employeeID = 1001,
		        .birthDate = {15, 5, 1998},
		        .joinDate = {1, 3, 2023}
		    };

		    printf("Ngay sinh: %02d/%02d/%d\n", 
		           emp.birthDate.day, emp.birthDate.month, emp.birthDate.year);

		    return 0;
		}
					
#### **2.2. Mảng của cấu trúc (Array of Structures)**

* **Cú pháp:** 

		struct Tên_Cấu_trúc tên_mảng[số_lượng];

* **Minh họa:**

			struct Student {
			    char name[50];
			    int studentID;
			    float gpa;
			};

			int main(void)
			{
			    struct Student class[3] = {
			        {"Nguyen Van A", 2023001, 3.75},
			        {"Tran Thi B",   2023002, 3.68},
			        {"Le Van C",     2023003, 3.92}
			    };

			    // Truy xuất phần tử
			    for(int i = 0; i < 3; i++) {
			        printf("SV %d: %s - GPA: %.2f\n", 
			               class[i].studentID, class[i].name, class[i].gpa);
			    }

			    return 0;
			}
	
	
#### **2.3. Cấu trúc tự tham chiếu (Self-Referential Structures)**

* Cấu trúc tự tham chiếu là cấu trúc chứa ít nhất một thành viên là con trỏ trỏ đến chính kiểu cấu trúc của nó.

* **Cú pháp:**

		struct Node {
		    int data;
		    struct Node *next;      // Con trỏ tự tham chiếu
		};

	
* **VD:**

		struct Node {
		    int data;
		    struct Node *next;
		};

		int main(void)
		{
		    struct Node n1 = {10, NULL};
		    struct Node n2 = {20, NULL};
		    struct Node n3 = {30, NULL};

		    n1.next = &n2;
		    n2.next = &n3;

		    // Duyệt danh sách
		    struct Node *current = &n1;
		    while (current != NULL) {
		        printf("%d -> ", current->data);
		        current = current->next;
		    }
		    printf("NULL\n");

		    return 0;
		}

#### **2.4. Thành viên mảng linh hoạt**

* Flexible Array Member là tính năng được giới thiệu từ chuẩn C99, cho phép khai báo một mảng không xác định kích thước làm thành viên cuối cùng của cấu trúc.

* **Cú pháp:**

		struct Tên_Cấu_trúc {
		    // các thành viên thông thường
		    kiểu_dữ_liệu tên_mảng_linh_hoạt[];   // Phải là thành viên cuối cùng
		};

* **VD:**

			#include <stdio.h>
			#include <stdlib.h>

			struct DynamicArray {
			    int length;
			    int data[];        // Flexible Array Member
			};

			int main(void)
			{
			    int size = 5;
			    
			    // Cấp phát động một khối nhớ đủ lớn
			    struct DynamicArray *arr = malloc(sizeof(struct DynamicArray) + size * sizeof(int));
			    
			    arr->length = size;
			    for(int i = 0; i < size; i++) {
			        arr->data[i] = i * 10;
			    }

			    for(int i = 0; i < arr->length; i++) {
			        printf("%d ", arr->data[i]);
			    }
			    
			    free(arr);
			    return 0;
			}


### **III.  Bí danh kiểu dữ liệu (typedef)**

#### **3.1. Cơ chế**

##### **3.1.1. Khái niệm**

* `typedef` là từ khóa dùng để tạo bí danh (alias) cho một kiểu dữ liệu đã tồn tại.

* `typedef` không tạo ra kiểu dữ liệu mới, mà chỉ tạo ra một tên gọi khác cho kiểu dữ liệu đó.

##### **3.1.2. Cú pháp**


		typedef kiểu_dữ_liệu_gốc tên_mới;

##### **3.1.3. VD**

			typedef unsigned int uint;        // Bí danh cho unsigned int
			typedef float real;               // Bí danh cho float

			uint count = 100;
			real pi = 3.14159;
	

	
#### **3.2. Sử dụng typedef với cấu trúc**

* **Không dùng typedef:**

		struct Student {
		    char name[50];
		    int studentID;
		    float gpa;
		};

		struct Student s1;        // Phải viết "struct Student"

* **Dùng typedef:**

		typedef struct {
		    char name[50];
		    int studentID;
		    float gpa;
		} Student;                // Student giờ là tên kiểu dữ liệu

		Student s1, s2;           // Không cần viết "struct" nữa

* **Structure tag:**

		typedef struct Student {     // Student là structure tag
		    char name[50];
		    int studentID;
		    float gpa;
		} Student;                   // Student cũng là tên kiểu sau typedef

#### **3.3. Ứng dụng**

* Thay vì dùng trực tiếp các kiểu dữ liệu phụ thuộc vào kiến trúc máy (như `int`, `long`), ta dùng typedef để định nghĩa tên kiểu có kích thước cố định.

* Khi chuyển sang nền tảng mới, chỉ cần sửa định nghĩa `typedef` một lần.

* VD:

			// Định nghĩa các kiểu dữ liệu có kích thước cố định
			typedef signed char        int8_t;
			typedef unsigned char      uint8_t;
			typedef signed short       int16_t;
			typedef unsigned short     uint16_t;
			typedef signed int         int32_t;
			typedef unsigned int       uint32_t;
			typedef long long          int64_t;
			typedef unsigned long long uint64_t;



#### **3.4. Định nghĩa bí danh cho con trỏ hàm**

##### **3.4.1. Ví dụ không dùng typedef**

		void sort(int arr[], int n, int (*compare)(int, int));

##### **3.4.2. Ví dụ dùng typedef**

		// Định nghĩa bí danh cho con trỏ hàm
		typedef int (*CompareFunc)(int, int);

		void sort(int arr[], int n, CompareFunc compare);

##### **3.4.2. Ví dụ đầy đủ**

			#include <stdio.h>

			typedef int (*CompareFunc)(int a, int b);

			int ascending(int a, int b) {
			    return a - b;
			}

			int descending(int a, int b) {
			    return b - a;
			}

			void bubbleSort(int arr[], int n, CompareFunc compare)
			{
			    for(int i = 0; i < n-1; i++) {
			        for(int j = 0; j < n-i-1; j++) {
			            if (compare(arr[j], arr[j+1]) > 0) {
			                int temp = arr[j];
			                arr[j] = arr[j+1];
			                arr[j+1] = temp;
			            }
			        }
			    }
			}

			int main(void)
			{
			    int numbers[] = {64, 34, 25, 12, 22, 11, 90};
			    int n = sizeof(numbers)/sizeof(numbers[0]);

			    bubbleSort(numbers, n, ascending);

			    printf("Mang sau khi sap xep tang dan: ");
			    for(int i = 0; i < n; i++) {
			        printf("%d ", numbers[i]);
			    }

			    return 0;
			}




### **IV.  Union**

#### **4.1. Bản chất và sự khác biệt với cấu trúc**

* Về mặt cú pháp, union rất giống với struct, nhưng chúng hoàn toàn khác nhau về cách tổ chức bộ nhớ.


* **Cú pháp định nghĩa union::**
	
			union Tên_Hợp_thể {
			    kiểu_dữ_liệu thành_viên_1;
			    kiểu_dữ_liệu thành_viên_2;
			    // ... các thành viên khác
			};
	
* **So sánh:**

	| Tiêu chí                     | Structure (struct)                                   | Union (union)                                      |
	|-----------------------------|------------------------------------------------------|----------------------------------------------------|
	| Cấp phát bộ nhớ             | Cấp phát riêng cho từng thành viên                   | Chỉ cấp phát một khối nhớ đủ lớn nhất              |
	| Kích thước (sizeof)         | Tổng kích thước tất cả thành viên + padding          | Kích thước của thành viên lớn nhất                 |
	| Địa chỉ các thành viên      | Các thành viên nằm ở vị trí khác nhau                | Tất cả thành viên bắt đầu tại cùng một địa chỉ     |
	| Sử dụng đồng thời           | Có thể dùng nhiều thành viên cùng lúc                | Chỉ nên dùng một thành viên tại một thời điểm      |

* **VD:**
	
		union Data {
		    int i;          // 4 bytes
		    float f;        // 4 bytes
		    char str[8];    // 8 bytes
		};

		union Data var;

		printf("Kich thuoc cua union: %zu bytes\n", sizeof(var));   // Kết quả: 8 bytes
			
#### **4.2. Quy tắc sử dụng**

* Tại bất kỳ thời điểm nào, union chỉ nên lưu trữ và sử dụng giá trị của một thành viên duy nhất.

* Việc ghi dữ liệu vào một thành viên sẽ ghi đè (phá hủy) dữ liệu của các thành viên khác.

* VD:

			#include <stdio.h>

			union Data {
			    int i;
			    float f;
			};

			int main(void)
			{
			    union Data var;
			    
			    var.i = 42;
			    printf("Gia tri int: %d\n", var.i);
			    
			    var.f = 3.14;                    // Ghi đè lên vùng nhớ của int
			    printf("Gia tri float: %.2f\n", var.f);
			    printf("Gia tri int sau khi ghi float: %d\n", var.i);  // Kết quả không xác định
			    
			    return 0;
			}



### **V.  Trường bit (Bit-fields)**

#### **5.1. Định nghĩa và cú pháp trường bit**

* Trường bit được khai báo bên trong một cấu trúc (hoặc hợp thể) bằng cách thêm dấu hai chấm (`:`) và số bit sau tên thành viên.

* **Cú pháp:**

		struct Tên_Cấu_trúc {
		    kiểu_dữ_liệu tên_thành_viên : số_bit;
		};

* **VD:**

		struct Flags {
		    unsigned int isActive   : 1;   // 1 bit
		    unsigned int isAdmin    : 1;   // 1 bit
		    unsigned int priority   : 3;   // 3 bit (giá trị từ 0 đến 7)
		    unsigned int status     : 4;   // 4 bit (giá trị từ 0 đến 15)
		    unsigned int reserved   : 23;  // Phần còn lại
		};
			
* **Lưu ý:**

	*  Kiểu dữ liệu của trường bit thường là `unsigned int` hoặc `int`.
	
	*  Tổng số bit của tất cả các trường bit trong một cấu trúc không nên vượt quá kích thước của kiểu dữ liệu cơ bản (thường là 32 hoặc 64 bit).
	
	*  Trường bit phải được khai báo liên tiếp nhau để trình biên dịch có thể đóng gói chúng vào cùng một đơn vị lưu trữ (storage unit).  


		
	
#### **5.2. Giới hạn và hành vi**

* **Các giới hạn quan trọng:**

	*  Không thể lấy địa chỉ của một trường bit bằng toán tử `&` (vì trường bit thường không nằm trên ranh giới byte).

	*  Không thể sử dụng mảng của trường bit.

	*  Không thể sử dụng toán tử `sizeof` trực tiếp trên một trường bit riêng lẻ.

	*  Không hỗ trợ khởi tạo trực tiếp bằng designated initializers cho từng trường bit một cách đơn giản.

* **Hành vi phụ thuộc nền tảng:**

	*  Thứ tự cấp phát bit:
	
		*  Từ trái sang phải hay từ phải sang trái phụ thuộc vào compiler và kiến trúc CPU (little-endian hay big-endian).

	*  Cách đóng gói:
	
		*  Cách trình biên dịch nhóm các trường bit vào các đơn vị lưu trữ (storage unit) có thể khác nhau.

	*  Kích thước và căn chỉnh của cấu trúc chứa bit-field có thể thay đổi giữa các nền tảng.
		
* **VD:**

		struct Test {
		    unsigned int a : 1;
		    unsigned int b : 1;
		    unsigned int c : 30;
		};

		printf("Size = %zu bytes\n", sizeof(struct Test));   // Kết quả có thể là 4 hoặc 8 tùy compiler


### **VI.  Căn chỉnh bộ nhớ cấu trúc (Memory Alignment và Padding)**

#### **6.1. Khái niệm căn chỉnh bộ nhớ và đệm (Padding)**

* CPU không đọc và ghi dữ liệu từng byte một, mà thường đọc theo các khối có kích thước cố định gọi là word (thường là 4 byte hoặc 8 byte trên hệ thống 64-bit).

* Để tăng tốc độ truy xuất, trình biên dịch tự động sắp xếp các thành viên trong cấu trúc sao cho địa chỉ của mỗi thành viên nằm ở vị trí chia hết cho kích thước của chính nó.

* Quá trình trình biên dịch tự động chèn các byte rỗng (không chứa dữ liệu) giữa các thành viên được gọi là đệm (padding).

		struct Example {
		    char  a;      // 1 byte
		    int   b;      // 4 bytes
		    char  c;      // 1 byte
		};

		printf("Kich thuoc struct: %zu bytes\n", sizeof(struct Example));

	* Mặc dù tổng kích thước các thành viên chỉ là 1 + 4 + 1 = 6 byte, nhưng sizeof(struct Example) thường trả về 8 byte hoặc 12 byte do trình biên dịch chèn byte đệm để đảm bảo căn chỉnh.
	
	*  Sau thành viên a (char), trình biên dịch chèn 3 byte padding để b (int) nằm ở địa chỉ chia hết cho 4.
	
	*  Sau thành viên c, có thể chèn thêm padding để kích thước toàn bộ cấu trúc là bội số của thành viên lớn nhất (thường là 4 hoặc 8).

#### **6.2. Ảnh hưởng của thứ tự thành viên đến kích thước cấu trúc**

* Thứ tự khai báo các thành viên trong cấu trúc ảnh hưởng rất lớn đến lượng bộ nhớ bị lãng phí do padding.

* **VD:**
	
		// Cách khai báo kém tối ưu
		struct Bad {
		    char  a;   // 1 byte
		    int   b;   // 4 bytes
		    char  c;   // 1 byte
		};             // Kích thước thực tế thường là 12 bytes

		// Cách khai báo tối ưu hơn
		struct Good {
		    int   b;   // 4 bytes
		    char  a;   // 1 byte
		    char  c;   // 1 byte
		};             // Kích thước thực tế thường là 8 bytes
		
* **Nguyên tắc sắp xếp tối ưu bộ nhớ:**

	*  Sắp xếp các thành viên theo thứ tự kích thước giảm dần (từ lớn đến nhỏ).
	
	*  Đặt các thành viên có kích thước lớn (double, int64_t, int) trước.
	
	*  Đặt các thành viên nhỏ (char, bool, int8_t) sau cùng.   

#### **6.3. Kiểm soát căn chỉnh bộ nhớ**

* **Sử dụng #pragma pack:**

			#pragma pack(push, 1)     // Tắt padding, đóng gói sát nhau
			struct Packed {
			    char  a;
			    int   b;
			    char  c;
			};
			#pragma pack(pop)         // Khôi phục cài đặt căn chỉnh cũ

* **Sử dụng thuộc tính GCC/Clang (__attribute__((packed))):**

		struct __attribute__((packed)) PackedStruct {
		    char  a;
		    int   b;
		    char  c;
		};

* **Sử dụng _Alignas và _Alignof (Chuẩn C11):**

		#include <stdalign.h>

		struct Aligned {
		    char a;
		    _Alignas(8) int b;     // Buộc b được căn chỉnh theo 8 byte
		    char c;
		};

* **Lưu ý:**

	*  Việc tắt padding (`pack(1)`) làm tăng tốc độ truy xuất giảm, nhưng tiết kiệm bộ nhớ và phù hợp với giao thức mạng.
	
	*  Sử dụng `packed` có thể gây unaligned access, dẫn đến lỗi hoặc giảm hiệu năng trên một số kiến trúc CPU (đặc biệt ARM).
	
	*  Nên ưu tiên sắp xếp thành viên hợp lý trước khi dùng `#pragma pack` hoặc `packed` 
					 										
   </details> 


<details>
    <summary><strong>CHƯƠNG 10: CẤP PHÁT BỘ NHỚ ĐỘNG</strong></summary>


## **CHƯƠNG 10: CẤP PHÁT BỘ NHỚ ĐỘNG**

### **I. GIAO DIỆN CẤP PHÁT BỘ NHỚ CHUẨN**

#### **1.1.Hàm malloc (Memory Allocation)**

##### **1.1.1.Khái niệm**

*	Hàm malloc là hàm cơ bản nhất trong giao diện cấp phát bộ nhớ động (dynamic memory allocation) của thư viện chuẩn C, được khai báo trong header file `<stdlib.h>`

##### **1.1.2.Cú pháp**
 
			 void * malloc(size_t size);
			 
*  Tham số: 

	*	`size`: Kiểu dữ liệu `size_t` (thường là unsigned int hoặc unsigned long tùy theo hệ thống), biểu diễn số byte cần cấp phát liên tục (contiguous block) trong vùng nhớ heap.
  
		*	Nếu size bằng 0, hành vi của malloc là do triển khai định nghĩa (implementation-defined).
		
		*  Một số hệ thống trả về con trỏ không NULL (nhưng không được sử dụng để truy cập bộ nhớ), một số khác trả về NULL
	
*  Giá trị trả về: 

	* Thành công: 
	
		* Trả về một con trỏ void* trỏ đến vùng nhớ đã được cấp phát.
		
		* Vùng nhớ này là:
		
			* Thô
			
			* Chưa được khởi tạo, chứa giá trị rác 
			
			* Được căn chỉnh phù hợp để lưu bất kỳ kiểu dữ liệu nào      
	
	* Thất bại:   
	
		* Trả về NULL khi hệ thống không thể cấp phát đủ bộ nhớ yêu cầu (ví dụ: hết bộ nhớ heap, hoặc size quá lớn vượt quá giới hạn của hệ thống). 
  
##### **1.1.3.Đặc tính**
			 
*  Vùng nhớ nằm trong heap (vùng nhớ động).

* Bộ nhớ được cấp phát có thể lớn hơn `size` một chút do cơ chế quản lý bộ nhớ của C

* Vùng nhớ không được tự động khởi tạo về 0

	* Nếu cần vùng nhớ chứa giá trị 0, phải sử dụng hàm `calloc` hoặc gọi `memset` sau khi cấp phát bằng `malloc`   

*	Con trỏ trả về có thể được ép kiểu (cast) an toàn sang bất kỳ kiểu con trỏ nào

##### **1.1.4.Cách sử dụng chuẩn**
			 
		#include <stdlib.h>

		int *arr = (int*)malloc(10 * sizeof(int));
		if (arr == NULL) {
		    // Xử lý lỗi: thông báo, thoát chương trình hoặc phục hồi
		    fprintf(stderr, "Khong du bo nho de cap phat!\n");
		    exit(1);
		}

* Sử dụng sizeof(int) thay vì ghi cứng số byte (ví dụ: 40) để đảm bảo tính khả chuyển (portability) giữa các nền tảng (32-bit, 64-bit, các kiến trúc khác nhau).

* Ép kiểu (int*) là cần thiết trong C++ và là thói quen tốt trong C (dù C cho phép gán void* trực tiếp cho con trỏ khác mà không cần cast).

* Luôn kiểm tra con trỏ trả về trước khi sử dụng.

* Cách sử dụng cho nhiều kiểu dữ liệu khác nhau:
			
			double *dptr = (double*)malloc(n * sizeof(double));
			struct Student *students = (struct Student*)malloc(m * sizeof(struct Student));
			char *buffer = (char*)malloc(1024);           // cấp phát 1KB 

##### **1.1.5.Hành vi không xác định (Undefined Behavior) khi sử dụng sai**
			 
*  Truy cập vùng nhớ trước khi kiểm tra con trỏ `NULL`

*  Sử dụng vùng nhớ sau khi đã `free()`

*  Truy cập ngoài giới hạn vùng nhớ đã cấp phát (buffer overflow).

* Giải phóng hai lần (double free).

* Ép kiểu và sử dụng sai kích thước (ví dụ: cấp phát cho int nhưng lại truy cập như double). 

#### **1.2.Hàm calloc (Cleared Allocation)**

##### **1.2.1.Khái niệm**

*	Hàm calloc là hàm cấp phát bộ nhớ động có khởi tạo giá trị, được khai báo trong thư viện chuẩn `<stdlib.h>`

##### **1.2.2.Cú pháp**
 
			 void * calloc(size_t nmemb, size_t size);
			 
*  Tham số: 

	*  `nmemb`: Số lượng phần tử cần cấp phát

	*	`size`: Kích thước byte của mỗi phần tử
  
		*	Tổng số byte bộ nhớ được cấp phát là `nmemb * size`.
		
		*  Nếu nmemb hoặc size bằng 0, hành vi của hàm là implementation-defined (tương tự malloc).
		
		*  Thông thường, hàm sẽ trả về một con trỏ hợp lệ nhưng không được sử dụng để truy cập bộ nhớ, hoặc trả về NULL. 
	
*  Giá trị trả về: 

	* Thành công: 
	
		* Trả về con trỏ void* trỏ đến vùng nhớ đã được cấp phát liên tục trên heap
		
		* Vùng nhớ này là:
		
			* Được khởi tạo toàn bộ về 0 trên tất cả các bit (zero-initialized).
			
			* Được căn chỉnh phù hợp (suitably aligned) để lưu trữ bất kỳ kiểu dữ liệu nào.
	
	* Thất bại:   
	
		* Trả về NULL nếu không đủ bộ nhớ để cấp phát.
  
##### **1.2.3.Đặc tính**
			 
*  Khởi tạo về 0: 

	* Đây là điểm khác biệt quan trọng nhất so với malloc. 
	
	* Toàn bộ vùng nhớ được đặt tất cả các byte về giá trị 0x00.


##### **1.2.4.Cách sử dụng chuẩn**
			 
		#include <stdlib.h>

		int *arr = (int*)calloc(10, sizeof(int));
		if (arr == NULL) {
		    fprintf(stderr, "Khong du bo nho de cap phat!\n");
		    exit(1);
		}

* Cách sử dụng cho nhiều kiểu dữ liệu khác nhau:
			
		// Cấp phát mảng 100 số nguyên (đã khởi tạo = 0)
		int *numbers = (int*)calloc(100, sizeof(int));

		// Cấp phát mảng cấu trúc
		struct Student {
		    char name[50];
		    int age;
		    float gpa;
		};
		struct Student *class = (struct Student*)calloc(50, sizeof(struct Student));

		// Cấp phát chuỗi ký tự
		char *buffer = (char*)calloc(1024, sizeof(char));  // tương đương chuỗi rỗng

##### **1.2.5.Lưu ý**
			 
*  Luôn kiểm tra con trỏ trả về trước khi sử dụng.

*  Sử dụng `sizeof` để đảm bảo tính khả chuyển (portability) giữa các nền tảng.

*  Ép kiểu `(type*)` là khuyến nghị tốt.

*  Bộ nhớ phải được giải phóng bằng hàm `free()` khi không còn sử dụng.

* Ép kiểu và sử dụng sai kích thước (ví dụ: cấp phát cho int nhưng lại truy cập như double). 

#### **1.3.Hàm realloc (Re-allocation)**

##### **1.3.1.Khái niệm**

*	Hàm realloc là hàm cho phép thay đổi kích thước của một khối bộ nhớ đã được cấp phát động trước đó bằng malloc, calloc hoặc realloc.

##### **1.3.2.Cú pháp**
 
			 void* realloc(void* ptr, size_t size);
			 
*  Tham số: 

	*  `ptr`: 
	
		* Con trỏ trỏ đến khối bộ nhớ đã được cấp phát trước đó (thường là kết quả trả về của malloc, calloc hoặc realloc trước đó).
		
		* Nếu ptr là NULL, hàm realloc hoạt động tương đương với malloc(size). 

	*	`size`: Kích thước mới (theo byte) mà khối bộ nhớ cần thay đổi thành.
	
*  Giá trị trả về: 

	* Thành công: 
	
		* Trả về con trỏ void* trỏ đến khối bộ nhớ có kích thước mới.
		
		* Con trỏ này có thể giống hoặc khác với con trỏ ptr ban đầu.
	
	* Thất bại:   
	
		* Trả về NULL.
		
		* Khi thất bại, hàm không giải phóng khối bộ nhớ cũ.
		
		* Khối nhớ ban đầu vẫn còn nguyên vẹn và vẫn phải được giải phóng bằng `free()` sau này.  
  
##### **1.3.3.Các kịch bản hoạt động**
			 
*  Hàm realloc xử lý theo nhiều trường hợp tùy theo khả năng của hệ thống quản lý bộ nhớ:

	* Thu nhỏ kích thước:
	
		* Khối bộ nhớ được giữ nguyên vị trí.
		
		* Phần bộ nhớ thừa ở cuối khối sẽ bị cắt bỏ và giải phóng.
		
		* Nội dung phần dữ liệu còn lại được giữ nguyên 
		
		* Trả về cùng con trỏ cũ     


	* Mở rộng tại chỗ:
	
		* Nếu có đủ không gian trống liền kề phía sau khối bộ nhớ hiện tại, hệ thống sẽ mở rộng khối đó ngay lập tức
		
		* Không cần sao chép dữ liệu.
		
		* Trả về cùng con trỏ cũ.
		
		* Phần bộ nhớ mới được thêm vào chưa được khởi tạo (chứa giá trị rác).

	* Di chuyển đến vị trí mới (Move / Relocate):
	
		* Khi không thể mở rộng tại chỗ (không gian liền kề không đủ), realloc sẽ:
		
			* Cấp phát một khối bộ nhớ mới đủ lớn ở vị trí khác.
			
			* Sao chép toàn bộ nội dung của khối cũ sang khối mới (sao chép tối đa size byte).
			
			* Giải phóng khối bộ nhớ cũ.
			
			* Trả về con trỏ mới trỏ đến khối nhớ mới. 
		
##### **1.3.4.Cách sử dụng chuẩn**
			 
		#include <stdlib.h>

		int *arr = (int*)malloc(10 * sizeof(int));
		if (arr == NULL) { /* xử lý lỗi */ }

		// Mở rộng mảng từ 10 lên 20 phần tử
		int *new_arr = (int*)realloc(arr, 20 * sizeof(int));
		if (new_arr == NULL) {
		    // Thất bại → khối arr vẫn còn hiệu lực
		    fprintf(stderr, "Khong the cap phat them bo nho!\n");
		    free(arr);        // Phải tự giải phóng
		    exit(1);
		}

		// Cập nhật con trỏ
		arr = new_arr;

* Lưu ý khi gán lại con trỏ:
			
		// Cách an toàn
		int *temp = (int*)realloc(arr, new_size);
		if (temp != NULL) {
		    arr = temp;
		} else {
		    // Xử lý lỗi, arr vẫn hợp lệ
		}

##### **1.3.5.Lưu ý**
			 
*  Không được giải phóng con trỏ cũ nếu realloc trả về con trỏ , khối cũ đã được hàm tự động giải phóng 

*  Khi realloc thất bại, phải giữ nguyên con trỏ cũ và giải phóng sau.

*  Phần bộ nhớ mới khi mở rộng không được khởi tạo về 0. Nếu cần, phải dùng memset.

*  Truyền size = 0 vào realloc(ptr, 0) có hành vi tương đương free(ptr) trên một số hệ thống, nhưng không được khuyến khích. Nên dùng free() trực tiếp.

*  Luôn sử dụng sizeof để đảm bảo tính khả chuyển.

*  Ép kiểu (type*) là thói quen tốt.  

#### **1.4.Hàm free (De-allocation)**

##### **1.4.1.Khái niệm**

*	Hàm free là hàm giải phóng bộ nhớ động, đóng vai trò quan trọng cuối cùng trong chu trình quản lý bộ nhớ động của ngôn ngữ C

##### **1.4.2.Cú pháp**
 
			 void free(void* ptr);
			 
*  Tham số: 

	*  `ptr`: 
	
		* Con trỏ trỏ đến khối bộ nhớ cần giải phóng.
		
		* Đây phải là con trỏ đã được trả về trước đó bởi:
		
			* `malloc()`
			
			* `calloc()`
			
			* `realloc()`   

			*	Hoặc ptr có thể là NULL.

  
##### **1.4.3.Mục đích**
			 
*  Trả lại khối bộ nhớ đã cấp phát động cho Heap Manager (hệ thống quản lý bộ nhớ heap) của chương trình.

* Cho phép hệ thống tái sử dụng vùng nhớ đó cho các lần cấp phát sau, giúp tránh tình trạng rò rỉ bộ nhớ (memory leak).

		
##### **1.4.4.Ràng buộc khi sử dụng**

* Chỉ được phép truyền vào `free`:

	*  Con trỏ nhận trực tiếp từ `malloc, calloc, hoặc realloc`.
	
	*  Con trỏ `NULL` (gọi `free(NULL)` là an toàn tuyệt đối và hàm sẽ không làm gì cả). 
			 
* Tuyệt đối không được phép:

	*  Giải phóng con trỏ không được cấp phát bởi các hàm trên (con trỏ stack, con trỏ static, con trỏ hằng…).
	
	*  Giải phóng hai lần cùng một con trỏ (double free).
	
	*  Giải phóng con trỏ đã bị thay đổi (không còn trỏ đúng vào đầu khối nhớ)
	
	*  Giải phóng một phần của khối nhớ 
	
	*  Sử dụng con trỏ sau khi đã `free`  



##### **1.4.5.Cách sử dụng đúng**
			 
		#include <stdlib.h>

		int *arr = (int*)malloc(100 * sizeof(int));
		if (arr == NULL) { /* xử lý lỗi */ }

		// Sử dụng arr...

		free(arr);      // Giải phóng đúng
		arr = NULL;     // Khuyến nghị tốt: gán NULL sau khi free

* 	Với realloc (trường hợp đặc biệt):
		
		int *arr = (int*)malloc(10 * sizeof(int));

		// Mở rộng
		int *temp = (int*)realloc(arr, 50 * sizeof(int));
		if (temp != NULL) {
		    arr = temp;
		}

		// Khi kết thúc
		free(arr);
		arr = NULL;
	 

 		        
### **II.  QUẢN LÝ VÒNG ĐỜI KHỐI NHỚ**

####  **2.1. Vòng đời chuẩn: Allocate → Use → Free**

* Một khối bộ nhớ cấp phát hợp lệ phải tuân theo 3 giai đoạn:

	* **Alocate (Cấp phát):** Sử dụng `malloc`, `calloc`, `realloc` để xin cấp phát bộ nhớ từ heap
	
	* **Use (Sử dụng):** Truy cập, đọc.ghi dữ liệu vào vùng nhớ đã cấp phát
	
	* **Free (Giải phóng):** Trả bộ nhớ về cho hệ thống bằng hàm `free`   

			
* **Nguyên tắc sở hữu:**

	* Trong các dự án trung bình và lớn, cần xác định rõ ràng ai là chủ sở hữu của khối bộ nhớ.
	
		* Module/hàm nào cấp phát bộ nhớ thì module/hàm đó có trách nhiệm giải phóng nó, trừ khi chủ sở hữu được chuyển giao một cách rõ ràng (ví dụ: qua tài liệu hàm hoặc tham số đầu ra).
		
		* Nguyên tắc này giúp tránh tình trạng “ai cũng nghĩ người khác sẽ free”, dẫn đến memory leak hoặc double free. 

				// Hàm này sở hữu bộ nhớ và phải chịu trách nhiệm free
				char* create_message(const char* text) {
				    char* msg = (char*)malloc(strlen(text) + 1);
				    if (msg == NULL) return NULL;
				    strcpy(msg, text);
				    return msg;        // Chuyển giao quyền sở hữu cho hàm gọi
				}



####  **2.2. Kiểm tra giá trị trả về bắt buộc**

* Mọi lời gọi hàm cấp phát bộ nhớ (`malloc, calloc,realloc`) phải được kiểm tra ngay kết quả trả về.

* Không kiểm tra là nguyên nhân hàng đầu gây ra segmentation fault hoặc crash chương trình.
	 
		int *arr = (int*)malloc(n * sizeof(int));
		if (arr == NULL) {
		    // Xử lý lỗi một cách graceful
		    fprintf(stderr, "Loi cap phat bo nho: khong du RAM!\n");
		    // Có thể: exit(1), return error_code, hoặc rollback các thao tác trước đó
		    return NULL;   // hoặc xử lý phù hợp theo ngữ cảnh
		}

* Với realloc:

		int *temp = (int*)realloc(arr, new_size * sizeof(int));
		if (temp == NULL) {
		    // arr vẫn hợp lệ, không được mất con trỏ cũ
		    free(arr);
		    return NULL;
		}
		arr = temp;   // chỉ gán khi thành công

####  **2.3. Nguyên tắc đối xứng**

* Mỗi lần cấp phát thành công phải tương ứng với đúng một lần giải phóng.

	* Một lời gọi malloc/calloc thành công → phải có đúng một lời gọi free
	
	* Một lời gọi realloc thành công (kể cả khi di chuyển khối nhớ) cũng tuân theo nguyên tắc này.
	
	* Không được free nhiều lần (double free) và không được quên free (memory leak).
	
* tổng bộ nhớ cấp phát = tổng bộ nhớ được giải phóng khi chương trình kết thúc (không leak).    



####  **2.4. Set to NULL after Free**

* Biến Dangling Pointer (con trỏ treo – con trỏ vẫn giữ địa chỉ cũ nhưng bộ nhớ đã được trả lại) thành con trỏ NULL an toàn.

* Nếu vô tình sử dụng lại con trỏ sau khi free, chương trình sẽ crash rõ ràng (NULL pointer dereference) thay vì hành vi không xác định (undefined behavior) khó debug.
	
* Dễ dàng kiểm tra: if (ptr != NULL) trước khi sử dụng hoặc free lại.

		void cleanup(struct Data* d) {
		    if (d->buffer) {
		        free(d->buffer);
		        d->buffer = NULL;     // An toàn
		    }
		    if (d->names) {
		        free(d->names);
		        d->names = NULL;
		    }
		}

### **III. RISKS**

####  **3.1. Memory Leaks**

* Rò rỉ bộ nhớ xảy ra khi một khối bộ nhớ đã được cấp phát động nhưng không bao giờ được giải phóng bằng free(), dẫn đến bộ nhớ bị “bỏ hoang” cho đến khi chương trình kết thúc.

* **Nguyên nhân:**

	* Mất con trỏ duy nhất trỏ đến khối nhớ (con trỏ bị ghi đè, đi ra khỏi phạm vi, hoặc gán giá trị khác).
	
	* Quên gọi free() trong các nhánh xử lý lỗi hoặc đường thoát sớm của hàm.
	
	* Trong vòng lặp hoặc hàm được gọi lặp lại nhiều lần.
	
	* Không giải phóng bộ nhớ trong các cấu trúc dữ liệu phức tạp (danh sách liên kết, cây, đồ thị…).  
					
			void process_data(int n) {
			    int *data = (int*)malloc(n * sizeof(int));
			    if (data == NULL) return;   // Quên free khi cấp phát thất bại ở các chỗ khác
			    // ... xử lý dữ liệu
			    // Quên free(data);
			}
	
####  **3.2. Dangling Pointers**

* Con trỏ vẫn giữ địa chỉ của một vùng nhớ đã được giải phóng bằng `free()`.

* **Nguyên nhân:**

	* Sử dụng con trỏ sau khi đã gọi free().
	
	* Trả về địa chỉ của biến cục bộ (stack) từ hàm.
		
	* Hai con trỏ cùng trỏ vào một khối nhớ, một con được `free()` nhưng con kia vẫn được sử dụng.

				
			int *ptr = (int*)malloc(sizeof(int));
			*ptr = 100;
			free(ptr);

			// Con trỏ lơ lửng
			*ptr = 200;        // Undefined Behavior!
			printf("%d\n", *ptr); 
		

####  **3.3. Double Free**

* Gọi hàm `free()` hai lần (hoặc nhiều lần) trên cùng một con trỏ hợp lệ.

* Nguyên nhân:

	* Logic xử lý lỗi phức tạp dẫn đến free() được gọi ở nhiều nhánh.
	
	* Không gán NULL sau khi free, sau đó kiểm tra và free lại.
	
	* Hai hàm cùng giải phóng cùng một khối nhớ do nhầm lẫn về quyền sở hữu.

* Hậu quả:

	* Phá hủy cấu trúc quản lý nội bộ của Heap Manager.
	
	* Tạo ra lỗ hổng bảo mật nghiêm trọng (có thể bị khai thác để thực thi mã độc).
	
			char *buf = (char*)malloc(100);
			// ... sử dụng
			free(buf);
			// ... một số logic
			free(buf);   // Double Free → Undefined Behavior
		


####  **3.4. Tràn bộ đệm Heap**

* Ghi dữ liệu vượt quá giới hạn kích thước của khối bộ nhớ đã được cấp phát trên heap.

* Nguyên nhân:

	* Sử dụng sai chỉ số mảng (arr[i] khi i vượt quá kích thước).
	
	* Sao chép chuỗi bằng strcpy mà không kiểm tra độ dài.
	
	* Hàm memcpy, memmove, sprintf không an toàn.

* Hậu quả:

	* Ghi đè lên metadata quản lý heap (kích thước khối, con trỏ next/prev…).
	
	* Gây hỏng các khối nhớ liền kề.
	
	* Dẫn đến double free, dangling pointer, hoặc ghi đè lên dữ liệu quan trọng.
	
			char *buf = (char*)malloc(16);
			strcpy(buf, "This is a very long string");  // Tràn bộ đệm

### **IV. CÔNG CỤ**

####  **4.1. Dynamic Analysis với Valgrind**

* Valgrind thực thi chương trình trên một CPU ảo (virtual CPU), mô phỏng và theo dõi từng byte bộ nhớ và từng thao tác truy cập bộ nhớ của chương trình.

* Nhờ đó, nó có thể phát hiện lỗi thời gian chạy một cách chính xác mà không cần biên dịch lại chương trình.

* Công cụ: `Memcheck` dùng để phát hiện

	* Rò rỉ bộ nhớ (Memory Leaks) 

	* Đọc/ghi bộ nhớ không hợp lệ (Invalid read/write)
	
	* Lỗi giải phóng bộ nhớ (double free, invalid free, mismatched alloc/free)
	
			valgrind --leak-check=full --show-leak-kinds=all ./program
			valgrind --tool=memcheck --track-origins=yes ./program   

####  **4.2. Sanitizers của trình biên dịch**

* Sanitizers là bộ công cụ được tích hợp sẵn trong GCC và Clang, hoạt động dựa trên kỹ thuật chèn mã kiểm tra (instrumentation) vào chương trình ngay tại thời điểm biên dịch.

	* AddressSanitizer (ASan): 
	
		* Phát hiện lỗi truy cập bộ nhớ 
		
		* Out-of-bounds, use-after-free, stack overflow, heap buffer overflow  
	

	* LeakSanitizer (LSan): 
	
		* Phát hiện rò rỉ bộ nhớ
		
		* Memory leaks (tự động báo cáo khi chương trình kết thúc)


	* MemorySanitizer (MSan): 
	
		* Phát hiện sử dụng dữ liệu chưa khởi tạo
		
		* Use of uninitialized memory
	

	* UndefinedBehaviorSanitizer (UBSan): 
	
		* Phát hiện hành vi không xác định
		
		* Integer overflow, null dereference, v.v.
			
* **Cách biên dịch với Sanitizers:**

		# ASan + LSan
		gcc -fsanitize=address -g -O1 program.c -o program

		# Kết hợp nhiều sanitizer
		clang -fsanitize=address,leak,undefined -g -O1 program.c -o program

####  **4.3. Custom Allocators / Debug Allocators**

* Đây là kỹ thuật tự triển khai các hàm bao bọc (wrapper) xung quanh malloc/free nhằm mục đích gỡ lỗi.

	* Mục đích:
	
		* Ghi log thông tin cấp phát (tên file, số dòng, hàm gọi) 
		
		* Thêm vùng đệm bảo vệ (guard bands) trước và sau khối nhớ để phát hiện tràn bộ đệm
		
		*  Theo dõi danh sách các khối nhớ đang được cấp phát
		
		* Phát hiện doublle free và memory leak tự động khi chương trình kết thúc   
		
	* VD:

			void* debug_malloc(size_t size, const char* file, int line) {
			    void* ptr = malloc(size + GUARD_SIZE*2);
			    // Thêm canary, ghi log vào allocation map...
			    return ptr + GUARD_SIZE;
			}

			#define malloc(size) debug_malloc(size, __FILE__, __LINE__) 

####  **4.4. Static Analysis**

* Phân tích tĩnh kiểm tra mã nguồn mà không cần chạy chương trình.

	* Công cụ phổ biến:
	
		* clang-tidy
		
		* Cppcheck
		
		* Coverity, CodeSonar, PVS-Studio
		
		* Compiler : `-Wall -Wextra -Wpedantic`
		
	* Khả năng phát hiện:
	
		* Con trỏ có khả năng bị rò rỉ
		
		* Free không tương ứng với malloc
		
		* Mismatched allocation/deallocation.    

	* Cách sử dụng:
	
			cppcheck --enable=all .
			clang-tidy main.c -- -I.
						
   </details> 


<details>
    <summary><strong>CHƯƠNG 11: BỐ CỤC BỘ NHỚ TIẾN TRÌNH</strong></summary>

## **CHƯƠNG 11: BỐ CỤC BỘ NHỚ TIẾN TRÌNH**

### **I.  Tổng quan về không gian địa chỉ ảo**

#### **1.1. Không gian địa chỉ ảo (Virtual Address Space)**

##### **1.1.1. Khái niệm**

* Mỗi tiến trình (process) khi được hệ điều hành nạp vào RAM đều được cấp một không gian địa chỉ ảo riêng biệt.

* Đây là không gian bộ nhớ tuyến tính, liền mạch về mặt logic mà lập trình viên và chương trình có thể nhìn thấy.

##### **1.1.2. Đặc điểm**

* **Độc lập giữa các tiến trình:**

	*  Mỗi tiến trình có không gian địa chỉ ảo riêng, không thể trực tiếp truy cập bộ nhớ của tiến trình khác.

* **Kích thước lớn:**

	*  **Hệ 32-bit:** 4 GB (từ địa chỉ 0 đến 0xFFFFFFFF)
	
	*	**Hệ 64-bit:** Hàng terabyte (thực tế thường giới hạn ở mức vài trăm GB hoặc vài TB tùy hệ điều hành)
	
* **Ánh xạ bởi MMU:**

	*  Không gian địa chỉ ảo được đơn vị quản lý bộ nhớ (Memory Management Unit) của CPU ánh xạ lên bộ nhớ vật lý (RAM) và có thể ánh xạ lên file trên đĩa (swap space).

#### **1.2. Các phân vùng bộ nhớ logic của tiến trình**

* Bộ nhớ của một tiến trình được tổ chức thành nhiều phân vùng (segments) có chức năng, quyền truy cập và đặc tính khác nhau.

		Địa chỉ thấp
		+-------------------+
		|   Text Segment    |  ← Mã lệnh (chỉ đọc, thực thi được)
		+-------------------+
		|   .data Segment   |  ← Dữ liệu khởi tạo (đọc-ghi)
		+-------------------+
		|   .bss Segment    |  ← Dữ liệu chưa khởi tạo (đọc-ghi)
		+-------------------+
		|       Heap        |  ← Cấp phát động (tăng dần lên)
		|       ↑           |
		|                   |
		|       ↓           |
		|      Stack        |  ← Ngăn xếp (giảm dần xuống)
		+-------------------+
		Địa chỉ cao

	* **Text Segment (Code Segment):**
	
		*  Chứa mã máy nhị phân (machine code) của chương trình đã được biên dịch.
		
		*  Thuộc tính: **Chỉ đọc (Read-only)** và **có thể thực thi (Executable)**.

		*  Mọi cố gắng ghi dữ liệu vào vùng này sẽ gây ra Segmentation Fault.
		
		*  Thường được chia sẻ giữa các tiến trình chạy cùng chương trình để tiết kiệm bộ nhớ.

	* **.data Segment (Initialized Data Segment):**
	
		*  Chứa các biến toàn cục (global) và biến tĩnh (static) được khởi tạo với giá trị khác 0
		
		*  Thuộc tính: Đọc-ghi (Read-Write).

		*  Kích thước được xác định tại thời điểm biên dịch và được lưu trữ trong file thực thi.

	* **.bss Segment (Uninitialized Data Segment):**
	
		*  Chứa các biến toàn cục và biến tĩnh chưa được khởi tạo hoặc được khởi tạo bằng 0.
		
		*  Hệ điều hành chỉ lưu kích thước của vùng này trong file thực thi, không lưu các giá trị 0.

		*  Khi chương trình chạy, kernel sẽ tự động cấp phát và khởi tạo toàn bộ vùng về 0.

	* **Heap Segment:**
	
		*  Vùng bộ nhớ dùng cho cấp phát động (`malloc`, `calloc`, `realloc`, `free`).
		
		*  Thuộc tính: Đọc-ghi, kích thước linh hoạt.

		*  Vùng Heap phát triển từ địa chỉ thấp lên cao (tăng dần).

	* **Stack Segment:**
	
		*  Vùng bộ nhớ quản lý biến cục bộ, tham số hàm, địa chỉ trả về và thông tin điều khiển hàm.
		
		*  Hoạt động theo cơ chế LIFO (Last-In, First-Out).

		*  Vùng Stack phát triển từ địa chỉ cao xuống thấp (giảm dần).
		
		* Kích thước thường bị giới hạn (mặc định vài MB đến vài chục MB).  
					



### **II.  Các phân vùng bộ nhớ chính**

#### **2.1. Phân vùng mã lệnh (Text Segment)**

* Phân vùng mã lệnh (hay còn gọi là Code Segment) chứa toàn bộ mã máy nhị phân đã được biên dịch từ chương trình.

* **Đặc điểm:** 

	* Chứa các lệnh máy (machine instructions) của hàm `main()` và tất cả các hàm khác.

	*  Có thuộc tính chỉ đọc và có thể thực thi (Read-only + Executable).

	*  Không cho phép ghi dữ liệu vào vùng này.
	
	*  Thường được chia sẻ (shared) giữa các tiến trình chạy cùng một chương trình để tiết kiệm bộ nhớ vật lý. 


* **VD:**

			void myFunction() {
			    // Mã của hàm này nằm trong Text Segment
			}

			int main(void) {
			    // Cố tình ghi vào vùng mã lệnh → Segmentation Fault
			    // char *p = (char*)main;
			    // p[0] = 0x90;        // Sai
			    return 0;
			}
					
#### **2.2. Phân vùng dữ liệu khởi tạo (.data Segment)**

* Phân vùng `.data` chứa các biến toàn cục và biến tĩnh được khởi tạo với giá trị khác không.

* **Đặc điểm:**

	* Chứa biến `global` và `static` có giá trị khởi tạo ban đầu khác 0. 

	* Có thuộc tính đọc-ghi (Read-Write).

	* Kích thước của phân vùng này được xác định tại thời điểm biên dịch và được lưu trữ trực tiếp trong file thực thi (.exe hoặc ELF).

	* Nội dung của vùng này được nạp từ file thực thi vào bộ nhớ khi chương trình khởi chạy.

* **VD:**

			int globalVar = 100;                    // Nằm trong .data
			static int staticVar = 500;             // Nằm trong .data

			int main(void) {
			    // globalVar và staticVar được khởi tạo giá trị trước khi main() chạy
			    return 0;
			}


	
#### **2.3. Phân vùng dữ liệu chưa khởi tạo (.bss Segment)**

* Phân vùng `.bss` (Block Started by Symbol) chứa các biến toàn cục và biến tĩnh chưa được khởi tạo hoặc được khởi tạo bằng 0.

	* Hệ điều hành chỉ lưu kích thước của vùng này trong file thực thi, không lưu các giá trị 0.
	
	*  Khi chương trình được nạp, kernel sẽ tự động cấp phát bộ nhớ và khởi tạo toàn bộ vùng `.bss` về 0.
	
	*  Giúp giảm đáng kể kích thước file thực thi so với việc lưu đầy đủ giá trị 0.

* **VD:**

			int globalUninit;                       // Nằm trong .bss
			static int staticUninit = 0;            // Nằm trong .bss
			static int staticZero = 0;              // Cũng nằm trong .bss

			int main(void) {
			    // globalUninit và staticUninit đều có giá trị 0 khi chương trình chạy
			    printf("%d\n", globalUninit);       // In ra 0
			    return 0;
			}

#### **2.4. Phân vùng ngăn xếp (Stack Segment)**

* Phân vùng ngăn xếp dùng để quản lý các dữ liệu có thời gian sống ngắn, liên quan đến việc gọi hàm.

	* Chứa biến cục bộ (`auto`), tham số hàm và thông tin điều khiển (địa chỉ trả về, frame pointer…).
	
	*  Hoạt động theo cơ chế LIFO (Last-In, First-Out).
	
	*  Bộ nhớ được cấp phát và thu hồi tự động bởi CPU khi hàm được gọi và kết thúc.
	
	*  Phát triển từ địa chỉ cao xuống thấp (giảm dần).
	
	*  Kích thước thường bị giới hạn (mặc định từ vài MB đến vài chục MB tùy hệ điều hành).   

#### **2.5. Phân vùng cấp phát động (Heap Segment)**

* Phân vùng Heap là vùng bộ nhớ dành cho việc cấp phát động do lập trình viên yêu cầu.

	* Được sử dụng bởi các hàm `malloc()`, `calloc()`, `realloc()`, `free()`.
	
	*  Kích thước linh hoạt, có thể tăng trưởng trong quá trình chạy chương trình.
	
	*  Phát triển từ địa chỉ thấp lên cao (tăng dần), ngược chiều với Stack.
	
	*  Được quản lý thủ công bởi lập trình viên.
	
	*  Kích thước lớn nhất trong các phân vùng (có thể lên đến hàng GB tùy hệ thống).


### **III.  Stack Frame**

#### **3.1. Cơ chế gọi hàm và xây dựng khung ngăn xếp**

##### **3.1.1. Khái niệm**

* Khi một hàm được gọi, CPU và trình biên dịch phối hợp tạo ra một khung ngăn xếp mới trên Stack. 

* Quá trình này tuân theo cơ chế LIFO (Last-In, First-Out).

##### **3.1.2. Quá trình xây dựng khung ngăn xếp**

* **Push tham số hàm** (nếu có) vào Stack.

*  **Push địa chỉ trả về (Return Address)** – vị trí lệnh tiếp theo sau khi hàm kết thúc.

*  **Push Frame Pointer cũ (nếu sử dụng FP)** để lưu lại khung của hàm gọi.

* Cập nhật Frame Pointer mới cho khung hiện tại.

* Cấp phát không gian cho biến cục bộ của hàm.

*  Thực thi thân hàm.

##### **3.1.3. Khi hàm kết thúc (gặp lệnh return)**

* Giải phóng không gian biến cục bộ.

* Khôi phục Frame Pointer cũ.

* Pop địa chỉ trả về và nhảy về hàm gọi.

* Giải phóng tham số (thường do hàm gọi thực hiện).     

##### **3.1.4. VD**

		void funcB(int x) {
		    int local = x * 2;     // Biến cục bộ nằm trong Stack Frame của funcB
		    // ...
		}

		void funcA() {
		    int a = 10;
		    funcB(a);              // Khi gọi funcB, một Stack Frame mới được tạo
		}

		int main(void) {
		    funcA();               // main → funcA → funcB
		    return 0;
		}

#### **3.2. Con trỏ ngăn xếp (SP) và con trỏ khung (FP/BP)**

* **Stack Pointer (SP):**

	*  Luôn trỏ đến đỉnh (top) của Stack hiện tại.
	
	*  Khi đẩy dữ liệu vào (push), SP giảm (trên hầu hết kiến trúc).
	
	*  Khi lấy dữ liệu ra (pop), SP tăng.
	
	*  SP thay đổi liên tục trong quá trình thực thi hàm.   

* **Frame Pointer / Base Pointer (FP hoặc BP):**

	*  Trỏ đến một vị trí cố định trong khung ngăn xếp hiện tại (thường là đáy của khung).
	
	*  Đóng vai trò là mốc tham chiếu ổn định để truy xuất tham số hàm và biến cục bộ.
	
	*  Giúp trình biên dịch sinh ra mã dễ dàng hơn khi truy cập biến, vì khoảng cách từ FP đến biến là cố định.  

* **Sơ đồ Stack Frame điển hình:**

		Địa chỉ cao
		+-------------------------+  ← Frame Pointer (FP) cũ của hàm gọi
		|   Saved FP (Base Pointer)|
		+-------------------------+
		|   Return Address        |
		+-------------------------+
		|   Tham số hàm           |  ← Các tham số được đẩy vào
		+-------------------------+
		|   Biến cục bộ           |  ← Không gian cho biến local
		|   (local variables)     |
		+-------------------------+  ← Stack Pointer (SP) hiện tại
		Địa chỉ thấp
		




### **IV.  Quản trị phân vùng Heap**

#### **4.1. Trình quản lý bộ nhớ Heap (Memory Allocator)**

* Trình quản lý bộ nhớ Heap (thường gọi là Memory Allocator) là một thành phần nằm trong thư viện C chuẩn (libc) chịu trách nhiệm quản lý toàn bộ vùng Heap.

* **Vai trò:**

	*  Theo dõi các khối bộ nhớ đang trống và đã được cấp phát.

	*  Tìm và cấp phát khối bộ nhớ phù hợp khi gọi `malloc()` hoặc `calloc()`.
	
	*  Giải phóng khối bộ nhớ khi gọi `free()` và cập nhật danh sách khối trống.
	
	*  Thực hiện hợp nhất (coalescing) các khối trống liền kề để giảm phân mảnh. 
	
* **Cấu trúc dữ liệu nội bộ phổ biến:**

	*  **Free Lists:** Danh sách liên kết các khối nhớ trống.

	*  **Boundary Tags:** Mỗi khối nhớ có metadata (kích thước, trạng thái đã cấp phát hay trống) ở đầu và cuối khối.
	
	* **Bins:** Nhiều danh sách riêng biệt theo kích thước khối (small bins, large bins…) để tăng tốc độ tìm kiếm.  


* **Quy trình cấp phát điển hình:**

	* Tìm khối trống đủ lớn trong Free List.
	
	*  Nếu tìm thấy → cắt khối nếu cần và trả về phần phù hợp cho người dùng.
	
	*  Nếu không tìm thấy → yêu cầu hệ điều hành cấp thêm bộ nhớ (qua brk() hoặc mmap() trên Linux).
	
	*  Trả về con trỏ đến vùng nhớ (sau khi đã trừ đi phần metadata).     
	

			
#### **4.2. Hiện tượng phân mảnh bộ nhớ (Memory Fragmentation)**

##### **4.2.1. Phân mảnh ngoài (External Fragmentation)**

* Xảy ra khi tổng dung lượng bộ nhớ trống đủ lớn, nhưng các khối trống bị rời rạc, không có khối liền mạch nào đủ lớn để đáp ứng yêu cầu cấp phát mới.

* Nguyên nhân: Việc cấp phát và giải phóng xen kẽ với nhiều kích thước khác nhau trong thời gian dài.

* **Minh họa:**

		[ Đã cấp phát ] [ Trống 8KB ] [ Đã cấp phát ] [ Trống 16KB ] [ Đã cấp phát ]
		→ Tổng trống = 24KB, nhưng không thể cấp phát một khối 20KB 

##### **4.2.2. Phân mảnh trong (Internal Fragmentation)**

* Xảy ra khi trình quản lý cấp phát một khối nhớ lớn hơn so với yêu cầu thực tế của chương trình.

* Nguyên nhân phổ biến: Làm tròn kích thước lên bội số của 8 hoặc 16 byte để dễ quản lý và căn chỉnh.

* **VD:**

	*  Yêu cầu cấp phát 30 byte → allocator trả về khối 32 byte hoặc 64 byte → 2 hoặc 34 byte bị lãng phí bên trong khối.

##### **4.2.3. Kỹ thuật giảm thiểu phân mảnh bộ nhớ**

* **Memory Pools / Object Pools**

	*  Cấp phát trước một khối bộ nhớ lớn.
	
	*  Chia nhỏ khối đó thành nhiều đối tượng có kích thước cố định.
	
	*   Rất hiệu quả khi chương trình tạo/hủy một loại đối tượng thường xuyên (ví dụ: node của danh sách liên kết, packet mạng…). 

* **Slab Allocation**

	*  Kỹ thuật nâng cao được sử dụng trong kernel Linux.
	
	*  Tạo các Slab (khối lớn) chứa nhiều đối tượng cùng kích thước.
	
	*   Khi một đối tượng được giải phóng, nó được đưa trở lại Slab thay vì đưa vào Free List chung.

* **Custom Allocators**

	*  Viết trình cấp phát riêng phù hợp với đặc thù của ứng dụng.
	
	*  VD:
	
		*   **Arena Allocator:** Cấp phát từ một vùng nhớ lớn, chỉ giải phóng toàn bộ arena một lần.
		
		*   **Region Allocator:** Phân vùng Heap thành nhiều vùng nhỏ, mỗi vùng phục vụ một mục đích cụ thể.
		
		*   **Bump Allocator:** Cấp phát cực nhanh bằng cách chỉ di chuyển một con trỏ (thường dùng trong compiler hoặc game engine).

					 										
   </details> 




<details>
    <summary><strong>CHƯƠNG 12: CON TRỎ NÂNG CAO</strong></summary>

## **CHƯƠNG 12: CON TRỎ NÂNG CAO**

### **I.  Con trỏ đa cấp (Multiple Indirection)**

#### **1.1. Khái niệm và cú pháp con trỏ đa cấp**

##### **1.1.1. Khái niệm**

* Con trỏ đa cấp (multiple indirection) là con trỏ trỏ đến một con trỏ khác. 

* Mỗi lần thêm một dấu `*` sẽ tăng thêm một mức gián tiếp.

##### **1.1.2. Cú pháp**

		kiểu_dữ_liệu **tên_con_trỏ;     // Con trỏ cấp 2
		kiểu_dữ_liệu ***tên_con_trỏ;    // Con trỏ cấp 3

##### **1.1.3. Ví dụ**

		int value = 100;

		int  *p1 = &value;      // Con trỏ cấp 1: trỏ đến value
		int **p2 = &p1;         // Con trỏ cấp 2: trỏ đến p1
		int ***p3 = &p2;        // Con trỏ cấp 3: trỏ đến p2

##### **1.1.4. Giải tham chiếu**

* Mỗi dấu `*` sẽ bóc một lớp con trỏ:

		printf("%d\n", value);      // 100
		printf("%d\n", *p1);        // 100
		printf("%d\n", **p2);       // 100
		printf("%d\n", ***p3);      // 100

		***p3 = 999;                // Thay đổi giá trị gốc qua con trỏ cấp 3
		printf("%d\n", value);      // Kết quả: 999
				
#### **1.2. Ứng dụng**

##### **1.2.1. Sửa đổi con trỏ trong hàm (Output Pointers)**


* Do ngôn ngữ C truyền tham số theo cơ chế pass-by-value, hàm không thể thay đổi giá trị của con trỏ gốc nếu chỉ truyền con trỏ cấp một.

* Để hàm có thể thay đổi con trỏ của hàm gọi, ta phải truyền địa chỉ của con trỏ đó vào, biến tham số hàm thành con trỏ cấp hai. 

* **VD:**

		#include <stdio.h>
		#include <stdlib.h>

		// Hàm cấp phát mảng động và trả về qua tham số
		void allocateArray(int **arr, int size)
		{
		    *arr = (int*)malloc(size * sizeof(int));
		    if (*arr == NULL) {
		        printf("Cap phat bo nho that bai!\n");
		        return;
		    }
		    
		    // Khởi tạo dữ liệu
		    for(int i = 0; i < size; i++) {
		        (*arr)[i] = i * 10;
		    }
		}

		int main(void)
		{
		    int *myArray = NULL;                    // Con trỏ ban đầu là NULL
		    
		    allocateArray(&myArray, 5);             // Truyền địa chỉ của myArray
		    
		    // Kiểm tra kết quả
		    for(int i = 0; i < 5; i++) {
		        printf("%d ", myArray[i]);
		    }
		    
		    free(myArray);                          // Giải phóng bộ nhớ
		    myArray = NULL;
		    
		    return 0;
		}

##### **1.2.2. Cấp phát mảng hai chiều động và mảng răng cưa**


* Con trỏ đa cấp cho phép tạo mảng hai chiều động một cách linh hoạt, đặc biệt là mảng răng cưa (jagged array) – nơi mỗi hàng có thể có số cột khác nhau.

* Cấu trúc bộ nhớ:

	* `matrix`  là con trỏ cấp hai: trỏ đến một mảng các con trỏ cấp một.
	
	* Mỗi `matrix[i]` là một con trỏ cấp một trỏ đến một hàng. 

* **VD:**

		#include <stdio.h>
		#include <stdlib.h>

		int main(void)
		{
		    int rows = 4;
		    int *cols = (int[]){3, 5, 2, 4};        // Số cột của từng hàng
		    
		    // Cấp phát mảng con trỏ (mảng các hàng)
		    int **matrix = (int**)malloc(rows * sizeof(int*));
		    
		    // Cấp phát từng hàng riêng lẻ
		    for(int i = 0; i < rows; i++) {
		        matrix[i] = (int*)malloc(cols[i] * sizeof(int));
		        
		        // Gán giá trị
		        for(int j = 0; j < cols[i]; j++) {
		            matrix[i][j] = i * 10 + j;
		        }
		    }
		    
		    // In mảng răng cưa
		    for(int i = 0; i < rows; i++) {
		        for(int j = 0; j < cols[i]; j++) {
		            printf("%3d ", matrix[i][j]);
		        }
		        printf("\n");
		    }
		    
		    // Giải phóng bộ nhớ (phải theo thứ tự ngược)
		    for(int i = 0; i < rows; i++) {
		        free(matrix[i]);
		    }
		    free(matrix);
		    
		    return 0;
		}


### **II.  Con trỏ hàm (Function Pointers)**

#### **2.1. Bản chất và cú pháp khai báo con trỏ hàm**

* Con trỏ hàm là một biến lưu trữ địa chỉ của vùng nhớ chứa mã máy (machine code) của một hàm. Nói cách khác, nó trỏ đến hàm thay vì trỏ đến dữ liệu.

* **Cú pháp:** 

		kiểu_trả_về (*tên_con_trỏ_hàm)(danh_sách_tham_số);


* **VD1:**

		int (*funcPtr1)(int, int);           // Con trỏ hàm nhận 2 int, trả về int
		void (*funcPtr2)(const char*);       // Con trỏ hàm nhận chuỗi, không trả về
		double (*funcPtr3)(double);          // Con trỏ hàm nhận double, trả về double

* **VD2:**

		int add(int a, int b) { return a + b; }
		int subtract(int a, int b) { return a - b; }
		int multiply(int a, int b) { return a * b; }

		int main(void)
		{
		    int (*operation)(int, int);     // Khai báo con trỏ hàm
		    
		    // ... sau này sẽ gán hàm vào operation
		    return 0;
		}
							
#### **2.2. Gán giá trị và gọi hàm thông qua con trỏ**

* **Cách gán giá trị cho con trỏ hàm:**

		operation = add;           // Cách viết phổ biến (tên hàm tự thoái hóa thành con trỏ)
		operation = &add;          // Cách viết tường minh (cũng hợp lệ)

* **Cách gọi hàm thông qua con trỏ:**

		int result1 = (*operation)(5, 3);     // Cú pháp tường minh
		int result2 = operation(5, 3);        // Cú pháp rút gọn (khuyến nghị)

* **VD:**

		#include <stdio.h>

		int add(int a, int b)      { return a + b; }
		int subtract(int a, int b) { return a - b; }

		int main(void)
		{
		    int (*op)(int, int) = NULL;
		    
		    op = add;
		    printf("5 + 3 = %d\n", op(5, 3));        // 8
		    
		    op = subtract;
		    printf("10 - 4 = %d\n", op(10, 4));      // 6
		    
		    return 0;
		}


	
#### **2.3. Ứng dụng**

##### **2.3.1. Hàm gọi lại (Callback Functions)**

* Cho phép truyền một hàm vào hàm khác để hàm đó gọi lại sau.

		void processArray(int arr[], int size, int (*callback)(int))
		{
		    for(int i = 0; i < size; i++) {
		        arr[i] = callback(arr[i]);
		    }
		}

		int square(int x) { return x * x; }

		int main(void)
		{
		    int numbers[] = {1, 2, 3, 4, 5};
		    processArray(numbers, 5, square);     // Truyền hàm square làm callback
		    return 0;
		}

##### **2.3.2. Bảng phương thức ảo (Virtual Method Table)**

* Mô phỏng lập trình hướng đối tượng trong C:

		typedef struct {
		    void (*draw)(void*);
		    void (*move)(void*, int, int);
		    void (*destroy)(void*);
		} ShapeVTable;

##### **2.3.3. Máy trạng thái (State Machine)**

			typedef void (*StateHandler)(void);

			StateHandler currentState = stateIdle;

			void stateIdle(void) { /* ... */ currentState = stateRunning; }
			void stateRunning(void) { /* ... */ currentState = stateIdle; }
		


### **III.  Mảng con trỏ hàm**

#### **3.1. Cấu trúc và cú pháp khai báo mảng con trỏ hàm**

##### **3.1.1. Khái niệm**

* Mảng con trỏ hàm là một mảng mà mỗi phần tử là một con trỏ hàm có cùng kiểu trả về và danh sách tham số.


##### **3.1.2. Cú pháp**

		kiểu_trả_về (*tên_mảng[kích_thước])(danh_sách_tham_số);

##### **3.1.3. Ví dụ**

* **VD1:**

		// Mảng chứa 10 con trỏ hàm: mỗi hàm nhận 2 int và trả về int
		int (*operations[10])(int, int);

		// Mảng chứa các hàm không trả về, nhận một chuỗi
		void (*handlers[5])(const char*);     

* **VD2:**

		#include <stdio.h>

		int add(int a, int b)      { return a + b; }
		int subtract(int a, int b) { return a - b; }
		int multiply(int a, int b) { return a * b; }
		int divide(int a, int b)   { return (b != 0) ? a / b : 0; }

		int main(void)
		{
		    // Khai báo và khởi tạo mảng con trỏ hàm
		    int (*mathOps[4])(int, int) = {add, subtract, multiply, divide};

		    printf("10 + 5 = %d\n", mathOps[0](10, 5));
		    printf("10 - 5 = %d\n", mathOps[1](10, 5));
		    printf("10 * 5 = %d\n", mathOps[2](10, 5));
		    printf("10 / 5 = %d\n", mathOps[3](10, 5));

		    return 0;
		}



#### **3.2. Ứng dụng**

* **Bảng điều phối lệnh (Command Dispatch Table):**

	*  Một trong những ứng dụng quan trọng và phổ biến nhất của mảng con trỏ hàm là xây dựng Command Dispatch Table (Bảng điều phối lệnh).
	
	*  Kỹ thuật này giúp thay thế chuỗi if-else hoặc switch-case dài dòng bằng một phép tra cứu nhanh O(1).
	
	* **VD:**

				#include <stdio.h>
				#include <string.h>

				typedef void (*CommandFunc)(const char* args);

				// Các hàm xử lý lệnh
				void cmd_help(const char* args) {
				    printf("Available commands: help, echo, clear, quit\n");
				}

				void cmd_echo(const char* args) {
				    printf("Echo: %s\n", args);
				}

				void cmd_clear(const char* args) {
				    printf("\033[2J\033[H");  // Clear screen (ANSI)
				}

				void cmd_quit(const char* args) {
				    printf("Goodbye!\n");
				    exit(0);
				}

				// Bảng điều phối lệnh
				struct {
				    const char* name;
				    CommandFunc func;
				} commandTable[] = {
				    {"help",  cmd_help},
				    {"echo",  cmd_echo},
				    {"clear", cmd_clear},
				    {"quit",  cmd_quit},
				    {NULL,    NULL}               // Kết thúc bảng
				};

				void executeCommand(const char* cmd, const char* args)
				{
				    for(int i = 0; commandTable[i].name != NULL; i++) {
				        if (strcmp(cmd, commandTable[i].name) == 0) {
				            commandTable[i].func(args);   // Gọi hàm qua con trỏ
				            return;
				        }
				    }
				    printf("Unknown command: %s\n", cmd);
				}

				int main(void)
				{
				    executeCommand("echo", "Hello World!");
				    executeCommand("help", "");
				    executeCommand("clear", "");
				    
				    return 0;
				}


		




### **IV.  Tối ưu với từ khóa restrict**

#### **4.1. Pointer Allasing**

* Pointer Aliasing xảy ra khi hai hoặc nhiều con trỏ khác nhau cùng trỏ đến (hoặc có thể trỏ đến) cùng một vùng nhớ, hoặc các vùng nhớ chồng lấn nhau.

* **Vấn đề đối với trình biên dịch:**

	*  Khi trình biên dịch nhìn thấy hai con trỏ, nó phải giả định rằng chúng có thể đang trỏ đến cùng một vùng nhớ.

	*  Do đó, nó không dám thực hiện nhiều tối ưu hóa quan trọng như:
	
		*  Sắp xếp lại thứ tự các lệnh (instruction reordering)
		
		*  Giữ giá trị trong thanh ghi (register caching)

		*  Vectorization (sử dụng lệnh SIMD)
		
		*  Loop unrolling
		
	* VD:

				void copy(int *dst, int *src, int n)
				{
				    for(int i = 0; i < n; i++) {
				        dst[i] = src[i];        // Trình biên dịch phải kiểm tra xem dst và src có chồng lấn không
				    }
				} 
			

			
#### **4.2. Ý nghĩa và cách sử dụng từ khóa restrict**

##### **4.2.1. Cú pháp**

		kiểu_dữ_liệu *restrict tên_con_trỏ;

##### **4.2.2. VD**

		void memcpy(void *restrict dest, const void *restrict src, size_t n);

		void addArrays(int *restrict a, int *restrict b, int *restrict result, int n)
		{
		    for(int i = 0; i < n; i++) {
		        result[i] = a[i] + b[i];    // Trình biên dịch biết a, b, result không chồng lấn
		    }
		}

##### **4.2.3. Quy tắc quan trọng khi sử dụng restrict**
		
* Chỉ được dùng `restrict` khi bạn chắc chắn tuyệt đối rằng các con trỏ không alias nhau.

* Nếu vi phạm lời hứa (các con trỏ thực sự chồng lấn), chương trình sẽ gặp Undefined Behavior (hành vi không xác định).

* `restrict` chỉ có ý nghĩa với con trỏ tham số của hàm hoặc con trỏ cục bộ.



#### **4.3. Lợi ích**

* Khi trình biên dịch tin vào lời hứa restrict, nó có thể thực hiện mạnh mẽ các tối ưu hóa sau:

	*  Giữ dữ liệu trong thanh ghi lâu hơn
	
	*  Sắp xếp lại thứ tự lệnh một cách tự do 
	
	*  Thực hiện vectorization (sử dụng lệnh SIMD)
	
	*  Loại bỏ các kiểm tra chồng lấn không cần thiết
	
	*  Tăng tốc đáng kể các vòng lặp xử lý mảng lớn    


			
### **V.  Variadic Functions**

#### **5.1. Khái niệm và ví dụ hàm khả biến**

* Hàm khả biến là hàm có thể chấp nhận số lượng đối số thay đổi (zero or more) trong mỗi lần gọi.

* **VD:**

		printf("Hello %s, you are %d years old.\n", "Alice", 25);
		// Hàm printf nhận 1 đối số cố định + nhiều đối số khả biến

* **Cú pháp:**

		kiểu_trả_về tên_hàm(kiểu_cố_định last_fixed_arg, ...);
			
#### **5.2. Thư viện <stdarg.h> và các macro cơ bản**

* Để xử lý đối số khả biến, chúng ta sử dụng thư viện `<stdarg.h>` với bộ macro sau:

	* **va_list:**
	
		* Kiểu dữ liệu lưu trữ danh sách đối số
		
		* VD: `va_list ap;`  

	* **va_start:**
	
		* Khởi tạo danh sách đối số
		
		* VD: `va_start(ap, last_fixed_arg);`  

	* **va_arg:**
	
		* Lấy đối số tiếp theo và ép kiểu
		
		* VD: `va_arg(ap, int);`  

	* **va_end:**
	
		* Dọn dẹp, giải phóng tài nguyên
		
		* VD: `va_end(ap);`  

	* **va_copy:**
	
		* Sao chép danh sách đối số
		
		* VD: `va_copy(dest, src);`  
				
* **VD:**

			#include <stdio.h>
			#include <stdarg.h>

			int sum(int count, ...)
			{
			    va_list ap;
			    int total = 0;

			    va_start(ap, count);           // Khởi tạo, bắt đầu từ sau tham số count

			    for(int i = 0; i < count; i++) {
			        total += va_arg(ap, int);  // Lấy đối số kiểu int
			    }

			    va_end(ap);                    // Dọn dẹp
			    return total;
			}

			int main(void)
			{
			    printf("Sum = %d\n", sum(5, 10, 20, 30, 40, 50));   // 150
			    printf("Sum = %d\n", sum(3, 100, 200, 300));        // 600
			    return 0;
			}

		
	
#### **5.3. Rủi ro**

* **Mất an toàn kiểu (Type Safety):**

	*  Trình biên dịch không kiểm tra kiểu của các đối số khả biến → dễ truyền sai kiểu.

* **Không biết số lượng đối số:**

	*  Hàm phải có cơ chế riêng để biết có bao nhiêu đối số (thường dùng tham số đếm hoặc chuỗi định dạng như `printf`).

* **Undefined Behavior nếu sai:**

	*  Truyền sai số lượng đối số
	
	*  Truyền sai kiểu dữ liệu 
	
	* Quên gọi `va_end()` 

#### **5.4. Kỹ thuật nâng cao với va_copy**

* **Cú pháp:**

		va_list ap, ap_copy;

		va_start(ap, last_arg);
		va_copy(ap_copy, ap);        // Tạo bản sao

* **VD:**

		void printAll(const char* format, ...)
		{
		    va_list ap, ap_copy;
		    
		    va_start(ap, format);
		    va_copy(ap_copy, ap);        // Tạo bản sao để dùng sau
		    
		    // Duyệt lần 1: đếm số đối số hoặc xử lý logic
		    // ...
		    
		    // Duyệt lần 2: in ra
		    va_list temp = ap_copy;
		    // ... sử dụng temp
		    
		    va_end(ap);
		    va_end(ap_copy);
		}
			 										
   </details> 


<details>
    <summary><strong>CHƯƠNG 13: THAO TÁC TỆP TIN</strong></summary>


## **CHƯƠNG 13: THAO TÁC TỆP TIN**

### **I. GIAO DIỆN QUẢN LÝ TỆP TIN CƠ SỞ**

#### **1.1.Luồng tệp tin và con trỏ FILE**

##### **1.1.1. Khái niệm**

*	Luồng là một dãy byte được truyền đi hoặc nhận về theo thứ tự

*  Trong ngôn ngữ C, mọi hoạt động nhập/xuất đều được mô hình hóa dưới dạng luồng	
  
*	Có hai luồng chính:

	* **Luồng văn bản (Text Stream):**	
  
		*	Dữ liệu được xử lý dưới dạng ký tự có thể đọc được bởi con người 
		
		*  Các ký tự kết thúc dòng (như `\n`) có thể được chuyển đổi bởi hệ thống
		
			* VD: `\n` thành `\r\n` trên Windows 	
	
	* **Luồng nhị phân (Binary Stream):**	
  
		*	Dữ liệu được xử lý chính xác từng byte mà không có bất kỳ chuyển đổi nào
		
		*  Phù hợp với việc lưu trữ dữ liệu không phải văn bản (hình ảnh, âm thanh, cơ sở dữ liệu...).
		
* Mọi luồng trong C đều được biểu diễn bởi con trỏ đến cấu trúc FILE.
  
 
##### **1.1.2. Cấu trúc FILE và Con trỏ FILE**

* 	Cấu trúc FILE được định nghĩa trong file tiêu đề `<stdio.h>`

*  **VD khai báo:**
	
			FILE *fp;        // fp là con trỏ đến một luồng tệp tin

	* **Vai trò:**
	 
		*  Nó đóng vai trò như một lớp vỏ bọc trừu tượng hóa (abstraction layer) giữa chương trình người dùng và hệ điều hành.
		
		*  Che giấu các chi tiết cấp thấp của hệ điều hành, chẳng hạn như file descriptor (số mô tả tệp tin) trong Unix/Linux hoặc HANDLE trong Windows.
		
		*  Chứa các thông tin quản lý luồng quan trọng:
		
			*  Con trỏ vị trí hiện tại trong tệp (current file position).
			
			*  Trạng thái của luồng (error flag, EOF flag).
			
			*  Bộ đệm (buffer) nội bộ.
			
			*  Chế độ mở tệp (read, write, append, binary, text...).
			
			*  File descriptor tương ứng.
			
*  Khi gọi hàm `fopen()`, hệ thống sẽ cấp phát một cấu trúc `FILE`, khởi tạo các thành phần cần thiết và trả về con trỏ đến cấu trúc đó

	* Nếu không mở được tệp, hàm sẽ trở về `NULL`     

##### **1.1.3. Bộ đệm (Buffering) trong luồng FILE**

* 	**Lý do sử dụng bộ đệm:**

	*  Truy cập trực tiếp vào đĩa cứng (hoặc thiết bị I/O) rất chậm so với tốc độ của CPU và RAM
	
	* Mỗi lần gọi system call (như `read()`/`write()` của kernel) đều có chi phí lớn (context switch).
	
	* Bộ đệm giúp tối ưu hóa hiệu suất bằng cách gom nhiều thao tác đọc/ghi nhỏ thành các khối lớn hơn.  
	

* **Các chế độ bộ đệm:**
	 
	*  **Fully buffered:**
		
		*  Chỉ ghi ra thiết bị khi bộ đệm đầy hoặc gọi `fflush()`
		
		*  Thường dùng cho tệp tin trên đĩa
		
	*  **Line buffered:**
		
		*  Ghi ra khi gặp ký tự `\n` hoặc bộ đệm đầy
		
		*  Thường dùng cho luồng xuất ra màn hình
			
	*  **Unbuffered:**
		
		*  Ghi/đọc ngay lập tức, không qua bộ đệm
		
		*  Thường dùng cho `stderr`

#### **1.2.Mở và đóng luồng tệp tin**

##### **1.2.1. Hàm fopen() – Mở luồng tệp tin**

*	**Khai báo hàm:**

		FILE *fopen(const char *filename, const char *mode);

*  **Chức năng:**

	* Hàm `fopen()` thiết lập một kênh giao tiếp giữa chương trình và tệp tin (hoặc thiết bị), cấp phát và khởi tạo cấu trúc FILE, sau đó trả về con trỏ đến cấu trúc này. 
	
	* Nếu không mở được tệp, hàm trả về `NULL`. 

*  **Tham số:**

	* `filename:` 
	
		* Chuỗi ký tự chứa đường dẫn và tên tệp tin cần mở (có thể là đường dẫn tương đối hoặc tuyệt đối)
		
	* `mode:`
	
		* Chuỗi ký tự xác định chế độ mở tệp tin     
	
*  **Giá trị trả về:**

	* Con trỏ `FILE*` hợp lệ nếu mở thành công
	
	* `NULL` nếu thất bại 

##### **1.2.2. Hàm fclose() – Đóng luồng tệp tin**

*	**Khai báo hàm:**

		int fclose(FILE *stream);

*  **Chức năng:**

	* Đẩy (flush) toàn bộ dữ liệu còn lại trong bộ đệm của luồng ra thiết bị lưu trữ.
	
	* Yêu cầu hệ điều hành đóng tệp tin, giải phóng file descriptor và các tài nguyên liên quan.
	
	* Giải phóng bộ nhớ của cấu trúc `FILE` mà `fopen()` đã cấp phát. 
	
*  **Giá trị trả về:**

	* `0:` Đóng thành công
	
	* `EOF:` Có lỗi xảy ra khi đóng

*  **Nguyên tắc quản trị:**

	* Luôn kiểm tra kết quả của `fopen()`.
	
	* Mỗi `fopen()` thành công phải có một `fclose()` tương ứng.
	
	* Xử lý lỗi một cách an toàn bằng `perror()` hoặc `strerror(errno)`. 

#### **1.3.Các chế độ truy cập tệp tin (File Modes)**

##### **1.3.1. Các chế độ cơ bản**

*	**"r" (Read):**

	* Mở tệp tin chỉ để đọc
	
	* Tệp phải tồn tại
	
	* Con trỏ đặt ở đầu tệp.    	

			#include <stdio.h>
			#include<stdlib.h>
			int main(){
				FILE *f;
				char buffer[100];

				// Mở file ở chế độ đọc - file phải tồn tại
				f = fopen("data.txt", "r");
				if (f == NULL){
					printf("Loi khong the mo file!\n");
					return 1;
				}

				// Đọc từng dòng
				while (fgets(buffer, sizeof(buffer), f) != NULL){
					printf("%s", buffer);
				}

				fclose(f);
				return 0;
			}

*	**"w" (Write):**

	* Mở tệp để ghi
	
	* Nếu tệp tồn tại thì xóa sạch nội dung cũ
	
	* Tạo tệp mới nếu chưa tồn tại.   	

			#include <stdio.h>

			int main() {
			    FILE *f;

			    // Mở file ở chế độ ghi - xóa sạch nội dung cũ, tạo mới nếu chưa có
			    f = fopen("output.txt", "w");
			    if (f == NULL) {
			        printf("Lỗi: Không thể tạo file!\n");
			        return 1;
			    }

			    // Ghi nội dung vào file
			    fprintf(f, "Dòng thứ nhất\n");
			    fprintf(f, "Dòng thứ hai\n");
			    fprintf(f, "Số nguyên: %d, Số thực: %.2f\n", 42, 3.14);

			    fclose(f);
			    printf("Đã ghi file thành công!\n");
			    return 0;
			}


*	**"a" (Append):**

	* Mở tệp để ghi nối vào cuối tệp
	
	* Tạo tệp mới nếu chưa tồn tại.

			#include <stdio.h>

			int main() {
			    FILE *f;

			    // Mở file ở chế độ ghi nối - ghi tiếp vào cuối file
			    f = fopen("output.txt", "a");
			    if (f == NULL) {
			        printf("Lỗi: Không thể mở file!\n");
			        return 1;
			    }

			    // Nội dung mới sẽ được thêm vào cuối file
			    fprintf(f, "Dòng được ghi nối thêm\n");
			    fprintf(f, "Thêm một dòng nữa\n");

			    fclose(f);
			    printf("Đã ghi nối vào file thành công!\n");
			    return 0;
			}


##### **1.3.2. Các bổ ngữ**

*	**"+":**

	* Chế độ cập nhật (update) – cho phép vừa đọc vừa ghi
	
	* `"r+", "w+", "a+"`    	
	
		* Đọc và Ghi - File phải tồn tại 

				#include <stdio.h>

				int main() {
				    FILE *f;
				    char buffer[100];

				    // Mở file để vừa đọc vừa ghi - file phải tồn tại
				    f = fopen("data.txt", "r+");
				    if (f == NULL) {
				        printf("Lỗi: File không tồn tại!\n");
				        return 1;
				    }

				    // Đọc nội dung hiện tại
				    printf("Nội dung trước khi ghi:\n");
				    while (fgets(buffer, sizeof(buffer), f) != NULL) {
				        printf("%s", buffer);
				    }

				    // Di chuyển con trỏ về cuối file để ghi nối
				    fseek(f, 0, SEEK_END);
				    fprintf(f, "Dòng được thêm vào cuối\n");

				    // Di chuyển con trỏ về đầu file để ghi đè
				    rewind(f);
				    fprintf(f, "Dòng này ghi đè lên đầu file\n");

				    fclose(f);
				    printf("\nĐã cập nhật file thành công!\n");
				    return 0;
				}

		* Đọc và Ghi - Xóa sạch hoặc tạo mới

				#include <stdio.h>

				int main() {
				    FILE *f;
				    char buffer[100];

				    // Mở file để vừa đọc vừa ghi - xóa sạch nội dung cũ
				    f = fopen("newfile.txt", "w+");
				    if (f == NULL) {
				        printf("Lỗi: Không thể tạo file!\n");
				        return 1;
				    }

				    // Ghi dữ liệu vào file
				    fprintf(f, "Dữ liệu mẫu 1\n");
				    fprintf(f, "Dữ liệu mẫu 2\n");
				    fprintf(f, "Dữ liệu mẫu 3\n");

				    // Di chuyển con trỏ về đầu file để đọc
				    rewind(f);

				    // Đọc lại dữ liệu vừa ghi
				    printf("Nội dung file:\n");
				    while (fgets(buffer, sizeof(buffer), f) != NULL) {
				        printf("%s", buffer);
				    }

				    fclose(f);
				    return 0;
				}

		* Đọc và Ghi nối

				#include <stdio.h>

				int main() {
				    FILE *f;
				    char buffer[100];

				    // Mở file để vừa đọc vừa ghi nối - tạo mới nếu chưa có
				    f = fopen("log.txt", "a+");
				    if (f == NULL) {
				        printf("Lỗi: Không thể mở file!\n");
				        return 1;
				    }

				    // Ghi thêm vào cuối file
				    fprintf(f, "[LOG] Thời điểm ghi log mới\n");

				    // Di chuyển con trỏ về đầu để đọc toàn bộ nội dung
				    rewind(f);
				    printf("Toàn bộ nội dung log:\n");
				    while (fgets(buffer, sizeof(buffer), f) != NULL) {
				        printf("%s", buffer);
				    }

				    fclose(f);
				    return 0;
				}
				    				
*	**"b":**

	* Chế độ nhị phân (binary)
	
	* `"rb", "wb", "ab", "rb+", "wb+", "ab+"` 
	
		* Ghi file nhị phân "wb"  

				#include <stdio.h>

				typedef struct {
				    int id;
				    char name[30];
				    float score;
				} Student;

				int main() {
				    FILE *f;
				    Student s1 = {1, "Nguyen Van A", 8.5};
				    Student s2 = {2, "Tran Thi B", 9.2};

				    // Mở file nhị phân để ghi
				    f = fopen("students.dat", "wb");
				    if (f == NULL) {
				        printf("Lỗi: Không thể tạo file!\n");
				        return 1;
				    }

				    // Ghi cấu trúc vào file nhị phân
				    fwrite(&s1, sizeof(Student), 1, f);
				    fwrite(&s2, sizeof(Student), 1, f);

				    fclose(f);
				    printf("Đã ghi file nhị phân thành công!\n");
				    return 0;
				}


#### **1.4.Các luồng chuẩn mặc định**

##### **1.4.1. Các chế độ cơ bản**

*	**stdin:**

	* Luồng đầu vào chuẩn (thường là bàn phím), line buffered	

*	**stdout:**

	* Luồng đầu ra chuẩn (thường là màn hình), line buffered hoặc fully buffered.

*	**stderr:**

	* Luồng báo lỗi chuẩn (thường là màn hình), unbuffered (không có bộ đệm).
 		        
### **II.  NHẬP XUẤT TỆP TIN VĂN BẢN**

####  **2.1. Đặc tính**

#####  **2.1.1. Dịch ký tự cuối dòng (Line Ending Translation)**

* **Trên Windows:**

	* Ký tự xuống dòng `\n` (LF - Line Feed) khi ghi sẽ được tự động chuyển thành `\r\n` (CRLF - Carriage Return + Line Feed). 
	
	* Ngược lại, khi đọc, `\r\n` sẽ được chuyển thành `\n`. 

* **Trên Unix/Linux:**

	* Không có chuyển đổi, `\n` được giữ nguyên.


	

#####  **2.1.2. Nhận diện ký tự kết thúc tệp (End-of-File Marker)**

* Khi đọc, nếu gặp ký tự `EOF` (thường là giá trị `-1`), hàm đọc sẽ báo hiệu kết thúc tệp.

* Trong chế độ văn bản, một số hệ thống có thể sử dụng ký tự `Ctrl+Z` (ASCII 26) làm dấu kết thúc tệp (đặc biệt trên Windows với tệp văn bản cũ). 

* Lưu ý:

	* Không nên mở tệp nhị phân ở chế độ văn bản vì sẽ gây sai lệch dữ liệu.   

	* Nên sử dụng chế độ nhị phân ("rb", "wb", ...) khi xử lý file không phải văn bản thuần.

####  **2.2. Thao tác theo từng ký tự**

* **Đọc ký tự:** 

	* `int fgetc(FILE *stream);`
	
	* `int getc(FILE *stream);`
 
	* Chức năng: Đọc một ký tự từ luồng và trả về mã ASCII của ký tự đó.
	
	* Giá trị trả về:
	
		* Ký tự đọc được (0-255).
		
		* `EOF (-1)` nếu gặp cuối tệp hoặc lỗi.   

* **Ghi ký tự:** 

	* `int fputc(int c, FILE *stream);`
	
	* `int putc(int c, FILE *stream);`
 
	* Chức năng: Ghi một ký tự vào luồng.
	
	* Giá trị trả về:
	
		* Ký tự vừa ghi nếu thành công, EOF nếu lỗi.

				FILE *fp = fopen("data.txt", "w");
				fputc('A', fp);
				fputc('\n', fp);
				fclose(fp);



####  **2.3.  Thao tác theo từng dòng**

* **Đọc dòng – fgets():**
	
	*  Khai báo 

			char *fgets(char *str, int n, FILE *stream);

	* **Chức năng:**
	
		*  Đọc tối đa `n-1` ký tự từ luồng vào mảng `str`.

		*  Dừng khi gặp ký tự `\n` hoặc cuối tệp
		
		* Bao gồm cả ký tự `\n` vào chuỗi nếu gặp
		
		* Tự động thêm ký tự `'\0'` kết thúc chuỗi  
		
	* VD:
	
		* Đọc một dòng từ file  

				#include <stdio.h>
				#include <string.h>

				int main() {
				    FILE *file;
				    char str[100];  // Bộ đệm để lưu dữ liệu đọc được
				    
				    // Mở file để đọc
				    file = fopen("data.txt", "r");
				    if (file == NULL) {
				        printf("Không thể mở file!\n");
				        return 1;
				    }
				    
				    // Đọc một dòng từ file (tối đa 99 ký tự + '\0')
				    if (fgets(str, 100, file) != NULL) {
				        printf("Dòng đọc được: %s", str);
				        printf("Độ dài chuỗi: %lu\n", strlen(str));
				        
				        // Kiểm tra xem có ký tự '\n' ở cuối không
				        if (str[strlen(str) - 1] == '\n') {
				            printf("Chuỗi kết thúc bằng ký tự xuống dòng\n");
				        }
				    }
				    
				    fclose(file);
				    return 0;
				}

		* Đọc từng dòng cho đến hết file  

				#include <stdio.h>
				#include <string.h>

				int main() {
				    FILE *file;
				    char line[256];
				    int lineNumber = 1;
				    
				    file = fopen("data.txt", "r");
				    if (file == NULL) {
				        printf("Không thể mở file!\n");
				        return 1;
				    }
				    
				    // Đọc từng dòng cho đến khi hết file
				    while (fgets(line, sizeof(line), file) != NULL) {
				        // Xóa ký tự '\n' ở cuối dòng (nếu có)
				        size_t len = strlen(line);
				        if (len > 0 && line[len - 1] == '\n') {
				            line[len - 1] = '\0';
				        }
				        
				        printf("Dòng %d: %s\n", lineNumber++, line);
				    }
				    
				    fclose(file);
				    return 0;
				}

* **Ghi dòng – fputs():**
	
	*  Khai báo 

			int fputs(const char *str, FILE *stream);

	* **Chức năng:**
	
		*  Ghi một chuỗi ký tự vào luồng.

		*  Không tự động thêm ký tự \n ở cuối.
		
		
	* VD:
	
				FILE *fp = fopen("log.txt", "a");
				fputs("Dong du lieu moi\n", fp);
				fclose(fp);

####  **2.4.  Thao tác theo định dạng**

* **Ghi dữ liệu định dạng – fprintf():**
	
	*  Khai báo 

			int fprintf(FILE *stream, const char *format, ...);

	* **Chức năng:**
	
		*  Ghi dữ liệu ra luồng theo định dạng giống như printf(), nhưng xuất ra tệp tin hoặc luồng chỉ định.  
		
	* VD:
	
		* Ghi dữ liệu cơ bản vào file

				#include <stdio.h>

				int main() {
				    FILE *file;
				    char name[] = "Nguyen Van A";
				    int age = 25;
				    float score = 8.75;
				    
				    // Mở file để ghi ("w" - write mode)
				    file = fopen("student.txt", "w");
				    if (file == NULL) {
				        printf("Không thể mở file!\n");
				        return 1;
				    }
				    
				    // Ghi dữ liệu có định dạng vào file
				    fprintf(file, "Ho ten: %s\n", name);
				    fprintf(file, "Tuoi: %d\n", age);
				    fprintf(file, "Diem: %.2f\n", score);
				    
				    // Có thể ghi nhiều giá trị trong một lệnh
				    fprintf(file, "Tong ket: %s, %d tuoi, dat %.2f diem\n", 
				            name, age, score);
				    
				    fclose(file);
				    printf("Da ghi du lieu vao file student.txt\n");
				    
				    return 0;
				}

				// Nội dung file student.txt:
				Ho ten: Nguyen Van A
				Tuoi: 25
				Diem: 8.75
				Tong ket: Nguyen Van A, 25 tuoi, dat 8.75 diem		

* **Đọc dữ liệu định dạng – fscanf():**
	
	*  Khai báo 

			int fscanf(FILE *stream, const char *format, ...);

	* **Chức năng:**
	
		*  Đọc và phân tích dữ liệu từ luồng theo định dạng giống như scanf()
		
	* **VD:** 

				FILE *fp = fopen("student.txt", "w");
				fprintf(fp, "%s %d %.2f\n", "Nguyen Van A", 20, 8.75);

				fclose(fp);

				fp = fopen("student.txt", "r");
				char name[50];
				int age;
				float score;
				fscanf(fp, "%s %d %f", name, &age, &score);
				
### **III. NHẬP XUẤT TỆP TIN NHỊ PHÂN**

####  **3.1. Chế độ nhị phân**

* Khi mở tệp tin ở chế độ nhị phân (binary mode – có chữ `b` trong chế độ: "rb", "wb", "ab", "rb+"...), thư viện stdio sẽ không thực hiện bất kỳ chuyển đổi ký tự nào.

* Đặc điểm

	*  Dữ liệu trong bộ nhớ được sao chép nguyên bản (byte-for-byte) ra tệp và ngược lại.
	
	*  Không diễn ra chuyển đổi ký tự cuối dòng (`\n` ↔ `\r\n`).  
	
	*  Không có xử lý đặc biệt cho ký tự kết thúc tệp (EOF marker). 

		

####  **3.2. Đọc ghi các khối dữ liệu**

* **Cú pháp:**

		size_t fread(void *buffer, size_t size, size_t count, FILE *stream);

		size_t fwrite(const void *buffer, size_t size, size_t count, FILE *stream);
		
* **Tham số:**

	* **buffer:** Con trỏ đến vùng nhớ chứa dữ liệu (đọc) hoặc cần ghi
	
	* **size:** Kích thước (theo byte) của mỗi phần tử
	
	* **count:** Số lượng phần tử cần đọc/ghi
	
	* **stream:** Con trỏ luồng tệp tin    

* **Giá trị trả về:**

	* Số lượng phần tử thực sự đã đọc/ghi thành công
	
	* Giá trị này phải được kiểm tra sau mỗi lần gọi để phát hiện lỗi hoặc cuối tệp.
	
* **VD:**
	
			int arr[100];
			FILE *fp = fopen("data.bin", "wb");
			fwrite(arr, sizeof(int), 100, fp);   // Ghi 100 số nguyên
			fclose(fp);


####  **3.3. Tuần tự hóa cấu trúc**

* Không nên chứa con trỏ bên trong cấu trúc.

* Nên dùng `sizeof(Struct)` để đảm bảo kích thước chính xác.
	
* Cần kiểm tra giá trị trả về của `fread/fwrite`.
	
			typedef struct {
			    char name[50];
			    int age;
			    float gpa;
			    long id;
			} Student;

			Student sv1 = {"Tran Van B", 21, 8.5, 2023001};

			// Ghi cấu trúc ra tệp
			FILE *fp = fopen("student.dat", "wb");
			fwrite(&sv1, sizeof(Student), 1, fp);
			fclose(fp);

			// Đọc lại từ tệp
			Student sv2;
			fp = fopen("student.dat", "rb");
			fread(&sv2, sizeof(Student), 1, fp);
			fclose(fp);

### **IV. ĐỊNH VỊ LUỒNG TỆP TIN**

####  **4.1. Truy cập ngẫu nhiên (Random Access)**

* **Truy cập tuần tự:**

	* Đọc/ghi dữ liệu theo thứ tự từ đầu đến cuối tệp. 

* **Truy cập ngẫu nhiên:**

	* Cho phép di chuyển con trỏ vị trí (file position indicator) đến bất kỳ vị trí nào trong tệp để đọc hoặc ghi dữ liệu.

####  **4.2. Di chuyển con trỏ vị trí**

* **Cú pháp:**

		int fseek(FILE *stream, long offset, int origin); 

	* `stream`: Con trỏ luồng tệp tin
	
	* `offset`: Số byte cần di chuyển
	
	* `origin`: Điểm xuất phát để tính offset
	
		* `SEEK_SET`: byte thứ `offset` từ đầu
		
		* `SEEK_CUR`: byte thứ `offset` từ vị trí hiện tại
		
		* `SEEK_END`: byte thứ `offset` từ cuối
		
* **Giá trị trả về:**

	* `0`: Thành công
	
	* `Khác 0`: Thất bại        

* **VD:**

			fseek(fp, 0, SEEK_SET);      // Về đầu tệp
			fseek(fp, 100, SEEK_SET);    // Nhảy đến byte thứ 100
			fseek(fp, -50, SEEK_CUR);    // Lùi lại 50 byte từ vị trí hiện tại
			fseek(fp, 0, SEEK_END);      // Nhảy đến cuối tệp
			fseek(fp, -128, SEEK_END);   // Lùi 128 byte từ cuối tệp
		

####  **4.3. Lấy vị trí hiện tại**

* **Cú pháp:**

		long ftell(FILE *stream);

* Trả về vị trí hiện tại của con trỏ vị trí, tính bằng số byte từ đầu tệp.

* Ứng dụng:

	* Xác định kích thước tệp.
	
	* Lưu vị trí hiện tại để quay lại sau.
	
	* Kiểm tra vị trí trước và sau khi thao tác.
	
* VD:

			long current_pos = ftell(fp);
			printf("Vi tri hien tai: %ld byte\n", current_pos);      	

####  **4.4. Quay về đầu tệp**

* **Cú pháp:**

		void rewind(FILE *stream);

* Đưa con trỏ vị trí về đầu tệp `(SEEK_SET` với offset = 0).

* Đồng thời xóa các cờ lỗi (error flag) và cờ cuối tệp (EOF flag) của luồng.

### **V. CƠ CHẾ XỬ LÝ LỖI THAO TÁC TỆP**

####  **5.1. Phân biệt trạng thái cuối tệp và lỗi**

* Khi thực hiện các hàm đọc như `fgetc(), fgets(), fread(), fscanf()`..., việc thất bại có thể xuất phát từ hai nguyên nhân khác nhau:

	* Đã đến cuối tệp (End-of-File).
	
	* Xảy ra lỗi I/O (lỗi cứng, mất quyền truy cập, đĩa đầy, hỏng sector...). 

* **Hàm feof():**

			int feof(FILE *stream);

* Trả về giá trị khác 0 (thường là 1) nếu cờ hiệu end-of-file đã được bật.

* Chỉ cho biết đã đọc hết dữ liệu, không phải là lỗi. 

* **Hàm ferror():**

			int ferror(FILE *stream);

* Trả về giá trị khác 0 nếu cờ hiệu lỗi đã được bật.

* Cho biết đã xảy ra lỗi trong quá trình I/O.

* **VD:**

			FILE *fp = fopen("data.bin", "rb");
			if (fp == NULL) { /* xử lý lỗi */ }

			int c;
			while ((c = fgetc(fp)) != EOF) {
			    // Xử lý dữ liệu
			}

			if (feof(fp)) {
			    printf("Da doc den cuoi tep tin.\n");
			} else if (ferror(fp)) {
			    printf("Co loi xay ra khi doc tep tin!\n");
			    perror("Chi tiet loi");
			}

			fclose(fp); 



####  **5.2. Đặt lại trạng thái lỗi**

* **Cú pháp:**

		void clearerr(FILE *stream);

		
* Xóa cả hai cờ hiệu: EOF flag và Error flag.

* Cho phép tiếp tục thực hiện các thao tác I/O trên luồng sau khi đã khắc phục lỗi (nếu có thể).

* Ứng dụng:  

	* Sau khi xử lý lỗi tạm thời (ví dụ: chờ đĩa sẵn sàng).
	
	* Trước khi thử lại các thao tác đọc/ghi.

####  **5.3. Hàm setvbuf() – Thiết lập chế độ bộ đệm**

* **Cú pháp:**

		int setvbuf(FILE *stream, char *buffer, int mode, size_t size);

		
* Các chế độ.

	* Full buffering: `_IOFBF`
	
	* Line buffering: `_IOLBF`
	
	* No buffering: `_IONBF`  

####  **5.4. Kỹ thuật khóa tệp tin**

* File Locking là cơ chế ngăn chặn nhiều tiến trình (hoặc thread) cùng truy cập một tệp tin đồng thời, đảm bảo tính toàn vẹn dữ liệu (data integrity) trong môi trường đa nhiệm.

* Các loại khóa phổ biến:

	* Exclusive Lock (khóa độc quyền): 
	
		* Chỉ cho phép một tiến trình đọc/ghi.
		
		* Các tiến trình khác phải chờ 
		
		* Sử dụng khi cần ghi dữ liệu 
	
	* Shared Lock (khóa chia sẻ): 
	
		* Nhiều tiến trình có thể đọc cùng lúc, nhưng không ai được ghi.
		
		* Sử dụng khi chỉ cần đọc dữ liệu    



				
   </details> 
   

<details>
    <summary><strong>CHƯƠNG 14: XỬ LÝ TÍN HIỆU (SIGNAL HANDLING)</strong></summary>


## **CHƯƠNG 14: XỬ LÝ TÍN HIỆU (SIGNAL HANDLING)**

### **I. KHÁI NIỆM VÀ PHÂN LOẠI TÍN HIỆU**

#### **1.1.Software Interrupts**

*	Tín hiệu là một cơ chế thông báo ngắn gọn, không đồng bộ do hệ điều hành (kernel) hoặc tiến trình khác gửi đến một tiến trình để báo hiệu một sự kiện đã xảy ra.
  
*  Cơ chế hoạt động: 

	*	Khi một tín hiệu được gửi đi, hệ điều hành tạm dừng luồng thực thi bình thường của tiến trình, buộc nó phải xử lý tín hiệu đó.
  
	*	Nếu tiến trình đã đăng ký một "Hàm xử lý tín hiệu" (Signal Handler), quyền điều khiển sẽ được chuyển đến hàm này.
	
	*  Sau khi hàm xử lý kết thúc, luồng thực thi chính có thể được tiếp tục (nếu không bị chấm dứt).
  
 
#### **1.2. Nguồn gốc phát sinh tín hiệu**

* **Từ User:**

	* 	Gõ tổ hợp phím trên terminal:

		*  `Ctrl+C` sinh ra **`SIGINT`** (Interrupt).
		
		*  `Ctrl+Z` sinh ra **`SIGTSTP`** (Terminal Stop).
		
		* `Ctrl+\` sinh ra **`SIGQUIT`** (Quit).

* **Từ Hardware/Kernel:**

	* 	Các ngoại lệ (exception) xảy ra trong chính tiến trình, được kernel ánh xạ thành tín hiệu:

		*  Lỗi tính toán: chia cho 0 sinh ra **`SIGFPE`**.
		
		*  Truy cập bộ nhớ không hợp lệ sinh ra **`SIGSEGV`**.
		
		* Thực thi lệnh không hợp lệ sinh ra **`SIGILL`**.
		
		*  Hết giờ của `alarm()` sinh ra **`SIGALRM`**.
		
		*  Ghi vào pipe đã bị đóng ở đầu đọc sinh ra **`SIGPIPE`**.

* **Từ Other Processes:**

	* 	Sử dụng lời gọi hệ thống `kill()` hoặc lệnh `kill` trên shell.

		*  `kill -TERM <pid>` gửi **`SIGTERM`**.
		
		* `kill -USR1 <pid>` gửi **`SIGUSR1`**.
		
#### **1.3. Hành động mặc định**

* Mỗi tín hiệu đều có một hành động mặc định được quy định bởi kernel. Các hành động phổ biến bao gồm:

	* 	Terminate: Chấm dứt tiến trình 
	
	*  Core dump: Chấm dứt tiến trình và tạo tệp `core` để gỡ lỗi 
	
	*  Ignore: Bỏ qua tín hiệu, không làm gì cả 
	
	*  Stop: Tạm dừng tiến trình cho đến khi nhận được `SIGCONT` 
	
	* Cont: Tiếp tục thực thi một tiến trình đã bị tạm dừng     

#### **1.4. Tín hiệu đồng bộ và bất đồng bộ**

##### **1.4.1. Tín hiệu đồng bộ (Synchronous Signals)**

* Được sinh ra trực tiếp bởi chính luồng thực thi của tiến trình do lỗi trong quá trình thực thi lệnh CPU.

* Luôn gắn với một chỉ thị cụ thể và xảy ra ngay lập tức.

* Các tín hiệu tiêu biểu:  

	* 	**`SIGSEGV`:** Truy cập bộ nhớ không hợp lệ, dereference con trỏ NULL
	
	*  **`SIGFPE`:** Lỗi tính toán số học (chia cho 0, tràn số).
	
	*  **`SIGILL`:** Thực thi một chỉ thị CPU không hợp lệ.
	
	*  **`SIGPIPE`:** Ghi dữ liệu vào một pipe hoặc socket đã bị đóng ở đầu đọc.
	
	* **`IGABRT`:** Được gửi bởi chính tiến trình khi gọi hàm `abort()`.     

##### **1.4.2. Tín hiệu bất đồng bộ (Asynchronous Signals)**

* Được gửi đến tiến trình từ các sự kiện bên ngoài luồng thực thi hiện tại.

* Không gắn với một chỉ thị cụ thể và có thể đến bất kỳ lúc nào.

* Các tín hiệu tiêu biểu:  

	* 	**`SIGINT`:** Người dùng nhấn `Ctrl+C`
	
	*  **`SIGTERM`:** Yêu cầu chấm dứt tiến trình một cách lịch sự.
	
	*  **`SIGHUP`:** Terminal điều khiển bị đóng (thường dùng để yêu cầu daemon tải lại cấu hình).
	
	*  **`SIGCHLD`:** Trạng thái của tiến trình con thay đổi (kết thúc, dừng,...).
	
	* **`SIGUSR1`, `SIGUSR2`:** Tín hiệu do người dùng tự định nghĩa.     
				  									
#### **1.5. Bảng tham chiếu tín hiệu phổ biến**


| Signal | Số | Default Action | Ý nghĩa / Nguyên nhân phổ biến | Loại |  
|------------|-----|--------------------------|---------------------------------------------------------------------|------------|  
| SIGABRT | 6 | Core dump & terminate | Gọi `abort()` (lỗi `assert` hoặc tự gọi). | Sync |  
| SIGALRM | 14 | Terminate | Hết giờ từ `alarm()` hoặc `setitimer()`. | Async |  
| SIGCONT | 18 | Cont | Tiếp tục tiến trình đã bị dừng | Async
| SIGCHLD | 17 | Ignore | Con process kết thúc hoặc thay đổi trạng thái. | Async |  
| SIGFPE | 8 | Core dump & terminate | Floating point exception (chia 0, overflow). | Sync |  
| SIGHUP | 1 | Terminate | Terminal đóng hoặc controlling process chết. | Async |  
| SIGILL | 4 | Core dump & terminate | Illegal instruction (lỗi opcode). | Sync |  
| SIGINT | 2 | Terminate | Interrupt từ keyboard (`Ctrl+C`). | Async |  
| SIGKILL | 9 | Forced terminate | Không thể catch/block/ignore (`kill -9`), dùng để hủy khẩn cấp | Async |  
| SIGPIPE | 13 | Terminate | Ghi vào pipe bị đóng ở đầu đọc. | Sync |  
| SIGQUIT | 3 | Core dump & terminate | Quit từ keyboard (`Ctrl+\`). | Async |  
| SIGSEGV | 11 | Core dump & terminate | Segmentation fault (truy cập bộ nhớ sai). | Sync | 
| SIGSTOP | 19 | Stop | Không thể catc/block/ignore. Dừng tiến tình | Async |
| SIGTERM | 15 | Terminate | Yêu cầu kết thúc lịch sự (`kill` command). | Async |  
| SIGTSTP | 20 | Stop | Tạm dừng từ keyboard (`Ctrl+Z`). | Async |  
| SIGUSR1 | 10 | Terminate | User-defined signal 1 (tùy ý sử dụng). | Async |  
| SIGUSR2 | 12 | Terminate | User-defined signal 2 (tùy ý sử dụng). | Async |




 		        
### **II.  GIAO DIỆN XỬ LÝ TÍN HIỆU CƠ SỞ**

####  **2.1. Hàm signal() - Đăng ký handler cơ bản**

* **Cú pháp:**

			#include <signal.h>
			typedef void (*sighandler_t)(int);
			sighandler_t signal(int signum, sighandler_t handler); 

	* **signum:** Số tín hiệu hoặc macro như `SIGINT`, `SIGTERM`, `SIGSEGV`
	
	* **handler:** Con trỏ tới hàm xử lý, có dạng `void handler(int sig)` , trong đó `sig` là số tín hiệu 
			
* **Giá trị trả về:**

	* Thành công: Con trỏ tới hàm xử lý cũ (`SIG_DFL` hoặc `SIG_IGN` nếu chưa được thiết lập)
	
	* Thất bại: Trả về `SIG_ERR` và set `errno`    

* **Các hằng số xử lý đặc biệt:**

	* **`SIG_DFL`:** Khôi phục hành động mặc định của tín hiệu
	
	* **`SIG_IGN`:** Yêu cầu tiến trình bỏ qua tín hiệu này
	
 * **VD:** 

					#include <stdio.h>
					#include <signal.h>
					#include <stdlib.h>
					#include <unistd.h>

					// Hàm xử lý dùng chung
					void termination_handler(int sig){
						const char *sig_name = "UNKNOWN";
						if (sig == SIGINT) sig_name = "SIGINT (Ctrl + C)";
						else if (sig == SIGTERM) sig_name = "SIGTERM";
						else if (sig == SIGHUP) sig_name = "SIGHUP (Hangup)";

						// Dùng write() an toàn hơn printf() trong handler()
					 printf("\n[!] Nhận %s. Đang dọn dẹp và thoát...\n", sig_name);
					 // Tại đây có thể thực hiện cleanup: đóng file, xóa file tạm...
					 _exit(0); // Thoát ngay lập tức
					}						 

					int main(){
						// Đăng ký handler cho nhiều tín hiệu
						signal(SIGINT, termination_handler);
						signal(SIGTERM, termination_handler);
						signal(SIGHUP, termination_handler);
					 printf("PID: %d. Đang chạy... (Gửi: kill -TERM %d hoặc kill -HUP %d)\n", getpid(), getpid(), getpid());
					 while (1) {
					 printf(".");
					 fflush(stdout);
					 sleep(1);
					 }
					 return 0;
					}						    		

####  **2.2. Hạn chế**

* Hàm `signal()` là một giao diện cũ từ Unix System V và có những hạn chế lớn, khiến nó **không được khuyến khích sử dụng** trong các ứng dụng hiện đại:

	* Trên một số hệ thống Unix cũ, sau khi một hàm xử lý tín hiệu được gọi, hệ thống sẽ tự động reset hành động của tín hiệu đó về `SIG_DFL`
	
	* Để có hành vi nhất quán và đáng tin cậy, POSIX chuẩn hóa `sigaction()` 
	
	* `signal()` không cung cấp cơ chế nào để chặn các tín hiệu khác trong khi hàm xử lý đang chạy (tạo mặt nạ tín hiệu). 
	 


### **III. XỬ LÝ TÍN HIỆU NÂNG CAO (POSIX sigaction)**

####  **3.1. Hàm sigaction()**

* Cung cấp một giao diện mạnh mẽ, đáng tin cậy, khả chuyển và chi tiết hơn `signal()` để kiểm soát hoàn toàn hành vi xử lý tín hiệu

* **Cú pháp:**

		#include <signal.h>

		int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);

	* **signum:** Số tín hiệu hoặc macro như `SIGINT`, `SIGTERM`,`SIGCHLD`,`SIGSEGV`
	
	* **act:** Con trỏ tới cấu trúc `struct sigaction` chứa thông tin handler mới (nếu NULL thì chỉ lấy thông tin cũ).
	
	* **oldact:** Con trỏ để lưu handler  (nếu NULL thì không quan tâm).

* **Giá trị trả về:**

	* 0 -> Thành công
	
	* -1 -> Lỗi và set `errno` 
		
*  **Cấu trúc struct sigaction:**
		
		struct sigaction {
		    void (*sa_handler)(int);               						// Handler đơn giản (giống signal())
		    void (*sa_sigaction)(int, siginfo_t *, void *);  // Handler nâng cao (khi SA_SIGINFO)
		    sigset_t sa_mask;                      					// Tín hiệu bị block trong handler
		    int sa_flags;                          					// Cờ điều khiển hành vi (SA_RESTART, SA_SIGINFO...)
		    void (*sa_restorer)(void);            					 // Không dùng nữa (deprecated)
		};
	
####  **3.2. Mặt nạ tín hiệu và sa_mask**

* Mỗi tiến trình có một "mặt nạ tín hiệu" (signal mask) - tập hợp các tín hiệu hiện đang bị chặn.

* Một tín hiệu bị chặn sẽ ở trạng thái "chờ" (pending) và chỉ được phân phối sau khi được bỏ chặn.

* **Cơ chế sa_mask:**

	* Trước khi gọi hàm xử lý `sa_handler` hoặc `sa_sigaction`, kernel tự động thêm tập tín hiệu trong `sa_mask` vào mặt nạ của tiến trình.
	
	* Khi hàm xử lý kết thúc, mặt nạ cũ sẽ được tự động khôi phục.    
	
		* Điều này đảm bảo hàm xử lý không bị gián đoạn bởi chính nó hoặc các tín hiệu khác, ngăn chặn race condition. 
		
	* Tín hiệu đang được xử lý (`signum`) cũng luôn bị chặn mặc định (trừ khi dùng cờ `SA_NODEFER`). 

				
* **Các cờ điều khiển hành vi (sa_flags ):**

	| Cờ | Ý nghĩa | Khi nào dùng |  
	|---------------|------------------------------------------------------------------------|------------------------------------------------------------------------------|  
	| SA_RESTART | System call bị interrupt (như `read()`, `write()`, `accept()`) sẽ tự động restart | Tránh lỗi `EINTR` khi thao tác I/O chậm (socket, pipe, terminal input...) |  
	| SA_SIGINFO | Dùng `sa_sigaction` thay vì `sa_handler`, nhận thêm `siginfo_t` | Khi cần thông tin chi tiết: sender PID, UID, fault address (`SIGSEGV`) |  
	| SA_NOCLDSTOP | Không gửi `SIGCHLD` khi child bị `SIGSTOP` / `SIGTSTP` (chỉ khi terminate) | Tránh nhận `SIGCHLD` thừa trong process manager / shell-like program |  
	| SA_NODEFER | Không tự động block signal hiện tại trong lúc handler đang chạy | Hiếm dùng; chỉ khi cần cho phép signal lồng nhau (cực kỳ cẩn thận) |
		

####  **3.3. VD**

* Ví dụ này cho phép handler in ra PID của tiến trình đã gửi tín hiệu `SIGUSR1` hoặc `SIGTERM`

		#include <stdio.h>
		#include <signal.h>
		#include <stdlib.h>
		#include <unistd.h>

		void advanced_handler(int sig, siginfo_t *info, void *ucontext){
			 printf("\n[+] Nhận tín hiệu: %d\n", sig);
			 printf("    Gửi bởi PID: %ld\n", (long)info->si_pid);
			 printf("    Gửi bởi UID: %ld\n", (long)info->si_uid);			
	
			if (sig == SIGTERM){
			 printf("    Đang thoát...\n");
			 _exit(0);
			 }
			 // Không nên dùng printf trong handler thực tế, chỉ dùng cho mục đích demo
			}				

		 int main(){
		  struct sigaction sa;
		
		  //1. Chọn handler nâng cao
		  sa.sa_sigaction = advanced_handler;

			//2. Xóa sạch mặt nạ tạm thời (không block thêm tín hiệu nào)
			sigemptyset(&sa.sa_mask);

			//3. Bật các cờ SA_SIGINFO để dùng handler nâng cao và SA_RESTART 
			sa.sa_flags = SA_SIGINFO | SA_RESTART;

			//4. Đăng ký cho SIGUSR1 và SIGTERM
			 if (sigaction(SIGUSR1, &sa, NULL) == -1) {
			 perror("sigaction SIGUSR1");
			 exit(1);
			 }
			 if (sigaction(SIGTERM, &sa, NULL) == -1) {
			 perror("sigaction SIGTERM");
			 exit(1);
			 }
			 printf("PID: %d. Đang chờ tín hiệu...\n", getpid());
			 printf("Thử gửi: kill -USR1 %d hoặc kill -TERM %d\n", getpid(), getpid());
			 while (1) pause(); // Dừng chương trình để chờ tín hiệu
			 return 0;
			}			
		


####  **3.4. Chặn tín hiệu với sigprocmask()**

* Cho phép thao tác trực tiếp với mặt nạ tín hiệu của tiến trình để bảo vệ các đoạn mã nguồn quan trọng

* **Cú pháp:**  `int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);`

* **Các hàm thao tác trên sigset_t:** 
	
	* `sigemptyset(sigset_t *set)`: Xóa hết tín hiệu trong set
	
	* `sigfillset(sigset_t *set)`: Thêm tất cả tín hiệu
	
	* `sigaddset(sigset_t *set, int signum):` Thêm một tín hiệu 
	
	* `sigdelset(sidset_t *set, int signum):` Xóa một tín hiệu 
	
	* `sigismember(const sigset_t *set, int signum):` Kiểm tra có trong set không   

* VD:
		
		sigset_t block_set, old_set;
		sigemptyset(&block_set);
		sigaddset(&block_set, SIGINT); // Muốn chặn Ctrl+C

		printf("Đang vào critical section (5 giây), Ctrl+C sẽ bị pending...\n");
		sigprocmask(SIG_BLOCK, &block_set, &old_set);
		sleep(5); // Mô phỏng công việc quan trọng
		printf("Đã rời khỏi critical section.\n");

		sigprocmask(SIG_SETMASK, &old_set, NULL); // Khôi phục mặt nạ cũ
		// Nếu có SIGINT pending, nó sẽ được xử lý ngay tại đây		

### **IV. TÍNH AN TOÀN TRONG HÀM XỬ LÝ TÍN HIỆU**

####  **4.1. Reentrancy và Async-Signal-Safety**

* Một tín hiệu có thể đến giữa chừng khi chương trình đang gọi một hàm không tái nhập (ví dụ: `printf`, `malloc`, `free`).

* Nếu hàm xử lý tín hiệu cũng gọi chính hàm đó, nó sẽ làm hỏng trạng thái nội bộ của hàm, dẫn đến deadlock hoặc crash.

* Ví dụ: `printf` dùng một buffer toàn cục và cơ chế khóa, gọi nó từ handler trong khi `main` cũng đang `printf` là cực kỳ nguy hiểm.

* Chỉ sử dụng các hàm được POSIX chứng nhận là **Async-Signal-Safe** (an toàn để gọi từ bên trong hàm xử lý tín hiệu một cách bất đồng bộ)

* Các hàm **Async-Signal-Safe**:

	* `_exit()` (không phải `exit()`)
	
	*  `write()` (không phải `printf()` hay `fwrite()`)   
	
	*   `read()` 
	
	*  `kill()`
	
	*  `signal()`, `sigaction()`
	
	*  `getpid()`, `getuid()`
	
	*  `alarm()`    

####  **4.2. Cờ hiệu volatile sig_atomic_t**

* **`sig_atomic_t`:**

	* Đây là kiểu dữ liệu số nguyên (do hệ thống định nghĩa) mà các thao tác đọc và ghi trên nó là nguyên tử (atomic), nghĩa là không thể bị gián đoạn dở chừng
	
	* Điều này đảm bảo không có race condition khi handler ghi và chương trình chính đọc  
	
* **`volatile`:**

	* Từ khóa này báo cho trình biên dịch biết giá trị của biến có thể thay đổi bất ngờ từ một luồng khác (hoặc từ handler).
	
	* Điều này ngăn trình biên dịch thực hiện các tối ưu hóa nguy hiểm, như lưu giá trị của biến vào thanh ghi CPU và đọc từ đó thay vì đọc từ bộ nhớ chính.
	
* **VD:**

		#include <stdio.h>
		#include <signal.h>
		#include <unistd.h>

		// Biến cờ toàn cục với volatile sig_atomic_t
		volatile sig_atomic_t got_sighup = 0;
		volatile sig_atomic_t keep_running = 1;

		// Hàm xử lý tối giản: chỉ đặt cờ
		void sighup_handler(int sig) {
		    got_sighup = 1;
		}

		void sigterm_handler(int sig) {
		    keep_running = 0; // Yêu cầu vòng lặp chính dừng lại
		}

		int main() {
		    // Đăng ký các handler tối giản
		    signal(SIGHUP, sighup_handler);
		    signal(SIGTERM, sigterm_handler);

		    printf("PID: %d. Đang chạy...\n", getpid());

		    while (keep_running) {
		        // Vòng lặp chính kiểm tra cờ một cách an toàn
		        if (got_sighup) {
		            got_sighup = 0; // Reset cờ
		            // Thực hiện hành động thực tế (an toàn vì đang ở main)
		            printf("[Main] Đã nhận SIGHUP, đang tải lại cấu hình...\n");
		            // reload_configuration();
		        }
		        // Công việc bình thường của chương trình
		        printf("Đang làm việc...\n");
		        sleep(1);
		    }

		    printf("[Main] Nhận tín hiệu dừng, đang thoát an toàn.\n");
		    // Dọn dẹp tài nguyên và thoát
		    return 0;
		} 

				
   </details> 

   
   

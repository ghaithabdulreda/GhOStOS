#define VIDEO_BUF_PTR 0xb8000
#define VIDEO_WIDTH (80) 
#define VIDEO_HEIGHT (25)
#define CURSOR_PORT (0x3D5) 
#define PIC1_PORT (0x20)       


int position = 0;  // متغير لحفظ الموضع الحالي للكتابة في شاشة الفيديو

void printf(const char* str1);
void clear();  // دالة لمسح الشاشة
void scanf(char* input);  // دالة لقراءة الإدخال من لوحة المفاتيح

static inline unsigned char inb(unsigned short port);
static inline void outb(unsigned short port, int data);

inline void strcmp();

const char* scancodeInputData(char scancode) {
    switch(scancode) {
        case 0x00: 
            return "ERROR";
        case 0x01: 
            return "ESC";
        case 0x02: 
            return "1";
        case 0x03: 
            return "2";
        case 0x04: 
            return "3";
        case 0x05: 
            return "4";
        case 0x06: 
            return "5";
        case 0x07: 
            return "6";
        case 0x08: 
            return "7";
        case 0x09: 
            return "8";
        case 0x0A: 
            return "9";
        case 0x0B: 
            return "0";
        case 0x0C: 
            return "-";
        case 0x0D: 
            return "=";
        case 0x0E: 
            return "BACKSPACE";
        case 0x0F: 
            return "TAB";
        case 0x10: 
            return "Q"; // Uppercase
        case 0x11: 
            return "W"; // Uppercase
        case 0x12: 
            return "E"; // Uppercase
        case 0x13: 
            return "R"; // Uppercase
        case 0x14: 
            return "T"; // Uppercase
        case 0x15: 
            return "Y"; // Uppercase
        case 0x16: 
            return "U"; // Uppercase
        case 0x17: 
            return "I"; // Uppercase
        case 0x18: 
            return "O"; // Uppercase
        case 0x19: 
            return "P"; // Uppercase
        case 0x1A: 
            return "["; // Uppercase
        case 0x1B: 
            return "]"; // Uppercase
        case 0x1C: 
            return "ENTER";
        case 0x1D: 
            return "CONTROL";
        case 0x1E: 
            return "A"; // Uppercase
        case 0x1F: 
            return "S"; // Uppercase
        case 0x20: 
            return "D"; // Uppercase
        case 0x21: 
            return "F"; // Uppercase
        case 0x22: 
            return "G"; // Uppercase
        case 0x23: 
            return "H"; // Uppercase
        case 0x24: 
            return "J"; // Uppercase
        case 0x25: 
            return "K"; // Uppercase
        case 0x26: 
            return "L"; // Uppercase
        case 0x27: 
            return ";"; // Uppercase
        case 0x28: 
            return "'"; // Uppercase
        case 0x29: 
            return "`"; // Uppercase
        case 0x2A: 
            return "SHIFT";
        case 0x2B: 
            return "\\"; // Uppercase
        case 0x2C: 
            return "Z"; // Uppercase
        case 0x2D: 
            return "X"; // Uppercase
        case 0x2E: 
            return "C"; // Uppercase
        case 0x2F: 
            return "V"; // Uppercase
        case 0x30: 
            return "B"; // Uppercase
        case 0x31: 
            return "N"; // Uppercase
        case 0x32: 
            return "M"; // Uppercase
        case 0x33: 
            return ","; // Uppercase
        case 0x34: 
            return "."; // Uppercase
        case 0x35: 
            return "/"; // Uppercase
        case 0x36: 
            return "SHIFT";
        case 0x37: 
            return "*"; // Numeric keypad
        case 0x38: 
            return "ALT"; // Alternate key
        case 0x39: 
            return "SPACE";
        case 0x3A: 
            return "CAPSLOCK";
        case 0x3B: 
            return "F1";
        case 0x3C: 
            return "F2";
        case 0x3D: 
            return "F3";
        case 0x3E: 
            return "F4";
        case 0x3F: 
            return "F5";
        case 0x40: 
            return "F6";
        case 0x41: 
            return "F7";
        case 0x42: 
            return "F8";
        case 0x43: 
            return "F9";
        case 0x44: 
            return "F10";
        case 0x45: 
            return "NUMLOCK";
        case 0x46: 
            return "SCROLLLOCK";
        case 0x47: 
            return "7"; // Numeric keypad
        case 0x48: 
            return "8"; // Numeric keypad
        case 0x49: 
            return "9"; // Numeric keypad
        case 0x4A: 
            return "-"; // Numeric keypad
        case 0x4B: 
            return "4"; // Numeric keypad
        case 0x4C: 
            return "5"; // Numeric keypad
        case 0x4D: 
            return "6"; // Numeric keypad
        case 0x4E: 
            return "+"; // Numeric keypad
        case 0x4F: 
            return "1"; // Numeric keypad
        case 0x50: 
            return "2"; // Numeric keypad
        case 0x51: 
            return "3"; // Numeric keypad
        case 0x52: 
            return "0"; // Numeric keypad
        case 0x53: 
            return "."; // Numeric keypad
        
   

        default: 
            return "UNKNOWN";
    }
}


// دالة لطباعة نص على الشاشة
void printf(const char* str1) {
    volatile char* video_memory = (volatile char*) VIDEO_BUF_PTR;
    unsigned char color = 7;  // اللون الافتراضي للنص (رمادي على أسود)

    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] == '\n') {
            int line_size = 80;  // الانتقال إلى السطر التالي
            position = (position / (line_size * 2) + 1) * (line_size * 2);  // الانتقال للسطر الجديد
        } else {
            video_memory[position] = str1[i];      // الحرف
            video_memory[position + 1] = color;   // اللون
            position += 2;  // الانتقال إلى الموقع التالي
        }
        
        // التأكد من عدم تجاوز نهاية الشاشة
        if (position >= VIDEO_WIDTH * VIDEO_HEIGHT * 2) {
            clear();  // مسح الشاشة إذا امتلأت
            position = 0;
        }
    }
}

// دالة لمسح الشاشة
void clear() {
    volatile char* video_memory = (volatile char*) VIDEO_BUF_PTR;
    unsigned char color = 7;  // اللون الافتراضي للنص

    for (int i = 0; i < 80 * 25 * 2; i += 2) {
        video_memory[i] = ' ';      // تعيين الحرف كمسافة
        video_memory[i + 1] = color;   // تعيين اللون
    }

    position = 0;  // إعادة تعيين المؤشر إلى البداية
}


void scanf(char* input, int max_size) {
    int p = 0; // مؤشر لحفظ موضع الإدخال
    unsigned char scan_code;

    while (1) {
        // تحقق مما إذا كان هناك بيانات جديدة في PS/2
        if (inb(0x64) & 0x01) {
            scan_code = inb(0x60);
            if (scan_code < 128) {
            	const char* char_input = scancodeInputData(scan_code);
            	if (char_input == "ENTER")
            		break;
            	else
            		printf(char_input);
            	input[p] = char_input[0];
            	p++;
            }
        }

        // الخروج إذا كانت المصفوفة ممتلئة
        if (p >= max_size - 1) {
            break; // المصفوفة ممتلئة، الخروج من الحلقة
        }
    }
    
    input[p] = '\0'; // إضافة علامة نهاية السلسلة
}

inline void strcmp(){

}


// تعريف دوال inb و outb
static inline unsigned char inb(unsigned short port) {
    unsigned char ret;
    __asm__ __volatile__("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

static inline void outb(unsigned short port, int data) {
    __asm__ __volatile__("outb %0, %1" : : "a"(data), "Nd"(port));
}

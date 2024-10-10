#include "cpp/io/stdio.cpp"
#define COMMAND_COUNT 6

void check_execute(char* str);

const char* commands[COMMAND_COUNT] = {
    "LS",
    "pwd",
    "whoami",
    "s",
    "A",
    "a",
};

// دالة مقارنة السلاسل
int my_strcmp(const char* str1, const char* str2) {
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }

    return str1[i] - str2[i];
}

// الدالة الرئيسية
extern "C" void main() {
    clear();

    const char* str1 = "Kernel Start...\n";
    printf(str1);

    const char* str2 = "Please Wait...\n";
    printf(str2);

    clear();

    char input[50];
    while (1) {
        printf("\nEnter your text: ");
        scanf(input, sizeof(input));  // تأكد من استخدام الحجم الصحيح
        if (my_strcmp(input, input) == 0) { // يجب تعديل شرط المقارنة هنا
            printf(input);
        }
    }

    return;
}

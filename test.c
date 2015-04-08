#include "base-conv.h"
#include <string.h>
#include <assert.h>

void test_parse(void) {
    unsigned int parsed;
    parse_number("1234", 10, &parsed);
    assert(parsed == 1234);

    parse_number("DEADBEEF", 16, &parsed);
    assert(parsed == 0xDEADBEEF);

    assert(parse_number("!", 10, &parsed));
}

void test_serialize(void) {
    char buf[65];

    assert(strcmp(serialize_number(1234, 10, buf), "1234") == 0);
    assert(strcmp(serialize_number(0xDEADBEEF, 16, buf), "DEADBEEF") == 0);
}

void test_digit_char(void) {
    assert(char_to_digit('A') == 10);
    assert(char_to_digit('3') == 3);

    assert(digit_to_char(35) == 'Z');
    assert(digit_to_char(10) == 'A');
}


int main(void) {
    test_parse();
    test_serialize();
    test_digit_char();

    return 0;
}

#include <REGX51.H>

void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 1275; j++);  // Approximate 1ms delay
}

// 7-segment codes for digits 0–9 (Common Cathode)
// Format: g-f-e-d-c-b-a (P2.6 to P2.0)
unsigned char seg_codes[10] = {
    0x3F,  // 0 ? 0011 1111
    0x06,  // 1 ? 0000 0110
    0x5B,  // 2 ? 0101 1011
    0x4F,  // 3 ? 0100 1111
    0x66,  // 4 ? 0110 0110
    0x6D,  // 5 ? 0110 1101
    0x7D,  // 6 ? 0111 1101
    0x07,  // 7 ? 0000 0111
    0x7F,  // 8 ? 0111 1111
    0x6F   // 9 ? 0110 1111
};

void main() {
    unsigned char i;

    while (1) {
        for (i = 0; i < 10; i++) {
            P2 = seg_codes[i];  // Output to P2.0–P2.6
            delay_ms(50);     // delay
        }
    }
}

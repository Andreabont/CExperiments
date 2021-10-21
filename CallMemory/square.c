#include <stdio.h>
#include <string.h>
#include <sys/mman.h>

// Prototipo della chiamata
typedef int square_t(int);

// Codice della chiamata
unsigned char square_code[] = {
    0x55, 
    0x48, 0x89, 0xE5, 
    0x89, 0x7D, 0xFC,
    0x89, 0x7D, 0xFC,
    0x0F, 0xAF, 0x7D, 0xFC,
    0x89, 0xF8,
    0x5D,
    0xC3
};


int main() {

    // Alloco un blocco di memoria dell'heap che sia eseguibile.
    void *square_memory =  mmap(0, sizeof(square_code), PROT_READ|PROT_WRITE|PROT_EXEC, MAP_PRIVATE|MAP_ANON, -1, 0);
    
    // Copio il codice nella memoria allocata
    memcpy (square_memory, square_code, sizeof(square_code));

    // Eseguo la chiamata attraverso un cast al prototipo.
    int a = ((square_t*) square_memory) (2);

    printf("Result: %d \n", a);

}

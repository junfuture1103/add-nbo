#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{

int len;
uint8_t buf1[32];
uint8_t buf2[32];

FILE *f1, *f2;

f1 = fopen(argv[1], "r");
fread(buf1, 1, 4, f1);
uint32_t* p1 = reinterpret_cast<uint32_t*>(buf1);
uint32_t n1 = htonl(*p1);

f2 = fopen(argv[2], "r");
fread(buf2, 1, 4, f2);
uint32_t* p2 = reinterpret_cast<uint32_t*>(buf2);
uint32_t n2 = htonl(*p2);


printf("this is content of buf1 : %x \n", n1);
printf("this is content of buf2 : %x \n", n2);

printf("%d(%x) + %d(%x) = %d(%x)\n", n1, n1, n2, n2, n1+n2, n1+n2);


fclose(f1);
fclose(f2);

return 0;
}

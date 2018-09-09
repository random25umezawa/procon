#include <stdio.h>
#include <stdlib.h>
int main() {
	for(int i = 0; i < 100; i++) printf("%x\n",rand()&0x1);
}

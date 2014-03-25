#include <cstdlib>
#include <assert.h>
#include <stdint.h>
#include <cstring>
#include <cstdio>

void* memcpy_n(void* src, size_t bytes, void *dest){
    //assert(src+bytes>dest&&dest+bytes>src);
    
    //speed up copying.
    size_t n_32 = bytes/sizeof(uint32_t);
    uint32_t *p32 = (uint32_t*) src;
    uint32_t *p32_dest = (uint32_t*) dest;

    while (n_32){
        *(p32_dest++)=*(p32++);
        n_32--;
    }

    size_t n_8 = bytes%sizeof(uint32_t);
    char *p8src = (char*) p32;
    char *p8dest = (char*) p32_dest;
    while (n_8){
        *(p8dest++)=*(p8src++);
        n_8--;
    }
    return dest;
}
        
        
int main(){
    char str[] = "The quick brownjumps over the lazy dog.";
    char strDest[100];
    memcpy_n(str,strlen(str),strDest);
    printf("%d\n%s\n",strlen(str),strDest);
}

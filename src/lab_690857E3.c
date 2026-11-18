#include <stdio.h>
#include <string.h>

void copy(char *psource, char *ptarget, unsigned num_char)
{
    unsigned count = 0;
    while (count < num_char && *psource != '\0') {
        *ptarget = *psource;
        ptarget++;
        psource++;
        count++;
    }
    *ptarget = '\0';
}

void concatenate(char *psrc1, char *psrc2, char *ptarget, unsigned buffer_size)
{
    unsigned len1;
    len1 = (unsigned)strlen(psrc1);
    if (len1 > buffer_size - 1) {
        len1 = buffer_size - 1;
    }
    copy(psrc1, ptarget, len1);
    if (len1 < buffer_size - 1) {
        copy(psrc2, ptarget + len1, buffer_size - 1 - len1);
    }
}

// DO NOT change the code below
#ifndef ___TEST___
int main(void)
{
    char buffer[100];
    char *source = "This is the first sentence.  ";
    char *target = "This is the second sentence.";

    concatenate(source, target, buffer, 70);

    printf("%s", buffer);
    return 0;
}
#endif
// DO NOT change the code above

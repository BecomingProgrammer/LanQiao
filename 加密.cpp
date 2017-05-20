#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void f(char* buf, unsigned char* uckey, int n)
{
    int i;
    for(i=0; i<n; i++)
        buf[i] = buf[i] ^ uckey[i];
}

int main()
{
    char p[] = "abcd中国人123";  // 待加密串

    char* key = "11001100010001110";  //以串的形式表达的密匙，运算时要转换为按位存储的形式。

    int np = strlen(p);
    int nk = strlen(key);
    unsigned char* uckey = (unsigned char*)malloc(np);  

    // 密匙串需要按位的形式循环拼入 uckey中
    int i;
    for(i=0; i<np*8; i++)
    {
        if(key[i%nk]=='1')
           uckey[i/8]=uckey[i/8]*2+1;  // 填空1
        else
            uckey[i/8]*=2;  // 填空2

    }

    f(p, uckey, strlen(p));
    f(p, uckey, strlen(p));

    printf("%s\n", p);

    free(uckey);

    return 0;
}

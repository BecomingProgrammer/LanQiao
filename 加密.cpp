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
    char p[] = "abcd�й���123";  // �����ܴ�

    char* key = "11001100010001110";  //�Դ�����ʽ�����ܳף�����ʱҪת��Ϊ��λ�洢����ʽ��

    int np = strlen(p);
    int nk = strlen(key);
    unsigned char* uckey = (unsigned char*)malloc(np);  

    // �ܳ״���Ҫ��λ����ʽѭ��ƴ�� uckey��
    int i;
    for(i=0; i<np*8; i++)
    {
        if(key[i%nk]=='1')
           uckey[i/8]=uckey[i/8]*2+1;  // ���1
        else
            uckey[i/8]*=2;  // ���2

    }

    f(p, uckey, strlen(p));
    f(p, uckey, strlen(p));

    printf("%s\n", p);

    free(uckey);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

unsigned int f(unsigned int x,unsigned int y, unsigned int z);
unsigned int g(unsigned int x,unsigned int y, unsigned int z);
unsigned int h(unsigned int x,unsigned int y, unsigned int z);
unsigned int I(unsigned int x,unsigned int y, unsigned int z);
unsigned int CircleLeftShift(unsigned int x,unsigned int N);
void DevM(char *source);
unsigned int calcuMain(int t);
unsigned int hexToDec(char *source);
int getIndexOfSigns(char ch);
int bitValue(unsigned int value,int n);

unsigned int AA = 0x67452301;
unsigned int BB = 0xefcdab89;
unsigned int CC = 0x98badcfe;
unsigned int DD = 0x10325476;

unsigned int M[16];

unsigned int f(unsigned int x,unsigned int y, unsigned int z){return (x&y)|(~x&z);}
unsigned int g(unsigned int x,unsigned int y, unsigned int z){return (z&x)|(~z&y);}
unsigned int h(unsigned int x,unsigned int y, unsigned int z){return x^y^z;}
unsigned int I(unsigned int x,unsigned int y, unsigned int z){return y^(x|~z);}

unsigned int CircleLeftShift(unsigned int x,unsigned int N){return (x << N) | (x >> (32 - N));}

void DevM(char *source){
    int i,j = 0;
    for(i = 0; i < 128; i=i+8){
        char temp[8];
        temp[0] = *(source + i);
        temp[1] = *(source + i+1);
        temp[2] = *(source + i+2);
        temp[3] = *(source + i+3);
        temp[4] = *(source + i+4);
        temp[5] = *(source + i+5);
        temp[6] = *(source + i+6);
        temp[7] = *(source + i+7);
        M[j] = hexToDec(temp);
        j++;
    }
}

unsigned int hexToDec(char *temp)
{
    unsigned int sum = 0;
    unsigned int  t = 1;
    int i;
    // 小端法16进制
    for(i=7; i>=0; i--)
    {
        sum += t * getIndexOfSigns(*(temp + i));
        t *= 16;
    }

    return sum;
}


int getIndexOfSigns(char ch)
{
    if(ch >= '0' && ch <= '9')
    {
        return ch - '0';
    }
    if(ch >= 'A' && ch <='F')
    {
        return ch - 'A' + 10;
    }
    if(ch >= 'a' && ch <= 'f')
    {
        return ch - 'a' + 10;
    }
    return -1;
}

unsigned int ff(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int Mj, unsigned int s, unsigned int Ti) {
unsigned int temp = a + f(b, c, d) + Mj + Ti;
	a = b + CircleLeftShift(temp, s);
	return a;
}
unsigned int gg(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int Mj, unsigned int s, unsigned int Ti) {
	unsigned int temp = a + g(b, c, d) + Mj + Ti;
	a = b + CircleLeftShift(temp, s);
	return a;
}
unsigned int hh(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int Mj, unsigned int s, unsigned int Ti) {
	unsigned int temp = a + h(b, c, d) + Mj + Ti;
	a = b + CircleLeftShift(temp, s);
	return a;
}
unsigned int II(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int Mj, unsigned int s, unsigned int Ti) {
	unsigned int temp = a + I(b, c, d) + Mj + Ti;
	a = b + CircleLeftShift(temp, s);
	return a;
}

void CalcuStatus (char *str){

        DevM(str);
        unsigned int A = AA;
		unsigned int B = BB;
		unsigned int C = CC;
		unsigned int D = DD;
		A = ff(A, B, C, D, M[0], 7, 0xD76AA478);
		D = ff(D, A, B, C, M[1], 12, 0xe8C7B756);
		C = ff(C, D, A, B, M[2], 17, 0x242070DB);
		B = ff(B, C, D, A, M[3], 22, 0xC1BDCeee);

		A = ff(A, B, C, D, M[4], 7, 0xf57C0fAf);
		D = ff(D, A, B, C, M[5], 12, 0x4787C62A);
		C = ff(C, D, A, B, M[6], 17, 0xA8304613);
		B = ff(B, C, D, A, M[7], 22, 0xfD469501);

		A = ff(A, B, C, D, M[8], 7, 0x698098D8);
		D = ff(D, A, B, C, M[9], 12, 0x8B44f7Af);
		C = ff(C, D, A, B, M[10], 17, 0xffff5BB1);
		B = ff(B, C, D, A, M[11], 22, 0x895CD7Be);

		A = ff(A, B, C, D, M[12], 7, 0x6B901122);
		D = ff(D, A, B, C, M[13], 12, 0xfD987193);
		C = ff(C, D, A, B, M[14], 17, 0xA679438e);
		B = ff(B, C, D, A, M[15], 22, 0x49B40821);


		A = gg(A, B, C, D, M[1], 5, 0xf61e2562);
		D = gg(D, A, B, C, M[6], 9, 0xC040B340);
		C = gg(C, D, A, B, M[11], 14, 0x265e5A51);
        B = gg(B, C, D, A, M[0], 20, 0xe9B6C7AA);
		A = gg(A, B, C, D, M[5], 5, 0xD62f105D);
		D = gg(D, A, B, C, M[10], 9, 0x2441453);
		C = gg(C, D, A, B, M[15], 14, 0xD8A1e681);
		B = gg(B, C, D, A, M[4], 20, 0xe7D3fBC8);
		A = gg(A, B, C, D, M[9], 5, 0x21e1CDe6);
		D = gg(D, A, B, C, M[14], 9, 0xC33707D6);
		C = gg(C, D, A, B, M[3], 14, 0xf4D50D87);
		B = gg(B, C, D, A, M[8], 20, 0x455A14eD);
		A = gg(A, B, C, D, M[13], 5, 0xA9e3e905);
		D = gg(D, A, B, C, M[2], 9, 0xfCefA3f8);
		C = gg(C, D, A, B, M[7], 14, 0x676f02D9);
		B = gg(B, C, D, A, M[12], 20, 0x8D2A4C8A);

		A = hh(A, B, C, D, M[5], 4, 0xfffA3942);
		D = hh(D, A, B, C, M[8], 11, 0x8771f681);
		C = hh(C, D, A, B, M[11], 16, 0x6D9D6122);
		B = hh(B, C, D, A, M[14], 23, 0xfDe5380C);
		A = hh(A, B, C, D, M[1], 4, 0xA4BeeA44);
		D = hh(D, A, B, C, M[4], 11, 0x4BDeCfA9);
		C = hh(C, D, A, B, M[7], 16, 0xf6BB4B60);
		B = hh(B, C, D, A, M[10], 23, 0xBeBfBC70);
		A = hh(A, B, C, D, M[13], 4, 0x289B7eC6);
		D = hh(D, A, B, C, M[0], 11, 0xeAA127fA);
		C = hh(C, D, A, B, M[3], 16, 0xD4ef3085);
		B = hh(B, C, D, A, M[6], 23, 0x4881D05);
		A = hh(A, B, C, D, M[9], 4, 0xD9D4D039);
		D = hh(D, A, B, C, M[12], 11, 0xe6DB99e5);
		C = hh(C, D, A, B, M[15], 16, 0x1fA27Cf8);
		B = hh(B, C, D, A, M[2], 23, 0xC4AC5665);

		A = II(A, B, C, D, M[0], 6, 0xf4292244);
		D = II(D, A, B, C, M[7], 10, 0x432Aff97);
		C = II(C, D, A, B, M[14], 15, 0xAB9423A7);
        B = II(B, C, D, A, M[5], 21, 0xfC93A039);

		A = II(A, B, C, D, M[12], 6, 0x655B59C3);
		D = II(D, A, B, C, M[3], 10, 0x8f0CCC92);
		C = II(C, D, A, B, M[10], 15, 0xffeff47D);
		B = II(B, C, D, A, M[1], 21, 0x85845DD1);

		A = II(A, B, C, D, M[8], 6, 0x6fA87e4f);
		D = II(D, A, B, C, M[15], 10, 0xfe2Ce6e0);
		C = II(C, D, A, B, M[6], 15, 0xA3014314);
		B = II(B, C, D, A, M[13], 21, 0x4e0811A1);

		A = II(A, B, C, D, M[4], 6, 0xf7537e82);
        int i = 0;
		for(i = 0; i <32; i++){
        printf("%d: ",i);
          printf("%d  ",bitValue(B,i));
		printf("%d\n",bitValue(A,i));
		}


		D = II(D, A, B, C, M[11], 10, 0xBD3Af235);
		C = II(C, D, A, B, M[2], 15, 0x2AD7D2BB);
		B = II(B, C, D, A, M[9], 21, 0xeB86D391);

		A += AA;
		B += BB;
		C += CC;
		D += DD;
}

int bitValue(unsigned int value,int n){
    return (value>>n)&1;
}

int main()
{
unsigned char str1[128] = "02dd31d1c4eee6c5069a3d695cf9af9807b5ca2fab7e46123e580440897ffbb80634ad5502b3f4098388e4835a41f125e82551089fc9cdf772bd1dd95b3c3780";
printf("一对近似碰撞块的最高为差分情况:\n");
printf("M':\n");
CalcuStatus(str1);

}

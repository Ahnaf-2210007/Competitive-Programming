```
<snippet>
    <content><![CDATA[
//to calculate modular inverse pass(a, mod-2, mod)
int binexp(int a, int b, int m) {
    int result = 1;
    while (b > 0) {
        if (b & 1) {
            result = (result * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return result;
}
]]></content>
    <tabTrigger>binModExpo</tabTrigger>
    <scope>source.c++</scope>
</snippet>

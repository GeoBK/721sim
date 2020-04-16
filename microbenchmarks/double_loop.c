int main(){
    int x=1;
    for(unsigned long long i = 0;i<100000;i++)
    {
        for(int j=0; j<20; j++)
        {
            x = x^0x0f0f;
        }
    }
    return x;
}
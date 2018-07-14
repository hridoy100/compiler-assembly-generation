int main(){
    int a,b,c[3];
    a=1*(2+3)%3;
    b= 1<5;
    c[0] = 3;
    c[1]= 3;
    if(a && b)
    {
        c[1]++;
    }
    else
    {
        c[1]=c[0];
    }
    println(a);
    println(b);
    a=c[0];
    println(a);
    a=c[1];
    println(a);
    
}

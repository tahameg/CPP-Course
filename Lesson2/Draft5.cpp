
int main(){
    int i = 14;
    void *vp;
    int *ip = &i;
    bool *bp;

    vp = ip; //valid in both languages
    //ip = vp //this is invalid in C++, valid in c
    ip = (int*)vp; //valid in both c and c++

    return 0;
}
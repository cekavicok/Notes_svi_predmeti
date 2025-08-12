static inline int min_int(int a, int b) { return (a < b) ? a : b; }



int FibonachiSearch(int* niz, int n, int key){
    int Fib2 = 0;
    int Fib1 = 1;
    int Fib0 = Fib2 + Fib1;

    while(Fib0 < n){
        Fib2 = Fib1;
        Fib1 = Fib0;
        Fib0 = Fib1 + Fib2;
    }

    int offset = -1;
    while(Fib0 > 0){
        int i = min_int(offset+Fib2, n-1);
        if(niz[i] == key){
            return i;
        }
        else if(niz[i] < key){
            Fib0 = Fib1;
            Fib1 = Fib2;
            Fib2 = Fib0 - Fib1;
            offset = i;
        }
        else{
            Fib0 = Fib2;
            Fib1 = Fib1 - Fib2;
            Fib2 = Fib0 - Fib1;
        }
    }

    if (Fib1 == 1 && offset + 1 < n && niz[offset + 1] == key) {
        return offset + 1;
    }

    return -1;
}
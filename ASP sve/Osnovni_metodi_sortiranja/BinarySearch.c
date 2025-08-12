int binSearch(const int* niz, int n, int key){
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = low + (high - low) / 2; //isto sto i mid = (low + high) / 2 samo pazi na overflow 
        if(niz[mid] == key) return mid;
        else if(niz[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1; // ako nismo nasli key
}


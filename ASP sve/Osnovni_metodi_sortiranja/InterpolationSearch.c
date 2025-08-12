int interpolaciono(const int* niz, int n, int key){
    if(!niz || n <= 0) return -1;
    
    int low = 0;
    int high = n-1;

    if(key < niz[low] || key > niz[high]) return -1;


    while(low <= high && key <= niz[high] && key >= niz[low]){
        if (niz[high] == niz[low]) {
            return (niz[low] == key) ? low : -1;
        }
        int mid = low + (key - niz[low])*(high - low) / (niz[high] - niz[low]);
        if (mid < low) mid = low; //ako mid kojim slucajem iskoci iako je jako tesko da se desi lol
        if (mid > high) mid = high;

        if (niz[mid] == key) {
            return mid;
        } else if (niz[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}
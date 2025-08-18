/*BASIC*/

int seqSearch(const int* niz, int key, int n){
    for(int i=0; i<n; i++){
        if(niz[i] == key){
            return i;
        }
    }
    return -1;
}


/*Sa kranicnikom (sentinelom lol)*/
/*varijanta 1*/

int seqSearchSenta(int* niz, int key, int n){
    niz[n] = key;
    int i = 0;
    while(niz[i] != key) i++;
    return (i<n) ? i : -1;
}

/*Sa kranicnikom (sentinelom lol)*/
/*varijanta 2*/

int seqSearchSentb(int* niz, int key, int n){
    int last = niz[n-1];
    niz[n-1] = key;
    int i = 0;
    while(niz[i] != key) i++;
    if(i<n) return i;
    return (last == key) ? (n-1) : -1;
}


/*Prebacivanje na pocetak i tranpozicija*/

/* prebaci element sa pozicije k na početak */
void move_to_front(int* niz, int k) {
    int t = niz[k];
    for (int i = k; i > 0; i--) niz[i] = niz[i-1];
    niz[0] = t;
}

/* transpozicija sa prethodnim */
void tranpozicija(int* niz, int k) {
    if (k > 0) {
        int t = niz[k]; niz[k] = niz[k-1]; niz[k-1] = t;
    }
}


/*Pretraga vise kljuceva nad uredjenim nizom*/

void seqSearchMul(const int* K, int n, const int* S, int m, int* rezultat){ //mul kao multiple jer trazimo vise kljuceva :) 
    int i = 0; //pokazivac u K (K su kljucevi)
    int j = 0; //pokazivac u S (S su kijevi tj njih trazimo)

    while(j < m && i < n){
        if(S[j] == K[i]){
            rezultat[j] = i;
            j++;
        }
        else if(S[j] > K[i]) {
            i++;
        }
        else{
            rezultat[j] = -1;
            j++;
        }
        

    }
    //svi preostali u S su veci od najveceg K sto znaci da nisu pronadjeni
    while(j < m){
        rezultat[j++] = -1; 
    }
}


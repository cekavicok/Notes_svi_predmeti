//ako uspe vraca oldHandler, ako ne uspe vraca SIG_ERR
//SIGHANDLER signal(int signal, SIGHANDLER newHandler);
//prvi argument signal ide na novi newHandler
#define pid_t int
#define handle_err(msg) do{printf("Error: %s\n", msg); exit(-1); } while(0) 
#define SIGTERM 67
#define SIG_ERR 68 //random skroz zbog greske isto
typedef void (*SIGHANDLER)(int);
SIGHANDLER signal(int signal, SIGHANDLER newHandler);
volatile int complete = 0;
void handler() {complete = 1;} //neki random handler da radi jer mi daje gresku c 


void main(){
    SIGHANDLER oldHandler = signal(SIGTERM, handler);
    if(oldHandler == SIG_ERR){
        handle_err("Signal handler error");
    }
    pid_t pid = fork();
    if(pid < 0) handle_err("Fork greska");
    else if(pid == 0){ //ulazak u dete
        while(1){
            while(!complete);
            printf("Are you sure you want to exit? (D/N)");
            int c = getchar();
            if (c == 'D' || c == 'd') exit(0);
            complete = 0;
        }
    }
    else {
        signal(SIGTERM, oldHandler);
        kill(pid, SIGTERM);
    }


}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>
#include <pthread.h>

#include <stdint.h>
#include <signal.h>
/* unix */
#include <unistd.h>
#include <fcntl.h>

#include <sys/time.h>
#include <sys/types.h>
#include <sys/termios.h>
#include <sys/mman.h>

struct infoVM{						
	int		noVM;
	unsigned char 	busy; 
	uint16_t * 	ptrDebutVM;	
	uint16_t   	offsetDebutCode; // region memoire ReadOnly
	uint16_t   	offsetFinCode;
	};								 

struct noeudVM{			
	struct infoVM	VM;		
	struct noeudVM		*suivant;	
	};	
	
void cls(void);
void error(const int exitcode, const char * message);

struct noeudVM * findItem(const int no);
struct noeudVM * findPrev(const int no);

void addItem();
void removeItem(const int noVM);
void listItems(const int start, const int end);
void saveItems(const char* sourcefname);
int executeFile(int noVM, char* sourcefname);

void* readTrans(char* nomFichier);

// paramM struct
struct paramM {
    int noVM;
    int Lmem ;

};

void modifier(struct paramM *param);


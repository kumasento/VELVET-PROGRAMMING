#include <cstdio>
#include <cstring>

#define MAXN 100000
#define TYPE int
#define cmp(x,y) ((x) < (y))
typedef struct _LT{
	struct _LT *c[2];
	TYPE v;
	int d;	
} LT, *PLT;

LT st[MAXN], *stp=st;

using namespace std;


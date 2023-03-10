#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int k;
    float g, p, ef;
}obiect;

typedef struct
{
    int fractionar;
    int n;
    float Gmax;
    obiect *v;
}rucsac;

int ordonare(const void *a, const void *b)
{
    obiect va=*(obiect *)a;
    obiect vb=*(obiect *)b;
    if(va.ef<vb.ef)
     return 1;
    if(va.ef==vb.ef)
     return 0;
     else
     return -1;
}

void citire(FILE *f, rucsac *r)
{
    int nr, frac;
    float gr;
    fscanf(f,"%d", &frac);
    fscanf(f, "%d %f", &nr, &gr);
    r->v = (obiect *) malloc(nr*sizeof(obiect));
    for(int i=0; i<nr; i++)
    {
        fscanf(f, "%f %f", &r->v[i].g, &r->v[i].p);
        r->v[i].ef = r->v[i].p/r->v[i].g;
        r->v[i].k=i;
    }
    r->fractionar=frac;
    r->n=nr;
    r->Gmax=gr;
}

void greedy(rucsac *r)
{
    float Gr;
    Gr = r->Gmax;
    for(int i=0; i<r->n&&Gr!=0; i++)
    {
        if(Gr>r->v[i].g)
        {
            printf("obiectul %d in cantitate 1\n", r->v[i].k);
            Gr=Gr-r->v[i].g;
        }
        else
        {
            if(r->fractionar){
            printf("obiectul %d in cantitate %f\n", r->v[i].k, Gr/r->v[i].g);
            Gr=0;
        }
        }
    }
}

int main()
{
    int n;
    float Gmax, Gr;
    rucsac *r=(rucsac *) malloc(sizeof(rucsac));
    FILE *f=fopen("greedy.txt", "r+");
    citire(f,r);
    qsort(r->v, r->n, sizeof(obiect), ordonare);
    greedy(r);
    return 0;
}

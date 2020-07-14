#include <stdio.h>
#include <string.h>
#define NEDELI 4
#define DENOVI 5

// ovde strukturata RabotnaNedela
typedef struct RabotnaNedela {
    int casovi[5];
    int br_nedela;
} RabotnaNedela;
typedef struct RabotnaNedela RN;

typedef struct Rabotnik { // ovde strukturata Rabotnik
    char ime[50];
    RN nedeli[4];
} Rabotnik;
typedef struct Rabotnik R;

// ovde funkciite
int CasoviNedela(int n, Rabotnik *r) {
    int i,vk=0;
    for(i=0; i<DENOVI; i++) {
        vk+=r->nedeli[n].casovi[i];
    }
    return vk;
}
int maxNedela(Rabotnik *r) {
    int max_indeks=0,j,max_casovi=0;
    for(int i=0; i<NEDELI; i++) {
        if (CasoviNedela(i, r )>max_casovi) {
            max_indeks=i;
            max_casovi=CasoviNedela(i,r);
        }
    }
    return max_indeks+1;
}
void table(Rabotnik *r, int n){
    int prva=0, vtora=0,treta=0,cetvrta=0,vk=0;
printf("Rab\t1\t2\t3\t4\tVkupno\n");
    for(int i=0;i<n;i++)
        {
        prva=CasoviNedela(0,&r[i]);
                vtora=CasoviNedela(1,&r[i]);
        treta= CasoviNedela(2,&r[i]);
                cetvrta=CasoviNedela(3,&r[i]);
        vk+=prva+vtora+treta+cetvrta;
            printf("%s\t%d\t%d\t%d\t%d\t%d\n", r[i].ime,prva,vtora,treta,cetvrta,vk);
        vk=0;
        }

}

int main() {
    int n;
    scanf("%d", &n);
    R rabotnici[n];
    int i;
    for (i = 0; i < n; ++i) {
        scanf("%s", rabotnici[i].ime);
        int j;
        for (j = 0; j < NEDELI; ++j) {
            int k;
            for (k = 0; k < DENOVI; ++k) {
                scanf("%d", &rabotnici[i].nedeli[j].casovi[k]);
            }

        }
    }
    printf("TABLE\n");
    table(rabotnici, n);
    printf("MAX NEDELA NA RABOTNIK: %s\n", rabotnici[n / 2].ime);
    printf("%d\n", maxNedela(&rabotnici[n / 2]));

    return 0;
}

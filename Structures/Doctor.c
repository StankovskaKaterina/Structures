#include<stdio.h>
typedef struct Pacient {
    char ime[100];
    int zdrastveno;
    int pregledi;
} Pacient;

typedef struct MaticenDoktor {
    char ime[100];
    int br_pac;
    Pacient niza[200];
    float cena;
} MaticenDoktor;
typedef struct MaticenDoktor doktor;

void najuspesen_doktor(MaticenDoktor *md,int n) {
    int i,j,doc=0,vk=0,tmp=0;
    float suma=1,max=0;
    for(i=0; i<n; i++) {
        suma=1;
        vk=0;
        for(j=0; j<md[i].br_pac; j++) {
            if (md[i].niza[j].zdrastveno==0) {
                vk+=md[i].niza[j].pregledi;
                suma*=md[i].cena*md[i].niza[j].pregledi;
            } else {
                vk+=md[i].niza[j].pregledi;
            }
        }
        if (suma >max) {
            doc=i;
            max=suma;
            tmp=vk;

        }
        if (suma == max) {
            if (tmp<vk) {
                doc=i;
                max=suma;
                tmp=vk;

            }
        }



    }
    printf("%s %.2f %d ",md[doc].ime,max,tmp);
}
int main() {
    int i, j, n, broj;
    doktor md[200];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        //ime na doktor
        scanf("%s", md[i].ime);
        //broj na pacienti
        scanf("%d", &md[i].br_pac);
        //cena na pregled
        scanf("%f", &md[i].cena);

        for (j = 0; j < md[i].br_pac; j++) {
            scanf("%s", md[i].niza[j].ime);
            scanf("%d", &md[i].niza[j].zdrastveno);
            scanf("%d", &md[i].niza[j].pregledi);
        }
    }
    najuspesen_doktor(md, n);

    return 0;
}

#include<stdio.h>
#include<string.h>

typedef struct SkiLift {
    char ime[15];
    int max_korisnici;
    int vo_funkcija;
} SkiLift;

typedef struct SkiCenter {
    char ime[20];
    char drzava[20];
    SkiLift niza[20];
    int br_liftovi;
} SkiCenter;
int kapacitet(SkiCenter sc) {
    int i,vk=0;
    for(i=0;i<sc.br_liftovi;i++){
        if (sc.niza[i].vo_funkcija){
        vk+=sc.niza[i].max_korisnici;
        }
    }
    return vk;
}
void najgolemKapacitet(SkiCenter *sc, int n) {
int i,max=0,max_br=0;
    for (i=0;i<n;i++){
        if ((kapacitet(sc[i])>max)|| (kapacitet(sc[i])==max&& sc[max_br].br_liftovi<sc[i].br_liftovi)){
        max=kapacitet(sc[i]);
            max_br=i;
        }
    }
    printf("%s\n%s\n%d\n", sc[max_br].ime,sc[max_br].drzava,max);
}
int main() {
    int i,j,n;
    SkiCenter sc[20];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", sc[i].ime);//vnesi ime
        scanf("%s",sc[i].drzava ); //vnesi drzava
        scanf("%d",&sc[i].br_liftovi ); //vnesi broj na liftovi


        for(j=0; j<sc[i].br_liftovi; j++) {
            //za sekoj ski lift vnesi:
            scanf("%s", sc[i].niza[j].ime); 	//vnesi ime
            scanf("%d", &sc[i].niza[j].max_korisnici);   //vnesi maksimalen broj korisnici
            scanf("%d", &sc[i].niza[j].vo_funkcija);  //vnesi dali e pusten vo funkcija
        }
    }
    najgolemKapacitet(sc,n);  //povik na funkcijata najgolemKapacitet

    return 0;
}

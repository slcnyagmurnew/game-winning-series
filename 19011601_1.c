#include <stdio.h>
#include <stdlib.h>

double game_winning(int n, double p) {
	double ** probability; // olasiliklarin tutulacagi matris
    probability = calloc(n + 1, sizeof * probability);
    int Awin, Bwin, k; // a takimi icin Awin b takimi icin Bwin degiskeni kullanilacak
    for(k = 0; k < n + 1; k++){ // matrise calloc ile yer aciliyor
    	probability[k] = calloc(n + 1, sizeof(double)); // calloc ile (satir kadar) sutunlar icin
	}
	
	for (Bwin= 1; Bwin<= n; Bwin++)
		/*
		a takiminin kazanma ihtimali hesaplanacagindan
		b takimininin kazanma ihtimalleri 1 ile ilklenir, hesaplamalar bunun uzerinden olacak
		*/
 		probability[0][Bwin] = 1.0;
 		
 	for (Awin = 1; Awin<=n; Awin++){
 		probability[Awin][0] = 0.0; // kazanma ihtimali hesaplanacak olan takim icin 0 ile ilkleme yapilir
 		for (Bwin=1; Bwin<= n; Bwin++) 
			/* 
			cikarilan rekurans bagintisina gore initial conditiondan hesaplama yapilarak
			ilgili indise hesaplanan sonuc yerlestirilir, bir oncekilerle toplanarak ilerlenecek
			*/
 	 		probability[Awin][Bwin] = p*probability[Awin-1][Bwin] +(1-p)*probability[Awin][Bwin-1];
   	}	
	// cikan matris sonucu yazdiriliyor
	printf("       ");
	for(Awin = 0; Awin<=n; Awin++)
		printf("j = %d  ", Awin);
	printf("\n");
	for(Awin = 0; Awin<=n; Awin++){
		printf("i = %d- ", Awin);
		for(Bwin = 0; Bwin<=n; Bwin++){
			printf("%.4lf ", probability[Awin][Bwin]);
		}
		printf("\n");
	}
	return probability[n][n]; // kullanicinin isterlerine gore hesaplanan sonuc dondurulur
}

int main(){
	int n; // bir takimin seriyi kazanmasi icin kazanmasi gereken toplam mac sayisi
	double p; // A takiminin bir maci kazanma olasiligi, kullanicidan alinir
	printf(" Enter the number of wins to win the game series : ");
	scanf("%d",&n);
	printf(" Enter the probability of team A winning :");
	scanf("%lf",&p);
	printf("\n Probability of team A winning the game series---> %.4lf ", game_winning(n, p));
	
	return 0;
}



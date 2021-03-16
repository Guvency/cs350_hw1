#include <stdio.h>

struct yemek{
       char *yemekIsim;
       int puan;
       };
       
struct yemek dizi_yemek[5];
struct yemek dizi_yemek_tur_2[5];
struct yemek enBuyuk;


int kebab = 0;
int burger = 0;
int pasta = 0;
int lahmacun = 0;
int salad = 0;
int en_buyuk = 0;
int dizi[] = {0, 0, 0, 0, 0}; 
int siralanmis_dizi[] = {0, 0, 0, 0, 0}; 

char kebab_C[] = "Kebab";
char burger_C[] = "Burger";
char pasta_C[] = "Pasta";
char lahmacun_C[] = "Lahmacun";
char salad_C[] = "Salad";
int threshold;
int thresholddan_buyuk_eleman_sayisi = 0;;

//char dizi_C[] = {kebab_C, burger_C, pasta_C, lahmacun_C, salad_C};
const char *strings[] = {"kebab", "burger", "pasta", "lahmacun_C", "aalad"};



void yemek_puanlama(int, int);
void yemek_puanlama_tur_2(int, int);

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main()
{
    dizi_yemek[0].yemekIsim = "kebab";
    dizi_yemek[1].yemekIsim = "burger";
    dizi_yemek[2].yemekIsim =  "pasta";
    dizi_yemek[3].yemekIsim =  "lahmacun";
    dizi_yemek[4].yemekIsim =  "salad";
    
    dizi_yemek[0].puan = 0;
    dizi_yemek[1].puan = 0;
    dizi_yemek[2].puan = 0;
    dizi_yemek[3].puan = 0;
    dizi_yemek[4].puan = 0;
    
    
	int i = 1;
	int j = 1;
	int kisi_sayisi;
	
	int tercih;
	int tercih_1;
	int tercih_2;
	int tercih_3;
	int tercih_4;
	int tercih_5;

	printf("kac kisi yemek siparisi verecek?  : ");
	scanf("%d", &kisi_sayisi);

    printf("%d kisi yemek siparisi verecek\n", kisi_sayisi);
    threshold =kisi_sayisi*3-1;
    printf("threshold: %d \n", threshold);
    
    for(i=1; i<=kisi_sayisi;i++)
    {
         printf("\n1-Kebab, 2-Burger, 3-Pasta, 4-Lahmacun, 5-Salad\n");
         printf("%d. kisinin ilk tercihi:",i);
         scanf("%d", &tercih_1);
         yemek_puanlama(tercih_1, 1);
         
         printf("%d. kisinin ikinci tercihi:",i);
         scanf("%d", &tercih_2);
         while(tercih_2 == tercih_1)
         {
                     printf("Ayni tercih ikinci kez yapilamaz...\n");
                     printf("%d. kisinin ikinci tercihi:",i);
                     scanf("%d", &tercih_2);
         }
         yemek_puanlama(tercih_2, 2);
         
         printf("%d. kisinin ucuncu tercihi:",i);
         scanf("%d", &tercih_3);
         while(tercih_3 == tercih_2 || tercih_3 == tercih_1)
         {
                     printf("Ayni tercih ikinci kez yapilamaz...\n");
                     printf("%d. kisinin ucuncu tercihi:",i);
                     scanf("%d", &tercih_3);
         }
         yemek_puanlama(tercih_3, 3);
         
         printf("%d. kisinin dorduncu tercihi:",i);
         scanf("%d", &tercih_4);
         while(tercih_4 == tercih_1 || tercih_4 == tercih_2 || tercih_4 == tercih_3)
         {
                     printf("Ayni tercih ikinci kez yapilamaz...\n");
                     printf("%d. kisinin dorduncu tercihi:",i);
                     scanf("%d", &tercih_4);
         }
         yemek_puanlama(tercih_4, 4);
         
         printf("%d. kisinin besinci tercihi:",i);
         scanf("%d", &tercih_5);
         while(tercih_5 == tercih_1 || tercih_5 == tercih_2 || tercih_5 == tercih_3 || tercih_5 == tercih_4)
         {
                     printf("Ayni tercih ikinci kez yapilamaz...\n");
                     printf("%d. kisinin besinci tercihi:",i);
                     scanf("%d", &tercih_5);
         }
         yemek_puanlama(tercih_5, 5);
    }
    ///////////////////////////////////77777777
    printf("\n\n");
    
    for(j=0 ; j<5 ; j++)
    {
           printf("%s, puan: %d\n", dizi_yemek[j].yemekIsim, dizi_yemek[j].puan);
    }
    ////////////////////////////////// liste
    i=0;
    for(j=0 ; j<5 ; j++)
    {
            
            if(dizi_yemek[j].puan > threshold)
            {
                thresholddan_buyuk_eleman_sayisi = thresholddan_buyuk_eleman_sayisi + 1;
                
                dizi_yemek_tur_2[i].yemekIsim = dizi_yemek[j].yemekIsim;
                dizi_yemek_tur_2[i].puan = dizi_yemek[j].puan;
                
                i=i+1;
            }
    }

    enBuyuk.yemekIsim = dizi_yemek[0].yemekIsim;
    enBuyuk.puan = dizi_yemek[0].puan;
                
    j=1;
    while(j<5)
    {
                      
            if(enBuyuk.puan < dizi_yemek[j].puan)
            {
                 enBuyuk.yemekIsim = dizi_yemek[j].yemekIsim;
                 enBuyuk.puan = dizi_yemek[j].puan;  
                                          
            }  
                      
            j = j +1;
    }
    
    if (thresholddan_buyuk_eleman_sayisi == 0)
    {
         printf("\n en cok puan %s, %d thresholddan (%d) kucuk evde yemek yiyoruz \n", enBuyuk.yemekIsim, enBuyuk.puan, threshold);
    }
    else if(thresholddan_buyuk_eleman_sayisi == 1)
    {         
         printf("\n en cok puan : %s, %d \n", enBuyuk.yemekIsim, enBuyuk.puan);
    }
    else
    {
        for(j=0 ; j<5 ; j++)
        {
            dizi_yemek_tur_2[j].puan = 0;
        }
        
        printf("\n\n");
        printf("thresholddan buyuk puanli yemekler");
        printf("\n\n");
        
        for(j=0 ; j<thresholddan_buyuk_eleman_sayisi ; j++)
        {
             printf("\n%d-%s\n", j+1, dizi_yemek_tur_2[j].yemekIsim);         
        }
        printf("\n\n");
        
        for(i=1; i<=kisi_sayisi;i++)
        {
                 for(j=0 ; j<thresholddan_buyuk_eleman_sayisi ; j++)
                 {
                     printf("%d. kisinin %d. tercihi:",i,j+1);
                     scanf("%d", &tercih);
                     yemek_puanlama_tur_2(tercih, j);
                     printf("\n\n");
                 }       
                 
        }
        
            ///////////////////////////////////77777777
            printf("\n\n");
    
            for(j=0 ; j<thresholddan_buyuk_eleman_sayisi ; j++)
            {
                    printf("%s, puan: %d\n", dizi_yemek_tur_2[j].yemekIsim, dizi_yemek_tur_2[j].puan);
            }
            ////////////////////////////////// liste
        
        


            enBuyuk.yemekIsim = dizi_yemek_tur_2[0].yemekIsim;
            enBuyuk.puan = dizi_yemek_tur_2[0].puan;
                
            j=1;
                
            while(j<thresholddan_buyuk_eleman_sayisi)
            {
                      
                 if(enBuyuk.puan < dizi_yemek_tur_2[j].puan)
                 {
                     enBuyuk.yemekIsim = dizi_yemek_tur_2[j].yemekIsim;
                     enBuyuk.puan = dizi_yemek_tur_2[j].puan;  
                                          
                 }  
                      
                 j = j +1;
            }
            printf("\n en cok puan : %s, %d \n", enBuyuk.yemekIsim, enBuyuk.puan);
        
        
        
        
    }
    
	return 0;
}


void yemek_puanlama(int tercih, int tercih_sirasi)
{
    if(tercih ==1 || tercih ==2 || tercih ==3 || tercih ==4 || tercih ==5)
    {
          dizi_yemek[tercih -1].puan = dizi_yemek[tercih -1].puan + 6-tercih_sirasi;      
    }
    else
    {
        printf("\n menude olmayan bisey secildi salata sectin sayiyorum :) \n");
        dizi_yemek[4].puan = dizi_yemek[4].puan + 6-tercih_sirasi; 
    }
      
}

void yemek_puanlama_tur_2(int tercih, int tercih_sirasi)
{
    if(tercih ==1 || tercih ==2 || tercih ==3 || tercih ==4 || tercih ==5)
    {
          dizi_yemek_tur_2[tercih -1].puan = dizi_yemek_tur_2[tercih -1].puan + thresholddan_buyuk_eleman_sayisi-tercih_sirasi;      
    }
    else
    {
        printf("\n menude olmayan bisey secildi, tercih hakki algoritmada :) \n");
        dizi_yemek_tur_2[0].puan = dizi_yemek_tur_2[0].puan + thresholddan_buyuk_eleman_sayisi-tercih_sirasi; 
    }
      
}



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Yigin{
int *veri;
struct Yigin* sonraki;
struct Yigin* onceki;
};
struct Yigin *kok;
int main()
{
    int boyut_satir=21,boyut_sutun=21,giris_satir=0,giris_sutun=0,cikis_satir=0,cikis_sutun=0;
    printf("Matrisin boyutlarini giriniz:\n");
    while(boyut_satir>20)
    {
        printf("Satir Sayisi:");
        scanf("%d",&boyut_satir);
        if(boyut_satir>20)
            printf("Lutfen eni 21'den kucuk giriniz.\n");
    }
    while(boyut_sutun>20)
    {
        printf("Sutun Sayisi:");
        scanf("%d",&boyut_sutun);
        if(boyut_sutun>20)
            printf("Lutfen boyu 21'den kucuk giriniz.\n");
    }
    boyut_satir+=2;
    boyut_sutun+=2;
    int matris[boyut_satir][boyut_sutun];
    matriseElemanAta(matris,boyut_satir,boyut_sutun);
    matrisiEkranaYaz(matris,boyut_satir,boyut_sutun);
    printf("Giris ve cikis kapilarini seciniz:\n");
    do
    {
        printf("Giris'i seciniz(Satir+\"Enter\" Sutun+\"Enter\")(1-%d)-(1-%d):\n",boyut_satir-2,boyut_sutun-2);
        scanf("%d",&giris_satir);
        scanf("%d",&giris_sutun);
        if(matris[giris_satir][giris_sutun]==0||((giris_satir>1&&giris_satir<boyut_satir-2)&&(giris_sutun>1&&giris_sutun<boyut_sutun-2))||giris_satir>boyut_satir-2||giris_sutun>boyut_sutun-2)
            printf("Hatali veri girdiniz, Lutfen tekrar deyeniniz. \n");
    }while(matris[giris_satir][giris_sutun]==0||((giris_satir>1&&giris_satir<boyut_satir-2)&&(giris_sutun>1&&giris_sutun<boyut_sutun-2))||giris_satir>boyut_satir-2||giris_sutun>boyut_sutun-2);
    do
    {
        printf("Cikis'i seciniz(Satir+\"Enter\" Sutun+\"Enter\")(1-%d)-(1-%d):\n",boyut_satir-2,boyut_sutun-2);
        scanf("%d",&cikis_satir);
        scanf("%d",&cikis_sutun);
        if(matris[cikis_satir][cikis_sutun]==0||((cikis_satir>1&&cikis_satir<boyut_satir-2)&&(cikis_sutun>1&&cikis_sutun<boyut_sutun-2))||cikis_satir>boyut_satir-2||cikis_sutun>boyut_sutun-2)
            printf("Hatali veri girdiniz, Lutfen tekrar deyeniniz.\n");
    }while(matris[cikis_satir][cikis_sutun]==0||((cikis_satir>1&&cikis_satir<boyut_satir-2)&&(cikis_sutun>1&&cikis_sutun<boyut_sutun-2))||cikis_satir>boyut_satir-2||cikis_sutun>boyut_sutun-2);
    int test=cikisBul(matris,boyut_satir,boyut_sutun,giris_satir,giris_sutun,cikis_satir,cikis_sutun);
    if(test)
    {
        printf("Cikis %d adimda bulundu.\n",test);
        matrisiEkranaYaz(matris,boyut_satir,boyut_sutun);
    }
    else
        printf("Cikis Bulunamadi.\n");
    return 0;
}
void matriseElemanAta(int *matris, int satir, int sutun)
{
    int i,j;
    srand(time(NULL));
    for(i=0;i<satir;i++)
    {
        for(j=0;j<sutun;j++)
        {
            *((matris+satir*i)+j)=rand()%2;
            if(i==0||i==satir-1)
            {
                *((matris+satir*i)+j)=0;
            }
            else
            {
                if(j==0||j==sutun-1)
                {
                    *((matris+satir*i)+j)=0;
                }
            }
        }
    }
}
void matrisiEkranaYaz(int *matris,int satir,int sutun)
{
    printf("MATRiSi EKRANA YAZ\n");
    int i,j;
    for(i=1;i<satir-1;i++)
    {
        for(j=1;j<sutun-1;j++)
        {
            printf("%d ",*((matris+satir*i)+j));
        }
        printf("\n");
    }
}
int cikisBul(int *matris,int satir,int sutun, int giris_satir, int giris_sutun, int cikis_satir, int cikis_sutun)
{
    int cikis_konumu=0;
    //Cikisin girise gore konumu hesaplanir
        if(cikis_satir<giris_satir){
            if(cikis_sutun<giris_sutun)
                cikis_konumu=4;//Sol Yukari
            else
                cikis_konumu=2;//Sag-Yukari
        }
        else{
            if(cikis_sutun<giris_sutun)
                cikis_konumu=3;//Sol-Asagi
            else
                cikis_konumu=1;//Sag-Asagi
        }
    ekle((matris+satir*giris_satir)+giris_sutun);
    int *konum;
    konum=kok->veri;
    kok->sonraki=kok;
    int sayac=0;
    while(konum!=(matris+satir*cikis_satir)+cikis_sutun)
    {
        sayac++;
        switch(cikis_konumu)
        {
        case(1):
            if(*(konum+1)==1&&(konum+1)!=kok->sonraki->veri)//Sag
            {
                    ekle(konum+1);
                    konum=kok->veri;
            }
            else if(*(konum+sutun)==1&&(konum+sutun)!=kok->sonraki->veri)//Asagi
            {
                    ekle(konum+sutun);
                    konum=kok->veri;
            }
            else if(*(konum-sutun)==1&&(konum-sutun)!=kok->sonraki->veri)//Yukari
            {
                    ekle(konum-sutun);
                    konum=kok->veri;
            }
            else if(*(konum-1)==1&&(konum-1)!=kok->sonraki->veri)//Sol
            {
                    ekle(konum-1);
                    konum=kok->veri;
            }
            else
            {
                *(konum)=0;
                al();
                if(konum==(matris+satir*giris_satir)+giris_sutun)
                {
                    return 0;
                }
                konum=kok->veri;
            }
            break;
        case(2):
            if(*(konum+1)==1&&(konum+1)!=kok->sonraki->veri)//Sag
            {
                    ekle(konum+1);
                    konum=kok->veri;
            }
            else if(*(konum-sutun)==1&&(konum-sutun)!=kok->sonraki->veri)//Yukari
            {
                    ekle(konum-sutun);
                    konum=kok->veri;
            }
            else if(*(konum+sutun)==1&&(konum+sutun)!=kok->sonraki->veri)//Asagi
            {
                    ekle(konum+sutun);
                    konum=kok->veri;
            }
           else if(*(konum-1)==1&&(konum-1)!=kok->sonraki->veri)//Sol
            {
                    ekle(konum-1);
                    konum=kok->veri;
            }
            else
            {
                *(konum)=0;
                al();
                if(konum==(matris+satir*giris_satir)+giris_sutun)
                {
                    return 0;
                }
                konum=kok->onceki->veri;
            }
            break;
        case(3):
            if(*(konum+sutun)==1&&(konum+sutun)!=kok->sonraki->veri)//Asagi
            {
                    ekle(konum+sutun);
                    konum=kok->veri;
            }
            else if(*(konum-1)==1&&(konum-1)!=kok->sonraki->veri)//Sol
            {
                    ekle(konum-1);
                    konum=kok->veri;
            }
            else if(*(konum+1)==1&&(konum+1)!=kok->sonraki->veri)//Sag
            {
                    ekle(konum+1);
                    konum=kok->veri;
            }
             else if(*(konum-sutun)==1&&(konum-sutun)!=kok->sonraki->veri)//Yukari
            {
                    ekle(konum-sutun);
                    konum=kok->veri;
            }
            else
            {
                *(konum)=0;
                al();
                if(konum==(matris+satir*giris_satir)+giris_sutun)
                {
                    return 0;
                }
                konum=kok->onceki->veri;
            }
            break;
        case(4):
            if(*(konum-sutun)==1&&(konum-sutun)!=kok->sonraki->veri)//Yukari
            {
                    ekle(konum-sutun);
                    konum=kok->veri;
            }
            else if(*(konum-1)==1&&(konum-1)!=kok->sonraki->veri)//Sol
            {
                    ekle(konum-1);
                    konum=kok->veri;
            }
            else if(*(konum+1)==1&&(konum+1)!=kok->sonraki->veri)//Sag
            {
                    ekle(konum+1);
                    konum=kok->veri;
            }
            else if(*(konum+sutun)==1&&(konum+sutun)!=kok->sonraki->veri)//Asagi
            {
                    ekle(konum+sutun);
                    konum=kok->veri;
            }
            else
            {
                *(konum)=0;
                al();
                if(konum==(matris+satir*giris_satir)+giris_sutun)
                {
                    return 0;
                }
                konum=kok->onceki->veri;
            }
            break;
        }
    }
    int i,j;
    for(i=1;i<satir-1;i++)
    {
        for(j=1;j<sutun-1;j++)
        {
            *((matris+satir*i)+j)=0;
        }
    }
    while(konum!=(matris+satir*giris_satir)+giris_sutun)
    {
        konum=kok->veri;
        *konum=1;
        kok=kok->sonraki;
    }
    return sayac;
}
struct Yigin* YeniDugum(int *veri){
struct Yigin* yigin=(struct Yigin*)malloc(sizeof(struct Yigin));
yigin->veri=veri;
yigin->sonraki=NULL;
return yigin;
}
void ekle(int *veri){
    struct Yigin *gecici=YeniDugum(veri);
    gecici->sonraki=kok;
    kok=gecici;
}
void al(){
    struct Yigin *gecici=kok;
    kok=kok->sonraki;
    free(gecici);
}



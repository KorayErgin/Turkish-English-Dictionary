#include <allegro.h>
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;



class km_islemleri
{
	
	protected: float genel_km,gunluk_km;
	
	
    public:	
	  km_islemleri(){genel_km=0; gunluk_km=0; }
	  
	  float genel_hesap(int hiz)
	{
        genel_km=hiz + genel_km;
		return genel_km/3600;
	}
    
     float gunluk_km_hesap(int hiz)
	{
	   gunluk_km=hiz + gunluk_km;
		return gunluk_km/3600;
	}
};

class far
{
	protected: int far_durumu,sinyal[3];
	
	public:
		far(){
			sinyal[0]=0;		
		    sinyal[1]=0;
		    sinyal[2]=0;
			far_durumu=0;
		}
		void kisa_faryak()
		{
	    far_durumu=1;
			 
		}
	    void uzun_faryak()
		{
		far_durumu=2;
		}
		 void far_kapat()
		{
		far_durumu=0;
		}
		int far_kontrol()
		{
			return far_durumu;
		}
		
		void sinyalver(int k)
    {
    	if(k==0) sinyal[0]=1;
    	else if(k==1) sinyal[1]=1;
    	else if(k==2) sinyal[2]=1;
    	else if(k==3) 
		{
    	sinyal[0]=0;		
		sinyal[1]=0;
		sinyal[2]=0;
    	}
    	
    }
		
		
};

class uyarilar
 {
       protected : int kemer_durumu,vitesariza,vites_ariza_durumu,hararet_uyarisi=0,kapi_durumu,yakit_uyarisi,aku,acikkapi,fren_asinma;

       public:
       	uyarilar(){vitesariza=0; }
       	uyarilar(int kapino){ kapi_durumu=kapino;      	}   // Çok biçimlilik
	   void yakit_Uyarisi(int ykt)
	 {
	  if(ykt<100) yakit_uyarisi=1;	
	 }
	 
	    int hararet(int isim)
	 {
	  if(isim>60) return 1;
	  else 	 return 0;
	 }
	void kapi_ac()
	{
      kapi_durumu=1; 
	}
	void kapi_kapat()
	{
	  kapi_durumu=0; 
	}
	 int kapi_durum()
	{
	 return kapi_durumu; 
	}
	
	void kemer_tak()
	{
	 kemer_durumu=1; 
	}
	
	void kemer_cikar()
	{
	 kemer_durumu=0; 
	}
	int kemer_durum()
	{
	 return kemer_durumu; 
	}
	int vites_arizalimi()
	{
	 vites_ariza_durumu =0;
	 vitesariza++;
	 if(vitesariza>5000) vites_ariza_durumu=1;
	 return vites_ariza_durumu; 
	}
	 
 };

class Araba:public far,public km_islemleri,public uyarilar
{
	protected: 
	int hiz,el_freni,km_genel,km_gun,isi,aku,yag;
	float devir;
	bool far,fren,gaz;
    float yakit;
	
    public:
	 Araba()
	{
	    isi=0;
	    yag=4000;
		hiz=0;
		aku=100;
		devir=0;
		yakit=500;
		el_freni=0;
	}
	~Araba(){};
	 public:
	 	
	 int hizgoster() {return hiz;}
	 int isigoster() {return isi;}
	 int akugoster() {return aku;}
	 int yaggoster() {return yag;}
     int elfrenidurumgoster() {return el_freni;}
	 float devirgoster(){return devir;}
   	 float yakitgoster(){return yakit;}
   	 
   	 void devirsifirla(){ devir=500;   	 }
   	 void devirmaxla(){ devir=3499;   	 }
	 void gaza_bas()
	 {
	 	yag-=2;
	   if(hiz<220&&el_freni==0&&yakit>3&&aku>0)
	   {
	   hiz+=5 ;
	    if(hiz%10==0) isi+=2;
	   
	   if(yakit>3){
	   yakit-=3;
	   if(devir<6000 )devir+=300;
       }
      }
	 }
	 void frene_bas()
	 {
	  if(hiz>=10&&devir>500)	{hiz-=10; 	devir-=500;}
	  else hiz=0;
	  if(yakit>0&&hiz>0)yakit-=1;
	 }
	  void surtunme()
	 {
	  if(hiz>0)
	 {
	 	yag-=2;
	    hiz-=1;
        if(devir>200)devir-=200;     }
	 
	 else devir=0;
	 
	 if(hiz%10==0&&isi>0) isi-=1;
	 if(aku>2) aku-=1;
     }
     void el_freni_cek(){      
		el_freni=1;
		hiz=0;
	 }  
     void el_freni_birak(){      
		el_freni=0;
	 }   
 
};



int main() {

    allegro_init(); 
    install_keyboard();
    install_mouse();
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1500, 768, 0, 0);
    BITMAP *gosterge=load_bitmap("audi.bmp",NULL);
    BITMAP *fren=load_bitmap("fren.bmp",NULL);
    BITMAP *gaz=load_bitmap("gaz.bmp",NULL);
    BITMAP *start2=load_bitmap("start2.bmp",NULL);
    BITMAP *ibrem=load_bitmap("ibre.bmp",NULL);
    BITMAP *clear=load_bitmap("clear.bmp",NULL);
    BITMAP *ibrem2=load_bitmap("ibre.bmp",NULL);
    BITMAP *isiibrem=load_bitmap("isi_ibre.bmp",NULL);
    BITMAP *uzunfar=load_bitmap("uzun.bmp",NULL);
    BITMAP *kisafar=load_bitmap("kisa.bmp",NULL);
    BITMAP *benzin_ibresi=load_bitmap("benzin.bmp",NULL);
    BITMAP *benzin_uyari=load_bitmap("benzinuyari.bmp",NULL);
    BITMAP *hararet_uyari=load_bitmap("hararet.bmp",NULL);
    BITMAP *solsinyal=load_bitmap("solsinyal.bmp",NULL);
    BITMAP *sagsinyal=load_bitmap("sagsinyal.bmp",NULL);
    BITMAP *kapi=load_bitmap("kapi.bmp",NULL);
    BITMAP *vites1=load_bitmap("vites1.bmp",NULL);
    BITMAP *vites2=load_bitmap("vites2.bmp",NULL);
    BITMAP *vites3=load_bitmap("vites3.bmp",NULL);
    BITMAP *vites4=load_bitmap("vites4.bmp",NULL);
    BITMAP *vites5=load_bitmap("vites5.bmp",NULL);
    BITMAP *vitestablo=load_bitmap("vitestablo.bmp",NULL);
    BITMAP *kemer=load_bitmap("kemer.bmp",NULL);
    BITMAP *akum=load_bitmap("aku.bmp",NULL);
    BITMAP *dortlu=load_bitmap("4lu.bmp",NULL);
    BITMAP *yagim=load_bitmap("yag.bmp",NULL);
    BITMAP *button=load_bitmap("button.bmp",NULL);
    BITMAP *elfreni=load_bitmap("elfreni.bmp",NULL);
    BITMAP *ariza=load_bitmap("ariza.bmp",NULL);
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,"A");
    SAMPLE *enginee=load_sample("startengine.wav");

    show_mouse(screen);
	blit(gosterge, screen, 0,0,0,0,1500,768);
    blit(fren, screen, 0,0,555,650,116,118);
    blit(gaz, screen, 0,0,800,570,93,193);
    blit(start2, screen, 0,0,170,590,190,193);

    const double start_degree=225;
	const double end_degree=-45;    //Hız göstergesi için
	const double maxHiz=225;
	
	const double start_degree2=225;
	const double end_degree2=-45;       //Devir saati için
	const double maxDevir=8000;
	
	const double start_degree3=0;
	const double end_degree3=75;       //yakit göstergesi için
	const double maxYakit=500;
	
	const double start_degree4=225;
	const double end_degree4=0;       //hararet göstergesi için
	const double maxisi=80;
	
    int gaz_durumu=0,durumsol,durumdort,elfreni_durum,durumsag,vitesdurum=0,vites=1,fren_durumu=0,yagg,hiz=0,motor_isisi,far_durum,aku,kemer_durum=0,sinyal,kapi_durum;
	float genel=0,gunluuk,gunlukekran=0;
	float devir;
    clock_t start;
    double duration;
    start = clock();
    Araba x;
    int eng,degree=0,degree2=0,degree3=0,degree4=0;
    rotate_sprite(screen,ibrem,1100,225,itofix(degree));
    rotate_sprite(screen,ibrem2,200,235,itofix(degree2));    //itofix çevrimi döndürmeyi saglar
    rotate_sprite(screen,benzin_ibresi,1130,485,itofix(degree3));
    rotate_sprite(screen,isiibrem,260,440,itofix(degree4));

    blit(button, screen, 0,0,610,188,190,193); 
    blit(vitestablo, screen, 0,0,650,400,190,193); 
    

      
    ilk:
    	eng=0;    // engine start düğmesine basma durumu
    	{
    	while(mouse_b&&1)
	 {
	 	int a=mouse_x;
	 	int b=mouse_y;                         // mouse kordinatları alındı
	 	int c=mouse_z;
	    textprintf_ex(screen,font,620,30, makecol(255,0,0) ,makecol(0,0,0) ,"Kordinat: %d  %d  %d",a,b,c);
	    
        if(a>194&&a<342&&b>617&&b<750 ) eng=1; 
	    else continue;
	    
	 }
    if(eng ==1)
    {
     eng=1;
	    play_sample(enginee,255,128,1000,FALSE); 
	    rest(100);
	while (!key[KEY_ESC]) {
		
		time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );

	
		float y=x.yakitgoster();
		hiz=x.hizgoster();
		aku=x.akugoster();
		yagg=x.yaggoster();
		genel=x.genel_hesap(hiz);
		elfreni_durum=x.elfrenidurumgoster();
		gunluuk=x.gunluk_km_hesap(hiz);
		devir=x.devirgoster(); ;
		if(devir>=3500&&vites<5){vites++; x.devirsifirla();	}
		if(devir<=400&&vites>1){vites--; x.devirmaxla();	}
		motor_isisi=x.isigoster();
		kapi_durum=x.kapi_durum();
		vitesdurum=x.vites_arizalimi();
		degree=(maxHiz-hiz)*(end_degree-start_degree)/maxHiz + start_degree;
		degree2=(maxDevir-devir)*(end_degree2-start_degree2)/maxDevir + start_degree2;
        degree3=(maxYakit-y)*(end_degree3-start_degree3)/maxYakit + start_degree3;
        degree4=(maxisi-motor_isisi)*(end_degree4-start_degree4)/maxisi + start_degree4;

		 while(mouse_b&&1)
	 {
	 	int a=mouse_x;
	 	int b=mouse_y;
	 	int c=mouse_z;
        
	    if(a>615&&a<660&&b>195&&b<635) gunlukekran=0;	    
        if(a>800&&a<900&&b>571&&b<666 ) 	gaz_durumu=1;    
        else if(a>571&&a<658&&b>650&&b<750 ) 	fren_durumu=1;   
	    else break;

	 }
	 gunlukekran=gunlukekran+(float)hiz/3600;
	 
	 if(vites==1) blit(vites1, screen, 0,0,650,400,190,193); 
	 else if(vites==2) blit(vites2, screen, 0,0,650,400,190,193); 
	 else if(vites==3) blit(vites3, screen, 0,0,650,400,190,193); 
	 else if(vites==4) blit(vites4, screen, 0,0,650,400,190,193); 
	 else if(vites==5) blit(vites5, screen, 0,0,650,400,190,193); 
	 
	 
	    if(yagg<20) blit(yagim, screen, 0,0,620,345,190,193);	
		if( key[KEY_UP] || gaz_durumu==1){ x.gaza_bas(); rest(130);}
	    else if(key[KEY_DOWN] || fren_durumu==1){ x.frene_bas(); rest(100);}
		else { x.surtunme(); rest(200);} // sürtünmeden kaynaklı yavaşlama
		
		
        if(y<100){
        	x.yakit_Uyarisi(y); 
            blit(benzin_uyari, screen, 0,0,620,345,190,193);                  //yakit uyarisi
        }
        else{
            blit(clear, screen, 0,0,620,345,190,193);	
        }
        int hararet_uyarisi=x.hararet(motor_isisi);
        if(key[KEY_Z]||hararet_uyarisi==1)      blit(hararet_uyari, screen, 0,0,680,345,190,193);  //denemek için z kullanılır

    
       
        if(key[KEY_K]&&far_durum!=1){ x.kisa_faryak();     blit(kisafar, screen, 0,0,730,340,93,193); rest(10); }
        else if(key[KEY_K]&&far_durum==1) { x.far_kapat();     blit(clear, screen, 0,0,730,340,100,200);  }
       
       
        if(key[KEY_U]&&far_durum!=2){ x.uzun_faryak();     blit(uzunfar, screen, 0,0,730,340,93,193); rest(10); }
        else if(key[KEY_U]&&far_durum==2){x.far_kapat();     blit(clear, screen, 0,0,730,340,100,200);  }
        far_durum=x.far_kontrol();
        
        
        if(vitesdurum==1) blit(ariza, screen, 0,0,730,340,93,193); 
        
        
        if(aku<25)  blit(akum, screen, 0,0,780,340,93,193);  
        else blit(clear, screen, 0,0,778,340,100,200);   
        
         if(key[KEY_D]&&kapi_durum!=1){ x.kapi_ac();     blit(kapi, screen, 0,0,730,290,93,193); rest(10); }
        else if(key[KEY_D]&&kapi_durum==1) { x.kapi_kapat();     blit(clear, screen, 0,0,730,290,100,200);  }
        
        if(key[KEY_H]&&elfreni_durum!=1){ x.el_freni_cek();   blit(elfreni, screen, 0,0,780,295,93,193); rest(10); }
        else if(key[KEY_H]&&elfreni_durum==1) { x.el_freni_birak();     blit(clear, screen, 0,0,780,295,100,200);  }
        
        
        
         if(key[KEY_C]&&kemer_durum!=1){ x.kemer_tak();     blit(kemer, screen, 0,0,680,290,93,193); rest(10); }
        else if(key[KEY_C]&&kemer_durum==1) { x.kemer_cikar();     blit(clear, screen, 0,0,680,290,100,200);  }
        kemer_durum=x.kemer_durum();
        
        if((key[KEY_RIGHT] && sinyal!=0) || durumsag==1 ) {
		 sinyal=0; 
		 durumsag=2;
		 durumsol=0;
		 x.sinyalver(0); 
		 blit(clear, screen, 0,0,495,60,45,45);
		 blit(sagsinyal, screen, 0,0,930,60,45,45);
		 rest(200);
		  }
		else if(durumsag==2){
		durumsag =1;
		blit(clear, screen, 0,0,930,60,45,45);
		rest(200);
		}           
		                  // 0 sağ 1 sol 2 dörtlüler 3 temizle
        else if(key[KEY_RIGHT] && sinyal==0 ) {
		 sinyal=3; 
		 x.sinyalver(3);
	      }                              //sağ sinyal
        
        if((key[KEY_LEFT] && sinyal!=1)||durumsol==1){ 
		sinyal=1; 
		durumsol=2;
		durumsag=0;
		x.sinyalver(1);
		blit(clear, screen, 0,0,930,60,45,45);
		blit(solsinyal, screen, 0,0,495,60,45,45);
		rest(200);
		}
		else if(durumsol==2){
			durumsol =1;
		    blit(clear, screen, 0,0,495,60,45,45);
		    rest(200);
		}
	
        else if(key[KEY_LEFT] && sinyal==1){
		 sinyal=3; 
		 x.sinyalver(3); 
		 }                               //sol sinyal

        
        if((key[KEY_SPACE] && sinyal!=2)||durumdort==1){
        durumdort=2;
		sinyal=2; 
		x.sinyalver(2);  
		blit(solsinyal, screen, 0,0,495,60,45,45);
		blit(sagsinyal, screen, 0,0,930,60,45,45);
 	    blit(dortlu, screen, 0,0,680,295,100,200);
		rest(200);
	    }
		else if(sinyal==2&&durumdort==2){
		durumdort=1;
		blit(clear, screen, 0,0,495,60,45,45);
		blit(clear, screen, 0,0,930,60,45,45);
		blit(clear, screen, 0,0,680,295,100,200);
		}                                   //4lüler
        
		
	    if(key[KEY_ENTER]){
		sinyal=3; 
		durumsol=0;
		durumsag=0;
		x.sinyalver(3);
		blit(clear, screen, 0,0,495,60,45,45);
		blit(clear, screen, 0,0,930,60,45,45);
		blit(clear, screen, 0,0,680,295,100,200);
        // flaşor ikaz resmi koyulcak
		} 
        
		rest(10);
		
		if(degree<150)rotate_sprite(screen,ibrem,1100,225,itofix(degree+45));
		if(degree2<150)rotate_sprite(screen,ibrem2,200,235,itofix(degree2+45));
        rotate_sprite(screen,benzin_ibresi,1130,485,itofix(degree3));
        rotate_sprite(screen,isiibrem,260,440,itofix(degree4));
		textprintf_ex(screen,font,630,130, makecol(255,0,0) ,makecol(0,0,0) ," %s ",ctime (&rawtime) );
		textprintf_ex(screen,font,670,200, makecol(255,0,0) ,makecol(0,0,0) ," GENEL KM: %.3f ",genel);
        textprintf_ex(screen,font,665,230, makecol(255,0,0) ,makecol(0,0,0) ," GUNLUK KM: %.3f ",gunlukekran );
	gaz_durumu=0;
	fren_durumu=0;
}
}
else goto ilk;
}
	return 0;
}END_OF_MAIN()

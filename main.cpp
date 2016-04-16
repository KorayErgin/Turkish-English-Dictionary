
#include <graphics.h>

main()
{
 while(1)
{
  
   bool sorgu1=0,sorgu2=0;
   int  x, y;
   system("COLOR 0F");
   initwindow(500,500,"Sozluk");
   setcolor(WHITE);
   rectangle(0,0,500,500);
   rectangle(150,35,350,70);   
   rectangle(360,35,400,70);
   rectangle(150,95,350,130); 
   rectangle(360,95,400,130); 
   outtextxy(170,45,"Ýngilizce - Turkce");   
   outtextxy(170,105,"Turkce - Ýngilizce");   
   outtextxy(150,155,"Lutfen secim yapiniz...");
   rectangle(180,180,300,230);
   outtextxy(210,200,"BASLAT");  
   while(1)
   {
   delay(50);
   getmouseclick(WM_LBUTTONDOWN,x,y);

   if(x<350 && y<70 && x>150 && y>35&&sorgu1==0)
   {   
   setfillstyle(SOLID_FILL, WHITE);
   bar(360,35,400,70);
   setfillstyle(SOLID_FILL, BLACK);
   bar(360,95,400,130);
   sorgu1=1; 
   sorgu2=0;        
   }
   else if(x<350 && y<130 && x>150 && y>95&&sorgu2==0)
   { 
   delay(50);
   setfillstyle(SOLID_FILL, WHITE); 
   bar(360,95,400,130); 
   setfillstyle(SOLID_FILL, BLACK);
   bar(360,35,400,70);
   sorgu1=0;
   sorgu2=1;
   }      
   else if(x<300&&x>180&&y>180&&y<230)
   {
   outtextxy(130,250,"Kelimeyi Konsola Giriniz ...");
   break;
   }
   clearmouseclick(WM_LBUTTONDOWN);
   }
   FILE *sozluk=fopen("sozluk.txt","r");
   FILE * trk=fopen("turkce.txt","w+");
   FILE * ingiliz=fopen("ingilizce.txt","w+");
   
   char tr[100][21],ing[100][21],bos[100][21];
   int i,j;
   for(i=0;i<100;i++)
 {
   fscanf(sozluk,"%s %s",tr[i],ing[i]);
 }
   for(j=0;j<99;j++)
{
   for(i=0;i<99;i++)
{
	
	
   if(strcmp(tr[i],tr[i+1])>0)
{
  
   strcpy(bos[i],tr[i]);
   strcpy(tr[i],tr[i+1]);
   strcpy(tr[i+1],bos[i]);
   
   strcpy(bos[i],ing[i]);
   strcpy(ing[i],ing[i+1]);
   strcpy(ing[i+1],bos[i]);	
}
}
}
	for(j=0;j<99;j++){
	
    fprintf(trk,"%s\n",tr[j]);
    fprintf(ingiliz,"%s\n",ing[j]);
}
    fclose(trk);
    fclose(ingiliz);
    fclose(sozluk);

    if(sorgu1==1&&sorgu2==0)
   {
   
   	int x,y,sayac2=0,sayac=0;
	char girdi[30],kelime[30];
	char cikti[30];
	printf("Kelimeyi giriniz :");
	scanf("%s",girdi);		
	
		for(int x=150;x<350;x+=20)
	{                               //loading barý
	setcolor(WHITE);
	rectangle(x,350,x+20,400);
    }
    for(int x=150;x<330;x++)
	{	delay(1);
	setfillstyle(SOLID_FILL, BLUE);
	bar(x,350,x+20,400);
	}
	for(int x=150;x<350;x++)
	{	
	setfillstyle(SOLID_FILL, BLACK);
	bar(x,350,x+20,400);
	}
		
	FILE* ingi=fopen("ingilizce.txt","r");
	
	if(ingi==NULL){ printf("ERROR"); }
	
	else {
	
	
	while (!feof(ingi))
	{
		
		fscanf(ingi,"%s\n",&kelime);
		sayac++;
		if(strcmp(girdi,kelime)==0) break;
			
	}
	FILE *turk=fopen("turkce.txt","r+");
	
	if(turk==NULL){printf("ERROR");	}
	
	else
	{
		
		if(strcmp(girdi,kelime)!=0){
		outtextxy(90,350,"Girdiginiz kelime sozlukte bulunmamaktadir...");
		printf("Girdiginiz kelime sozlukte bulunmamaktadir...");
		
		}		
		else{
			
		while (!feof(turk))
	{
		fscanf(turk,"%s\n",&kelime);
		sayac2++;
		if(sayac==sayac2) break;	
	}	
	printf("%s\n",kelime);
	printf("\ningilizce.txt dosyasinda aradiginiz %s kelimesi %d . kelimedir",girdi,sayac);
	outtextxy(90,350,"Girilen Kelime :");
	outtextxy(300,350,girdi);
	outtextxy(90,370,"Kelimenin Turkcesi :");	
	outtextxy(300,370,kelime);
	}
    }
	}
	fclose(ingi);
    }
    if(sorgu1==0&&sorgu2==1)
    {
    	int x,y,sayac2=0,sayac=0;
	char girdi[30],kelime[30];
	char cikti[30];
	printf("Kelimeyi giriniz :");
	scanf("%s",girdi);

			for( int a=0;a<30;++a)
	{ 
	  char d;
		for( int b=0;b<strlen(girdi);++b)
		{
		
		if((int)girdi[b]==-115) {
		d='i'; girdi[b] =d;}
		
		else if((int)girdi[b]==135) {
		d='c'; girdi[b] =d;}
		
		else if((int)girdi[b]==-127) {
		d='u'; girdi[b] =d;}
		
		else if((int)girdi[b]==-108) {
		d='o'; girdi[b] =d;}	
		
		else if((int)girdi[b]==-89) {
		d='g'; girdi[b] =d;}
		
		else if((int)girdi[b]==-2) {   //s ve ç harflerinde sýkýntý var
		d='s'; girdi[b] =d;}	
		
 		
		}
	}
	
		for(int x=150;x<350;x+=20)
	{
	setcolor(WHITE);
	rectangle(x,350,x+20,400);
    }
    for(int x=150;x<330;x++)
	{	delay(1);
	setfillstyle(SOLID_FILL, BLUE);
	bar(x,350,x+20,400);
	}
	for(int x=150;x<350;x++)
	{	
	setfillstyle(SOLID_FILL, BLACK);
	bar(x,350,x+20,400);
	}
	

	FILE* dosya=fopen("turkce.txt","r");
	
	if(dosya==NULL){ printf("ERROR"); }
	
	else {
		
	
	while (!feof(dosya))
	{
		
		fscanf(dosya,"%s\n",&kelime);
		sayac++;
		if(strcmp(girdi,kelime)==0) break;
	
	}
	
	
	FILE *ing=fopen("ingilizce.txt","r+");
	if(ing==NULL){printf("ERROR");	}
	else{
		
		if(strcmp(girdi,kelime)!=0){
		outtextxy(90,350,"Girdiginiz kelime sozlukte bulunmamaktadir...");
		printf("Girdiginiz kelime sozlukte bulunmamaktadir...");
		}
		
		else{
		
		while (!feof(ing))
	{
		fscanf(ing,"%s\n",&kelime);
		sayac2++;
		if(sayac==sayac2) break;
	}
	printf("%s",kelime);	
	printf("\nturkce.txt dosyasinda aradiginiz %s kelimesi %d . kelimedir",girdi,sayac);
    outtextxy(125,350,"Girilen Kelime :");
	outtextxy(325,350,girdi);
	outtextxy(125,370,"Kelimenin Ýngilizcesi:");	
	outtextxy(325,370,kelime);	
    }
	}	
    }
    }
    
    getch();
    closegraph();
}
    return 0;
    }    

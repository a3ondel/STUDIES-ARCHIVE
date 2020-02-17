#include "write.h"

/*
zapis calego bmp do pliku
*/
int write_file(char *filename, BMP *img)
{

	FILE *file;
	file=fopen(filename, "wb");
	
	int padding = 0;
	padding=get_padding((int)img->imghead.width_px); // obliczanie wymaganego wyrownania bitowego
	char paddingcan[3] = { 0,0,0 }; //tablica z zerami (trzy elementy bo maksymalny padding sklada sie z 3 bajtow)
	if (file)
	{
		headerupdate(img, padding);
		
		fwrite(&img->fhead, sizeof(FILEHEADER), 1, file); //zapis pierwszego naglowka bmp do pliku
		fwrite(&img->imghead, sizeof(IMGHEADER), 1, file);//zapis drugiego naglowka bmp do pliku
		
		for (int i = 0; i < (int)img->imghead.height_px; i++) //powtarzane wysokosc-obrazka-razy
		{
			fwrite(&(img->imgarray[i*(int)img->imghead.width_px]), sizeof(PIXEL), (int)img->imghead.width_px, file); //zapis prawidlowych pixeli do pliku
			fwrite(paddingcan, sizeof(char), padding, file);		//zapis wyrownania do pliku 
		}

		fclose(file);
		return 1; 
	}
	else
		return 0; // blad tworzenia pliku


}

//aktualziacja informacji o rozmiarze pliku, rozmiarze obrazka oraz o lokalizacji bitmapy w pliku
void headerupdate(BMP *imgtmp,int padding)
{

	imgtmp->fhead.file_size = (unsigned __int32)(sizeof(FILEHEADER) + sizeof(IMGHEADER)
							+ padding * sizeof(char)*imgtmp->imghead.height_px 
							+ imgtmp->imghead.height_px*imgtmp->imghead.width_px * sizeof(PIXEL));
	
	
	imgtmp->fhead.offset = (unsigned __int32) sizeof(FILEHEADER) + sizeof(IMGHEADER);

	imgtmp->imghead.img_size = imgtmp->fhead.file_size - (sizeof(FILEHEADER) + sizeof(IMGHEADER));

}